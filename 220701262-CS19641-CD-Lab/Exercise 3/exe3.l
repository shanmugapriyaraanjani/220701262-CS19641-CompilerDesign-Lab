%{
#include <stdio.h>
#include <string.h>

int line = 1;

char *keywords[] = {
    "int", "float", "if", "else", "while", "for", "return", "void", "char", "double"
};

int isKeyword(char *word) {
    for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}
%}

%%

"//".*                      { printf("Single-line Comment: %s\n", yytext); }
"/*"(.|\n)*"*/"            { printf("Multi-line Comment: %s\n", yytext); }

[ \t]+                    ;  // Ignore whitespace
\n                        { line++; }

"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/" {
                             printf("Operator: %s\n", yytext);
                         }

"{"                      { printf("Special Symbol: {\n"); }
"}"                      { printf("Special Symbol: }\n"); }
"("                      { printf("Special Symbol: (\n"); }
")"                      { printf("Special Symbol: )\n"); }
";"                      { printf("Special Symbol: ;\n"); }
","                      { printf("Special Symbol: ,\n"); }

[0-9]+\.[0-9]+           { printf("Float Constant: %s\n", yytext); }
[0-9]+                   { printf("Integer Constant: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*   {
                             if (isKeyword(yytext))
                                 printf("Keyword: %s\n", yytext);
                             else
                                 printf("Identifier: %s\n", yytext);
                         }

.                        { printf("Unknown Token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter C code (Ctrl+D to end):\n");
    yylex();
    return 0;
}
