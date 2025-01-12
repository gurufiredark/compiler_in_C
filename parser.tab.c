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
#include <stdbool.h> 

extern int erros_lexicos;
int erros_sintaticos = 0;

typedef struct No {
    char* tipo;
    char* valor;
    int num_filhos;
    struct No** filhos;
} No;

typedef struct {
    char* nome;        // Nome do identificador
    char* tipo;        // Tipo do dado (int, float, char, etc)
    char* categoria;   // Variável ou Função
    int linha;         // Linha onde foi declarado
} SimboloEntrada;

typedef struct {
    SimboloEntrada* entradas;
    int quantidade;
    int capacidade;
} TabelaSimbolos;

typedef struct Escopo {
    TabelaSimbolos* tabela;
    struct Escopo* pai;
} Escopo;

// Variáveis globais
int erros_semanticos = 0;
Escopo* escopo_atual = NULL;

TabelaSimbolos* tabela;

TabelaSimbolos* criar_tabela_simbolos();     
void adicionar_simbolo(TabelaSimbolos* t, const char* nome, const char* tipo, const char* categoria, int linha);
void imprimir_tabela(TabelaSimbolos* t);                
void liberar_tabela(TabelaSimbolos* t);   


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


#line 132 "parser.tab.c"

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
  YYSYMBOL_PRINT = 15,                     /* PRINT  */
  YYSYMBOL_SCAN = 16,                      /* SCAN  */
  YYSYMBOL_NUM_INT = 17,                   /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 18,                 /* NUM_FLOAT  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_ID = 21,                        /* ID  */
  YYSYMBOL_IGUAL = 22,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 23,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 24,                     /* MENOR  */
  YYSYMBOL_MAIOR = 25,                     /* MAIOR  */
  YYSYMBOL_MENOR_IGUAL = 26,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 27,               /* MAIOR_IGUAL  */
  YYSYMBOL_E = 28,                         /* E  */
  YYSYMBOL_OU = 29,                        /* OU  */
  YYSYMBOL_NAO = 30,                       /* NAO  */
  YYSYMBOL_INC = 31,                       /* INC  */
  YYSYMBOL_DEC = 32,                       /* DEC  */
  YYSYMBOL_STRING_START = 33,              /* STRING_START  */
  YYSYMBOL_STRING_END = 34,                /* STRING_END  */
  YYSYMBOL_STRING_TEXT = 35,               /* STRING_TEXT  */
  YYSYMBOL_INTERPOLACAO_START = 36,        /* INTERPOLACAO_START  */
  YYSYMBOL_INTERPOLACAO_END = 37,          /* INTERPOLACAO_END  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_43_ = 43,                       /* '%'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* '#'  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_programa = 55,                  /* programa  */
  YYSYMBOL_includes = 56,                  /* includes  */
  YYSYMBOL_include_stmt = 57,              /* include_stmt  */
  YYSYMBOL_declaracoes = 58,               /* declaracoes  */
  YYSYMBOL_declaracao = 59,                /* declaracao  */
  YYSYMBOL_declaracao_variavel = 60,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 61,                      /* tipo  */
  YYSYMBOL_declaracao_funcao = 62,         /* declaracao_funcao  */
  YYSYMBOL_parametros = 63,                /* parametros  */
  YYSYMBOL_lista_parametros = 64,          /* lista_parametros  */
  YYSYMBOL_parametro = 65,                 /* parametro  */
  YYSYMBOL_bloco = 66,                     /* bloco  */
  YYSYMBOL_comandos = 67,                  /* comandos  */
  YYSYMBOL_comando = 68,                   /* comando  */
  YYSYMBOL_comando_print = 69,             /* comando_print  */
  YYSYMBOL_string_interpolada = 70,        /* string_interpolada  */
  YYSYMBOL_partes_string = 71,             /* partes_string  */
  YYSYMBOL_parte_string = 72,              /* parte_string  */
  YYSYMBOL_comando_scan = 73,              /* comando_scan  */
  YYSYMBOL_comando_if = 74,                /* comando_if  */
  YYSYMBOL_comando_while = 75,             /* comando_while  */
  YYSYMBOL_comando_for = 76,               /* comando_for  */
  YYSYMBOL_atribuicao_for = 77,            /* atribuicao_for  */
  YYSYMBOL_atribuicao = 78,                /* atribuicao  */
  YYSYMBOL_expressao = 79                  /* expressao  */
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
#define YYLAST   484

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,     2,     2,    46,     2,    43,     2,     2,
      44,    45,    41,    39,    51,    40,    47,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   114,   117,   125,   134,   139,   147,   151,
     158,   164,   172,   180,   190,   194,   198,   202,   206,   213,
     221,   232,   235,   243,   248,   256,   264,   273,   276,   282,
     291,   292,   293,   294,   295,   296,   297,   305,   310,   315,
     322,   329,   334,   342,   350,   355,   363,   367,   375,   380,
     389,   395,   405,   414,   425,   431,   435,   441,   448,   457,
     463,   469,   473,   477,   481,   486,   492,   498,   504,   510,
     516,   522,   526,   531,   537,   543,   549,   555,   561,   567,
     572,   577,   582,   587
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
  "FOR", "RETURN", "MAIN", "INCLUDE", "PRINT", "SCAN", "NUM_INT",
  "NUM_FLOAT", "STRING", "CHAR", "ID", "IGUAL", "DIFERENTE", "MENOR",
  "MAIOR", "MENOR_IGUAL", "MAIOR_IGUAL", "E", "OU", "NAO", "INC", "DEC",
  "STRING_START", "STRING_END", "STRING_TEXT", "INTERPOLACAO_START",
  "INTERPOLACAO_END", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'('",
  "')'", "'#'", "'.'", "';'", "'['", "']'", "','", "'{'", "'}'", "$accept",
  "programa", "includes", "include_stmt", "declaracoes", "declaracao",
  "declaracao_variavel", "tipo", "declaracao_funcao", "parametros",
  "lista_parametros", "parametro", "bloco", "comandos", "comando",
  "comando_print", "string_interpolada", "partes_string", "parte_string",
  "comando_scan", "comando_if", "comando_while", "comando_for",
  "atribuicao_for", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,    27,    16,   -65,   -65,   -65,   -65,   -65,   -65,    37,
     -65,   -65,   247,   -65,    40,   -65,    28,   -65,    11,   -41,
      43,    32,   247,   -65,    -1,    31,    30,    66,    47,   -65,
      39,    46,    -5,    72,   449,   -65,   -65,    30,   247,    49,
      76,   -65,    82,    67,    69,    70,   134,    81,    95,   -34,
     449,    89,    73,   449,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,    93,   -65,   134,   134,    53,   -65,   -65,
     -65,   -65,    94,   134,   134,   134,   134,   134,   163,   103,
     121,   140,   134,   -65,   -43,   -65,   -65,   -65,   271,   295,
     111,   123,   114,   134,     0,     0,     0,     0,   319,   134,
     134,   134,   134,   134,   134,   134,   134,   -65,   -65,   134,
     134,   134,   134,   -65,   118,   122,   124,   128,   130,    45,
     131,   -19,   120,   190,    44,    30,    30,   134,   139,   134,
      77,   -65,   442,   442,   167,   167,   167,   167,   409,   388,
     192,   192,     0,     0,   133,   135,   145,   148,   149,   -65,
     158,   166,    45,   153,   162,   134,   -65,   -65,   144,   211,
     -65,   367,   134,   217,   -65,   -65,   -65,   -65,   -65,   -65,
     188,   -65,   -65,   -65,   -65,   106,   134,    30,   367,   134,
     -65,   181,   244,   -65,   343,   179,   -65,    30,   -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    14,    15,    16,    17,    18,     0,
       4,     2,     6,     8,     0,     9,     0,     7,     0,     0,
       0,     0,    21,    10,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,    27,    20,    25,     0,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    27,    34,    35,    31,    32,    33,    30,
      19,    24,    11,     0,     5,     0,     0,     0,    59,    60,
      62,    63,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    26,    28,    13,     0,     0,
       0,     0,     0,     0,    79,    80,    81,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,     0,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    73,    74,    70,    69,    75,    76,    77,    78,
      65,    66,    67,    68,     0,     0,     0,     0,     0,    46,
       0,     0,    44,     0,     0,     0,    58,    56,     0,    50,
      52,    54,     0,     0,    64,    39,    40,    41,    42,    38,
       0,    43,    45,    37,    48,     0,     0,     0,    55,     0,
      47,     0,     0,    51,     0,     0,    57,     0,    49,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   -65,   216,   -65,    42,    12,   -65,   -65,
     197,   -65,   -37,   -25,   -65,   -65,   -65,    84,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    12,    50,    51,    15,    28,
      29,    30,    35,    52,    53,    54,   120,   151,   152,    55,
      56,    57,    58,    92,    59,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    88,    89,    22,    81,    23,    24,    23,    24,    94,
      95,    96,    97,    98,    14,    82,    31,   123,   124,     4,
       5,     6,     7,     8,    14,    83,   154,     3,    86,   130,
     155,   107,   108,    40,    27,   132,   133,   134,   135,   136,
     137,   138,   139,    41,    13,   140,   141,   142,   143,    32,
      27,    16,    20,    18,    13,    21,     4,     5,     6,     7,
       8,    19,     9,   161,    25,   163,    99,   100,   101,   102,
     103,   104,   105,   106,    90,   107,   108,    26,    33,    91,
     149,   150,    34,   109,   110,   111,   112,    36,   159,   160,
      38,   175,    37,    42,   158,    63,    39,    62,   178,    99,
     100,   101,   102,   103,   104,   105,   106,    64,   107,   108,
      84,    65,   182,    66,    67,   184,   109,   110,   111,   112,
     114,   115,   116,   117,   118,    79,    85,   164,    99,   100,
     101,   102,   103,   104,   105,   106,   119,   107,   108,    80,
     183,    87,   121,    93,   128,   109,   110,   111,   112,   127,
     189,    68,    69,    70,    71,    72,   181,    68,    69,   122,
      71,    72,   129,   144,    73,    74,    75,   145,   156,   146,
      73,    74,    75,   147,    76,   148,   153,   162,    77,   170,
      76,   165,   176,   166,    77,    99,   100,   101,   102,   103,
     104,   105,   106,   167,   107,   108,   168,   169,   107,   108,
     171,   173,   109,   110,   111,   112,   109,   110,   111,   112,
     174,   113,    99,   100,   101,   102,   103,   104,   105,   106,
     177,   107,   108,   107,   108,   180,   185,   188,    17,   109,
     110,   111,   112,   111,   112,    61,   172,     0,   157,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
       4,     5,     6,     7,     8,     0,   109,   110,   111,   112,
       0,     0,     0,     0,     0,   179,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,     0,     0,     0,
       0,     0,   186,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,     0,     0,     0,     0,     0,     0,
     109,   110,   111,   112,     0,     0,   125,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,     0,     0,
       0,     0,     0,     0,   109,   110,   111,   112,     0,     0,
     126,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,     0,     0,   131,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,     0,     0,     0,     0,
       0,     0,   109,   110,   111,   112,     0,     0,   187,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
      99,   100,   101,   102,   103,   104,   105,     0,     0,   107,
     108,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,    99,   100,   101,   102,   103,   104,     0,     0,     0,
     107,   108,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,     4,     5,     6,     7,     8,    43,     0,    44,
      45,    46,     0,     0,    47,    48,   101,   102,   103,   104,
      49,     0,     0,   107,   108,     0,     0,     0,     0,     0,
       0,   109,   110,   111,   112
};

