/* scanprintf2.c */
#include <stdio.h>

float plus(float c, float d), minus(float c, float d), mul(float c, float d), div(float c, float d);


int main()
{
  float c, d;

  printf(" Input a  number, please? ");
  scanf("%f", &c);

  printf(" Input a  number2, please?  ");
  scanf("%f", &d);
  
  printf(" c + d = %.4f.   %e.\n", plus(c, d),  plus(c, d));

  printf(" c - d = %.4f.   %e.\n", minus(c, d), minus(c, d));

  printf(" c * d = %.4f.    %e.\n", mul(c, d), mul(c, d));
 
  if (d == 0)
    printf(" Unknown.\n");
  else
  printf(" c / d = %.4f.   %e.\n", div(c, d), div(c, d));
 
  return 0;
}

float plus(float c, float d)
{
  return c + d;
}

float minus(float c, float d)
{
  return c - d;
}

float mul(float c, float d)
{
  return c * d;
}

float div(float c, float d)
{
  return c / d;
}
