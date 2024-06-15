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
#line 1 "mini.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tac.h"
#include "obj.h"

int yylex();
void yyerror(char* msg);


#line 83 "y.tab.c"

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
    INT = 258,                     /* INT  */
    CHAR = 259,                    /* CHAR  */
    EQ = 260,                      /* EQ  */
    NE = 261,                      /* NE  */
    LT = 262,                      /* LT  */
    LE = 263,                      /* LE  */
    GT = 264,                      /* GT  */
    GE = 265,                      /* GE  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    NOT = 268,                     /* NOT  */
    UMINUS = 269,                  /* UMINUS  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    FI = 273,                      /* FI  */
    WHILE = 274,                   /* WHILE  */
    FOR = 275,                     /* FOR  */
    DO = 276,                      /* DO  */
    DONE = 277,                    /* DONE  */
    CONTINUE = 278,                /* CONTINUE  */
    FUNC = 279,                    /* FUNC  */
    PRINT = 280,                   /* PRINT  */
    RETURN = 281,                  /* RETURN  */
    INTEGER = 282,                 /* INTEGER  */
    IDENTIFIER = 283,              /* IDENTIFIER  */
    TEXT = 284,                    /* TEXT  */
    CHARTEXT = 285                 /* CHARTEXT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define CHAR 259
#define EQ 260
#define NE 261
#define LT 262
#define LE 263
#define GT 264
#define GE 265
#define AND 266
#define OR 267
#define NOT 268
#define UMINUS 269
#define IF 270
#define THEN 271
#define ELSE 272
#define FI 273
#define WHILE 274
#define FOR 275
#define DO 276
#define DONE 277
#define CONTINUE 278
#define FUNC 279
#define PRINT 280
#define RETURN 281
#define INTEGER 282
#define IDENTIFIER 283
#define TEXT 284
#define CHARTEXT 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "mini.y"

	char character;
	char *string;
	SYM *sym;
	TAC *tac;
	EXP	*exp;

#line 204 "y.tab.c"

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
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_EQ = 5,                         /* EQ  */
  YYSYMBOL_NE = 6,                         /* NE  */
  YYSYMBOL_LT = 7,                         /* LT  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GT = 9,                         /* GT  */
  YYSYMBOL_GE = 10,                        /* GE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_NOT = 13,                       /* NOT  */
  YYSYMBOL_UMINUS = 14,                    /* UMINUS  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FI = 18,                        /* FI  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_DONE = 22,                      /* DONE  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_FUNC = 24,                      /* FUNC  */
  YYSYMBOL_PRINT = 25,                     /* PRINT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 28,                /* IDENTIFIER  */
  YYSYMBOL_TEXT = 29,                      /* TEXT  */
  YYSYMBOL_CHARTEXT = 30,                  /* CHARTEXT  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '-'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_function_declaration_list = 47, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 48,      /* function_declaration  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_variable_list = 50,             /* variable_list  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_function_head = 52,             /* function_head  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_declaration_list = 56,          /* declaration_list  */
  YYSYMBOL_statement_list = 57,            /* statement_list  */
  YYSYMBOL_assignment_statement = 58,      /* assignment_statement  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_expression_list = 61,           /* expression_list  */
  YYSYMBOL_print_statement = 62,           /* print_statement  */
  YYSYMBOL_print_list = 63,                /* print_list  */
  YYSYMBOL_print_item = 64,                /* print_item  */
  YYSYMBOL_return_statement = 65,          /* return_statement  */
  YYSYMBOL_null_statement = 66,            /* null_statement  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_while_statement = 68,           /* while_statement  */
  YYSYMBOL_for_statement = 69,             /* for_statement  */
  YYSYMBOL_call_statement = 70,            /* call_statement  */
  YYSYMBOL_call_expression = 71            /* call_expression  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   281

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,     2,    44,     2,
      39,    40,    33,    31,    38,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    37,    37,    44,    45,    51,    52,    55,    59,    63,
      67,    74,    78,    82,    86,    92,    98,   105,   113,   117,
     122,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   143,   150,   153,   159,   160,   166,   170,   174,   178,
     184,   188,   192,   196,   200,   204,   208,   212,   216,   220,
     224,   228,   232,   236,   240,   244,   248,   252,   256,   260,
     264,   268,   272,   276,   280,   288,   291,   294,   295,   302,
     308,   309,   315,   320,   326,   334,   340,   344,   350,   356,
     364,   370
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "CHAR", "EQ",
  "NE", "LT", "LE", "GT", "GE", "AND", "OR", "NOT", "UMINUS", "IF", "THEN",
  "ELSE", "FI", "WHILE", "FOR", "DO", "DONE", "CONTINUE", "FUNC", "PRINT",
  "RETURN", "INTEGER", "IDENTIFIER", "TEXT", "CHARTEXT", "'+'", "'-'",
  "'*'", "'/'", "';'", "'['", "']'", "','", "'('", "')'", "'{'", "'}'",
  "'='", "'&'", "$accept", "program", "function_declaration_list",
  "function_declaration", "declaration", "variable_list", "function",
  "function_head", "parameter_list", "statement", "block",
  "declaration_list", "statement_list", "assignment_statement",
  "expression", "argument_list", "expression_list", "print_statement",
  "print_list", "print_item", "return_statement", "null_statement",
  "if_statement", "while_statement", "for_statement", "call_statement",
  "call_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,   -64,    -3,    -1,   -64,    13,     3,   -64,   -64,   -64,
     -24,    -7,    22,    45,    16,    49,   -64,   -64,    44,    76,
     -64,   -64,     7,    81,   -64,   -64,    66,    72,   -64,    58,
      73,    83,    84,    78,   -64,    79,   -64,   -64,   -64,   -64,
     -64,   146,   -64,    85,    87,    89,   -64,    90,    46,   -25,
     -20,   -64,   -64,   -64,   118,    96,    99,   100,   101,   -64,
     -64,   -64,   105,    46,    46,    23,    88,   -64,    46,   -64,
      52,   -64,   -64,    46,   -19,    46,    94,   247,   -64,   115,
       9,    46,   102,   120,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   183,   193,   -31,   117,   -64,   247,    67,   -64,    65,
     126,     9,   -64,   -64,   127,   229,   -64,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,   119,
     247,   114,   124,   247,    46,   132,    84,    84,    46,    88,
     -64,   121,   128,   133,   -64,    12,    12,    12,    12,    12,
      12,    65,    65,    59,    59,   -64,   -64,   130,   -64,    46,
     247,   140,   153,   -64,   239,   -64,   -64,   -64,   148,    46,
     247,   136,    84,    23,   137,   247,   135,   -64,   141,   -64,
      46,    84,   247,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,     0,     0,    17,     0,     0,     3,     6,     5,
       0,    11,     0,     0,    11,     0,     1,     4,    20,     0,
      13,     7,     0,     0,     8,    18,     0,     0,    12,     0,
       0,     0,     0,     0,    14,     0,    19,    32,    15,     9,
      10,     0,    30,     0,     0,     0,    75,     0,     0,     0,
       0,    33,    34,    29,     0,     0,     0,     0,     0,    26,
      27,    28,     0,     0,     0,     0,     0,    64,     0,    58,
      61,    59,    62,     0,     0,     0,     0,    74,    63,     0,
       0,     0,     0,     0,    31,    35,    21,    24,    23,    25,
      22,     0,     0,     0,     0,    59,    72,     0,    70,    45,
       0,     0,    44,    56,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,    66,    36,     0,     0,     0,     0,     0,     0,
      69,     0,     0,     0,    54,    48,    49,    50,    51,    52,
      53,    46,    47,    40,    41,    42,    43,     0,    80,     0,
      38,     0,    76,    78,     0,    71,    60,    81,     0,     0,
      68,     0,     0,     0,     0,    37,     0,    77,     0,    57,
       0,     0,    39,    79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -64,   -64,   151,   139,   179,   -64,   -64,   -64,   129,
     -32,   -64,   -64,   -63,   -47,    95,   -64,   -64,   -64,    55,
     -64,   -64,   -64,   -64,   -64,   -64,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    13,     9,    10,    26,    52,
      53,    41,    54,    55,    96,   121,   122,    56,    97,    98,
      57,    58,    59,    60,    61,    62,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    77,    94,    -2,     1,    79,     2,     3,    82,   103,
      67,    79,    81,    16,    80,    18,    91,    92,    81,    83,
     104,    99,    68,   113,   114,    11,   102,    14,   105,    19,
      12,     4,    12,   120,   123,    28,    69,    70,    71,    72,
      29,    73,    74,   115,   116,   117,   118,    67,    75,   -65,
      20,    93,    23,    76,   120,     1,    50,     2,     3,    68,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    25,    69,    70,    71,    72,   150,    73,    74,
      21,   154,     4,    22,    24,    75,    34,    22,   100,    67,
      76,   101,   117,   118,   152,   153,   115,   116,   117,   118,
     168,    68,   160,    27,    31,   129,    32,   130,    30,    33,
      35,    36,   165,    39,    40,    69,    70,    95,    72,    42,
      73,    74,   106,   172,    63,    37,    64,    75,    65,    66,
     167,    86,    76,    43,    87,    88,    89,    44,    45,   173,
      90,    46,   119,    47,    48,   124,    49,    42,   125,     2,
       3,    50,   128,   131,   148,   133,   147,    17,   156,    37,
      84,    43,   149,   151,   158,    44,    45,   161,   157,    46,
     162,    47,    48,   159,    49,   164,   166,   169,   170,    50,
      51,   171,    15,    85,   155,     0,     0,    37,   107,   108,
     109,   110,   111,   112,   113,   114,   132,     0,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,     0,     0,
       0,     0,     0,   126,   115,   116,   117,   118,     0,     0,
       0,     0,     0,   127,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,   107,   108,   109,   110,   111,   112,
     113,   114,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,   134,
     115,   116,   117,   118,   163,     0,     0,     0,   115,   116,
     117,   118
};

static const yytype_int16 yycheck[] =
{
      32,    48,    65,     0,     1,    36,     3,     4,    28,    28,
       1,    36,    43,     0,    39,    39,    63,    64,    43,    39,
      39,    68,    13,    11,    12,    28,    73,    28,    75,    36,
      33,    28,    33,    80,    81,    28,    27,    28,    29,    30,
      33,    32,    33,    31,    32,    33,    34,     1,    39,    40,
      28,    28,    36,    44,   101,     1,    33,     3,     4,    13,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    28,    27,    28,    29,    30,   124,    32,    33,
      35,   128,    28,    38,    35,    39,    28,    38,    36,     1,
      44,    39,    33,    34,   126,   127,    31,    32,    33,    34,
     163,    13,   149,    27,    38,    38,    40,    40,    27,    37,
      37,    28,   159,    35,    35,    27,    28,    29,    30,     1,
      32,    33,    28,   170,    39,    41,    39,    39,    39,    39,
     162,    35,    44,    15,    35,    35,    35,    19,    20,   171,
      35,    23,    27,    25,    26,    43,    28,     1,    28,     3,
       4,    33,    35,    27,    40,    28,    37,     6,    37,    41,
      42,    15,    38,    31,    31,    19,    20,    27,    40,    23,
      17,    25,    26,    43,    28,    27,    40,    40,    43,    33,
      41,    40,     3,    54,   129,    -1,    -1,    41,     5,     6,
       7,     8,     9,    10,    11,    12,   101,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,     5,     6,     7,     8,     9,    10,    11,    12,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    40,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    31,    32,
      33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,    28,    46,    47,    48,    49,    51,
      52,    28,    33,    50,    28,    50,     0,    48,    39,    36,
      28,    35,    38,    36,    35,    28,    53,    27,    28,    33,
      27,    38,    40,    37,    28,    37,    28,    41,    55,    35,
      35,    56,     1,    15,    19,    20,    23,    25,    26,    28,
      33,    49,    54,    55,    57,    58,    62,    65,    66,    67,
      68,    69,    70,    39,    39,    39,    39,     1,    13,    27,
      28,    29,    30,    32,    33,    39,    44,    59,    71,    36,
      39,    43,    28,    39,    42,    54,    35,    35,    35,    35,
      35,    59,    59,    28,    58,    29,    59,    63,    64,    59,
      36,    39,    59,    28,    39,    59,    28,     5,     6,     7,
       8,     9,    10,    11,    12,    31,    32,    33,    34,    27,
      59,    60,    61,    59,    43,    28,    40,    40,    35,    38,
      40,    27,    60,    28,    40,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    37,    40,    38,
      59,    31,    55,    55,    59,    64,    37,    40,    31,    43,
      59,    27,    17,    35,    27,    59,    40,    55,    58,    40,
      43,    40,    59,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    50,    50,    50,    50,    51,    51,    52,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    65,    66,    67,    67,    68,    69,
      70,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     3,     6,
       6,     1,     3,     2,     4,     5,     1,     1,     1,     3,
       0,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     4,     0,     2,     1,     2,     3,     6,     4,     8,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     6,     1,     1,
       4,     1,     1,     1,     1,     0,     1,     1,     3,     4,
       1,     3,     1,     1,     2,     1,     5,     7,     5,     9,
       4,     4
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
  case 2: /* program: function_declaration_list  */
