3/* main5.c */
#include <stdio.h>
#include "al.h"

int main()
{
  struct cell *adjacency_list[NODES];
  struct cell **p;
  int edges[MAX_EDGES][2];
  int i, j;
  
  if( adjacency( "graph1.dat", edges, adjacency_list) == -1 ) {
    fprintf(stderr, "ERROR!\n");
    return -1; ;
  }
  
  for(i = 0; i < NODES; i++) {
    printf("node %d: ", i);
    for( p = &adjacency_list[i];  *p != NULL;  p = &((*p)->next) )
      if(i == edges[(*p)->value][1])
        printf("(%d, %d) ", edges[(*p)->value][0], i ) ;
      else
        printf("(%d, %d) ", i, edges[(*p)->value][1] ) ;
    printf("\n");
  }
  
  return 0;
}
