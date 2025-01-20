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
char* tipo_funcao_atual = NULL;

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
    int tamanho_vetor; 
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
bool is_safe_conversion(const char* tipo_destino, const char* tipo_origem); 
const char* inferir_tipo_expressao(No* expressao);
void verificar_atribuicao(No* no);
void verificar_acesso_vetor(No* no);
void verificar_identificador(No* no);
void verificar_funcao(No* no);
void verificar_return(No* no);
void iniciar_analise_semantica(No* raiz);

extern int linha;
extern char* yytext;
extern FILE* yyin;
void yyerror(const char* s);
int yylex();

No* raiz = NULL;


#line 153 "parser.tab.c"

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
  YYSYMBOL_lista_valores = 61,             /* lista_valores  */
  YYSYMBOL_tipo = 62,                      /* tipo  */
  YYSYMBOL_declaracao_funcao = 63,         /* declaracao_funcao  */
  YYSYMBOL_parametros = 64,                /* parametros  */
  YYSYMBOL_lista_parametros = 65,          /* lista_parametros  */
  YYSYMBOL_parametro = 66,                 /* parametro  */
  YYSYMBOL_bloco = 67,                     /* bloco  */
  YYSYMBOL_comandos = 68,                  /* comandos  */
  YYSYMBOL_comando = 69,                   /* comando  */
  YYSYMBOL_return_stmt = 70,               /* return_stmt  */
  YYSYMBOL_comando_print = 71,             /* comando_print  */
  YYSYMBOL_string_interpolada = 72,        /* string_interpolada  */
  YYSYMBOL_partes_string = 73,             /* partes_string  */
  YYSYMBOL_parte_string = 74,              /* parte_string  */
  YYSYMBOL_comando_scan = 75,              /* comando_scan  */
  YYSYMBOL_comando_if = 76,                /* comando_if  */
  YYSYMBOL_comando_while = 77,             /* comando_while  */
  YYSYMBOL_comando_for = 78,               /* comando_for  */
  YYSYMBOL_atribuicao_for = 79,            /* atribuicao_for  */
  YYSYMBOL_atribuicao = 80,                /* atribuicao  */
  YYSYMBOL_expressao = 81                  /* expressao  */
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
#define YYLAST   645

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       0,   125,   125,   136,   139,   147,   156,   161,   169,   173,
     180,   186,   193,   205,   215,   226,   236,   246,   253,   260,
     267,   277,   281,   285,   289,   293,   300,   308,   319,   322,
     330,   335,   340,   345,   353,   361,   369,   372,   378,   387,
     388,   389,   390,   391,   392,   393,   394,   398,   406,   411,
     416,   423,   430,   435,   443,   451,   456,   464,   468,   476,
     481,   490,   496,   506,   515,   526,   533,   542,   548,   558,
     564,   570,   574,   578,   582,   587,   592,   598,   604,   610,
     616,   622,   628,   632,   637,   643,   649,   655,   661,   667,
     673,   678,   683,   688,   693
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
  "declaracao_variavel", "lista_valores", "tipo", "declaracao_funcao",
  "parametros", "lista_parametros", "parametro", "bloco", "comandos",
  "comando", "return_stmt", "comando_print", "string_interpolada",
  "partes_string", "parte_string", "comando_scan", "comando_if",
  "comando_while", "comando_for", "atribuicao_for", "atribuicao",
  "expressao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -74,    30,    15,   -74,   -74,   -74,   -74,   -74,   -74,    -9,
     -74,   -74,   161,   -74,    31,   -74,     8,   -74,     7,   104,
      44,    52,    54,   153,   -74,    -7,    36,    47,   -74,   -74,
     -74,   -74,   -41,    60,    60,    60,    60,    60,   284,   -40,
      82,    61,   -74,    64,   176,    78,   -32,   119,   106,   -74,
     153,    60,    32,    32,    32,    32,   446,    60,    60,    60,
      60,    60,    60,    60,    60,   -74,   -74,    60,    60,    60,
      60,   -74,   153,   -74,    47,   153,   153,    57,   126,   -74,
     122,   107,   125,   131,    60,   133,   148,    38,   106,   173,
     143,   106,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   311,
     150,   197,   -74,   603,   603,   147,   147,   147,   147,   584,
     563,    18,    18,    32,    32,   164,   -74,   -74,   -74,   157,
     -74,   162,   -74,    60,    60,   128,   338,    37,   190,    60,
      60,   -74,   -15,   -74,   -74,   -74,   165,   -74,   -74,    50,
     -74,   470,   494,   174,   193,   182,   -74,   186,   187,   188,
     189,   195,    84,   196,   -18,   365,   226,   -74,   -74,   -74,
     111,    47,    47,    60,   204,    60,   198,   208,   211,   212,
     213,   -74,   214,   209,    84,   215,   216,    60,   -74,   206,
     221,   163,   236,   -74,   542,    60,   392,   -74,   -74,   -74,
     -74,   -74,   225,   -74,   -74,   -74,   -74,   255,    60,   -74,
     -74,   -74,    47,   542,    60,   -74,   227,   419,   -74,   518,
     222,   -74,    47,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    21,    22,    23,    24,    25,     0,
       4,     2,     6,     8,     0,     9,     0,     7,     0,     0,
       0,     0,     0,    28,    10,     0,     0,     0,    69,    70,
      72,    73,    71,     0,     0,     0,     0,     0,     0,    71,
       0,     0,    29,    30,    31,     0,     0,     0,    36,    27,
      28,     0,    90,    91,    92,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,     0,     0,     0,
       0,    11,    28,    34,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    71,    36,     0,
       0,    36,    45,    43,    44,    40,    41,    42,    39,     0,
       0,     0,    82,    84,    85,    81,    80,    86,    87,    88,
      89,    76,    77,    78,    79,     0,    26,    32,    33,     0,
      13,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,    35,    37,    46,    74,    75,    74,     0,
      16,     0,     0,     0,     0,     0,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    17,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,    55,     0,     0,     0,    67,    75,
       0,     0,    61,    63,    66,     0,     0,    50,    51,    52,
      53,    49,     0,    54,    56,    48,    59,     0,     0,    14,
      18,    20,     0,    65,     0,    58,     0,     0,    62,     0,
       0,    68,     0,    60,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   259,   -74,   142,   -74,     5,   -74,
     -48,   115,   -74,   -73,   -63,   -74,   -74,   -74,   -74,    99,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    10,    11,    12,    88,   160,    40,    15,
      41,    42,    43,    49,    90,    91,    92,    93,   153,   173,
     174,    94,    95,    96,    97,   145,    98,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,   116,   100,    50,    72,    16,    78,    14,    51,    51,
      45,    52,    53,    54,    55,    56,    79,    14,     4,     5,
       6,     7,     8,    22,   115,   131,    99,   176,   134,   101,
       3,   177,    20,    24,    25,   103,   104,   105,   106,   107,
     108,   109,   110,    46,    18,   111,   112,   113,   114,    65,
      66,    21,    19,    89,   147,   148,   149,   150,   151,    69,
      70,     9,   126,    65,    66,    26,    99,   158,   159,    99,
     152,    28,    29,    30,    31,    32,   129,    28,    29,    30,
      31,    39,    72,    47,    33,    34,    35,   130,   182,   183,
      33,    34,    35,    89,    36,   119,    89,    27,    37,    48,
      36,   141,   142,    73,    37,   120,    74,   155,   156,     4,
       5,     6,     7,     8,    81,    75,    82,    83,    84,   171,
     172,    85,    86,    28,    29,    30,    31,    87,    77,   208,
     144,     4,     5,     6,     7,     8,    33,    34,    35,   214,
      80,   184,    22,   186,    13,   121,    36,   122,    23,   143,
      37,   123,    24,    25,    13,   197,     4,     5,     6,     7,
       8,   180,   181,   203,     4,     5,     6,     7,     8,   124,
      28,    29,    30,    31,    39,   125,   207,   127,    65,    66,
     200,   201,   209,    33,    34,    35,    67,    68,    69,    70,
     117,   118,   128,    36,   132,   136,   133,    37,    57,    58,
      59,    60,    61,    62,    63,    64,   139,    65,    66,   138,
     140,   154,   163,   157,   164,    67,    68,    69,    70,    57,
      58,    59,    60,    61,    62,    63,    64,    76,    65,    66,
     165,   166,   167,   168,   169,   192,    67,    68,    69,    70,
     170,   175,   185,   193,   198,   202,   187,   137,    57,    58,
      59,    60,    61,    62,    63,    64,   188,    65,    66,   189,
     190,   191,   205,   195,   196,    67,    68,    69,    70,   199,
     213,    17,   210,   194,     0,     0,   179,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,     0,     0,
       0,     0,     0,     0,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,     0,   206,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,     0,     0,     0,
       0,     0,    71,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    65,    66,     0,     0,     0,     0,     0,     0,
      67,    68,    69,    70,     0,     0,     0,     0,     0,   135,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      70,     0,     0,     0,     0,     0,   146,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,     0,     0,
       0,     0,     0,     0,    67,    68,    69,    70,     0,     0,
       0,     0,     0,   178,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,     0,     0,     0,     0,     0,
       0,    67,    68,    69,    70,     0,     0,     0,     0,     0,
     204,    57,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,     0,     0,     0,     0,     0,     0,    67,    68,
      69,    70,     0,     0,     0,     0,     0,   211,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,     0,
       0,   102,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,     0,     0,     0,     0,     0,     0,    67,
      68,    69,    70,     0,     0,   161,    57,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,     0,     0,   162,
      57,    58,    59,    60,    61,    62,    63,    64,     0,    65,
      66,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      70,     0,     0,   212,    57,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,     0,     0,     0,     0,     0,
       0,    67,    68,    69,    70,    57,    58,    59,    60,    61,
      62,    63,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    57,    58,    59,    60,
      61,    62,     0,     0,     0,    65,    66,     0,     0,     0,
       0,     0,     0,    67,    68,    69,    70,    59,    60,    61,
      62,     0,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      22,    74,    50,    44,    44,    14,    38,     2,    49,    49,
      17,    33,    34,    35,    36,    37,    48,    12,     3,     4,
       5,     6,     7,    38,    72,    88,    48,    45,    91,    51,
       0,    49,    24,    48,    49,    57,    58,    59,    60,    61,
      62,    63,    64,    50,    13,    67,    68,    69,    70,    31,
      32,    44,    21,    48,    17,    18,    19,    20,    21,    41,
      42,    46,    84,    31,    32,    21,    88,    17,    18,    91,
      33,    17,    18,    19,    20,    21,    38,    17,    18,    19,
      20,    21,    44,    47,    30,    31,    32,    49,   161,   162,
      30,    31,    32,    88,    40,    38,    91,    45,    44,    52,
      40,   123,   124,    21,    44,    48,    45,   129,   130,     3,
       4,     5,     6,     7,     8,    51,    10,    11,    12,    35,
      36,    15,    16,    17,    18,    19,    20,    21,    50,   202,
     125,     3,     4,     5,     6,     7,    30,    31,    32,   212,
      21,   163,    38,   165,     2,    19,    40,    25,    44,    21,
      44,    44,    48,    49,    12,   177,     3,     4,     5,     6,
       7,    50,    51,   185,     3,     4,     5,     6,     7,    44,
      17,    18,    19,    20,    21,    44,   198,    44,    31,    32,
      17,    18,   204,    30,    31,    32,    39,    40,    41,    42,
      75,    76,    44,    40,    21,    45,    53,    44,    22,    23,
      24,    25,    26,    27,    28,    29,    49,    31,    32,    45,
      48,    21,    38,    48,    21,    39,    40,    41,    42,    22,
      23,    24,    25,    26,    27,    28,    29,    51,    31,    32,
      48,    45,    45,    45,    45,    21,    39,    40,    41,    42,
      45,    45,    38,    34,    38,     9,    48,    50,    22,    23,
      24,    25,    26,    27,    28,    29,    48,    31,    32,    48,
      48,    48,    37,    48,    48,    39,    40,    41,    42,    48,
      48,    12,    45,   174,    -1,    -1,    50,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    22,    23,    24,    25,    26,    27,
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
      -1,    -1,    -1,    39,    40,    41,    42,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,    46,
      57,    58,    59,    60,    62,    63,    14,    58,    13,    21,
      24,    44,    38,    44,    48,    49,    21,    45,    17,    18,
      19,    20,    21,    30,    31,    32,    40,    44,    81,    21,
      62,    64,    65,    66,    81,    17,    50,    47,    52,    67,
      44,    49,    81,    81,    81,    81,    81,    22,    23,    24,
      25,    26,    27,    28,    29,    31,    32,    39,    40,    41,
      42,    48,    44,    21,    45,    51,    51,    50,    38,    48,
      21,     8,    10,    11,    12,    15,    16,    21,    60,    62,
      68,    69,    70,    71,    75,    76,    77,    78,    80,    81,
      64,    81,    45,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    64,    67,    65,    65,    38,
      48,    19,    25,    44,    44,    44,    81,    44,    44,    38,
      49,    68,    21,    53,    68,    48,    45,    50,    45,    49,
      48,    81,    81,    21,    62,    79,    48,    17,    18,    19,
      20,    21,    33,    72,    21,    81,    81,    48,    17,    18,
      61,    45,    45,    38,    21,    48,    45,    45,    45,    45,
      45,    35,    36,    73,    74,    45,    45,    49,    48,    50,
      50,    51,    67,    67,    81,    38,    81,    48,    48,    48,
      48,    48,    21,    34,    73,    48,    48,    81,    38,    48,
      17,    18,     9,    81,    48,    37,    50,    81,    67,    81,
      45,    48,    45,    48,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    66,    67,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    71,    71,
      71,    71,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     7,     1,     2,     1,     1,
       3,     5,     8,     6,    10,     5,     7,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     6,     5,     0,     1,
       1,     1,     3,     3,     2,     3,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     5,
       5,     5,     5,     5,     3,     1,     2,     1,     3,     5,
       8,     5,     7,     5,     9,     4,     3,     4,     7,     1,
       1,     1,     1,     1,     4,     4,     3,     3,     3,     3,
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
#line 126 "parser.y"
    {
        (yyval.no) = criar_no("PROGRAMA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        raiz = (yyval.no);
    }
#line 1451 "parser.tab.c"
    break;

  case 3: /* includes: %empty  */
#line 136 "parser.y"
    {
        (yyval.no) = criar_no("INCLUDES", "");
    }
#line 1459 "parser.tab.c"
    break;

  case 4: /* includes: includes include_stmt  */
#line 140 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1468 "parser.tab.c"
    break;

  case 5: /* include_stmt: '#' INCLUDE MENOR ID '.' ID MAIOR  */
#line 148 "parser.y"
    {
        char include_name[100];
        sprintf(include_name, "%s.%s", (yyvsp[-3].sval), (yyvsp[-1].sval));
        (yyval.no) = criar_no("INCLUDE", include_name);
    }
#line 1478 "parser.tab.c"
    break;

  case 6: /* declaracoes: declaracao  */
#line 157 "parser.y"
    { 
        (yyval.no) = criar_no("DECLARACOES", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1487 "parser.tab.c"
    break;

  case 7: /* declaracoes: declaracao declaracoes  */
#line 162 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1496 "parser.tab.c"
    break;

  case 8: /* declaracao: declaracao_variavel  */
#line 170 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1504 "parser.tab.c"
    break;

  case 9: /* declaracao: declaracao_funcao  */
#line 174 "parser.y"
    { 
        (yyval.no) = (yyvsp[0].no);
    }
#line 1512 "parser.tab.c"
    break;

  case 10: /* declaracao_variavel: tipo ID ';'  */
#line 181 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-1].sval));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_simbolo(tabela, (yyvsp[-1].sval), (yyvsp[-2].no)->valor, "variavel", linha);
    }
#line 1522 "parser.tab.c"
    break;

  case 11: /* declaracao_variavel: tipo ID '=' expressao ';'  */
#line 187 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_simbolo(tabela, (yyvsp[-3].sval), (yyvsp[-4].no)->valor, "variavel", linha);
    }
#line 1533 "parser.tab.c"
    break;

  case 12: /* declaracao_variavel: tipo ID '=' ID '(' parametros ')' ';'  */
#line 194 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_VAR", (yyvsp[-6].sval));
        adicionar_filho((yyval.no), (yyvsp[-7].no)); 
        
        // Cria o nó de chamada de função
        No* chamada_funcao = criar_no("CHAMADA_FUNCAO", (yyvsp[-4].sval));
        adicionar_filho(chamada_funcao, (yyvsp[-2].no));
        adicionar_filho((yyval.no), chamada_funcao); 
        
        adicionar_simbolo(tabela, (yyvsp[-6].sval), (yyvsp[-7].no)->valor, "variavel", linha);
    }
