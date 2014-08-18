/* cat scan1.l */
%%
[\t ]+ 			{ }
"+"|"-"|"*"|"/"|"="	{ printf("%s (operator) ", yytext);}
";"			{ printf("%s (seaprator) ", yytext);}
[a-z][a-z0-9]*		{ printf("%s (identifier) ", yytext);}
[0-9\.]+		{ printf("%s (number) ", yytext);}
.			{ printf("%s (I don't know) ", yytext);}
%%
