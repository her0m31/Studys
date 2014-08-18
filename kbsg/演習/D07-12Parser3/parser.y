%{
#include <stdio.h>
%}

%token PLUS TIMES LPAR RPAR IDENTIFIER
%%
E:	E PLUS T	{ $$ = make_tuple("+", $1, $3); }
	| T		{ $$ = $1; }
T:	T TIMES F	{ $$ = make_tuple("*", $1, $3); }
	| F		{ $$ = $1; }
F:	LPAR E RPAR	{ $$ = $2; }
	| IDENTIFIER	{ $$ = $1; }
%%
main() {
  yyparse();
}

yyerror(char *msg) {
   printf("%s\n", msg);
}
