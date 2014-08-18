/* calc-polar.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define square(x) ((x) * (x))

double radius(double x, double y)
{
  return sqrt(square(x) + square(y));
}

double theta(double x, double y)
{
  return atan(y / x);
}

int main(int argc, char **argv)
{
  double x, y;
  double r, t;

  if (argc == 3 && (x = atof(argv[1])) && (y = atof(argv[2]))){
    r = radius(x, y);
    t = theta(x, y);

    printf("r: %f, t: %f\n", r, t);
  }
  return 0;
}