static const yytype_int16 yycheck[] =
{
      37,    65,    66,    44,    38,    48,    49,    48,    49,    73,
      74,    75,    76,    77,     2,    49,    17,    81,    82,     3,
       4,     5,     6,     7,    12,    50,    45,     0,    53,    93,
      49,    31,    32,    38,    22,    99,   100,   101,   102,   103,
     104,   105,   106,    48,     2,   109,   110,   111,   112,    50,
      38,    14,    24,    13,    12,    44,     3,     4,     5,     6,
       7,    21,    46,   127,    21,   129,    22,    23,    24,    25,
      26,    27,    28,    29,    21,    31,    32,    45,    47,    67,
      35,    36,    52,    39,    40,    41,    42,    21,   125,   126,
      51,   155,    45,    21,    50,    19,    50,    48,   162,    22,
      23,    24,    25,    26,    27,    28,    29,    25,    31,    32,
      21,    44,   176,    44,    44,   179,    39,    40,    41,    42,
      17,    18,    19,    20,    21,    44,    53,    50,    22,    23,
      24,    25,    26,    27,    28,    29,    33,    31,    32,    44,
     177,    48,    21,    49,    21,    39,    40,    41,    42,    38,
     187,    17,    18,    19,    20,    21,    50,    17,    18,    19,
      20,    21,    48,    45,    30,    31,    32,    45,    48,    45,
      30,    31,    32,    45,    40,    45,    45,    38,    44,    21,
      40,    48,    38,    48,    44,    22,    23,    24,    25,    26,
      27,    28,    29,    48,    31,    32,    48,    48,    31,    32,
      34,    48,    39,    40,    41,    42,    39,    40,    41,    42,
      48,    48,    22,    23,    24,    25,    26,    27,    28,    29,
       9,    31,    32,    31,    32,    37,    45,    48,    12,    39,
      40,    41,    42,    41,    42,    38,   152,    -1,    48,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
       3,     4,     5,     6,     7,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    45,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      45,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    45,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    45,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    -1,    -1,    15,    16,    24,    25,    26,    27,
      21,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,    46,
      57,    58,    59,    60,    61,    62,    14,    58,    13,    21,
      24,    44,    44,    48,    49,    21,    45,    61,    63,    64,
      65,    17,    50,    47,    52,    66,    21,    45,    51,    50,
      38,    48,    21,     8,    10,    11,    12,    15,    16,    21,
      60,    61,    67,    68,    69,    73,    74,    75,    76,    78,
      66,    64,    48,    19,    25,    44,    44,    44,    17,    18,
      19,    20,    21,    30,    31,    32,    40,    44,    79,    44,
      44,    38,    49,    67,    21,    53,    67,    48,    79,    79,
      21,    61,    77,    49,    79,    79,    79,    79,    79,    22,
      23,    24,    25,    26,    27,    28,    29,    31,    32,    39,
      40,    41,    42,    48,    17,    18,    19,    20,    21,    33,
      70,    21,    19,    79,    79,    45,    45,    38,    21,    48,
      79,    45,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    45,    45,    45,    45,    45,    35,
      36,    71,    72,    45,    45,    49,    48,    48,    50,    66,
      66,    79,    38,    79,    50,    48,    48,    48,    48,    48,
      21,    34,    71,    48,    48,    79,    38,     9,    79,    48,
      37,    50,    79,    66,    79,    45,    48,    45,    48,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    76,    77,    77,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     7,     1,     2,     1,     1,
       3,     6,     5,     7,     1,     1,     1,     1,     1,     6,
       5,     0,     1,     1,     3,     2,     3,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     5,     5,     5,
       5,     5,     5,     3,     1,     2,     1,     3,     5,     8,
       5,     7,     5,     9,     3,     4,     4,     7,     4,     1,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2
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
#line 104 "parser.y"
    {
        (yyval.no) = criar_no("PROGRAMA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        raiz = (yyval.no);
    }
#line 1383 "parser.tab.c"
    break;

  case 3: /* includes: %empty  */
#line 114 "parser.y"
    {
        (yyval.no) = criar_no("INCLUDES", "");
    }
#line 1391 "parser.tab.c"
    break;

  case 4: /* includes: includes include_stmt  */
#line 118 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1400 "parser.tab.c"
    break;

  case 5: /* include_stmt: '#' INCLUDE MENOR ID '.' ID MAIOR  */
#line 126 "parser.y"
    {
        char include_name[100];
        sprintf(include_name, "%s.%s", (yyvsp[-3].sval), (yyvsp[-1].sval));
        (yyval.no) = criar_no("INCLUDE", include_name);
    }
#line 1410 "parser.tab.c"
    break;

  case 6: /* declaracoes: declaracao  */
#line 135 "parser.y"
    { 
        (yyval.no) = criar_no("DECLARACOES", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1419 "parser.tab.c"
    break;

  case 7: /* declaracoes: declaracao declaracoes  */
#line 140 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1428 "parser.tab.c"
    break;

  case 8: /* declaracao: declaracao_variavel  */
#line 148 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1436 "parser.tab.c"
    break;

  case 9: /* declaracao: declaracao_funcao  */
#line 152 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1444 "parser.tab.c"
    break;

  case 10: /* declaracao_variavel: tipo ID ';'  */
#line 159 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-1].sval));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_simbolo(tabela, (yyvsp[-1].sval), (yyvsp[-2].no)->valor, "variavel", linha);
    }
#line 1454 "parser.tab.c"
    break;

  case 11: /* declaracao_variavel: tipo ID '[' NUM_INT ']' ';'  */
#line 165 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[%d]", (yyvsp[-4].sval), (yyvsp[-2].ival));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), (yyvsp[-5].no)->valor, "variavel", linha);
    }
#line 1466 "parser.tab.c"
    break;

  case 12: /* declaracao_variavel: tipo ID '[' ']' ';'  */
#line 173 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[]", (yyvsp[-3].sval));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_simbolo(tabela, (yyvsp[-3].sval), (yyvsp[-4].no)->valor, "variavel", linha);
    }
#line 1478 "parser.tab.c"
    break;

  case 13: /* declaracao_variavel: tipo ID '[' ']' '=' STRING ';'  */
#line 181 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_STRING", (yyvsp[-5].sval));
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
        adicionar_simbolo(tabela, (yyvsp[-5].sval), (yyvsp[-6].no)->valor, "variavel", linha);
    }
