/* dfsw.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsw.h"

int adjacency(char file[], char *word[], int matrix[][NODES])
{ 
  char wor[10]; 
  FILE *fp;
  int i, j;
  
  fp = fopen(file, "r");
  if (fp == NULL)
    return -1;
  
  for(i = 0; i < NODES && fscanf(fp, "%s", wor) != EOF; i++ ) {
    word[i] = (char *)malloc(sizeof(char) * (strlen(wor) + 1));
    if (word[i] == NULL)
      return -1;
    strcpy(word[i], wor); 
  }
  fclose(fp);
  
  for(i = 0; i < NODES; i++) {
    for(j = 0; j < NODES; j++)
      matrix[i][j] = 0;
  }
  
  for(i = 0; i < NODES; i++) {
    for(j = 0; j < NODES; j++) {
      if( word[i][strlen(word[i])-2] == word[j][0] && word[i][strlen(word[i])-1] == word[j][1] )
        matrix[i][j] = 1;
    }
  }
  
  return 0;
}

void df_search(int u, int *df_flag, int *edge_cnt, struct edge df_tree[], int matrix[][NODES])
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
