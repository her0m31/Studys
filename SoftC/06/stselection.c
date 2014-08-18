/* stselection.c */
#include <stdio.h>

#define N 10

int main()
{
  int stuno[N]  = {2010014, 2010023, 2010031, 2010034, 2010037,
                   2010055, 2010074, 2010082, 2010142, 2010160};
  int hostno[N] = {    400,     300,     800,     600,     200,
                       100,     700,     500,     900,     150};
  int i, j;
  int k;
  int temp;
  int key  = 0;
  int data = 0;
  
  for (i = 0; i < N; i++)
    printf("%3d : %7d\n", hostno[i], stuno[i]);
  
  for (i = 0; i < N - 1; i++) {
    k = i;
    for (j = i + 1; j < N; j++){
      if (hostno[k] > hostno[j]){
        k = j;
      }
      key++;
    }
    
    data++;
    temp      = hostno[i];
    hostno[i] = hostno[k];
    hostno[k] = temp;
    
    temp     = stuno[i];
    stuno[i] = stuno[k];
    stuno[k] = temp;
  }
  
  printf("\n");
  
  for (j = 0; j < N; j++) 
    printf("%3d : %7d\n", hostno[j], stuno[j]); 
  
  printf("key : %d\ndata : %d\n", key, data);
  
  return 0;
}
