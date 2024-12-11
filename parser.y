%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

%}

%union {
    struct No* no;
    int ival;
    float fval;
    char* sval;
}

%token <sval> TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_STRING VOID
%token <sval> IF ELSE WHILE FOR
%token <sval> RETURN MAIN INCLUDE PRINT SCAN
%token <ival> NUM_INT
%token <fval> NUM_FLOAT
%token <sval> STRING CHAR ID
%token <sval> IGUAL DIFERENTE MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL
%token <sval> E OU NAO INC DEC

%token <sval> STRING_START STRING_END STRING_TEXT
%token <sval> INTERPOLACAO_START INTERPOLACAO_END

%right '='
%left OU
%left E
%left IGUAL DIFERENTE
%left MENOR MAIOR MENOR_IGUAL MAIOR_IGUAL
%left '+' '-'
%left '*' '/' '%'
%right NAO
%right INC DEC
%left '(' ')'

%type <no> programa declaracoes declaracao declaracao_variavel tipo
%type <no> declaracao_funcao bloco comandos comando expressao
%type <no> atribuicao comando_if comando_while comando_for atribuicao_for
%type <no> parametros lista_parametros parametro
%type <no> includes include_stmt
%type <no> comando_print comando_scan
%type <no> string_interpolada partes_string parte_string

%%

programa: 
    includes declaracoes 
    {
        $$ = criar_no("PROGRAMA", "");
        adicionar_filho($$, $1);
        adicionar_filho($$, $2);
        raiz = $$;
    }
    ;

includes:
    
    {
        $$ = criar_no("INCLUDES", "");
    }
    | includes include_stmt 
    {
        $$ = $2;
        adicionar_filho($$, $1);
    }
    ;

include_stmt:
    '#' INCLUDE MENOR ID '.' ID MAIOR
    {
        char include_name[100];
        sprintf(include_name, "%s.%s", $4, $6);
        $$ = criar_no("INCLUDE", include_name);
    }
    ;

declaracoes: 
    declaracao 
    { 
        $$ = criar_no("DECLARACOES", "");
        adicionar_filho($$, $1);
    }
    | declaracao declaracoes
    {
        $$ = $2;
        adicionar_filho($$, $1);
    }
    ;

declaracao:
    declaracao_variavel 
    { 
        $$ = $1;
    }
    | declaracao_funcao 
    { 
        $$ = $1;
    }
    ;

