#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sql_parser.h"
#include <math.h>

#define ATT_SIZE 25

// ASTNode* parse_tree = NULL;
extern FILE *yyin;
extern long long yyparse();
extern ASTNode *parse_tree[10];
extern long long parse_tree_count;

TABLE *tables = NULL;
long long num_tables = 0;

long long tuples_per_block(ASTNode *node)
{
    if (!node)
        return 0; // Invalid node
    scope_attr *att = build_scope(node);
    if (!att)
        return 0; // No attributes or scope failed
    long long count_atts = 0;
    scope_attr *current = att;
    while (current)
    {
        count_atts++;
        current = current->next;
    }
    long long tuple_size = count_atts * ATT_SIZE;
    long long result = (tuple_size > 0) ? (BLOCK_SIZE / tuple_size) : 0;
    free_scope(att); // Free the scope to avoid memory leaks
    return result;
}

// Helper functions for statistics retrieval (unchanged)
long long get_num_tuples(const char *table_name)
{
    for (long long i = 0; i < num_tables; i++)
    {
        if (strcmp(tables[i].TABLE_NAME, table_name) == 0)
        {
            return tables[i].num_tuples;
        }
    }
    return -1; // Table not found
}

long long get_num_distinct(const char *table_name, const char *attr_name)
{
    char attr_copy[256];
    strcpy(attr_copy, attr_name);
    char *dot_pos = strchr(attr_copy, '.');
    if (dot_pos != NULL)
    {
        attr_name = dot_pos + 1;
    }
    for (long long i = 0; i < num_tables; i++)
    {
        if (strcmp(tables[i].TABLE_NAME, table_name) == 0)
        {
            for (long long j = 0; j < tables[i].num_attributes; j++)
            {
                if (strcmp(tables[i].attr_list[j].name, attr_name) == 0)
                {
                    return tables[i].attr_list[j].num_distinct;
                }
            }
        }
    }
    // printf("hello\n");
    return -1; // Attribute not found
}

long long get_flag(const char *table_name, const char *attr_name)
{
    for (long long i = 0; i < num_tables; i++)
    {
        if (strcmp(tables[i].TABLE_NAME, table_name) == 0)
        {
            for (long long j = 0; j < tables[i].num_attributes; j++)
            {
                if (strcmp(tables[i].attr_list[j].name, attr_name) == 0)
                {
                    return tables[i].attr_list[j].flag;
                }
            }
        }
    }
    return -1; // Attribute not found
}

long long get_num_blocks(const char *table_name)
{
    long long num_tuples = get_num_tuples(table_name);
    if (num_tuples == -1)
        return -1;
    return (num_tuples + TUPLES_PER_BLOCK - 1) / TUPLES_PER_BLOCK; // Ceiling division
}

const char *get_table_name(ASTNode *node)
{
    if (!node)
        return NULL;
    if (node->type == RA_RELATION)
        return node->value;
    if (node->type == RA_ALIAS && node->left && node->left->type == RA_RELATION)
        return node->left->value;
    return NULL;
}

// Selectivity Estimation Functions (No Histogram, Uniform Distribution)
long long estimate_selection_size(ASTNode *condition, ASTNode *input)
{
    if (!input)
        return 0;
    long long n_input = estimate_size(input);
    if (!condition)
        return n_input;

    if (condition->type == RA_COMPARISON)
    {
        ASTNode *left = condition->left;
        ASTNode *right = condition->right;
        const char *op = condition->value;
        if (left && right && op && left->type == RA_ATTRIBUTE && right->type == RA_LITERAL)
        {
            const char *attr_name = left->value;
            long long V_A = estimate_distinct_values(input, attr_name);
            if (V_A > 0)
            {
                if (strcmp(op, "=") == 0)
                {
                    return n_input / V_A; // Selectivity = 1/V(A, e)
                }
                else if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 ||
                         strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
                {
                    return n_input / 2; // Approximate 50% selectivity for range
                }
            }
        }
    }
    else if (condition->type == RA_AND)
    {
        long long size_left = estimate_selection_size(condition->left, input);
        long long size_right = estimate_selection_size(condition->right, input);
        double sel_left = (double)size_left / n_input;
        double sel_right = (double)size_right / n_input;
        return (long long)(sel_left * sel_right * n_input);
    }
    else if (condition->type == RA_OR)
    {
        long long size_left = estimate_selection_size(condition->left, input);
        long long size_right = estimate_selection_size(condition->right, input);
        double sel_left = (double)size_left / n_input;
        double sel_right = (double)size_right / n_input;
        return (long long)((sel_left + sel_right - sel_left * sel_right) * n_input);
    }
    else if (condition->type == RA_NOT)
    {
        long long size_inner = estimate_selection_size(condition->left, input);
        return n_input - size_inner;
    }
    return n_input / 2; // Default: halve the size if condition is complex
}

