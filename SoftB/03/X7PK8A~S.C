/*dividing*/
#include<stdio.h>

main()
{
  int X, Y, A, i;

  printf("Input a number, Please?\n");

  printf("X = ");
  scanf("%d", &X);

  printf("Y = ");
  scanf("%d", &Y);
  
  if (Y == 0)
    printf(" unknown.");
  else if (X % Y ==0)
    printf(" X / Y = %d", X/Y);
  else{
    A = X / Y;
    X = X % Y;
    printf (" X / Y = %d.", A);
    for (i = 1; i <= 20; i++){  
      printf ("%d", (X * 10) / Y);
      if ((X * 10) % Y == 0)
	break;
      else
	X = (X * 10) % Y;
    }
  }
  printf("\n");
}
