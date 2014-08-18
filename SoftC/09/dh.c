/* bh.c */
#include "dh.h"
void downheap(int *data, int v, int n)
{
  int temp;
  int w;
  
  if(v > n/2)
    return;

  w = 2*v;
  if( w+1 <= n && data[w] < data[w+1])
    w = w+1;
  
  if(data[v] < data[w]) {
    temp    = data[v];
    data[v] = data[w];
    data[w] = temp;
    downheap(data, w, n);
  }
}
