%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex(void);
%}

%token IF ELSE WHILE FOR SWITCH CASE DEFAULT BREAK
%token IDENTIFIER NUMBER
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON
%token ASSIGN LT INCR
%token NEWLINE

%left ELSE
%nonassoc LOWER_THAN_ELSE

%%

program:
    statement NEWLINE { printf("Valid control structure\n"); }
    ;

statement:
      if_stmt
    | while_stmt
    | for_stmt
    | switch_stmt
    | block
    ;

if_stmt:
      IF LPAREN expr RPAREN statement %prec LOWER_THAN_ELSE
    | IF LPAREN expr RPAREN statement ELSE statement
    ;

while_stmt:
    WHILE LPAREN expr RPAREN statement
    ;

for_stmt:
    FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN statement
    ;

switch_stmt:
    SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE
    ;

case_list:
      case_list CASE NUMBER COLON statement
    | case_list DEFAULT COLON statement
    | /* empty */
    ;

expr:
      IDENTIFIER
    | NUMBER
    | IDENTIFIER ASSIGN expr
    | expr LT expr
    | expr INCR
    ;