#line 38 "mini.y"
{
	tac_last=(yyvsp[0].tac);
	tac_complete();
}
#line 1392 "y.tab.c"
    break;

  case 4: /* function_declaration_list: function_declaration_list function_declaration  */
#line 46 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1400 "y.tab.c"
    break;

  case 7: /* declaration: INT variable_list ';'  */
#line 56 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1408 "y.tab.c"
    break;

  case 8: /* declaration: CHAR variable_list ';'  */
#line 60 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1416 "y.tab.c"
    break;

  case 9: /* declaration: INT IDENTIFIER '[' INTEGER ']' ';'  */
#line 64 "mini.y"
{
	(yyval.tac)=declare_arr_new((yyvsp[-4].string),(yyvsp[-2].string));
}
#line 1424 "y.tab.c"
    break;

  case 10: /* declaration: CHAR IDENTIFIER '[' INTEGER ']' ';'  */
#line 68 "mini.y"
{
	(yyval.tac)=declare_arr_new((yyvsp[-4].string),(yyvsp[-2].string));
}
#line 1432 "y.tab.c"
    break;

  case 11: /* variable_list: IDENTIFIER  */
#line 75 "mini.y"
{
	(yyval.tac)=declare_var((yyvsp[0].string));
}
#line 1440 "y.tab.c"
    break;

  case 12: /* variable_list: variable_list ',' IDENTIFIER  */
