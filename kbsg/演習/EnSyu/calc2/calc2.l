%{
#include "y.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

[a-z]	{	ECHO;
		printf(" -> ");
                yylval = *yytext - 'a';
                return VARIABLE;
	}

[0-9]+	{	ECHO;
		printf(" -> ");
                yylval = atoi(yytext);
                return INTEGER;
	}

[-+()=/*\n]     { ECHO; 
		  if (*yytext!='\n') printf(" -> \n");
		  return *yytext; 
                }

[ \t]   ;       /* skip whitespace */

.               { yyerror("Unknown character"); }

%%

int yywrap(void) {
    return 1;
}
