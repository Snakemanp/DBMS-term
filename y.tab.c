/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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


#line 101 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    OPERATOR = 260,                /* OPERATOR  */
    NUM = 261,                     /* NUM  */
    SELECT = 262,                  /* SELECT  */
    ALL = 263,                     /* ALL  */
    DISTINCT = 264,                /* DISTINCT  */
    FROM = 265,                    /* FROM  */
    WHERE = 266,                   /* WHERE  */
    GROUP = 267,                   /* GROUP  */
    BY = 268,                      /* BY  */
    HAVING = 269,                  /* HAVING  */
    ORDER = 270,                   /* ORDER  */
    ASC = 271,                     /* ASC  */
    DESC = 272,                    /* DESC  */
    USING = 273,                   /* USING  */
    NULLS = 274,                   /* NULLS  */
    FIRST = 275,                   /* FIRST  */
    LAST = 276,                    /* LAST  */
    UNION = 277,                   /* UNION  */
    INTERSECT = 278,               /* INTERSECT  */
    EXCEPT = 279,                  /* EXCEPT  */
    INSERT = 280,                  /* INSERT  */
    INTO = 281,                    /* INTO  */
    VALUES = 282,                  /* VALUES  */
    DEFAULT = 283,                 /* DEFAULT  */
    WITH = 284,                    /* WITH  */
    RECURSIVE = 285,               /* RECURSIVE  */
    AS = 286,                      /* AS  */
    UPDATE = 287,                  /* UPDATE  */
    ONLY = 288,                    /* ONLY  */
    SET = 289,                     /* SET  */
    ROW = 290,                     /* ROW  */
    DELETE = 291,                  /* DELETE  */
    EXISTS = 292,                  /* EXISTS  */
    BETWEEN = 293,                 /* BETWEEN  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    IN = 296,                      /* IN  */
    INNER = 297,                   /* INNER  */
    NATURAL = 298,                 /* NATURAL  */
    LEFT = 299,                    /* LEFT  */
    RIGHT = 300,                   /* RIGHT  */
    FULL = 301,                    /* FULL  */
    CROSS = 302,                   /* CROSS  */
    JOIN = 303,                    /* JOIN  */
    ON = 304,                      /* ON  */
    IS = 305,                      /* IS  */
    NOT = 306,                     /* NOT  */
    NULL_VAL = 307,                /* NULL_VAL  */
    SEMICOLON = 308,               /* SEMICOLON  */
    COMMA = 309,                   /* COMMA  */
    DOT = 310,                     /* DOT  */
    ASTERISK = 311,                /* ASTERISK  */
    LPAREN = 312,                  /* LPAREN  */
    RPAREN = 313,                  /* RPAREN  */
    EQ = 314,                      /* EQ  */
    NE = 315,                      /* NE  */
    LT = 316,                      /* LT  */
    GT = 317,                      /* GT  */
    LE = 318,                      /* LE  */
    GE = 319,                      /* GE  */
    CONCAT = 320,                  /* CONCAT  */
    PLUS = 321,                    /* PLUS  */
    MINUS = 322,                   /* MINUS  */
    DIV = 323,                     /* DIV  */
    UMINUS = 324                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define STRING_LITERAL 259
#define OPERATOR 260
#define NUM 261
#define SELECT 262
#define ALL 263
#define DISTINCT 264
#define FROM 265
#define WHERE 266
#define GROUP 267
#define BY 268
#define HAVING 269
#define ORDER 270
#define ASC 271
#define DESC 272
#define USING 273
#define NULLS 274
#define FIRST 275
#define LAST 276
#define UNION 277
#define INTERSECT 278
#define EXCEPT 279
#define INSERT 280
#define INTO 281
#define VALUES 282
#define DEFAULT 283
#define WITH 284
#define RECURSIVE 285
#define AS 286
#define UPDATE 287
#define ONLY 288
#define SET 289
#define ROW 290
#define DELETE 291
#define EXISTS 292
#define BETWEEN 293
#define AND 294
#define OR 295
#define IN 296
#define INNER 297
#define NATURAL 298
#define LEFT 299
#define RIGHT 300
#define FULL 301
#define CROSS 302
#define JOIN 303
#define ON 304
#define IS 305
#define NOT 306
#define NULL_VAL 307
#define SEMICOLON 308
#define COMMA 309
#define DOT 310
#define ASTERISK 311
#define LPAREN 312
#define RPAREN 313
#define EQ 314
#define NE 315
#define LT 316
#define GT 317
#define LE 318
#define GE 319
#define CONCAT 320
#define PLUS 321
#define MINUS 322
#define DIV 323
#define UMINUS 324

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

    char* str;
    int num;
    struct ASTNode* node;

