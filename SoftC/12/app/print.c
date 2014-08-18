/* print.c */
#include "adrb.h"

void print_adrb(struct tree *root)
{
  if (root == NULL)
    return;
  
  print_adrb( root->child_l );
  printf("%s\t%s\t%s\t%s\t%s\n", root->value->name, root->value->posc, root->value->adre, root->value->tell, root->value->mail); 
  print_adrb( root->child_r );
}

void save_file(FILE *fp, struct tree **root)
{
  if (*root == NULL)
    return;
  
  save_file( fp, &((*root)->child_l) );
  fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\n", (*root)->value->name, (*root)->value->posc, (*root)->value->adre, (*root)->value->tell, (*root)->value->mail, (*root)->value->count ); 
  save_file( fp, &((*root)->child_r) ); 
}

void print_history(struct tree *root, int count)
{ 
  if (root == NULL || count == 5)
    return;
  
  print_history(root->child_l, count);
  if( root->value->count != 0 ) {
    printf("%s\t%s\t%s\t%s\t%s\n", root->value->name, root->value->posc, root->value->adre, root->value->tell, root->value->mail); 
    count++;
  }
  print_history(root->child_r, count);
}

void print_match(struct tree *root, struct adrb **data, char *key, int num, int *count)
{
  struct tree **view;
   
  view = &root;
  if(num == 0) {
    while( *view != NULL ) {
      if( strcmp( key, (*view)->value->name ) == 0 ) {
        data[(*count)] = (*view)->value;
        (*count)++;
        if( strcmp(key, (*view)->value->name) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      } else {
        if( strcmp(key, (*view)->value->name) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
  }else if(num == 1) {
    while( *view != NULL ) {
      if( strcmp( key, (*view)->value->posc ) == 0 ) {
        data[(*count)] = (*view)->value;
        (*count)++;
        if( strcmp(key, (*view)->value->posc) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      } else {
        if( strcmp(key, (*view)->value->posc) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
  }else if(num == 2) {
      while( *view != NULL ) {
      if( strcmp( key, (*view)->value->adre ) == 0 ) {
        data[(*count)] = (*view)->value;
        (*count)++;
        if( strcmp(key, (*view)->value->adre) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      } else {
        if( strcmp(key, (*view)->value->adre) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
  }else if(num == 3) {
    while( *view != NULL ) {
      if( strcmp( key, (*view)->value->tell ) == 0 ) {
        data[(*count)] = (*view)->value;
        (*count)++;
        if( strcmp(key, (*view)->value->tell) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      } else {
        if( strcmp(key, (*view)->value->tell) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
  }else if(num == 4) {
    while( *view != NULL ) {
      if( strcmp( key, (*view)->value->mail ) == 0 ) {
        data[(*count)] = (*view)->value;
        (*count)++;
        if( strcmp(key, (*view)->value->mail) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      } else {
        if( strcmp(key, (*view)->value->mail) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
  }
}