#line 1489 "parser.tab.c"
    break;

  case 14: /* tipo: TIPO_INT  */
#line 191 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "int");
    }
#line 1497 "parser.tab.c"
    break;

  case 15: /* tipo: TIPO_FLOAT  */
#line 195 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "float");
    }
#line 1505 "parser.tab.c"
    break;

  case 16: /* tipo: TIPO_CHAR  */
#line 199 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "char");
    }
#line 1513 "parser.tab.c"
    break;

  case 17: /* tipo: TIPO_STRING  */
#line 203 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "string");
    }
#line 1521 "parser.tab.c"
    break;

  case 18: /* tipo: VOID  */
#line 207 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "void");
    }
#line 1529 "parser.tab.c"
    break;

  case 19: /* declaracao_funcao: tipo ID '(' parametros ')' bloco  */
#line 214 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", (yyvsp[-4].sval));
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), (yyvsp[-5].no)->valor, "funcao", linha);
    }
#line 1541 "parser.tab.c"
    break;

  case 20: /* declaracao_funcao: tipo MAIN '(' ')' bloco  */
#line 222 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", "main");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, "main", (yyvsp[-4].no)->valor, "funcao", linha);
    }
#line 1552 "parser.tab.c"
    break;

  case 21: /* parametros: %empty  */
