%{
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "sql_parser.h"

extern int yylex();
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

void yyerror(const char* s);
ASTNode* create_node(NodeType type, const char* value);
void print_tree(ASTNode* node, int depth);

int num_trees=1;
ASTNode* all_trees[MAX_RES_TREE];
ASTNode* parse_tree[10];
int parse_tree_count =0;

extern int num_tables;
extern TABLE *tables;

int changed=0;
int is_projection_star_only(ASTNode *args);
int no_with_tables = 0;

%}

/* Define union for semantic values */
%union {
    char* str;
    int num;
    struct ASTNode* node;
}

/* Define token types */
%token <str> ID STRING_LITERAL OPERATOR
%token <num> NUM

/* SQL keywords */
%token SELECT ALL DISTINCT FROM WHERE GROUP BY HAVING ORDER
%token ASC DESC USING NULLS FIRST LAST
%token UNION INTERSECT EXCEPT
%token INSERT INTO VALUES DEFAULT WITH RECURSIVE AS
%token UPDATE ONLY SET ROW
%token DELETE EXISTS BETWEEN AND OR IN
%token INNER NATURAL LEFT RIGHT FULL CROSS JOIN ON IS NOT NULL_VAL 

/* Operators and punctuation */
%token SEMICOLON COMMA DOT ASTERISK LPAREN RPAREN
%token EQ NE LT GT LE GE CONCAT PLUS MINUS DIV

/* Define precedence and associativity */
%left OR
%left AND
%right NOT
%left EQ NE LT GT LE GE
%left PLUS MINUS
%left ASTERISK DIV
%left CONCAT
%nonassoc UMINUS

/* Define start symbol */
%start program

/* Define types for non-terminals */
%type <node> program statement_list statement query select_stmt
%type <node> with_clause with_query with_query_list recursive_opt
%type <node> select_opts column_list column as_id_opt
%type <node> from_clause from_item_list from_item
%type <node> where_clause group_clause group_item_list
%type <node> having_clause order_clause order_item_list order_item
%type <node> insert_stmt column_list_opt column_name_list
%type <node> insert_values insert_value_list insert_value_items insert_value
%type <node> update_stmt only_opt asterisk_opt set_clause set_item_list set_item
%type <node> set_value column_name
%type <node> delete_stmt using_clause_opt
%type <node> expression and_condition 
%type <node> condition not_opt in_items comparison_op
%type <node> operand summand factor term
%type <node> with_clause_opt order_option nulls_option
%type <node> join_type set_op modified_id base_table joined_table join_condition_opt

%%

program
    : statement_list 
    {
    }
    ;

statement_list
    : statement 
    {
    }
    | statement_list statement
    {
    }
    ;

statement
    : query SEMICOLON
    {
        no_with_tables=0;
        $$ = $1;
        parse_tree[parse_tree_count] = $$;
        parse_tree_count++;
        printf("=================================================================================================\n");
        printf("\nOriginal Relational Algebra Tree for sql statement %d:\n",parse_tree_count);
        print_tree($1, 0);
        printf("\nCost of actual tree: %lld\n",cost_calculation($1));


        printf("---------------------------------------------------------------------------------------------------\n");
        $$ = pre_transform_tree($$,NULL);
        printf("\nTree after Pre-Transformations:\n");
        print_tree($$, 0);

        num_trees=1;
        for(int i=0;i<MAX_RES_TREE;i++){
            all_trees[i]=NULL;
        }
        all_trees[0] = deep_copy_tree($$);
        apply_join_transf(all_trees[0]);
        int nit = num_trees;
        for(int i=0;i<nit;i++){
            all_trees[i] = apply_transformations(all_trees[i]);
        }
        int opt_tree_ind=0;
        long long int opt_cost=INT64_MAX;
        printf("---------------------------------------------------------------------------------------------------\n");
        printf("\nTree after Transformations:\n");
        for(int i=0;i<num_trees;i++){
            printf("\nTransformed Tree %d:\n",i+1);
            if(all_trees[i])print_tree(all_trees[i], 0);
            long long int cost = cost_calculation(all_trees[i]);
            printf("\nCost of transformed tree %d: %lld\n",i+1,cost);
            if(cost<opt_cost){
                opt_cost=cost;
                opt_tree_ind=i;
            }
        }
        printf("---------------------------------------------------------------------------------------------------\n");
        printf("\nOptimized Tree:\n");
        if(opt_tree_ind!=-1&&all_trees[opt_tree_ind])print_tree(all_trees[opt_tree_ind], 0);
            printf("\nCost of Optimized tree %d: %lld\n",opt_tree_ind+1,opt_cost);
        for(int i = 0;i<num_trees;i++){
            free_tree(all_trees[i]);
        }
        num_tables-=no_with_tables;
    }
    ;

query
    : select_stmt
    {
        $$ = $1;
    }
    | insert_stmt
    {
        $$ = $1;
    }
    | update_stmt
    {
        $$ = $1;
    }
    | delete_stmt
    {
        $$ = $1;
    }
    | select_stmt set_op select_opts select_stmt
    {
        $$ = $2;
        $$->left = $1;
        $$->right = $4;
        if($3 && strcmp($3->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, $3->value);
            distinct->left = $$;
            $$ = distinct;
        }
    }
    ;

set_op
    : UNION
    {
        $$ = create_node(RA_SET_OP, "∪");  // Union symbol
    }
    | INTERSECT
    {
        $$ = create_node(RA_SET_OP, "∩");  // Intersection symbol
    }
    | EXCEPT
    {
        $$ = create_node(RA_SET_OP, "−");  // Minus symbol
    }
    ;

/* SELECT statement */
select_stmt
    : with_clause_opt SELECT select_opts column_list from_clause where_clause group_clause having_clause order_clause
    {
        // Start building the tree from the bottom up
        ASTNode* base_tree = $5;  // FROM clause
        
        // Apply WITH clause
        if ($1 && $1->type != RA_EMPTY) {
            $1->right=base_tree;
            base_tree=$1;
        }

        // Apply WHERE clause (σ - selection)
        if ($6 && $6->type != RA_EMPTY) {
            ASTNode* selection = $6;
            // selection->left = $6->left;  // Condition
            // selection->args = $6;
            selection->left = base_tree;
            base_tree = selection;
        }
        
        // Apply GROUP BY (γ - grouping)
        if ($7 && $7->type != RA_EMPTY) {
            ASTNode* grouping = $7;
            // grouping->left = $7->left;  // Grouping columns
            // grouping->args = $7;
            grouping->left = base_tree;
            base_tree = grouping;
        }
        
        // Apply HAVING (σ - selection after grouping)
        if ($8 && $8->type != RA_EMPTY) {
            ASTNode* having = $8;
            // having->left = $8->left;  // Condition
            // having->args = $8;
            having->left = base_tree;
            base_tree = having;
        }
        
        // Apply projection (π)
        ASTNode* projection = create_node(RA_PROJECTION, "");
        projection->args = $4;  // SELECT columns
        projection->left = base_tree;

        // Apply DISTINCT if specified
        if ($3 && strcmp($3->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, "DISTINCT");
            distinct->left = projection;
            $$ = distinct;
        }
        else{
            $$ = projection;
        }
        
        // Apply ORDER BY
        if ($9 && $9->type != RA_EMPTY) {
            $9->right = $$;
            $$ = $9;
        }
        
    }
    ;

