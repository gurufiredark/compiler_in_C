%{
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

%type <no> programa declaracoes declaracao declaracao_variavel tipo lista_valores
%type <no> declaracao_funcao bloco comandos comando expressao
%type <no> atribuicao comando_if comando_while comando_for atribuicao_for
%type <no> parametros lista_parametros parametro
%type <no> includes include_stmt
%type <no> return_stmt
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
    | tipo ID '=' expressao ';'
    {
        $$ = criar_no("DECLARACAO_VAR", $2);
        adicionar_filho($$, $1);
        adicionar_filho($$, $4);
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    | tipo ID '=' ID '(' parametros ')' ';'  // Chamada de função
    {
        $$ = criar_no("DECLARACAO_VAR", $2);
        adicionar_filho($$, $1); 
        
        // Cria o nó de chamada de função
        No* chamada_funcao = criar_no("CHAMADA_FUNCAO", $4);
        adicionar_filho(chamada_funcao, $6);
        adicionar_filho($$, chamada_funcao); 
        
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    | tipo ID '[' NUM_INT ']' ';'  /* vetor com tamanho específico */
    {
        char temp[32];
        sprintf(temp, "%s[%d]", $2, $4);
        $$ = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho($$, $1);
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[%d]", $1->valor, $4);
        adicionar_simbolo(tabela, $2, tipo_vetor, "vetor", linha);
    }
    | tipo ID '[' NUM_INT ']' '=' '[' lista_valores ']' ';'  /* vetor com inicialização de valores */
    {
        char temp[32];
        sprintf(temp, "%s[%d]", $2, $4);
        $$ = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho($$, $1);
        adicionar_filho($$, $8);
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[%d]", $1->valor, $4);
        adicionar_simbolo(tabela, $2, tipo_vetor, "vetor", linha);
    }
    | tipo ID '[' ']' ';'  /* vetor sem tamanho específico */
    {
        char temp[32];
        sprintf(temp, "%s[]", $2);
        $$ = criar_no("DECLARACAO_VETOR", temp);
        adicionar_filho($$, $1);
        char tipo_vetor[32];
        sprintf(tipo_vetor, "%s[]", $1->valor);
        adicionar_simbolo(tabela, $2, tipo_vetor, "vetor", linha);
    }
    | tipo ID '[' ']' '=' STRING ';'  /* string com inicialização sem tamanho explícito */
    {
        $$ = criar_no("DECLARACAO_STRING", $2);
        adicionar_filho($$, $1);
        adicionar_filho($$, criar_no("STRING", $6));
        adicionar_simbolo(tabela, $2, $1->valor, "variavel", linha);
    }
    ;

lista_valores:
    NUM_INT
    {
        $$ = criar_no("LISTA_VALORES", "");
        char valor[32];
        sprintf(valor, "%d", $1);
        adicionar_filho($$, criar_no("NUM_INT", valor));
    }
    | lista_valores ',' NUM_INT
    {
        $$ = $1;
        char valor[32];
        sprintf(valor, "%d", $3);
        adicionar_filho($$, criar_no("NUM_INT", valor));
    }
    |NUM_FLOAT
    {
        $$ = criar_no("LISTA_VALORES", "");
        char valor[32];
        sprintf(valor, "%f", $1);
        adicionar_filho($$, criar_no("NUM_FLOAT", valor));
    }
    | lista_valores ',' NUM_FLOAT
    {
        $$ = $1;
        char valor[32];
        sprintf(valor, "%f", $3);
        adicionar_filho($$, criar_no("NUM_FLOAT", valor));
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
    | expressao
    {
        $$ = criar_no("LISTA_PARAMETROS", "");
        adicionar_filho($$, $1);
    }
    | parametro ',' lista_parametros
    {
        $$ = $3;
        adicionar_filho($$, $1);
    }
    | expressao  ',' lista_parametros
    {
        $$ = $1;
        adicionar_filho($$, $3);
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
    | return_stmt { $$ = $1; }
    | expressao ';' { $$ = $1; }
    ;

return_stmt:
    RETURN expressao ';'
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
        adicionar_filho($$, $3);
        adicionar_filho($$, $5);
        adicionar_filho($$, $7);
        adicionar_filho($$, $9);
    }
    ;

atribuicao_for:
    tipo ID '=' expressao  // Declaração com tipo
    {
        $$ = criar_no("ATRIBUICAO", "");
        adicionar_filho($$, criar_no("ID", $2));
        adicionar_filho($$, $1);  // Adiciona o tipo
        adicionar_filho($$, $4);  // Adiciona a expressão
    }
    | ID '=' expressao     // Atribuição simples
    {
        $$ = criar_no("ATRIBUICAO", "");
        adicionar_filho($$, criar_no("ID", $1));
        adicionar_filho($$, $3);
    }
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
    | ID '(' parametros ')'
    {
        $$ = criar_no("CHAMADA_FUNCAO", $1);
        adicionar_filho($$, $3);  // Adiciona a lista de argumentos como filho
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