#line 79 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_var((yyvsp[0].string)));
}
#line 1448 "y.tab.c"
    break;

  case 13: /* variable_list: '*' IDENTIFIER  */
#line 83 "mini.y"
{
	(yyval.tac)=declare_ptr((yyvsp[0].string));
}
#line 1456 "y.tab.c"
    break;

  case 14: /* variable_list: variable_list ',' '*' IDENTIFIER  */
#line 87 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-3].tac), declare_ptr((yyvsp[0].string)));
}
#line 1464 "y.tab.c"
    break;

  case 15: /* function: function_head '(' parameter_list ')' block  */
#line 93 "mini.y"
{
	(yyval.tac)=do_func((yyvsp[-4].sym), (yyvsp[-2].tac), (yyvsp[0].tac));
	scope_local=0; /* Leave local scope. */
	sym_tab_local=NULL; /* Clear local symbol table. */
}
#line 1474 "y.tab.c"
    break;

  case 16: /* function: error  */
#line 99 "mini.y"
{
	error("Bad function syntax");
	(yyval.tac)=NULL;
}
#line 1483 "y.tab.c"
    break;

  case 17: /* function_head: IDENTIFIER  */
#line 106 "mini.y"
{
	(yyval.sym)=declare_func((yyvsp[0].string));
	scope_local=1; /* Enter local scope. */
	sym_tab_local=NULL; /* Init local symbol table. */
}
#line 1493 "y.tab.c"
    break;

  case 18: /* parameter_list: IDENTIFIER  */
