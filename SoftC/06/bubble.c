/* bubble.c */
#include <stdio.h>

#define N 20

int main()
{
  int num[N] = {7, 20, 1, 18, 9, 15, 24, 10, 3, 12};
  int temp;
  int i,j;
  int key = 0;
  int dat = 0;

/* 1. i=0��i=N-2�δַ����֤� */  
  for(i = 0; i < N - 2; i++){              

/* 2. j��N - 1�Ȥ���   4. j��1���餷j>i�ʤ鷫���֤�3�˿ʤ� */
    for(j = N - 1; i < j; j--){       

/* 3. num[j]��num[j-1]����Ӥ���num[j]�Τۤ�����������и򴹤��� */
      if(num[j - 1] > num[j]){             
        temp       = num[j];
        num[j]     = num[j -1];
        num[j - 1] = temp;
        dat++;
      }
      key++;
    }
  }
  
  for (i = 0; i < N; i++) 
    printf("%2d ", num[i]);
  printf("\n");
  
  printf("key  : %2d\ndata : %2d\n", key, dat);
  
  return 0;
}