long long estimate_join_size(ASTNode *join_node, ASTNode *left, ASTNode *right)
{
    if (!join_node || !left || !right)
        return 0;
    long long n_left = estimate_size(left);
    long long n_right = estimate_size(right);
    if (n_left == 0 || n_right == 0)
        return 0;

    ASTNode *condition = join_node->condition;
    if (!condition || condition->type != RA_COMPARISON || strcmp(condition->value, "=") != 0)
    {
        return n_left * n_right; // Cross product
    }

    ASTNode *left_attr = condition->left;
    ASTNode *right_attr = condition->right;
    if (!left_attr || !right_attr || left_attr->type != RA_ATTRIBUTE ||
        right_attr->type != RA_ATTRIBUTE)
    {
        return n_left * n_right;
    }

    const char *attr_left = left_attr->value;
    const char *attr_right = right_attr->value;
    long long V_left = estimate_distinct_values(left, attr_left);
    long long V_right = estimate_distinct_values(right, attr_right);
    if (V_left <= 0 || V_right <= 0)
    {
        return n_left * n_right / 2; // Fallback: halve cross product
    }

    long long max_V = (V_left > V_right) ? V_left : V_right;
    return (n_left * n_right) / max_V; // Equi-join formula
}

// long long estimate_projection_size(ASTNode *node) {
//     if (!node || node->type != RA_PROJECTION) return estimate_size(node->left);
//     ASTNode *args = node->args;
//     if (args && args->type == RA_ATTRIBUTE && strcmp(args->value, "*") == 0) {
//         return estimate_size(node->left); // No duplicate elimination
//     }
//     // For single attribute projection, size is V(A, r)
//     const char *table_name = get_table_name(node->left);
//     printf("hi2\n");
//     return get_num_distinct(table_name, args->value);
// }

long long estimate_projection_size(ASTNode *node)
{
    if (!node || node->type != RA_PROJECTION)
        return 0;
    return estimate_size(node->left); // Size unchanged, duplicates kept
}

long long estimate_aggregation_size(ASTNode *node)
{
    if (!node || node->type != RA_GROUPBY)
        return estimate_size(node->left);
    ASTNode *group_attrs = node->args;
    if (!group_attrs)
        return 1; // No grouping: one output tuple

    if (group_attrs->type == RA_ATTRIBUTE && group_attrs->args == NULL)
    {
        // Single attribute: number of groups = V(A, e)
        return estimate_distinct_values(node->left, group_attrs->value);
    }
    else
    {
        // Multiple attributes: approximate as min(V(Ai, e))
        long long min_V = estimate_size(node->left);
        ASTNode *curr = group_attrs;
        while (curr)
        {
            if (curr->type == RA_ATTRIBUTE)
            {
                long long V = estimate_distinct_values(node->left, curr->value);
                if (V > 0 && V < min_V)
                    min_V = V;
            }
            curr = curr->args;
        }
        return min_V > 0 ? min_V : estimate_size(node->left) / 2;
    }
}