#line 232 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
    }
#line 1560 "parser.tab.c"
    break;

  case 22: /* parametros: lista_parametros  */
#line 236 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1569 "parser.tab.c"
    break;

  case 23: /* lista_parametros: parametro  */
#line 244 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1578 "parser.tab.c"
    break;

  case 24: /* lista_parametros: parametro ',' lista_parametros  */
#line 249 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1587 "parser.tab.c"
    break;

  case 25: /* parametro: tipo ID  */
#line 257 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETRO", (yyvsp[0].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1596 "parser.tab.c"
    break;

  case 26: /* bloco: '{' comandos '}'  */
#line 265 "parser.y"
    {
        (yyval.no) = criar_no("BLOCO", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1605 "parser.tab.c"
    break;

  case 27: /* comandos: %empty  */
#line 273 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
    }
#line 1613 "parser.tab.c"
    break;

  case 28: /* comandos: comando comandos  */
#line 277 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1623 "parser.tab.c"
    break;

  case 29: /* comandos: declaracao_variavel comandos  */
#line 283 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1633 "parser.tab.c"
    break;

  case 30: /* comando: atribuicao  */
#line 291 "parser.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1639 "parser.tab.c"
    break;

  case 31: /* comando: comando_if  */
#line 292 "parser.y"
                 { (yyval.no) = (yyvsp[0].no); }
#line 1645 "parser.tab.c"
    break;

  case 32: /* comando: comando_while  */
#line 293 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1651 "parser.tab.c"
    break;

  case 33: /* comando: comando_for  */
#line 294 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1657 "parser.tab.c"
    break;

  case 34: /* comando: comando_print  */
#line 295 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1663 "parser.tab.c"
    break;

  case 35: /* comando: comando_scan  */
#line 296 "parser.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1669 "parser.tab.c"
    break;

  case 36: /* comando: RETURN expressao ';'  */
#line 298 "parser.y"
    {
        (yyval.no) = criar_no("RETURN", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1678 "parser.tab.c"
    break;

  case 37: /* comando_print: PRINT '(' string_interpolada ')' ';'  */
#line 306 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1687 "parser.tab.c"
    break;

  case 38: /* comando_print: PRINT '(' ID ')' ';'  */
#line 311 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1696 "parser.tab.c"
    break;

  case 39: /* comando_print: PRINT '(' NUM_INT ')' ';'  */
#line 316 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[-2].ival));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_INT", valor));
    }
#line 1707 "parser.tab.c"
    break;

  case 40: /* comando_print: PRINT '(' NUM_FLOAT ')' ';'  */
#line 323 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[-2].fval));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_FLOAT", valor));
    }
#line 1718 "parser.tab.c"
    break;

  case 41: /* comando_print: PRINT '(' STRING ')' ';'  */
#line 330 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-2].sval)));
    }
