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

int erros_lexicos = 0;
int erros_sintaticos = 0;

typedef struct No {
    char* tipo;
    char* valor;
    int num_filhos;
    struct No** filhos;
} No;

No* criar_no(char* tipo, char* valor);
void adicionar_filho(No* pai, No* filho);
void imprimir_arvore(No* raiz, int nivel);
void liberar_arvore(No* raiz);

extern int linha;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);
int yylex();

No* raiz = NULL;


#line 101 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIPO_INT = 3,                   /* TIPO_INT  */
  YYSYMBOL_TIPO_FLOAT = 4,                 /* TIPO_FLOAT  */
  YYSYMBOL_TIPO_CHAR = 5,                  /* TIPO_CHAR  */
  YYSYMBOL_TIPO_STRING = 6,                /* TIPO_STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_MAIN = 13,                      /* MAIN  */
  YYSYMBOL_INCLUDE = 14,                   /* INCLUDE  */
  YYSYMBOL_NUM_INT = 15,                   /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 16,                 /* NUM_FLOAT  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_IGUAL = 20,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 21,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MAIOR = 23,                     /* MAIOR  */
  YYSYMBOL_MENOR_IGUAL = 24,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 25,               /* MAIOR_IGUAL  */
  YYSYMBOL_E = 26,                         /* E  */
  YYSYMBOL_OU = 27,                        /* OU  */
  YYSYMBOL_NAO = 28,                       /* NAO  */
  YYSYMBOL_INC = 29,                       /* INC  */
  YYSYMBOL_DEC = 30,                       /* DEC  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* '%'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* '#'  */
  YYSYMBOL_40_ = 40,                       /* '.'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programa = 48,                  /* programa  */
  YYSYMBOL_includes = 49,                  /* includes  */
  YYSYMBOL_include_stmt = 50,              /* include_stmt  */
  YYSYMBOL_declaracoes = 51,               /* declaracoes  */
  YYSYMBOL_declaracao = 52,                /* declaracao  */
  YYSYMBOL_declaracao_variavel = 53,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 54,                      /* tipo  */
  YYSYMBOL_declaracao_funcao = 55,         /* declaracao_funcao  */
  YYSYMBOL_parametros = 56,                /* parametros  */
  YYSYMBOL_lista_parametros = 57,          /* lista_parametros  */
  YYSYMBOL_parametro = 58,                 /* parametro  */
  YYSYMBOL_bloco = 59,                     /* bloco  */
  YYSYMBOL_comandos = 60,                  /* comandos  */
  YYSYMBOL_comando = 61,                   /* comando  */
  YYSYMBOL_comando_if = 62,                /* comando_if  */
  YYSYMBOL_comando_while = 63,             /* comando_while  */
  YYSYMBOL_comando_for = 64,               /* comando_for  */
  YYSYMBOL_atribuicao = 65,                /* atribuicao  */
  YYSYMBOL_expressao = 66                  /* expressao  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

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
       2,     2,     2,     2,     2,    39,     2,    36,     2,     2,
      37,    38,    34,    32,    44,    33,    40,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
       0,    67,    67,    78,    81,    89,    98,   103,   111,   115,
     122,   127,   134,   143,   147,   151,   155,   159,   166,   173,
     183,   186,   194,   199,   207,   215,   224,   227,   232,   240,
     244,   248,   252,   255,   263,   269,   279,   288,   299,   305,
     316,   322,   328,   332,   336,   340,   345,   351,   357,   363,
     369,   375,   381,   385,   390,   396,   402,   408,   414,   420,
     426,   431,   436,   441,   446
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
  "\"end of file\"", "error", "\"invalid token\"", "TIPO_INT",
  "TIPO_FLOAT", "TIPO_CHAR", "TIPO_STRING", "VOID", "IF", "ELSE", "WHILE",
  "FOR", "RETURN", "MAIN", "INCLUDE", "NUM_INT", "NUM_FLOAT", "STRING",
  "CHAR", "ID", "IGUAL", "DIFERENTE", "MENOR", "MAIOR", "MENOR_IGUAL",
  "MAIOR_IGUAL", "E", "OU", "NAO", "INC", "DEC", "'='", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'('", "')'", "'#'", "'.'", "';'", "'['", "']'",
  "','", "'{'", "'}'", "$accept", "programa", "includes", "include_stmt",
  "declaracoes", "declaracao", "declaracao_variavel", "tipo",
  "declaracao_funcao", "parametros", "lista_parametros", "parametro",
  "bloco", "comandos", "comando", "comando_if", "comando_while",
  "comando_for", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,    17,     3,   -57,   -57,   -57,   -57,   -57,   -57,    42,
     -57,   -57,   137,   -57,    12,   -57,     4,   -57,    -5,    55,
      31,    29,   137,   -57,   -14,    35,    23,    65,    49,   -57,
      51,    50,    77,    92,   285,   -57,   -57,    23,   137,    78,
     101,    97,    95,    98,   117,    36,   -20,   285,   138,   116,
     285,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   122,   -57,
      36,    36,   145,   -57,   -57,   -57,   -57,   123,    36,    36,
      36,    36,    36,   104,    36,    36,   -57,   -39,   -57,   -57,
     -57,   192,   211,    36,    36,    19,    19,    19,    19,   230,
      36,    36,    36,    36,    36,    36,    36,    36,   -57,   -57,
      36,    36,    36,    36,   -57,   126,    56,    23,    23,   148,
      80,   -57,   316,   316,    28,    28,    28,    28,   302,   286,
      87,    87,    19,    19,   -57,   135,   167,   -57,    36,   -57,
      36,    23,   249,   170,   -57,    23,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    13,    14,    15,    16,    17,     0,
       4,     2,     6,     8,     0,     9,     0,     7,     0,     0,
       0,     0,    20,    10,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,    26,    19,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
      26,    30,    31,    32,    29,    18,    23,    11,     0,     5,
       0,     0,     0,    40,    41,    43,    44,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    25,    27,
      12,     0,     0,     0,     0,    60,    61,    62,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    64,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,    52,    54,    55,    51,    50,    56,    57,    58,    59,
      46,    47,    48,    49,    38,     0,    34,    36,     0,    45,
       0,     0,     0,     0,    35,     0,    39,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   -57,   172,   -57,    18,    21,   -57,   -57,
     141,   -57,   -37,   -26,   -57,   -57,   -57,   -57,   124,   -56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    12,    47,    48,    15,    28,
      29,    30,    35,    49,    50,    51,    52,    53,    54,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    31,    23,    24,    81,    82,     4,     5,     6,     7,
       8,    74,    85,    86,    87,    88,    89,     3,   105,   106,
      13,    76,    75,    14,    79,    18,    20,   109,   110,    32,
      13,    19,    21,    14,   112,   113,   114,   115,   116,   117,
     118,   119,     9,    27,   120,   121,   122,   123,    98,    99,
      25,    63,    64,    65,    66,    67,    16,    98,    99,    27,
     100,   101,   102,   103,    68,    69,    70,    26,    34,    71,
     126,   127,   132,    72,   133,    33,    90,    91,    92,    93,
      94,    95,    96,    97,    36,    98,    99,    37,   100,   101,
     102,   103,    22,    39,   134,    38,    23,    24,   137,   125,
      90,    91,    92,    93,    94,    95,    96,    97,    40,    98,
      99,    41,   100,   101,   102,   103,    98,    99,    58,    57,
      59,   102,   103,   129,    90,    91,    92,    93,    94,    95,
      96,    97,    60,    98,    99,    61,   100,   101,   102,   103,
       4,     5,     6,     7,     8,   104,    90,    91,    92,    93,
      94,    95,    96,    97,    62,    98,    99,    77,   100,   101,
     102,   103,    78,    80,    46,    84,   130,   124,    90,    91,
      92,    93,    94,    95,    96,    97,   131,    98,    99,    56,
     100,   101,   102,   103,    17,     0,    83,     0,     0,   128,
      90,    91,    92,    93,    94,    95,    96,    97,     0,    98,
      99,     0,   100,   101,   102,   103,     0,     0,     0,     0,
       0,   136,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    98,    99,     0,   100,   101,   102,   103,     0,     0,
     107,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      98,    99,     0,   100,   101,   102,   103,     0,     0,   108,
      90,    91,    92,    93,    94,    95,    96,    97,     0,    98,
      99,     0,   100,   101,   102,   103,     0,     0,   111,    90,
      91,    92,    93,    94,    95,    96,    97,     0,    98,    99,
       0,   100,   101,   102,   103,     0,     0,   135,     4,     5,
       6,     7,     8,    42,     0,    43,    44,    45,     0,     0,
       0,     0,     0,     0,    46,     0,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    98,    99,     0,   100,   101,
     102,   103,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    98,    99,     0,   100,   101,   102,   103,    92,    93,
      94,    95,     0,     0,     0,    98,    99,     0,   100,   101,
     102,   103
};

static const yytype_int16 yycheck[] =
{
      37,    15,    41,    42,    60,    61,     3,     4,     5,     6,
       7,    31,    68,    69,    70,    71,    72,     0,    74,    75,
       2,    47,    42,     2,    50,    13,    22,    83,    84,    43,
      12,    19,    37,    12,    90,    91,    92,    93,    94,    95,
      96,    97,    39,    22,   100,   101,   102,   103,    29,    30,
      19,    15,    16,    17,    18,    19,    14,    29,    30,    38,
      32,    33,    34,    35,    28,    29,    30,    38,    45,    33,
     107,   108,   128,    37,   130,    40,    20,    21,    22,    23,
      24,    25,    26,    27,    19,    29,    30,    38,    32,    33,
      34,    35,    37,    43,   131,    44,    41,    42,   135,    43,
      20,    21,    22,    23,    24,    25,    26,    27,    31,    29,
      30,    19,    32,    33,    34,    35,    29,    30,    17,    41,
      23,    34,    35,    43,    20,    21,    22,    23,    24,    25,
      26,    27,    37,    29,    30,    37,    32,    33,    34,    35,
       3,     4,     5,     6,     7,    41,    20,    21,    22,    23,
      24,    25,    26,    27,    37,    29,    30,    19,    32,    33,
      34,    35,    46,    41,    19,    42,    31,    41,    20,    21,
      22,    23,    24,    25,    26,    27,     9,    29,    30,    38,
      32,    33,    34,    35,    12,    -1,    62,    -1,    -1,    41,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    -1,    -1,
      -1,    41,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    -1,    32,    33,    34,    35,    -1,    -1,
      38,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    33,    34,    35,    -1,    -1,    38,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    -1,    32,    33,    34,    35,    -1,    -1,    38,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      -1,    32,    33,    34,    35,    -1,    -1,    38,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    29,    30,    -1,    32,    33,
      34,    35,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    30,    -1,    32,    33,    34,    35,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    30,    -1,    32,    33,
      34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     3,     4,     5,     6,     7,    39,
      50,    51,    52,    53,    54,    55,    14,    51,    13,    19,
      22,    37,    37,    41,    42,    19,    38,    54,    56,    57,
      58,    15,    43,    40,    45,    59,    19,    38,    44,    43,
      31,    19,     8,    10,    11,    12,    19,    53,    54,    60,
      61,    62,    63,    64,    65,    59,    57,    41,    17,    23,
      37,    37,    37,    15,    16,    17,    18,    19,    28,    29,
      30,    33,    37,    66,    31,    42,    60,    19,    46,    60,
      41,    66,    66,    65,    42,    66,    66,    66,    66,    66,
      20,    21,    22,    23,    24,    25,    26,    27,    29,    30,
      32,    33,    34,    35,    41,    66,    66,    38,    38,    66,
      66,    38,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    41,    43,    59,    59,    41,    43,
      31,     9,    66,    66,    59,    38,    41,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     7,     1,     2,     1,     1,
       3,     6,     7,     1,     1,     1,     1,     1,     6,     5,
       0,     1,     1,     3,     2,     3,     0,     2,     2,     1,
       1,     1,     1,     3,     5,     7,     5,     8,     4,     7,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2
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
  case 2: /* programa: includes declaracoes  */