long long estimate_set_operation_size(ASTNode *node)
{
    if (!node || node->type != RA_SET_OP)
        return 0;
    long long size_left = estimate_size(node->left);
    long long size_right = estimate_size(node->right);

    if (strcmp(node->value, "∪") == 0)
    {
        return size_left + size_right; // Upper bound
    }
    else if (strcmp(node->value, "∩") == 0)
    {
        return size_left < size_right ? size_left : size_right; // Minimum
    }
    else if (strcmp(node->value, "−") == 0)
    {
        return size_left; // Upper bound
    }
    return 0;
}

long long estimate_outer_join_size(ASTNode *join_node)
{
    if (!join_node || !join_node->left || !join_node->right)
        return 0;
    ASTNode *left = join_node->left;
    ASTNode *right = join_node->right;
    long long join_size = estimate_join_size(join_node, left, right);
    long long left_size = estimate_size(left);
    long long right_size = estimate_size(right);

    if (strcmp(join_node->value, "⟕") == 0)
    {                     // Left outer join
        return left_size; // At least left_size, assuming most rows match
    }
    else if (strcmp(join_node->value, "⟖") == 0)
    { // Right outer join
        return right_size;
    }
    else if (strcmp(join_node->value, "⟗") == 0)
    {                                              // Full outer join
        return left_size + right_size - join_size; // Approximate
    }
    return join_size; // Default to inner join size
}
long long estimate_size(ASTNode *node)
{
    if (!node)
        return 0;

    switch (node->type)
    {
    case RA_RELATION:
        return get_num_tuples(node->value);
    case RA_SELECTION:
        return estimate_selection_size(node->args, node->left);
    case RA_JOIN:
        return estimate_join_size(node, node->left, node->right);
    case RA_PROJECTION:
        return estimate_projection_size(node);
    case RA_GROUPBY:
        return estimate_aggregation_size(node);
    case RA_SET_OP:
        return estimate_set_operation_size(node); // Assume unchanged
    case RA_DISTINCT:
    {
        if (!node->left || node->left->type != RA_PROJECTION)
        {
            return estimate_size(node->left) / 2;
        }
        ASTNode *args = node->left->args;
        if (args && args->type == RA_ATTRIBUTE && args->args == NULL)
        {
            return estimate_distinct_values(node->left->left, args->value);
        }
        else
        {
            long long min_V = estimate_size(node->left->left);
            ASTNode *curr = args;
            while (curr)
            {
                if (curr->type == RA_ATTRIBUTE)
                {
                    long long V = estimate_distinct_values(node->left->left, curr->value);
                    if (V > 0 && V < min_V)
                        min_V = V;
                }
                curr = curr->args;
            }
            return min_V > 0 ? min_V : estimate_size(node->left) / 2;
        }
    }
    default:
        return estimate_size(node->left) / 2; // Fallback
    }
}

long long estimate_distinct_values(ASTNode *node, const char *attr_name)
{
    if (!node || !attr_name)
        return 0;

    switch (node->type)
    {
    case RA_RELATION:
        return get_num_distinct(node->value, attr_name);
    case RA_SELECTION:
    {
        long long V = estimate_distinct_values(node->left, attr_name);
        ASTNode *condition = node->args;
        if (condition && condition->type == RA_COMPARISON &&
            condition->left->type == RA_ATTRIBUTE &&
            strcmp(condition->left->value, attr_name) == 0)
        {
            if (strcmp(condition->value, "=") == 0)
                return 1;
            return V / 2; // Range condition approximation
        }
        return V; // Unrelated condition
    }
    case RA_JOIN:
    {
        long long V_left = estimate_distinct_values(node->left, attr_name);
        long long V_right = estimate_distinct_values(node->right, attr_name);
        if (V_left > 0)
            return V_left; // Attribute from left
        if (V_right > 0)
            return V_right; // Attribute from right
        return 0;
    }
    case RA_PROJECTION:
    {
        ASTNode *args = node->args;
        while (args)
        {
            if (args->type == RA_ATTRIBUTE && strcmp(args->value, attr_name) == 0)
            {
                return estimate_distinct_values(node->left, attr_name);
            }
            args = args->args;
        }
        return 0; // Attribute not projected
    }
    case RA_GROUPBY:
    {
        ASTNode *group_attrs = node->args;
        while (group_attrs)
        {
            if (group_attrs->type == RA_ATTRIBUTE &&
                strcmp(group_attrs->value, attr_name) == 0)
            {
                return estimate_distinct_values(node->left, attr_name);
            }
            group_attrs = group_attrs->args;
        }
        return 1; // Aggregated attribute
    }
    default:
        return estimate_distinct_values(node->left, attr_name) / 2;
    }
}

