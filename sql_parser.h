#ifndef SQL_PARSER_H
#define SQL_PARSER_H

#define MAX_STRING_LENGTH 256
#define MAX_RES_TREE 25

#define BLOCK_SIZE 4096                            // bytes
#define TUPLE_SIZE 100                             // bytes (assumed average tuple size)
#define TUPLES_PER_BLOCK (BLOCK_SIZE / TUPLE_SIZE) // 40 tuples per block
#define INDEX_HEIGHT 1                             // Assumed B+-tree height
#define BUFFER_BLOCKS 100                          // Number of buffer blocks (M)
#define TS 40                                      // Seek time: 4ms = 40 * 0.1ms
#define TB 1                                       // Block transfer time: 0.1ms = 1 * 0.1ms

typedef enum
{
    RA_EMPTY,
    RA_PROJECTION,
    RA_SELECTION,
    RA_GROUPBY,
    RA_ORDERBY,
    RA_JOIN,
    RA_SET_OP,
    RA_WITH,
    RA_WITH_LIST,
    RA_WITH_QUERY,
    RA_RELATION,
    RA_ATTRIBUTE,
    RA_ALIAS,
    RA_DISTINCT,
    RA_PROJECTION_LIST,
    RA_GROUP_LIST,
    RA_ORDER_LIST,
    RA_ORDER_ITEM,
    RA_INSERT,
    RA_UPDATE,
    RA_DELETE,
    RA_VALUES,
    RA_VALUE_LIST,
    RA_VALUE_ITEMS,
    RA_COLUMN_LIST,
    RA_SET,
    RA_SET_LIST,
    RA_ASSIGNMENT,
    RA_USING,
    RA_FROM,
    RA_JOIN_TYPE,
    RA_OR,
    RA_AND,
    RA_NOT,
    RA_COMPARISON,
    RA_NULL_CHECK,
    RA_IN,
    RA_RANGE,
    RA_CONCAT,
    RA_ARITHMETIC,
    RA_LITERAL,
    RA_OPERATOR,
    RA_EXISTS,
    RA_BETWEEN,
    RA_TRANSFORMED
} NodeType;

typedef struct
{
    char *name;
    int flag;
    int num_distinct;
    int max_len;
} attr;

typedef struct
{
    char *TABLE_NAME;
    attr *attr_list;
    int num_tuples;
    int num_attributes;
} TABLE;

struct scope_attr
{
    char *name;
    char *alias;
    TABLE *tablename;
    struct scope_attr *next;
};
typedef struct scope_attr scope_attr;

typedef struct ASTNode
{
    NodeType type;
    char value[MAX_STRING_LENGTH];
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *args;
    struct ASTNode *condition; // For join conditions, WHERE, etc.
    struct ASTNode *from;      // For UPDATE's FROM clause
    // scope_attr *scope;         // For scoping attributes
    int assoc_left_done;
    int assoc_right_done;
} ASTNode;

extern ASTNode *parse_tree[10];

// Function prototypes
void yyerror(const char *s);
ASTNode *create_node(NodeType type, const char *value);
void print_tree(ASTNode *node, int depth);
void free_tree(ASTNode *node);
void print_subtree(ASTNode *node, int depth);

// Transformation functions
ASTNode *pre_transform_tree(ASTNode *node, scope_attr *req);
ASTNode *selection_pushdown(ASTNode *node);
ASTNode *projection_pushdown(ASTNode *node);
void join_associativity(ASTNode *node, ASTNode *node2, ASTNode *org_node);
void apply_join_transf(ASTNode *node);
ASTNode *apply_transformations(ASTNode *node);

// Helper functions
int condition_involves_only(ASTNode *cond, scope_attr *scope);
ASTNode *deep_copy_tree(ASTNode *original);
ASTNode *deep_copy_shallow(ASTNode *node);
ASTNode *extract_attributes_from_conditions(ASTNode *node);

// scope attribute functions
scope_attr *merge_scopes(scope_attr *left, scope_attr *right);
scope_attr *build_scope(ASTNode *node);
void free_scope(scope_attr *scope);

long long cost_calculation(ASTNode *node);
attr *get_attr_from_table(TABLE *table, const char *attr_name);

void print_tree_scope(ASTNode *node, int level);

long long estimate_size(ASTNode *node);
long long estimate_distinct_values(ASTNode *node, const char *attr_name);

#endif