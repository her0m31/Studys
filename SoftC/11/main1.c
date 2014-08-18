/* main1.c */
#include <stdio.h>
#include "dijk.h"

int main()
{
  struct node node_dat[NODES];
  int matrix[NODES][NODES];
  int times;
  int start = 0;
  int end   = 5;
  int i;
  
  if( adjacency("graph2.dat", matrix) == -1 ) {
    fprintf(stderr, "Can't open file: graph2.dat\n");
    return -1;
  }
  
  for( i = 0; i < NODES; i++ ) {
    node_dat[i].dist = INF;
    node_dat[i].flag = 0;
  }
  
  times = dijkstra(start, end, node_dat, matrix);
  
  printf("%d : Distance = %d\n", end, node_dat[end].dist);
  printf("    Comparison %d\n", times);
  
  return 0;
}
