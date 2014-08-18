/* navi.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "navi.h"

void dijkstra( int start, int end )
{
  struct edge *ptr;
  int u, x;
  int nex;
  
  node_dat[start].flag = 1;
  for( ptr = list[start]; ptr != NULL; ptr = ptr->next )
  
  if( ptr->weight < node_dat[ptr->dst].dist ) {
    node_dat[ptr->dst].dist = ptr->weight;
    node_dat[ptr->dst].path = start;
  }
  
  node_dat[start].dist = 0;
  node_dat[start].path = EOP;
  u = start;
  while( u != end ) {
    nex = INF;
    for(x = 0; x < nodes; x++) {
      if(node_dat[x].flag != 1 && nex > node_dat[x].dist ) {
        nex =  node_dat[x].dist;
        u   =  x;
      }
    }
    
    node_dat[u].flag = 1;
    for( ptr = list[u]; ptr != NULL; ptr = ptr->next ) {
      if( node_dat[ptr->dst].dist > node_dat[u].dist + ptr->weight ) {
        node_dat[ptr->dst].dist = node_dat[u].dist + ptr->weight;
        node_dat[ptr->dst].path = u;
      }
    }
  }
}

void make_path( struct edge **ptr, int start, int end )
{
  struct edge *path, *tmp;
  int min;
  int i;
  
  *ptr = NULL;
  insert_cell( ptr, end, 0, NULL);
  for(i = end; node_dat[i].path != EOP; i = node_dat[i].path) {
    min = INF;
    for(path = list[i]; path != NULL; path = path->next) {
      if( min > node_dat[path->dst].dist && node_dat[i].path == path->dst ) {
        min = node_dat[path->dst].dist;
        tmp = path;
      }
    }
    if( insert_cell( ptr, tmp->dst, tmp->weight, tmp->line ) == -1)
      return;
  }  
}

int check_point(char *name)
{
  int i;
  
  for(i = 0; i < nodes; i++) {
    if( strcmp(node_dat[i].name, name) == 0 )
      return i;
  }
  
  return INF;
}

void output(struct edge *path, int start, int end)
{
  struct edge *ptr, *tmp;
  
  printf("The shortest path from %s to %s\n", node_dat[start].name, node_dat[end].name);
  
  for( ptr = path; ptr->next != NULL; ptr = ptr->next ) {
    tmp = ptr->next;
    printf(" %17s -> %17s ", node_dat[ptr->dst].name, node_dat[tmp->dst].name);
    printf("by %19s for %3d [min.]\n", ptr->line, ptr->weight);
  }
  
  printf("Total time required ... %d[min.]\n", node_dat[ptr->dst].dist );
}
