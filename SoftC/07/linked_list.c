/* linked_list.c */
#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

int insert_cell(struct cell **pointer, int new_value)
{
  struct cell *new_cell;
  
  new_cell = (struct cell *)malloc(sizeof(struct cell));
  if( new_cell == NULL ){
    return 0;
  }
  new_cell->value = new_value;
  new_cell->next  = *pointer;
  *pointer        = new_cell;
  return 1;
}

void delete_cell(struct cell **pointer)
{
  struct cell *target;
  
  target   = *pointer;
  *pointer = target->next;
   free((void *)target);
}
