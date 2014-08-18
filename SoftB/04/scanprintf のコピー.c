/* scanprintf.c */
#include <stdio.h>

int plus(int a, int b), minus(int a, int b), mul(int a, int b), div(int a, int b);

int main()
{
  int a, b;

  printf(" Input a  number, please? ");
  scanf("%d", &a);

  printf(" Input a  number2, please?  ");
  scanf("%d", &b);
  
  printf(" a + b = %d.   %x.\n", plus(a, b),  plus(a, b));

  printf(" a - b = %d.   %x.\n", minus(a, b), minus(a, b));

  printf(" a * b = %d.    %x.\n", mul(a, b), mul(a, b));
 
  if (b == 0)
    printf(" Unknown.\n");
  else
  printf(" a / b = %d.   %x.\n", div(a, b), div(a, b));
 
  return 0;
}

int plus(int a, int b)
{
  return a + b;
}

int minus(int a, int b)
{
  return a - b;
}

int mul(int a, int b)
{
  return a * b;
}

int div(int a, int b)
{
  return a / b;
}