#line 68 "parser.y"
    {
        (yyval.no) = criar_no("PROGRAMA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        raiz = (yyval.no);
    }
#line 1286 "parser.tab.c"
    break;

  case 3: /* includes: %empty  */
#line 78 "parser.y"
    {
        (yyval.no) = criar_no("INCLUDES", "");
    }
#line 1294 "parser.tab.c"
    break;

  case 4: /* includes: includes include_stmt  */
#line 82 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1303 "parser.tab.c"
    break;

  case 5: /* include_stmt: '#' INCLUDE MENOR ID '.' ID MAIOR  */
#line 90 "parser.y"
    {
        char include_name[100];
        sprintf(include_name, "%s.%s", (yyvsp[-3].sval), (yyvsp[-1].sval));
        (yyval.no) = criar_no("INCLUDE", include_name);
    }
#line 1313 "parser.tab.c"
    break;

  case 6: /* declaracoes: declaracao  */
#line 99 "parser.y"
    { 
        (yyval.no) = criar_no("DECLARACOES", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1322 "parser.tab.c"
    break;

  case 7: /* declaracoes: declaracao declaracoes  */
#line 104 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1331 "parser.tab.c"
    break;

  case 8: /* declaracao: declaracao_variavel  */
#line 112 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1339 "parser.tab.c"
    break;

  case 9: /* declaracao: declaracao_funcao  */
#line 116 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1347 "parser.tab.c"
    break;

  case 10: /* declaracao_variavel: tipo ID ';'  */
#line 123 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-1].sval));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1356 "parser.tab.c"
    break;

  case 11: /* declaracao_variavel: tipo ID '[' NUM_INT ']' ';'  */
#line 128 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[%d]", (yyvsp[-4].sval), (yyvsp[-2].ival));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-5].no));
    }
#line 1367 "parser.tab.c"
    break;

  case 12: /* declaracao_variavel: tipo ID '[' ']' '=' STRING ';'  */
#line 135 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VETOR", (yyvsp[-5].sval));
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
    }
#line 1377 "parser.tab.c"
    break;

  case 13: /* tipo: TIPO_INT  */
#line 144 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "int");
    }
