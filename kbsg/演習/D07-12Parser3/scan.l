/* cat scan1.l */
%{
#include "y.tab.h"
extern int yylval;
%}

%%
[\t ]+ 			{ }
"+"			{ return PLUS;}
"*"			{ return TIMES;}
"("			{ return LPAR;}
")"			{ return RPAR;}
[a-z][a-z0-9]*		{ yylval = copy_lexeme();
			  return IDENTIFIER; }
\n			{ return 0;}
.			{ printf("lexical error: '%c' \n", yytext[0]);
			  return 0; }
%%
