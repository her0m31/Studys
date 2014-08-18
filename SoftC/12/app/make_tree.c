/* make_tree.c */
#include "adrb.h"

struct tree *create_node(struct adrb *new_adrb)
{
  struct tree *new_node;
  
  new_node          =  (struct tree *)malloc(sizeof(struct tree));
  if(new_node == NULL)
    return 0;
  new_node->value   =  new_adrb;
  new_node->child_l =  NULL;
  new_node->child_r =  NULL;
  
  return new_node;
}

struct tree *make_tree(int item_num)
{ 
  struct tree *root = NULL;
  char items[5][MAXLEN];
  int count;
  FILE *fp;
    
  fp = fopen( "adrb.dat", "r" );
  if ( fp == NULL ) {
    fprintf(stderr, "Cannot open file: adrb.dat\n");
    add_node( &root, create_node( create_adrb( "ZZZZ", "ZZZZ", "ZZZZ", "ZZZZ", "ZZZZ", 0 ) ), item_num );
    return root;
  }
  
  while( fscanf( fp, "%s%s%s%s%s%d", items[0], items[1], items[2], items[3], items[4], &count ) != EOF ) {
    add_node( &root, create_node( create_adrb( items[0], items[1], items[2], items[3], items[4], count ) ), item_num );
  }
  
  fclose(fp);

  return root;
}

struct tree *make_rev_tree(int item_num)
{
  struct tree *root = NULL;
   char items[5][MAXLEN];
  int count;
  FILE *fp;
  
  fp = fopen( "adrb.dat", "r" );
  if ( fp == NULL ) {
    fprintf(stderr, "Cannot open file: adrb.dat\n");
    return;
  }
  
  while( fscanf( fp, "%s%s%s%s%s%d", items[0], items[1], items[2], items[3], items[4], &count ) != EOF ) {
    add_rev_node( &root, create_node( create_adrb( items[0], items[1], items[2], items[3], items[4], count ) ), item_num );
  }
  
  fclose(fp);

  return root;
}
