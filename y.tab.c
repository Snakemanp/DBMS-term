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

#line 93 "y.tab.c"

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
    LEFT = 298,                    /* LEFT  */
    RIGHT = 299,                   /* RIGHT  */
    FULL = 300,                    /* FULL  */
    CROSS = 301,                   /* CROSS  */
    JOIN = 302,                    /* JOIN  */
    ON = 303,                      /* ON  */
    IS = 304,                      /* IS  */
    NOT = 305,                     /* NOT  */
    NULL_VAL = 306,                /* NULL_VAL  */
    SEMICOLON = 307,               /* SEMICOLON  */
    COMMA = 308,                   /* COMMA  */
    DOT = 309,                     /* DOT  */
    ASTERISK = 310,                /* ASTERISK  */
    LPAREN = 311,                  /* LPAREN  */
    RPAREN = 312,                  /* RPAREN  */
    EQ = 313,                      /* EQ  */
    NE = 314,                      /* NE  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    CONCAT = 319,                  /* CONCAT  */
    PLUS = 320,                    /* PLUS  */
    MINUS = 321,                   /* MINUS  */
    DIV = 322,                     /* DIV  */
    UMINUS = 323                   /* UMINUS  */
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
#define LEFT 298
#define RIGHT 299
#define FULL 300
#define CROSS 301
#define JOIN 302
#define ON 303
#define IS 304
#define NOT 305
#define NULL_VAL 306
#define SEMICOLON 307
#define COMMA 308
#define DOT 309
#define ASTERISK 310
#define LPAREN 311
#define RPAREN 312
#define EQ 313
#define NE 314
#define LT 315
#define GT 316
#define LE 317
#define GE 318
#define CONCAT 319
#define PLUS 320
#define MINUS 321
#define DIV 322
#define UMINUS 323

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

    char* str;
    int num;
    struct ASTNode* node;

