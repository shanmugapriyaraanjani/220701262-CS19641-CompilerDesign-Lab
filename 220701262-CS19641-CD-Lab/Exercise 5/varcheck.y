%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);

%}

%union {
    char *str;
}

%token <str> IDENTIFIER

%%

input:
    IDENTIFIER   { printf("Valid variable name: %s\n", $1); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Invalid variable name\n");
}
