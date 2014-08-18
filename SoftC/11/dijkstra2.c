/* dijkstra2.c */
#include <stdio.h>
#include "dijk2.h"

int adjacency(char file[], int matrix[][NODES])
{ 
  FILE *fp;
  int start, end, weight;
  
  for(start = 0; start < NODES; start++){
    for(end = 0; end < NODES; end++)
      matrix[start][end] = INF;
  }
  
  fp = fopen(file, "r");
  if (fp == NULL)
    return -1;
  
  while( fscanf(fp, "%d %d %d", &start, &end, &weight) != EOF ) {
    matrix[start][end] = weight;
    matrix[end][start] = weight;
  }
  
  fclose(fp);
  
  return 0;
}

void dijkstra(int start, int end, struct node node_dat[], int matrix[][NODES])
{
  int next;
  int u, x, v;

  node_dat[start].flag = 1;
  for( next = 0; next < NODES; next++ ) {
    if( matrix[start][next] != INF) {
      node_dat[next].dist = matrix[start][next];
      node_dat[next].path = start;
    }
  }
  
  node_dat[start].dist = 0; 
  node_dat[start].path = END_OF_PATH;
  u = start;
  while( u != end ) {
    next = INF;
    for(x = 0; x < NODES; x++) {
      if(node_dat[x].flag != 1 && node_dat[x].dist < next) {
        next =  node_dat[x].dist;
        u    =  x;
      }
    }
    
    node_dat[u].flag = 1;
    for( v = 0; v < NODES; v++ ) {
      if( matrix[u][v] != INF && node_dat[v].flag != 1 ) {
        if( node_dat[v].dist > node_dat[u].dist + matrix[u][v] ) {
          node_dat[v].dist = node_dat[u].dist + matrix[u][v];
          node_dat[v].path = u;
        }
      }
    }
  }
}
