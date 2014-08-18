/* dfs.c */
#include <stdio.h>
#include "dfs.h"

int adjacency(char file[], int matrix[][NODES])
{ 
  FILE *fp;
  int i, j;
  
  for(i = 0; i < NODES; i++){
    for(j = 0; j < NODES; j ++)
      matrix[i][j] = 0;
  }
  
  fp = fopen(file, "r");
  if (fp == NULL)
    return -1;
  
  while( fscanf(fp, "%d %d", &i, &j) != EOF ){
    matrix[i][j] = 1;
    matrix[j][i] = 1;
  }
  
  fclose(fp);
}

void df_search(int u, int *df_flag, int *edge_cnt,
               struct edge df_tree[], int matrix[][NODES])
{
  int v;
  
  df_flag[u] = 1;
  for(v = 0; v < NODES; v++) {
    if( matrix[u][v] == 1 ) {
      if( df_flag[v] == 0 ) {
        df_tree[*edge_cnt].start_node = u;
        df_tree[*edge_cnt].end_node   = v;
        (*edge_cnt)++;
        df_search(v, df_flag, edge_cnt, df_tree, matrix);
      }
    }
  }
}
