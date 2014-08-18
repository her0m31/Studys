/* rinta.c */
#include <stdio.h>

double rint(double num);

int main()
{
  double a, b;

  printf("Input a real number:");
  scanf("%lf", &a);
  
  printf("\tInteger:%f\n", rint(a));
  
  return 0;
}

double rint(double num)
{
  return (double)(int)(num + 0.5);
}