#line 114 "mini.y"
{
	(yyval.tac)=declare_para((yyvsp[0].string));
}
#line 1501 "y.tab.c"
    break;

  case 19: /* parameter_list: parameter_list ',' IDENTIFIER  */
#line 118 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), declare_para((yyvsp[0].string)));
}
#line 1509 "y.tab.c"
    break;

  case 20: /* parameter_list: %empty  */
#line 122 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1517 "y.tab.c"
    break;

  case 30: /* statement: error  */
#line 137 "mini.y"
{
	error("Bad statement syntax");
	(yyval.tac)=NULL;
}
#line 1526 "y.tab.c"
    break;

  case 31: /* block: '{' declaration_list statement_list '}'  */
#line 144 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[-1].tac));
}
#line 1534 "y.tab.c"
    break;

  case 32: /* declaration_list: %empty  */
#line 150 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1542 "y.tab.c"
    break;

  case 33: /* declaration_list: declaration_list declaration  */
#line 154 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1550 "y.tab.c"
    break;

  case 35: /* statement_list: statement_list statement  */
#line 161 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-1].tac), (yyvsp[0].tac));
}
#line 1558 "y.tab.c"
    break;

  case 36: /* assignment_statement: IDENTIFIER '=' expression  */
#line 167 "mini.y"
{
	(yyval.tac)=do_assign(get_var((yyvsp[-2].string)), (yyvsp[0].exp));
}
#line 1566 "y.tab.c"
    break;

  case 37: /* assignment_statement: IDENTIFIER '[' INTEGER ']' '=' expression  */
