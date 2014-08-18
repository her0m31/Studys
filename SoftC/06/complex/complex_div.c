/* complex_div.c */
#include <stdio.h>
#include "complex.h"

struct complex div(struct complex x, struct complex y)
{
  struct complex z;
  z.real = (x.real * y.real - x.imaginary * y.imaginary)
    / (x.real * x.real) + (y.imaginary * y.imaginary);
  z.imaginary = (x.real * y.imaginary + y.real * x.imaginary)
    / (x.real * x.real) + (y.imaginary * y.imaginary);
  return z;
}
