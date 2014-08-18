/*2~50*/
#include<stdio.h>

main()
{
  int n, i, div, x;

  printf("Input a number, Please ?\n");
  scanf("%d", &n);

  printf("  div\n");

  for (i = 2; i <= n; i++){
    div = 0;
    for(x = 1; x <= i; x++){
      if (i % x == 0)
	div++;
    }
    if (div == 2)
      printf("  %d", i);
  }
  printf("\n");
}
