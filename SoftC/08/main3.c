/* main3.c */
#include <stdio.h>
#include <stdlib.h>
#include "tra.h"

int main()
{
  int data;
  int i;
  struct node *root = NULL;

  scanf("%d", &data);
  srand(data);

  printf("      ");
  for(i = 0; i < 15; i++){
    data = (int)((double)rand() / ((double)RAND_MAX + 1.0) * 100.0);
   
    add_node( &root, create_node(data));

    printf("%2d ", data);
  }

  printf("\npre : "); 
  pre_search_node(root);
  
  printf("\nino : "); 
  ino_search_node(root);

  printf("\npos : "); 
  pos_search_node(root);

  printf("\n"); 

  return 0;
}