#line 1385 "parser.tab.c"
    break;

  case 14: /* tipo: TIPO_FLOAT  */
#line 148 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "float");
    }
#line 1393 "parser.tab.c"
    break;

  case 15: /* tipo: TIPO_CHAR  */
#line 152 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "char");
    }
#line 1401 "parser.tab.c"
    break;

  case 16: /* tipo: TIPO_STRING  */
#line 156 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "string");
    }
#line 1409 "parser.tab.c"
    break;

  case 17: /* tipo: VOID  */
#line 160 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "void");
    }
#line 1417 "parser.tab.c"
    break;

  case 18: /* declaracao_funcao: tipo ID '(' parametros ')' bloco  */
#line 167 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", (yyvsp[-4].sval));
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1428 "parser.tab.c"
    break;

  case 19: /* declaracao_funcao: tipo MAIN '(' ')' bloco  */
#line 174 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", "main");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1438 "parser.tab.c"
    break;

  case 20: /* parametros: %empty  */
#line 183 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
    }
#line 1446 "parser.tab.c"
    break;

  case 21: /* parametros: lista_parametros  */
#line 187 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1455 "parser.tab.c"
    break;

  case 22: /* lista_parametros: parametro  */
#line 195 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1464 "parser.tab.c"
    break;

  case 23: /* lista_parametros: parametro ',' lista_parametros  */
