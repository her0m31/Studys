/* main5.c */
#include <stdio.h>
#include "lhs.h"

int main()
{
  struct cell *head = NULL, **p;
  int data;
  int i;
  int n;
  
  for( i = 1; scanf("%d", &data) != EOF; i++ ) {
    for( p = &head; *p != NULL; p = &((*p)->next) );
    if( (insert(p, data)) == 0 )
      return 0;
  }
  
  heapsort(&head, i-1);
  
  for(p = &head;  *p != NULL;   p = &((*p)->next))
    printf("%d ", (*p)->value);
  printf("\n");
  
  return 0;
}
