/* main1.c */
#include <stdio.h>
#include "list1.h"

int main()
{
  float data;
  
  while( ((scanf("%f", &data)) != EOF) && (push(data) != 0) );
  
  while( (pop(&data)) != 0 )
    printf("%.2f ", data);
  printf("\n");
  
  return 0;
}
