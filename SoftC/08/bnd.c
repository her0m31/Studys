/* bnd.c */
#include <stdio.h>
#include <stdlib.h>
#include "bnd.h"

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

void add_node(struct node **pointer, struct node *new_node)
{
  if(*pointer == NULL)
    *pointer = new_node;
  else if( (*pointer)->value > new_node->value )
    add_node( &((*pointer)->child_l), new_node);
  else
    add_node( &((*pointer)->child_r), new_node);
}

int delete(struct node **pointer, int value)
{
  struct node *temp;
  
  while( *pointer != NULL ){
//目的のノードを見つけた時
    if( value == (*pointer)->value ){
      temp = *pointer;
//子の有無を調べる
      if(temp->child_l == NULL ) 
        *pointer = temp->child_r;
      else if( temp->child_r == NULL )
        *pointer = temp->child_l;
      else {
//両側に子が有る時は右部分木の最小値を探す
        *pointer            = delete_min( &temp->child_r );
        (*pointer)->child_r = temp->child_r;
        (*pointer)->child_l = temp->child_l;
      }
      free(temp);
      return 0;
    }
    if( value < (*pointer)->value )
//左の子の探索
      pointer = &(*pointer)->child_l;
    else
//右の子の探索
      pointer = &(*pointer)->child_r;
  }
  return 1;
}

struct node *delete_min(struct node **pointer)
{
  struct node *temp;
  
  while( (*pointer)->child_l != NULL )
    pointer = &((*pointer)->child_l);
  
  temp = *pointer; 
  *pointer = (*pointer)->child_r;
  
  return temp;
}
