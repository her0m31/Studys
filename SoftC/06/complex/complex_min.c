/* complex_min.c */
#include <stdio.h>
#include "complex.h"

struct complex min(struct complex x, struct complex y)
{
  struct complex z;
  z.real = x.real - y.real;
  z.imaginary = x.imaginary - y.imaginary;
  return z;
}
