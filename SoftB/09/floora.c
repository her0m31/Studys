/* floora.c */
#include <stdio.h>

double floor(double num);

int main()
{
  double a;

  printf("Input a real number:");
  scanf("%lf", &a);
  
  printf("\tInteger:%f\n", floor(a));
  
  return 0;
}

double floor(double num)
{
  return (double)(int)(num);
}