with_clause_opt
    : with_clause
    {
        $$ = $1;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

with_clause
    : WITH recursive_opt with_query_list
    {
        $$ = create_node(RA_WITH, "");
        if (strcmp($2->value, "RECURSIVE") == 0) {
            strcpy($$->value,"RECURSIVE") ; // Mark as recursive
        }
        $$->left = $3;
    }
    ;

recursive_opt
    : RECURSIVE
    {
        $$ = create_node(RA_ATTRIBUTE, "RECURSIVE");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

with_query_list
    : with_query
    {
        $$ = $1;
    }
    | with_query_list COMMA with_query
    {
        ASTNode* list = create_node(RA_WITH_LIST, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
    }
    ;

with_query
    : ID AS LPAREN query RPAREN 
    {
        $$ = create_node(RA_RELATION, $1);  // Represents a table now available by name $1
        $$ = create_node(RA_ALIAS, $1);
        $$->left = $4;
        // Build scope of the query result
        scope_attr *with_scope = build_scope($4);

        // Count attributes
        int no_with_attr = 0;
        for (scope_attr *temp = with_scope; temp; temp = temp->next) {
            no_with_attr++;
        }

        // Store metadata in global tables[]
        TABLE *t = &tables[num_tables];
        t->TABLE_NAME = strdup($1);
        t->num_attributes = no_with_attr;
        t->attr_list = (attr*)malloc(no_with_attr * sizeof(attr));
        t->num_tuples = estimate_size($4); // You should implement this function

        int i = 0;
        for (scope_attr *temp = with_scope; temp; temp = temp->next) {
            t->attr_list[i].name = strdup(temp->name);
            t->attr_list[i].flag = 0; // default no-index
            t->attr_list[i].max_len = t->num_tuples; // worst case distinct
            t->attr_list[i].num_distinct = 0;
            i++;
        }

        num_tables++;
        no_with_tables++;

        free_scope(with_scope);
    }
    ;

select_opts
    : ALL
    {
        $$ = create_node(RA_ATTRIBUTE, "ALL");
    }
    | DISTINCT
    {
        $$ = create_node(RA_ATTRIBUTE, "DISTINCT");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

column_list
    : column as_id_opt
    {
        if ($2->type != RA_EMPTY) {
            // Handle column alias
            ASTNode* alias = create_node(RA_ALIAS, $2->value);
            alias->args = $1;
            $$ = alias;
        } else {
            $$ = $1;
        }
    }
    | column_list COMMA column as_id_opt
    {
        ASTNode* col;
        if ($4->type != RA_EMPTY) {
            // Handle column alias
            col = create_node(RA_ALIAS, $4->value);
            col->args = $3;
        } else {
            col = $3;
        }
        $$ = col;
        $$->left=$1;
    }
    | ASTERISK
    {
        $$ = create_node(RA_ATTRIBUTE, "*");
    }
    ;

column
    : term
    {
        $$ = $1;
    }
    | ID DOT ASTERISK
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.*", $1);
        $$ = create_node(RA_ATTRIBUTE, value);
    }
    ;

as_id_opt
    : AS ID
    {
        $$ = create_node(RA_ALIAS, $2);
    }
    | ID
    {
        $$ = create_node(RA_ALIAS, $1);
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

modified_id
    : ID
    {
        $$ = create_node(RA_ATTRIBUTE, $1);
    }
    | ID DOT ID
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.%s", $1, $3);
        $$ = create_node(RA_ATTRIBUTE, value);
    }
    ;

from_clause
    : FROM from_item_list
    {
        $$ = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;


from_item_list
    : from_item
    {
        $$ = $1;
    }
    | from_item_list COMMA from_item
    {
        ASTNode* cross_join = create_node(RA_JOIN, "⋈");  // Cross product
        cross_join->left = $1;
        cross_join->right = $3;
        $$ = cross_join;
    }
    ;

from_item
    : joined_table
    {
        $$=$1;
    }
    | base_table
    {
        $$=$1;
    }
    | LPAREN from_item RPAREN
    {
        $$=$2;
    }
    ;

base_table
    : modified_id as_id_opt
    {
        if ($2->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, $2->value);
            alias->left = create_node(RA_RELATION, $1->value);
            $$ = alias;
        } else {
            $$ = create_node(RA_RELATION, $1->value);
        }
    }
    | LPAREN query RPAREN as_id_opt
    {
        if ($4->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, $4->value);
            alias->left = $2;
            $$ = alias;
        } else {
            $$ = $2;
        }
    }
    ;

joined_table
    : from_item join_type base_table join_condition_opt
    {        
        ASTNode* join = create_node(RA_JOIN, $2->value);
        join->left = $1;
        join->right = $3;
        
        // Add join condition
        if($4->type != RA_EMPTY) join->condition = $4;
        
        $$ = join;
    }
    | from_item join_type LPAREN joined_table RPAREN join_condition_opt
    {        
        ASTNode* join = create_node(RA_JOIN, $2->value);
        join->left = $1;
        join->right = $4;
        
        // Add join condition
        if($6->type != RA_EMPTY) join->condition = $6;
        
        $$ = join;
    }
    ;

join_condition_opt
    : ON expression
    {
        $$ = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    /* | USING LPAREN column_name_list RPAREN */
    ;

join_type
    : INNER JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
    | LEFT JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⟕");  // Left join symbol
    }
    | RIGHT JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⟖");  // Right join symbol
    }
    | FULL JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⟗");  // Full join symbol
    }
    | CROSS JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈");  // Cross join symbol
    }
    | JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
    | NATURAL JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈ᴺ");  // Natural join symbol
    }
    ;

