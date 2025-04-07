%{
#include <stdio.h>
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

ASTNode* parse_tree[10];
int parse_tree_count =0;

extern int num_tables;
extern TABLE *tables;
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
%token INNER LEFT RIGHT FULL CROSS JOIN ON IS NOT NULL_VAL 

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
%type <node> join_type set_op modified_id

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
        parse_tree[parse_tree_count] = $1;
        parse_tree_count++;
        printf("\nOriginal Relational Algebra Tree for sql statement %d:\n",parse_tree_count);
        print_tree($1, 0);
        
        ASTNode* transformed_both = apply_transformations(deep_copy_tree($1));
        printf("\nTree after Transformations:\n");
        print_tree(transformed_both, 0);
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
            base_tree->left = $1;
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
            ASTNode* order = create_node(RA_ORDERBY, "");
            order->left = $$;
            $$ = order;
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
        $$ = create_node(RA_ALIAS, $1);
        $$->left = $4;
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
        $$ = $1;
        $$->left=col;
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
    : LPAREN from_item_list RPAREN
    {
        $$ = $2;
    }
    | from_item
    {
        $$ = $1;
    }
    | from_item_list COMMA from_item
    {
        ASTNode* cross_join = create_node(RA_CROSS_JOIN, "×");  // Cross product
        cross_join->left = $1;
        cross_join->right = $3;
        $$ = cross_join;
    }
    ;

from_item
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
            alias->left = create_node(RA_RELATION, $2->value);
            $$ = alias;
        } else {
            $$ = create_node(RA_RELATION, $2->value);
            $$->left = $2;
        }
    }
    | from_item join_type ID as_id_opt ON expression
    {
        ASTNode* right_relation;
        if ($4->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, $4->value);
            right_relation->left = create_node(RA_RELATION, $3);
        } else {
            right_relation = create_node(RA_RELATION, $3);
        }
        
        ASTNode* join = create_node(RA_JOIN, $2->value);
        join->left = $1;
        join->right = right_relation;
        
        // Add join condition
        join->condition = $6;
        
        $$ = join;
    }
    | from_item join_type ID as_id_opt
    {
        ASTNode* right_relation;
        if ($4->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, $4->value);
            right_relation->left = create_node(RA_RELATION, $3);
        } else {
            right_relation = create_node(RA_RELATION, $3);
        }
        
        ASTNode* join = create_node(RA_JOIN, $2->value);
        join->left = $1;
        join->right = right_relation;
        
        $$ = join;
    }
    ;

join_type
    : INNER JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈");  // Natural join symbol
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
        $$ = create_node(RA_JOIN_TYPE, "×");  // Cross join symbol
    }
    | JOIN
    {
        $$ = create_node(RA_JOIN_TYPE, "⋈");  // Natural join symbol
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
    }
    | order_item_list COMMA order_item
    {
        ASTNode* list = create_node(RA_ORDER_LIST, "");
        list->left = $1;
        list->right = $3;
        $$ = list;
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
        $$ = $2;
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
    
    return node;
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
    return copy;
}

ASTNode* selection_pushdown(ASTNode* node) {
    if (!node) return NULL;

    if (node->type == RA_SELECTION && node->left && node->left->type == RA_JOIN) {
        ASTNode* join_node = node->left;
        ASTNode* condition = node->args;

        // Check if the condition only involves attributes from the left relation
        if (condition_involves_only(condition, join_node->left)) {
            // Create a new selection node to push down to the left relation
            ASTNode* new_selection = create_node(RA_SELECTION, "σ");
            new_selection->args = deep_copy_tree(condition);
            new_selection->left = deep_copy_tree(join_node->left);

            // Create a new join node with the selection applied to the left
            ASTNode* new_join = create_node(RA_JOIN, join_node->value);
            new_join->left = new_selection;
            new_join->right = deep_copy_tree(join_node->right);
            new_join->condition = deep_copy_tree(join_node->condition);

            // Return the new join node directly
            return new_join;
        }
    }

    // Recursively apply selection pushdown to children
    node->left = selection_pushdown(node->left);
    node->right = selection_pushdown(node->right);
    return node;
}

ASTNode* projection_pushdown(ASTNode* node) {
    if (!node) return NULL;

    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_JOIN) {
        ASTNode* join_node = node->left;
        ASTNode* projection_attrs = node->args;

        // Extract attributes relevant to the left and right relations
        ASTNode* left_attrs = extract_attributes(projection_attrs, join_node->left);
        ASTNode* right_attrs = extract_attributes(projection_attrs, join_node->right);

        // Create projection nodes for the left and right subtrees
        ASTNode* new_left = create_node(RA_PROJECTION, "π");
        new_left->args = left_attrs;
        new_left->left = deep_copy_tree(join_node->left);

        ASTNode* new_right = create_node(RA_PROJECTION, "π");
        new_right->args = right_attrs;
        new_right->left = deep_copy_tree(join_node->right);

        // Create a new join node with the projected subtrees
        ASTNode* new_join = create_node(RA_JOIN, join_node->value);
        new_join->left = new_left;
        new_join->right = new_right;
        new_join->condition = deep_copy_tree(join_node->condition);
        
        return new_join;
    }

    // Recursively apply projection pushdown to children
    node->left = projection_pushdown(node->left);
    node->right = projection_pushdown(node->right);
    return node;
}

ASTNode* apply_transformations(ASTNode* node) {
    if (!node) return NULL;
    int changed;
    do {
        changed = 0;
        ASTNode* original = deep_copy_tree(node);
        ASTNode* after_selection = selection_pushdown(node);
        if (after_selection != node) {
            node = after_selection;
            changed = 1;
        }

        ASTNode* after_projection = projection_pushdown(node);
        if (after_projection != node) {
            node = after_projection;
            changed = 1;
        }
    } while (changed);

    return node;
}

int condition_involves_only(ASTNode* condition, ASTNode* relation) {
    // implementation that checks if condition only uses attributes from relation
    return 1; // Assume true for demonstration
}

ASTNode* extract_attributes(ASTNode* projection, ASTNode* relation) {
    // implementation that filters attributes relevant to the relation
    return deep_copy_tree(projection); // Simplified for demonstration
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
        case RA_CROSS_JOIN:
            printf("×-cross join\n");
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
        default:
            printf("Node: %d (%s)\n", node->type, node->value);
            break;
    }
    
    // Recursively print children
    print_tree(node->args,depth+1);
    print_tree(node->left, depth + 1);
    print_tree(node->right, depth + 1);
}

