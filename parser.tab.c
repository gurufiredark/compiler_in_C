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
    int linha;
    struct No* pai;
    struct No** filhos;
    int verificado;
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

//funções semânticas
void erro_semantico(const char* msg, int linha);
void verificar_declaracao_duplicada(TabelaSimbolos* tabela, const char* nome, int linha);
bool verificar_variavel_declarada(TabelaSimbolos* tabela, const char* nome);
void verificar_tipo_operacao(No* no);
bool verificar_compatibilidade_tipos(const char* tipo1, const char* tipo2);
bool is_tipo_numerico(const char* tipo);
const char* inferir_tipo_expressao(No* expressao);
void verificar_acesso_vetor(No* no);
void iniciar_analise_semantica(No* raiz);

extern int linha;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);
int yylex();

No* raiz = NULL;


#line 146 "parser.tab.c"

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
  YYSYMBOL_return_stmt = 69,               /* return_stmt  */
  YYSYMBOL_comando_print = 70,             /* comando_print  */
  YYSYMBOL_string_interpolada = 71,        /* string_interpolada  */
  YYSYMBOL_partes_string = 72,             /* partes_string  */
  YYSYMBOL_parte_string = 73,              /* parte_string  */
  YYSYMBOL_comando_scan = 74,              /* comando_scan  */
  YYSYMBOL_comando_if = 75,                /* comando_if  */
  YYSYMBOL_comando_while = 76,             /* comando_while  */
  YYSYMBOL_comando_for = 77,               /* comando_for  */
  YYSYMBOL_atribuicao_for = 78,            /* atribuicao_for  */
  YYSYMBOL_atribuicao = 79,                /* atribuicao  */
  YYSYMBOL_expressao = 80                  /* expressao  */
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
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

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
       0,   118,   118,   129,   132,   140,   149,   154,   162,   166,
     173,   179,   187,   195,   205,   209,   213,   217,   221,   228,
     236,   247,   250,   258,   263,   271,   279,   287,   290,   296,
     305,   306,   307,   308,   309,   310,   311,   315,   323,   328,
     333,   340,   347,   352,   360,   368,   373,   381,   385,   393,
     398,   407,   413,   423,   432,   443,   449,   458,   464,   471,
     480,   486,   492,   496,   500,   504,   509,   515,   521,   527,
     533,   539,   545,   549,   554,   560,   566,   572,   578,   584,
     590,   595,   600,   605,   610
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
  "return_stmt", "comando_print", "string_interpolada", "partes_string",
  "parte_string", "comando_scan", "comando_if", "comando_while",
  "comando_for", "atribuicao_for", "atribuicao", "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -66,    27,    16,   -66,   -66,   -66,   -66,   -66,   -66,    30,
     -66,   -66,   198,   -66,    46,   -66,    40,   -66,    22,   -41,
      66,    43,   198,   -66,    -1,    47,    41,    74,    62,   -66,
      59,    61,    -5,    99,   454,   -66,   -66,    41,   198,    78,
     117,   -66,   100,    98,   109,   110,   140,   111,   123,   -34,
     454,   122,    91,   454,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   104,   -66,   140,   140,    71,   -66,
     -66,   -66,   -66,   119,   140,   140,   140,   140,   140,   168,
      64,   148,   145,   140,   -66,   -43,   -66,   -66,   -66,   276,
     300,   135,   153,   130,   140,     0,     0,     0,     0,   324,
     140,   140,   140,   140,   140,   140,   140,   140,   -66,   -66,
     140,   140,   140,   140,   -66,   134,   136,   137,   138,   141,
      37,   142,   -19,   150,   195,    29,    41,    41,   140,   173,
     140,    77,   -66,   447,   447,    82,    82,    82,    82,   414,
     393,   108,   108,     0,     0,   158,   164,   165,   166,   167,
     -66,   204,   154,    37,   180,   181,   140,   -66,   -66,   192,
     223,   -66,   372,   140,   222,   -66,   -66,   -66,   -66,   -66,
     -66,   194,   -66,   -66,   -66,   -66,   106,   140,    41,   372,
     140,   -66,   188,   249,   -66,   348,   190,   -66,    41,   -66,
     -66
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
      27,     0,     0,    27,    36,    34,    35,    31,    32,    33,
      30,    19,    24,    11,     0,     5,     0,     0,     0,    60,
      61,    63,    64,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,    26,    28,    13,     0,
       0,     0,     0,     0,     0,    80,    81,    82,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    74,    75,    71,    70,    76,    77,    78,
      79,    66,    67,    68,    69,     0,     0,     0,     0,     0,
      47,     0,     0,    45,     0,     0,     0,    59,    57,     0,
      51,    53,    55,     0,     0,    65,    40,    41,    42,    43,
      39,     0,    44,    46,    38,    49,     0,     0,     0,    56,
       0,    48,     0,     0,    52,     0,     0,    58,     0,    50,
      54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   227,   -66,    84,    12,   -66,   -66,
     202,   -66,   -37,   -25,   -66,   -66,   -66,   -66,    88,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    12,    50,    51,    15,    28,
      29,    30,    35,    52,    53,    54,    55,   121,   152,   153,
      56,    57,    58,    59,    93,    60,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    89,    90,    22,    82,    23,    24,    23,    24,    95,
      96,    97,    98,    99,    14,    83,    31,   124,   125,     4,
       5,     6,     7,     8,    14,    84,   155,     3,    87,   131,
     156,   108,   109,    40,    27,   133,   134,   135,   136,   137,
     138,   139,   140,    41,    16,   141,   142,   143,   144,    32,
      27,   100,   101,   102,   103,   104,   105,   106,   107,    18,
     108,   109,     9,   162,    20,   164,    21,    19,   110,   111,
     112,   113,   150,   151,     4,     5,     6,     7,     8,   159,
      92,   115,   116,   117,   118,   119,    13,    25,    26,   160,
     161,   176,    91,    34,    33,    36,    13,   120,   179,   100,
     101,   102,   103,   104,   105,   106,   107,    37,   108,   109,
      38,    39,   183,   108,   109,   185,   110,   111,   112,   113,
      42,   110,   111,   112,   113,    65,    63,   165,   100,   101,
     102,   103,   104,   105,   106,   107,    64,   108,   109,   108,
     109,   184,    66,    85,    86,   110,   111,   112,   113,   112,
     113,   190,    88,    67,    68,    80,   182,    69,    70,    71,
      72,    73,    69,    70,   123,    72,    73,    81,    94,   122,
      74,    75,    76,   128,   129,    74,    75,    76,   130,   145,
      77,   146,   147,   148,    78,    77,   149,   154,   172,    78,
     100,   101,   102,   103,   104,   105,   106,   107,   157,   108,
     109,     4,     5,     6,     7,     8,   166,   110,   111,   112,
     113,   163,   167,   168,   169,   170,   114,   100,   101,   102,
     103,   104,   105,   106,   107,   171,   108,   109,   174,   175,
     177,   181,   178,   186,   110,   111,   112,   113,   189,    17,
      62,   173,     0,   158,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,     0,     0,     0,     0,     0,
     180,   100,   101,   102,   103,   104,   105,   106,   107,     0,
     108,   109,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   187,   100,   101,
     102,   103,   104,   105,   106,   107,     0,   108,   109,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,     0,
       0,   126,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,   109,     0,     0,     0,     0,     0,     0,   110,
     111,   112,   113,     0,     0,   127,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,   109,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,     0,     0,   132,
     100,   101,   102,   103,   104,   105,   106,   107,     0,   108,
     109,     0,     0,     0,     0,     0,     0,   110,   111,   112,
     113,     0,     0,   188,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,   109,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   100,   101,   102,   103,   104,
     105,   106,     0,     0,   108,   109,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   100,   101,   102,   103,
     104,   105,     0,     0,     0,   108,   109,     0,     0,     0,
       0,     0,     0,   110,   111,   112,   113,     4,     5,     6,
       7,     8,    43,     0,    44,    45,    46,     0,     0,    47,
      48,   102,   103,   104,   105,    49,     0,     0,   108,   109,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
      37,    66,    67,    44,    38,    48,    49,    48,    49,    74,
      75,    76,    77,    78,     2,    49,    17,    82,    83,     3,
       4,     5,     6,     7,    12,    50,    45,     0,    53,    94,
      49,    31,    32,    38,    22,   100,   101,   102,   103,   104,
     105,   106,   107,    48,    14,   110,   111,   112,   113,    50,
      38,    22,    23,    24,    25,    26,    27,    28,    29,    13,
      31,    32,    46,   128,    24,   130,    44,    21,    39,    40,
      41,    42,    35,    36,     3,     4,     5,     6,     7,    50,
      68,    17,    18,    19,    20,    21,     2,    21,    45,   126,
     127,   156,    21,    52,    47,    21,    12,    33,   163,    22,
      23,    24,    25,    26,    27,    28,    29,    45,    31,    32,
      51,    50,   177,    31,    32,   180,    39,    40,    41,    42,
      21,    39,    40,    41,    42,    25,    48,    50,    22,    23,
      24,    25,    26,    27,    28,    29,    19,    31,    32,    31,
      32,   178,    44,    21,    53,    39,    40,    41,    42,    41,
      42,   188,    48,    44,    44,    44,    50,    17,    18,    19,
      20,    21,    17,    18,    19,    20,    21,    44,    49,    21,
      30,    31,    32,    38,    21,    30,    31,    32,    48,    45,
      40,    45,    45,    45,    44,    40,    45,    45,    34,    44,
      22,    23,    24,    25,    26,    27,    28,    29,    48,    31,
      32,     3,     4,     5,     6,     7,    48,    39,    40,    41,
      42,    38,    48,    48,    48,    48,    48,    22,    23,    24,
      25,    26,    27,    28,    29,    21,    31,    32,    48,    48,
      38,    37,     9,    45,    39,    40,    41,    42,    48,    12,
      38,   153,    -1,    48,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    45,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    45,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    45,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    45,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    -1,    -1,    15,
      16,    24,    25,    26,    27,    21,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42
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
      60,    61,    67,    68,    69,    70,    74,    75,    76,    77,
      79,    66,    64,    48,    19,    25,    44,    44,    44,    17,
      18,    19,    20,    21,    30,    31,    32,    40,    44,    80,
      44,    44,    38,    49,    67,    21,    53,    67,    48,    80,
      80,    21,    61,    78,    49,    80,    80,    80,    80,    80,
      22,    23,    24,    25,    26,    27,    28,    29,    31,    32,
      39,    40,    41,    42,    48,    17,    18,    19,    20,    21,
      33,    71,    21,    19,    80,    80,    45,    45,    38,    21,
      48,    80,    45,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    45,    45,    45,    45,    45,
      35,    36,    72,    73,    45,    45,    49,    48,    48,    50,
      66,    66,    80,    38,    80,    50,    48,    48,    48,    48,
      48,    21,    34,    72,    48,    48,    80,    38,     9,    80,
      48,    37,    50,    80,    66,    80,    45,    48,    45,    48,
      66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     7,     1,     2,     1,     1,
       3,     6,     5,     7,     1,     1,     1,     1,     1,     6,
       5,     0,     1,     1,     3,     2,     3,     0,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     5,
       5,     5,     5,     5,     3,     1,     2,     1,     3,     5,
       8,     5,     7,     5,     9,     3,     4,     4,     7,     4,
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
#line 119 "parser.y"
    {
        (yyval.no) = criar_no("PROGRAMA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        raiz = (yyval.no);
    }
#line 1401 "parser.tab.c"
    break;

  case 3: /* includes: %empty  */
#line 129 "parser.y"
    {
        (yyval.no) = criar_no("INCLUDES", "");
    }
#line 1409 "parser.tab.c"
    break;

  case 4: /* includes: includes include_stmt  */
#line 133 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1418 "parser.tab.c"
    break;

  case 5: /* include_stmt: '#' INCLUDE MENOR ID '.' ID MAIOR  */
#line 141 "parser.y"
    {
        char include_name[100];
        sprintf(include_name, "%s.%s", (yyvsp[-3].sval), (yyvsp[-1].sval));
        (yyval.no) = criar_no("INCLUDE", include_name);
    }
#line 1428 "parser.tab.c"
    break;

  case 6: /* declaracoes: declaracao  */
#line 150 "parser.y"
    { 
        (yyval.no) = criar_no("DECLARACOES", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1437 "parser.tab.c"
    break;

  case 7: /* declaracoes: declaracao declaracoes  */
#line 155 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1446 "parser.tab.c"
    break;

  case 8: /* declaracao: declaracao_variavel  */
#line 163 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1454 "parser.tab.c"
    break;

  case 9: /* declaracao: declaracao_funcao  */
#line 167 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1462 "parser.tab.c"
    break;

  case 10: /* declaracao_variavel: tipo ID ';'  */
#line 174 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-1].sval));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_simbolo(tabela, (yyvsp[-1].sval), (yyvsp[-2].no)->valor, "variavel", linha);
    }
#line 1472 "parser.tab.c"
    break;

  case 11: /* declaracao_variavel: tipo ID '[' NUM_INT ']' ';'  */
#line 180 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[%d]", (yyvsp[-4].sval), (yyvsp[-2].ival));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), (yyvsp[-5].no)->valor, "variavel", linha);
    }
#line 1484 "parser.tab.c"
    break;

  case 12: /* declaracao_variavel: tipo ID '[' ']' ';'  */
#line 188 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[]", (yyvsp[-3].sval));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_simbolo(tabela, (yyvsp[-3].sval), (yyvsp[-4].no)->valor, "variavel", linha);
    }
