#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "navi.h"

int main( int argc, char *argv[] )
{
  struct node **node_inf;
  int num;
  int i;
    
  node_inf = read_station( "station.dat", &num );
  if( &node_inf == NULL ) {
    fprintf( stderr, "ERROR!.\n" );
    return -1;
  }

  for(i = 0; i < num; i++)
    printf("%d %s\n", i, node_inf[i]->name);
  
  return 0;
}
 
