/* main5.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "navi.h"

struct node *node_dat;
struct edge **list;
int nodes;

int main( int argc, char *argv[] )
{
  struct edge *path;
  int start = -1;
  int end   = -1;
  int i;
  
  if( argc != 3 ) {
    fprintf( stderr, "Please give a start point and a destination as argument.\n" );
    return -1;
  }
  
  read_station();

  if( ( start = check_point( argv[1] ) ) == INF ) {
    fprintf( stderr, "Start point is not registered.\n" );
    return -1;
  } else if ( ( end = check_point( argv[2] ) ) == INF ) {
    fprintf( stderr, "Destination point is not registered.\n" );
    return -1;
  }

  read_line();
  
  for( i = 0; i < nodes; i++ ) {
    node_dat[i].dist = INF;
    node_dat[i].flag = 0;
  }

  dijkstra( start, end );
  make_path( &path, start, end );
  output( path, start, end );
  
  return 0;
}
