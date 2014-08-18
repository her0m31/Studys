/* ceila.c */
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
  if (num > 0.0){
    if (num - (double)(int)num != 0.0)
      return (double)((int)num + 1);
  }  
  else 
    return (double)(int)num;
  
}
