/* main7.c */
#include <stdio.h>
#include "bnd.h"

int main()
{
  int data[12] = {51, 31, 3, 47, 45, 78, 67, 58, 72, 99, 85, 105};
  int i;
  struct node *root = NULL;
  
  printf("      "); 
  for(i = 0; i < 12; i++){
    add_node( &root, create_node(data[i]) );
    
    printf("%2d ", data[i]);
  }

  printf("\npre : "); 
  pre_search_node(root);
  
  printf("\n"); 
  scanf("%d", &i);
  if(delete(&root, i) != 0){
    fprintf(stderr, "error!\n");
    return -1;
  }
  printf("pre : "); 
  pre_search_node(root);
  
  printf("\n"); 

  return 0;
}
