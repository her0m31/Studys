/* bst.c */
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct node *create_node(struct student *new_student)
{
  struct node *new_node;
  
  new_node          =  (struct node *)malloc(sizeof(struct node));
  if(new_node == NULL)
    return 0;
  new_node->value   =  new_student;
  new_node->child_l =  NULL;
  new_node->child_r =  NULL;
  
  return new_node;
}

struct student *search_node(struct node *pointer, char *key)
{
  if (pointer == NULL)
    return NULL;
  
  if ( strcmp(pointer->value->name, key) == 0 )
    return pointer->value;
  
  if ( strcmp(pointer->value->name, key) > 0 )
    return search_node(pointer->child_l, key);
  else
    return search_node(pointer->child_r, key);
}

void add_node(struct node **pointer, struct node *new_node)
{
  if(*pointer == NULL)
    *pointer = new_node;
  else if( strcmp( (*pointer)->value->name, new_node->value->name) > 0 )
    add_node( &((*pointer)->child_l), new_node);
  else
    add_node( &((*pointer)->child_r), new_node);
}
