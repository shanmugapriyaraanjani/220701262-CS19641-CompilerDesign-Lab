%{
#include <stdio.h>
#include <stdlib.h>

float result = 0;
%}

%%

[0-9]+\.[0-9]+     { result = atof(yytext); printf("Number: %f\n", result); }
[0-9]+             { result = atoi(yytext); printf("Number: %d\n", atoi(yytext)); }

"+"                { printf("Operator: +\n"); }
"-"                { printf("Operator: -\n"); }
"*"                { printf("Operator: *\n"); }
"/"                { printf("Operator: /\n"); }

"("                { printf("Left Paren: (\n"); }
")"                { printf("Right Paren: )\n"); }

[ \t\n]+           ;  // Ignore whitespace

.                  { printf("Invalid token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter an arithmetic expression (Ctrl+D to finish):\n");
    yylex();
    return 0;
}
