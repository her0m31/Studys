/* sort3_main.c */
#include <stdio.h>
#include "sort.h"

#define N 50000

int main()
{
  FILE *fp;
  int i, j;
  int n[N];

  fp = fopen("c06-50000.dat", "r");
  if(fp == NULL){
    fprintf(stderr, "CAN NOT OPEN\n");
    return -1;
  }
  
  for(j = 0; (fscanf(fp, "%d", &i) != EOF) && j < N; j++)
    n[j] = i;
  
  i = 0; 
  bubbles(n, j);

  return 0;
}
