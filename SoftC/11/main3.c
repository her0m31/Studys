/* main3.c */
#include <stdio.h>
#include "dijk2.h"

int main()
{
  struct node node_dat[NODES];
  int matrix[NODES][NODES];
  int start = 0;
  int end   = 5;
  int i;
  int x;
  
  if( adjacency("graph2.dat", matrix) == -1 ) {
    fprintf(stderr, "Can't open file: graph2.dat\n");
    return 0;
  }
  
  for( i = 0; i < NODES; i++ ) {
    node_dat[i].dist = INF;
    node_dat[i].flag = 0;
  }
  
  dijkstra(start, end, node_dat, matrix);
  
  printf("%d -> %d : Distance = %d, ", start, end, node_dat[end].dist);
  
  x = end;
  printf("Path : %d", end);
  while(node_dat[x].path != END_OF_PATH) {
    printf(" %d", node_dat[x].path);
    x = node_dat[x].path;
  }
  printf("\n");

  return 0;
}
