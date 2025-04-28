%{
#include "y.tab.h"
#include <string.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
.|\n                  { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