#line 298 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_OPERATOR = 5,                   /* OPERATOR  */
  YYSYMBOL_NUM = 6,                        /* NUM  */
  YYSYMBOL_SELECT = 7,                     /* SELECT  */
  YYSYMBOL_ALL = 8,                        /* ALL  */
  YYSYMBOL_DISTINCT = 9,                   /* DISTINCT  */
  YYSYMBOL_FROM = 10,                      /* FROM  */
  YYSYMBOL_WHERE = 11,                     /* WHERE  */
  YYSYMBOL_GROUP = 12,                     /* GROUP  */
  YYSYMBOL_BY = 13,                        /* BY  */
  YYSYMBOL_HAVING = 14,                    /* HAVING  */
  YYSYMBOL_ORDER = 15,                     /* ORDER  */
  YYSYMBOL_ASC = 16,                       /* ASC  */
  YYSYMBOL_DESC = 17,                      /* DESC  */
  YYSYMBOL_USING = 18,                     /* USING  */
  YYSYMBOL_NULLS = 19,                     /* NULLS  */
  YYSYMBOL_FIRST = 20,                     /* FIRST  */
  YYSYMBOL_LAST = 21,                      /* LAST  */
  YYSYMBOL_UNION = 22,                     /* UNION  */
  YYSYMBOL_INTERSECT = 23,                 /* INTERSECT  */
  YYSYMBOL_EXCEPT = 24,                    /* EXCEPT  */
  YYSYMBOL_INSERT = 25,                    /* INSERT  */
  YYSYMBOL_INTO = 26,                      /* INTO  */
  YYSYMBOL_VALUES = 27,                    /* VALUES  */
  YYSYMBOL_DEFAULT = 28,                   /* DEFAULT  */
  YYSYMBOL_WITH = 29,                      /* WITH  */
  YYSYMBOL_RECURSIVE = 30,                 /* RECURSIVE  */
  YYSYMBOL_AS = 31,                        /* AS  */
  YYSYMBOL_UPDATE = 32,                    /* UPDATE  */
  YYSYMBOL_ONLY = 33,                      /* ONLY  */
  YYSYMBOL_SET = 34,                       /* SET  */
  YYSYMBOL_ROW = 35,                       /* ROW  */
  YYSYMBOL_DELETE = 36,                    /* DELETE  */
  YYSYMBOL_EXISTS = 37,                    /* EXISTS  */
  YYSYMBOL_BETWEEN = 38,                   /* BETWEEN  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_IN = 41,                        /* IN  */
  YYSYMBOL_INNER = 42,                     /* INNER  */
  YYSYMBOL_NATURAL = 43,                   /* NATURAL  */
  YYSYMBOL_LEFT = 44,                      /* LEFT  */
  YYSYMBOL_RIGHT = 45,                     /* RIGHT  */
  YYSYMBOL_FULL = 46,                      /* FULL  */
  YYSYMBOL_CROSS = 47,                     /* CROSS  */
  YYSYMBOL_JOIN = 48,                      /* JOIN  */
  YYSYMBOL_ON = 49,                        /* ON  */
  YYSYMBOL_IS = 50,                        /* IS  */
  YYSYMBOL_NOT = 51,                       /* NOT  */
  YYSYMBOL_NULL_VAL = 52,                  /* NULL_VAL  */
  YYSYMBOL_SEMICOLON = 53,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 54,                     /* COMMA  */
  YYSYMBOL_DOT = 55,                       /* DOT  */
  YYSYMBOL_ASTERISK = 56,                  /* ASTERISK  */
  YYSYMBOL_LPAREN = 57,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 58,                    /* RPAREN  */
  YYSYMBOL_EQ = 59,                        /* EQ  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_LT = 61,                        /* LT  */
  YYSYMBOL_GT = 62,                        /* GT  */
  YYSYMBOL_LE = 63,                        /* LE  */
  YYSYMBOL_GE = 64,                        /* GE  */
  YYSYMBOL_CONCAT = 65,                    /* CONCAT  */
  YYSYMBOL_PLUS = 66,                      /* PLUS  */
  YYSYMBOL_MINUS = 67,                     /* MINUS  */
  YYSYMBOL_DIV = 68,                       /* DIV  */
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_statement_list = 72,            /* statement_list  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_query = 74,                     /* query  */
  YYSYMBOL_set_op = 75,                    /* set_op  */
  YYSYMBOL_select_stmt = 76,               /* select_stmt  */
  YYSYMBOL_with_clause_opt = 77,           /* with_clause_opt  */
  YYSYMBOL_with_clause = 78,               /* with_clause  */
  YYSYMBOL_recursive_opt = 79,             /* recursive_opt  */
  YYSYMBOL_with_query_list = 80,           /* with_query_list  */
  YYSYMBOL_with_query = 81,                /* with_query  */
  YYSYMBOL_select_opts = 82,               /* select_opts  */
  YYSYMBOL_column_list = 83,               /* column_list  */
  YYSYMBOL_column = 84,                    /* column  */
  YYSYMBOL_as_id_opt = 85,                 /* as_id_opt  */
  YYSYMBOL_modified_id = 86,               /* modified_id  */
  YYSYMBOL_from_clause = 87,               /* from_clause  */
  YYSYMBOL_from_item_list = 88,            /* from_item_list  */
  YYSYMBOL_from_item = 89,                 /* from_item  */
  YYSYMBOL_base_table = 90,                /* base_table  */
  YYSYMBOL_joined_table = 91,              /* joined_table  */
  YYSYMBOL_join_condition_opt = 92,        /* join_condition_opt  */
  YYSYMBOL_join_type = 93,                 /* join_type  */
  YYSYMBOL_where_clause = 94,              /* where_clause  */
  YYSYMBOL_group_clause = 95,              /* group_clause  */
  YYSYMBOL_group_item_list = 96,           /* group_item_list  */
  YYSYMBOL_having_clause = 97,             /* having_clause  */
  YYSYMBOL_order_clause = 98,              /* order_clause  */
  YYSYMBOL_order_item_list = 99,           /* order_item_list  */
  YYSYMBOL_order_item = 100,               /* order_item  */
  YYSYMBOL_order_option = 101,             /* order_option  */
  YYSYMBOL_nulls_option = 102,             /* nulls_option  */
  YYSYMBOL_insert_stmt = 103,              /* insert_stmt  */
  YYSYMBOL_column_list_opt = 104,          /* column_list_opt  */
  YYSYMBOL_column_name_list = 105,         /* column_name_list  */
  YYSYMBOL_insert_values = 106,            /* insert_values  */
  YYSYMBOL_insert_value_list = 107,        /* insert_value_list  */
  YYSYMBOL_insert_value_items = 108,       /* insert_value_items  */
  YYSYMBOL_insert_value = 109,             /* insert_value  */
  YYSYMBOL_update_stmt = 110,              /* update_stmt  */
  YYSYMBOL_only_opt = 111,                 /* only_opt  */
  YYSYMBOL_asterisk_opt = 112,             /* asterisk_opt  */
  YYSYMBOL_set_clause = 113,               /* set_clause  */
  YYSYMBOL_set_item_list = 114,            /* set_item_list  */
  YYSYMBOL_set_item = 115,                 /* set_item  */
  YYSYMBOL_set_value = 116,                /* set_value  */
  YYSYMBOL_column_name = 117,              /* column_name  */
  YYSYMBOL_delete_stmt = 118,              /* delete_stmt  */
  YYSYMBOL_using_clause_opt = 119,         /* using_clause_opt  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_and_condition = 121,            /* and_condition  */
  YYSYMBOL_condition = 122,                /* condition  */
  YYSYMBOL_not_opt = 123,                  /* not_opt  */
  YYSYMBOL_in_items = 124,                 /* in_items  */
  YYSYMBOL_comparison_op = 125,            /* comparison_op  */
  YYSYMBOL_operand = 126,                  /* operand  */
  YYSYMBOL_summand = 127,                  /* summand  */
  YYSYMBOL_factor = 128,                   /* factor  */
  YYSYMBOL_term = 129                      /* term  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    95,    98,   104,   157,   161,   165,   169,
     173,   187,   191,   195,   203,   266,   271,   277,   288,   293,
     299,   303,   313,   351,   355,   360,   366,   377,   390,   397,
     401,   410,   414,   419,   425,   429,   438,   443,   450,   454,
     464,   468,   472,   479,   490,   504,   515,   529,   534,   541,
     545,   549,   553,   557,   561,   565,   572,   578,   584,   590,
     596,   600,   610,   616,   622,   628,   634,   639,   650,   672,
     676,   681,   687,   691,   696,   703,   731,   736,   742,   746,
     756,   760,   765,   772,   778,   788,   792,   802,   806,   814,
     850,   855,   861,   866,   872,   880,   884,   894,   901,   908,
     915,   925,   929,   933,   940,   948,   974,   980,   987,   991,
    1001,  1005,  1015,  1019,  1025,  1032,  1051,  1087,  1092,  1098,
    1102,  1109,  1113,  1117,  1121,  1125,  1129,  1136,  1140,  1150,
    1154,  1161,  1171,  1175,  1182,  1192,  1196,  1200,  1206
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING_LITERAL",
  "OPERATOR", "NUM", "SELECT", "ALL", "DISTINCT", "FROM", "WHERE", "GROUP",
  "BY", "HAVING", "ORDER", "ASC", "DESC", "USING", "NULLS", "FIRST",
  "LAST", "UNION", "INTERSECT", "EXCEPT", "INSERT", "INTO", "VALUES",
  "DEFAULT", "WITH", "RECURSIVE", "AS", "UPDATE", "ONLY", "SET", "ROW",
  "DELETE", "EXISTS", "BETWEEN", "AND", "OR", "IN", "INNER", "NATURAL",
  "LEFT", "RIGHT", "FULL", "CROSS", "JOIN", "ON", "IS", "NOT", "NULL_VAL",
  "SEMICOLON", "COMMA", "DOT", "ASTERISK", "LPAREN", "RPAREN", "EQ", "NE",
  "LT", "GT", "LE", "GE", "CONCAT", "PLUS", "MINUS", "DIV", "UMINUS",
  "$accept", "program", "statement_list", "statement", "query", "set_op",
  "select_stmt", "with_clause_opt", "with_clause", "recursive_opt",
  "with_query_list", "with_query", "select_opts", "column_list", "column",
  "as_id_opt", "modified_id", "from_clause", "from_item_list", "from_item",
  "base_table", "joined_table", "join_condition_opt", "join_type",
  "where_clause", "group_clause", "group_item_list", "having_clause",
  "order_clause", "order_item_list", "order_item", "order_option",
  "nulls_option", "insert_stmt", "column_list_opt", "column_name_list",
  "insert_values", "insert_value_list", "insert_value_items",
  "insert_value", "update_stmt", "only_opt", "asterisk_opt", "set_clause",
  "set_item_list", "set_item", "set_value", "column_name", "delete_stmt",
  "using_clause_opt", "expression", "and_condition", "condition",
  "not_opt", "in_items", "comparison_op", "operand", "summand", "factor",
  "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-119)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    -4,    99,    27,  -111,    73,   165,    75,  -111,  -111,
    -111,  -111,  -111,   134,  -111,  -111,  -111,  -111,  -111,  -111,
     115,   115,    76,   109,   140,   121,   106,  -111,  -111,  -111,
     -10,    18,   178,  -111,   179,   182,   146,   134,  -111,   197,
     150,  -111,  -111,  -111,    84,     0,    36,  -111,  -111,    36,
     151,   188,   -10,  -111,     2,   160,   -42,   135,    54,  -111,
      12,    89,   205,  -111,   214,  -111,   161,  -111,    36,    12,
     205,   162,  -111,  -111,   216,  -111,    84,    84,    84,    84,
      84,     5,    36,   167,   130,  -111,  -111,    36,    57,   210,
    -111,   220,   128,   190,   167,  -111,  -111,   135,    54,    54,
    -111,  -111,   168,    85,  -111,    12,   177,   180,   181,   183,
     184,   185,  -111,    37,  -111,    57,    57,   187,   191,  -111,
     149,   221,   222,  -111,   -25,   186,   208,  -111,  -111,    41,
     227,    36,  -111,   130,  -111,  -111,  -111,  -111,  -111,  -111,
       5,   189,  -111,    39,   133,    57,    57,   193,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,   198,    84,   220,    57,   225,
     220,  -111,    77,   192,  -111,   220,  -111,   194,  -111,   195,
     205,  -111,   130,   199,    57,  -111,  -111,   191,  -111,   200,
     196,   176,  -111,   201,   187,   229,  -111,  -111,  -111,    59,
    -111,   176,   202,    61,    41,     8,  -111,   189,   187,  -111,
      14,   220,    84,    77,  -111,    77,   203,  -111,  -111,  -111,
     187,   103,  -111,  -111,   204,   206,  -111,   207,  -111,    21,
    -111,    62,    11,  -111,    84,  -111,  -111,   226,  -111,   209,
      49,  -111,   127,  -111,    77,   211,    81,  -111,  -111,    82,
    -111,  -111,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,    19,     0,    16,     3,     0,     6,     0,    15,     7,
       8,     9,    18,     0,     1,     4,     5,    11,    12,    13,
      25,    25,     0,    91,     0,     0,    17,    20,    23,    24,
      16,     0,     0,    90,     0,     0,     0,     0,    10,     0,
      34,   138,   137,    28,     0,    37,    33,   136,    29,    33,
      93,   107,    16,    21,     0,    34,     0,   127,   129,   132,
       0,     0,    57,    32,     0,    26,    77,    92,    33,     0,
      57,     0,    35,    30,     0,   135,     0,     0,     0,     0,
       0,    16,    33,    36,    38,    41,    40,    33,     0,    59,
      31,     0,    16,     0,   106,   105,    22,   128,   130,   131,
     133,   134,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,    54,     0,    27,     0,     0,    56,   108,   110,
     118,     0,    63,    78,     0,     0,     0,    82,    75,     0,
      37,    33,    42,    39,    49,    55,    50,    51,    52,    53,
      16,    48,   113,     0,   118,     0,     0,   118,   117,   121,
     122,   123,   124,   125,   126,     0,     0,     0,     0,    65,
       0,    76,     0,    81,    80,     0,   104,    94,    95,     0,
      57,    44,     0,    40,     0,    45,   112,   109,   111,     0,
       0,   114,    60,    58,    62,     0,    14,    79,    88,     0,
      85,    87,     0,     0,     0,     0,    89,    48,    47,   115,
      16,     0,     0,     0,    83,     0,     0,    96,   103,    97,
     102,   101,    46,   120,   119,     0,    61,    64,    66,    71,
      86,     0,     0,   116,     0,    69,    70,    74,    84,     0,
      16,    67,     0,    68,     0,     0,     0,    72,    73,     0,
     100,    98,    99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   244,   -51,  -111,   219,   230,  -111,  -111,
    -111,   213,   235,    51,   212,   -40,   -56,   137,   215,   -74,
     152,   123,    71,  -111,   -67,  -111,  -111,  -111,  -111,  -111,
      46,  -111,  -111,  -111,  -111,   107,  -111,  -111,  -109,    68,
    -111,  -111,  -111,  -111,  -111,    80,  -111,  -111,  -111,  -111,
    -110,   131,   -70,   132,  -111,  -111,   -44,   217,    92,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    20,     6,     7,     8,    13,
      26,    27,    30,    45,    46,    65,    47,    62,    83,    84,
      85,    86,   175,   113,    89,   122,   183,   159,   186,   217,
     218,   227,   233,     9,    92,   124,   128,   163,   189,   190,
      10,    34,    68,   130,   167,   168,   209,   169,    11,    70,
     117,   118,   119,   155,   215,   156,   120,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    71,    48,    95,    82,    72,   143,   103,    55,    66,
      60,    55,    41,    82,    42,    55,    75,    40,    41,     1,
      42,    40,    41,    76,    42,    82,    12,    -2,    93,   160,
     102,   133,    48,   161,     1,   123,   208,   225,   226,    63,
      55,   127,   104,     1,    55,   142,   229,   114,   184,    82,
     100,   101,    55,    41,    61,    42,     1,    82,    73,   115,
      55,    41,    81,    42,   198,   116,   172,    64,   230,    81,
      43,    44,   144,   166,    43,    44,   178,   188,     1,   145,
      55,    41,    21,    42,    82,   210,    76,    55,    41,   102,
      42,   171,    40,    41,   140,    42,   221,   176,   165,    14,
      22,   182,    32,   196,   187,   188,    44,    23,   115,   123,
      79,    24,   181,   203,   116,   160,   203,   204,   191,   206,
     228,   236,    80,    28,    29,   239,    16,   106,   107,   108,
     109,   110,   111,   112,    44,   203,   203,    25,   166,   241,
     242,    44,    33,   132,  -118,   216,    44,   237,   238,   213,
      35,   211,    36,   147,   148,   125,   126,     1,   219,   191,
      37,   191,   149,   150,   151,   152,   153,   154,    76,    98,
      99,    48,   106,   107,   108,   109,   110,   111,   112,   235,
     219,    49,    50,   147,   148,    51,   191,    17,    18,    19,
     191,    75,   149,   150,   151,   152,   153,   154,    76,   147,
     148,    77,    78,    52,    21,    54,    69,    67,   149,   150,
     151,   152,   153,   154,    76,    74,    88,    90,    91,    72,
      96,   105,   121,    55,   129,   134,   131,   145,   135,   136,
     146,   137,   138,   139,   157,   164,   158,    60,   174,   180,
     185,    76,   202,   162,   148,   232,   192,    15,   194,    38,
      53,   214,   199,   200,   195,   201,    31,   197,    61,   205,
      39,   224,   222,   173,   223,   141,   234,   170,   212,   240,
     231,   220,   193,    87,   207,     0,   177,     0,     0,   179,
       0,     0,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,    97
};

static const yytype_int16 yycheck[] =
{
      44,    52,    31,    70,    60,     3,   116,    81,     3,    49,
      10,     3,     4,    69,     6,     3,    58,     3,     4,    29,
       6,     3,     4,    65,     6,    81,    30,     0,    68,    54,
      81,   105,    61,    58,    29,    91,    28,    16,    17,     3,
       3,    92,    82,    29,     3,   115,    35,    87,   158,   105,
      79,    80,     3,     4,    54,     6,    29,   113,    56,    51,
       3,     4,    57,     6,   174,    57,   140,    31,    57,    57,
      56,    57,   116,   129,    56,    57,   146,    28,    29,    40,
       3,     4,     7,     6,   140,   195,    65,     3,     4,   140,
       6,   131,     3,     4,    57,     6,   205,    58,    57,     0,
      25,   157,    26,   170,   160,    28,    57,    32,    51,   165,
      56,    36,   156,    54,    57,    54,    54,    58,   162,    58,
      58,   230,    68,     8,     9,   234,    53,    42,    43,    44,
      45,    46,    47,    48,    57,    54,    54,     3,   194,    58,
      58,    57,    33,    58,    41,   201,    57,    20,    21,   200,
      10,   195,    31,    50,    51,    27,    28,    29,   202,   203,
      54,   205,    59,    60,    61,    62,    63,    64,    65,    77,
      78,   200,    42,    43,    44,    45,    46,    47,    48,   230,
     224,     3,     3,    50,    51,     3,   230,    22,    23,    24,
     234,    58,    59,    60,    61,    62,    63,    64,    65,    50,
      51,    66,    67,    57,     7,    55,    18,    56,    59,    60,
      61,    62,    63,    64,    65,    55,    11,     3,    57,     3,
      58,    54,    12,     3,    34,    48,    58,    40,    48,    48,
      39,    48,    48,    48,    13,    27,    14,    10,    49,    41,
      15,    65,    13,    57,    51,    19,    54,     3,    54,    30,
      37,   200,    52,    57,    59,    54,    21,    58,    54,    57,
      30,    54,    59,   140,    58,   113,    57,   130,   197,    58,
     224,   203,   165,    61,   194,    -1,   145,    -1,    -1,   147,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    71,    72,    73,    74,    76,    77,    78,   103,
     110,   118,    30,    79,     0,    73,    53,    22,    23,    24,
      75,     7,    25,    32,    36,     3,    80,    81,     8,     9,
      82,    82,    26,    33,   111,    10,    31,    54,    76,    77,
       3,     4,     6,    56,    57,    83,    84,    86,   129,     3,
       3,     3,    57,    81,    55,     3,   126,   127,   128,   129,
      10,    54,    87,     3,    31,    85,    85,    56,   112,    18,
     119,    74,     3,    56,    55,    58,    65,    66,    67,    56,
      68,    57,    86,    88,    89,    90,    91,    84,    11,    94,
       3,    57,   104,    85,    88,    94,    58,   127,   128,   128,
     129,   129,    74,    89,    85,    54,    42,    43,    44,    45,
      46,    47,    48,    93,    85,    51,    57,   120,   121,   122,
     126,    12,    95,    86,   105,    27,    28,    74,   106,    34,
     113,    58,    58,    89,    48,    48,    48,    48,    48,    48,
      57,    90,   122,   120,   126,    40,    39,    50,    51,    59,
      60,    61,    62,    63,    64,   123,   125,    13,    14,    97,
      54,    58,    57,   107,    27,    57,    86,   114,   115,   117,
      87,    85,    89,    91,    49,    92,    58,   121,   122,   123,
      41,   126,    86,    96,   120,    15,    98,    86,    28,   108,
     109,   126,    54,   105,    54,    59,    94,    58,   120,    52,
      57,    54,    13,    54,    58,    57,    58,   115,    28,   116,
     120,   126,    92,    74,    83,   124,    86,    99,   100,   126,
     109,   108,    59,    58,    54,    16,    17,   101,    58,    35,
      57,   100,    19,   102,    57,    74,   108,    20,    21,   108,
      58,    58,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   101,
     101,   101,   102,   102,   102,   103,   104,   104,   105,   105,
     106,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     111,   111,   112,   112,   113,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   117,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   127,   128,   128,   128,   129,   129,   129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       4,     1,     1,     1,     9,     1,     0,     3,     1,     0,
       1,     3,     5,     1,     1,     0,     2,     4,     1,     1,
       3,     2,     1,     0,     1,     3,     2,     0,     1,     3,
       1,     1,     3,     2,     4,     4,     6,     2,     0,     2,
       2,     2,     2,     2,     1,     2,     2,     0,     3,     0,
       1,     3,     2,     0,     3,     0,     1,     3,     3,     1,
       1,     0,     2,     2,     0,     7,     3,     0,     1,     3,
       2,     2,     1,     3,     5,     1,     3,     1,     1,     9,
       1,     0,     1,     0,     2,     1,     3,     3,     7,     8,
       7,     1,     1,     1,     1,     6,     2,     0,     1,     3,
       1,     3,     3,     2,     3,     4,     6,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 90 "parser.y"
    {
    }
#line 1600 "y.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 96 "parser.y"
    {
    }
#line 1607 "y.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 99 "parser.y"
    {
    }
#line 1614 "y.tab.c"
    break;

  case 5: /* statement: query SEMICOLON  */
