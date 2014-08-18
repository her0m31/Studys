/*x:y.c*/
#include<stdio.h>

main()
{
  int x, y;
  int a;
  int i;

  printf("Input a number, Please?\n");

  printf("X = ");
  scanf("%d", &x);

  printf("Y = ");
  scanf("%d", &y);
  
  if(y == 0)
    printf("  The divided number is 0. ");
  else if (x % y ==0)
    printf(" X / Y = %d", x/y);
  else{
    a = x / y;			
    x = x % y;			
    printf (" X / Y = %d.", a);
    for (i = 1; i <= 20; i++){  
      printf ("%d", (x * 10) / y);
      if ((x * 10) % y == 0)
        break;
      else
        x = (x * 10) % y;
    }
  }
  printf("\n");
}