#line 288 "y.tab.c"

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
  YYSYMBOL_LEFT = 43,                      /* LEFT  */
  YYSYMBOL_RIGHT = 44,                     /* RIGHT  */
  YYSYMBOL_FULL = 45,                      /* FULL  */
  YYSYMBOL_CROSS = 46,                     /* CROSS  */
  YYSYMBOL_JOIN = 47,                      /* JOIN  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_IS = 49,                        /* IS  */
  YYSYMBOL_NOT = 50,                       /* NOT  */
  YYSYMBOL_NULL_VAL = 51,                  /* NULL_VAL  */
  YYSYMBOL_SEMICOLON = 52,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 53,                     /* COMMA  */
  YYSYMBOL_DOT = 54,                       /* DOT  */
  YYSYMBOL_ASTERISK = 55,                  /* ASTERISK  */
  YYSYMBOL_LPAREN = 56,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 57,                    /* RPAREN  */
  YYSYMBOL_EQ = 58,                        /* EQ  */
  YYSYMBOL_NE = 59,                        /* NE  */
  YYSYMBOL_LT = 60,                        /* LT  */
  YYSYMBOL_GT = 61,                        /* GT  */
  YYSYMBOL_LE = 62,                        /* LE  */
  YYSYMBOL_GE = 63,                        /* GE  */
  YYSYMBOL_CONCAT = 64,                    /* CONCAT  */
  YYSYMBOL_PLUS = 65,                      /* PLUS  */
  YYSYMBOL_MINUS = 66,                     /* MINUS  */
  YYSYMBOL_DIV = 67,                       /* DIV  */
  YYSYMBOL_UMINUS = 68,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_program = 70,                   /* program  */
  YYSYMBOL_statement_list = 71,            /* statement_list  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_query = 73,                     /* query  */
  YYSYMBOL_set_op = 74,                    /* set_op  */
  YYSYMBOL_select_stmt = 75,               /* select_stmt  */
  YYSYMBOL_with_clause_opt = 76,           /* with_clause_opt  */
  YYSYMBOL_with_clause = 77,               /* with_clause  */
  YYSYMBOL_recursive_opt = 78,             /* recursive_opt  */
  YYSYMBOL_with_query_list = 79,           /* with_query_list  */
  YYSYMBOL_with_query = 80,                /* with_query  */
  YYSYMBOL_select_opts = 81,               /* select_opts  */
  YYSYMBOL_column_list = 82,               /* column_list  */
  YYSYMBOL_column = 83,                    /* column  */
  YYSYMBOL_as_id_opt = 84,                 /* as_id_opt  */
  YYSYMBOL_modified_id = 85,               /* modified_id  */
  YYSYMBOL_from_clause = 86,               /* from_clause  */
  YYSYMBOL_from_item_list = 87,            /* from_item_list  */
  YYSYMBOL_from_item = 88,                 /* from_item  */
  YYSYMBOL_join_type = 89,                 /* join_type  */
  YYSYMBOL_where_clause = 90,              /* where_clause  */
  YYSYMBOL_group_clause = 91,              /* group_clause  */
  YYSYMBOL_group_item_list = 92,           /* group_item_list  */
  YYSYMBOL_having_clause = 93,             /* having_clause  */
  YYSYMBOL_order_clause = 94,              /* order_clause  */
  YYSYMBOL_order_item_list = 95,           /* order_item_list  */
  YYSYMBOL_order_item = 96,                /* order_item  */
  YYSYMBOL_order_option = 97,              /* order_option  */
  YYSYMBOL_nulls_option = 98,              /* nulls_option  */
  YYSYMBOL_insert_stmt = 99,               /* insert_stmt  */
  YYSYMBOL_column_list_opt = 100,          /* column_list_opt  */
  YYSYMBOL_column_name_list = 101,         /* column_name_list  */
  YYSYMBOL_insert_values = 102,            /* insert_values  */
  YYSYMBOL_insert_value_list = 103,        /* insert_value_list  */
  YYSYMBOL_insert_value_items = 104,       /* insert_value_items  */
  YYSYMBOL_insert_value = 105,             /* insert_value  */
  YYSYMBOL_update_stmt = 106,              /* update_stmt  */
  YYSYMBOL_only_opt = 107,                 /* only_opt  */
  YYSYMBOL_asterisk_opt = 108,             /* asterisk_opt  */
  YYSYMBOL_set_clause = 109,               /* set_clause  */
  YYSYMBOL_set_item_list = 110,            /* set_item_list  */
  YYSYMBOL_set_item = 111,                 /* set_item  */
  YYSYMBOL_set_value = 112,                /* set_value  */
  YYSYMBOL_column_name = 113,              /* column_name  */
  YYSYMBOL_delete_stmt = 114,              /* delete_stmt  */
  YYSYMBOL_using_clause_opt = 115,         /* using_clause_opt  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_and_condition = 117,            /* and_condition  */
  YYSYMBOL_condition = 118,                /* condition  */
  YYSYMBOL_not_opt = 119,                  /* not_opt  */
  YYSYMBOL_in_items = 120,                 /* in_items  */
  YYSYMBOL_comparison_op = 121,            /* comparison_op  */
  YYSYMBOL_operand = 122,                  /* operand  */
  YYSYMBOL_summand = 123,                  /* summand  */
  YYSYMBOL_factor = 124,                   /* factor  */
  YYSYMBOL_term = 125                      /* term  */
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
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    87,    90,    96,   115,   119,   123,   127,
     131,   145,   149,   153,   161,   224,   229,   235,   246,   251,
     257,   261,   271,   280,   284,   289,   295,   306,   319,   326,
     330,   339,   343,   348,   354,   358,   367,   372,   378,   382,
     386,   396,   407,   420,   439,   458,   462,   466,   470,   474,
     478,   485,   491,   497,   503,   509,   513,   523,   529,   535,
     541,   547,   551,   561,   582,   586,   591,   597,   601,   606,
     613,   641,   646,   652,   656,   666,   670,   675,   682,   686,
     696,   700,   710,   714,   722,   758,   763,   769,   774,   780,
     788,   792,   802,   809,   816,   823,   833,   837,   841,   848,
     856,   882,   888,   895,   899,   909,   913,   923,   927,   933,
     940,   959,   995,  1000,  1006,  1010,  1017,  1021,  1025,  1029,
    1033,  1037,  1044,  1048,  1058,  1062,  1069,  1079,  1083,  1090,
    1100,  1104,  1108,  1114
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
  "DELETE", "EXISTS", "BETWEEN", "AND", "OR", "IN", "INNER", "LEFT",
  "RIGHT", "FULL", "CROSS", "JOIN", "ON", "IS", "NOT", "NULL_VAL",
  "SEMICOLON", "COMMA", "DOT", "ASTERISK", "LPAREN", "RPAREN", "EQ", "NE",
  "LT", "GT", "LE", "GE", "CONCAT", "PLUS", "MINUS", "DIV", "UMINUS",
  "$accept", "program", "statement_list", "statement", "query", "set_op",
  "select_stmt", "with_clause_opt", "with_clause", "recursive_opt",
  "with_query_list", "with_query", "select_opts", "column_list", "column",
  "as_id_opt", "modified_id", "from_clause", "from_item_list", "from_item",
  "join_type", "where_clause", "group_clause", "group_item_list",
  "having_clause", "order_clause", "order_item_list", "order_item",
  "order_option", "nulls_option", "insert_stmt", "column_list_opt",
  "column_name_list", "insert_values", "insert_value_list",
  "insert_value_items", "insert_value", "update_stmt", "only_opt",
  "asterisk_opt", "set_clause", "set_item_list", "set_item", "set_value",
  "column_name", "delete_stmt", "using_clause_opt", "expression",
  "and_condition", "condition", "not_opt", "in_items", "comparison_op",
  "operand", "summand", "factor", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-114)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,   -19,    17,    65,  -125,   -25,   157,    85,  -125,  -125,
    -125,  -125,  -125,    75,  -125,  -125,  -125,  -125,  -125,  -125,
      44,    44,    67,    63,    99,    87,    81,  -125,  -125,  -125,
     -23,    32,   139,  -125,   140,   151,   106,    75,  -125,   115,
     116,  -125,  -125,  -125,    51,    38,    11,  -125,  -125,    11,
     143,   159,   -23,  -125,     5,   145,    56,    62,    48,  -125,
      18,    60,   196,  -125,   205,  -125,   154,  -125,    11,    18,
     196,   152,  -125,  -125,   208,  -125,    51,    51,    51,    51,
      51,    20,    11,   160,   122,    11,    25,   200,  -125,   211,
     166,   181,   160,  -125,  -125,    62,    48,    48,  -125,  -125,
     161,    66,  -125,    21,   169,   170,   172,   173,   174,  -125,
     219,  -125,    25,    25,   183,   185,  -125,   142,   212,   213,
    -125,    73,   175,   199,  -125,  -125,    34,   218,    11,  -125,
     -23,   122,  -125,  -125,  -125,  -125,  -125,    11,  -125,    49,
     126,    25,    25,   179,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,   189,    51,   211,    25,   217,   211,  -125,    55,   180,
    -125,   211,  -125,   182,  -125,   176,   196,  -125,   188,  -125,
     185,  -125,   186,   184,   177,  -125,   190,   183,   225,  -125,
    -125,  -125,    76,  -125,   177,   191,    82,    34,     6,  -125,
      25,  -125,    12,   211,    51,    55,  -125,    55,   187,  -125,
    -125,  -125,   183,    97,   183,  -125,   193,   192,  -125,   195,
    -125,    68,  -125,    83,    69,  -125,    51,  -125,  -125,   220,
    -125,   194,    16,  -125,   153,  -125,    55,   197,    92,  -125,
    -125,    95,  -125,  -125,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      16,    19,     0,    16,     3,     0,     6,     0,    15,     7,
       8,     9,    18,     0,     1,     4,     5,    11,    12,    13,
      25,    25,     0,    86,     0,     0,    17,    20,    23,    24,
      16,     0,     0,    85,     0,     0,     0,     0,    10,     0,
      34,   133,   132,    28,     0,    37,    33,   131,    29,    33,
      88,   102,    16,    21,     0,    34,     0,   122,   124,   127,
       0,     0,    52,    32,     0,    26,    72,    87,    33,     0,
      52,     0,    35,    30,     0,   130,     0,     0,     0,     0,
       0,    16,    33,    36,    39,    33,     0,    54,    31,     0,
      16,     0,   101,   100,    22,   123,   125,   126,   128,   129,
       0,     0,    41,     0,     0,     0,     0,     0,     0,    50,
       0,    27,     0,     0,    51,   103,   105,   113,     0,    58,
      73,     0,     0,     0,    77,    70,     0,    37,    33,    38,
      16,    40,    45,    46,    47,    48,    49,    33,   108,     0,
     113,     0,     0,   113,   112,   116,   117,   118,   119,   120,
     121,     0,     0,     0,     0,    60,     0,    71,     0,    76,
      75,     0,    99,    89,    90,     0,    52,    42,    44,   107,
     104,   106,     0,     0,   109,    55,    53,    57,     0,    14,
      74,    83,     0,    80,    82,     0,     0,     0,     0,    84,
       0,   110,    16,     0,     0,     0,    78,     0,     0,    91,
      98,    92,    97,    96,    43,   115,   114,     0,    56,    59,
      61,    66,    81,     0,     0,   111,     0,    64,    65,    69,
      79,     0,    16,    62,     0,    63,     0,     0,     0,    67,
      68,     0,    95,    93,    94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   239,   -51,  -125,   214,   221,  -125,  -125,
    -125,   215,   232,    64,   198,   -42,   -56,   128,    43,   155,
    -125,   -67,  -125,  -125,  -125,  -125,  -125,    41,  -125,  -125,
    -125,  -125,   100,  -125,  -125,  -124,    70,  -125,  -125,  -125,
    -125,  -125,    77,  -125,  -125,  -125,  -125,  -108,   121,   -41,
     117,  -125,  -125,   -44,   201,   119,   -29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    20,     6,     7,     8,    13,
      26,    27,    30,    45,    46,    65,    47,    62,    83,    84,
     110,    87,   119,   176,   155,   179,   209,   210,   219,   225,
       9,    90,   121,   125,   159,   182,   183,    10,    34,    68,
     127,   163,   164,   201,   165,    11,    70,   114,   115,   116,
     151,   207,   152,   117,    57,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    71,    48,    93,    82,   139,     1,    66,    72,    55,
      41,    12,    42,    82,    63,    40,    41,    14,    42,    55,
      41,    55,    42,    55,    55,    82,    91,    16,    55,    41,
     100,    42,    48,   120,   200,    40,    41,    55,    42,   124,
     102,     1,    64,   111,   181,     1,   177,    82,    60,     1,
      98,    99,    28,    29,    55,    41,   112,    42,    55,    41,
      73,    42,   113,    40,    41,    -2,    42,    43,    44,   140,
     162,   138,    44,   213,    81,   112,    81,   130,    25,   100,
     202,   113,   204,   181,   217,   218,   167,    43,    44,   141,
     161,    61,    21,    32,     1,   168,    33,   175,   228,   189,
     180,   171,   231,    79,   221,   120,   169,    44,   174,    35,
      22,    44,    92,    75,   184,    80,    44,    23,    36,   103,
      76,    24,    21,   129,   101,   222,   156,    77,    78,   195,
     157,   162,    76,   196,    37,   156,   195,   208,  -113,   198,
     220,   205,    49,    50,   203,   195,   143,   144,   195,   233,
     211,   184,   234,   184,    51,   145,   146,   147,   148,   149,
     150,    76,    52,    48,   104,   105,   106,   107,   108,   109,
      54,   227,   211,   229,   230,   143,   144,    69,   184,    17,
      18,    19,   184,    75,   145,   146,   147,   148,   149,   150,
      76,   143,   144,   122,   123,     1,    96,    97,    67,    74,
     145,   146,   147,   148,   149,   150,    76,    86,    88,    94,
      89,    72,   118,   103,    55,   126,   132,   133,   128,   134,
     135,   136,   137,   141,   142,   153,   160,   154,    60,   144,
     173,   158,   178,   185,   188,   187,   190,   191,   194,   224,
     192,    76,    15,   193,    38,   214,    61,   197,   216,   215,
     226,    39,    53,    31,   232,   166,   206,   223,   131,    85,
     172,   186,   170,     0,   199,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95
};

