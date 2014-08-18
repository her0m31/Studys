/* main2.c */
#include <stdio.h>
#include "hs.h"
#define N 20

int main()
{
  int data[N];
  int num;
  int i;
  int times[] = {0, 0};
  
  data[0] = -1;
  for(i = 1; scanf("%d", &data[i]) != EOF; i++);
  
  num = i;
  heapsort(data, num-1, times);
  
  for(i = 1; i < num; i++)
    printf(" %2d", data[i]);

  printf("\nkey    : %2d\ndata   : %2d\n", times[0], times[1]);

  return 0;
}
