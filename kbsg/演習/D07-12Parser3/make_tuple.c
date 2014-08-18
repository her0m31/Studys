#include <stdio.h>
#include <string.h>

int prev_tuple = 0;
int make_tuple( char *op, int arg1, int arg2 ) {
   printf("T%d: (%s, ", ++prev_tuple, op);
   if ( arg1 > 0) 
	printf("%s, ", arg1);
   else 
	printf("T%d, ", -arg1);

   if ( arg2 > 0 )
	printf("%s", arg2);
   else 
	printf("T%d", -arg2);
   printf(")\n");

   return -prev_tuple;
}