static const yytype_int16 yycheck[] =
{
      44,    52,    31,    70,    60,   113,    29,    49,     3,     3,
       4,    30,     6,    69,     3,     3,     4,     0,     6,     3,
       4,     3,     6,     3,     3,    81,    68,    52,     3,     4,
      81,     6,    61,    89,    28,     3,     4,     3,     6,    90,
      82,    29,    31,    85,    28,    29,   154,   103,    10,    29,
      79,    80,     8,     9,     3,     4,    50,     6,     3,     4,
      55,     6,    56,     3,     4,     0,     6,    55,    56,   113,
     126,   112,    56,   197,    56,    50,    56,    56,     3,   130,
     188,    56,   190,    28,    16,    17,   128,    55,    56,    40,
      56,    53,     7,    26,    29,   137,    33,   153,   222,   166,
     156,   142,   226,    55,    35,   161,    57,    56,   152,    10,
      25,    56,    69,    57,   158,    67,    56,    32,    31,    53,
      64,    36,     7,    57,    81,    56,    53,    65,    66,    53,
      57,   187,    64,    57,    53,    53,    53,   193,    41,    57,
      57,   192,     3,     3,   188,    53,    49,    50,    53,    57,
     194,   195,    57,   197,     3,    58,    59,    60,    61,    62,
      63,    64,    56,   192,    42,    43,    44,    45,    46,    47,
      54,   222,   216,    20,    21,    49,    50,    18,   222,    22,
      23,    24,   226,    57,    58,    59,    60,    61,    62,    63,
      64,    49,    50,    27,    28,    29,    77,    78,    55,    54,
      58,    59,    60,    61,    62,    63,    64,    11,     3,    57,
      56,     3,    12,    53,     3,    34,    47,    47,    57,    47,
      47,    47,     3,    40,    39,    13,    27,    14,    10,    50,
      41,    56,    15,    53,    58,    53,    48,    51,    13,    19,
      56,    64,     3,    53,    30,    58,    53,    56,    53,    57,
      56,    30,    37,    21,    57,   127,   192,   216,   103,    61,
     143,   161,   141,    -1,   187,   195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    70,    71,    72,    73,    75,    76,    77,    99,
     106,   114,    30,    78,     0,    72,    52,    22,    23,    24,
      74,     7,    25,    32,    36,     3,    79,    80,     8,     9,
      81,    81,    26,    33,   107,    10,    31,    53,    75,    76,
       3,     4,     6,    55,    56,    82,    83,    85,   125,     3,
       3,     3,    56,    80,    54,     3,   122,   123,   124,   125,
      10,    53,    86,     3,    31,    84,    84,    55,   108,    18,
     115,    73,     3,    55,    54,    57,    64,    65,    66,    55,
      67,    56,    85,    87,    88,    83,    11,    90,     3,    56,
     100,    84,    87,    90,    57,   123,   124,   124,   125,   125,
      73,    87,    84,    53,    42,    43,    44,    45,    46,    47,
      89,    84,    50,    56,   116,   117,   118,   122,    12,    91,
      85,   101,    27,    28,    73,   102,    34,   109,    57,    57,
      56,    88,    47,    47,    47,    47,    47,     3,   118,   116,
     122,    40,    39,    49,    50,    58,    59,    60,    61,    62,
      63,   119,   121,    13,    14,    93,    53,    57,    56,   103,
      27,    56,    85,   110,   111,   113,    86,    84,    84,    57,
     117,   118,   119,    41,   122,    85,    92,   116,    15,    94,
      85,    28,   104,   105,   122,    53,   101,    53,    58,    90,
      48,    51,    56,    53,    13,    53,    57,    56,    57,   111,
      28,   112,   116,   122,   116,    73,    82,   120,    85,    95,
      96,   122,   105,   104,    58,    57,    53,    16,    17,    97,
      57,    35,    56,    96,    19,    98,    56,    73,   104,    20,
      21,   104,    57,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    76,    76,    77,    78,    78,
      79,    79,    80,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    97,    97,    97,    98,    98,    98,
      99,   100,   100,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   107,   107,   108,   108,   109,
     110,   110,   111,   111,   111,   111,   112,   112,   112,   113,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   124,
     125,   125,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       4,     1,     1,     1,     9,     1,     0,     3,     1,     0,
       1,     3,     5,     1,     1,     0,     2,     4,     1,     1,
       3,     2,     1,     0,     1,     3,     2,     0,     3,     1,
       3,     2,     4,     6,     4,     2,     2,     2,     2,     2,
       1,     2,     0,     3,     0,     1,     3,     2,     0,     3,
       0,     1,     3,     3,     1,     1,     0,     2,     2,     0,
       7,     3,     0,     1,     3,     2,     2,     1,     3,     5,
       1,     3,     1,     1,     9,     1,     0,     1,     0,     2,
       1,     3,     3,     7,     8,     7,     1,     1,     1,     1,
       6,     2,     0,     1,     3,     1,     3,     3,     2,     3,
       4,     6,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     1
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
#line 82 "parser.y"
    {
    }
#line 1578 "y.tab.c"
    break;

  case 3: /* statement_list: statement  */
#line 88 "parser.y"
    {
    }
#line 1585 "y.tab.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 91 "parser.y"
    {
    }
#line 1592 "y.tab.c"
    break;

  case 5: /* statement: query SEMICOLON  */
#line 97 "parser.y"
    {
        (yyval.node) = create_node(RA_SCOPE,NULL);
        (yyval.node)->left = (yyvsp[-1].node);
        parse_tree[parse_tree_count] = (yyval.node);
        parse_tree_count++;
        printf("\nOriginal Relational Algebra Tree for sql statement %d:\n",parse_tree_count);
        print_tree((yyvsp[-1].node), 0);

        printf("Cost of actual tree: %d\n",cost_estimation((yyvsp[-1].node)));
        
        ASTNode* transformed_both = apply_transformations(deep_copy_tree((yyval.node)));
        printf("\nTree after Transformations:\n");
        print_tree(transformed_both, 0);
        printf("Cost of transformed tree: %d\n",cost_estimation(transformed_both));
    }
#line 1612 "y.tab.c"
    break;

  case 6: /* query: select_stmt  */
#line 116 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1620 "y.tab.c"
    break;

  case 7: /* query: insert_stmt  */
#line 120 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1628 "y.tab.c"
    break;

  case 8: /* query: update_stmt  */
#line 124 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1636 "y.tab.c"
    break;

  case 9: /* query: delete_stmt  */
#line 128 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1644 "y.tab.c"
    break;

  case 10: /* query: select_stmt set_op select_opts select_stmt  */
#line 132 "parser.y"
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
#line 1659 "y.tab.c"
    break;

  case 11: /* set_op: UNION  */
#line 146 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∪");  // Union symbol
    }
