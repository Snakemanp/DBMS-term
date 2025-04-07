#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sql_parser.h"

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