#line 105 "parser.y"
    {
        no_with_tables=0;
        (yyval.node) = (yyvsp[-1].node);
        parse_tree[parse_tree_count] = (yyval.node);
        parse_tree_count++;
        printf("=================================================================================================\n");
        printf("\nOriginal Relational Algebra Tree for sql statement %d:\n",parse_tree_count);
        print_tree((yyvsp[-1].node), 0);
        printf("\nCost of actual tree: %lld\n",cost_calculation((yyvsp[-1].node)));


        printf("---------------------------------------------------------------------------------------------------\n");
        (yyval.node) = pre_transform_tree((yyval.node),NULL);
        printf("\nTree after Pre-Transformations:\n");
        print_tree((yyval.node), 0);

        num_trees=1;
        for(int i=0;i<MAX_RES_TREE;i++){
            all_trees[i]=NULL;
        }
        all_trees[0] = deep_copy_tree((yyval.node));
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
#line 1668 "y.tab.c"
    break;

  case 6: /* query: select_stmt  */
#line 158 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1676 "y.tab.c"
    break;

  case 7: /* query: insert_stmt  */
#line 162 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1684 "y.tab.c"
    break;

  case 8: /* query: update_stmt  */
#line 166 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1692 "y.tab.c"
    break;

  case 9: /* query: delete_stmt  */
#line 170 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1700 "y.tab.c"
    break;

  case 10: /* query: select_stmt set_op select_opts select_stmt  */
#line 174 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        (yyval.node)->left = (yyvsp[-3].node);
        (yyval.node)->right = (yyvsp[0].node);
        if((yyvsp[-1].node) && strcmp((yyvsp[-1].node)->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, (yyvsp[-1].node)->value);
            distinct->left = (yyval.node);
            (yyval.node) = distinct;
        }
    }
