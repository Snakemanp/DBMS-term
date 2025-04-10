#ifndef SQL_PARSER_H
#define SQL_PARSER_H

#define MAX_STRING_LENGTH 256

typedef enum
{
    RA_EMPTY,
    RA_PROJECTION,
    RA_SELECTION,
    RA_GROUPBY,
    RA_ORDERBY,
    RA_JOIN,
    RA_CROSS_JOIN,
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
    RA_TRANSFORMED,
    RA_SCOPE
} NodeType;

typedef struct
{
    char *name;
    int flag;
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
} ASTNode;

extern ASTNode *parse_tree[10];

// Function prototypes
void yyerror(const char *s);
ASTNode *create_node(NodeType type, const char *value);
void print_tree(ASTNode *node, int depth);
void free_tree(ASTNode *node);
void print_subtree(ASTNode *node, int depth);

// Transformation functions
ASTNode *selection_pushdown(ASTNode *node);
ASTNode *projection_pushdown(ASTNode *node);
ASTNode *apply_transformations(ASTNode *node);

// Helper functions
int condition_involves_only(ASTNode *condition, ASTNode *relation);
ASTNode *extract_attributes(ASTNode *projection, ASTNode *relation);
ASTNode *deep_copy_tree(ASTNode *original);
ASTNode *extract_attributes_from_conditions(ASTNode *node);

// scope attribute functions
scope_attr *merge_scopes(scope_attr *left, scope_attr *right);
scope_attr *build_scope(ASTNode *node);
void free_scope(scope_attr *scope);

int cost_estimation(ASTNode *node);

#endif