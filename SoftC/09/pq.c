/* pq.c */
#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int insert(int *queue, int new_value)
{
  int i;
  //キューの第0要素はキューに要素が何個入ったかをカウントする。
  queue[0]++;
  if(queue[0] < QueueCapacity+1) {
    queue[queue[0]] = new_value;
    return 0;
  } else {
    for(i = QueueCapacity+1/2; i > 0; i--)
      downheap( queue, i, QueueCapacity+1 );
    printf("END : [%2d]\n", extractmax(queue));
    queue[1] = new_value; 
  }
}

int maximum(int *queue)
{
  return queue[1];
}

int extractmax(int *queue)
{
  int maxkey;
  
  maxkey = maximum(queue);
  
  return maxkey;
}

void downheap(int *queue, int v, int n)
{
  int temp;
  int w;
  
  if(v > n/2)
    return;
  
  w = 2*v;
  if( w+1 <= n && queue[w] < queue[w+1])
    w = w+1;
  
  if( queue[v] < queue[w] ) {
    temp     = queue[v];
    queue[v] = queue[w];
    queue[w] = temp;
    downheap(queue, w, n);
  }
}
