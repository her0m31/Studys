/* main6.c */
#include <stdio.h>
#include "pq.h"

int main()
{
  int queue[QueueCapacity+1];
  int data;
  int i, j;
  int q;
  
  //カウントのために初期化
  queue[0] = 0;
  printf("DATA : ");
  for(i = 1; scanf("%2d\n", &data) != EOF; i++) {
    if( insert(queue, data) != 0 ) {
      printf("REST : ");
      for( j = QueueCapacity;  j > 0; j-- )
        printf("%2d ", queue[j]);
      printf("\n"); 
    }
  }
  return 0;
}
