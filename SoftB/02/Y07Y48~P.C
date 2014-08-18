/* y=ax*x+bx+c.c */
#include <stdio.h>

main()
{
  int a, b, c, x;

  printf("a: ");
  scanf("%d", &a);

  printf("b: ");
  scanf("%d", &b);

  printf("c: ");
  scanf("%d", &c);

  printf("y= ax*x + bx + c=(%d)x*x + (%d)x + (%d) \n", a, b, c);

  printf("x: ");
  scanf("%d", &x);

  printf("y= %d, if x= %d.", a * (x * x) + b * x + c, x);
}
