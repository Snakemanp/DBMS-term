#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sql_parser.h"
#include <math.h>

// ASTNode* parse_tree = NULL;
extern FILE *yyin;
extern int yyparse();
extern ASTNode *parse_tree[10];
extern int parse_tree_count;

TABLE *tables = NULL;
int num_tables = 0;

void free_tree(ASTNode *node)
{
    if (!node)
        return;

    free_tree(node->left);
    free_tree(node->right);
    free_tree(node->condition);
    free_tree(node->from);
    free(node);
}

void read_table_data();

int main(int argc, char **argv)
{
    read_table_data();
    // int yyin;
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (!yyin)
        {
            perror("Cannot open input file");
            return 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        parse_tree[i] = NULL;
    }

    yyparse();

    for (int i = 0; i < parse_tree_count; i++)
    {
        // printf("Parse tree for statement %d:\n", i + 1);
        // print_tree(parse_tree[i], 0);
        free_tree(parse_tree[i]);
    }

    if (yyin != stdin)
    {
        fclose(yyin);
    }

    return 0;
}

void read_table_data()
{
    FILE *data_base = fopen("database.txt", "r");
    if (!data_base)
    {
        perror("Cannot open data_base.txt");
        exit(1);
    }

    fscanf(data_base, "%d", &num_tables);

    tables = (TABLE *)malloc(num_tables * sizeof(TABLE));
    if (!tables)
    {
        perror("Memory allocation failed for tables");
        fclose(data_base);
        exit(1);
    }

    for (int i = 0; i < num_tables; ++i)
    {
        char table_name[100];
        int num_attributes, num_tuples;

        fscanf(data_base, " TABLE %s %d %d", table_name, &num_attributes, &num_tuples);

        tables[i].TABLE_NAME = strdup(table_name);
        tables[i].num_attributes = num_attributes;
        tables[i].num_tuples = num_tuples;

        tables[i].attr_list = (attr *)malloc(num_attributes * sizeof(attr));
        if (!tables[i].attr_list)
        {
            perror("Memory allocation failed for attributes");
            fclose(data_base);
            exit(1);
        }

        for (int j = 0; j < num_attributes; ++j)
        {
            char attr_name[100];
            int flag, max_len;

            fscanf(data_base, " %s %d %d", attr_name, &flag, &max_len);

            tables[i].attr_list[j].name = strdup(attr_name);
            tables[i].attr_list[j].flag = flag;
            tables[i].attr_list[j].max_len = max_len;
        }
    }

    fclose(data_base);

    for (int i = 0; i < num_tables; i++)
    {
        printf("Table Name: %s\n", tables[i].TABLE_NAME);
        printf("Number of Attributes: %d\n", tables[i].num_attributes);
        printf("Number of Tuples: %d\n", tables[i].num_tuples);
        for (int j = 0; j < tables[i].num_attributes; j++)
        {
            printf("Attribute Name: %s, Flag: %d, Max Length: %d\n", tables[i].attr_list[j].name, tables[i].attr_list[j].flag, tables[i].attr_list[j].max_len);
        }
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
}

void free_scope(scope_attr *scope)
{
    scope_attr *current = scope;
    while (current != NULL)
    {
        scope_attr *next = current->next;
        free(current->name);
        free(current->alias);
        free(current);
        current = next;
    }
}

float estimate_selectivity(ASTNode *cond)
{
    if (!cond)
        return 1.0f;

    switch (cond->type)
    {
    case RA_AND:
    {
        float left = estimate_selectivity(cond->left);
        float right = estimate_selectivity(cond->right);
        return left * right;
    }
    case RA_OR:
    {
        float left = estimate_selectivity(cond->left);
        float right = estimate_selectivity(cond->right);
        return left + right - (left * right);
    }
    case RA_COMPARISON:
    {
        if (!cond->left || cond->left->type != RA_ATTRIBUTE)
            return 0.5f;

        // Try to guess selectivity based on operator
        const char *op = cond->value;
        if (strcmp(op, "=") == 0)
            return 0.1f;
        if (strcmp(op, "!=") == 0)
            return 0.9f;
        if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 ||
            strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
            return 0.33f;

        return 0.5f; // fallback
    }
    default:
        return 0.5f;
    }
}

float estimate_join_selectivity(ASTNode *condition, scope_attr *left_scope, scope_attr *right_scope)
{
    if (!condition || condition->type != RA_COMPARISON)
        return 1.0f;

    if (strcmp(condition->value, "=") != 0)
        return 0.1f;

    ASTNode *left_attr = condition->left;
    ASTNode *right_attr = condition->right;

    if (!left_attr || !right_attr || left_attr->type != RA_ATTRIBUTE || right_attr->type != RA_ATTRIBUTE)
        return 0.1f;

    // Parse aliases and attribute names
    char alias1[256], name1[256], alias2[256], name2[256];
    sscanf(left_attr->value, "%[^.].%s", alias1, name1);
    sscanf(right_attr->value, "%[^.].%s", alias2, name2);

    int distinct1 = 0;
    int distinct2 = 0;

    // Search left scope
    for (scope_attr *s = left_scope; s; s = s->next)
    {
        if (strcmp(s->alias, alias1) == 0 && strcmp(s->name, name1) == 0 && s->tablename != NULL)
        {
            for (int i = 0; i < s->tablename->num_attributes; i++)
            {
                if (strcmp(s->tablename->attr_list[i].name, name1) == 0)
                {
                    distinct1 = s->tablename->attr_list[i].max_len; // you may rename to 'distinct_count'
                    break;
                }
            }
        }
    }

    for (scope_attr *s = right_scope; s; s = s->next)
    {
        if (strcmp(s->alias, alias2) == 0 && strcmp(s->name, name2) == 0 && s->tablename != NULL)
        {
            for (int i = 0; i < s->tablename->num_attributes; i++)
            {
                if (strcmp(s->tablename->attr_list[i].name, name2) == 0)
                {
                    distinct2 = s->tablename->attr_list[i].max_len;
                    break;
                }
            }
        }
    }

    int max_distinct = (distinct1 > distinct2) ? distinct1 : distinct2;
    if (max_distinct == 0)
        max_distinct = 1000; // avoid div-by-zero

    float sel = 1.0f / max_distinct;
    return sel;
}

int estimate_selection_cost(ASTNode *condition, scope_attr *scope)
{
    if (!condition)
        return 0;

    float sel = estimate_selectivity(condition);
    printf("Slectivity: %f\n", sel);
    int cost = 0;

    // Extract attributes used in condition
    ASTNode *attr_list = extract_attributes_from_conditions(condition);

    for (ASTNode *curr = attr_list; curr; curr = curr->args)
    {
        if (!curr || curr->type != RA_ATTRIBUTE)
            continue;

        char *attr_str = curr->value;
        char alias[256], attr_name[256];
        char *dot = strchr(attr_str, '.');

        if (dot)
        {
            int len = dot - attr_str;
            strncpy(alias, attr_str, len);
            alias[len] = '\0';
            strcpy(attr_name, dot + 1);
        }
        else
        {
            strcpy(alias, "");
            strcpy(attr_name, attr_str);
        }

        // Resolve attribute in scope
        TABLE *table = NULL;
        int table_size = 1000; // default
        int indexed = 0;
        int found_count = 0;

        for (scope_attr *s = scope; s; s = s->next)
        {
            if ((strcmp(alias, "") == 0 && strcmp(s->name, attr_name) == 0) ||
                (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr_name) == 0))
            {
                table = s->tablename;
                if (!table)
                    continue;

                found_count++;

                table_size = table->num_tuples;

                for (int i = 0; i < table->num_attributes; i++)
                {
                    if (strcmp(table->attr_list[i].name, attr_name) == 0)
                    {
                        indexed = table->attr_list[i].flag;
                        break;
                    }
                }
                break;
            }
        }

        if (!table || found_count > 1)
        {
            continue; // ambiguous or not found
        }

        // Calculate cost
        if (indexed)
        {
            cost += (int)(log2(table_size) + table_size * sel);
        }
        else
        {
            cost += (int)(table_size * (sel + 1));
        }
    }

    free_tree(attr_list);
    return cost;
}

