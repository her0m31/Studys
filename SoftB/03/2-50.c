/*2-50.c*/
#include<stdio.h>

main()
{
  int n;
  int i, x;
  int div;

  printf("Input a number, Please ?\n");
  scanf("%d", &n);

  printf("  pn\n");

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
