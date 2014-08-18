/* cbt.c */
#include <stdio.h>

#define N 10

int cbt(int dat[], int c, int x);

int main()
{
  int dat[N + 1] = {-1, 4, 1, 7, 9, 0, 6, 3, 5, 8, 2}; 
  int num;
  int i;
 
  printf("数字を入力  ");
  
  scanf("%d", &num);
  for(i = 1; i < N+1; i++){
    if(num == dat[i])
      break;
  }
  if(i == N+1){
    printf("error!\n");
    return -1;
  }

  if(i > 1)
    printf("parent  %d\n", dat[i/2]);
  
  if(2*i <= N){
    printf("child_l %d\n", dat[2*i]);
    if(2*i+1 <= N)
      printf("child_r %d\n", dat[2*i+1]);
  }

  return 0;
}
