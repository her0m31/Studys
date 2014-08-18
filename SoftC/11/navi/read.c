/* read.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "navi.h"

int insert_cell( struct edge **ptr, int dst, int weight, char *line )
{
  struct edge *new_cell;
  
  new_cell = (struct edge *)malloc(sizeof(struct edge));
  if( new_cell == NULL )
    return -1;
  
  new_cell->dst    = dst;
  new_cell->weight = weight;
  if(line != NULL) {
    new_cell->line = (char *)malloc( sizeof(char)*(strlen(line)+1) );
    if( new_cell->line == NULL )
      return -1;
    strcpy( new_cell->line, line );
  } else 
    new_cell->line = NULL;
  
  new_cell->next   = *ptr;
  *ptr             = new_cell;
  
  return 0;  
}

void read_station(void)
{
  FILE *fp;
  char station[30];
  int  i, j;
  
  fp = fopen( "station.dat", "r" );
  if (fp == NULL)
    return;  
  
  fscanf( fp, "%d", &nodes );
  node_dat = (struct node *)malloc( sizeof(struct node) * nodes );
  if (node_dat == NULL)
    return;
  
  for( i = 0; i < nodes && fscanf(fp, "%d %s", &j, station) != EOF; i++ ) {
    node_dat[j].name = (char *)malloc( sizeof(char)*(strlen(station)+1) );
    if ( node_dat[j].name == NULL )
      return;
    strcpy( node_dat[j].name, station );
  }
  
  fclose(fp);
}

void read_line(void)
{
  FILE *fp;
  char linename[30];
  int start, end, weight;
  int len;
  int i;
  
  fp = fopen( "line.dat", "r" );
  if (fp == NULL)
    return;
  
  list = (struct edge **)malloc( sizeof(struct edge *) * nodes );
  if (list == NULL)
    return;
  
  for( i = 0; i < nodes; i++ )
    list[i] = NULL;
  
  while( fscanf(fp, "%d %d %d", &start, &end, &weight) != EOF ) {
    fgets(linename, 30, fp);
    len = strlen( linename );
    if(linename[len -1] == '\n')
      linename[len -1] = '\0';
    
    insert_cell( &(list[start]), end, weight, linename );
    insert_cell( &(list[end]), start, weight, linename );
  }

  fclose(fp);
}
