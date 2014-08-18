/* main3.c */
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main()
{
  struct cell *head = NULL, **p;
  int data;
  
  while(scanf("%d", &data) != EOF) {
    for(p = &head; (*p != NULL)/* && (data > (*p)->value)*/; p = &((*p)->next));
    
    if( insert_cell(p, data) == 0 )
      return 0;
  }
  
  for(p = &head;  *p != NULL;   p = &((*p)->next))
    printf("%d ", (*p)->value);
  printf("\n");
  
  p = &head;
  while( *p != NULL){
    if( ((*p)->value % 2) != 0 )
      delete_cell(p);
    else
      p = &((*p)->next);
  }
  
  for(p = &head;  *p != NULL;   p = &((*p)->next))
    printf("%d ", (*p)->value);
  printf("\n");
 
  return 0;
}
