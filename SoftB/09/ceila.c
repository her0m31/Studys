/* rinta.c */
#include <stdio.h>

double ceil(double num);

int main()
{
  double a;

  printf("Input a real number:");
  scanf("%lf", &a);
  
  printf("\tInteger:%f\n", ceil(a));
  
  return 0;
}

double ceil(double num)
{
  return (double)(int)(num + 0.9);
}