#line 1667 "y.tab.c"
    break;

  case 12: /* set_op: INTERSECT  */
#line 150 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "∩");  // Intersection symbol
    }
#line 1675 "y.tab.c"
    break;

  case 13: /* set_op: EXCEPT  */
#line 154 "parser.y"
    {
        (yyval.node) = create_node(RA_SET_OP, "−");  // Minus symbol
    }
#line 1683 "y.tab.c"
    break;

  case 14: /* select_stmt: with_clause_opt SELECT select_opts column_list from_clause where_clause group_clause having_clause order_clause  */
#line 162 "parser.y"
    {
        // Start building the tree from the bottom up
        ASTNode* base_tree = (yyvsp[-4].node);  // FROM clause
        
        // Apply WITH clause
        if ((yyvsp[-8].node) && (yyvsp[-8].node)->type != RA_EMPTY) {
            base_tree->left = (yyvsp[-8].node);
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
            ASTNode* order = create_node(RA_ORDERBY, "");
            order->left = (yyval.node);
            (yyval.node) = order;
        }
        
    }
#line 1747 "y.tab.c"
    break;

  case 15: /* with_clause_opt: with_clause  */
#line 225 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1755 "y.tab.c"
    break;

  case 16: /* with_clause_opt: %empty  */
#line 229 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1763 "y.tab.c"
    break;

  case 17: /* with_clause: WITH recursive_opt with_query_list  */
#line 236 "parser.y"
    {
        (yyval.node) = create_node(RA_WITH, "");
        if (strcmp((yyvsp[-1].node)->value, "RECURSIVE") == 0) {
            strcpy((yyval.node)->value,"RECURSIVE") ; // Mark as recursive
        }
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 1775 "y.tab.c"
    break;

  case 18: /* recursive_opt: RECURSIVE  */
#line 247 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "RECURSIVE");
    }
#line 1783 "y.tab.c"
    break;

  case 19: /* recursive_opt: %empty  */
#line 251 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1791 "y.tab.c"
    break;

  case 20: /* with_query_list: with_query  */
#line 258 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1799 "y.tab.c"
    break;

  case 21: /* with_query_list: with_query_list COMMA with_query  */
#line 262 "parser.y"
    {
        ASTNode* list = create_node(RA_WITH_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 1810 "y.tab.c"
    break;

  case 22: /* with_query: ID AS LPAREN query RPAREN  */
#line 272 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[-4].str));
        (yyval.node)->left = create_node(RA_SCOPE,NULL);
        (yyval.node)->left->left = (yyvsp[-1].node);
    }
#line 1820 "y.tab.c"
    break;

  case 23: /* select_opts: ALL  */
#line 281 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ALL");
    }
#line 1828 "y.tab.c"
    break;

  case 24: /* select_opts: DISTINCT  */
#line 285 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DISTINCT");
    }
#line 1836 "y.tab.c"
    break;

  case 25: /* select_opts: %empty  */
#line 289 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1844 "y.tab.c"
    break;

  case 26: /* column_list: column as_id_opt  */
#line 296 "parser.y"
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
#line 1859 "y.tab.c"
    break;

  case 27: /* column_list: column_list COMMA column as_id_opt  */
#line 307 "parser.y"
    {
        ASTNode* col;
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle column alias
            col = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            col->args = (yyvsp[-1].node);
        } else {
            col = (yyvsp[-1].node);
        }
        (yyval.node) = (yyvsp[-3].node);
        (yyval.node)->left=col;
    }
#line 1876 "y.tab.c"
    break;

  case 28: /* column_list: ASTERISK  */
#line 320 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 1884 "y.tab.c"
    break;

  case 29: /* column: term  */
#line 327 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1892 "y.tab.c"
    break;

  case 30: /* column: ID DOT ASTERISK  */
#line 331 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.*", (yyvsp[-2].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 1902 "y.tab.c"
    break;

  case 31: /* as_id_opt: AS ID  */
#line 340 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 1910 "y.tab.c"
    break;

  case 32: /* as_id_opt: ID  */
#line 344 "parser.y"
    {
        (yyval.node) = create_node(RA_ALIAS, (yyvsp[0].str));
    }
#line 1918 "y.tab.c"
    break;

  case 33: /* as_id_opt: %empty  */
#line 348 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1926 "y.tab.c"
    break;

  case 34: /* modified_id: ID  */
#line 355 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, (yyvsp[0].str));
    }
