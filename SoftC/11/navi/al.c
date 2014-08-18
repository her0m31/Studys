/* al.c */
#include <stdio.h>
#include <stdlib.h>
#include "al.h"

int adjacency(char filename[], int edges[MAX_EDGES][2],
              struct cell *adjacency_list[])
{
  struct cell **p;
  FILE *fp;
  int start, end;
  int i, j;
  
  fp = fopen(filename, "r");
  if (fp == NULL)
    return -1;
  
  for(i = 0; i < MAX_EDGES; i++) {
    edges[i][0] = -1;
    edges[i][1] = -1;
  }
  
  for( i = 0; i < MAX_EDGES && fscanf(fp, "%d %d", &start, &end) != EOF; i++ ) {
    edges[i][0] = start;
    edges[i][1] = end;    
  }
  
  for( i = 0; i < NODES; i++ ) {
    adjacency_list[i] = NULL;
    for(j = 0; j < MAX_EDGES && edges[j][0] != -1; j++) {
      if(i == edges[j][0] || i == edges[j][1]) {
        for(p = &adjacency_list[i]; *p != NULL; p = &((*p)->next) );
        
        if( insert(p, j) == -1)
          return -1;
      }
    }
  }
  
  fclose(fp);
}

int insert(struct cell **pointer, int new_value)
{
  struct cell *new_cell;
  
  new_cell = (struct cell *)malloc(sizeof(struct cell));
  if( new_cell == NULL )
    return -1;
  new_cell->value = new_value;
  new_cell->next  = *pointer;
  *pointer        = new_cell;
  return 0;
}