#line 1496 "parser.tab.c"
    break;

  case 13: /* declaracao_variavel: tipo ID '[' ']' '=' STRING ';'  */
#line 196 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_STRING", (yyvsp[-5].sval));
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
        adicionar_simbolo(tabela, (yyvsp[-5].sval), (yyvsp[-6].no)->valor, "variavel", linha);
    }
#line 1507 "parser.tab.c"
    break;

  case 14: /* tipo: TIPO_INT  */
#line 206 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "int");
    }
#line 1515 "parser.tab.c"
    break;

  case 15: /* tipo: TIPO_FLOAT  */
#line 210 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "float");
    }
#line 1523 "parser.tab.c"
    break;

  case 16: /* tipo: TIPO_CHAR  */
#line 214 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "char");
    }
#line 1531 "parser.tab.c"
    break;

  case 17: /* tipo: TIPO_STRING  */
#line 218 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "string");
    }
#line 1539 "parser.tab.c"
    break;

  case 18: /* tipo: VOID  */
#line 222 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "void");
    }
#line 1547 "parser.tab.c"
    break;

  case 19: /* declaracao_funcao: tipo ID '(' parametros ')' bloco  */
#line 229 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", (yyvsp[-4].sval));
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), (yyvsp[-5].no)->valor, "funcao", linha);
    }
