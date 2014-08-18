/* main4.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsw.h"

int main()
{
  struct edge df_tree[NODES - 1];
  char *word[15];
  int matrix[NODES][NODES];
  int df_flag[NODES];
  int edge_cnt; 
  int i;
  
  if( adjacency("word.dat", word, matrix) == -1 ) {
    fprintf(stderr, "ERROR!\n");
    return -1;
  }
  
  edge_cnt = 0;
  for(i = 0; i < NODES - 1; i++) {
    df_tree[i].start_node = -1;
    df_tree[i].end_node   = -1;
  }
  
  for(i = 0; i < NODES; i++)
    df_flag[i] = 0;
 
  df_search(0, df_flag, &edge_cnt, df_tree, matrix);
  
  for(i = 0; i < NODES; i++) {
    if( df_tree[i].start_node == -1)
      break;
    printf("(%s, %s)", word[df_tree[i].start_node], word[df_tree[i].end_node]);
  } 
  printf("\n");
  
  return 0;
}
