/* e2-4-1.c */
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

  printf("((a >= 2 || b == 1) && c > 0)");

  printf("%d", ( a >= 2 || b == 1) && c > 0);
}