#line 1715 "y.tab.c"
    break;

  case 11: /* set_op: UNION  */
#line 188 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∪");  // Union symbol
    }
#line 1723 "y.tab.c"
    break;

  case 12: /* set_op: INTERSECT  */
#line 192 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∩");  // Intersection symbol
    }
#line 1731 "y.tab.c"
    break;

  case 13: /* set_op: EXCEPT  */
#line 196 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "−");  // Minus symbol
    }
#line 1739 "y.tab.c"
    break;

  case 14: /* select_stmt: with_clause_opt SELECT select_opts column_list from_clause where_clause group_clause having_clause order_clause  */
#line 204 "parser.y"
    {
        // Start building the tree from the bottom up
        ASTNode* base_tree = (yyvsp[-4].node);  // FROM clause
        
        // Apply WITH clause
        if ((yyvsp[-8].node) && (yyvsp[-8].node)->type != RA_EMPTY) {
            (yyvsp[-8].node)->right=base_tree;
            base_tree=(yyvsp[-8].node);
        }

        // Apply WHERE clause (σ - selection)
        if ((yyvsp[-3].node) && (yyvsp[-3].node)->type != RA_EMPTY) {
            ASTNode* selection = (yyvsp[-3].node);
            // selection->left = $6->left;  // Condition
            // selection->args = $6;
            selection->left = base_tree;
            base_tree = selection;
        }
        
        // Apply GROUP BY (γ - grouping)
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != RA_EMPTY) {
            ASTNode* grouping = (yyvsp[-2].node);
            // grouping->left = $7->left;  // Grouping columns
            // grouping->args = $7;
            grouping->left = base_tree;
            base_tree = grouping;
        }
        
        // Apply HAVING (σ - selection after grouping)
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->type != RA_EMPTY) {
            ASTNode* having = (yyvsp[-1].node);
            // having->left = $8->left;  // Condition
            // having->args = $8;
            having->left = base_tree;
            base_tree = having;
        }
        
        // Apply projection (π)
        ASTNode* projection = create_node(RA_PROJECTION, "");
        projection->args = (yyvsp[-5].node);  // SELECT columns
        projection->left = base_tree;

        // Apply DISTINCT if specified
        if ((yyvsp[-6].node) && strcmp((yyvsp[-6].node)->value, "DISTINCT") == 0) {
            ASTNode* distinct = create_node(RA_DISTINCT, "DISTINCT");
            distinct->left = projection;
            (yyval.node) = distinct;
        }
        else{
            (yyval.node) = projection;
        }
        
        // Apply ORDER BY
        if ((yyvsp[0].node) && (yyvsp[0].node)->type != RA_EMPTY) {
            (yyvsp[0].node)->right = (yyval.node);
            (yyval.node) = (yyvsp[0].node);
        }
        
    }