#line 1934 "y.tab.c"
    break;

  case 35: /* modified_id: ID DOT ID  */
#line 359 "parser.y"
    {
        char value[MAX_STRING_LENGTH];
        snprintf(value, sizeof(value), "%s.%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.node) = create_node(RA_ATTRIBUTE, value);
    }
#line 1944 "y.tab.c"
    break;

  case 36: /* from_clause: FROM from_item_list  */
#line 368 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1952 "y.tab.c"
    break;

  case 37: /* from_clause: %empty  */
#line 372 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 1960 "y.tab.c"
    break;

  case 38: /* from_item_list: LPAREN from_item_list RPAREN  */
#line 379 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1968 "y.tab.c"
    break;

  case 39: /* from_item_list: from_item  */
#line 383 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1976 "y.tab.c"
    break;

  case 40: /* from_item_list: from_item_list COMMA from_item  */
#line 387 "parser.y"
    {
        ASTNode* cross_join = create_node(RA_CROSS_JOIN, "×");  // Cross product
        cross_join->left = (yyvsp[-2].node);
        cross_join->right = (yyvsp[0].node);
        (yyval.node) = cross_join;
    }
#line 1987 "y.tab.c"
    break;

  case 41: /* from_item: modified_id as_id_opt  */
#line 397 "parser.y"
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
#line 2002 "y.tab.c"
    break;

  case 42: /* from_item: LPAREN query RPAREN as_id_opt  */
#line 408 "parser.y"
    {
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            // Handle table alias
            ASTNode* alias = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            alias->left = create_node(RA_SCOPE, NULL);
            alias->left->left = (yyvsp[-2].node);
            (yyval.node) = alias;
        } else {
            (yyval.node) = create_node(RA_SCOPE, NULL);
            (yyval.node)->left = (yyvsp[-2].node);
        }
    }
#line 2019 "y.tab.c"
    break;

  case 43: /* from_item: from_item join_type ID as_id_opt ON expression  */
#line 421 "parser.y"
    {
        ASTNode* right_relation;
        if ((yyvsp[-2].node)->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, (yyvsp[-2].node)->value);
            right_relation->left = create_node(RA_RELATION, (yyvsp[-3].str));
        } else {
            right_relation = create_node(RA_RELATION, (yyvsp[-3].str));
        }
        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-4].node)->value);
        join->left = (yyvsp[-5].node);
        join->right = right_relation;
        
        // Add join condition
        join->condition = (yyvsp[0].node);
        
        (yyval.node) = join;
    }
#line 2042 "y.tab.c"
    break;

  case 44: /* from_item: from_item join_type ID as_id_opt  */
#line 440 "parser.y"
    {
        ASTNode* right_relation;
        if ((yyvsp[0].node)->type != RA_EMPTY) {
            right_relation = create_node(RA_ALIAS, (yyvsp[0].node)->value);
            right_relation->left = create_node(RA_RELATION, (yyvsp[-1].str));
        } else {
            right_relation = create_node(RA_RELATION, (yyvsp[-1].str));
        }
        
        ASTNode* join = create_node(RA_JOIN, (yyvsp[-2].node)->value);
        join->left = (yyvsp[-3].node);
        join->right = right_relation;
        
        (yyval.node) = join;
    }
#line 2062 "y.tab.c"
    break;

  case 45: /* join_type: INNER JOIN  */
#line 459 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Natural join symbol
    }
#line 2070 "y.tab.c"
    break;

  case 46: /* join_type: LEFT JOIN  */
#line 463 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟕");  // Left join symbol
    }
#line 2078 "y.tab.c"
    break;

  case 47: /* join_type: RIGHT JOIN  */
#line 467 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟖");  // Right join symbol
    }
#line 2086 "y.tab.c"
    break;

  case 48: /* join_type: FULL JOIN  */
#line 471 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⟗");  // Full join symbol
    }
#line 2094 "y.tab.c"
    break;

  case 49: /* join_type: CROSS JOIN  */
#line 475 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "×");  // Cross join symbol
    }
#line 2102 "y.tab.c"
    break;

  case 50: /* join_type: JOIN  */
#line 479 "parser.y"
    {
        (yyval.node) = create_node(RA_JOIN_TYPE, "⋈");  // Natural join symbol
    }
#line 2110 "y.tab.c"
    break;

  case 51: /* where_clause: WHERE expression  */
#line 486 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "WHERE");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2119 "y.tab.c"
    break;

  case 52: /* where_clause: %empty  */
#line 491 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2127 "y.tab.c"
    break;

  case 53: /* group_clause: GROUP BY group_item_list  */
