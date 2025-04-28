%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int temp_count = 0;

char* new_temp() {
    char* temp = malloc(10);
    sprintf(temp, "t%d", temp_count++);
    return temp;
}

void yyerror(const char *s);
int yylex(void);
%}

%union {
    char *str;
}

%token <str> ID NUM
%token ASSIGN PLUS MINUS MUL DIV LPAREN RPAREN SEMICOLON
%type <str> expr

%%

stmt:
    ID ASSIGN expr SEMICOLON {
        printf("%s = %s\n", $1, $3);
    }
    ;

expr:
    expr PLUS expr {
        char *temp = new_temp();
        printf("%s = %s + %s\n", temp, $1, $3);
        $$ = temp;
    }
    | expr MINUS expr {
        char *temp = new_temp();
        printf("%s = %s - %s\n", temp, $1, $3);
        $$ = temp;
    }
    | expr MUL expr {
        char *temp = new_temp();
        printf("%s = %s * %s\n", temp, $1, $3);
        $$ = temp;
    }
    | expr DIV expr {
        char *temp = new_temp();
        printf("%s = %s / %s\n", temp, $1, $3);
        $$ = temp;
    }
    | LPAREN expr RPAREN {
        $$ = $2;
    }
    | ID {
        $$ = $1;
    }
    | NUM {
        $$ = $1;
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}

int main() {
    printf("Enter an expression (e.g., a = b + c * d;):\n");
    yyparse();
    return 0;
}
