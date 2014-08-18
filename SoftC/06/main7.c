/* main7.c */
#include <stdio.h>
#include "sort.h"

#define N 50000

int main(int argc, char *argv[])
{
  FILE *fp;
  int i, j, num;
  int n[N];
  
  if(argc < 2){
    fprintf(stderr, "Arguments\n");
    return -1;
  }
  
  fp = fopen(argv[1], "r");
  
  if(fp == NULL){
    fprintf(stderr, "CAN NOT OPEN\n");
    return -1;
  }
  
  for(j = 0; j < N && (fscanf(fp, "%d", &i) != EOF); j++)
    n[j] = i;

  fclose(fp);

  i = 0;
  if(j <= 5){
    simples(n, j);
    printf("Use simple sort\n");
  } else {
    quicks(n, i, j-1);
    printf("Use quick sort\n");
  }
  
  return 0;
}
