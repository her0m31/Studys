/* lhs.c */
#include <stdlib.h>
#include "lhs.h"

struct cell **get_v(struct cell **head, int n)
{
  struct cell **p; 
  int i;

  p = head;
  for(i = 1; i != n; i++){
    if(*p == NULL)
      break;
    p = &((*p)->next);
  }
  
  return p;
}

int insert(struct cell **pointer, int new_value)
{
  struct cell *new_cell;
  
  new_cell = (struct cell *)malloc(sizeof(struct cell));
  if( new_cell == NULL )
    return 0;
  new_cell->value = new_value;
  new_cell->next  = *pointer;
  *pointer        = new_cell;
  return 1;
}

void downheap(struct cell **head, int v, int n)
{
  struct cell **p, **w;
  int temp;
   
  if(v > n/2)
    return; 
  
  p = get_v(head, v);
  v = 2*v;
  w = get_v(head, v);
  if( v+1 <= n && (*w)->value < (*w)->next->value ) {
    w = &((*w)->next);
    v++;
  }
  
  if( (*p)->value < (*w)->value ) {
    temp        = (*p)->value;
    (*p)->value = (*w)->value;
    (*w)->value = temp;
    downheap(head, v, n);
  }
}

void heapsort(struct cell **head, int n)
{
  struct cell **p;
  int temp;
  int i;
  
  for(i = n/2; i > 0; i--)
    downheap(head, i, n); 
  
  while(n > 1) {
    p = get_v(head, n);
    
    temp           = (*head)->value;
    (*head)->value = (*p)->value;
    (*p)->value    = temp;
    
    downheap(head, 1, n-1);  
    
    n--;
  }
}