declaracao_variavel:
    tipo ID ';'
    {
        $$ = criar_no("DECLARACAO_VAR", $2);
        adicionar_filho($$, $1);
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    | tipo ID '[' NUM_INT ']' ';'  /* vetor com tamanho específico */
    {
        char temp[32];
        sprintf(temp, "%s[%d]", $2, $4);
        $$ = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho($$, $1);
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    | tipo ID '[' ']' ';'  /* vetor sem tamanho específico */
    {
        char temp[32];
        sprintf(temp, "%s[]", $2);
        $$ = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho($$, $1);
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    | tipo ID '[' ']' '=' STRING ';'  /* string com inicialização sem tamanho explícito */
    {
        $$ = criar_no("DECLARACAO_STRING", $2);
        adicionar_filho($$, $1);
        adicionar_filho($$, criar_no("STRING", $6));
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    ;

tipo:
    TIPO_INT    
    { 
        $$ = criar_no("TIPO", "int");
    }
    | TIPO_FLOAT 
    { 
        $$ = criar_no("TIPO", "float");
    }
    | TIPO_CHAR  
    { 
        $$ = criar_no("TIPO", "char");
    }
    | TIPO_STRING 
    { 
        $$ = criar_no("TIPO", "string");
    }
    | VOID      
    { 
        $$ = criar_no("TIPO", "void");
    }
    ;

declaracao_funcao:
    tipo ID '(' parametros ')' bloco
    {
        $$ = criar_no("FUNCAO", $2);
        adicionar_filho($$, $1);
        adicionar_filho($$, $4);
        adicionar_filho($$, $6);
        adicionar_simbolo(tabela, $2, $1->valor, "funcao", linha);
    }
    | tipo MAIN '(' ')' bloco
    {
        $$ = criar_no("FUNCAO", "main");
        adicionar_filho($$, $1);
        adicionar_filho($$, $5);
        adicionar_simbolo(tabela, "main", $1->valor, "funcao", linha);
    }
    ;

parametros:
    /* vazio */
    {
        $$ = criar_no("PARAMETROS", "");
    }
    | lista_parametros
    {
        $$ = criar_no("PARAMETROS", "");
        adicionar_filho($$, $1);
    }
    ;

lista_parametros:
    parametro
    {
        $$ = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho($$, $1);
    }
    | parametro ',' lista_parametros
    {
        $$ = $3;
        adicionar_filho($$, $1);
    }
    ;

parametro:
    tipo ID
    {
        $$ = criar_no("PARAMETRO", $2);
        adicionar_filho($$, $1);
    }
    ;

bloco:
    '{' comandos '}'
    {
        $$ = criar_no("BLOCO", "");
        adicionar_filho($$, $2);
    }
    ;

comandos:
    /* vazio */
    {
        $$ = criar_no("COMANDOS", "");
    }
    | comando comandos
    {
        $$ = criar_no("COMANDOS", "");
        adicionar_filho($$, $1);
        adicionar_filho($$, $2);
    }
    | declaracao_variavel comandos
    {
        $$ = criar_no("COMANDOS", "");
        adicionar_filho($$, $1);
        adicionar_filho($$, $2);
    }
    ;

comando:
    atribuicao { $$ = $1; }
    | comando_if { $$ = $1; }
    | comando_while { $$ = $1; }
    | comando_for { $$ = $1; }
    | comando_print { $$ = $1; }
    | comando_scan { $$ = $1; }
    | RETURN expressao ';'
    {
        $$ = criar_no("RETURN", "");
        adicionar_filho($$, $2);
    }
    ;

comando_print:
    PRINT '(' string_interpolada ')' ';'
    {
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, $3);
    }
    | PRINT '(' ID ')' ';'  /* Apenas identificadores simples */
    {
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, criar_no("ID", $3));
    }
    | PRINT '(' NUM_INT ')' ';'  /* Números inteiros */
    {
        char valor[32];
        sprintf(valor, "%d", $3);
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, criar_no("NUM_INT", valor));
    }
    | PRINT '(' NUM_FLOAT ')' ';'  /* Números float */
    {
        char valor[32];
        sprintf(valor, "%f", $3);
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, criar_no("NUM_FLOAT", valor));
    }
    | PRINT '(' STRING ')' ';'  /* Strings literais simples */
    {
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, criar_no("STRING", $3));
    }
    | PRINT '(' CHAR ')' ';'  /* Caracteres */
    {
        $$ = criar_no("PRINT", "");
        adicionar_filho($$, criar_no("CHAR", $3));
    }
    ;

string_interpolada:
    STRING_START partes_string STRING_END
    {
        $$ = criar_no("STRING_INTERPOLADA", "");
        adicionar_filho($$, $2);
    }
    ;

partes_string:
    parte_string
    {
        $$ = criar_no("PARTES_STRING", "");
        adicionar_filho($$, $1);
    }
    | parte_string partes_string
    {
        $$ = $2;
        adicionar_filho($$, $1);
    }
    ;

parte_string:
    STRING_TEXT
    {
        $$ = criar_no("TEXTO", $1);
    }
    | INTERPOLACAO_START ID INTERPOLACAO_END
    {
        $$ = criar_no("INTERPOLACAO", "");
        adicionar_filho($$, criar_no("ID", $2));
    }
    ;

comando_scan:
    SCAN '(' ID ')' ';'
    {
        $$ = criar_no("SCAN", "");
        adicionar_filho($$, criar_no("ID", $3));
    }
    | SCAN '(' ID '[' expressao ']' ')' ';'
    {
        $$ = criar_no("SCAN_VETOR", "");
        adicionar_filho($$, criar_no("ID", $3));
        adicionar_filho($$, $5);  /* índice do vetor */
    }
    ;

comando_if:
    IF '(' expressao ')' bloco
    {
        $$ = criar_no("IF", "");
        adicionar_filho($$, $3);
        adicionar_filho($$, $5);
    }
    | IF '(' expressao ')' bloco ELSE bloco
    {
        $$ = criar_no("IF_ELSE", "");
        adicionar_filho($$, $3);
        adicionar_filho($$, $5);
        adicionar_filho($$, $7);
    }
    ;

comando_while:
    WHILE '(' expressao ')' bloco
    {
        $$ = criar_no("WHILE", "");
        adicionar_filho($$, $3);
        adicionar_filho($$, $5);
    }
    ;