where_clause
    : WHERE expression
    {
        $$ = create_node(RA_SELECTION, "WHERE");
        $$->args = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

group_clause
    : GROUP BY group_item_list
    {
        $$ = create_node(RA_GROUPBY, "GROUP BY");
        $$->args = $3;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

group_item_list
    : modified_id
    {
        $$ = $1;
    }
    | group_item_list COMMA modified_id
    {
        ASTNode* list = create_node(RA_GROUP_LIST, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
    }
    ;

having_clause
    : HAVING expression
    {
        $$ = create_node(RA_SELECTION, "HAVING");
        $$->args = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

order_clause
    : ORDER BY order_item_list
    {
        $$ = create_node(RA_ORDERBY, "ORDER BY");
        $$->args = $3;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

order_item_list
    : order_item
    {
        $$ = $1;
        $1->args = NULL;
    }
    | order_item_list COMMA order_item
    {
        ASTNode* curr = $1;
        while (curr->args) curr = curr->args;
        curr->args = $3;
        $3->args = NULL;
        $$ = $1;
    }
    ;

order_item
    : operand order_option nulls_option
    {
        char direction[MAX_STRING_LENGTH] = "";
        if ($2->type != RA_EMPTY) {
            strncpy(direction, $2->value, MAX_STRING_LENGTH - 1);
        }
        
        if ($3->type != RA_EMPTY) {
            if (direction[0] != '\0') {
                strncat(direction, ", ", MAX_STRING_LENGTH - strlen(direction) - 1);
            }
            strncat(direction, $3->value, MAX_STRING_LENGTH - strlen(direction) - 1);
        }
        
        ASTNode* order_item = create_node(RA_ORDER_ITEM, direction);
        order_item->left = $1;
        $$ = order_item;
        
    }
    ;

order_option
    : ASC
    {
        $$ = create_node(RA_ATTRIBUTE, "ASC");
    }
    | DESC
    {
        $$ = create_node(RA_ATTRIBUTE, "DESC");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

nulls_option
    : NULLS FIRST
    {
        $$ = create_node(RA_ATTRIBUTE, "NULLS FIRST");
    }
    | NULLS LAST
    {
        $$ = create_node(RA_ATTRIBUTE, "NULLS LAST");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

/* INSERT statement */
insert_stmt
    : with_clause_opt INSERT INTO ID as_id_opt column_list_opt insert_values
    {
        ASTNode* target = create_node(RA_RELATION, $4);
        
        // Apply WITH clause
        if ($1 && $1->type != RA_EMPTY) {
            target->left = $1;
        }

        if ($5->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, $5->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* insert = create_node(RA_INSERT, "INSERT");
        insert->left = target;
        if ($6->type != RA_EMPTY) {
            insert->right = $6;  // Columns
        }
        
        insert->args = $7;  // Values or subquery
        
        $$ = insert;
    }
    ;

column_list_opt
    : LPAREN column_name_list RPAREN
    {
        $$ = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

column_name_list
    : modified_id
    {
        $$ = $1;
    }
    | column_name_list COMMA modified_id
    {
        ASTNode* list = create_node(RA_COLUMN_LIST, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
    }
    ;

insert_values
    : DEFAULT VALUES
    {
        $$ = create_node(RA_VALUES, "DEFAULT");
    }
    | VALUES insert_value_list
    {
        $$ = create_node(RA_VALUES, "");
        $$->left = $2;
    }
    | query
    {
        $$ = $1;  // Subquery
    }
    ;

insert_value_list
    : LPAREN insert_value_items RPAREN
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->right = $2;
        $$ = list;
    }
    | insert_value_list COMMA LPAREN insert_value_items RPAREN
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->left = $1;
        list->right = $4;
        $$ = list;
    }
    ;

insert_value_items
    : insert_value
    {
        $$ = $1;
    }
    | insert_value_items COMMA insert_value
    {
        ASTNode* list = create_node(RA_VALUE_ITEMS, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
    }
    ;

insert_value
    : operand
    {
        $$ = $1;
    }
    | DEFAULT
    {
        $$ = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
    ;

/* UPDATE statement */
update_stmt
    : with_clause_opt UPDATE only_opt ID asterisk_opt as_id_opt set_clause from_clause where_clause
    {
        ASTNode* target = create_node(RA_RELATION, $4);

        // Apply WITH clause
        if ($1 && $1->type != RA_EMPTY) {
            target->left = $1;
        }

        if ($6->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, $6->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* update = create_node(RA_UPDATE, "");
        update->left = target;
        update->args = $7;  // SET clause
        
        if ($9->type != RA_EMPTY) {
            update->right = $9;  // WHERE condition
        }

        if ($8->type != RA_EMPTY) {
            if(update->right==NULL)update->right = $8;
            else{
                update->right->left = $8;
            }
        }
        
        
        $$ = update;
    }
    ;

only_opt
    : ONLY
    {
        $$ = create_node(RA_ATTRIBUTE, "ONLY");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

asterisk_opt
    : ASTERISK
    {
        $$ = create_node(RA_ATTRIBUTE, "*");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

set_clause
    : SET set_item_list
    {
        $$ = create_node(RA_SET, "");
        $$->left = $2;
    }
    ;

set_item_list
    : set_item
    {
        $$ = $1;
    }
    | set_item_list COMMA set_item 
    {
        ASTNode* list = create_node(RA_SET_LIST, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
    }
    ;

set_item
    : column_name EQ set_value
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = $1;
        assignment->right = $3;
        $$ = assignment;
    }
    | LPAREN column_name_list RPAREN EQ LPAREN insert_value_items RPAREN
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = $2;
        assignment->right = $6;
        $$ = assignment;
    }
    | LPAREN column_name_list RPAREN EQ ROW LPAREN insert_value_items RPAREN
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "= ROW");
        assignment->left = $2;
        assignment->right = $7;
        $$ = assignment;
    }
    | LPAREN column_name_list RPAREN EQ LPAREN query RPAREN
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = $2;
        assignment->right = $6;
        $$ = assignment;
    }
    ;

set_value
    : operand
    {
        $$ = $1;
    }
    | expression
    {
        $$ = $1;
    }
    | DEFAULT
    {
        $$ = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
    ;

column_name
    : modified_id
    {
        $$ = $1;
    }
    ;

/* DELETE statement */
delete_stmt
    : with_clause_opt DELETE FROM ID using_clause_opt where_clause
    {
        ASTNode* target = create_node(RA_RELATION, $4);
        
        // Apply WITH clause
        if ($1 && $1->type != RA_EMPTY) {
            target->left = $1;
        }

        ASTNode* delete = create_node(RA_DELETE, "");
        delete->left = target;
        
        if ($5->type != RA_EMPTY) {
            delete->right = $5;  // USING clause
        }
        
        if ($6->type != RA_EMPTY) {
            if(delete->right)delete->right->left = $6;  // WHERE condition
            else delete->right = $6;
        }
        
        $$ = delete;
    }
    ;

using_clause_opt
    : USING from_item_list
    {
        $$ = create_node(RA_USING, "");
        $$->args = $2;
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

/* EXPRESSION rules */
expression
    : and_condition
    {
        $$ = $1;
    }
    | expression OR and_condition
    {
        ASTNode* or_node = create_node(RA_OR, "OR");
        or_node->left = $1;
        or_node->right = $3;
        $$ = or_node;
    }
    ;

and_condition
    : condition
    {
        $$ = $1;
    }
    | and_condition AND condition
    {
        ASTNode* and_node = create_node(RA_AND, "AND");
        and_node->left = $1;
        and_node->right = $3;
        $$ = and_node;
    }
    ;

condition
    : LPAREN expression RPAREN
    {
        $$ = $2;
    }
    | NOT condition
    {
        ASTNode* not_node = create_node(RA_NOT, "NOT");
        not_node->left = $2;
        $$ = not_node;
    }
    | operand comparison_op operand
    {
        ASTNode* comp = create_node(RA_COMPARISON, $2->value);
        comp->left = $1;
        comp->right = $3;
        $$ = comp;
    }
    | operand IS not_opt NULL_VAL
    {
        char value[MAX_STRING_LENGTH];
        if ($3->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "IS NOT NULL");
        } else {
            snprintf(value, sizeof(value), "IS NULL");
        }
        
        ASTNode* null_check = create_node(RA_NULL_CHECK, value);
        null_check->left = $1;
        $$ = null_check;
    }
    /* | EXISTS LPAREN query RPAREN
    {
        ASTNode* exists = create_node(RA_EXISTS, "EXISTS");
        exists->left = $3;
        $$ = exists;
    } */
    | operand not_opt IN LPAREN in_items RPAREN
    {
        char value[MAX_STRING_LENGTH];
        if ($2->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "NOT IN");
        } else {
            snprintf(value, sizeof(value), "IN");
        }
        
        ASTNode* in_check = create_node(RA_IN, value);
        in_check->left = $1;
        in_check->right = $5;
        $$ = in_check;
    }
    /* | operand not_opt BETWEEN operand AND operand
    {
        char value[MAX_STRING_LENGTH];
        if ($2->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "NOT BETWEEN");
        } else {
            snprintf(value, sizeof(value), "BETWEEN");
        }
        
        ASTNode* between = create_node(RA_BETWEEN, value);
        between->left = $1;
        
        ASTNode* range = create_node(RA_RANGE, "AND");
        range->left = $4;
        range->right = $6;
        
        between->right = range;
        $$ = between;
    } */
    ;

not_opt
    : NOT
    {
        $$ = create_node(RA_ATTRIBUTE, "NOT");
    }
    | /* empty */
    {
        $$ = create_node(RA_EMPTY, "");
    }
    ;

in_items
    : column_list
    {
        $$ = $1;
    }
    | query
    {
        $$ = $1;
    }
    ;

comparison_op
    : EQ
    {
        $$ = create_node(RA_OPERATOR, "=");
    }
    | NE
    {
        $$ = create_node(RA_OPERATOR, "<>");
    }
    | LT
    {
        $$ = create_node(RA_OPERATOR, "<");
    }
    | GT
    {
        $$ = create_node(RA_OPERATOR, ">");
    }
    | LE
    {
        $$ = create_node(RA_OPERATOR, "<=");
    }
    | GE
    {
        $$ = create_node(RA_OPERATOR, ">=");
    }
    ;

operand
    : summand
    {
        $$ = $1;
    }
    | operand CONCAT summand
    {
        ASTNode* concat = create_node(RA_CONCAT, "||");
        concat->left = $1;
        concat->right = $3;
        $$ = concat;
    }
    ;

summand
    : factor
    {
        $$ = $1;
    }
    | summand PLUS factor
    {
        ASTNode* add = create_node(RA_ARITHMETIC, "+");
        add->left = $1;
        add->right = $3;
        $$ = add;
    }
    | summand MINUS factor
    {
        ASTNode* subtract = create_node(RA_ARITHMETIC, "-");
        subtract->left = $1;
        subtract->right = $3;
        $$ = subtract;
    }
    ;

factor
    : term
    {
        $$ = $1;
    }
    | factor ASTERISK term
    {
        ASTNode* multiply = create_node(RA_ARITHMETIC, "*");
        multiply->left = $1;
        multiply->right = $3;
        $$ = multiply;
    }
    | factor DIV term
    {
        ASTNode* divide = create_node(RA_ARITHMETIC, "/");
        divide->left = $1;
        divide->right = $3;
        $$ = divide;
    }
    ;

term
    : LPAREN operand RPAREN
    {
        $$ = $2;
    }
    | modified_id
    {
        $$ = $1;
    }
    | NUM
    {
        char value[32];
        snprintf(value, sizeof(value), "%d", $1);
        $$ = create_node(RA_LITERAL, value);
    }
    | STRING_LITERAL
    {
        $$ = create_node(RA_LITERAL, $1);
    }
    ;

%%



void yyerror(const char* s) {
    fprintf(stderr, "Parse error on line %d: %s at '%s'\n", yylineno, s, yytext);
    exit(1);
}

ASTNode* create_node(NodeType type, const char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    node->type = type;
    if (value) {
        strncpy(node->value, value, MAX_STRING_LENGTH - 1);
        node->value[MAX_STRING_LENGTH - 1] = '\0';
    } else {
        node->value[0] = '\0';
    }
    
    node->left = NULL;
    node->right = NULL;
    node->condition = NULL;
    node->from = NULL;
    node->args = NULL;
    node->assoc_left_done=0;
    node->assoc_right_done=0;
    return node;
}

scope_attr* merge_scopes(scope_attr* left, scope_attr* right) {
    scope_attr* merged = NULL;
    scope_attr* tail = NULL;

    for (scope_attr* curr = left; curr; curr = curr->next) {
        scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
        sa->name = strdup(curr->name);
        sa->alias = strdup(curr->alias);
        sa->tablename = curr->tablename;
        sa->next = NULL;

        if (!merged) merged = tail = sa;
        else { tail->next = sa; tail = sa; }
    }

    for (scope_attr* curr = right; curr; curr = curr->next) {
        scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
        sa->name = strdup(curr->name);
        sa->alias = strdup(curr->alias);
        sa->tablename = curr->tablename;
        sa->next = NULL;

        if (!merged) merged = tail = sa;
        else { tail->next = sa; tail = sa; }
    }

    return merged;
}


scope_attr* build_scope(ASTNode* node) {
    if (!node) return NULL;

    switch (node->type) {
        case RA_RELATION: {
            const char* table_name = NULL;
            const char* alias = NULL;

            table_name = alias = node->value;

            // Find table in global tables[]
            TABLE* table = NULL;
            for (int i = 0; i < num_tables; ++i) {
                if (strcmp(tables[i].TABLE_NAME, table_name) == 0) {
                    table = &tables[i];
                    break;
                }
            }

            if (!table) return NULL;

            // Build scope_attr list
            scope_attr* head = NULL;
            scope_attr* tail = NULL;

            for (int i = 0; i < table->num_attributes; ++i) {
                scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                sa->name = strdup(table->attr_list[i].name);
                sa->alias = strdup(alias);
                sa->tablename = table;
                sa->next = NULL;

                if (!head) head = tail = sa;
                else { tail->next = sa; tail = sa; }
            }

            return head;
        }

        
        case RA_ALIAS:{
            scope_attr* base_scope = build_scope(node->left);
            const char* alias = node->value;
            for(scope_attr* curr = base_scope; curr; curr = curr->next) {
                free(curr->alias);
                curr->alias = strdup(alias);
            }
            return base_scope;
        }

        case RA_PROJECTION: {
            scope_attr* base_scope = build_scope(node->left);

            scope_attr* head = NULL;
            scope_attr* tail = NULL;

            for (ASTNode* curr = node->args; curr; curr = curr->left) {
                if (curr->type == RA_ATTRIBUTE || curr->type == RA_ALIAS) {
                    ASTNode *alias_node = NULL;
                    if(curr->type == RA_ALIAS){
                        alias_node = curr;
                        curr = curr->left;
                    }
                    char* dot = strchr(curr->value, '.');
                    char alias_buf[256], name_buf[256];

                    if (dot) {
                        int len = dot - curr->value;
                        strncpy(alias_buf, curr->value, len);
                        alias_buf[len] = '\0';
                        strcpy(name_buf, dot + 1);
                    } else {
                        strcpy(alias_buf, "");
                        strcpy(name_buf, curr->value);
                    }

                    TABLE* matched_table = NULL;
                    for (scope_attr* s = base_scope; s; s = s->next) {
                        if ((strcmp(alias_buf, "") == 0 || strcmp(s->alias, alias_buf) == 0) &&
                            strcmp(s->name, name_buf) == 0) {
                            matched_table = s->tablename;
                            strcpy(alias_buf, s->alias);
                            break;
                        }
                    }

                    scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                    sa->alias = strdup(alias_buf);
                    if(alias_node) sa->name = strdup(alias_node->value);
                    else sa->name = strdup(name_buf);
                    sa->tablename = matched_table;
                    sa->next = NULL;

                    if (!head) head = tail = sa;
                    else { tail->next = sa; tail = sa; }
                }
            }

            free_scope(base_scope);
            return head;
        }


        case RA_SELECTION:
        case RA_DISTINCT:
        case RA_GROUPBY:
            return build_scope(node->left);
        case RA_ORDERBY:
            return build_scope(node->right);

        case RA_JOIN:
        case RA_JOIN_TYPE:{
            if(strcmp(node->value,"⋈")==0){
                scope_attr* left = build_scope(node->left);
                scope_attr* right = build_scope(node->right);
                return merge_scopes(left, right);
            }
            else{
                scope_attr* left = build_scope(node->left);
                scope_attr* right = build_scope(node->right);

                for (scope_attr* curr = left; curr; curr = curr->next) {
                    int matched = 0;
                    for(scope_attr *curr2 = right; curr2; curr2 = curr2->next){
                            
                        if(strcmp(curr->name,curr2->name)==0){
                            matched = 1;
                            break;
                        }
                    }
                    if(matched == 0){
                        scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                        sa->name = strdup(curr->name);
                        sa->alias = strdup(curr->alias);
                        sa->tablename = curr->tablename;
                        sa->next = right;

                        right = sa;
                    }
                }

                free_scope(left);
                return right;
            }
        }

        default:
            return build_scope(node->left);
    }
}


void print_subtree(ASTNode* node, int depth) {
    if (!node) return;

    switch (node->type) {
        case RA_ATTRIBUTE:
            printf("%s, ",node->value);
            break;
        case RA_LITERAL:
            printf("%s, ",node->value);
            break;
        default:
    }
    print_subtree(node->left, depth + 1);
    print_subtree(node->right, depth + 1);
}

ASTNode* deep_copy_tree(ASTNode* original) {
    if (!original) return NULL;
    
    ASTNode* copy = create_node(original->type, original->value);
    copy->left = deep_copy_tree(original->left);
    copy->right = deep_copy_tree(original->right);
    copy->args = deep_copy_tree(original->args);
    copy->condition = deep_copy_tree(original->condition);
    copy->from = deep_copy_tree(original->from);
    copy->assoc_left_done=original->assoc_left_done;
    copy->assoc_right_done=original->assoc_right_done;
    return copy;
}

ASTNode* append_condition(ASTNode* root, ASTNode* cond) {
    if (!root) return deep_copy_tree(cond);

    ASTNode* new_node = create_node(RA_AND, "AND");
    new_node->left = root;
    new_node->right = deep_copy_tree(cond);
    return new_node;
}

int condition_involves_only(ASTNode* cond, scope_attr* scope) {
    if (!cond) return 1;
    if (cond->type == RA_ATTRIBUTE) {
        char alias[256], attr[256];
        char* dot = strchr(cond->value, '.');
        if (dot) {
            strncpy(alias, cond->value, dot - cond->value);
            alias[dot - cond->value] = '\0';
            strcpy(attr, dot + 1);
        } else {
            strcpy(alias, "");
            strcpy(attr, cond->value);
        }

        for (scope_attr* s = scope; s; s = s->next) {
            if(strcmp(alias, "") == 0 || strcmp(s->alias, alias) == 0) {
                if (strcmp(s->name, attr) == 0) {
                    return 1;
                }
            }
        }
        return 0;
    }

    return condition_involves_only(cond->left, scope)
        && condition_involves_only(cond->right, scope)
        && condition_involves_only(cond->args, scope);
}

ASTNode* selection_pushdown(ASTNode* node) {
    if (!node) return NULL;

    int count = 0;
    ASTNode* conds[64]; // Assuming at most 64 AND conditions

    // Flatten condition tree (only handle AND chains here)
    void flatten_conditions(ASTNode* expr) {
        if (!expr) return;
        if (expr->type == RA_AND) {
            flatten_conditions(expr->left);
            flatten_conditions(expr->right);
        } else {
            conds[count++] = expr;
        }
    }

    // case: pushing the condition of join invloves only one side of the join as select node to reduce the join size
    if(node->type == RA_JOIN && node->condition){
        ASTNode* cond = node->condition;
        flatten_conditions(cond);

        scope_attr* left_scope = build_scope(node->left);
        scope_attr* right_scope = build_scope(node->right);

        // Step 1: Classify conditions
        ASTNode* left_conditions = NULL;
        ASTNode* right_conditions = NULL;
        ASTNode* remaining_conditions = NULL;

        for (int i = 0; i < count; i++) {
            ASTNode* c = conds[i];
            int in_left = condition_involves_only(c, left_scope);
            int in_right = condition_involves_only(c, right_scope);

            if (in_left) {
                left_conditions = append_condition(left_conditions, c);
            } else if (in_right) {
                right_conditions = append_condition(right_conditions, c);
            }
            else{
                remaining_conditions = append_condition(remaining_conditions, c);
            }
        }

        // Step 2: Push down to join children
        if (left_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = left_conditions;
            sel->left = node->left;
            node->left = sel;
            changed = 1;
        }

        if (right_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = right_conditions;
            sel->left = node->right;
            node->right = sel;
            changed = 1;
        }

        free_tree(node->condition);
        node->condition = remaining_conditions;

        free_scope(left_scope);
        free_scope(right_scope);
        if(changed) return node; 
    }

    // Case: σ(cond) over a join
    if (node->type == RA_SELECTION && node->left && node->left->type == RA_JOIN) {
        ASTNode* join_node = node->left;

        scope_attr* left_scope = build_scope(join_node->left);
        scope_attr* right_scope = build_scope(join_node->right);

        // Step 1: Break condition into ANDs
        ASTNode* cond = node->args;

        flatten_conditions(cond);

        // Step 2: Classify conditions
        ASTNode* left_conditions = NULL;
        ASTNode* right_conditions = NULL;
        ASTNode* join_conditions = NULL;

        for (int i = 0; i < count; i++) {
            ASTNode* c = conds[i];
            int in_left = condition_involves_only(c, left_scope);
            int in_right = condition_involves_only(c, right_scope);

            if (in_left) {
                left_conditions = append_condition(left_conditions, c);
            } else if (in_right) {
                right_conditions = append_condition(right_conditions, c);
            } else {
                join_conditions = append_condition(join_conditions, c);
            }
        }

        // Step 3: Push down to join children
        if (left_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = left_conditions;
            sel->left = join_node->left;
            join_node->left = sel;
        }

        if (right_conditions) {
            ASTNode* sel = create_node(RA_SELECTION, "");
            sel->args = right_conditions;
            sel->left = join_node->right;
            join_node->right = sel;
        }


        // Step 4: Keep remaining at the top if needed
        free_scope(left_scope);
        free_scope(right_scope);

        changed = 1;

        if (join_conditions) {
            if (join_node->condition) {
                // Merge existing join condition with new one using AND
                ASTNode* merged = create_node(RA_AND, "AND");
                merged->left = join_node->condition;
                merged->right = join_conditions;
                join_node->condition = merged;
            } else {
                join_node->condition = join_conditions;
            }
        }
        return join_node;
    }

    // Merge selects
    if (node->type == RA_SELECTION && node->left && node->left->type == RA_SELECTION) {
        // Merge conditions into one AND expression
        ASTNode* merged = create_node(RA_AND, "AND");
        merged->left = node->args;
        merged->right = node->left->args;

        node->args = merged;
        node->left = node->left->left;

        changed = 1;
    }

    if(changed) return node;
    node->left = selection_pushdown(node->left);
    if(changed) return node;
    node->right = selection_pushdown(node->right);
    return node;
}


int attribute_in_list(ASTNode* list, const char* attr) {
    for (ASTNode* curr = list; curr; curr = curr->args) {
        if (strcmp(curr->value, attr) == 0)
            return 1;
    }
    return 0;
}

ASTNode* deep_copy_shallow(ASTNode* node) {
    if (!node) return NULL;

    ASTNode* copy = create_node(node->type, node->value ? node->value : "");
    copy->args = NULL;
    copy->left = NULL;
    copy->right = NULL;
    copy->condition = NULL;
    copy->from = NULL;
    return copy;
}

ASTNode* merge_attribute_lists(ASTNode* list1, ASTNode* list2) {
    ASTNode* merged = NULL;
    ASTNode* tail = NULL;

    // Helper function to check if an attribute exists in a list
    int attribute_exists(ASTNode* list, const char* alias, const char* attr) {
        for (ASTNode* curr = list; curr; curr = curr->left) {
            char* dot = strchr(curr->value, '.');
            char curr_alias[256], curr_attr[256];
            
            if (dot) {
                int len = dot - curr->value;
                strncpy(curr_alias, curr->value, len);
                curr_alias[len] = '\0';
                strcpy(curr_attr, dot + 1);
            } else {
                strcpy(curr_alias, "");
                strcpy(curr_attr, curr->value);
            }
            
            if ((strcmp(alias, curr_alias) == 0) && (strcmp(attr, curr_attr) == 0)) {
                return 1;
            }
        }
        return 0;
    }

    // Add all attributes from list1
    for (ASTNode* curr = list1; curr; curr = curr->left) {
        ASTNode* node = deep_copy_shallow(curr);
        if (!merged) {
            merged = tail = node;
        } else {
            tail->left = node;
            tail = node;
        }
    }

    // Add attributes from list2 only if they don't exist in merged list
    for (ASTNode* curr = list2; curr; curr = curr->left) {
        char* dot = strchr(curr->value, '.');
        char alias[256], attr[256];

        if (dot) {
            int len = dot - curr->value;
            strncpy(alias, curr->value, len);
            alias[len] = '\0';
            strcpy(attr, dot + 1);
        } else {
            strcpy(alias, "");
            strcpy(attr, curr->value);
        }

        if (!attribute_exists(merged, alias, attr)) {
            ASTNode* node = deep_copy_shallow(curr);
            if (!merged) {
                merged = tail = node;
            } else {
                tail->left = node;
                tail = node;
            }
        }
    }

    return merged;
}


ASTNode* extract_attributes_from_conditions(ASTNode* node) {
    if (!node) return NULL;

    ASTNode* result = NULL;

    if (node->type == RA_ATTRIBUTE) {
        ASTNode* copy = deep_copy_tree(node);
        copy->args = NULL;
        result = copy;
    } else {
        ASTNode* left_attrs = extract_attributes_from_conditions(node->left);
        ASTNode* right_attrs = extract_attributes_from_conditions(node->right);
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->condition);
        ASTNode* args_attrs = extract_attributes_from_conditions(node->args);

        // Merge and free intermediate lists step-by-step
        result = merge_attribute_lists(left_attrs, right_attrs);
        free_tree(left_attrs);
        free_tree(right_attrs);

        ASTNode* temp = merge_attribute_lists(result, cond_attrs);
        free_tree(result);
        free_tree(cond_attrs);
        result = temp;

        temp = merge_attribute_lists(result, args_attrs);
        free_tree(result);
        free_tree(args_attrs);
        result = temp;
    }

    return result;
}

int is_projection_star_only(ASTNode *proj_node) {
    if (!proj_node || proj_node->type != RA_PROJECTION) return 0;

    ASTNode *args = proj_node->args;

    for (ASTNode *curr = args; curr; curr = curr->left) {
        if (curr->type == RA_ATTRIBUTE && strcmp(curr->value, "*") == 0) {
            return 1;
        }
    }

    scope_attr *scope = build_scope(proj_node->left);
    int all_found = 1;

    for (scope_attr *s = scope; s; s = s->next) {
        int found = 0;
        for (ASTNode *curr = args; curr; curr = curr->left) {
            if (curr->type != RA_ATTRIBUTE) continue;

            char *dot = strchr(curr->value, '.');
            char alias[256], attr[256];

            if (dot) {
                int len = dot - curr->value;
                strncpy(alias, curr->value, len);
                alias[len] = '\0';
                strcpy(attr, dot + 1);
            } else {
                strcpy(alias, "");
                strcpy(attr, curr->value);
            }

            if ((strcmp(alias, "") == 0 || strcmp(s->alias, alias) == 0) &&
                strcmp(s->name, attr) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            all_found = 0;
            break;
        }
    }

    free_scope(scope);
    return all_found;
}

attr* get_attr_from_table(TABLE* table, const char* attr_name) {
    for (int i = 0; i < table->num_attributes; ++i) {
        if (strcmp(table->attr_list[i].name, attr_name) == 0) {
            return &table->attr_list[i];
        }
    }
    return NULL;
}

ASTNode *projection_pushdown(ASTNode *node) {
    if (!node) return NULL;

    node->left = projection_pushdown(node->left);
    if(changed) return node;

    node->right = projection_pushdown(node->right);
    if(changed) return node;

    node->args = projection_pushdown(node->args);
    if(changed) return node;

    node->condition = projection_pushdown(node->condition);
    if(changed) return node;

    node->from = projection_pushdown(node->from);
    if(changed) return node;

    if (node->type == RA_PROJECTION && is_projection_star_only(node->args)) {
        ASTNode *temp = node->left;
        free_tree(node->args);
        free(node);
        changed = 1;
        return temp;
    }

    // Case: π → σ
    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_SELECTION) {
        if(node->assoc_left_done) return node;
        ASTNode *select_node = node->left;

        scope_attr *scope = build_scope(select_node);
        if (!scope) return node;

        // Step 1: Extract and merge condition + projection attributes
        ASTNode *cond_attrs = extract_attributes_from_conditions(select_node->args);
        ASTNode *merged_attrs = merge_attribute_lists(NULL, cond_attrs);

        ASTNode *new_proj = create_node(RA_PROJECTION, "");
        new_proj->args = merged_attrs;
        new_proj->left = select_node->left;
        select_node->left = new_proj;

        free_tree(cond_attrs);
        free_scope(scope);

        changed = 1;
        node->assoc_left_done=1;
        return node;
    }

    // Case: π → JOIN(any join)
    if (node->type == RA_PROJECTION &&
        node->left && node->left->type == RA_JOIN &&
        strcmp(node->left->value, "⋈ᴺ") != 0)  // Exclude natural joins
    {
        if(node->assoc_left_done) return node;
        node->assoc_left_done=1;
        ASTNode *join_node = node->left;

        // Combine projection and join condition attributes
        ASTNode *proj_attrs = node->args;
        ASTNode *cond_attrs = extract_attributes_from_conditions(join_node->condition);
        ASTNode *proj_cond_attrs = extract_attributes_from_conditions(proj_attrs);
        ASTNode *combined_attrs = merge_attribute_lists(proj_cond_attrs, cond_attrs);

        free_tree(cond_attrs);
        free(proj_cond_attrs);

        // Build scopes for both sides
        scope_attr *left_scope = build_scope(join_node->left);
        scope_attr *right_scope = build_scope(join_node->right);

        // Initialize attribute containers
        ASTNode *left_attrs = NULL, *right_attrs = NULL;
        ASTNode *tail_left = NULL, *tail_right = NULL;

        // Split attributes between left and right based on scope
        for (ASTNode *curr = combined_attrs; curr; curr = curr->left) {
            char alias[256] = "", attr[256];
            char *dot = strchr(curr->value, '.');

            if (dot) {
                int len = dot - curr->value;
                strncpy(alias, curr->value, len);
                alias[len] = '\0';
                strcpy(attr, dot + 1);
            } else {
                strcpy(attr, curr->value);  //  Unqualified (fallback)
            }

            int found_left = 0, found_right = 0;
            int match_count = 0;

            // Check in left scope
            for (scope_attr *s = left_scope; s; s = s->next) {
                if (strcmp(s->name, attr) == 0 &&
                    (alias[0] == '\0' || strcmp(s->alias, alias) == 0)) {
                    found_left = 1;
                    match_count++;
                }
            }

            // Check in right scope
            for (scope_attr *s = right_scope; s; s = s->next) {
                if (strcmp(s->name, attr) == 0 &&
                    (alias[0] == '\0' || strcmp(s->alias, alias) == 0)) {
                    found_right = 1;
                    match_count++;
                }
            }

            ASTNode *copy = deep_copy_shallow(curr);
            copy->args = NULL;

            if (found_left && !found_right) {
                if (!left_attrs) left_attrs = tail_left = copy;
                else { tail_left->left = copy; tail_left = copy; }
            } else if (found_right && !found_left) {
                if (!right_attrs) right_attrs = tail_right = copy;
                else { tail_right->left = copy; tail_right = copy; }
            }
        }

        // Push projections down to respective branches
        if (left_attrs) {
            ASTNode *left_proj = create_node(RA_PROJECTION, "");
            left_proj->args = left_attrs;
            left_proj->left = join_node->left;
            join_node->left = left_proj;
        }

        if (right_attrs) {
            ASTNode *right_proj = create_node(RA_PROJECTION, "");
            right_proj->args = right_attrs;
            right_proj->left = join_node->right;
            join_node->right = right_proj;
        }

        // Cleanup
        free_scope(left_scope);
        free_scope(right_scope);
        free_tree(combined_attrs);
        changed = 1;

        return node;
    }

    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_PROJECTION) {
        // Keep only attributes from outer projection
        ASTNode *temp = node->left;
        node->left = node->left->left;
        free_tree(temp->args);
        free(temp);
        changed = 1;
        return node;
    }

    return node;
}


void join_associativity(ASTNode* node,ASTNode* node2,ASTNode* org_node) {
    if (!node || changed) return;

    // Case: Current node is a join and right child is also a join (A ⋈ (B ⋈ C))
    if (node->type==RA_JOIN && node->left && node->left->type == RA_JOIN && node->assoc_left_done!=1) {
        /* printf("its me left yoooooooooooo\n"); */
        org_node->assoc_left_done=1;
        node->assoc_left_done=1;
        node2->assoc_left_done=1;
        ASTNode* A = (node->right);
        ASTNode* B = node->left->left;
        ASTNode* C = node->left->right;
        ASTNode* cond1 = node->condition;       // Condition between A and (B ⋈ C)
        ASTNode* cond2 = node->left->condition; // Condition between B and C
        ASTNode* and_node;

        if(cond1==NULL){
            and_node = cond2;
        }
        else if(cond2 ==NULL){
            and_node = cond1;
        }
        else{
            and_node = create_node(RA_AND, "AND");
            and_node->left = cond1;
            and_node->right = cond2;
        }

        node->right = deep_copy_tree(B);
        node->left->left = deep_copy_tree(A);
        node->left->right= deep_copy_tree(C);
        node->condition = deep_copy_tree(and_node);
        node->left->condition = NULL;

        node2->right = deep_copy_tree(C);
        node2->left->left = deep_copy_tree(B);
        node2->left->right= deep_copy_tree(A);
        node2->condition = deep_copy_tree(and_node);
        node2->left->condition = NULL;
        /* node = selection_pushdown(node);
        node2 = selection_pushdown(node2); */
        changed = 1;
        return;
    }
    if (node->type==RA_JOIN && node->right && node->right->type == RA_JOIN && node->assoc_right_done!=1) {
        /* printf("its me right yoooooooooooo\n"); */
        org_node->assoc_right_done=1;
        node->assoc_right_done=1;
        node2->assoc_right_done=1;
        ASTNode* A = node->left;
        ASTNode* B = node->right->left;
        ASTNode* C = node->right->right;
        ASTNode* cond1 = node->condition;       // Condition between A and (B ⋈ C)
        ASTNode* cond2 = node->right->condition; // Condition between B and C
        ASTNode* and_node;

        if(cond1==NULL){
            and_node = cond2;
        }
        else if(cond2 ==NULL){
            and_node = cond1;
        }
        else{
            and_node = create_node(RA_AND, "AND");
            and_node->left = cond1;
            and_node->right = cond2;
        }

        node->left = deep_copy_tree(B);
        node->right->left = deep_copy_tree(A);
        node->right->right= deep_copy_tree(C);
        node->condition = deep_copy_tree(and_node);
        node->right->condition = NULL;

        node2->left = deep_copy_tree(C);
        node2->right->left = deep_copy_tree(B);
        node2->right->right= deep_copy_tree(A);
        node2->condition = deep_copy_tree(and_node);
        node2->right->condition = NULL;
        changed = 1;
        return;
    }
    /* printf("not me %d %d %d\n",(node->left)?node->left->type:0,node->type,node->assoc_left_done); */
    join_associativity(node->left,node2->left,org_node->left);
    if(changed){
        return;
    }
    /* printf("not left\n"); */
    join_associativity(node->right,node2->right,org_node->right);
    return;
}

void apply_join_transf(ASTNode* node){
    if (!node) return;
    int changed_;
    changed=0;
    num_trees=1;
    all_trees[0] = node;
    do {
        changed_=0;
        changed=0;
        for(int i=0;i<num_trees && i<MAX_RES_TREE;i++){ 
            ASTNode* duplicate1 = deep_copy_tree(all_trees[i]);
            ASTNode* duplicate2 = deep_copy_tree(all_trees[i]);
            changed_ = 0;
            changed=0;
            join_associativity(duplicate1,duplicate2,all_trees[i]);
            if(changed){
                changed_ = 1;
                changed=0;
                if(num_trees < MAX_RES_TREE){
                    all_trees[num_trees] = duplicate1;
                    num_trees++;
                }
                if(num_trees < MAX_RES_TREE){
                    all_trees[num_trees] = duplicate2;
                    num_trees++;
                }
            }
        }
    } while (changed_&&num_trees<MAX_RES_TREE);
}

ASTNode* apply_transformations(ASTNode* node) {
    if (!node) return NULL;
    int changed_;
    do {
        changed_ = 0;
        changed = 0;

        ASTNode* dup_sel = deep_copy_tree(node);
        node = selection_pushdown(node);
        if (changed) {
            changed_ = 1;
            changed = 0;

            if (num_trees < MAX_RES_TREE) {
                all_trees[num_trees++] = dup_sel;
            } else {
                free_tree(dup_sel);
            }
        } else {
            free_tree(dup_sel);
        }

        ASTNode* dup_proj = deep_copy_tree(node);
        node = projection_pushdown(node);
        if (changed) {
            changed_ = 1;
            changed = 0;

            if (num_trees < MAX_RES_TREE) {
                all_trees[num_trees++] = dup_proj;
            } else {
                free_tree(dup_proj);
            }
        } else {
            free_tree(dup_proj);
        }

    } while (changed_);
    return node;
}


void print_tree(ASTNode* node, int depth) {
    if (!node) return;
    
    // Print indentation
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    if (node->type == RA_TRANSFORMED) {
        printf("[%s Transformation]\n", node->value);
        print_tree(node->left, depth + 1);
        return;
    }

    // Print node information
    switch (node->type) {
        case RA_EMPTY:
            printf("EMPTY\n");
            break;
        case RA_PROJECTION:
            printf("π-Project (%s)\n", node->value);
            break;
        case RA_SELECTION:
            printf("σ-Select[%s]\n", node->value);
            break;
        case RA_GROUPBY:
            printf("γ-Group by [%s]\n", node->value);
            break;
        case RA_ORDERBY:
            printf("τ-order by [%s]\n", node->value);
            break;
        case RA_JOIN:
            printf("%s-join\n", node->value);
            if (node->condition) {
                for (int i = 0; i < depth + 1; i++) printf("  ");
                printf("Condition:\n");
                print_tree(node->condition, depth + 2);
            }
            break;
        case RA_SET_OP:
            printf("%s-set_op\n", node->value);
            break;
        case RA_WITH:
            printf("WITH %s\n", node->value);
            break;
        case RA_WITH_LIST:
            printf("WITH LIST %s\n", node->value);
            break;
        case RA_WITH_QUERY:
            printf("WITH QUERY %s\n", node->value);
            break;
        case RA_RELATION:
            printf("Relation: %s\n", node->value);
            break;
        case RA_ATTRIBUTE:
            printf("Attribute: %s\n", node->value);
            break;
        case RA_ALIAS:
            printf("AS %s\n", node->value);
            break;
        case RA_LITERAL:
            printf("Literal: %s\n", node->value);
            break;
        case RA_COMPARISON:
            printf("Comparison: %s\n", node->value);
            break;
        case RA_ARITHMETIC:
            printf("Arithmetic: %s\n", node->value);
            break;
        case RA_DISTINCT:
            printf("δ (%s)\n", node->value);
            break;
        case RA_INSERT:
            printf("Insert: %s\n", node->value);
            break;
        case RA_UPDATE:
            printf("Update: %s\n", node->value);
            break;
        case RA_DELETE:
            printf("Delete: %s\n", node->value);
            break;
        case RA_VALUES:
            printf("Values: %s\n", node->value);
            break;
        case RA_VALUE_LIST:
            printf("Value List: %s\n", node->value);
            break;
        case RA_VALUE_ITEMS:
            printf("Value Items: %s(", node->value);
            print_subtree(node->left,depth);
            if(node->right)printf("%s)\n",node->right->value);
            else printf(")\n");
            return;
        case RA_COLUMN_LIST:
            printf("Column List: %s(", node->value);
            print_subtree(node->left,depth);
            if(node->right)printf("%s)\n",node->right->value);
            else printf(")\n");
            return;
        case RA_SET:
            printf("Set\n");
            break;
        case RA_SET_LIST:
            printf("Set List: %s\n", node->value);
            break;
        case RA_ASSIGNMENT:
            printf("Assignment: %s\n", node->value);
            break;
        case RA_USING:
            printf("Using: %s\n", node->value);
            break;
        case RA_FROM:
            printf("From: %s\n", node->value);
            break;
        case RA_JOIN_TYPE:
            printf("Join Type: %s\n", node->value);
            break;
        case RA_OR:
            printf("Or: %s\n", node->value);
            break;
        case RA_AND:
            printf("And: %s\n", node->value);
            break;
        case RA_NOT:
            printf("Not: %s\n", node->value);
            break;
        case RA_NULL_CHECK:
            printf("Null Check: %s\n", node->value);
            break;
        case RA_IN:
            printf("In: %s\n", node->value);
            break;
        case RA_RANGE:
            printf("Range: %s\n", node->value);
            break;
        case RA_CONCAT:
            printf("Concat: %s\n", node->value);
            break;
        case RA_ORDER_ITEM:
            printf("Odering by: %s\n",node->value);
            break;
        default:
            printf("Node: %d (%s)\n", node->type, node->value);
            break;
    }
    
    // Recursively print children
    // printf("ARGS:");
    print_tree(node->args,depth+1);
    // printf("LEFT:");
    print_tree(node->left, depth + 1);
    // printf("RIGHT:");
    print_tree(node->right, depth + 1);
}

void print_tree_scope(ASTNode* node,int level) {
    if (!node) return;

    // Full scope of the current node
    for(int i=0;i<level;i++){
        printf("  ");
    }

    scope_attr* full_scope = build_scope(node);
    printf("Scope: ");
    for (scope_attr* s = full_scope; s; s = s->next) {
        if (s->next)
            printf("%s.%s, ", s->alias, s->name);
        else
            printf("%s.%s", s->alias, s->name);
    }
    printf("\n");
    free_scope(full_scope);

    // Scope of left child
    print_tree_scope(node->left,level+1);
    print_tree_scope(node->right,level+1);
}

void change_attributes(ASTNode *node, scope_attr* scope_left, scope_attr* scope_right, scope_attr** extended, scope_attr** tail) {
    if (!node) return;
    
    if (node->type == RA_ATTRIBUTE) {
        char* dot = strchr(node->value, '.');
        if (dot) return; // Already qualified
        
        char attr[MAX_STRING_LENGTH];
        strcpy(attr, node->value);
        
        int matched = 0;
        scope_attr* matched_scope = NULL;
        
        // Check left scope first
        for (scope_attr* s = scope_left; s; s = s->next) {
            if (strcmp(s->name, attr) == 0) {
                matched++;
                matched_scope = s;
                
                // Add to extended required attributes
                int already_present = 0;
                for (scope_attr* e = *extended; e; e = e->next) {
                    if (strcmp(e->name, s->name) == 0 && strcmp(e->alias, s->alias) == 0) {
                        already_present = 1;
                        break;
                    }
                }
                
                if (!already_present) {
                    scope_attr* new_scope_node = (scope_attr *)malloc(sizeof(scope_attr));
                    new_scope_node->name = strdup(s->name);
                    new_scope_node->alias = strdup(s->alias);
                    new_scope_node->tablename = s->tablename;
                    new_scope_node->next = NULL;
                    
                    if (!(*extended)) {
                        *extended = new_scope_node;
                        *tail = new_scope_node;
                    } else {
                        (*tail)->next = new_scope_node;
                        *tail = new_scope_node;
                    }
                }
            }
        }
        
        // Check right scope if not found or to check for ambiguity
        for (scope_attr* s = scope_right; s; s = s->next) {
            if (strcmp(s->name, attr) == 0) {
                matched++;
                if (!matched_scope) matched_scope = s;
                
                // Add to extended required attributes
                int already_present = 0;
                for (scope_attr* e = *extended; e; e = e->next) {
                    if (strcmp(e->name, s->name) == 0 && strcmp(e->alias, s->alias) == 0) {
                        already_present = 1;
                        break;
                    }
                }
                
                if (!already_present) {
                    scope_attr* new_scope_node = (scope_attr *)malloc(sizeof(scope_attr));
                    new_scope_node->name = strdup(s->name);
                    new_scope_node->alias = strdup(s->alias);
                    new_scope_node->tablename = s->tablename;
                    new_scope_node->next = NULL;
                    
                    if (!(*extended)) {
                        *extended = new_scope_node;
                        *tail = new_scope_node;
                    } else {
                        (*tail)->next = new_scope_node;
                        *tail = new_scope_node;
                    }
                }
            }
        }
        
        
        // Qualify the attribute
        char qualified[MAX_STRING_LENGTH];
        snprintf(qualified, MAX_STRING_LENGTH, "%s.%s", matched_scope->alias, matched_scope->name);
        strcpy(node->value, qualified);
    }
    
    change_attributes(node->args, scope_left, scope_right, extended, tail);
    change_attributes(node->left, scope_left, scope_right, extended, tail);
    change_attributes(node->right, scope_left, scope_right, extended, tail);
    change_attributes(node->condition, scope_left, scope_right, extended, tail);
}

ASTNode* pre_transform_tree(ASTNode* node, scope_attr* req) {
    if (node == NULL) return NULL;

    // Handle DELETE No need to transform DELETE and 
    if (node->type == RA_DELETE) {
        return node;
    }

    // Handle UPDATE
    if (node->type == RA_UPDATE) {
        return node;
    }

    
    scope_attr* extended = NULL;
    scope_attr* tail = NULL;
    
    // Copy required attributes to extended list
    for (scope_attr* curr = req; curr; curr = curr->next) {
        scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
        new_attr->name = strdup(curr->name);
        new_attr->alias = strdup(curr->alias);
        new_attr->tablename = curr->tablename;
        new_attr->next = NULL;
        
        if (!extended) {
            extended = tail = new_attr;
        } else {
            tail->next = new_attr;
            tail = new_attr;
        }
    }
    
    // Build scopes for left and right children
    scope_attr* scope_left = build_scope(node->left);
    scope_attr* scope_right = build_scope(node->right);
    
    // Process node based on type
    if (node->type == RA_PROJECTION) {
        int all_attributes = is_projection_star_only(node);
        if(all_attributes){

            ASTNode *temp = node; 
            node = node->left;
            
            free_scope(extended);
            free_scope(scope_left);
            free_scope(scope_right);
            return node;
        }
        ASTNode* proj_attrs = node->args;
        
        if (is_projection_star_only(proj_attrs)) {
            // Star projection - no need to transform attributes
            node->left = pre_transform_tree(node->left, req);
            
            free_scope(extended);
            free_scope(scope_left);
            free_scope(scope_right);
            return node;
        }
        
        // Qualify attributes in projection list
        change_attributes(proj_attrs, scope_left, scope_right, &extended, &tail);
        
        // Add projected attributes to required list for child nodes
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->args);
        for (ASTNode* temp = cond_attrs; temp; temp = temp->left) {
            char alias[MAX_STRING_LENGTH] = "";
            char attr_name[MAX_STRING_LENGTH];
            char* dot = strchr(temp->value, '.');
            
            if (dot) {
                int len = dot - temp->value;
                strncpy(alias, temp->value, len);
                alias[len] = '\0';
                strcpy(attr_name, dot + 1);
            } else {
                strcpy(attr_name, temp->value);
            }
            
            // Check if already in extended list
            int already_present = 0;
            for (scope_attr* s = extended; s; s = s->next) {
                if (strcmp(s->name, attr_name) == 0 && 
                    (alias[0] == '\0' || strcmp(s->alias, alias) == 0)) {
                    already_present = 1;
                    break;
                }
            }
            
            if (!already_present) {
                scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
                new_attr->name = strdup(attr_name);
                new_attr->alias = strdup(alias);
                new_attr->tablename = NULL;
                new_attr->next = NULL;
                
                if (!extended) {
                    extended = tail = new_attr;
                } else {
                    tail->next = new_attr;
                    tail = new_attr;
                }
            }
        }
        free_tree(cond_attrs);
    } 
    else if (node->type == RA_SELECTION) {
        // Qualify attributes in selection condition
        change_attributes(node->args, scope_left, scope_right, &extended, &tail);
        
        // Add condition attributes to required list
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->args);
        for (ASTNode* temp = cond_attrs; temp; temp = temp->left) {
            char alias[MAX_STRING_LENGTH] = "";
            char attr_name[MAX_STRING_LENGTH];
            char* dot = strchr(temp->value, '.');
            
            if (dot) {
                int len = dot - temp->value;
                strncpy(alias, temp->value, len);
                alias[len] = '\0';
                strcpy(attr_name, dot + 1);
            } else {
                strcpy(attr_name, temp->value);
            }
            
            // Check if already in extended list
            int already_present = 0;
            for (scope_attr* s = extended; s; s = s->next) {
                if (strcmp(s->name, attr_name) == 0 && 
                    (alias[0] == '\0' || strcmp(s->alias, alias) == 0)) {
                    already_present = 1;
                    break;
                }
            }
            
            if (!already_present) {
                scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
                new_attr->name = strdup(attr_name);
                new_attr->alias = strdup(alias);
                new_attr->tablename = NULL;
                new_attr->next = NULL;
                
                if (!extended) {
                    extended = tail = new_attr;
                } else {
                    tail->next = new_attr;
                    tail = new_attr;
                }
            }
        }
        free_tree(cond_attrs);
    }
    else if (node->type == RA_JOIN && strcmp(node->value, "⋈") == 0) {
        // Qualify attributes in join condition
        change_attributes(node->condition, scope_left, scope_right, &extended, &tail);
        
        // Add condition attributes to required list
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->condition);
        for (ASTNode* temp = cond_attrs; temp; temp = temp->left) {

            char alias[MAX_STRING_LENGTH] = "";
            char attr_name[MAX_STRING_LENGTH];
            char* dot = strchr(temp->value, '.');
            
            if (dot) {
                int len = dot - temp->value;
                strncpy(alias, temp->value, len);
                alias[len] = '\0';
                strcpy(attr_name, dot + 1);
            } else {
                strcpy(attr_name, temp->value);
            }

            scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
            new_attr->name = strdup(attr_name);

            new_attr->alias = strdup(alias);
            new_attr->tablename = NULL;
            new_attr->next = NULL;
                
            if (!extended) {
                extended = tail = new_attr;
            } else {
                tail->next = new_attr;
                tail = new_attr;
            }
        }
        free_tree(cond_attrs);
        
        int left_has_required = 0;
        int right_has_required = 0;
        
        for (scope_attr* r = extended; r; r = r->next) {
            for (scope_attr* l = scope_left; l && !left_has_required; l = l->next) {
                if ((strcmp(r->alias, "") == 0 || strcmp(r->alias, l->alias) == 0) && 
                    strcmp(r->name, l->name) == 0) {
                    left_has_required = 1;
                    break;
                }
            }
            
            for (scope_attr* rght = scope_right; rght && !right_has_required; rght = rght->next) {
                if ((strcmp(r->alias, "") == 0 || strcmp(r->alias, rght->alias) == 0) && 
                    strcmp(r->name, rght->name) == 0) {
                    right_has_required = 1;
                    break;
                }
            }
            
            if (left_has_required && right_has_required) break;
        }
        
        // Prune join tree if appropriate
        if (left_has_required && !right_has_required) {
            // Only left side needed
            ASTNode* result = node->left;
            node->left = NULL;  // Prevent recursive free
            free_tree(node);
            
            // Process the left subtree
            result = pre_transform_tree(result, extended);
            
            free_scope(extended);
            free_scope(scope_left);
            free_scope(scope_right);
            return result;
        } else if (!left_has_required && right_has_required) {
            // Only right side needed
            ASTNode* result = node->right;
            node->right = NULL;  // Prevent recursive free
            free_tree(node);
            
            // Process the right subtree
            result = pre_transform_tree(result, extended);
            
            free_scope(extended);
            free_scope(scope_left);
            free_scope(scope_right);
            return result;
        }
    }
    else if(node->type == RA_JOIN){
        change_attributes(node->condition, scope_left, scope_right, &extended, &tail);
        
        // Add condition attributes to required list
        ASTNode* cond_attrs = extract_attributes_from_conditions(node->condition);
        for (ASTNode* temp = cond_attrs; temp; temp = temp->left) {

            char alias[MAX_STRING_LENGTH] = "";
            char attr_name[MAX_STRING_LENGTH];
            char* dot = strchr(temp->value, '.');
            
            if (dot) {
                int len = dot - temp->value;
                strncpy(alias, temp->value, len);
                alias[len] = '\0';
                strcpy(attr_name, dot + 1);
            } else {
                strcpy(attr_name, temp->value);
            }

            scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
            new_attr->name = strdup(attr_name);

            new_attr->alias = strdup(alias);
            new_attr->tablename = NULL;
            new_attr->next = NULL;
                
            if (!extended) {
                extended = tail = new_attr;
            } else {
                tail->next = new_attr;
                tail = new_attr;
            }
        }
        free_tree(cond_attrs);
    }

    else if (node->type == RA_ORDERBY) {
        scope_attr* base_scope = build_scope(node->left);

        // Qualify order attributes
        change_attributes(node->args, base_scope, NULL, &extended, &tail);

        // Extract attributes from order by args and add to required list
        ASTNode* order_attrs = extract_attributes_from_conditions(node->args);
        for (ASTNode* temp = order_attrs; temp; temp = temp->left) {
            char alias[MAX_STRING_LENGTH] = "";
            char attr_name[MAX_STRING_LENGTH];
            char* dot = strchr(temp->value, '.');

            if (dot) {
                int len = dot - temp->value;
                strncpy(alias, temp->value, len); alias[len] = '\0';
                strcpy(attr_name, dot + 1);
            } else {
                strcpy(attr_name, temp->value);
            }

            int already_present = 0;
            for (scope_attr* s = extended; s; s = s->next) {
                if (strcmp(s->name, attr_name) == 0 &&
                    (alias[0] == '\0' || strcmp(s->alias, alias) == 0)) {
                    already_present = 1;
                    break;
                }
            }

            if (!already_present) {
                scope_attr* new_attr = (scope_attr*)malloc(sizeof(scope_attr));
                new_attr->name = strdup(attr_name);
                new_attr->alias = strdup(alias);
                new_attr->tablename = NULL;
                new_attr->next = NULL;

                if (!extended) extended = tail = new_attr;
                else { tail->next = new_attr; tail = new_attr; }
            }
        }

        free_tree(order_attrs);
        
        // Continue pre-transform on ORDER BY's child
        if (node->left)
            node->left = pre_transform_tree(node->left, extended);

        free_scope(base_scope);
        free_scope(extended);
        free_scope(scope_left);
        free_scope(scope_right);
        return node;
    }
    
    // Recursively transform children if they exist
    if (node->left) {
        node->left = pre_transform_tree(node->left, extended);
    }
    
    if (node->right) {
        node->right = pre_transform_tree(node->right, extended);
    }
    
    free_scope(extended);
    free_scope(scope_left);
    free_scope(scope_right);
    return node;
}