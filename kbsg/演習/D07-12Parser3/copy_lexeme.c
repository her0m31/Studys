#include <string.h>
extern char *yytext;

char StringTable[1000];
char *STp = StringTable;
int copy_lexeme() {
   int p = (int) STp;
   strcpy(STp, yytext);
   STp += strlen(yytext)+1;
   return p;
}