#line 200 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1473 "parser.tab.c"
    break;

  case 24: /* parametro: tipo ID  */
#line 208 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETRO", (yyvsp[0].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1482 "parser.tab.c"
    break;

  case 25: /* bloco: '{' comandos '}'  */
#line 216 "parser.y"
    {
        (yyval.no) = criar_no("BLOCO", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1491 "parser.tab.c"
    break;

  case 26: /* comandos: %empty  */
#line 224 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
    }
#line 1499 "parser.tab.c"
    break;

  case 27: /* comandos: comando comandos  */
#line 228 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1508 "parser.tab.c"
    break;

  case 28: /* comandos: declaracao_variavel comandos  */
#line 233 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1517 "parser.tab.c"
    break;

  case 29: /* comando: atribuicao  */
#line 241 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1525 "parser.tab.c"
    break;

  case 30: /* comando: comando_if  */
#line 245 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1533 "parser.tab.c"
    break;

  case 31: /* comando: comando_while  */
#line 249 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1541 "parser.tab.c"
    break;

  case 32: /* comando: comando_for  */
#line 253 "parser.y"
    {   (yyval.no)  = (yyvsp[0].no); 
    }
#line 1548 "parser.tab.c"
    break;

  case 33: /* comando: RETURN expressao ';'  */
#line 256 "parser.y"
    {
        (yyval.no) = criar_no("RETURN", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1557 "parser.tab.c"
    break;

  case 34: /* comando_if: IF '(' expressao ')' bloco  */
#line 264 "parser.y"
    {
        (yyval.no) = criar_no("IF", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1567 "parser.tab.c"
    break;

  case 35: /* comando_if: IF '(' expressao ')' bloco ELSE bloco  */
#line 270 "parser.y"
    {
        (yyval.no) = criar_no("IF_ELSE", "");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1578 "parser.tab.c"
    break;

  case 36: /* comando_while: WHILE '(' expressao ')' bloco  */
#line 280 "parser.y"
    {
        (yyval.no) = criar_no("WHILE", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1588 "parser.tab.c"
    break;

  case 37: /* comando_for: FOR '(' atribuicao expressao ';' expressao ')' bloco  */
#line 289 "parser.y"
    {
        (yyval.no) = criar_no("FOR", "");
        adicionar_filho((yyval.no), (yyvsp[-5].no)); // inicialização
        adicionar_filho((yyval.no), (yyvsp[-4].no)); // condição
        adicionar_filho((yyval.no), (yyvsp[-2].no)); // incremento
        adicionar_filho((yyval.no), (yyvsp[0].no)); // bloco
    }
#line 1600 "parser.tab.c"
    break;

  case 38: /* atribuicao: ID '=' expressao ';'  */
#line 300 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1610 "parser.tab.c"
    break;

  case 39: /* atribuicao: ID '[' expressao ']' '=' expressao ';'  */
#line 306 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-6].sval)));
        adicionar_filho((yyval.no), (yyvsp[-4].no));  // índice
        adicionar_filho((yyval.no), (yyvsp[-1].no));  // valor
    }
#line 1621 "parser.tab.c"
    break;

  case 40: /* expressao: NUM_INT  */
#line 317 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        (yyval.no) = criar_no("NUM_INT", valor);
    }
#line 1631 "parser.tab.c"
    break;

  case 41: /* expressao: NUM_FLOAT  */
#line 323 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        (yyval.no) = criar_no("NUM_FLOAT", valor);
    }
#line 1641 "parser.tab.c"
    break;

  case 42: /* expressao: ID  */
#line 329 "parser.y"
    { 
        (yyval.no) = criar_no("ID", (yyvsp[0].sval));
    }
#line 1649 "parser.tab.c"
    break;

  case 43: /* expressao: STRING  */
#line 333 "parser.y"
    { 
        (yyval.no) = criar_no("STRING", (yyvsp[0].sval));
    }
#line 1657 "parser.tab.c"
    break;

  case 44: /* expressao: CHAR  */
#line 337 "parser.y"
    { 
        (yyval.no) = criar_no("CHAR", (yyvsp[0].sval));
    }
#line 1665 "parser.tab.c"
    break;

  case 45: /* expressao: ID '[' expressao ']'  */
#line 341 "parser.y"
    {
        (yyval.no) = criar_no("ACESSO_VETOR", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1674 "parser.tab.c"
    break;

  case 46: /* expressao: expressao '+' expressao  */
#line 346 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "+");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1684 "parser.tab.c"
    break;

  case 47: /* expressao: expressao '-' expressao  */
#line 352 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "-");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1694 "parser.tab.c"
    break;

  case 48: /* expressao: expressao '*' expressao  */
#line 358 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "*");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1704 "parser.tab.c"
    break;

  case 49: /* expressao: expressao '/' expressao  */
#line 364 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "/");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1714 "parser.tab.c"
    break;

  case 50: /* expressao: expressao MAIOR expressao  */
#line 370 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1724 "parser.tab.c"
    break;

  case 51: /* expressao: expressao MENOR expressao  */
#line 376 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1734 "parser.tab.c"
    break;

  case 52: /* expressao: '(' expressao ')'  */
#line 382 "parser.y"
    {
        (yyval.no) = (yyvsp[-1].no);
    }
#line 1742 "parser.tab.c"
    break;

  case 53: /* expressao: '-' expressao  */
#line 386 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_UNARIO", "-");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1751 "parser.tab.c"
    break;

  case 54: /* expressao: expressao IGUAL expressao  */
#line 391 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "==");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1761 "parser.tab.c"
    break;

  case 55: /* expressao: expressao DIFERENTE expressao  */
#line 397 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1771 "parser.tab.c"
    break;

  case 56: /* expressao: expressao MENOR_IGUAL expressao  */
#line 403 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1781 "parser.tab.c"
    break;

  case 57: /* expressao: expressao MAIOR_IGUAL expressao  */
#line 409 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1791 "parser.tab.c"
    break;

  case 58: /* expressao: expressao E expressao  */
#line 415 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "&&");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1801 "parser.tab.c"
    break;

  case 59: /* expressao: expressao OU expressao  */
#line 421 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "||");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1811 "parser.tab.c"
    break;

  case 60: /* expressao: NAO expressao  */
#line 427 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1820 "parser.tab.c"
    break;

  case 61: /* expressao: INC expressao  */
#line 432 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "++");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1829 "parser.tab.c"
    break;

  case 62: /* expressao: DEC expressao  */
#line 437 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "--");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1838 "parser.tab.c"
    break;

  case 63: /* expressao: expressao INC  */
#line 442 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "++");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1847 "parser.tab.c"
    break;

  case 64: /* expressao: expressao DEC  */
#line 447 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "--");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1856 "parser.tab.c"
    break;


#line 1860 "parser.tab.c"

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

#line 453 "parser.y"


No* criar_no(char* tipo, char* valor) {
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória\n");
        exit(1);
    }
    no->tipo = strdup(tipo);
    no->valor = strdup(valor ? valor : "");
    no->num_filhos = 0;
    no->filhos = NULL;
    return no;
}

void adicionar_filho(No* pai, No* filho) {
    if (pai == NULL || filho == NULL) return;
    
    pai->num_filhos++;
    pai->filhos = (No**)realloc(pai->filhos, pai->num_filhos * sizeof(No*));
    if (pai->filhos == NULL) {
        fprintf(stderr, "Erro: falha na realocação de memória\n");
        exit(1);
    }
    pai->filhos[pai->num_filhos - 1] = filho;
}

void imprimir_arvore(No* no, int nivel) {
    if (no == NULL) {
        printf("DEBUG: Nó NULL encontrado!\n");
        return;
    }
    
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    
    printf("%s", no->tipo);
    if (no->valor && strlen(no->valor) > 0) {
        printf(" (%s)", no->valor);
    }
    printf("\n");
    
    for (int i = 0; i < no->num_filhos; i++) {
        imprimir_arvore(no->filhos[i], nivel + 1);
    }
}

void liberar_arvore(No* no) {
    if (no == NULL) return;
    
    for (int i = 0; i < no->num_filhos; i++) {
        liberar_arvore(no->filhos[i]);
    }
    
    if (no->tipo) free(no->tipo);
    if (no->valor) free(no->valor);
    if (no->filhos) free(no->filhos);
    free(no);
}

void yyerror(const char* s) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", linha, s);
    fprintf(stderr, "Último token lido: %s\n", yytext);
    erros_sintaticos++;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso: %s arquivo.txt\n", argv[0]);
        return 1;
    }

    FILE* arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    yyin = arquivo;
    
    printf("\n=== Iniciando análise ===\n");
    int resultado = yyparse();
    
    printf("\n=== Resumo da análise ===\n");
    if (erros_lexicos > 0) {
        printf("Total de erros léxicos: %d\n", erros_lexicos);
    }
    if (erros_sintaticos > 0) {
        printf("Total de erros sintáticos: %d\n", erros_sintaticos);
    }
    
    if (erros_lexicos == 0 && erros_sintaticos == 0) {
        printf("\nÁrvore Sintática:\n");
        if (raiz != NULL) {
            imprimir_arvore(raiz, 0);
        } else {
            printf("ERRO: Raiz da árvore é NULL!\n");
        }
    }
    
    liberar_arvore(raiz);
    fclose(arquivo);
    return resultado;
}
