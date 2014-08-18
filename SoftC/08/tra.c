/* tra.c */
#include <stdio.h>
#include <stdlib.h>
#include "tra.h"

struct node *create_node(int value)
{
  struct node *new_node;
  
  new_node          =  (struct node *)malloc(sizeof(struct node));
  new_node->value   =  value;
  new_node->child_l =  NULL;
  new_node->child_r =  NULL;
  
  return new_node;
}

void pre_search_node(struct node *pointer)
{
  if (pointer == NULL)
    return;
  
  printf("%2d ", pointer->value); 
  pre_search_node(pointer->child_l);
  pre_search_node(pointer->child_r);
}

void ino_search_node(struct node *pointer)
{
  if (pointer == NULL)
    return;
  
  ino_search_node(pointer->child_l);
  printf("%2d ", pointer->value); 
  ino_search_node(pointer->child_r);
}

void pos_search_node(struct node *pointer)
{
  if (pointer == NULL)
    return;
  
  pos_search_node(pointer->child_l);
  pos_search_node(pointer->child_r);
  printf("%2d ", pointer->value); 
}

void add_node(struct node **pointer, struct node *new_node)
{
  if(*pointer == NULL)
    *pointer = new_node;
  else if( (*pointer)->value > new_node->value )
    add_node( &((*pointer)->child_l), new_node);
  else
    add_node( &((*pointer)->child_r), new_node);
}
