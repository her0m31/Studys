/* square.c */
#include <stdio.h>

#define square(x) ((x) * (x))

int main()
{
  double a = -5.0, b = -5.0;

  printf("square(a+b)       = %lf\n", square(a+b));
  printf("(a+b)/square(a+b) = %lf\n", (a+b)/square(a+b));

  return 0;
}
