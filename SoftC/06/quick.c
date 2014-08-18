/* quick.c */
#include <stdio.h>

#define N 10

void quick(int n[], int start, int end, int time[]);

int main()
{
  int time[2] = {0, 0};
  int num[N] = {7, 20, 1, 18, 9, 15, 24, 10, 3, 12};
  int i = 0;
  int j = N - 1;
  
  quick(num, i, j, time);
  
  for(i = 0; i < N; i++)
    printf("%d ", num[i]);
  printf("\n");
  
  printf("key  : %2d\ndata : %2d\n", time[0], time[1]);
  
  return 0;
}

void quick(int n[], int start, int end, int time[])
{
  int temp;
  int pivo;
  int i;
  int j;
  
  i = start;
  j = end;
  
  /* ピボットの決定 */
  pivo = n[(start + end)/2];
  
  while(i <= j){
    
    /* 左方向からの要素の探索 */
    while(++time[0] && n[i] < pivo)
      i++;

    /* 右方向からの要素の探索 */
    while(++time[0] && pivo < n[j])
      j--;
    
    if(i < j && ++time[0] && n[i] != n[j]){
      temp = n[i];
      n[i] = n[j];
      n[j] = temp;
      time[1]++;
      i++;
      j--;
    }
    
    if(i == j || (++time[0] && n[i] == n[j])){
      i++;
      j--;
    }
  } 
  
  /* 左方向にソートできる要素があれば再帰 */   
  if(start <  i - 1) 
    quick(n, start, i - 1, time); 
  /* 右方向にソートできる要素があれば再帰 */
  if(i < end) 
    quick(n, i , end, time); 
}
