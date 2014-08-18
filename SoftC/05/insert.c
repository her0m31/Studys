#include <stdio.h>

#define N 10

int main()
{
  int num[N] ={6, 15, 12, 7, 9, 23, 2, 10, 4, 20};
  int temp;
  int i, j;
  int key  = 0;
  int data = 0;
  
  for (i = 0; i < N; i++)
    printf("%2d ", num[i]);
  
  for (i = 0; i < N; i++) {
    temp = num[i];
    for (j = i; j > 0 && num[j - 1] > temp; j--){
      num[j] = num[j - 1];
    }
    num[j] = temp;
  }
  
  printf("\n");
  
  for (i = 0; i < N; i++)
    printf("%2d ", num[i]);
  
  printf("\n");
  
  return 0;
}
