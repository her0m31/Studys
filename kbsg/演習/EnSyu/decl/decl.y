%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(char *);
%}

%start line
%token CHAR COMMA FLOAT ID INT SEMI

%%

line :	line decl	{ printf("successed!\n"); }
	| /* null */
     	;
decl :	type ID list
	;
list :	COMMA ID list 
     	| SEMI
     	;
type :	INT | CHAR | FLOAT
     	;

%%

extern FILE *yyin;
main() {
    do {
        yyparse();
    } while(!feof(yyin));
}

void yyerror(char *s) {
   printf("Syntax error\n");
}
