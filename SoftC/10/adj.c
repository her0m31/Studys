/* adj.c */
#include <gtk/gtk.h>
#include <stdio.h>

#define NODES 9

int main()
{
  FILE *fp;
  int i, j;
  int adj[NODES][NODES];

  for(i = 0; i < NODES; i++){
    for(j = 0; j < NODES; j ++)
      adj[i][j] = 0;
  }
  
  fp = fopen("graph1.dat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file: graph1.dat\n");
    return -1;
  }
  
  while( fscanf(fp, "%d %d", &i, &j) != EOF ){
    adj[i][j] = 1;
    adj[j][i] = 1;
  }
  
  printf("  | 0 1 2 3 4 5 6 7 8\n");
  printf("----------------------\n");
  for(i = 0; i < NODES; i++){
    printf("%d |", i);
    for(j = 0; j < NODES; j ++)
      printf(" %d", adj[i][j]);
    printf("\n");
  }
  
  return 0;
}