#line 1559 "parser.tab.c"
    break;

  case 20: /* declaracao_funcao: tipo MAIN '(' ')' bloco  */
#line 237 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", "main");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, "main", (yyvsp[-4].no)->valor, "funcao", linha);
    }
#line 1570 "parser.tab.c"
    break;

  case 21: /* parametros: %empty  */
#line 247 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
    }
#line 1578 "parser.tab.c"
    break;

  case 22: /* parametros: lista_parametros  */
#line 251 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1587 "parser.tab.c"
    break;

  case 23: /* lista_parametros: parametro  */
#line 259 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1596 "parser.tab.c"
    break;

  case 24: /* lista_parametros: parametro ',' lista_parametros  */
#line 264 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1605 "parser.tab.c"
    break;

  case 25: /* parametro: tipo ID  */
#line 272 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETRO", (yyvsp[0].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1614 "parser.tab.c"
    break;

  case 26: /* bloco: '{' comandos '}'  */
#line 280 "parser.y"
    {
        (yyval.no) = criar_no("BLOCO", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1623 "parser.tab.c"
    break;

  case 27: /* comandos: %empty  */
#line 287 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
    }
#line 1631 "parser.tab.c"
    break;

  case 28: /* comandos: comando comandos  */
#line 291 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1641 "parser.tab.c"
    break;

  case 29: /* comandos: declaracao_variavel comandos  */
#line 297 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1651 "parser.tab.c"
    break;

  case 30: /* comando: atribuicao  */
#line 305 "parser.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1657 "parser.tab.c"
    break;

  case 31: /* comando: comando_if  */
#line 306 "parser.y"
                 { (yyval.no) = (yyvsp[0].no); }
#line 1663 "parser.tab.c"
    break;

  case 32: /* comando: comando_while  */
#line 307 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1669 "parser.tab.c"
    break;

  case 33: /* comando: comando_for  */
#line 308 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1675 "parser.tab.c"
    break;

  case 34: /* comando: comando_print  */
#line 309 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1681 "parser.tab.c"
    break;

  case 35: /* comando: comando_scan  */
#line 310 "parser.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1687 "parser.tab.c"
    break;

  case 36: /* comando: return_stmt  */
#line 311 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1693 "parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN expressao ';'  */
#line 316 "parser.y"
    {
        (yyval.no) = criar_no("RETURN", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1702 "parser.tab.c"
    break;

  case 38: /* comando_print: PRINT '(' string_interpolada ')' ';'  */
#line 324 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1711 "parser.tab.c"
    break;

  case 39: /* comando_print: PRINT '(' ID ')' ';'  */
#line 329 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1720 "parser.tab.c"
    break;

  case 40: /* comando_print: PRINT '(' NUM_INT ')' ';'  */
#line 334 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[-2].ival));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_INT", valor));
    }
#line 1731 "parser.tab.c"
    break;

  case 41: /* comando_print: PRINT '(' NUM_FLOAT ')' ';'  */
#line 341 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[-2].fval));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_FLOAT", valor));
    }
#line 1742 "parser.tab.c"
    break;

  case 42: /* comando_print: PRINT '(' STRING ')' ';'  */
#line 348 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-2].sval)));
    }