#line 1727 "parser.tab.c"
    break;

  case 42: /* comando_print: PRINT '(' CHAR ')' ';'  */
#line 335 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("CHAR", (yyvsp[-2].sval)));
    }
#line 1736 "parser.tab.c"
    break;

  case 43: /* string_interpolada: STRING_START partes_string STRING_END  */
#line 343 "parser.y"
    {
        (yyval.no) = criar_no("STRING_INTERPOLADA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1745 "parser.tab.c"
    break;

  case 44: /* partes_string: parte_string  */
#line 351 "parser.y"
    {
        (yyval.no) = criar_no("PARTES_STRING", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1754 "parser.tab.c"
    break;

  case 45: /* partes_string: parte_string partes_string  */
#line 356 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1763 "parser.tab.c"
    break;

  case 46: /* parte_string: STRING_TEXT  */
#line 364 "parser.y"
    {
        (yyval.no) = criar_no("TEXTO", (yyvsp[0].sval));
    }
#line 1771 "parser.tab.c"
    break;

  case 47: /* parte_string: INTERPOLACAO_START ID INTERPOLACAO_END  */
#line 368 "parser.y"
    {
        (yyval.no) = criar_no("INTERPOLACAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-1].sval)));
    }
#line 1780 "parser.tab.c"
    break;

  case 48: /* comando_scan: SCAN '(' ID ')' ';'  */
#line 376 "parser.y"
    {
        (yyval.no) = criar_no("SCAN", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1789 "parser.tab.c"
    break;

  case 49: /* comando_scan: SCAN '(' ID '[' expressao ']' ')' ';'  */
#line 381 "parser.y"
    {
        (yyval.no) = criar_no("SCAN_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-5].sval)));
        adicionar_filho((yyval.no), (yyvsp[-3].no));  /* índice do vetor */
    }
#line 1799 "parser.tab.c"
    break;

  case 50: /* comando_if: IF '(' expressao ')' bloco  */
#line 390 "parser.y"
    {
        (yyval.no) = criar_no("IF", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1809 "parser.tab.c"
    break;

  case 51: /* comando_if: IF '(' expressao ')' bloco ELSE bloco  */
#line 396 "parser.y"
    {
        (yyval.no) = criar_no("IF_ELSE", "");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1820 "parser.tab.c"
    break;

  case 52: /* comando_while: WHILE '(' expressao ')' bloco  */
#line 406 "parser.y"
    {
        (yyval.no) = criar_no("WHILE", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1830 "parser.tab.c"
    break;

  case 53: /* comando_for: FOR '(' atribuicao_for ';' expressao ';' expressao ')' bloco  */
#line 415 "parser.y"
    {
        (yyval.no) = criar_no("FOR", "");
        adicionar_filho((yyval.no), (yyvsp[-6].no)); // inicialização
        adicionar_filho((yyval.no), (yyvsp[-4].no)); // condição
        adicionar_filho((yyval.no), (yyvsp[-2].no)); // incremento
        adicionar_filho((yyval.no), (yyvsp[0].no)); // bloco
    }
#line 1842 "parser.tab.c"
    break;

  case 54: /* atribuicao_for: ID '=' expressao  */
#line 426 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1852 "parser.tab.c"
    break;

  case 56: /* atribuicao: ID '=' expressao ';'  */
#line 436 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1862 "parser.tab.c"
    break;

  case 57: /* atribuicao: ID '[' expressao ']' '=' expressao ';'  */
#line 442 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-6].sval)));
        adicionar_filho((yyval.no), (yyvsp[-4].no));  // índice
        adicionar_filho((yyval.no), (yyvsp[-1].no));  // valor
    }
#line 1873 "parser.tab.c"
    break;

  case 58: /* atribuicao: ID '=' STRING ';'  */
#line 449 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_STRING", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
    }
#line 1883 "parser.tab.c"
    break;

  case 59: /* expressao: NUM_INT  */
#line 458 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        (yyval.no) = criar_no("NUM_INT", valor);
    }
#line 1893 "parser.tab.c"
    break;

  case 60: /* expressao: NUM_FLOAT  */
#line 464 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        (yyval.no) = criar_no("NUM_FLOAT", valor);
    }
#line 1903 "parser.tab.c"
    break;

  case 61: /* expressao: ID  */
#line 470 "parser.y"
    { 
        (yyval.no) = criar_no("ID", (yyvsp[0].sval));
    }
#line 1911 "parser.tab.c"
    break;

  case 62: /* expressao: STRING  */
#line 474 "parser.y"
    { 
        (yyval.no) = criar_no("STRING", (yyvsp[0].sval));
    }
#line 1919 "parser.tab.c"
    break;

  case 63: /* expressao: CHAR  */
#line 478 "parser.y"
    { 
        (yyval.no) = criar_no("CHAR", (yyvsp[0].sval));
    }
#line 1927 "parser.tab.c"
    break;

  case 64: /* expressao: ID '[' expressao ']'  */
#line 482 "parser.y"
    {
        (yyval.no) = criar_no("ACESSO_VETOR", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1936 "parser.tab.c"
    break;

  case 65: /* expressao: expressao '+' expressao  */
#line 487 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "+");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1946 "parser.tab.c"
    break;

  case 66: /* expressao: expressao '-' expressao  */
#line 493 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "-");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1956 "parser.tab.c"
    break;

  case 67: /* expressao: expressao '*' expressao  */
#line 499 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "*");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1966 "parser.tab.c"
    break;

  case 68: /* expressao: expressao '/' expressao  */
#line 505 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "/");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1976 "parser.tab.c"
    break;

  case 69: /* expressao: expressao MAIOR expressao  */
#line 511 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1986 "parser.tab.c"
    break;

  case 70: /* expressao: expressao MENOR expressao  */
#line 517 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1996 "parser.tab.c"
    break;

  case 71: /* expressao: '(' expressao ')'  */
#line 523 "parser.y"
    {
        (yyval.no) = (yyvsp[-1].no);
    }
#line 2004 "parser.tab.c"
    break;

  case 72: /* expressao: '-' expressao  */
#line 527 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_UNARIO", "-");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2013 "parser.tab.c"
    break;

  case 73: /* expressao: expressao IGUAL expressao  */
#line 532 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "==");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2023 "parser.tab.c"
    break;

  case 74: /* expressao: expressao DIFERENTE expressao  */
#line 538 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2033 "parser.tab.c"
    break;

  case 75: /* expressao: expressao MENOR_IGUAL expressao  */
#line 544 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2043 "parser.tab.c"
    break;

  case 76: /* expressao: expressao MAIOR_IGUAL expressao  */
#line 550 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2053 "parser.tab.c"
    break;

  case 77: /* expressao: expressao E expressao  */
#line 556 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "&&");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2063 "parser.tab.c"
    break;

  case 78: /* expressao: expressao OU expressao  */
#line 562 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "||");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2073 "parser.tab.c"
    break;

  case 79: /* expressao: NAO expressao  */
#line 568 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2082 "parser.tab.c"
    break;

  case 80: /* expressao: INC expressao  */
#line 573 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "++");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2091 "parser.tab.c"
    break;

  case 81: /* expressao: DEC expressao  */
#line 578 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "--");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2100 "parser.tab.c"
    break;

  case 82: /* expressao: expressao INC  */
#line 583 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "++");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2109 "parser.tab.c"
    break;

  case 83: /* expressao: expressao DEC  */
#line 588 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "--");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2118 "parser.tab.c"
    break;


#line 2122 "parser.tab.c"

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

#line 594 "parser.y"


//ARVORE
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

//TABELA

TabelaSimbolos* criar_tabela_simbolos() {
    TabelaSimbolos* t = (TabelaSimbolos*)malloc(sizeof(TabelaSimbolos));
    t->capacidade = 100;
    t->quantidade = 0;
    t->entradas = (SimboloEntrada*)malloc(sizeof(SimboloEntrada) * t->capacidade);
    return t;
}

void adicionar_simbolo(TabelaSimbolos* t, const char* nome, const char* tipo, const char* categoria, int linha) {
    if(t->quantidade >= t->capacidade) {
        t->capacidade *= 2;
        t->entradas = (SimboloEntrada*)realloc(t->entradas, sizeof(SimboloEntrada) * t->capacidade);
    }

    SimboloEntrada* novo = &t->entradas[t->quantidade];
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->categoria = strdup(categoria);
    novo->linha = linha;
    t->quantidade++;
}

void imprimir_tabela(TabelaSimbolos* t) {
    printf("\n=== Tabela de Símbolos ===\n");
    printf("%-15s %-10s %-12s %-8s\n", 
           "Nome", "Tipo", "Categoria", "Linha");
    printf("----------------------------------------\n");
    
    for(int i = 0; i < t->quantidade; i++) {
        printf("%-15s %-10s %-12s %-8d\n",
               t->entradas[i].nome,
               t->entradas[i].tipo,
               t->entradas[i].categoria,
               t->entradas[i].linha);
    }
    printf("\n");
}

void liberar_tabela(TabelaSimbolos* t) {
    for(int i = 0; i < t->quantidade; i++) {
        free(t->entradas[i].nome);
        free(t->entradas[i].tipo);
        free(t->entradas[i].categoria);
    }
    free(t->entradas);
    free(t);
}

// Funções da análise semântica
void erro_semantico(const char* msg, int linha) {
    fprintf(stderr, "Erro semântico na linha %d: %s\n", linha, msg);
    erros_semanticos++;
}

// Funções de escopo
Escopo* criar_escopo() {
    Escopo* novo = (Escopo*)malloc(sizeof(Escopo));
    novo->tabela = criar_tabela_simbolos();
    novo->pai = escopo_atual;
    escopo_atual = novo;
    return novo;
}

void liberar_escopo() {
    if (escopo_atual) {
        Escopo* temp = escopo_atual;
        escopo_atual = escopo_atual->pai;
        liberar_tabela(temp->tabela);
        free(temp);
    }
}

// Verificações semânticas principais
void verificar_declaracao_duplicada(TabelaSimbolos* tabela, const char* nome, int linha) {
    for (int i = 0; i < tabela->quantidade; i++) {
        if (strcmp(tabela->entradas[i].nome, nome) == 0) {
            char msg[100];
            sprintf(msg, "Identificador '%s' já declarado", nome);
            erro_semantico(msg, linha);
            return;
        }
    }
}

bool verificar_variavel_declarada(TabelaSimbolos* tabela, const char* nome) {
    Escopo* atual = escopo_atual;
    while (atual) {
        for (int i = 0; i < atual->tabela->quantidade; i++) {
            if (strcmp(atual->tabela->entradas[i].nome, nome) == 0) {
                return true;
            }
        }
        atual = atual->pai;
    }
    return false;
}

bool verificar_compatibilidade_tipos(const char* tipo1, const char* tipo2) {
    if (strcmp(tipo1, tipo2) == 0) return true;
    if (strcmp(tipo1, "float") == 0 && strcmp(tipo2, "int") == 0) return true;
    return false;
}

bool is_tipo_numerico(const char* tipo) {
    return (strcmp(tipo, "int") == 0 || strcmp(tipo, "float") == 0);
}

const char* inferir_tipo_expressao(No* expressao) {
    if (!expressao) return NULL;

    if (strcmp(expressao->tipo, "NUM_INT") == 0) return "int";
    if (strcmp(expressao->tipo, "NUM_FLOAT") == 0) return "float";
    if (strcmp(expressao->tipo, "CHAR") == 0) return "char";
    if (strcmp(expressao->tipo, "STRING") == 0) return "string";
    
    if (strcmp(expressao->tipo, "ID") == 0) {
        Escopo* atual = escopo_atual;
        while (atual) {
            for (int i = 0; i < atual->tabela->quantidade; i++) {
                if (strcmp(atual->tabela->entradas[i].nome, expressao->valor) == 0) {
                    return atual->tabela->entradas[i].tipo;
                }
            }
            atual = atual->pai;
        }
    }
    return NULL;
}

void verificar_tipo_operacao(No* no) {
    if (!no || !no->tipo) return;

    if (strcmp(no->tipo, "OPERADOR") == 0) {
        const char* tipo_esq = inferir_tipo_expressao(no->filhos[0]);
        const char* tipo_dir = inferir_tipo_expressao(no->filhos[1]);

        if (strcmp(no->valor, "+") == 0 || 
            strcmp(no->valor, "-") == 0 || 
            strcmp(no->valor, "*") == 0 || 
            strcmp(no->valor, "/") == 0) {
            if (!is_tipo_numerico(tipo_esq) || !is_tipo_numerico(tipo_dir)) {
                erro_semantico("Operação aritmética requer tipos numéricos", linha);
            }
        }
        else if (strcmp(no->valor, ">") == 0 || 
                 strcmp(no->valor, "<") == 0 || 
                 strcmp(no->valor, ">=") == 0 || 
                 strcmp(no->valor, "<=") == 0) {
            if (!is_tipo_numerico(tipo_esq) || !is_tipo_numerico(tipo_dir)) {
                erro_semantico("Comparação requer tipos numéricos", linha);
            }
        }
        else if (strcmp(no->valor, "==") == 0 || strcmp(no->valor, "!=") == 0) {
            if (!verificar_compatibilidade_tipos(tipo_esq, tipo_dir)) {
                erro_semantico("Comparação entre tipos incompatíveis", linha);
            }
        }
    }
}

void verificar_acesso_vetor(No* no) {
    if (!no || strcmp(no->tipo, "ACESSO_VETOR") != 0) return;
    const char* tipo_indice = inferir_tipo_expressao(no->filhos[0]);
    if (strcmp(tipo_indice, "int") != 0) {
        erro_semantico("Índice de vetor deve ser do tipo inteiro", linha);
    }
}

void iniciar_analise_semantica(No* raiz) {
    if (!raiz) return;
    
    criar_escopo();
    
    // Verifica funções básicas necessárias (main)
    if (!verificar_variavel_declarada(escopo_atual->tabela, "main")) {
        erro_semantico("Função 'main' não declarada", 0);
    }
    
    liberar_escopo();
}

//MAIN
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
    
    // Cria a tabela de símbolos
    tabela = criar_tabela_simbolos();
    
    printf("\n=== Iniciando análise ===\n");
    yyparse();
    
    printf("\n=== Resumo da análise ===\n");
    if (erros_lexicos > 0) {
        printf("Total de erros léxicos: %d\n", erros_lexicos);
        printf("O código contém caracteres ou tokens inválidos.\n");
    }
    if (erros_sintaticos > 0) {
        printf("Total de erros sintáticos: %d\n", erros_sintaticos);
        printf("O código contém estruturas sintáticas inválidas.\n");
    }
    if (erros_semanticos > 0) {
        printf("Total de erros semânticos: %d\n", erros_semanticos);
    }
    
    if (erros_lexicos == 0 && erros_sintaticos == 0 && erros_semanticos == 0) {
        printf("\nCódigo analisado com sucesso!\n");
        printf("\nÁrvore Sintática:\n");
        if (raiz != NULL) {
            imprimir_arvore(raiz, 0);
        }
        // Imprime a tabela de símbolos
        imprimir_tabela(tabela);
    }
    
    // Libera memória
    liberar_tabela(tabela);
    liberar_arvore(raiz);
    fclose(arquivo);
    return (erros_lexicos + erros_sintaticos + erros_semanticos) > 0 ? 1 : 0;
}
