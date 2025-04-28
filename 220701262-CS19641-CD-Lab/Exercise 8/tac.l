%{
#include "y.tab.h"
%}

%%
[ \t\n]+                   ;  // ignore whitespace
"="                        { return ASSIGN; }
"("                        { return LPAREN; }
")"                        { return RPAREN; }
"+"                        { return PLUS; }
"-"                        { return MINUS; }
"*"                        { return MUL; }
"/"                        { return DIV; }
[a-zA-Z_][a-zA-Z0-9_]*     { yylval.str = strdup(yytext); return ID; }
[0-9]+                     { yylval.str = strdup(yytext); return NUM; }
";"                        { return SEMICOLON; }
.                          ;  // ignore unknown characters
%%

int yywrap() {
    return 1;
}