#line 1751 "parser.tab.c"
    break;

  case 43: /* comando_print: PRINT '(' CHAR ')' ';'  */
#line 353 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("CHAR", (yyvsp[-2].sval)));
    }
#line 1760 "parser.tab.c"
    break;

  case 44: /* string_interpolada: STRING_START partes_string STRING_END  */
#line 361 "parser.y"
    {
        (yyval.no) = criar_no("STRING_INTERPOLADA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1769 "parser.tab.c"
    break;

  case 45: /* partes_string: parte_string  */
#line 369 "parser.y"
    {
        (yyval.no) = criar_no("PARTES_STRING", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1778 "parser.tab.c"
    break;

  case 46: /* partes_string: parte_string partes_string  */
#line 374 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1787 "parser.tab.c"
    break;

  case 47: /* parte_string: STRING_TEXT  */
#line 382 "parser.y"
    {
        (yyval.no) = criar_no("TEXTO", (yyvsp[0].sval));
    }
#line 1795 "parser.tab.c"
    break;

  case 48: /* parte_string: INTERPOLACAO_START ID INTERPOLACAO_END  */
#line 386 "parser.y"
    {
        (yyval.no) = criar_no("INTERPOLACAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-1].sval)));
    }
#line 1804 "parser.tab.c"
    break;

  case 49: /* comando_scan: SCAN '(' ID ')' ';'  */
#line 394 "parser.y"
    {
        (yyval.no) = criar_no("SCAN", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1813 "parser.tab.c"
    break;

  case 50: /* comando_scan: SCAN '(' ID '[' expressao ']' ')' ';'  */
#line 399 "parser.y"
    {
        (yyval.no) = criar_no("SCAN_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-5].sval)));
        adicionar_filho((yyval.no), (yyvsp[-3].no));  /* índice do vetor */
    }
#line 1823 "parser.tab.c"
    break;

  case 51: /* comando_if: IF '(' expressao ')' bloco  */
#line 408 "parser.y"
    {
        (yyval.no) = criar_no("IF", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1833 "parser.tab.c"
    break;

  case 52: /* comando_if: IF '(' expressao ')' bloco ELSE bloco  */
#line 414 "parser.y"
    {
        (yyval.no) = criar_no("IF_ELSE", "");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1844 "parser.tab.c"
    break;

  case 53: /* comando_while: WHILE '(' expressao ')' bloco  */
#line 424 "parser.y"
    {
        (yyval.no) = criar_no("WHILE", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1854 "parser.tab.c"
    break;

  case 54: /* comando_for: FOR '(' atribuicao_for ';' expressao ';' expressao ')' bloco  */
#line 433 "parser.y"
    { 
        (yyval.no) = criar_no("FOR", "");
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1866 "parser.tab.c"
    break;

  case 55: /* atribuicao_for: ID '=' expressao  */
#line 444 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1876 "parser.tab.c"
    break;

  case 56: /* atribuicao_for: tipo ID '=' expressao  */
#line 450 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1886 "parser.tab.c"
    break;

  case 57: /* atribuicao: ID '=' expressao ';'  */
#line 459 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1896 "parser.tab.c"
    break;

  case 58: /* atribuicao: ID '[' expressao ']' '=' expressao ';'  */
#line 465 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-6].sval)));
        adicionar_filho((yyval.no), (yyvsp[-4].no));  // índice
        adicionar_filho((yyval.no), (yyvsp[-1].no));  // valor
    }
#line 1907 "parser.tab.c"
    break;

  case 59: /* atribuicao: ID '=' STRING ';'  */
#line 472 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_STRING", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
    }
#line 1917 "parser.tab.c"
    break;

  case 60: /* expressao: NUM_INT  */
#line 481 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        (yyval.no) = criar_no("NUM_INT", valor);
    }
#line 1927 "parser.tab.c"
    break;

  case 61: /* expressao: NUM_FLOAT  */
#line 487 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        (yyval.no) = criar_no("NUM_FLOAT", valor);
    }
#line 1937 "parser.tab.c"
    break;

  case 62: /* expressao: ID  */
#line 493 "parser.y"
    { 
        (yyval.no) = criar_no("ID", (yyvsp[0].sval));
    }
#line 1945 "parser.tab.c"
    break;

  case 63: /* expressao: STRING  */
#line 497 "parser.y"
    { 
        (yyval.no) = criar_no("STRING", (yyvsp[0].sval));
    }
#line 1953 "parser.tab.c"
    break;

  case 64: /* expressao: CHAR  */
#line 501 "parser.y"
    { 
        (yyval.no) = criar_no("CHAR", (yyvsp[0].sval));
    }
#line 1961 "parser.tab.c"
    break;

  case 65: /* expressao: ID '[' expressao ']'  */
#line 505 "parser.y"
    {
        (yyval.no) = criar_no("ACESSO_VETOR", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1970 "parser.tab.c"
    break;

  case 66: /* expressao: expressao '+' expressao  */
#line 510 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "+");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1980 "parser.tab.c"
    break;

  case 67: /* expressao: expressao '-' expressao  */
#line 516 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "-");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1990 "parser.tab.c"
    break;

  case 68: /* expressao: expressao '*' expressao  */
#line 522 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "*");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2000 "parser.tab.c"
    break;

  case 69: /* expressao: expressao '/' expressao  */
#line 528 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "/");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2010 "parser.tab.c"
    break;

  case 70: /* expressao: expressao MAIOR expressao  */
#line 534 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2020 "parser.tab.c"
    break;

  case 71: /* expressao: expressao MENOR expressao  */
#line 540 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2030 "parser.tab.c"
    break;

  case 72: /* expressao: '(' expressao ')'  */
#line 546 "parser.y"
    {
        (yyval.no) = (yyvsp[-1].no);
    }
#line 2038 "parser.tab.c"
    break;

  case 73: /* expressao: '-' expressao  */
#line 550 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_UNARIO", "-");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2047 "parser.tab.c"
    break;

  case 74: /* expressao: expressao IGUAL expressao  */
#line 555 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "==");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2057 "parser.tab.c"
    break;

  case 75: /* expressao: expressao DIFERENTE expressao  */
#line 561 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2067 "parser.tab.c"
    break;

  case 76: /* expressao: expressao MENOR_IGUAL expressao  */
#line 567 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2077 "parser.tab.c"
    break;

  case 77: /* expressao: expressao MAIOR_IGUAL expressao  */
#line 573 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2087 "parser.tab.c"
    break;

  case 78: /* expressao: expressao E expressao  */
#line 579 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "&&");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2097 "parser.tab.c"
    break;

  case 79: /* expressao: expressao OU expressao  */
#line 585 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "||");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2107 "parser.tab.c"
    break;

  case 80: /* expressao: NAO expressao  */
#line 591 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2116 "parser.tab.c"
    break;

  case 81: /* expressao: INC expressao  */
#line 596 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "++");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2125 "parser.tab.c"
    break;

  case 82: /* expressao: DEC expressao  */
#line 601 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "--");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2134 "parser.tab.c"
    break;

  case 83: /* expressao: expressao INC  */
#line 606 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "++");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2143 "parser.tab.c"
    break;

  case 84: /* expressao: expressao DEC  */
#line 611 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "--");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2152 "parser.tab.c"
    break;


#line 2156 "parser.tab.c"

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

#line 617 "parser.y"


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
    no->linha = linha;
    no->pai = NULL;
    no->filhos = NULL;
    no->verificado = 0;
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
    filho->pai = pai; 
}

void imprimir_arvore(No* no, int nivel) {
    if (no == NULL) {
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
        if (strcmp(tabela->entradas[i].nome, nome) == 0 && 
            linha > tabela->entradas[i].linha) {  // Verifica se é uma declaração posterior
            char msg[100];
            sprintf(msg, "Identificador '%s' já declarado", nome);
            erro_semantico(msg, linha);
            return;
        }
    }
}

bool verificar_variavel_declarada(TabelaSimbolos* tabela, const char* nome) {
    // Primeiro verifica na tabela atual
    for (int i = 0; i < tabela->quantidade; i++) {
        if (strcmp(tabela->entradas[i].nome, nome) == 0) {
            return true;
        }
    }
    return false;
}

bool verificar_compatibilidade_tipos(const char* tipo1, const char* tipo2) {
    // Tipos devem ser exatamente iguais
    if (strcmp(tipo1, tipo2) == 0) 
        return true;
    
    // Vetores do mesmo tipo são compatíveis
    if (strstr(tipo1, "[]") != NULL && strstr(tipo2, "[]") != NULL) {
        char base1[32], base2[32];
        strncpy(base1, tipo1, strchr(tipo1, '[') - tipo1);
        strncpy(base2, tipo2, strchr(tipo2, '[') - tipo2);
        base1[strchr(tipo1, '[') - tipo1] = '\0';
        base2[strchr(tipo2, '[') - tipo2] = '\0';
        return strcmp(base1, base2) == 0;
    }

    // Se chegou aqui, os tipos não são compatíveis
    return false;
}

bool is_tipo_numerico(const char* tipo) {
    return (strcmp(tipo, "int") == 0 || strcmp(tipo, "float") == 0);
}

const char* inferir_tipo_expressao(No* expressao) {
    if (!expressao) {
        return NULL;
    }

    // Para literais numéricos
    if (strcmp(expressao->tipo, "NUM_INT") == 0) return "int";
    if (strcmp(expressao->tipo, "NUM_FLOAT") == 0) return "float";
    if (strcmp(expressao->tipo, "CHAR") == 0) return "char";
    if (strcmp(expressao->tipo, "STRING") == 0) return "string";
    
    // Para identificadores
    if (strcmp(expressao->tipo, "ID") == 0) {
        for (int i = 0; i < tabela->quantidade; i++) {
            if (strcmp(tabela->entradas[i].nome, expressao->valor) == 0) {
                return tabela->entradas[i].tipo;
            }
        }
        
        return NULL;
    }

    // Para operadores
    if (strcmp(expressao->tipo, "OPERADOR") == 0) {
        const char* tipo_esq = inferir_tipo_expressao(expressao->filhos[0]);
        const char* tipo_dir = inferir_tipo_expressao(expressao->filhos[1]);
        
        if (strcmp(expressao->valor, "==") == 0 || 
            strcmp(expressao->valor, "!=") == 0 ||
            strcmp(expressao->valor, ">") == 0 || 
            strcmp(expressao->valor, "<") == 0 || 
            strcmp(expressao->valor, ">=") == 0 || 
            strcmp(expressao->valor, "<=") == 0) {
            return "int";  // Comparações sempre retornam int
        }
        
        if (tipo_esq && tipo_dir) {
            if (strcmp(tipo_esq, "int") == 0 && strcmp(tipo_dir, "int") == 0) return "int";
            if (strcmp(tipo_esq, "float") == 0 || strcmp(tipo_dir, "float") == 0) return "float";
        }
    }

    return NULL;
}

void verificar_tipo_operacao(No* no) {
    if (!no || !no->tipo) return;

    if (strcmp(no->tipo, "OPERADOR") == 0 && !no->verificado) {
        no->verificado = 1;
        const char* tipo_esq = inferir_tipo_expressao(no->filhos[0]);
        const char* tipo_dir = inferir_tipo_expressao(no->filhos[1]);

        // Verifica strings em comparações relacionais
        if (tipo_dir && strcmp(tipo_dir, "string") == 0) {
            if (strcmp(no->valor, "<") == 0 || 
                strcmp(no->valor, ">") == 0 || 
                strcmp(no->valor, "<=") == 0 || 
                strcmp(no->valor, ">=") == 0) {
                erro_semantico("Não é possível usar string em comparação relacional", no->linha);
                return;
            }
            else if (strcmp(no->valor, "==") == 0 || strcmp(no->valor, "!=") == 0) {
                if (tipo_esq && is_tipo_numerico(tipo_esq)) {
                    erro_semantico("Não é possível comparar strings com tipos numéricos", no->linha);
                    return;
                }
            }
        }

        if (!tipo_esq || !tipo_dir) return;

        // Comparações de igualdade
        if (strcmp(no->valor, "==") == 0 || strcmp(no->valor, "!=") == 0) {
            if ((strcmp(tipo_esq, "string") == 0 && is_tipo_numerico(tipo_dir)) || 
                (is_tipo_numerico(tipo_esq) && strcmp(tipo_dir, "string") == 0)) {
                erro_semantico("Não é possível comparar strings com tipos numéricos", no->linha);
                return;
            }
        }
        // Comparações relacionais
        else if (strcmp(no->valor, ">") == 0 || 
                 strcmp(no->valor, "<") == 0 || 
                 strcmp(no->valor, ">=") == 0 || 
                 strcmp(no->valor, "<=") == 0) {
            if (strcmp(tipo_esq, "string") == 0 || strcmp(tipo_dir, "string") == 0) {
                erro_semantico("Não é possível usar string em comparação relacional", no->linha);
                return;
            }
            else if ((strcmp(tipo_esq, "char") == 0 && strcmp(tipo_dir, "int") == 0) ||
                     (strcmp(tipo_esq, "int") == 0 && strcmp(tipo_dir, "char") == 0)) {
                erro_semantico("Comparação relacional inválida entre tipos 'char' e 'int'", no->linha);
            }
            else if (!is_tipo_numerico(tipo_esq) || !is_tipo_numerico(tipo_dir)) {
                char msg[200];
                sprintf(msg, "Comparação relacional inválida entre tipos '%s' e '%s'", tipo_esq, tipo_dir);
                erro_semantico(msg, no->linha);
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
void verificar_declaracoes(No* no) {
    if (strcmp(no->tipo, "DECLARACAO_VAR") == 0) {
        verificar_declaracao_duplicada(tabela, no->valor, no->linha);
    }
}

void verificar_identificador(No* no) {
    if (no->verificado) return;
    
    // Verifica se o ID está dentro de um FOR ou SCAN
    No* atual = no;
    while (atual->pai) {
        if (strcmp(atual->pai->tipo, "FOR") == 0) {
            No* init_no = atual->pai->filhos[0];
            if (init_no && strcmp(init_no->tipo, "ATRIBUICAO") == 0 &&
                strcmp(init_no->filhos[0]->valor, no->valor) == 0) {
                no->verificado = 1;
                return;  // É a variável de controle do FOR
            }
        }
        if (strcmp(atual->pai->tipo, "SCAN") == 0) {
            no->verificado = 1;
            return;  // Ignora IDs dentro de SCAN
        }
        atual = atual->pai;
    }
    
    // Se não é variável de controle do FOR nem dentro de SCAN
    if (!verificar_variavel_declarada(tabela, no->valor)) {
        char msg[100];
        sprintf(msg, "Variável '%s' não foi declarada", no->valor);
        erro_semantico(msg, no->linha);
    }
    
    no->verificado = 1;
}

void verificar_atribuicao(No* no) {
    if (strcmp(no->tipo, "ATRIBUICAO") == 0) {
        const char* id = no->filhos[0]->valor;
        const char* tipo_id = NULL;
        for (int i = 0; i < tabela->quantidade; i++) {
            if (strcmp(tabela->entradas[i].nome, id) == 0) {
                tipo_id = tabela->entradas[i].tipo;
                break;
            }
        }
        const char* tipo_expr = inferir_tipo_expressao(no->filhos[1]);
        if (tipo_id && tipo_expr && !verificar_compatibilidade_tipos(tipo_id, tipo_expr)) {
            char msg[200];
            sprintf(msg, "Atribuição inválida: não é possível atribuir tipo '%s' a variável do tipo '%s'", 
                    tipo_expr, tipo_id);
            erro_semantico(msg, no->linha);
        }
    }
}

void verificar_operador_igualdade(const char* tipo_esq, const char* tipo_dir, int linha) {
    if ((strcmp(tipo_esq, "string") == 0 && is_tipo_numerico(tipo_dir)) || 
        (is_tipo_numerico(tipo_esq) && strcmp(tipo_dir, "string") == 0)) {
        erro_semantico("Não é possível comparar strings com tipos numéricos", linha);
    }
    else if (!verificar_compatibilidade_tipos(tipo_esq, tipo_dir)) {
        char msg[200];
        sprintf(msg, "Comparação de igualdade inválida entre tipos '%s' e '%s'", tipo_esq, tipo_dir);
        erro_semantico(msg, linha);
    }
}

void verificar_operador_relacional(const char* tipo_esq, const char* tipo_dir, int linha) {
    if (!verificar_compatibilidade_tipos(tipo_esq, tipo_dir)) {
        char msg[200];
        sprintf(msg, "Comparação relacional inválida entre tipos '%s' e '%s'", tipo_esq, tipo_dir);
        erro_semantico(msg, linha);
    }
}

void verificar_operador_aritmetico(const char* tipo_esq, const char* tipo_dir, int linha) {
    if (!is_tipo_numerico(tipo_esq) || !is_tipo_numerico(tipo_dir)) {
        char msg[200];
        sprintf(msg, "Operação aritmética inválida entre tipos '%s' e '%s'", tipo_esq, tipo_dir);
        erro_semantico(msg, linha);
    }
}

void verificar_scan(No* no) {
    if (!no->verificado) {
        if (no->filhos[0] && strcmp(no->filhos[0]->tipo, "ID") == 0) {
            const char* id = no->filhos[0]->valor;
            if (!verificar_variavel_declarada(tabela, id)) {
                char msg[100];
                sprintf(msg, "Variável '%s' não foi declarada", id);
                erro_semantico(msg, no->linha);
            }
        }
        no->verificado = 1;
    }
}

void verificar_return(No* no) {
    if (strcmp(no->tipo, "RETURN") == 0) {
        const char* tipo_retorno = inferir_tipo_expressao(no->filhos[0]);
        const char* tipo_funcao = "int";  // Para o exemplo, assumimos que é uma função int (pode ser qualquer tipo)
        
        if (tipo_retorno && strcmp(tipo_retorno, tipo_funcao) != 0) {
            char msg[200];
            sprintf(msg, "Tipo de retorno incompatível: esperado '%s', encontrado '%s'", 
                    tipo_funcao, tipo_retorno);
            erro_semantico(msg, no->linha);
        }
    }
}

void verificar_operadores(No* no) {
    if (strcmp(no->tipo, "OPERADOR") == 0) {
        const char* tipo_esq = inferir_tipo_expressao(no->filhos[0]);
        const char* tipo_dir = inferir_tipo_expressao(no->filhos[1]);

        if (!tipo_esq || !tipo_dir) return;

        if (strcmp(no->valor, "==") == 0 || strcmp(no->valor, "!=") == 0) {
            verificar_operador_igualdade(tipo_esq, tipo_dir, no->linha);
        }
        else if (strcmp(no->valor, ">") == 0 || 
                 strcmp(no->valor, "<") == 0 || 
                 strcmp(no->valor, ">=") == 0 || 
                 strcmp(no->valor, "<=") == 0) {
            verificar_operador_relacional(tipo_esq, tipo_dir, no->linha);
        }
        else if (strcmp(no->valor, "+") == 0 || 
                 strcmp(no->valor, "-") == 0 || 
                 strcmp(no->valor, "*") == 0 || 
                 strcmp(no->valor, "/") == 0) {
            verificar_operador_aritmetico(tipo_esq, tipo_dir, no->linha);
        }
    }
}

void verificar_condicional(No* no) {
    if (strcmp(no->tipo, "IF") == 0 || strcmp(no->tipo, "IF_ELSE") == 0) {
        const char* tipo_cond = inferir_tipo_expressao(no->filhos[0]);
        if (tipo_cond && strcmp(tipo_cond, "string") == 0) {
            erro_semantico("Não é possível usar string como condição em if", no->linha);
        }
    }
}

void verificar_repeticao(No* no) {
    if (!no) return;
    
    if (strcmp(no->tipo, "WHILE") == 0) {
        No* cond_no = no->filhos[0];
        if (cond_no) {
            if (strcmp(cond_no->tipo, "OPERADOR") == 0) {
                verificar_tipo_operacao(cond_no);
            } else {
                const char* tipo_cond = inferir_tipo_expressao(cond_no);
                if (tipo_cond && strcmp(tipo_cond, "string") == 0) {
                    erro_semantico("Não é possível usar string como condição em while", no->linha);
                }
            }
        }
    }
    else if (strcmp(no->tipo, "FOR") == 0) {
        // Verifica condição (segundo filho)
        if (no->num_filhos >= 2) {
            No* cond_no = no->filhos[1];
            if (cond_no && strcmp(cond_no->tipo, "OPERADOR") == 0) {
                verificar_tipo_operacao(cond_no);
            }
        }

        // Verifica incremento (terceiro filho)
        if (no->num_filhos >= 3) {
            No* inc_no = no->filhos[2];
            const char* tipo_inc = inferir_tipo_expressao(inc_no);
            if (tipo_inc && !is_tipo_numerico(tipo_inc)) {
                erro_semantico("Expressão de incremento do for deve ser numérica", no->linha);
            }
        }
    }
}

void registrar_variavel_for(No* no) {
    if (no->filhos[0] && strcmp(no->filhos[0]->tipo, "ATRIBUICAO") == 0) {
        No* id_no = no->filhos[0]->filhos[0];
        if (id_no && strcmp(id_no->tipo, "ID") == 0) {
            adicionar_simbolo(tabela, id_no->valor, "int", "variavel", no->linha);
        }
    }
}

void analisar_no(No* no) {
    if (!no || no->verificado) return;
    
    if (strcmp(no->tipo, "FOR") == 0) {
        registrar_variavel_for(no);  // Registra variável antes das verificações
        verificar_repeticao(no);     // Faz todas as verificações do FOR
        
        // Analisa apenas o bloco do FOR (último filho)
        if (no->num_filhos > 3) {
            analisar_no(no->filhos[3]);
        }
        return;  // Evita processar os outros filhos novamente
    }
    
    // Verificações normais para outros tipos de nós
    if (strcmp(no->tipo, "OPERADOR") == 0) verificar_tipo_operacao(no);
    else if (strcmp(no->tipo, "ID") == 0) {
        if (no->pai && strcmp(no->pai->tipo, "DECLARACAO_VAR") != 0 && 
            strcmp(no->pai->tipo, "PARAMETRO") != 0) {
            verificar_identificador(no);
        }
    }
    else if (strcmp(no->tipo, "ATRIBUICAO") == 0) verificar_atribuicao(no);
    else if (strcmp(no->tipo, "WHILE") == 0) verificar_repeticao(no);
    else if (strcmp(no->tipo, "RETURN") == 0) verificar_return(no);
    else if (strcmp(no->tipo, "SCAN") == 0) verificar_scan(no);
    
    // Processa os filhos recursivamente
    for (int i = 0; i < no->num_filhos; i++) {
        analisar_no(no->filhos[i]);
    }
}

void registrar_declaracoes(No* no) {
    if (!no) return;
    
    if (strcmp(no->tipo, "DECLARACAO_VAR") == 0 && !no->verificado) {
        no->verificado = 1;  // Marca como verificado
        verificar_declaracao_duplicada(tabela, no->valor, no->linha);
        if (!verificar_variavel_declarada(tabela, no->valor)) {
            adicionar_simbolo(tabela, no->valor, no->filhos[0]->valor, "variavel", no->linha);
        }
    }
    
    // Processa primeiro os nós filhos
    for (int i = 0; i < no->num_filhos; i++) {
        registrar_declaracoes(no->filhos[i]);
    }
}

void resetar_verificacoes(No* no) {
    if (!no) return;
    no->verificado = 0;
    for (int i = 0; i < no->num_filhos; i++) {
        resetar_verificacoes(no->filhos[i]);
    }
}

void iniciar_analise_semantica(No* raiz) {
    if (!raiz) return;
    criar_escopo();
    
    // Primeiro registra todas as declarações
    registrar_declaracoes(raiz);
    
    // Reseta as flags de verificação antes da análise
    resetar_verificacoes(raiz);
    
    // Faz a análise
    analisar_no(raiz);
    
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
    // Faz a análise léxica e sintática
    yyparse();
    
    // Inicia a análise semântica se não houver erros léxicos ou sintáticos
    if (erros_lexicos == 0 && erros_sintaticos == 0) {
    printf("\n=== Iniciando análise semântica ===\n"); 
    iniciar_analise_semantica(raiz);
    }
    
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
        printf("O código contém erros de tipos ou uso indevido de variáveis.\n");
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
    
    // Retorna 1 se houver qualquer tipo de erro, 0 caso contrário
    return (erros_lexicos + erros_sintaticos + erros_semanticos) > 0 ? 1 : 0;
}