#line 498 "parser.y"
    {
        (yyval.node) = create_node(RA_GROUPBY, "GROUP BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2136 "y.tab.c"
    break;

  case 54: /* group_clause: %empty  */
#line 503 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2144 "y.tab.c"
    break;

  case 55: /* group_item_list: modified_id  */
#line 510 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2152 "y.tab.c"
    break;

  case 56: /* group_item_list: group_item_list COMMA modified_id  */
#line 514 "parser.y"
    {
        ASTNode* list = create_node(RA_GROUP_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2163 "y.tab.c"
    break;

  case 57: /* having_clause: HAVING expression  */
#line 524 "parser.y"
    {
        (yyval.node) = create_node(RA_SELECTION, "HAVING");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2172 "y.tab.c"
    break;

  case 58: /* having_clause: %empty  */
#line 529 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2180 "y.tab.c"
    break;

  case 59: /* order_clause: ORDER BY order_item_list  */
#line 536 "parser.y"
    {
        (yyval.node) = create_node(RA_ORDERBY, "ORDER BY");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2189 "y.tab.c"
    break;

  case 60: /* order_clause: %empty  */
#line 541 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2197 "y.tab.c"
    break;

  case 61: /* order_item_list: order_item  */
#line 548 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2205 "y.tab.c"
    break;

  case 62: /* order_item_list: order_item_list COMMA order_item  */
#line 552 "parser.y"
    {
        ASTNode* list = create_node(RA_ORDER_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2216 "y.tab.c"
    break;

  case 63: /* order_item: operand order_option nulls_option  */
#line 562 "parser.y"
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
#line 2238 "y.tab.c"
    break;

  case 64: /* order_option: ASC  */
#line 583 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ASC");
    }
#line 2246 "y.tab.c"
    break;

  case 65: /* order_option: DESC  */
#line 587 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DESC");
    }
#line 2254 "y.tab.c"
    break;

  case 66: /* order_option: %empty  */
#line 591 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2262 "y.tab.c"
    break;

  case 67: /* nulls_option: NULLS FIRST  */
#line 598 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS FIRST");
    }
#line 2270 "y.tab.c"
    break;

  case 68: /* nulls_option: NULLS LAST  */
#line 602 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NULLS LAST");
    }
#line 2278 "y.tab.c"
    break;

  case 69: /* nulls_option: %empty  */
#line 606 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2286 "y.tab.c"
    break;

  case 70: /* insert_stmt: with_clause_opt INSERT INTO ID as_id_opt column_list_opt insert_values  */
#line 614 "parser.y"
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
#line 2315 "y.tab.c"
    break;

  case 71: /* column_list_opt: LPAREN column_name_list RPAREN  */
#line 642 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2323 "y.tab.c"
    break;

  case 72: /* column_list_opt: %empty  */
#line 646 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2331 "y.tab.c"
    break;

  case 73: /* column_name_list: modified_id  */
#line 653 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2339 "y.tab.c"
    break;

  case 74: /* column_name_list: column_name_list COMMA modified_id  */
#line 657 "parser.y"
    {
        ASTNode* list = create_node(RA_COLUMN_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2350 "y.tab.c"
    break;

  case 75: /* insert_values: DEFAULT VALUES  */
#line 667 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "DEFAULT");
    }
#line 2358 "y.tab.c"
    break;

  case 76: /* insert_values: VALUES insert_value_list  */
#line 671 "parser.y"
    {
        (yyval.node) = create_node(RA_VALUES, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2367 "y.tab.c"
    break;

  case 77: /* insert_values: query  */
#line 676 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);  // Subquery
    }
#line 2375 "y.tab.c"
    break;

  case 78: /* insert_value_list: LPAREN insert_value_items RPAREN  */
#line 683 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2383 "y.tab.c"
    break;

  case 79: /* insert_value_list: insert_value_list COMMA LPAREN insert_value_items RPAREN  */
#line 687 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_LIST, "");
        list->left = (yyvsp[-4].node);
        list->right = (yyvsp[-1].node);
        (yyval.node) = list;
    }
#line 2394 "y.tab.c"
    break;

  case 80: /* insert_value_items: insert_value  */
#line 697 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2402 "y.tab.c"
    break;

  case 81: /* insert_value_items: insert_value_items COMMA insert_value  */
#line 701 "parser.y"
    {
        ASTNode* list = create_node(RA_VALUE_ITEMS, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2413 "y.tab.c"
    break;

  case 82: /* insert_value: operand  */
#line 711 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2421 "y.tab.c"
    break;

  case 83: /* insert_value: DEFAULT  */
#line 715 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2429 "y.tab.c"
    break;

  case 84: /* update_stmt: with_clause_opt UPDATE only_opt ID asterisk_opt as_id_opt set_clause from_clause where_clause  */
#line 723 "parser.y"
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
#line 2466 "y.tab.c"
    break;

  case 85: /* only_opt: ONLY  */
#line 759 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "ONLY");
    }
#line 2474 "y.tab.c"
    break;

  case 86: /* only_opt: %empty  */
#line 763 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2482 "y.tab.c"
    break;

  case 87: /* asterisk_opt: ASTERISK  */
#line 770 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "*");
    }
#line 2490 "y.tab.c"
    break;

  case 88: /* asterisk_opt: %empty  */
#line 774 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2498 "y.tab.c"
    break;

  case 89: /* set_clause: SET set_item_list  */
#line 781 "parser.y"
    {
        (yyval.node) = create_node(RA_SET, "");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2507 "y.tab.c"
    break;

  case 90: /* set_item_list: set_item  */
#line 789 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2515 "y.tab.c"
    break;

  case 91: /* set_item_list: set_item_list COMMA set_item  */
#line 793 "parser.y"
    {
        ASTNode* list = create_node(RA_SET_LIST, "");
        list->left = (yyvsp[-2].node);
        list->right = (yyvsp[0].node);
        (yyval.node) = list;
    }
#line 2526 "y.tab.c"
    break;

  case 92: /* set_item: column_name EQ set_value  */
#line 803 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-2].node);
        assignment->right = (yyvsp[0].node);
        (yyval.node) = assignment;
    }
#line 2537 "y.tab.c"
    break;

  case 93: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN insert_value_items RPAREN  */
#line 810 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2548 "y.tab.c"
    break;

  case 94: /* set_item: LPAREN column_name_list RPAREN EQ ROW LPAREN insert_value_items RPAREN  */
#line 817 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "= ROW");
        assignment->left = (yyvsp[-6].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2559 "y.tab.c"
    break;

  case 95: /* set_item: LPAREN column_name_list RPAREN EQ LPAREN query RPAREN  */
#line 824 "parser.y"
    {
        ASTNode* assignment = create_node(RA_ASSIGNMENT, "=");
        assignment->left = (yyvsp[-5].node);
        assignment->right = (yyvsp[-1].node);
        (yyval.node) = assignment;
    }
#line 2570 "y.tab.c"
    break;

  case 96: /* set_value: operand  */
#line 834 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2578 "y.tab.c"
    break;

  case 97: /* set_value: expression  */
#line 838 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2586 "y.tab.c"
    break;

  case 98: /* set_value: DEFAULT  */
#line 842 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "DEFAULT");
    }
#line 2594 "y.tab.c"
    break;

  case 99: /* column_name: modified_id  */
#line 849 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2602 "y.tab.c"
    break;

  case 100: /* delete_stmt: with_clause_opt DELETE FROM ID using_clause_opt where_clause  */
#line 857 "parser.y"
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
#line 2629 "y.tab.c"
    break;

  case 101: /* using_clause_opt: USING from_item_list  */
#line 883 "parser.y"
    {
        (yyval.node) = create_node(RA_USING, "");
        (yyval.node)->args = (yyvsp[0].node);
    }
#line 2638 "y.tab.c"
    break;

  case 102: /* using_clause_opt: %empty  */
#line 888 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2646 "y.tab.c"
    break;

  case 103: /* expression: and_condition  */
#line 896 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2654 "y.tab.c"
    break;

  case 104: /* expression: expression OR and_condition  */
#line 900 "parser.y"
    {
        ASTNode* or_node = create_node(RA_OR, "OR");
        or_node->left = (yyvsp[-2].node);
        or_node->right = (yyvsp[0].node);
        (yyval.node) = or_node;
    }
#line 2665 "y.tab.c"
    break;

  case 105: /* and_condition: condition  */
#line 910 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2673 "y.tab.c"
    break;

  case 106: /* and_condition: and_condition AND condition  */
#line 914 "parser.y"
    {
        ASTNode* and_node = create_node(RA_AND, "AND");
        and_node->left = (yyvsp[-2].node);
        and_node->right = (yyvsp[0].node);
        (yyval.node) = and_node;
    }
#line 2684 "y.tab.c"
    break;

  case 107: /* condition: LPAREN expression RPAREN  */
#line 924 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2692 "y.tab.c"
    break;

  case 108: /* condition: NOT condition  */
#line 928 "parser.y"
    {
        ASTNode* not_node = create_node(RA_NOT, "NOT");
        not_node->left = (yyvsp[0].node);
        (yyval.node) = not_node;
    }
#line 2702 "y.tab.c"
    break;

  case 109: /* condition: operand comparison_op operand  */
#line 934 "parser.y"
    {
        ASTNode* comp = create_node(RA_COMPARISON, (yyvsp[-1].node)->value);
        comp->left = (yyvsp[-2].node);
        comp->right = (yyvsp[0].node);
        (yyval.node) = comp;
    }
#line 2713 "y.tab.c"
    break;

  case 110: /* condition: operand IS not_opt NULL_VAL  */
#line 941 "parser.y"
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
#line 2730 "y.tab.c"
    break;

  case 111: /* condition: operand not_opt IN LPAREN in_items RPAREN  */
#line 960 "parser.y"
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
#line 2748 "y.tab.c"
    break;

  case 112: /* not_opt: NOT  */
#line 996 "parser.y"
    {
        (yyval.node) = create_node(RA_ATTRIBUTE, "NOT");
    }
#line 2756 "y.tab.c"
    break;

  case 113: /* not_opt: %empty  */
#line 1000 "parser.y"
    {
        (yyval.node) = create_node(RA_EMPTY, "");
    }
#line 2764 "y.tab.c"
    break;

  case 114: /* in_items: column_list  */
#line 1007 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2772 "y.tab.c"
    break;

  case 115: /* in_items: query  */
#line 1011 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2780 "y.tab.c"
    break;

  case 116: /* comparison_op: EQ  */
#line 1018 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "=");
    }
#line 2788 "y.tab.c"
    break;

  case 117: /* comparison_op: NE  */
#line 1022 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<>");
    }
#line 2796 "y.tab.c"
    break;

  case 118: /* comparison_op: LT  */
#line 1026 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<");
    }
#line 2804 "y.tab.c"
    break;

  case 119: /* comparison_op: GT  */
#line 1030 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">");
    }
#line 2812 "y.tab.c"
    break;

  case 120: /* comparison_op: LE  */
#line 1034 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, "<=");
    }