#line 171 "mini.y"
{
	(yyval.tac)=do_assign_arr(get_var((yyvsp[-5].string)),(yyvsp[-3].string), (yyvsp[0].exp));
}
#line 1574 "y.tab.c"
    break;

  case 38: /* assignment_statement: '*' IDENTIFIER '=' expression  */
#line 175 "mini.y"
{
	(yyval.tac)=do_assign_ptr(get_var((yyvsp[-2].string)),(yyvsp[0].exp));
}
#line 1582 "y.tab.c"
    break;

  case 39: /* assignment_statement: '*' '(' IDENTIFIER '+' INTEGER ')' '=' expression  */
#line 179 "mini.y"
{
	(yyval.tac)=do_assign_ptr_new(get_var((yyvsp[-5].string)),(yyvsp[-3].string),(yyvsp[0].exp));
}
#line 1590 "y.tab.c"
    break;

  case 40: /* expression: expression '+' expression  */
#line 185 "mini.y"
{
	(yyval.exp)=do_bin(TAC_ADD, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1598 "y.tab.c"
    break;

  case 41: /* expression: expression '-' expression  */
#line 189 "mini.y"
{
	(yyval.exp)=do_bin(TAC_SUB, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1606 "y.tab.c"
    break;

  case 42: /* expression: expression '*' expression  */
#line 193 "mini.y"
{
	(yyval.exp)=do_bin(TAC_MUL, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1614 "y.tab.c"
    break;

  case 43: /* expression: expression '/' expression  */
#line 197 "mini.y"
{
	(yyval.exp)=do_bin(TAC_DIV, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1622 "y.tab.c"
    break;

  case 44: /* expression: '-' expression  */
#line 201 "mini.y"
{
	(yyval.exp)=do_un(TAC_NEG, (yyvsp[0].exp));
}
#line 1630 "y.tab.c"
    break;

  case 45: /* expression: NOT expression  */
#line 205 "mini.y"
{
    (yyval.exp)=do_not(TAC_NOT,(yyvsp[0].exp));
}
#line 1638 "y.tab.c"
    break;

  case 46: /* expression: expression AND expression  */
#line 209 "mini.y"
{
    (yyval.exp)=do_and(TAC_AND,(yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1646 "y.tab.c"
    break;

  case 47: /* expression: expression OR expression  */
#line 213 "mini.y"
{
    (yyval.exp)=do_or(TAC_OR,(yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1654 "y.tab.c"
    break;

  case 48: /* expression: expression EQ expression  */
#line 217 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_EQ, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1662 "y.tab.c"
    break;

  case 49: /* expression: expression NE expression  */
#line 221 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_NE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1670 "y.tab.c"
    break;

  case 50: /* expression: expression LT expression  */
#line 225 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1678 "y.tab.c"
    break;

  case 51: /* expression: expression LE expression  */
#line 229 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_LE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1686 "y.tab.c"
    break;

  case 52: /* expression: expression GT expression  */
#line 233 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GT, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1694 "y.tab.c"
    break;

  case 53: /* expression: expression GE expression  */
#line 237 "mini.y"
{
	(yyval.exp)=do_cmp(TAC_GE, (yyvsp[-2].exp), (yyvsp[0].exp));
}
#line 1702 "y.tab.c"
    break;

  case 54: /* expression: '(' expression ')'  */
#line 241 "mini.y"
{
	(yyval.exp)=(yyvsp[-1].exp);
}
#line 1710 "y.tab.c"
    break;

  case 55: /* expression: '&' IDENTIFIER  */
#line 245 "mini.y"
{
    (yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1718 "y.tab.c"
    break;

  case 56: /* expression: '*' IDENTIFIER  */
#line 249 "mini.y"
{
    (yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1726 "y.tab.c"
    break;

  case 57: /* expression: '*' '(' IDENTIFIER '+' INTEGER ')'  */
#line 253 "mini.y"
{
    (yyval.exp)=mk_exp_ptr(NULL, get_var((yyvsp[-3].string)),(yyvsp[-1].string), NULL);
}
#line 1734 "y.tab.c"
    break;

  case 58: /* expression: INTEGER  */
#line 257 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_const(atoi((yyvsp[0].string))), NULL);
}
#line 1742 "y.tab.c"
    break;

  case 59: /* expression: TEXT  */
#line 261 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_text((yyvsp[0].string)), NULL);
}
#line 1750 "y.tab.c"
    break;

  case 60: /* expression: IDENTIFIER '[' INTEGER ']'  */
#line 265 "mini.y"
{
    (yyval.exp)=mk_exp_arr(NULL, get_var((yyvsp[-3].string)),(yyvsp[-1].string), NULL);
}
#line 1758 "y.tab.c"
    break;

  case 61: /* expression: IDENTIFIER  */
#line 269 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, get_var((yyvsp[0].string)), NULL);
}
#line 1766 "y.tab.c"
    break;

  case 62: /* expression: CHARTEXT  */
#line 273 "mini.y"
{
	(yyval.exp)=mk_exp(NULL, mk_char((yyvsp[0].string)[1]), NULL);
}
#line 1774 "y.tab.c"
    break;

  case 63: /* expression: call_expression  */
#line 277 "mini.y"
{
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1782 "y.tab.c"
    break;

  case 64: /* expression: error  */
#line 281 "mini.y"
{
	error("Bad expression syntax");
	(yyval.exp)=mk_exp(NULL, NULL, NULL);
}
#line 1791 "y.tab.c"
    break;

  case 65: /* argument_list: %empty  */
#line 288 "mini.y"
{
	(yyval.exp)=NULL;
}
#line 1799 "y.tab.c"
    break;

  case 68: /* expression_list: expression_list ',' expression  */
#line 296 "mini.y"
{
	(yyvsp[0].exp)->next=(yyvsp[-2].exp);
	(yyval.exp)=(yyvsp[0].exp);
}
#line 1808 "y.tab.c"
    break;

  case 69: /* print_statement: PRINT '(' print_list ')'  */
#line 303 "mini.y"
{
	(yyval.tac)=(yyvsp[-1].tac);
}
#line 1816 "y.tab.c"
    break;

  case 71: /* print_list: print_list ',' print_item  */
#line 310 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1824 "y.tab.c"
    break;

  case 72: /* print_item: expression  */
#line 316 "mini.y"
{
	(yyval.tac)=join_tac((yyvsp[0].exp)->tac,
	do_lib("PRINTN", (yyvsp[0].exp)->ret));
}
#line 1833 "y.tab.c"
    break;

  case 73: /* print_item: TEXT  */
#line 321 "mini.y"
{
	(yyval.tac)=do_lib("PRINTS", mk_text((yyvsp[0].string)));
}
#line 1841 "y.tab.c"
    break;

  case 74: /* return_statement: RETURN expression  */
#line 327 "mini.y"
{
	TAC *t=mk_tac(TAC_RETURN, (yyvsp[0].exp)->ret, NULL, NULL);
	t->prev=(yyvsp[0].exp)->tac;
	(yyval.tac)=t;
}
#line 1851 "y.tab.c"
    break;

  case 75: /* null_statement: CONTINUE  */
#line 335 "mini.y"
{
	(yyval.tac)=NULL;
}
#line 1859 "y.tab.c"
    break;

  case 76: /* if_statement: IF '(' expression ')' block  */
#line 341 "mini.y"
{
	(yyval.tac)=do_if((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1867 "y.tab.c"
    break;

  case 77: /* if_statement: IF '(' expression ')' block ELSE block  */
#line 345 "mini.y"
{
	(yyval.tac)=do_test((yyvsp[-4].exp), (yyvsp[-2].tac), (yyvsp[0].tac));
}
#line 1875 "y.tab.c"
    break;

  case 78: /* while_statement: WHILE '(' expression ')' block  */
#line 351 "mini.y"
{
	(yyval.tac)=do_while((yyvsp[-2].exp), (yyvsp[0].tac));
}
#line 1883 "y.tab.c"
    break;

  case 79: /* for_statement: FOR '(' assignment_statement ';' expression ';' assignment_statement ')' block  */
#line 357 "mini.y"
{
    (yyval.tac)=do_for((yyvsp[-6].tac),(yyvsp[-4].exp),(yyvsp[-2].tac),(yyvsp[0].tac));
}
#line 1891 "y.tab.c"
    break;

  case 80: /* call_statement: IDENTIFIER '(' argument_list ')'  */
#line 365 "mini.y"
{
	(yyval.tac)=do_call((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1899 "y.tab.c"
    break;

  case 81: /* call_expression: IDENTIFIER '(' argument_list ')'  */
#line 371 "mini.y"
{
	(yyval.exp)=do_call_ret((yyvsp[-3].string), (yyvsp[-1].exp));
}
#line 1907 "y.tab.c"
    break;


#line 1911 "y.tab.c"

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

#line 376 "mini.y"


void yyerror(char* msg) 
{
	fprintf(stderr, "%s: line %d\n", msg, yylineno);
	exit(0);
}

int main(int argc,   char *argv[])
{
	if(argc != 2)
	{
		printf("usage: %s filename\n", argv[0]);
		exit(0);
	}
	
	char *input, *output;

	input = argv[1];
	if(freopen(input, "r", stdin)==NULL)
	{
		printf("error: open %s failed\n", input);
		return 0;
	}

	output=(char *)malloc(strlen(input + 10));
	strcpy(output,input);
	strcat(output,".s");

	if(freopen(output, "w", stdout)==NULL)
	{
		printf("error: open %s failed\n", output);
		return 0;
	}

	tac_init();

	yyparse();

    tac_dump();
    tac_obj();


	return 0;
}
