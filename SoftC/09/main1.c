/* main1.c */
#include <stdio.h>
#include "dh.h"
#define N 20

int main()
{
  int data[N];
  int num;
  int i;
  
  data[0] = -1;
  for(i = 1; scanf("%d", &data[i]) != EOF; i++);
  
  num = i;
  printf("BEFORE : ");
  for(i = 1; i < num; i++)
    printf("%2d ", data[i]);
  printf("\n");
  
  for(i = num/2; i > 0; i--)
    downheap(data, i, num-1);
  
  printf("AFTER  : ");
  for(i = 1; i < num; i++)
    printf("%2d ", data[i]);
  printf("\n");
  
  return 0;
}
