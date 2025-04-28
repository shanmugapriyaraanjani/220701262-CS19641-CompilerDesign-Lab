%{
#include "y.tab.h"
%}

%%
[0-9]+        { yylval.val = atoi(yytext); return NUMBER; }
[ \t]+        ;         // skip spaces and tabs
\n            { return '\n'; }  // return newline to trigger YACC evaluation
.             { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