// Cost Calculation Functions
long long cost_selection(ASTNode *selection_node)
{
    if (!selection_node || !selection_node->left)
        return 0; // Invalid selection node
    ASTNode *input = selection_node->left;
    ASTNode *condition = selection_node->args;
    long long block_transfers = 0, seeks = 0;

    long long tpb = tuples_per_block(input);
    if (tpb <= 0)
        return 0; // Invalid tuples per block
    long long n = estimate_size(input);
    long long b_r = (n + tpb - 1) / tpb;

    if (input->type == RA_RELATION)
    {
        const char *table_name = input->value;
        if (!table_name)
            return 0; // Missing table name
        long long num_tuples = get_num_tuples(table_name);
        if (num_tuples == -1)
            return 0;

        if (!condition)
        { // No condition: linear search
            block_transfers = b_r * TB;
            seeks = TS;
            return block_transfers + seeks;
        }

        if (condition->type == RA_COMPARISON)
        {
            ASTNode *left = condition->left;
            ASTNode *right = condition->right;
            const char *op = condition->value;
            if (!left || !right || !op)
                return b_r * TB + TS; // Default to linear search

            if (left->type == RA_ATTRIBUTE && right->type == RA_LITERAL)
            {
                const char *attr_name = left->value;
                if (!attr_name)
                    return b_r * TB + TS; // Missing attribute
                long long flag = get_flag(table_name, attr_name);
                long long num_distinct = get_num_distinct(table_name, attr_name);
                if (flag == -1 || num_distinct == -1)
                    return b_r * TB + TS; // Default to linear search
                long long n = (flag == 1) ? 1 : (num_tuples / num_distinct);

                if (strcmp(op, "=") == 0)
                {
                    if (flag == 2)
                    { // Clustering index, equality on key
                        block_transfers = (INDEX_HEIGHT + 1) * TB;
                        seeks = (INDEX_HEIGHT + 1) * TS;
                    }
                    else if (flag == 3)
                    { // Secondary index, equality
                        block_transfers = (INDEX_HEIGHT + n) * TB;
                        seeks = (INDEX_HEIGHT + n) * TS;
                    }
                    else
                    { // Linear search
                        block_transfers = b_r * TB;
                        seeks = TS;
                    }
                }
                else if (strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
                {
                    n = num_tuples / 2; // 50% selectivity
                    if (flag == 2)
                    { // Clustering index, comparison
                        long long b = (n + tpb - 1) / tpb;
                        block_transfers = (INDEX_HEIGHT * TB) + (b * TB);
                        seeks = (INDEX_HEIGHT + 1) * TS;
                    }
                    else if (flag == 3)
                    { // Secondary index, comparison
                        block_transfers = (INDEX_HEIGHT + n) * TB;
                        seeks = (INDEX_HEIGHT + n) * TS;
                    }
                    else
                    { // Linear search
                        block_transfers = b_r * TB;
                        seeks = TS;
                    }
                }
                return block_transfers + seeks;
            }
        }
        else if (condition->type == RA_AND)
        {
            block_transfers = b_r * TB;
            seeks = TS;
            return block_transfers + seeks;
        }
        block_transfers = b_r * TB;
        seeks = TS;
        return block_transfers + seeks;
    }
    else
    {
        long long n = estimate_size(input);
        if (n == -1)
            return 0;
        long long b = (n + tpb - 1) / tpb;
        block_transfers = b * TB;
        seeks = TS;
        return block_transfers + seeks;
    }
}

long long cost_sort(ASTNode *node)
{
    if (!node)
        return 0;
    ASTNode *input = (node->type == RA_ORDERBY) ? node->right : node->left;
    if (!input)
        return 0;
    // printf("hi\n");
    long long n = estimate_size(input);
    long long tpb = tuples_per_block(input);
    if (tpb <= 0)
        return 0;
    long long b_r = (n + tpb - 1) / tpb;
    long long M = BUFFER_BLOCKS;
    long long passes = ceil(log((double)b_r / M) / log(M - 1));
    long long block_transfers = b_r * (2 * passes + 1) * TB;
    long long seeks = (2 * ceil((double)b_r / M) + b_r * (2 * passes - 1)) * TS;
    return block_transfers + seeks;
}

long long cost_join(ASTNode *join_node)
{
    if (!join_node || !join_node->left || !join_node->right)
        return 0; // Invalid join node
    ASTNode *left = join_node->left;
    ASTNode *right = join_node->right;

    long long n_left = estimate_size(join_node->left);
    // printf("hi\n");
    long long n_right = estimate_size(join_node->right);
    if (n_left == -1 || n_right == -1)
        return 0; // Estimation failed

    long long tpb_left = tuples_per_block(left);
    long long tpb_right = tuples_per_block(right);
    if (tpb_left <= 0 || tpb_right <= 0)
        return 0;

    long long b_left = (n_left + tpb_left - 1) / tpb_left;
    long long b_right = (n_right + tpb_right - 1) / tpb_right;
    long long M = BUFFER_BLOCKS;
    long long block_transfers = 0, seeks = 0;

    ASTNode *condition = join_node->condition;
    if (condition && condition->type == RA_COMPARISON && strcmp(condition->value, "=") == 0)
    {
        ASTNode *right_attr = condition->right;
        if (right_attr && right_attr->type == RA_ATTRIBUTE)
        {
            const char *right_table = get_table_name(join_node->right);
            if (right_table)
            {
                const char *attr_value = right_attr->value;
                if (attr_value)
                {
                    long long flag_right = get_flag(right_table, attr_value);
                    if (flag_right == 2)
                    { // Indexed Nested-Loop with clustering index
                        long long num_distinct = get_num_distinct(right_table, attr_value);
                        if (num_distinct > 0)
                        {
                            long long n_matching = get_num_tuples(right_table) / num_distinct;
                            long long b_matching = (n_matching + tpb_right - 1) / tpb_right;
                            block_transfers = b_left * TB + n_left * (INDEX_HEIGHT * TB + b_matching * TB);
                            seeks = b_left * TS + n_left * (INDEX_HEIGHT + b_matching) * TS;
                            return block_transfers + seeks;
                        }
                    }
                    else if (flag_right == 3)
                    { // Indexed Nested-Loop with secondary index
                        long long num_distinct = get_num_distinct(right_table, attr_value);
                        if (num_distinct > 0)
                        {
                            long long n_matching = get_num_tuples(right_table) / num_distinct;
                            block_transfers = b_left * TB + n_left * (INDEX_HEIGHT * TB + n_matching * TB);
                            seeks = b_left * TS + n_left * (INDEX_HEIGHT + n_matching) * TS;
                            return block_transfers + seeks;
                        }
                    }
                }
            }
        }
    }
    // Block Nested-Loop Join
    block_transfers = (b_left + ceil((double)b_left / (M - 2)) * b_right) * TB;
    seeks = (b_left + ceil((double)b_left / (M - 2))) * TS;
    return block_transfers + seeks;
}

long long cost_duplicate_elimination(ASTNode *node)
{
    return cost_sort(node); // Same as sorting cost
}

long long cost_projection(ASTNode *node)
{
    return 0;
    long long n = estimate_size(node->left);
    long long tpb = tuples_per_block(node->left);
    if (tpb <= 0)
        return 0;
    long long b = (n + tpb - 1) / tpb;
    long long block_transfers = b * TB;
    long long seeks = TS;
    return block_transfers + seeks;
}

long long cost_set_operation(ASTNode *node)
{
    if (!node || !node->left || !node->right)
        return 0;
    long long n_left = estimate_size(node->left);
    long long n_right = estimate_size(node->right);
    long long tpb_left = tuples_per_block(node->left);
    long long tpb_right = tuples_per_block(node->right);
    if (tpb_left <= 0 || tpb_right <= 0)
        return 0;
    long long b_left = (n_left + tpb_left - 1) / tpb_left;
    long long b_right = (n_right + tpb_right - 1) / tpb_right;
    long long sort_cost = cost_sort(node);
    long long block_transfers = (b_left + b_right) * TB + sort_cost / (TS + TB) * TB;
    long long seeks = 2 * TS + sort_cost / (TS + TB) * TS;
    return block_transfers + seeks;
}

long long cost_outer_join(ASTNode *join_node)
{
    if (!join_node || !join_node->left || !join_node->right)
        return 0;
    long long join_cost = cost_join(join_node);
    long long n_left = estimate_size(join_node->left);
    long long n_right = estimate_size(join_node->right);
    long long tpb_left = tuples_per_block(join_node->left);
    long long tpb_right = tuples_per_block(join_node->right);
    if (tpb_left <= 0 || tpb_right <= 0)
        return 0;
    long long b_left = (n_left + tpb_left - 1) / tpb_left;
    long long b_right = (n_right + tpb_right - 1) / tpb_right;
    long long extra_blocks = 0;

    if (strcmp(join_node->value, "⟕") == 0)
    { // Left outer join
        extra_blocks = b_left;
    }
    else if (strcmp(join_node->value, "⟖") == 0)
    { // Right outer join
        extra_blocks = b_right;
    }
    else if (strcmp(join_node->value, "⟗") == 0)
    { // Full outer join
        extra_blocks = b_left + b_right;
    }
    long long block_transfers = join_cost / (TS + TB) * TB + extra_blocks * TB;
    long long seeks = join_cost / (TS + TB) * TS + extra_blocks * TS;
    return block_transfers + seeks;
}

long long cost_aggregation(ASTNode *node)
{
    return cost_sort(node); // Similar to duplicate elimination
}

long long count_insert_rows(ASTNode *values_node)
{
    if (!values_node)
        return 0;

    values_node = values_node->left;

    long long count = 0;
    ASTNode *current = values_node;

    while (current)
    {
        if (current->type == RA_VALUE_LIST)
        {
            count++;
        }
        current = current->left;
    }

    return count;
}

long long cost_insert(ASTNode *node)
{
    if (!node || !node->left)
        return 0; // Invalid insert node
    // printf("hii1\n");
    // Get the target table information
    ASTNode *target = node->left;
    const char *table_name = get_table_name(target); // Assumes this function exists
    if (!table_name)
        return 0;
    // printf("hii2\n");
    long long tpb = tuples_per_block(target); // Tuples per block for the target table
    // printf("hii3%s\n", table_name);
    if (tpb <= 0)
        return 0;
    // printf("hii3\n");
    if (node->args && node->args->type == RA_VALUES)
    {
        // Direct value insertion (e.g., INSERT INTO table VALUES (1, 2), (3, 4))
        long long M = count_insert_rows(node->args); // Count the number of rows
        // printf("%lldi1\n",M);
        long long blocks_written = (M + tpb - 1) / tpb; // ceil(M / tpb)
        // printf("%lldi2\n",blocks_written);
        // printf("hii4\n");
        return blocks_written * 2; // Write cost (2 units per block)
    }
    else
    {
        // Insertion with subquery (e.g., INSERT INTO table SELECT ...)
        ASTNode *subquery = node->args;
        long long subquery_cost = cost_calculation(subquery); // Cost of evaluating subquery
        // printf("%lldhii5\n", subquery_cost);
        long long N = estimate_size(subquery);          // Estimated number of rows from subquery
        long long blocks_written = (N + tpb - 1) / tpb; // ceil(N / tpb)
        return subquery_cost + blocks_written * 2;      // Read cost + Write cost
    }
}

long long cost_update(ASTNode *node)
{
    if (!node || !node->left)
        return 0; // Invalid update node

    // Get the target table
    ASTNode *target = node->left;
    const char *table_name = get_table_name(target);
    if (!table_name)
        return 0;

    // Tuples per block
    long long tpb = tuples_per_block(target);
    if (tpb <= 0)
        return 0;

    // Get the condition (WHERE clause)
    ASTNode *condition = node->right; // Assuming condition is in node->right

    // Create a temporary selection node
    ASTNode *selection_node = create_node(RA_SELECTION, "");
    selection_node->args = condition;
    selection_node->left = target;

    // Calculate cost of selecting rows
    long long selection_cost = cost_selection(selection_node);

    // Estimate number of rows to update
    long long N = estimate_selection_size(condition, target);

    // Estimate number of blocks affected
    long long blocks_affected = (N + tpb - 1) / tpb; // ceil(N / tpb)

    // Total cost: selection cost + write cost
    long long total_cost = selection_cost + blocks_affected * 2;

    // Free the temporary node
    free(selection_node);

    return total_cost;
}

long long cost_delete(ASTNode *node)
{
    if (!node || !node->left)
        return 0; // Invalid delete node

    // Get the target table
    ASTNode *target = node->left;
    const char *table_name = get_table_name(target);
    if (!table_name)
        return 0;

    // Tuples per block
    long long tpb = tuples_per_block(target);
    if (tpb <= 0)
        return 0;

    // Get the condition (WHERE clause)
    ASTNode *condition = node->right; // Assuming condition is in node->right

    // Create a temporary selection node
    ASTNode *selection_node = create_node(RA_SELECTION, "");
    selection_node->args = condition;
    selection_node->left = target;

    // Calculate cost of selecting rows
    long long selection_cost = cost_selection(selection_node);

    // Estimate number of rows to delete
    long long N = estimate_selection_size(condition, target);

    // Estimate number of blocks affected
    long long blocks_affected = (N + tpb - 1) / tpb; // ceil(N / tpb)

    // Total cost: selection cost + write cost
    long long total_cost = selection_cost + blocks_affected * 2;

    // Free the temporary node
    free(selection_node);

    return total_cost;
}

// Main Cost Calculation Function
long long cost_calculation(ASTNode *node)
{
    if (!node)
        return 0;

    long long total_cost = 0;

    switch (node->type)
    {
    case RA_RELATION:
        // No cost for the relation itself
        total_cost = 0;
        break;
    case RA_SELECTION:
        // Cost of selection plus cost of its input
        total_cost += cost_selection(node);
        total_cost += cost_calculation(node->left);
        break;
    case RA_JOIN:
        // Cost of join plus costs of both inputs
        // printf("%lldj0\n",total_cost);
        total_cost += cost_join(node);
        // printf("%lldj1\n",total_cost);
        total_cost += cost_calculation(node->left);
        // printf("%lldj2\n",total_cost);
        total_cost += cost_calculation(node->right);
        // printf("%lldj3\n",total_cost);
        break;
    case RA_PROJECTION:
        // Cost of projection plus cost of its input
        total_cost += cost_projection(node);
        // printf("%lldp1\n",total_cost);
        total_cost += cost_calculation(node->left);
        // printf("%lldp2\n",total_cost);
        fflush(stdout);
        break;
    case RA_DISTINCT:
        // Cost of distinct plus cost of its input
        total_cost += cost_duplicate_elimination(node);
        total_cost += cost_calculation(node->left);
        break;
    case RA_GROUPBY:
        // Cost of group by plus cost of its input
        total_cost += cost_aggregation(node);
        total_cost += cost_calculation(node->left);
        break;
    case RA_ORDERBY:
        // Cost of order by plus cost of its input
        total_cost += cost_sort(node);
        // printf("%lldp1\n",total_cost);
        total_cost += cost_calculation(node->right);
        // printf("%lldp1\n",total_cost);
        break;
    case RA_SET_OP:
        // Cost of set operation plus costs of both inputs
        total_cost += cost_set_operation(node);
        total_cost += cost_calculation(node->left);
        total_cost += cost_calculation(node->right);
        break;
    case RA_ALIAS:
        // Cost is the same as its input
        total_cost += cost_calculation(node->left);
        break;
    case RA_INSERT:
        total_cost += cost_insert(node);
        // printf("%lldc\n", total_cost);
        break;
    case RA_DELETE:
        total_cost += cost_delete(node);
        break;
    case RA_UPDATE:
        total_cost += cost_update(node);
        break;
    default:
        // For any other type, accumulate costs of children
        total_cost += cost_calculation(node->left);
        total_cost += cost_calculation(node->right);
        break;
    }

    return total_cost;
}

void read_table_data()
{
    FILE *data_base = fopen("database.txt", "r");
    if (!data_base)
    {
        perror("Cannot open database.txt");
        exit(1);
    }

    if (fscanf(data_base, "%lld", &num_tables) != 1)
    {
        fprintf(stderr, "Failed to read number of tables\n");
        exit(1);
    }
    tables = (TABLE *)malloc((num_tables + 10) * sizeof(TABLE));
    if (!tables)
    {
        perror("Memory allocation failed for tables");
        fclose(data_base);
        exit(1);
    }

    for (long long i = 0; i < num_tables; ++i)
    {
        char table_name[100];
        long long num_attributes, num_tuples;
        if (fscanf(data_base, " TABLE %s %lld %lld", table_name, &num_attributes, &num_tuples) != 3)
        {
            fprintf(stderr, "Failed to read table %lld\n", i);
            exit(1);
        }

        tables[i].TABLE_NAME = strdup(table_name);
        if (!tables[i].TABLE_NAME)
        {
            perror("Failed to duplicate table name");
            exit(1);
        }
        tables[i].num_attributes = num_attributes;
        tables[i].num_tuples = num_tuples;

        tables[i].attr_list = (attr *)malloc(num_attributes * sizeof(attr));
        if (!tables[i].attr_list)
        {
            perror("Memory allocation failed for attributes");
            fclose(data_base);
            exit(1);
        }

        for (long long j = 0; j < num_attributes; ++j)
        {
            char attr_name[100];
            long long flag, num_distinct;
            if (fscanf(data_base, " %s %lld %lld", attr_name, &flag, &num_distinct) != 3)
            {
                fprintf(stderr, "Failed to read attribute %lld of table %s\n", j, table_name);
                exit(1);
            }

            tables[i].attr_list[j].name = strdup(attr_name);
            if (!tables[i].attr_list[j].name)
            {
                perror("Failed to duplicate attribute name");
                exit(1);
            }
            tables[i].attr_list[j].flag = flag;
            tables[i].attr_list[j].max_len = 0;
            tables[i].attr_list[j].num_distinct = num_distinct;
        }
    }

    fclose(data_base);

    for (long long i = 0; i < num_tables; i++)
    {
        printf("Table Name: %s\n", tables[i].TABLE_NAME);
        printf("Number of Attributes: %d\n", tables[i].num_attributes);
        printf("Number of Tuples: %d\n", tables[i].num_tuples);
        for (long long j = 0; j < tables[i].num_attributes; j++)
        {
            printf("Attribute Name: %s, Flag: %d, Max Length: %d, Distinct: %d\n", tables[i].attr_list[j].name, tables[i].attr_list[j].flag, tables[i].attr_list[j].max_len, tables[i].attr_list[j].num_distinct);
        }
    }

    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
}

void free_tree(ASTNode *node)
{
    if (!node)
        return;
    free_tree(node->left);
    free_tree(node->right);
    free_tree(node->condition);
    free_tree(node->args);
    free_tree(node->from);
    free(node);
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

long long main(long long argc, char **argv)
{
    read_table_data();
    // long long yyin;
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (!yyin)
        {
            perror("Cannot open input file");
            return 1;
        }
    }

    for (long long i = 0; i < 10; i++)
    {
        parse_tree[i] = NULL;
    }

    yyparse();

    for (long long i = 0; i < parse_tree_count; i++)
    {
        free_tree(parse_tree[i]);
    }

    if (yyin != stdin)
    {
        fclose(yyin);
    }

    return 0;
}
