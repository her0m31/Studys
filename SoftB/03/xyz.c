/*XYZ.c*/
#include<stdio.h>

main()
{
  int x, y, z;
  int m;

  printf("x = ");
  scanf("%d", &x);

  printf("y = ");
  scanf("%d", &y);

  printf("z = ");
  scanf("%d", &z);

    if (x > y)
      m = x;
    else
      m = y;
    if (z > m)
      m = z;

	printf(" maximum  %d\n", m);
}
