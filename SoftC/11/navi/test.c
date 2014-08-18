#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "navi.h"

void read_line( char filename[], struct edge *df_tree[], int edges[][2], int num )
{
  struct edge **p;
  FILE *fp;
  char linename[25];
  char line[5];
  int weight;
  int start;
  int end;
  int i, j;
  
  fp = fopen(filename, "r");
  if (fp == NULL)
    return -1;
  
  for(i = 0; i < num; i++) {
    edges[i][0] = -1;
    edges[i][1] = -1;
  }
  
  for( i = 0; i < num && fscanf(fp, "%d %d", &start, &end) != EOF; i++ ) {
    edges[i][0] = start;
    edges[i][1] = end;    
  }
  
  for( i = 0; i < num; i++ ) {
    df_tree[i] = NULL;
    for( j = 0; j < num && edges[j][0] != -1 && 
           fscanf(fp, "%d  %d %d %s %s", &start, &end, &weight, linename, line ) != EOF; j++ ) {
      strcat( linename, " ");
      strcat( linename, line);
      
      if(i == edge[j][0] || i == edge[j][1] ) {
        for(p = &df_tree[start]; *p != NULL; p = &((*p)->next) );

        if( insert_cell(p, end, weight, linename) == -1)
          return -1;  
        
      }
    }
  }
  fclose(fp);
}
