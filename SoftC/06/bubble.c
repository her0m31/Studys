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

/* 1. i=0〜i=N-2の間繰り返す */  
  for(i = 0; i < N - 2; i++){              

/* 2. jをN - 1とする   4. jを1減らしj>iなら繰り返し3に進む */
    for(j = N - 1; i < j; j--){       

/* 3. num[j]とnum[j-1]を比較し、num[j]のほうが小さければ交換する */
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