comando_for:
    FOR '(' atribuicao_for ';' expressao ';' expressao ')' bloco
    {
        $$ = criar_no("FOR", "");
        adicionar_filho($$, $3); // inicialização
        adicionar_filho($$, $5); // condição
        adicionar_filho($$, $7); // incremento
        adicionar_filho($$, $9); // bloco
    }
    ;

atribuicao_for:
    ID '=' expressao
    {
        $$ = criar_no("ATRIBUICAO", "");
        adicionar_filho($$, criar_no("ID", $1));
        adicionar_filho($$, $3);
    }
    | tipo ID '=' expressao
    ;

atribuicao:
    ID '=' expressao ';'
    {
        $$ = criar_no("ATRIBUICAO", "");
        adicionar_filho($$, criar_no("ID", $1));
        adicionar_filho($$, $3);
    }
    | ID '[' expressao ']' '=' expressao ';'  /* Atribuição em posição específica do vetor */
    {
        $$ = criar_no("ATRIBUICAO_VETOR", "");
        adicionar_filho($$, criar_no("ID", $1));
        adicionar_filho($$, $3);  // índice
        adicionar_filho($$, $6);  // valor
    }
    | ID '=' STRING ';'  /* Atribuição direta de string */
    {
        $$ = criar_no("ATRIBUICAO_STRING", "");
        adicionar_filho($$, criar_no("ID", $1));
        adicionar_filho($$, criar_no("STRING", $3));
    }
    ;

expressao:
    NUM_INT
    {
        char valor[32];
        sprintf(valor, "%d", $1);
        $$ = criar_no("NUM_INT", valor);
    }
    | NUM_FLOAT
    {
        char valor[32];
        sprintf(valor, "%f", $1);
        $$ = criar_no("NUM_FLOAT", valor);
    }
    | ID 
    { 
        $$ = criar_no("ID", $1);
    }
    | STRING 
    { 
        $$ = criar_no("STRING", $1);
    }
    | CHAR 
    { 
        $$ = criar_no("CHAR", $1);
    }
    | ID '[' expressao ']'  /* Acesso a vetor/string */
    {
        $$ = criar_no("ACESSO_VETOR", $1);
        adicionar_filho($$, $3);
    }
    | expressao '+' expressao
    {
        $$ = criar_no("OPERADOR", "+");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao '-' expressao
    {
        $$ = criar_no("OPERADOR", "-");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao '*' expressao
    {
        $$ = criar_no("OPERADOR", "*");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao '/' expressao
    {
        $$ = criar_no("OPERADOR", "/");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao MAIOR expressao
    {
        $$ = criar_no("OPERADOR", ">");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao MENOR expressao
    {
        $$ = criar_no("OPERADOR", "<");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | '(' expressao ')'
    {
        $$ = $2;
    }
    | '-' expressao %prec NAO
    {
        $$ = criar_no("OPERADOR_UNARIO", "-");
        adicionar_filho($$, $2);
    }
    | expressao IGUAL expressao
    {
        $$ = criar_no("OPERADOR", "==");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao DIFERENTE expressao
    {
        $$ = criar_no("OPERADOR", "!=");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao MENOR_IGUAL expressao
    {
        $$ = criar_no("OPERADOR", "<=");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao MAIOR_IGUAL expressao
    {
        $$ = criar_no("OPERADOR", ">=");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao E expressao
    {
        $$ = criar_no("OPERADOR", "&&");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | expressao OU expressao
    {
        $$ = criar_no("OPERADOR", "||");
        adicionar_filho($$, $1);
        adicionar_filho($$, $3);
    }
    | NAO expressao
    {
        $$ = criar_no("OPERADOR", "!");
        adicionar_filho($$, $2);
    }
    | INC expressao
    {
        $$ = criar_no("OPERADOR_PRE", "++");
        adicionar_filho($$, $2);
    }
    | DEC expressao
    {
        $$ = criar_no("OPERADOR_PRE", "--");
        adicionar_filho($$, $2);
    }
    | expressao INC
    {
        $$ = criar_no("OPERADOR_POS", "++");
        adicionar_filho($$, $1);
    }
    | expressao DEC
    {
        $$ = criar_no("OPERADOR_POS", "--");
        adicionar_filho($$, $1);
    }
    ;

%%

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
    
    if (erros_lexicos == 0 && erros_sintaticos == 0) {
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
    return (erros_lexicos + erros_sintaticos) > 0 ? 1 : 0;
}