int estimate_width(scope_attr *scope)
{
    int count = 0;
    for (scope_attr *s = scope; s; s = s->next)
        count++;
    return count;
}

int estimate_cardinality(ASTNode *node)
{
    if (!node)
        return 0;

    switch (node->type)
    {
    case RA_RELATION:
    case RA_ALIAS:
    {
        const char *table_name = (node->type == RA_ALIAS && node->left)
                                     ? node->left->value
                                     : node->value;
        for (int i = 0; i < num_tables; ++i)
        {
            if (strcmp(tables[i].TABLE_NAME, table_name) == 0)
                return tables[i].num_tuples;
        }
        return 1000; // default/fallback
    }

    case RA_SELECTION:
        return (int)(estimate_cardinality(node->left) * estimate_selectivity(node->args));

    case RA_PROJECTION:
    case RA_DISTINCT:
        return estimate_cardinality(node->left); // no change in cardinality assumed

    case RA_JOIN:
    {
        int left = estimate_cardinality(node->left);
        int right = estimate_cardinality(node->right);

        scope_attr *left_scope = build_scope(node->left);
        scope_attr *right_scope = build_scope(node->right);

        float sel = estimate_join_selectivity(node->condition, left_scope, right_scope);

        free_scope(left_scope);
        free_scope(right_scope);

        return (int)(left * right * sel);
    }

    case RA_GROUPBY:
    case RA_ORDERBY:
        return estimate_cardinality(node->left); // group/order doesn’t change size for now

    default:
        return estimate_cardinality(node->left); // fallback recursive
    }
}

long long int cost_estimation(ASTNode *node)
{
    if (node == NULL)
        return 0;

    long long int cost = 0;

    switch (node->type)
    {
    case RA_SELECTION:
    {
        scope_attr *scope = build_scope(node);
        long long int sel_cost = estimate_selection_cost(node->args, scope);
        free_scope(scope);
        cost += sel_cost;
        break; // DO NOT return early
    }

    case RA_JOIN:
    {
        int left_rows = estimate_cardinality(node->left);
        int right_rows = estimate_cardinality(node->right);

        scope_attr *left_scope = build_scope(node->left);
        scope_attr *right_scope = build_scope(node->right);

        int width_left = estimate_width(left_scope);
        int width_right = estimate_width(right_scope);

        float join_sel = estimate_join_selectivity(node->condition, left_scope, right_scope);

        free_scope(left_scope);
        free_scope(right_scope);

        long long int join_output = (long long int)((long long int)left_rows * right_rows * join_sel);

        long long int join_cost = (long long int)(left_rows * width_left) + (right_rows * width_right) + (long long int)(join_output * (long long int)(width_left + width_right));

        cost += cost_estimation(node->left);
        cost += cost_estimation(node->right);

        // Step 5: Return total
        return cost + join_cost;
    }

    default:
        break;
    }

    // Continue recursion
    long long int left_cost = cost_estimation(node->left), right_cost = cost_estimation(node->right);
    cost += left_cost;
    cost += right_cost;
    return cost;
}