#line 2820 "y.tab.c"
    break;

  case 121: /* comparison_op: GE  */
#line 1038 "parser.y"
    {
        (yyval.node) = create_node(RA_OPERATOR, ">=");
    }
#line 2828 "y.tab.c"
    break;

  case 122: /* operand: summand  */
#line 1045 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2836 "y.tab.c"
    break;

  case 123: /* operand: operand CONCAT summand  */
#line 1049 "parser.y"
    {
        ASTNode* concat = create_node(RA_CONCAT, "||");
        concat->left = (yyvsp[-2].node);
        concat->right = (yyvsp[0].node);
        (yyval.node) = concat;
    }
#line 2847 "y.tab.c"
    break;

  case 124: /* summand: factor  */
#line 1059 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2855 "y.tab.c"
    break;

  case 125: /* summand: summand PLUS factor  */
#line 1063 "parser.y"
    {
        ASTNode* add = create_node(RA_ARITHMETIC, "+");
        add->left = (yyvsp[-2].node);
        add->right = (yyvsp[0].node);
        (yyval.node) = add;
    }
#line 2866 "y.tab.c"
    break;

  case 126: /* summand: summand MINUS factor  */
#line 1070 "parser.y"
    {
        ASTNode* subtract = create_node(RA_ARITHMETIC, "-");
        subtract->left = (yyvsp[-2].node);
        subtract->right = (yyvsp[0].node);
        (yyval.node) = subtract;
    }
#line 2877 "y.tab.c"
    break;

  case 127: /* factor: term  */
#line 1080 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2885 "y.tab.c"
    break;

  case 128: /* factor: factor ASTERISK term  */
#line 1084 "parser.y"
    {
        ASTNode* multiply = create_node(RA_ARITHMETIC, "*");
        multiply->left = (yyvsp[-2].node);
        multiply->right = (yyvsp[0].node);
        (yyval.node) = multiply;
    }
#line 2896 "y.tab.c"
    break;

  case 129: /* factor: factor DIV term  */
#line 1091 "parser.y"
    {
        ASTNode* divide = create_node(RA_ARITHMETIC, "/");
        divide->left = (yyvsp[-2].node);
        divide->right = (yyvsp[0].node);
        (yyval.node) = divide;
    }
#line 2907 "y.tab.c"
    break;

  case 130: /* term: LPAREN operand RPAREN  */
#line 1101 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2915 "y.tab.c"
    break;

  case 131: /* term: modified_id  */
#line 1105 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2923 "y.tab.c"
    break;

  case 132: /* term: NUM  */
#line 1109 "parser.y"
    {
        char value[32];
        snprintf(value, sizeof(value), "%d", (yyvsp[0].num));
        (yyval.node) = create_node(RA_LITERAL, value);
    }
#line 2933 "y.tab.c"
    break;

  case 133: /* term: STRING_LITERAL  */
#line 1115 "parser.y"
    {
        (yyval.node) = create_node(RA_LITERAL, (yyvsp[0].str));
    }
#line 2941 "y.tab.c"
    break;


#line 2945 "y.tab.c"

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