#line 1803 "y.tab.c"
    break;

  case 15: /* with_clause_opt: with_clause  */
#line 267 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1811 "y.tab.c"
    break;

  case 16: /* with_clause_opt: %empty  */
#line 271 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1819 "y.tab.c"
    break;

  case 17: /* with_clause: WITH recursive_opt with_query_list  */
#line 278 "parser.y"
    {
        (yyval.node) = create_node(RA_WITH, "");
        if (strcmp((yyvsp[-1].node)->value, "RECURSIVE") == 0) {
            strcpy((yyval.node)->value,"RECURSIVE") ; // Mark as recursive
        }
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1831 "y.tab.c"
    break;

  case 18: /* recursive_opt: RECURSIVE  */
#line 289 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "RECURSIVE");
    }
#line 1839 "y.tab.c"
    break;

  case 19: /* recursive_opt: %empty  */
#line 293 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1847 "y.tab.c"
    break;

  case 20: /* with_query_list: with_query  */
#line 300 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1855 "y.tab.c"
    break;

  case 21: /* with_query_list: with_query_list COMMA with_query  */
#line 304 "parser.y"
    {
        ASTNode* list = create_node(RA_WITH_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 1866 "y.tab.c"
    break;

  case 22: /* with_query: ID AS LPAREN query RPAREN  */
#line 314 "parser.y"
    {
        (yyval.node) = create_node(RA_RELATION, (yyvsp[-4].str));  // Represents a table now available by name $1
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[-4].str));
        (yyval.node)->left = (yyvsp[-1].node);
        // Build scope of the query result
        scope_attr *with_scope = build_scope((yyvsp[-1].node));

        // Count attributes
        int no_with_attr = 0;
        for (scope_attr *temp = with_scope; temp; temp = temp->next) {
            no_with_attr++;
        }

        // Store metadata in global tables[]
        TABLE *t = &tables[num_tables];
        t->TABLE_NAME = strdup((yyvsp[-4].str));
        t->num_attributes = no_with_attr;
        t->attr_list = (attr*)malloc(no_with_attr * sizeof(attr));
        t->num_tuples = estimate_size((yyvsp[-1].node)); // You should implement this function

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
#line 1905 "y.tab.c"
    break;

  case 23: /* select_opts: ALL  */
#line 352 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ALL");
    }
#line 1913 "y.tab.c"
    break;

  case 24: /* select_opts: DISTINCT  */
#line 356 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DISTINCT");
    }
#line 1921 "y.tab.c"
    break;

  case 25: /* select_opts: %empty  */
#line 360 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1929 "y.tab.c"
    break;

  case 26: /* column_list: column as_id_opt  */
#line 367 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle column alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->args = (yyvsp[-1].node);
            (yyval.node) = alias;
        } else {
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1944 "y.tab.c"
    break;

  case 27: /* column_list: column_list COMMA column as_id_opt  */
#line 378 "parser.y"
    {
        ASTNode* col;
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle column alias
            col = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            col->args = (yyvsp[-1].node);
        } else {
            col = (yyvsp[-1].node);
        }
        (yyval.node) = col;
        (yyval.node)->left=(yyvsp[-3].node);
    }
