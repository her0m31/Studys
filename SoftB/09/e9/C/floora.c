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
  if (num >= 0)
    return (double)(int)(num);
  else{
    if (num - (double)(int)num == 0.0)
      return (double)(int)num;
    else
      return (double)(int)(num - 1.0);
  }
}
