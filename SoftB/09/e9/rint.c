/* rint.c */
#include <stdio.h>
#include <math.h>

int main()
{
  double a, b;

  printf("Input a real number:");
  scanf("%lf", &a);

  b = rint(a);

  printf("\t    Integer:%f\n", b);
  
  return 0;
}
