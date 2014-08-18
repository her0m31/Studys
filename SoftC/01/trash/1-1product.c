/* 1-1product.c */
#include <stdio.h>

#define mult(a, b) ((a) * (b))

int main(int argc, char *argv[])
{
  int x, y, z;

  printf("x = ");
  scanf("%d", &x);
  
  printf("y = ");
  scanf("%d", &y);

  z = mult(x+y, x-y);

  printf("(x+y)(x-y) = %d\n", z);

  return 0;
}