#line 1961 "y.tab.c"
    break;

  case 28: /* column_list: ASTERISK  */
#line 391 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 1969 "y.tab.c"
    break;

  case 29: /* column: term  */
#line 398 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1977 "y.tab.c"
    break;

  case 30: /* column: ID DOT ASTERISK  */
#line 402 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.*", (yyvsp[-2].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 1987 "y.tab.c"
    break;

  case 31: /* as_id_opt: AS ID  */
#line 411 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 1995 "y.tab.c"
    break;

  case 32: /* as_id_opt: ID  */
#line 415 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 2003 "y.tab.c"
    break;

  case 33: /* as_id_opt: %empty  */
#line 419 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2011 "y.tab.c"
    break;

  case 34: /* modified_id: ID  */
#line 426 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, (yyvsp[0].str));
    }
#line 2019 "y.tab.c"
    break;

  case 35: /* modified_id: ID DOT ID  */
#line 430 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 2029 "y.tab.c"
    break;

  case 36: /* from_clause: FROM from_item_list  */
#line 439 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2037 "y.tab.c"
    break;

  case 37: /* from_clause: %empty  */
#line 443 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2045 "y.tab.c"
    break;

  case 38: /* from_item_list: from_item  */
#line 451 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2053 "y.tab.c"
    break;

  case 39: /* from_item_list: from_item_list COMMA from_item  */
#line 455 "parser.y"
    {
        ASTNode* cross_join = create_node(RA_JOIN, "⋈");  // Cross product
        cross_join->left = (yyvsp[-2].node);
        cross_join->right = (yyvsp[0].node);
        (yyval.node) = cross_join;
    }
#line 2064 "y.tab.c"
    break;

  case 40: /* from_item: joined_table  */
#line 465 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2072 "y.tab.c"
    break;

  case 41: /* from_item: base_table  */
#line 469 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2080 "y.tab.c"
    break;

  case 42: /* from_item: LPAREN from_item RPAREN  */
#line 473 "parser.y"
    {
        (yyval.node)=(yyvsp[-1].node);
    }
#line 2088 "y.tab.c"
    break;

  case 43: /* base_table: modified_id as_id_opt  */
#line 480 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->left = create_node(RA_RELATION, (yyvsp[-1].node)->value);
            (yyval.node) = alias;
        } else {
            (yyval.node) = create_node(RA_RELATION, (yyvsp[-1].node)->value);
        }
    }
#line 2103 "y.tab.c"
    break;

  case 44: /* base_table: LPAREN query RPAREN as_id_opt  */
#line 491 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->left = (yyvsp[-2].node);
            (yyval.node) = alias;
        } else {
            (yyval.node) = (yyvsp[-2].node);
        }
    }
#line 2118 "y.tab.c"
    break;

  case 45: /* joined_table: from_item join_type base_table join_condition_opt  */
#line 505 "parser.y"
    {        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-2].node)->value);
        join->left = (yyvsp[-3].node);
        join->right = (yyvsp[-1].node);
        
        // Add join condition
        if((yyvsp[0].node)->type != RA_EMPTY) join->condition = (yyvsp[0].node);
        
        (yyval.node) = join;
    }
#line 2133 "y.tab.c"
    break;

  case 46: /* joined_table: from_item join_type LPAREN joined_table RPAREN join_condition_opt  */
#line 516 "parser.y"
    {        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-4].node)->value);
        join->left = (yyvsp[-5].node);
        join->right = (yyvsp[-2].node);
        
        // Add join condition
        if((yyvsp[0].node)->type != RA_EMPTY) join->condition = (yyvsp[0].node);
        
        (yyval.node) = join;
    }
#line 2148 "y.tab.c"
    break;

  case 47: /* join_condition_opt: ON expression  */
#line 530 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2156 "y.tab.c"
    break;

  case 48: /* join_condition_opt: %empty  */
#line 534 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2164 "y.tab.c"
    break;

  case 49: /* join_type: INNER JOIN  */
#line 542 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
#line 2172 "y.tab.c"
    break;

  case 50: /* join_type: LEFT JOIN  */
#line 546 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟕");  // Left join symbol
    }
#line 2180 "y.tab.c"
    break;

  case 51: /* join_type: RIGHT JOIN  */
#line 550 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟖");  // Right join symbol
    }
#line 2188 "y.tab.c"
    break;

  case 52: /* join_type: FULL JOIN  */
#line 554 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟗");  // Full join symbol
    }
#line 2196 "y.tab.c"
    break;

  case 53: /* join_type: CROSS JOIN  */
#line 558 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Cross join symbol
    }
#line 2204 "y.tab.c"
    break;

  case 54: /* join_type: JOIN  */
#line 562 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Join symbol
    }
#line 2212 "y.tab.c"
    break;

  case 55: /* join_type: NATURAL JOIN  */
#line 566 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈ᴺ");  // Natural join symbol
    }
#line 2220 "y.tab.c"
    break;

  case 56: /* where_clause: WHERE expression  */
#line 573 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "WHERE");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2229 "y.tab.c"
    break;

  case 57: /* where_clause: %empty  */
#line 578 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2237 "y.tab.c"
    break;

  case 58: /* group_clause: GROUP BY group_item_list  */
#line 585 "parser.y"
    {
        (yyval.node) = create_node(RA_GROUPBY, "GROUP BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2246 "y.tab.c"
    break;

  case 59: /* group_clause: %empty  */
#line 590 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2254 "y.tab.c"
    break;

  case 60: /* group_item_list: modified_id  */
#line 597 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2262 "y.tab.c"
    break;

  case 61: /* group_item_list: group_item_list COMMA modified_id  */
#line 601 "parser.y"
    {
        ASTNode* list = create_node(RA_GROUP_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2273 "y.tab.c"
    break;

  case 62: /* having_clause: HAVING expression  */
#line 611 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "HAVING");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2282 "y.tab.c"
    break;

  case 63: /* having_clause: %empty  */
#line 616 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2290 "y.tab.c"
    break;

  case 64: /* order_clause: ORDER BY order_item_list  */
#line 623 "parser.y"
    {
        (yyval.node) = create_node(RA_ORDERBY, "ORDER BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2299 "y.tab.c"
    break;

  case 65: /* order_clause: %empty  */
#line 628 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2307 "y.tab.c"
    break;

  case 66: /* order_item_list: order_item  */
#line 635 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
        (yyvsp[0].node)->args = NULL;
    }
#line 2316 "y.tab.c"
    break;

  case 67: /* order_item_list: order_item_list COMMA order_item  */
#line 640 "parser.y"
    {
        ASTNode* curr = (yyvsp[-2].node);
        while (curr->args) curr = curr->args;
        curr->args = (yyvsp[0].node);
        (yyvsp[0].node)->args = NULL;
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2328 "y.tab.c"
    break;

  case 68: /* order_item: operand order_option nulls_option  */
#line 651 "parser.y"
    {
        char direction[MAX_STRING_LENGTH] = "";
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            strncpy(direction, (yyvsp[-1].node)->value, MAX_STRING_LENGTH - 1);
        }
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            if (direction[0] != '\0') {
                strncat(direction, ", ", MAX_STRING_LENGTH - strlen(direction) - 1);
            }
            strncat(direction, (yyvsp[0].node)->value, MAX_STRING_LENGTH - strlen(direction) - 1);
        }
        
        ASTNode* order_item = create_node(RA_ORDER_ITEM, direction);
        order_item->left = (yyvsp[-2].node);
        (yyval.node) = order_item;
        
    }
#line 2351 "y.tab.c"
    break;

  case 69: /* order_option: ASC  */
#line 673 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ASC");
    }
#line 2359 "y.tab.c"
    break;

  case 70: /* order_option: DESC  */
#line 677 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DESC");
    }
#line 2367 "y.tab.c"
    break;

  case 71: /* order_option: %empty  */
#line 681 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2375 "y.tab.c"
    break;

  case 72: /* nulls_option: NULLS FIRST  */
#line 688 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS FIRST");
    }
#line 2383 "y.tab.c"
    break;

  case 73: /* nulls_option: NULLS LAST  */
#line 692 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS LAST");
    }
