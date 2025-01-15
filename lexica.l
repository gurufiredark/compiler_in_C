%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

int linha = 1;
int erros_lexicos = 0;

void erro_lexico(const char* msg) {
    fprintf(stderr, "Erro léxico na linha %d: %s - Token: '%s'\n", linha, msg, yytext);
    erros_lexicos++;
}

#define YY_NO_INPUT
#define YY_NO_UNPUT

%}

%x COMENTARIO_BLOCO
%x STRING_INTERPOLACAO
%x INSIDE_INTERPOLACAO

%%
[ \t\r]                  ;  /* Ignora espaços, tabs e retorno de carro */
[\n]                     { linha++; }

"//".*                   ;

"/*"                     { BEGIN(COMENTARIO_BLOCO); }
<COMENTARIO_BLOCO>"*/"   { BEGIN(INITIAL); }
<COMENTARIO_BLOCO>\n     { linha++; }
<COMENTARIO_BLOCO>.      ;

"int"                    { return TIPO_INT; }
"float"                  { return TIPO_FLOAT; }
"char"                   { return TIPO_CHAR; }
"string"                 { return TIPO_STRING; }
"void"                   { return VOID; }

"if"                     { return IF; }
"else"                   { return ELSE; }
"while"                  { return WHILE; }
"for"                    { return FOR; }
"return"                 { return RETURN; }
"print"                  { return PRINT; }
"scan"                   { return SCAN; }

"main"                   { return MAIN; }
"include"                { return INCLUDE; }

[0-9]+                   { yylval.ival = atoi(yytext); return NUM_INT; }
[0-9]+"."[0-9]+         { yylval.fval = atof(yytext); return NUM_FLOAT; }
\'[^\']\'               { yylval.sval = strdup(yytext); return CHAR; }

\"\$                     { BEGIN(STRING_INTERPOLACAO); yylval.sval = strdup(""); return STRING_START; }
\"[^\"$][^\"]*\"        { yylval.sval = strdup(yytext); return STRING; }

<STRING_INTERPOLACAO>\$\{ { BEGIN(INSIDE_INTERPOLACAO); return INTERPOLACAO_START; }
<STRING_INTERPOLACAO>\"  { BEGIN(INITIAL); return STRING_END; }
<STRING_INTERPOLACAO>[^\"\$]+  { yylval.sval = strdup(yytext); return STRING_TEXT; }
<STRING_INTERPOLACAO>\$[^\{]  { yylval.sval = strdup(yytext); return STRING_TEXT; }

<INSIDE_INTERPOLACAO>\}  { BEGIN(STRING_INTERPOLACAO); return INTERPOLACAO_END; }
<INSIDE_INTERPOLACAO>[^}]+  { yylval.sval = strdup(yytext); return ID; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.sval = strdup(yytext); return ID; }

"+"                      { return '+'; }
"++"                     { return INC; }
"-"                      { return '-'; }
"--"                     { return DEC; }
"*"                      { return '*'; }
"/"                      { return '/'; }
"="                      { return '='; }
"=="                     { return IGUAL; }
"!="                     { return DIFERENTE; }
"<"                      { return MENOR; }
">"                      { return MAIOR; }
"<="                     { return MENOR_IGUAL; }
">="                     { return MAIOR_IGUAL; }
"&&"                     { return E; }
"||"                     { return OU; }
"!"                      { return NAO; }

"("                      { return '('; }
")"                      { return ')'; }
"{"                      { return '{'; }
"}"                      { return '}'; }
"["                      { return '['; }
"]"                      { return ']'; }
";"                      { return ';'; }
","                      { return ','; }
"."                      { return '.'; }
"&"                      { return '&'; }
"^"                      { return '^'; }
"%"                      { return '%'; }
"$"                      { return '$'; }
"#"                      { return '#'; }

.                        { erro_lexico("Caractere inválido"); }

%%

int yywrap() {
    return 1;
}