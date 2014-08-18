/* complex.c */
#include <stdio.h>

struct orthogonal_complex {
  double real;
  double imaginary;
};

struct orthogonal_complex define_orthogonal_complex(int x, int y);

void put_orthogonal_complex(struct orthogonal_complex z);

int main()
{
  int x, y;
 
  scanf("%d", &x);
  scanf("%d", &y);

  put_orthogonal_complex(define_orthogonal_complex(x, y));
  
  return 0;
}

struct orthogonal_complex define_orthogonal_complex(int x, int y)
{
  struct orthogonal_complex r;
  r.real      = x;
  r.imaginary = y;
  return r;
}

void put_orthogonal_complex(struct orthogonal_complex z)
{
  printf("z = %.2f%+.2fi\n", z.real, z.imaginary);
}