#line 2391 "y.tab.c"
    break;

  case 74: /* nulls_option: %empty  */
#line 696 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2399 "y.tab.c"
    break;

  case 75: /* insert_stmt: with_clause_opt INSERT INTO ID as_id_opt column_list_opt insert_values  */
#line 704 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-3].str));
        
        // Apply WITH clause
        if ((yyvsp[-6].node) && (yyvsp[-6].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-6].node);
        }

        if ((yyvsp[-2].node)->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[-2].node)->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* insert = create_node(RA_INSERT, "INSERT");
        insert->left = target;
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            insert->right = (yyvsp[-1].node);  // Columns
        }
        
        insert->args = (yyvsp[0].node);  // Values or subquery
        
        (yyval.node) = insert;
    }
#line 2428 "y.tab.c"
    break;

  case 76: /* column_list_opt: LPAREN column_name_list RPAREN  */
#line 732 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2436 "y.tab.c"
    break;

  case 77: /* column_list_opt: %empty  */
#line 736 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2444 "y.tab.c"
    break;

  case 78: /* column_name_list: modified_id  */
#line 743 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2452 "y.tab.c"
    break;

  case 79: /* column_name_list: column_name_list COMMA modified_id  */
#line 747 "parser.y"
    {
        ASTNode* list = create_node(RA_COLUMN_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2463 "y.tab.c"
    break;

  case 80: /* insert_values: DEFAULT VALUES  */
#line 757 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "DEFAULT");
    }
#line 2471 "y.tab.c"
    break;

  case 81: /* insert_values: VALUES insert_value_list  */
#line 761 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2480 "y.tab.c"
    break;

  case 82: /* insert_values: query  */
#line 766 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);  // Subquery
    }
#line 2488 "y.tab.c"
    break;

  case 83: /* insert_value_list: LPAREN insert_value_items RPAREN  */
#line 773 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->right = (yyvsp[-1].node);
        (yyval.node) = list;
    }
#line 2498 "y.tab.c"
    break;

  case 84: /* insert_value_list: insert_value_list COMMA LPAREN insert_value_items RPAREN  */
#line 779 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->left = (yyvsp[-4].node);
        list->right = (yyvsp[-1].node);
        (yyval.node) = list;
    }
#line 2509 "y.tab.c"
    break;

  case 85: /* insert_value_items: insert_value  */
#line 789 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2517 "y.tab.c"
    break;

  case 86: /* insert_value_items: insert_value_items COMMA insert_value  */
#line 793 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_ITEMS, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2528 "y.tab.c"
    break;

  case 87: /* insert_value: operand  */
#line 803 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2536 "y.tab.c"
    break;

  case 88: /* insert_value: DEFAULT  */
#line 807 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2544 "y.tab.c"
    break;

  case 89: /* update_stmt: with_clause_opt UPDATE only_opt ID asterisk_opt as_id_opt set_clause from_clause where_clause  */
#line 815 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-5].str));

        // Apply WITH clause
        if ((yyvsp[-8].node) && (yyvsp[-8].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-8].node);
        }

        if ((yyvsp[-3].node)->type != RA_EMPTY) {
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[-3].node)->value);
            alias->left = target;
            target = alias;
        }
        
        ASTNode* update = create_node(RA_UPDATE, "");
        update->left = target;
        update->args = (yyvsp[-2].node);  // SET clause
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            update->right = (yyvsp[0].node);  // WHERE condition
        }

        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            if(update->right==NULL)update->right = (yyvsp[-1].node);
            else{
                update->right->left = (yyvsp[-1].node);
            }
        }
        
        
        (yyval.node) = update;
    }
#line 2581 "y.tab.c"
    break;

  case 90: /* only_opt: ONLY  */
#line 851 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ONLY");
    }
#line 2589 "y.tab.c"
    break;

  case 91: /* only_opt: %empty  */
#line 855 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2597 "y.tab.c"
    break;

  case 92: /* asterisk_opt: ASTERISK  */
#line 862 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 2605 "y.tab.c"
    break;

  case 93: /* asterisk_opt: %empty  */
#line 866 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2613 "y.tab.c"
    break;

  case 94: /* set_clause: SET set_item_list  */
