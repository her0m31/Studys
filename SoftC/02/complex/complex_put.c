/* complex_put.c */
#include <stdio.h>
#include "complex.h"

void put_complex(struct complex z)
{
  printf(" %.2lf%+.2lfi\n", z.real, z.imaginary);
}
