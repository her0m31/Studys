/*1-40.c*/
#include<stdio.h>

main()
{
  int i;
  int n;

  printf("Input a number, Please ?\n");
  scanf("%d", &n);

  printf("  multiple of 4\n");

  for (i = 1; i <= n; i++){
    if(i % 4 == 0)
      printf("    %d", i);
  }
  printf("\n");
}

