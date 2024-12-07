%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

int linha = 1;
extern int erros_lexicos;


#define YY_NO_INPUT
#define YY_NO_UNPUT

%}

%x COMENTARIO_BLOCO

%%
[ \t]                    ;
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

"main"                   { return MAIN; }
"include"                { return INCLUDE; }

[0-9]+                   { printf("Número inteiro (INT) encontrado: %s\n", yytext); yylval.ival = atoi(yytext); return NUM_INT; }
[0-9]+"."[0-9]+         { yylval.fval = atof(yytext); return NUM_FLOAT; }
\"[^\"]*\"              { yylval.sval = strdup(yytext); return STRING; }
\'[^\']\'               { yylval.sval = strdup(yytext); return CHAR; }

[a-zA-Z_][a-zA-Z0-9_]*  { printf("Identificador (ID) encontrado: %s\n", yytext); yylval.sval = strdup(yytext); return ID; }

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
"@"                      { return '@'; }

%%

int yywrap() {
    return 1;
}