#line 873 "parser.y"
    {
        (yyval.node) = create_node(RA_SET, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2622 "y.tab.c"
    break;

  case 95: /* set_item_list: set_item  */
#line 881 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2630 "y.tab.c"
    break;

  case 96: /* set_item_list: set_item_list COMMA set_item  */
#line 885 "parser.y"
    {
        ASTNode* list = create_node(RA_SET_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2641 "y.tab.c"
    break;

  case 97: /* set_item: column_name EQ set_value  */
#line 895 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-2].node);
        assignment->right = (yyvsp[0].node);
        (yyval.node) = assignment;
    }
#line 2652 "y.tab.c"
    break;

  case 98: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN insert_value_items RPAREN  */
#line 902 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2663 "y.tab.c"
    break;

  case 99: /* set_item: LPAREN column_name_list RPAREN EQ ROW LPAREN insert_value_items RPAREN  */
#line 909 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "= ROW");
        assignment->left = (yyvsp[-6].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2674 "y.tab.c"
    break;

  case 100: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN query RPAREN  */
#line 916 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2685 "y.tab.c"
    break;

  case 101: /* set_value: operand  */
#line 926 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2693 "y.tab.c"
    break;

  case 102: /* set_value: expression  */
#line 930 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2701 "y.tab.c"
    break;

  case 103: /* set_value: DEFAULT  */
#line 934 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2709 "y.tab.c"
    break;

  case 104: /* column_name: modified_id  */
#line 941 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2717 "y.tab.c"
    break;

  case 105: /* delete_stmt: with_clause_opt DELETE FROM ID using_clause_opt where_clause  */
#line 949 "parser.y"
    {
        ASTNode* target = create_node(RA_RELATION, (yyvsp[-2].str));
        
        // Apply WITH clause
        if ((yyvsp[-5].node) && (yyvsp[-5].node)->type != RA_EMPTY) {
            target->left = (yyvsp[-5].node);
        }

        ASTNode* delete = create_node(RA_DELETE, "");
        delete->left = target;
        
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            delete->right = (yyvsp[-1].node);  // USING clause
        }
        
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            if(delete->right)delete->right->left = (yyvsp[0].node);  // WHERE condition
            else delete->right = (yyvsp[0].node);
        }
        
        (yyval.node) = delete;
    }
#line 2744 "y.tab.c"
    break;

  case 106: /* using_clause_opt: USING from_item_list  */
#line 975 "parser.y"
    {
        (yyval.node) = create_node(RA_USING, "");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2753 "y.tab.c"
    break;

  case 107: /* using_clause_opt: %empty  */
#line 980 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2761 "y.tab.c"
    break;

  case 108: /* expression: and_condition  */
#line 988 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2769 "y.tab.c"
    break;

  case 109: /* expression: expression OR and_condition  */
#line 992 "parser.y"
    {
        ASTNode* or_node = create_node(RA_OR, "OR");
        or_node->left = (yyvsp[-2].node);
        or_node->right = (yyvsp[0].node);
        (yyval.node) = or_node;
    }
#line 2780 "y.tab.c"
    break;

  case 110: /* and_condition: condition  */
#line 1002 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2788 "y.tab.c"
    break;

  case 111: /* and_condition: and_condition AND condition  */
#line 1006 "parser.y"
    {
        ASTNode* and_node = create_node(RA_AND, "AND");
        and_node->left = (yyvsp[-2].node);
        and_node->right = (yyvsp[0].node);
        (yyval.node) = and_node;
    }
#line 2799 "y.tab.c"
    break;

  case 112: /* condition: LPAREN expression RPAREN  */
#line 1016 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2807 "y.tab.c"
    break;

  case 113: /* condition: NOT condition  */
#line 1020 "parser.y"
    {
        ASTNode* not_node = create_node(RA_NOT, "NOT");
        not_node->left = (yyvsp[0].node);
        (yyval.node) = not_node;
    }
#line 2817 "y.tab.c"
    break;

  case 114: /* condition: operand comparison_op operand  */
#line 1026 "parser.y"
    {
        ASTNode* comp = create_node(RA_COMPARISON, (yyvsp[-1].node)->value);
        comp->left = (yyvsp[-2].node);
        comp->right = (yyvsp[0].node);
        (yyval.node) = comp;
    }
#line 2828 "y.tab.c"
    break;

  case 115: /* condition: operand IS not_opt NULL_VAL  */
#line 1033 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        if ((yyvsp[-1].node)->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "IS NOT NULL");
        } else {
            snprintf(value, sizeof(value), "IS NULL");
        }
        
        ASTNode* null_check = create_node(RA_NULL_CHECK, value);
        null_check->left = (yyvsp[-3].node);
        (yyval.node) = null_check;
    }
#line 2845 "y.tab.c"
    break;

  case 116: /* condition: operand not_opt IN LPAREN in_items RPAREN  */
#line 1052 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        if ((yyvsp[-4].node)->type != RA_EMPTY) {
            snprintf(value, sizeof(value), "NOT IN");
        } else {
            snprintf(value, sizeof(value), "IN");
        }
        
        ASTNode* in_check = create_node(RA_IN, value);
        in_check->left = (yyvsp[-5].node);
        in_check->right = (yyvsp[-1].node);
        (yyval.node) = in_check;
    }
#line 2863 "y.tab.c"
    break;

  case 117: /* not_opt: NOT  */
#line 1088 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NOT");
    }
#line 2871 "y.tab.c"
    break;

  case 118: /* not_opt: %empty  */
#line 1092 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2879 "y.tab.c"
    break;

  case 119: /* in_items: column_list  */
#line 1099 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2887 "y.tab.c"
    break;

  case 120: /* in_items: query  */
#line 1103 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2895 "y.tab.c"
    break;

  case 121: /* comparison_op: EQ  */
#line 1110 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "=");
    }
#line 2903 "y.tab.c"
    break;

  case 122: /* comparison_op: NE  */
#line 1114 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<>");
    }
#line 2911 "y.tab.c"
    break;

  case 123: /* comparison_op: LT  */
#line 1118 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<");
    }
#line 2919 "y.tab.c"
    break;

  case 124: /* comparison_op: GT  */
#line 1122 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">");
    }
#line 2927 "y.tab.c"
    break;

  case 125: /* comparison_op: LE  */
#line 1126 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<=");
    }
#line 2935 "y.tab.c"
    break;

  case 126: /* comparison_op: GE  */
#line 1130 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">=");
    }
#line 2943 "y.tab.c"
    break;

  case 127: /* operand: summand  */
#line 1137 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2951 "y.tab.c"
    break;

  case 128: /* operand: operand CONCAT summand  */
#line 1141 "parser.y"
    {
        ASTNode* concat = create_node(RA_CONCAT, "||");
        concat->left = (yyvsp[-2].node);
        concat->right = (yyvsp[0].node);
        (yyval.node) = concat;
    }
#line 2962 "y.tab.c"
    break;

  case 129: /* summand: factor  */
#line 1151 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2970 "y.tab.c"
    break;

  case 130: /* summand: summand PLUS factor  */
#line 1155 "parser.y"
    {
        ASTNode* add = create_node(RA_ARITHMETIC, "+");
        add->left = (yyvsp[-2].node);
        add->right = (yyvsp[0].node);
        (yyval.node) = add;
    }
#line 2981 "y.tab.c"
    break;

  case 131: /* summand: summand MINUS factor  */
#line 1162 "parser.y"
    {
        ASTNode* subtract = create_node(RA_ARITHMETIC, "-");
        subtract->left = (yyvsp[-2].node);
        subtract->right = (yyvsp[0].node);
        (yyval.node) = subtract;
    }
#line 2992 "y.tab.c"
    break;

  case 132: /* factor: term  */
#line 1172 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3000 "y.tab.c"
    break;

  case 133: /* factor: factor ASTERISK term  */
#line 1176 "parser.y"
    {
        ASTNode* multiply = create_node(RA_ARITHMETIC, "*");
        multiply->left = (yyvsp[-2].node);
        multiply->right = (yyvsp[0].node);
        (yyval.node) = multiply;
    }
#line 3011 "y.tab.c"
    break;

  case 134: /* factor: factor DIV term  */
#line 1183 "parser.y"
    {
        ASTNode* divide = create_node(RA_ARITHMETIC, "/");
        divide->left = (yyvsp[-2].node);
        divide->right = (yyvsp[0].node);
        (yyval.node) = divide;
    }
#line 3022 "y.tab.c"
    break;

  case 135: /* term: LPAREN operand RPAREN  */
#line 1193 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 3030 "y.tab.c"
    break;

  case 136: /* term: modified_id  */
#line 1197 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3038 "y.tab.c"
    break;

  case 137: /* term: NUM  */
#line 1201 "parser.y"
    {
        char value[32];
        snprintf(value, sizeof(value), "%d", (yyvsp[0].num));
        (yyval.node) = create_node(RA_LITERAL, value);
    }
#line 3048 "y.tab.c"
    break;

  case 138: /* term: STRING_LITERAL  */
#line 1207 "parser.y"
    {
        (yyval.node) = create_node(RA_LITERAL, (yyvsp[0].str));
    }
#line 3056 "y.tab.c"
    break;


#line 3060 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1212 "parser.y"




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
