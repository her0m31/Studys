/* search.c */
#include "adrb.h"

struct adrb *search_adrb(struct tree *root, char *key, int items)
{
  if (root == NULL)
    return NULL;
  
  if(items == 0) {
    if ( strcmp(root->value->name, key) == 0 ) { 
      return root->value;
    }
    if ( strcmp(root->value->name, key) > 0 )
      return search_adrb(root->child_l, key, items);
    else
      return search_adrb(root->child_r, key, items);
  }
  else if(items == 1) {
    if ( strcmp(root->value->posc, key) == 0 )
      return root->value;
    
    if ( strcmp(root->value->posc, key) > 0 )
      return search_adrb(root->child_l, key, items);
    else
      return search_adrb(root->child_r, key, items);
  }
  else if(items == 2) {
    if ( strcmp(root->value->adre, key) == 0 )
      return root->value;
   
    if ( strcmp(root->value->adre, key) > 0 )
      return search_adrb(root->child_l, key, items);
    else
      return search_adrb(root->child_r, key, items);
  }
  else if(items == 3) {
    if ( strcmp(root->value->tell, key) == 0 )
      return root->value;
    
    if ( strcmp(root->value->tell, key) > 0 )
      return search_adrb(root->child_l, key, items);
    else
      return search_adrb(root->child_r, key, items);
  }
  else if(items == 4) {
    if ( strcmp(root->value->mail, key) == 0 )
      return root->value; 
    
    if ( strcmp(root->value->mail, key) > 0 )
      return search_adrb(root->child_l, key, items);
    else
      return search_adrb(root->child_r, key, items);
  }
}
