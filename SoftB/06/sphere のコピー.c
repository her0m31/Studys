/*sphere.c*/
#include <stdio.h>

float sphere(float d);

int main()
{
  float d;

  printf("Input a number, please ?   ");
  scanf("%f", &d);

  printf("Volume of sphere is  %f(L)\n", sphere(d));

  return 0;
}

float sphere(float d)
{
  float pi = 3.14159265338979323846;

  return (pi * (d * d * d)) / 6;
}
