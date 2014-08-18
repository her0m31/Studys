%{
#include <stdio.h>
#include "y.tab.h"
%}
id        [a-zA-Z][a-zA-Z0-9]*
wspc      [ \t\n]+
semi      [;]
comma     [,]

%%

int       { printf("len=%d, \t token(int)=`%s`\n", yyleng, yytext); 
	    return INT; }
char      { printf("len=%d, \t token(char)=`%s`\n", yyleng, yytext); 
	    return CHAR; }
float     { printf("len=%d, \t token(float)=`%s`\n", yyleng, yytext); 
	    return FLOAT; }
{comma}   { printf("len=%d, \t token(comma)=`%s`\n", yyleng, yytext); 
	    return COMMA; }
{semi}    { printf("len=%d, \t token(semi)=`%s`\n", yyleng, yytext); 
	    return SEMI; }
{id}      { printf("len=%d, \t token(id)=`%s`\n", yyleng, yytext); 
	    return ID;}
{wspc}    { ;}
.	  { ;}
%%

int yywrap(void) {
    return 1;
}