#line 1120 "parser.y"




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
        case RA_RELATION:
        case RA_ALIAS: {
            const char* table_name = NULL;
            const char* alias = NULL;

            if (node->type == RA_ALIAS && node->left) {
                table_name = node->left->value;
                alias = node->value;
            } else {
                table_name = alias = node->value;
            }

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

        case RA_PROJECTION: {
            scope_attr* base_scope = build_scope(node->left); // 🔑 get full alias→table mapping

            scope_attr* head = NULL;
            scope_attr* tail = NULL;

            for (ASTNode* curr = node->args; curr; curr = curr->args) {
                if (curr->type == RA_ATTRIBUTE) {
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

                    // 🧠 Try to find the matching attribute in base scope
                    TABLE* matched_table = NULL;
                    for (scope_attr* s = base_scope; s; s = s->next) {
                        if ((strcmp(alias_buf, "") == 0 || strcmp(s->alias, alias_buf) == 0) &&
                            strcmp(s->name, name_buf) == 0) {
                            matched_table = s->tablename;
                            break;
                        }
                    }

                    scope_attr* sa = (scope_attr*)malloc(sizeof(scope_attr));
                    sa->alias = strdup(alias_buf);
                    sa->name = strdup(name_buf);
                    sa->tablename = matched_table; // ✅ copied from matched scope
                    sa->next = NULL;

                    if (!head) head = tail = sa;
                    else { tail->next = sa; tail = sa; }
                }
            }

            free_scope(base_scope); // clean up base scope after using
            return head;
        }


        case RA_SELECTION:
        case RA_DISTINCT:
        case RA_GROUPBY:
        case RA_ORDERBY:
            return build_scope(node->left);

        case RA_JOIN:
        case RA_CROSS_JOIN: {
            scope_attr* left = build_scope(node->left);
            scope_attr* right = build_scope(node->right);
            return merge_scopes(left, right);
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

int attribute_in_list(ASTNode* list, const char* attr) {
    for (ASTNode* curr = list; curr; curr = curr->args) {
        if (strcmp(curr->value, attr) == 0)
            return 1;
    }
    return 0;
}

ASTNode* merge_attribute_lists(ASTNode* list1, ASTNode* list2) {
    ASTNode* merged = NULL;
    ASTNode* tail = NULL;

    for (ASTNode* curr = list1; curr; curr = curr->args) {
        ASTNode* node = deep_copy_tree(curr);
        node->args = NULL;
        if (!merged) merged = tail = node;
        else { tail->args = node; tail = node; }
    }

    for (ASTNode* curr = list2; curr; curr = curr->args) {
        if (!attribute_in_list(merged, curr->value)) {
            ASTNode* node = deep_copy_tree(curr);
            node->args = NULL;
            if (!merged) merged = tail = node;
            else { tail->args = node; tail = node; }
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

        result = merge_attribute_lists(left_attrs, right_attrs);
        result = merge_attribute_lists(result, cond_attrs);
        result = merge_attribute_lists(result, args_attrs);
    }

    return result;
}


ASTNode *projection_pushdown(ASTNode *node) {
    if (!node) return NULL;

    node->left = projection_pushdown(node->left);
    node->right = projection_pushdown(node->right);
    node->args = projection_pushdown(node->args);
    node->condition = projection_pushdown(node->condition);
    node->from = projection_pushdown(node->from);

    // Case: π → σ
    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_SELECTION) {
        ASTNode *select_node = node->left;

        // Step 1: Extract attributes used in the selection condition
        ASTNode *cond_attrs = extract_attributes_from_conditions(select_node->args);

        // Step 2: Merge selection condition attributes + original projection args
        ASTNode *merged_attrs = merge_attribute_lists(node->args, cond_attrs);

        // Step 3: Create new projection node below selection with merged attributes
        ASTNode *new_proj = create_node(RA_PROJECTION, "");
        new_proj->args = merged_attrs;
        new_proj->left = select_node->left;

        // Step 4: Replace selection's child with new projection
        select_node->left = new_proj;
        free_tree(cond_attrs);

        // Recurse downward to handle inner cases (π under joins etc.)
        return projection_pushdown(select_node);
    }

    // Case: π → JOIN
    // Case: π → JOIN
    if (node->type == RA_PROJECTION && node->left && node->left->type == RA_JOIN) {
        ASTNode *join_node = node->left;

        ASTNode *proj_attrs = node->args;
        ASTNode *cond_attrs = extract_attributes_from_conditions(join_node->condition);
        ASTNode *combined_attrs = merge_attribute_lists(proj_attrs, cond_attrs);

        scope_attr *left_scope = build_scope(join_node->left);
        if (!left_scope) printf("Left scope is NULL\n");
        scope_attr *right_scope = build_scope(join_node->right);
        if (!right_scope) printf("Right scope is NULL\n");

        ASTNode *left_proj_attrs = NULL;
        ASTNode *right_proj_attrs = NULL;
        ASTNode *tail_left = NULL, *tail_right = NULL;

        for (ASTNode *curr = combined_attrs; curr; curr = curr->args) {
            char *attr_full = curr->value;
            char *dot = strchr(attr_full, '.');
            char alias[256], attr[256];

            if (dot) {
                int len = dot - attr_full;
                strncpy(alias, attr_full, len); alias[len] = '\0';
                strcpy(attr, dot + 1);
            } else {
                strcpy(alias, "");
                strcpy(attr, attr_full);
            }

            int found_in_left = 0, found_in_right = 0;

            for (scope_attr *s = left_scope; s; s = s->next) {
                if (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr) == 0) {
                    found_in_left = 1;
                    break;
                }
            }

            for (scope_attr *s = right_scope; s; s = s->next) {
                if (strcmp(s->alias, alias) == 0 && strcmp(s->name, attr) == 0) {
                    found_in_right = 1;
                    break;
                }
            }
            

            ASTNode *copy = deep_copy_tree(curr);
            copy->args = NULL;

            if (found_in_left && !found_in_right) {
                if (!left_proj_attrs) left_proj_attrs = tail_left = copy;
                else { tail_left->args = copy; tail_left = copy; }
            } else if (found_in_right && !found_in_left) {
                if (!right_proj_attrs) right_proj_attrs = tail_right = copy;
                else { tail_right->args = copy; tail_right = copy; }
            }
        }

        // Step 6: Push down to left
        if (left_proj_attrs) {
            ASTNode *left_proj_node = create_node(RA_PROJECTION, "");
            left_proj_node->args = left_proj_attrs;
            left_proj_node->left = join_node->left;
            join_node->left = left_proj_node;
        }

        // Step 7: Push down to right
        if (right_proj_attrs) {
            ASTNode *right_proj_node = create_node(RA_PROJECTION, "");
            right_proj_node->args = right_proj_attrs;
            right_proj_node->left = join_node->right;
            join_node->right = right_proj_node;
        }

        // Step 8: Check if all projection attributes have been pushed
        int all_attrs_pushed = 1;
        for (ASTNode *curr = proj_attrs; curr; curr = curr->args) {
            if (!attribute_in_list(left_proj_attrs, curr->value) &&
                !attribute_in_list(right_proj_attrs, curr->value)) {
                all_attrs_pushed = 0;
                break;
            }
        }

        free_scope(left_scope);
        free_scope(right_scope);
        free_tree(combined_attrs);

        if (all_attrs_pushed) {
            return join_node;
        } else {
            node->left = join_node;
            return node;
        }
    }

    return node;
}

ASTNode* apply_transformations(ASTNode* node) {
    if (!node) return NULL;
    int changed;
    do {
        changed = 0;
        ASTNode* original = deep_copy_tree(node);
        //ASTNode* after_selection = selection_pushdown(node);
        //if (after_selection != node) {
            //node = after_selection;
            //changed = 1;
        //}

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


ASTNode* extract_attributes(ASTNode* attr_list, ASTNode* relation) {
    if (!attr_list || !relation) return NULL;

    const char* alias = relation->value;
    ASTNode* result = NULL;
    ASTNode* last = NULL;

    for (ASTNode* curr = attr_list; curr; curr = curr->args) {
        if (curr->type == RA_ATTRIBUTE) {
            char* dot = strchr(curr->value, '.');

            int include = 0;

            if (dot) {
                // Qualified attribute: alias.attr
                char prefix[256];
                strncpy(prefix, curr->value, dot - curr->value);
                prefix[dot - curr->value] = '\0';

                // Match alias (or table name if you track it)
                if (strcmp(prefix, alias) == 0) {
                    include = 1;
                }
            } else {
                // Unqualified attribute: attr
                // Include just to be safe (or enhance this with schema-based resolution)
                include = 1;
            }

            if (include) {
                ASTNode* new_attr = deep_copy_tree(curr);
                new_attr->args = NULL;

                if (!result) {
                    result = last = new_attr;
                } else {
                    last->args = new_attr;
                    last = new_attr;
                }
            }
        }
    }

    return result;
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
