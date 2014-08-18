%{
#include <stdio.h>
void yyerror(char *);
int yylex(void);

int sym[26];
%}

%token INTEGER VARIABLE
%left '+' '-'
%left '*' '/'

%%

program:
        program  statement '\n'		{ printf("result = %d\n", $2); }
        | /* NULL */
        ;

statement:
        expression                      { printf("expression -> statement \n"); $$ = $1;}
        | VARIABLE '=' expression       { printf("VARIABLE = expression -> statement\n"); sym[$1] = $3; }
        ;

expression:
        INTEGER				{ printf("INTEGER -> expression\n"); }
        | VARIABLE                      { printf("VARIABLE -> expression\n"); $$ = sym[$1]; }
        | expression '+' expression     { printf("expression + expression -> expression\n"); $$ = $1 + $3; }
        | expression '-' expression     { printf("expression - expression -> expression\n"); $$ = $1 - $3; }
        | expression '*' expression     { printf("expression * expression -> expression\n"); $$ = $1 * $3; }
        | expression '/' expression     { printf("expression / expression -> expression\n"); $$ = $1 / $3; }
        | '(' expression ')'            { printf("( expression ) -> expression\n"); $$ = $2; }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
}
