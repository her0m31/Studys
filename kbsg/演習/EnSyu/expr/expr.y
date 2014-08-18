%{
    #include <stdio.h>
    void yyerror(char *);
    int yylex(void);

    int sym[26];
%}

%start result
%token INTEGER VARIABLE
%left '+' '-'
%left '*' '/'

%%
result:	result expr '\n' 	{printf("result = %d\n", $2); }
	| /* null */
	;
expr:   expr '+' term     	{ printf("expr + term -> expr\n"); $$ = $1 + $3; }
        | term			{ printf("term -> expr\n"); $$ = $1; }
        ;

term:	term '*' factor 	{ printf("term * factor -> term\n"); $$ = $1 * $3; }
	| factor		{ printf("factor -> term\n"); $$ = $1; }
	;

factor:	'(' expr ')'		{ printf("( expr ) -> factor\n"); $$ = $2; }
	| INTEGER		{ printf("INTEGER -> factor\n");  $$ = $1; }
	| VARIABLE		{ printf("VARIABLE -> factor\n"); $$ = $1; }
	;
	
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
}
