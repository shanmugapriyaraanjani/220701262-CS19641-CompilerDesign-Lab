%{
#include "y.tab.h"
%}

%%
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"break"     { return BREAK; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }
":"         { return COLON; }

"="         { return ASSIGN; }
"<"         { return LT; }
"++"        { return INCR; }

\n          { return NEWLINE; }

[0-9]+      { return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }

[ \t\n]+    ;  // skip whitespace
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
