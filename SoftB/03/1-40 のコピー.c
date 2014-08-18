/*1~40*/
#include<stdio.h>

main()
{
  int i;
  int n;

  printf("Input a number, Please ?\n");
  scanf("%d", &n);

  for (i = 1; i <= n; i++){
    if(i % 4 == 0)
    printf("mul = %d\n", i);
  }
}

