/* e242.c */
#include <stdio.h>

main()
{
  int a, b, c;

  printf("a: ");
  scanf("%d", &a);

  printf("b: ");
  scanf("%d", &b);

  printf("c: ");
  scanf("%d", &c);

  printf("(a >= 2 || b == 1 && c > 0)\n");

  printf("%d\n",  a >= 2 || b == 1 && c > 0);
}
