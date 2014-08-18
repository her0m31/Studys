/*XYZ*/
#include<stdio.h>

main()
{
  int X, Y, Z, M;

  printf("X = ");
  scanf("%d", &X);

  printf("Y = ");
  scanf("%d", &Y);

  printf("Z = ");
  scanf("%d", &Z);


  if (X == Y, X == Z)
    printf(" all are equal.\n");
  else {
    if (X > Y)
      M = X;
    else
      M = Y;
    if (M > Z)
      printf(" maximum  %d\n", M);
    else
      printf(" maximum  %d\n", Z);
    
  }
}

