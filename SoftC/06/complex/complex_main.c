/* complex_main.c */
#include <stdio.h>
#include "complex.h"

int main()
{
  struct complex x;
  struct complex y;

  printf("z1 = X + Yi ");
  scanf("%lf %lf", &x.real, &x.imaginary);

  printf("z2 = X + Yi ");
  scanf("%lf %lf", &y.real, &y.imaginary);

  printf("\n");

  printf("add\n");
  put_complex(add(x, y));
  
  printf("minus\n");
  put_complex(min(x, y));

  printf("Multiplication\n");
  put_complex(mul(x, y));
 
  printf("divid\n");
  put_complex(div(x, y));

  return 0;
}
