/* push_pop2.c */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct cell *head = NULL;

int push(float data)
{
  if( insert_cell(&head, data) == 0 )
    return 0;
  
  return 1; 
}

int pop(float *data)
{
  struct cell **p;
  
  if (head == NULL )
    return 0;
  else{
    p = &head;
    *data = (*p)->value;
    delete_cell(p);
    return 1;
  }
}  

int insert_cell(struct cell **pointer, float new_value)
{
  struct cell *new_cell;
  
  new_cell = (struct cell *)malloc(sizeof(struct cell));
  if( new_cell == NULL ){
    fprintf(stderr, "error!\n");
    return 0;
  }
  new_cell->value = new_value;
  new_cell->next  = *pointer;
  *pointer        = new_cell;
}

void delete_cell(struct cell **pointer)
{
  struct cell *target;
  
  target   = *pointer;
  *pointer = target->next;
   free((void *)target);
}