#line 1549 "parser.tab.c"
    break;

  case 13: /* declaracao_variavel: tipo ID '[' NUM_INT ']' ';'  */
#line 206 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[%d]", (yyvsp[-4].sval), (yyvsp[-2].ival));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[%d]", (yyvsp[-5].no)->valor, (yyvsp[-2].ival));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), tipo_vetor, "vetor", linha);
    }
#line 1563 "parser.tab.c"
    break;

  case 14: /* declaracao_variavel: tipo ID '[' NUM_INT ']' '=' '[' lista_valores ']' ';'  */
#line 216 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[%d]", (yyvsp[-8].sval), (yyvsp[-6].ival));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-9].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[%d]", (yyvsp[-9].no)->valor, (yyvsp[-6].ival));
        adicionar_simbolo(tabela, (yyvsp[-8].sval), tipo_vetor, "vetor", linha);
    }
#line 1578 "parser.tab.c"
    break;

  case 15: /* declaracao_variavel: tipo ID '[' ']' ';'  */
#line 227 "parser.y"
    {
        char temp[32];
        sprintf(temp, "%s[]", (yyvsp[-3].sval));
        (yyval.no) = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[]", (yyvsp[-4].no)->valor);
        adicionar_simbolo(tabela, (yyvsp[-3].sval), tipo_vetor, "vetor", linha);
    }
