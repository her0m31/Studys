/* complex_min.c */
#include <stdio.h>
#include "complex.h"

struct complex mul(struct complex x, struct complex y)
{
  struct complex z;
  z.real = (x.real * y.real - x.imaginary * y.imaginary);
  z.imaginary = (x.real * y.imaginary + y.real * x.imaginary);
  return z;
}
