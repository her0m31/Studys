/* main2.c */
#include <stdio.h>
#include "dfs.h"

int main()
{
  struct edge df_tree[NODES-1];
  int matrix[NODES][NODES];
  int df_flag[NODES];
  int edge_cnt;
  int i;
  
  if( adjacency( "graph1.dat", matrix ) == -1 ){
    fprintf(stderr, "Can't open file: graph1.dat\n");
    return -1; ;
  }
  
  edge_cnt = 0;
  for(i = 0; i < NODES; i++)
    df_flag[i] = 0;
  
  df_search(0, df_flag, &edge_cnt, df_tree, matrix);
  
  for(i = 0; i < NODES-1; i++)
    printf("(%d, %d)", df_tree[i].start_node, df_tree[i].end_node);
  printf("\n");
  
  return 0;
}