#line 1592 "parser.tab.c"
    break;

  case 16: /* declaracao_variavel: tipo ID '[' ']' '=' STRING ';'  */
#line 237 "parser.y"
    {
        (yyval.no) = criar_no("DECLARACAO_STRING", (yyvsp[-5].sval));
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-1].sval)));
        adicionar_simbolo(tabela, (yyvsp[-5].sval), (yyvsp[-6].no)->valor, "variavel", linha);
    }
#line 1603 "parser.tab.c"
    break;

  case 17: /* lista_valores: NUM_INT  */
#line 247 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_VALORES", "");
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        adicionar_filho((yyval.no), criar_no("NUM_INT", valor));
    }
#line 1614 "parser.tab.c"
    break;

  case 18: /* lista_valores: lista_valores ',' NUM_INT  */
#line 254 "parser.y"
    {
        (yyval.no) = (yyvsp[-2].no);
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        adicionar_filho((yyval.no), criar_no("NUM_INT", valor));
    }
#line 1625 "parser.tab.c"
    break;

  case 19: /* lista_valores: NUM_FLOAT  */
#line 261 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_VALORES", "");
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        adicionar_filho((yyval.no), criar_no("NUM_FLOAT", valor));
    }
#line 1636 "parser.tab.c"
    break;

  case 20: /* lista_valores: lista_valores ',' NUM_FLOAT  */
#line 268 "parser.y"
    {
        (yyval.no) = (yyvsp[-2].no);
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        adicionar_filho((yyval.no), criar_no("NUM_FLOAT", valor));
    }
#line 1647 "parser.tab.c"
    break;

  case 21: /* tipo: TIPO_INT  */
#line 278 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "int");
    }
#line 1655 "parser.tab.c"
    break;

  case 22: /* tipo: TIPO_FLOAT  */
#line 282 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "float");
    }
#line 1663 "parser.tab.c"
    break;

  case 23: /* tipo: TIPO_CHAR  */
#line 286 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "char");
    }
#line 1671 "parser.tab.c"
    break;

  case 24: /* tipo: TIPO_STRING  */
#line 290 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "string");
    }
#line 1679 "parser.tab.c"
    break;

  case 25: /* tipo: VOID  */
#line 294 "parser.y"
    { 
        (yyval.no) = criar_no("TIPO", "void");
    }
#line 1687 "parser.tab.c"
    break;

  case 26: /* declaracao_funcao: tipo ID '(' parametros ')' bloco  */
#line 301 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", (yyvsp[-4].sval));
        adicionar_filho((yyval.no), (yyvsp[-5].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, (yyvsp[-4].sval), (yyvsp[-5].no)->valor, "funcao", linha);
    }
#line 1699 "parser.tab.c"
    break;

  case 27: /* declaracao_funcao: tipo MAIN '(' ')' bloco  */
#line 309 "parser.y"
    {
        (yyval.no) = criar_no("FUNCAO", "main");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
        adicionar_simbolo(tabela, "main", (yyvsp[-4].no)->valor, "funcao", linha);
    }
#line 1710 "parser.tab.c"
    break;

  case 28: /* parametros: %empty  */
#line 319 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
    }
#line 1718 "parser.tab.c"
    break;

  case 29: /* parametros: lista_parametros  */
#line 323 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1727 "parser.tab.c"
    break;

  case 30: /* lista_parametros: parametro  */
#line 331 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1736 "parser.tab.c"
    break;

  case 31: /* lista_parametros: expressao  */
