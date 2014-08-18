/* hs.c */
#include "hs.h"

void downheap(int *data, int v, int n, int times[])
{
  int temp;
  int w;
  
  if(v > n/2)
    return;

  w = 2*v;
  if(w+1 <= n && ++times[0] && data[w] < data[w+1])
    w = w+1;
  
  if(++times[0] && data[v] < data[w]){
    temp    = data[v];
    data[v] = data[w];
    data[w] = temp;
    times[1]++;
    downheap(data, w, n, times);
  }
}

void heapsort(int *data, int n, int times[])
{
  int temp;
  int i;
  
  for(i = n/2; i > 0; i--)
    downheap(data, i, n, times);
  
  while(n > 1) {
    temp    = data[n];
    data[n] = data[1];
    data[1] = temp;
    times[1]++;
    
    downheap(data, 1, n-1, times);
    
    n--;
  }
}