#line 336 "parser.y"
    {
        (yyval.no) = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1745 "parser.tab.c"
    break;

  case 32: /* lista_parametros: parametro ',' lista_parametros  */
#line 341 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1754 "parser.tab.c"
    break;

  case 33: /* lista_parametros: expressao ',' lista_parametros  */
#line 346 "parser.y"
    {
        (yyval.no) = (yyvsp[-2].no);
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1763 "parser.tab.c"
    break;

  case 34: /* parametro: tipo ID  */
#line 354 "parser.y"
    {
        (yyval.no) = criar_no("PARAMETRO", (yyvsp[0].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1772 "parser.tab.c"
    break;

  case 35: /* bloco: '{' comandos '}'  */
#line 362 "parser.y"
    {
        (yyval.no) = criar_no("BLOCO", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1781 "parser.tab.c"
    break;

  case 36: /* comandos: %empty  */
#line 369 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
    }
#line 1789 "parser.tab.c"
    break;

  case 37: /* comandos: comando comandos  */
#line 373 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1799 "parser.tab.c"
    break;

  case 38: /* comandos: declaracao_variavel comandos  */
#line 379 "parser.y"
    {
        (yyval.no) = criar_no("COMANDOS", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1809 "parser.tab.c"
    break;

  case 39: /* comando: atribuicao  */
#line 387 "parser.y"
               { (yyval.no) = (yyvsp[0].no); }
#line 1815 "parser.tab.c"
    break;

  case 40: /* comando: comando_if  */
#line 388 "parser.y"
                 { (yyval.no) = (yyvsp[0].no); }
#line 1821 "parser.tab.c"
    break;

  case 41: /* comando: comando_while  */
#line 389 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1827 "parser.tab.c"
    break;

  case 42: /* comando: comando_for  */
#line 390 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1833 "parser.tab.c"
    break;

  case 43: /* comando: comando_print  */
#line 391 "parser.y"
                    { (yyval.no) = (yyvsp[0].no); }
#line 1839 "parser.tab.c"
    break;

  case 44: /* comando: comando_scan  */
#line 392 "parser.y"
                   { (yyval.no) = (yyvsp[0].no); }
#line 1845 "parser.tab.c"
    break;

  case 45: /* comando: return_stmt  */
#line 393 "parser.y"
                  { (yyval.no) = (yyvsp[0].no); }
#line 1851 "parser.tab.c"
    break;

  case 46: /* comando: expressao ';'  */
#line 394 "parser.y"
                    { (yyval.no) = (yyvsp[-1].no); }
#line 1857 "parser.tab.c"
    break;

  case 47: /* return_stmt: RETURN expressao ';'  */
#line 399 "parser.y"
    {
        (yyval.no) = criar_no("RETURN", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1866 "parser.tab.c"
    break;

  case 48: /* comando_print: PRINT '(' string_interpolada ')' ';'  */
#line 407 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
    }
#line 1875 "parser.tab.c"
    break;

  case 49: /* comando_print: PRINT '(' ID ')' ';'  */
#line 412 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1884 "parser.tab.c"
    break;

  case 50: /* comando_print: PRINT '(' NUM_INT ')' ';'  */
#line 417 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[-2].ival));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_INT", valor));
    }
#line 1895 "parser.tab.c"
    break;

  case 51: /* comando_print: PRINT '(' NUM_FLOAT ')' ';'  */
#line 424 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[-2].fval));
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("NUM_FLOAT", valor));
    }
#line 1906 "parser.tab.c"
    break;

  case 52: /* comando_print: PRINT '(' STRING ')' ';'  */
#line 431 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("STRING", (yyvsp[-2].sval)));
    }
#line 1915 "parser.tab.c"
    break;

  case 53: /* comando_print: PRINT '(' CHAR ')' ';'  */
#line 436 "parser.y"
    {
        (yyval.no) = criar_no("PRINT", "");
        adicionar_filho((yyval.no), criar_no("CHAR", (yyvsp[-2].sval)));
    }
#line 1924 "parser.tab.c"
    break;

  case 54: /* string_interpolada: STRING_START partes_string STRING_END  */
#line 444 "parser.y"
    {
        (yyval.no) = criar_no("STRING_INTERPOLADA", "");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1933 "parser.tab.c"
    break;

  case 55: /* partes_string: parte_string  */
#line 452 "parser.y"
    {
        (yyval.no) = criar_no("PARTES_STRING", "");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1942 "parser.tab.c"
    break;

  case 56: /* partes_string: parte_string partes_string  */
#line 457 "parser.y"
    {
        (yyval.no) = (yyvsp[0].no);
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 1951 "parser.tab.c"
    break;

  case 57: /* parte_string: STRING_TEXT  */
#line 465 "parser.y"
    {
        (yyval.no) = criar_no("TEXTO", (yyvsp[0].sval));
    }
#line 1959 "parser.tab.c"
    break;

  case 58: /* parte_string: INTERPOLACAO_START ID INTERPOLACAO_END  */
#line 469 "parser.y"
    {
        (yyval.no) = criar_no("INTERPOLACAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-1].sval)));
    }
#line 1968 "parser.tab.c"
    break;

  case 59: /* comando_scan: SCAN '(' ID ')' ';'  */
#line 477 "parser.y"
    {
        (yyval.no) = criar_no("SCAN", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
    }
#line 1977 "parser.tab.c"
    break;

  case 60: /* comando_scan: SCAN '(' ID '[' expressao ']' ')' ';'  */
#line 482 "parser.y"
    {
        (yyval.no) = criar_no("SCAN_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-5].sval)));
        adicionar_filho((yyval.no), (yyvsp[-3].no));  /* índice do vetor */
    }
#line 1987 "parser.tab.c"
    break;

  case 61: /* comando_if: IF '(' expressao ')' bloco  */
#line 491 "parser.y"
    {
        (yyval.no) = criar_no("IF", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 1997 "parser.tab.c"
    break;

  case 62: /* comando_if: IF '(' expressao ')' bloco ELSE bloco  */
#line 497 "parser.y"
    {
        (yyval.no) = criar_no("IF_ELSE", "");
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2008 "parser.tab.c"
    break;

  case 63: /* comando_while: WHILE '(' expressao ')' bloco  */
#line 507 "parser.y"
    {
        (yyval.no) = criar_no("WHILE", "");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2018 "parser.tab.c"
    break;

  case 64: /* comando_for: FOR '(' atribuicao_for ';' expressao ';' expressao ')' bloco  */
#line 516 "parser.y"
    { 
        (yyval.no) = criar_no("FOR", "");
        adicionar_filho((yyval.no), (yyvsp[-6].no));
        adicionar_filho((yyval.no), (yyvsp[-4].no));
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2030 "parser.tab.c"
    break;

  case 65: /* atribuicao_for: tipo ID '=' expressao  */
#line 527 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
        adicionar_filho((yyval.no), (yyvsp[-3].no));  // Adiciona o tipo
        adicionar_filho((yyval.no), (yyvsp[0].no));  // Adiciona a expressão
    }
#line 2041 "parser.tab.c"
    break;

  case 66: /* atribuicao_for: ID '=' expressao  */
#line 534 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-2].sval)));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2051 "parser.tab.c"
    break;

  case 67: /* atribuicao: ID '=' expressao ';'  */
#line 543 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-3].sval)));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2061 "parser.tab.c"
    break;

  case 68: /* atribuicao: ID '[' expressao ']' '=' expressao ';'  */
#line 549 "parser.y"
    {
        (yyval.no) = criar_no("ATRIBUICAO_VETOR", "");
        adicionar_filho((yyval.no), criar_no("ID", (yyvsp[-6].sval)));
        adicionar_filho((yyval.no), (yyvsp[-4].no));  // índice
        adicionar_filho((yyval.no), (yyvsp[-1].no));  // valor
    }
#line 2072 "parser.tab.c"
    break;

  case 69: /* expressao: NUM_INT  */
#line 559 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%d", (yyvsp[0].ival));
        (yyval.no) = criar_no("NUM_INT", valor);
    }
#line 2082 "parser.tab.c"
    break;

  case 70: /* expressao: NUM_FLOAT  */
#line 565 "parser.y"
    {
        char valor[32];
        sprintf(valor, "%f", (yyvsp[0].fval));
        (yyval.no) = criar_no("NUM_FLOAT", valor);
    }
#line 2092 "parser.tab.c"
    break;

  case 71: /* expressao: ID  */
#line 571 "parser.y"
    { 
        (yyval.no) = criar_no("ID", (yyvsp[0].sval));
    }
#line 2100 "parser.tab.c"
    break;

  case 72: /* expressao: STRING  */
#line 575 "parser.y"
    { 
        (yyval.no) = criar_no("STRING", (yyvsp[0].sval));
    }
#line 2108 "parser.tab.c"
    break;

  case 73: /* expressao: CHAR  */
#line 579 "parser.y"
    { 
        (yyval.no) = criar_no("CHAR", (yyvsp[0].sval));
    }
#line 2116 "parser.tab.c"
    break;

  case 74: /* expressao: ID '(' parametros ')'  */
#line 583 "parser.y"
    {
        (yyval.no) = criar_no("CHAMADA_FUNCAO", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));  // Adiciona a lista de argumentos como filho
    }
#line 2125 "parser.tab.c"
    break;

  case 75: /* expressao: ID '[' expressao ']'  */
#line 588 "parser.y"
    {
        (yyval.no) = criar_no("ACESSO_VETOR", (yyvsp[-3].sval));
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2134 "parser.tab.c"
    break;

  case 76: /* expressao: expressao '+' expressao  */
#line 593 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "+");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2144 "parser.tab.c"
    break;

  case 77: /* expressao: expressao '-' expressao  */
#line 599 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "-");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2154 "parser.tab.c"
    break;

  case 78: /* expressao: expressao '*' expressao  */
#line 605 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "*");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2164 "parser.tab.c"
    break;

  case 79: /* expressao: expressao '/' expressao  */
#line 611 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "/");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2174 "parser.tab.c"
    break;

  case 80: /* expressao: expressao MAIOR expressao  */
#line 617 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2184 "parser.tab.c"
    break;

  case 81: /* expressao: expressao MENOR expressao  */
#line 623 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2194 "parser.tab.c"
    break;

  case 82: /* expressao: '(' expressao ')'  */
#line 629 "parser.y"
    {
        (yyval.no) = (yyvsp[-1].no);
    }
#line 2202 "parser.tab.c"
    break;

  case 83: /* expressao: '-' expressao  */
#line 633 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_UNARIO", "-");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2211 "parser.tab.c"
    break;

  case 84: /* expressao: expressao IGUAL expressao  */
#line 638 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "==");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2221 "parser.tab.c"
    break;

  case 85: /* expressao: expressao DIFERENTE expressao  */
#line 644 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2231 "parser.tab.c"
    break;

  case 86: /* expressao: expressao MENOR_IGUAL expressao  */
#line 650 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "<=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2241 "parser.tab.c"
    break;

  case 87: /* expressao: expressao MAIOR_IGUAL expressao  */
#line 656 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", ">=");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2251 "parser.tab.c"
    break;

  case 88: /* expressao: expressao E expressao  */
#line 662 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "&&");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2261 "parser.tab.c"
    break;

  case 89: /* expressao: expressao OU expressao  */
#line 668 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "||");
        adicionar_filho((yyval.no), (yyvsp[-2].no));
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2271 "parser.tab.c"
    break;

  case 90: /* expressao: NAO expressao  */
#line 674 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR", "!");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2280 "parser.tab.c"
    break;

  case 91: /* expressao: INC expressao  */
#line 679 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "++");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2289 "parser.tab.c"
    break;

  case 92: /* expressao: DEC expressao  */
#line 684 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_PRE", "--");
        adicionar_filho((yyval.no), (yyvsp[0].no));
    }
#line 2298 "parser.tab.c"
    break;

  case 93: /* expressao: expressao INC  */
#line 689 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "++");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2307 "parser.tab.c"
    break;

  case 94: /* expressao: expressao DEC  */
#line 694 "parser.y"
    {
        (yyval.no) = criar_no("OPERADOR_POS", "--");
        adicionar_filho((yyval.no), (yyvsp[-1].no));
    }
#line 2316 "parser.tab.c"
    break;


#line 2320 "parser.tab.c"

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

#line 700 "parser.y"


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
    // Tipos exatamente iguais são sempre compatíveis
    if (strcmp(tipo1, tipo2) == 0) 
        return true;

    // Verifica conversões seguras (int para float)
    if (is_safe_conversion(tipo1, tipo2)) 
        return true;

    // Não permite atribuir array/string para tipos primitivos
    if (is_tipo_numerico(tipo1) || strcmp(tipo1, "char") == 0) {
        if (strstr(tipo2, "[") || strcmp(tipo2, "string") == 0) {
            return false;
        }
    }

    // Permite string literal para array de char
    if (strstr(tipo1, "char[") && strcmp(tipo2, "string") == 0) {
        return true;
    }

    // Vetores do mesmo tipo são compatíveis
    if (strstr(tipo1, "[]") != NULL && strstr(tipo2, "[]") != NULL) {
        char base1[32], base2[32];
        strncpy(base1, tipo1, strchr(tipo1, '[') - tipo1);
        strncpy(base2, tipo2, strchr(tipo2, '[') - tipo2);
        base1[strchr(tipo1, '[') - tipo1] = '\0';
        base2[strchr(tipo2, '[') - tipo2] = '\0';
        return strcmp(base1, base2) == 0;
    }

    // Arrays de string são compatíveis
    if (strstr(tipo1, "string[") != NULL && strstr(tipo2, "string[") != NULL) {
        char base1[32], base2[32];
        strncpy(base1, tipo1, strchr(tipo1, '[') - tipo1);
        strncpy(base2, tipo2, strchr(tipo2, '[') - tipo2);
        base1[strchr(tipo1, '[') - tipo1] = '\0';
        base2[strchr(tipo2, '[') - tipo2] = '\0';
        return strcmp(base1, base2) == 0;
    }

    return false;
}

bool is_tipo_numerico(const char* tipo) {
    return (strcmp(tipo, "int") == 0 || strcmp(tipo, "float") == 0);
}

bool is_safe_conversion(const char* tipo_destino, const char* tipo_origem) {
    // Tipos devem ser exatamente iguais
    if (strcmp(tipo_destino, tipo_origem) == 0) 
        return true;

    // Conversão de float para float
    if (strcmp(tipo_destino, "float") == 0) {
        return (strcmp(tipo_origem, "int") == 0);
    }
    
    // Conversão de int para int
    if (strcmp(tipo_destino, "int") == 0) {
        return (strcmp(tipo_origem, "float") == 0 );
    }

    return false;
}

const char* inferir_tipo_expressao(No* expressao) {
    if (!expressao) {
        return NULL;
    }

    if (strcmp(expressao->tipo, "CHAMADA_FUNCAO") == 0) {
        // Busca o tipo de retorno da função na tabela de símbolos
        for (int i = 0; i < tabela->quantidade; i++) {
            if (strcmp(tabela->entradas[i].nome, expressao->valor) == 0 && 
                strcmp(tabela->entradas[i].categoria, "funcao") == 0) {
                return tabela->entradas[i].tipo;
            }
        }
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
                if (strstr(tabela->entradas[i].tipo, "char[")) {
                    return "string";
                }
                return tabela->entradas[i].tipo;
            }
        }
        
        return NULL;
    }

    // Chamada de função
    if (strcmp(expressao->tipo, "OPERADOR") == 0 && expressao->valor) {
        // Verifica se é uma chamada de função
        for (int i = 0; i < tabela->quantidade; i++) {
            if (strcmp(tabela->entradas[i].nome, expressao->valor) == 0 && 
                strcmp(tabela->entradas[i].categoria, "funcao") == 0) {
                return tabela->entradas[i].tipo;
            }
        }
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

    if (strcmp(no->tipo, "ATRIBUICAO") == 0) {
        // Verifica se a atribuição é para char
        No* id_no = no->filhos[0];
        No* valor_no = no->filhos[1];

        if (strcmp(id_no->tipo, "CHAR") == 0) {
            if (strcmp(valor_no->tipo, "STRING") == 0) {
                erro_semantico("Não é possível atribuir string a uma variável char", no->linha);
                return;
            }
        }

        // Nova verificação para char literal
        if (valor_no && strcmp(valor_no->tipo, "CHAR") == 0) {
            // Remove as aspas simples para verificar o conteúdo
            char* valor = valor_no->valor;
            char* conteudo = valor + 1;  // Pula a primeira aspas
            conteudo[strlen(conteudo) - 1] = '\0';  // Remove a última aspas
            
            if (strlen(conteudo) > 1) {
                erro_semantico("char deve conter apenas um caractere", no->linha);
                return;
            }
        }
    }

    if (strcmp(no->tipo, "OPERADOR") == 0 && !no->verificado) {
        no->verificado = 1;
        const char* tipo_esq = inferir_tipo_expressao(no->filhos[0]);
        const char* tipo_dir = inferir_tipo_expressao(no->filhos[1]);

        // verifica se é uma divisão por zero
        if (strcmp(no->valor, "/") == 0) {
            No* divisor = no->filhos[1];
            // Verifica se é um número literal
            if (strcmp(divisor->tipo, "NUM_INT") == 0) {
                if (atoi(divisor->valor) == 0) {
                    erro_semantico("Divisão por zero detectada", no->linha);
                    return;
                }
            }
            else if (strcmp(divisor->tipo, "NUM_FLOAT") == 0 && atof(divisor->valor) == 0.0) {
                erro_semantico("Divisão por zero detectada", no->linha);
            }
            else if (strcmp(divisor->tipo, "NUM_FLOAT") == 0) {
                if (atof(divisor->valor) == 0.0) {
                    erro_semantico("Divisão por zero detectada", no->linha);
                    return;
                }
            }
             else if (strcmp(divisor->tipo, "ID") == 0) {
                erro_semantico("Possível divisão por zero: divisor é variável", no->linha);
            }
            // Verifica se é uma expressão que resulta em zero
            else if (strcmp(divisor->tipo, "OPERADOR") == 0 && 
                     strcmp(divisor->valor, "-") == 0) {
                // Caso de subtração de números iguais (x - x)
                if (divisor->filhos[0] && divisor->filhos[1] &&
                    strcmp(divisor->filhos[0]->valor, divisor->filhos[1]->valor) == 0) {
                    erro_semantico("Possível divisão por zero detectada", no->linha);
                    return;
                }
            }
        }
        
        // Verifica se está tentando fazer operação com char
        if ((tipo_esq && strcmp(tipo_esq, "char") == 0) ||
            (tipo_dir && strcmp(tipo_dir, "char") == 0)) {
            if (strcmp(no->valor, "+") == 0 || 
                strcmp(no->valor, "-") == 0 || 
                strcmp(no->valor, "*") == 0 || 
                strcmp(no->valor, "/") == 0) {
                erro_semantico("Não é possível realizar operações aritméticas com char", no->linha);
                return;
            }
        }

        bool eh_string_esq = (tipo_esq && (strcmp(tipo_esq, "string") == 0 || strstr(tipo_esq, "char[") != NULL));
        bool eh_string_dir = (tipo_dir && (strcmp(tipo_dir, "string") == 0 || strstr(tipo_dir, "char[") != NULL));

        if (eh_string_esq || eh_string_dir) {
            // Se for operador aritmético, gera erro
            if (strcmp(no->valor, "+") == 0 || 
                strcmp(no->valor, "-") == 0 || 
                strcmp(no->valor, "*") == 0 || 
                strcmp(no->valor, "/") == 0) {
                erro_semantico("Não é possível realizar operações aritméticas com strings", no->linha);
                return;
            }
        }
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

void verificar_char_literal(No* no, int linha) {
    if (!no) return;
    
    // Remove as aspas simples para verificar o conteúdo
    char* valor = no->valor;
    char* conteudo = valor + 1;  // Pula a primeira aspas
    conteudo[strlen(conteudo) - 1] = '\0';  // Remove a última aspas
    
    if (strlen(conteudo) > 1) {
        erro_semantico("char deve conter apenas um caractere", linha);
    }
}

void verificar_acesso_vetor(No* no) {
    if (!no || (strcmp(no->tipo, "ACESSO_VETOR") != 0 && strcmp(no->tipo, "ATRIBUICAO_VETOR") != 0)) return;

    const char* nome_vetor = strcmp(no->tipo, "ACESSO_VETOR") == 0 ? no->valor : no->filhos[0]->valor;
                
    // verifica se o vetor foi declarado
    if (!verificar_variavel_declarada(tabela, nome_vetor)) {
        char msg[100];
        sprintf(msg, "Vetor '%s' não foi declarado", nome_vetor);
        erro_semantico(msg, no->linha);
        return;
    }

    No* indice_no = strcmp(no->tipo, "ACESSO_VETOR") == 0 ? no->filhos[0] : no->filhos[1];

    // Função auxiliar para avaliar o índice e verificar se é negativo
    int avaliar_indice(No* no) {
        if (strcmp(no->tipo, "NUM_INT") == 0) {
            return atoi(no->valor);
        }
        else if (strcmp(no->tipo, "OPERADOR_UNARIO") == 0 && strcmp(no->valor, "-") == 0) {
            // Se for um operador unário de negação
            if (strcmp(no->filhos[0]->tipo, "NUM_INT") == 0) {
                return -atoi(no->filhos[0]->valor);
            }
        }
        return 0; // Valor padrão se não conseguir avaliar
    }

    // verifica se o índice é uma expressão numérica
    if (indice_no) {
        const char* tipo_indice = inferir_tipo_expressao(indice_no);
        
        // Verificação de tipo
        if (strcmp(indice_no->tipo, "NUM_INT") != 0 && 
            (tipo_indice && strcmp(tipo_indice, "int") != 0)) {
            erro_semantico("Índice de vetor deve ser do tipo inteiro", no->linha);
            return;
        }

        // Verificação de índice negativo
        int indice = avaliar_indice(indice_no);
        if (indice < 0) {
            erro_semantico("Índice de vetor não pode ser negativo", no->linha);
            return;
        }
    }

    // se for um número literal, verifica os limites
    if (indice_no && (strcmp(indice_no->tipo, "NUM_INT") == 0 || 
        (strcmp(indice_no->tipo, "OPERADOR_UNARIO") == 0 && strcmp(indice_no->valor, "-") == 0))) {
        int indice = avaliar_indice(indice_no);
        
        // Procura o vetor na tabela de símbolos
        for (int i = 0; i < tabela->quantidade; i++) {
            if (strcmp(tabela->entradas[i].nome, nome_vetor) == 0) {
                char* tipo_str = strdup(tabela->entradas[i].tipo);
                char* inicio = strchr(tipo_str, '[');
                char* fim = strchr(tipo_str, ']');
                
                if (inicio && fim && (fim > inicio)) {
                    inicio++; // Pula o '['
                    *fim = '\0'; // Termina a string no ']'
                    int tamanho = atoi(inicio);
                    
                    if (tamanho > 0 && indice >= tamanho) {
                        char msg[100];
                        sprintf(msg, "Acesso fora dos limites do vetor '%s'. Índice %d não é permitido", 
                                nome_vetor, indice);
                        erro_semantico(msg, no->linha);
                    }
                }
                free(tipo_str);
                break;
            }
        }
    }
}

void verificar_lista_valores(No* no, const char* tipo_vetor, int tamanho_vetor) {
    if (!no || strcmp(no->tipo, "LISTA_VALORES") != 0) return;

    // Verifica se a quantidade de valores excede o tamanho do vetor
    if (no->num_filhos > tamanho_vetor) {
        char msg[200];
        sprintf(msg, "Quantidade de valores (%d) excede o tamanho do vetor (%d). Índices válidos: 0 a %d", 
                no->num_filhos, tamanho_vetor, tamanho_vetor - 1);
        erro_semantico(msg, no->linha);
        return;
    }

    // Verifica o tipo de cada valor na lista
    for (int i = 0; i < no->num_filhos; i++) {
        No* valor = no->filhos[i];
        
        // Para vetores de inteiros
        if (strcmp(tipo_vetor, "int") == 0) {
            if (strcmp(valor->tipo, "NUM_INT") != 0) {
                char msg[100];
                sprintf(msg, "Valor incompatível na posição %d da inicialização do vetor. Esperado: int", i);
                erro_semantico(msg, no->linha);
            }
        }
        // Para vetores de float
        else if (strcmp(tipo_vetor, "float") == 0) {
            if (strcmp(valor->tipo, "NUM_FLOAT") != 0 && strcmp(valor->tipo, "NUM_INT") != 0) {
                char msg[100];
                sprintf(msg, "Valor incompatível na posição %d da inicialização do vetor. Esperado: float", i);
                erro_semantico(msg, no->linha);
            }
        }
        // Para vetores de char
        else if (strcmp(tipo_vetor, "char") == 0) {
            if (strcmp(valor->tipo, "CHAR") != 0) {
                char msg[100];
                sprintf(msg, "Valor incompatível na posição %d da inicialização do vetor. Esperado: char", i);
                erro_semantico(msg, no->linha);
            }
        }
    }
}

void verificar_declaracoes(No* no) {
    if (strcmp(no->tipo, "DECLARACAO_VAR") == 0) {
        verificar_declaracao_duplicada(tabela, no->valor, no->linha);
    }
}

void verificar_identificador(No* no) {
    if (!no || no->verificado) return;

    No* atual = no;
    while (atual->pai) {
        // Verifica se está no contexto de um FOR
        if (strcmp(atual->pai->tipo, "FOR") == 0) {
            No* init_no = atual->pai->filhos[0]; // Inicialização do FOR
            if (init_no && strcmp(init_no->tipo, "ATRIBUICAO") == 0) {
                No* id_no = init_no->filhos[0]; // Identificador
                if (id_no && strcmp(id_no->valor, no->valor) == 0) {
                    no->verificado = 1;
                    return;  // É a variável de controle do FOR
                }
            }
        }
        // Ignora verificações se for declaração de variável, parâmetro ou SCAN
        if (strcmp(atual->pai->tipo, "PARAMETRO") == 0 || 
            strcmp(atual->pai->tipo, "DECLARACAO_VAR") == 0 ||
            strcmp(atual->pai->tipo, "SCAN") == 0) {
            no->verificado = 1;
            return;
        }
        atual = atual->pai;
    }

    // Verifica se a variável foi declarada no escopo atual ou global
    if (!verificar_variavel_declarada(escopo_atual->tabela, no->valor) &&
        !verificar_variavel_declarada(tabela, no->valor)) {
        char msg[100];
        sprintf(msg, "Variável '%s' não foi declarada", no->valor);
        erro_semantico(msg, no->linha);
    }

    no->verificado = 1; // Marca como verificado
}

void verificar_atribuicao(No* no) {
    if (!no) return;

    if (strcmp(no->tipo, "DECLARACAO_VAR") == 0 || strcmp(no->tipo, "ATRIBUICAO") == 0) {
        No* id_no = no->filhos[0];
        No* valor_no = NULL;
        const char* tipo_id = NULL;

        if (strcmp(no->tipo, "DECLARACAO_VAR") == 0) {
            if (strcmp(no->filhos[0]->valor, "void") == 0) {
                erro_semantico("Tipo void não pode ser usado para declarar variáveis", no->linha);
                return;
            }
            tipo_id = no->filhos[0]->valor;
            if (no->num_filhos >= 2) {
                valor_no = no->filhos[1];
                
                // Verificar se o valor é um ID não declarado
                if (strcmp(valor_no->tipo, "ID") == 0) {
                    if (!verificar_variavel_declarada(tabela, valor_no->valor)) {
                        char msg[100];
                        sprintf(msg, "Variável '%s' não foi declarada", valor_no->valor);
                        erro_semantico(msg, no->linha);
                        return;
                    }
                }
            }
        } else {
            valor_no = no->filhos[1];
            for (int i = 0; i < tabela->quantidade; i++) {
                if (strcmp(tabela->entradas[i].nome, id_no->valor) == 0) {
                    tipo_id = tabela->entradas[i].tipo;
                    break;
                }
            }
        }

        if (valor_no && tipo_id) {
            // Verifica atribuição em variável char (somente para char simples, não arrays)
            if (strcmp(tipo_id, "char") == 0 && !strstr(tipo_id, "[")) {
                if (strcmp(valor_no->tipo, "STRING") == 0) {
                    erro_semantico("Variável char deve receber um único caractere entre aspas simples", no->linha);
                    return;
                }
            }

            const char* tipo_expr = NULL;
            
            if (strcmp(valor_no->tipo, "ID") == 0) {
                for (int i = 0; i < tabela->quantidade; i++) {
                    if (strcmp(tabela->entradas[i].nome, valor_no->valor) == 0) {
                        tipo_expr = tabela->entradas[i].tipo;
                        break;
                    }
                }
            } else {
                tipo_expr = inferir_tipo_expressao(valor_no);
            }

            if (tipo_expr) {
                // Verifica atribuição de array/string para tipo primitivo
                if ((is_tipo_numerico(tipo_id) || strcmp(tipo_id, "char") == 0) && 
                    !strstr(tipo_id, "[") &&  // Adiciona esta verificação
                    (strstr(tipo_expr, "[") || strcmp(tipo_expr, "string") == 0)) {
                    char msg[200];
                    sprintf(msg, "Incompatibilidade de tipos (%s para %s)", tipo_expr, tipo_id);
                    erro_semantico(msg, no->linha);
                    return;
                }
                
                if (!verificar_compatibilidade_tipos(tipo_id, tipo_expr)) {
                    char msg[200];
                    sprintf(msg, "Atribuição inválida: não é possível atribuir expressão do tipo '%s' a variável do tipo '%s'", 
                            tipo_expr, tipo_id);
                    erro_semantico(msg, no->linha);
                    return;
                }
                
                // Aviso específico para possível perda de precisão
                if (strcmp(tipo_expr, "float") == 0 && strcmp(tipo_id, "int") == 0) {
                    erro_semantico("Atribuição inválida: possível perda de precisão ao atribuir float para int", no->linha);
                    return;
                }
            }
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
    // Verifica se algum dos operandos é string
    if ((tipo_esq && (strcmp(tipo_esq, "string") == 0 || strstr(tipo_esq, "char[") != NULL)) ||
        (tipo_dir && (strcmp(tipo_dir, "string") == 0 || strstr(tipo_dir, "char[") != NULL))) {
        erro_semantico("Não é possível realizar operações aritméticas com strings", linha);
        return;
    }
    
    // Primeiro verifica se é operação entre char e int/float ou vice-versa
    if ((strcmp(tipo_esq, "char") == 0 && is_tipo_numerico(tipo_dir)) ||
        (is_tipo_numerico(tipo_esq) && strcmp(tipo_dir, "char") == 0)) {
        erro_semantico("Não é possível realizar operações aritméticas entre char e tipos numéricos", linha);
        return;
    }

    // Depois verifica se ambos são tipos numéricos
    if (!is_tipo_numerico(tipo_esq) || !is_tipo_numerico(tipo_dir)) {
        char msg[200];
        sprintf(msg, "Operação aritmética inválida entre tipos '%s' e '%s'", tipo_esq, tipo_dir);
        erro_semantico(msg, linha);
        return;
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
        // Se não estiver dentro de uma função
        if (!tipo_funcao_atual) {
            erro_semantico("Retorno fora de contexto de função", no->linha);
            return;
        }

        const char* tipo_retorno = inferir_tipo_expressao(no->filhos[0]);
        
        if (!tipo_retorno) {
            // Se não conseguir inferir o tipo, tenta obter o tipo do nó diretamente
            tipo_retorno = no->filhos[0]->tipo;
        }

        if (strncmp(tipo_retorno, "NUM_", 4) == 0) {
            if (strstr(tipo_retorno, "INT")) tipo_retorno = "int";
            else if (strstr(tipo_retorno, "FLOAT")) tipo_retorno = "float";
        }

        // Conversões flexíveis
        if (strcmp(tipo_funcao_atual, "int") == 0) {
            if (strcmp(tipo_retorno, "char") == 0 || 
                strcmp(tipo_retorno, "float") == 0) {
                // Permite conversão com aviso
                printf("Aviso: conversão implícita de %s para int na linha %d\n", 
                       tipo_retorno, no->linha);
                return;
            }
        }
        else if (strcmp(tipo_funcao_atual, "float") == 0) {
            if (strcmp(tipo_retorno, "int") == 0 || 
                strcmp(tipo_retorno, "char") == 0) {
                // Permite conversão com aviso
                printf("Aviso: conversão implícita para float na linha %d\n", no->linha);
                return;
            }
        }
        else if (strcmp(tipo_funcao_atual, "char") == 0) {
            if (strcmp(tipo_retorno, "string") == 0) {
                return;  // Permite retornar string para função char
            }
        }

        // Verifica compatibilidade de tipos
        if (!verificar_compatibilidade_tipos(tipo_funcao_atual, tipo_retorno)) {
            char msg[200];
            sprintf(msg, "Tipo de retorno incompatível");
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
    if (!no || (strcmp(no->tipo, "IF") != 0 && strcmp(no->tipo, "IF_ELSE") != 0)) return;

    // Verifica a condição (primeiro filho)
    No* condicao = no->filhos[0];
    if (condicao) {
        const char* tipo_cond = inferir_tipo_expressao(condicao);
        
        // Verifica se é uma string
        if (tipo_cond && strcmp(tipo_cond, "string") == 0) {
            erro_semantico("Não é possível usar string como condição em if", no->linha);
            return;
        }

        // Verifica se a condição é uma expressão de comparação válida
        if (strcmp(condicao->tipo, "OPERADOR") == 0) {
            const char* op = condicao->valor;
            if (strcmp(op, "==") != 0 && strcmp(op, "!=") != 0 &&
                strcmp(op, "<") != 0 && strcmp(op, ">") != 0 &&
                strcmp(op, "<=") != 0 && strcmp(op, ">=") != 0 &&
                strcmp(op, "&&") != 0 && strcmp(op, "||") != 0) {
                erro_semantico("Operador inválido na condição do if", no->linha);
                return;
            }
        }
        // Se não for um operador, verifica se é um identificador ou número
        else if (strcmp(condicao->tipo, "ID") == 0) {
            // Verifica se o identificador foi declarado
            if (!verificar_variavel_declarada(tabela, condicao->valor)) {
                char msg[100];
                sprintf(msg, "Variável '%s' não foi declarada", condicao->valor);
                erro_semantico(msg, no->linha);
                return;
            }
        }
        else if (strcmp(condicao->tipo, "NUM_INT") != 0 && 
                 strcmp(condicao->tipo, "NUM_FLOAT") != 0 &&
                 strcmp(condicao->tipo, "CHAR") != 0) {
            erro_semantico("Expressão inválida na condição do if", no->linha);
            return;
        }
    }

    // Verifica o bloco then (segundo filho)
    if (no->num_filhos >= 2) {
        No* bloco_then = no->filhos[1];
        if (bloco_then && strcmp(bloco_then->tipo, "BLOCO") == 0) {
            No* comandos = bloco_then->filhos[0];
            if (comandos) {
                for (int i = 0; i < comandos->num_filhos; i++) {
                    No* comando = comandos->filhos[i];
                    // Verifica se é uma expressão solta (número, string, etc.)
                    if (strcmp(comando->tipo, "NUM_INT") == 0 ||
                        strcmp(comando->tipo, "NUM_FLOAT") == 0 ||
                        strcmp(comando->tipo, "STRING") == 0 ||
                        strcmp(comando->tipo, "CHAR") == 0) {
                        erro_semantico("Expressão inválida como instrução", comando->linha);
                    }
                }
            }
        }
    }

    // Se for IF_ELSE, verifica o bloco else (terceiro filho)
    if (strcmp(no->tipo, "IF_ELSE") == 0 && no->num_filhos >= 3) {
        No* bloco_else = no->filhos[2];
        if (bloco_else && strcmp(bloco_else->tipo, "BLOCO") == 0) {
            No* comandos = bloco_else->filhos[0];
            if (comandos) {
                for (int i = 0; i < comandos->num_filhos; i++) {
                    No* comando = comandos->filhos[i];
                    // Verifica se é uma expressão solta (número, string, etc.)
                    if (strcmp(comando->tipo, "NUM_INT") == 0 ||
                        strcmp(comando->tipo, "NUM_FLOAT") == 0 ||
                        strcmp(comando->tipo, "STRING") == 0 ||
                        strcmp(comando->tipo, "CHAR") == 0) {
                        erro_semantico("Expressão inválida como instrução", comando->linha);
                    }
                }
            }
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
        // Verifica a inicialização (primeiro filho)
        if (no->num_filhos >= 1) {
            No* init_no = no->filhos[0];
            if (init_no && strcmp(init_no->tipo, "ATRIBUICAO") == 0) {
                No* id_no = init_no->filhos[0]; // ID da variável
                No* tipo_no = init_no->filhos[1]; // Tipo da variável (se existir)

                if (id_no && strcmp(id_no->tipo, "ID") == 0) {
                    // Verifica se é uma declaração com tipo
                    if (init_no->num_filhos > 2 && strcmp(tipo_no->tipo, "TIPO") == 0) {
                        adicionar_simbolo(escopo_atual->tabela, id_no->valor, tipo_no->valor, "variavel", no->linha);
                    } else {
                        // Se não for uma declaração, verifica se já foi declarada
                        if (!verificar_variavel_declarada(escopo_atual->tabela, id_no->valor) &&
                            !verificar_variavel_declarada(tabela, id_no->valor)) {
                            char msg[100];
                            sprintf(msg, "Variável '%s' usada no FOR não foi declarada", id_no->valor);
                            erro_semantico(msg, no->linha);
                        }
                    }
                }
            }
        }

        // Verifica condição (segundo filho)
        if (no->num_filhos >= 2) {
            No* cond_no = no->filhos[1];
            if (cond_no) {
                if (strcmp(cond_no->tipo, "OPERADOR") != 0 ||
                    !(strcmp(cond_no->valor, "<") == 0 || strcmp(cond_no->valor, ">") == 0 ||
                    strcmp(cond_no->valor, "==") == 0 || strcmp(cond_no->valor, "!=") == 0 ||
                    strcmp(cond_no->valor, "<=") == 0 || strcmp(cond_no->valor, ">=") == 0)) {
                    erro_semantico("Condição do 'for' deve ser uma comparação válida", no->linha);
                }
            }
        }

        // Verifica o incremento/decremento (terceiro filho)
        if (no->num_filhos >= 3) {
            No* inc_no = no->filhos[2];
            if (inc_no) {
                if (!((strcmp(inc_no->tipo, "OPERADOR_PRE") == 0 || strcmp(inc_no->tipo, "OPERADOR_POS") == 0) &&
                    (strcmp(inc_no->valor, "++") == 0 || strcmp(inc_no->valor, "--") == 0))) {
                    erro_semantico("Expressão de incremento ou decremento inválida no 'for'", no->linha);
                }
            }
        }
    }

}

void verificar_chamada_funcao(No* no) {
    if (!no || strcmp(no->tipo, "CHAMADA_FUNCAO") != 0) return;

    const char* nome_funcao = no->valor;

    // Verifica se a função existe
    bool funcao_encontrada = false;
    for (int i = 0; i < tabela->quantidade; i++) {
        if (strcmp(tabela->entradas[i].nome, nome_funcao) == 0 && 
            strcmp(tabela->entradas[i].categoria, "funcao") == 0) {
            funcao_encontrada = true;
            break;
        }
    }

    if (!funcao_encontrada) {
        char msg[100];
        sprintf(msg, "Função '%s' não declarada", nome_funcao);
        erro_semantico(msg, no->linha);
        return;
    }

    // Verifica os parâmetros
    No* parametros = no->filhos[0];
    if (parametros && strcmp(parametros->tipo, "PARAMETROS") == 0) {
        // Se tem parâmetros, verifica seus tipos
        if (parametros->num_filhos > 0 && 
            strcmp(parametros->filhos[0]->tipo, "LISTA_PARAMETROS") == 0) {
            No* lista_parametros = parametros->filhos[0];
            
            // Verifica cada parâmetro passado
            for (int j = 0; j < lista_parametros->num_filhos; j++) {
                No* parametro = lista_parametros->filhos[j];
                
                // Obtém o tipo da expressão do parâmetro
                const char* tipo_expressao = inferir_tipo_expressao(parametro->filhos[1]);
                
                if (!tipo_expressao) {
                    char msg[100];
                    sprintf(msg, "Não foi possível inferir o tipo do parâmetro %d na função '%s'", 
                            j + 1, nome_funcao);
                    erro_semantico(msg, no->linha);
                }
            }
        }
    }
}

void verificar_funcao(No* no) {
    if (!no || strcmp(no->tipo, "FUNCAO") != 0) return;

    // Extrai o tipo de retorno da função
    const char* tipo_retorno = no->filhos[0]->valor;

    // Nome da função (segundo parâmetro)
    const char* nome_funcao = no->valor;

    // Verifica declarações duplicadas de função
    verificar_declaracao_duplicada(tabela, nome_funcao, no->linha);

    // Verifica os parâmetros
    if (no->num_filhos >= 2) {
        No* parametros = no->filhos[1];  // Nó de PARAMETROS
        
        // Conjunto para verificar parâmetros duplicados
        TabelaSimbolos* tabela_parametros = criar_tabela_simbolos();

        if (parametros && strcmp(parametros->tipo, "PARAMETROS") == 0) {
            // Se os parâmetros não estão vazios
            if (parametros->num_filhos > 0 && 
                strcmp(parametros->filhos[0]->tipo, "LISTA_PARAMETROS") == 0) {
                
                No* lista_parametros = parametros->filhos[0];

                // Percorre os parâmetros
                for (int i = 0; i < lista_parametros->num_filhos; i++) {
                    No* parametro = lista_parametros->filhos[i];
                    
                    if (strcmp(parametro->tipo, "PARAMETRO") == 0) {
                        // Tipo do parâmetro (primeiro filho)
                        const char* tipo_parametro = parametro->filhos[0]->valor;
                        
                        // Nome do parâmetro (valor do nó)
                        const char* nome_parametro = parametro->valor;

                        // Verifica parâmetros duplicados
                        verificar_declaracao_duplicada(tabela_parametros, nome_parametro, parametro->linha);

                        // Adiciona o parâmetro à tabela de parâmetros 
                        adicionar_simbolo(tabela_parametros, nome_parametro, tipo_parametro, "parametro", parametro->linha);
                        
                        // Adiciona o parâmetro à tabela de símbolos global
                        adicionar_simbolo(tabela, nome_parametro, tipo_parametro, "parametro", parametro->linha);
                        
                        // Adiciona o parâmetro à tabela de símbolos do escopo atual
                        adicionar_simbolo(escopo_atual->tabela, nome_parametro, tipo_parametro, "parametro", parametro->linha);
                    }
                }
            }
        }

        // Libera a tabela temporária de parâmetros
        liberar_tabela(tabela_parametros);
    }

    // Adiciona a função à tabela de símbolos apenas se não for main
    if (strcmp(nome_funcao, "main") != 0) {
        adicionar_simbolo(tabela, nome_funcao, tipo_retorno, "funcao", no->linha);
    }

    // Verificações específicas para a função main
    if (strcmp(nome_funcao, "main") == 0) {
        // Verifica o tipo de retorno da main (permite int ou void)
        if (strcmp(tipo_retorno, "int") != 0 && strcmp(tipo_retorno, "void") != 0) {
            char msg[200];
            sprintf(msg, "Função main deve retornar 'int' ou 'void', encontrado '%s'", tipo_retorno);
            erro_semantico(msg, no->linha);
        }
    }

    // Define o tipo de retorno global para verificações posteriores
    if (tipo_funcao_atual) free(tipo_funcao_atual);
    tipo_funcao_atual = strdup(tipo_retorno);
}

void registrar_variavel_for(No* no) {
    if (!no || strcmp(no->tipo, "FOR") != 0) return;

    No* init_no = no->filhos[0]; // Primeiro filho: inicialização
    if (init_no && strcmp(init_no->tipo, "ATRIBUICAO") == 0) {
        No* id_no = init_no->filhos[0]; // ID da variável
        if (init_no->num_filhos >= 3) {  // Se tiver tipo na declaração
            No* tipo_no = init_no->filhos[1];
            if (id_no && strcmp(id_no->tipo, "ID") == 0 && 
                tipo_no && strcmp(tipo_no->tipo, "TIPO") == 0) {
                adicionar_simbolo(escopo_atual->tabela, id_no->valor, tipo_no->valor, "variavel", no->linha);
                id_no->verificado = 1;
            }
        }
    }
}


void analisar_no(No* no) {
    if (!no || no->verificado) return;

    if (strcmp(no->tipo, "ID") == 0 && !no->verificado) {
    verificar_identificador(no);
    }

    if (strcmp(no->tipo, "FUNCAO") == 0) {
        verificar_funcao(no);
    }

    if (strcmp(no->tipo, "CHAMADA_FUNCAO") == 0) {
        verificar_chamada_funcao(no);
    }
    
    if (strcmp(no->tipo, "FOR") == 0) {
        criar_escopo();               // Cria um novo escopo para o FOR
        registrar_variavel_for(no);   // Registra a variável do FOR no escopo
        verificar_repeticao(no);      // Verifica condições do FOR
        
        // Processa os filhos dentro do escopo do FOR
        for (int i = 0; i < no->num_filhos; i++) {
            analisar_no(no->filhos[i]);
        }
        
        liberar_escopo();             // Remove o escopo ao sair do FOR
        return;
    }

    // Verifica condição do IF ou IF_ELSE
    if (strcmp(no->tipo, "IF") == 0 || strcmp(no->tipo, "IF_ELSE") == 0) {
    verificar_condicional(no);
    }
    
    // Verificações normais para outros tipos de nós
    if (strcmp(no->tipo, "OPERADOR") == 0) verificar_tipo_operacao(no);
    else if (strcmp(no->tipo, "ID") == 0) {
        if (no->pai && strcmp(no->pai->tipo, "DECLARACAO_VAR") != 0 && 
            strcmp(no->pai->tipo, "PARAMETRO") != 0) {
            verificar_identificador(no);
        }
    }
    else if (strcmp(no->tipo, "DECLARACAO_VAR") == 0) {
        verificar_atribuicao(no);  // Verifica declaração com atribuição
    }
    else if (strcmp(no->tipo, "ATRIBUICAO") == 0) verificar_atribuicao(no);
    else if (strcmp(no->tipo, "WHILE") == 0) verificar_repeticao(no);
    else if (strcmp(no->tipo, "RETURN") == 0) verificar_return(no);
    else if (strcmp(no->tipo, "SCAN") == 0) verificar_scan(no);
    else if (strcmp(no->tipo, "ACESSO_VETOR") == 0 || strcmp(no->tipo, "ATRIBUICAO_VETOR") == 0) {
        verificar_acesso_vetor(no);
    }
    else if (strcmp(no->tipo, "DECLARACAO_VETOR") == 0) {
        // Se tiver inicialização (lista de valores)
        if (no->num_filhos >= 2 && no->filhos[1] && 
            strcmp(no->filhos[1]->tipo, "LISTA_VALORES") == 0) {
            
            // Extrai o tipo base e tamanho do vetor
            char* tipo_str = strdup(no->filhos[0]->valor);
            int tamanho_vetor = 0;
            
            // Extrai o tamanho do vetor do nome do nó
            char* valor_no = strdup(no->valor);
            char* inicio = strchr(valor_no, '[');
            if (inicio) {
                inicio++; // Pula o '['
                char* fim = strchr(inicio, ']');
                if (fim) {
                    *fim = '\0';
                    tamanho_vetor = atoi(inicio);
                }
            }
            free(valor_no);
            
            // Remove qualquer '[' do tipo
            char* colchete = strchr(tipo_str, '[');
            if (colchete) {
                *colchete = '\0';
            }
            
            // Verifica a compatibilidade dos valores e o tamanho
            verificar_lista_valores(no->filhos[1], tipo_str, tamanho_vetor);
            
            free(tipo_str);
        }
    }
    
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
    int resultado_parse = yyparse();

    // Inicia a análise semântica apenas se não houver erros léxicos ou sintáticos
    if (erros_lexicos == 0 && erros_sintaticos == 0 && resultado_parse == 0) {
        // Não precisa imprimir mensagem aqui, pois a análise semântica é parte da análise geral
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
