/* equation.c */
#include <stdio.h>

void equation(int a, int b, int c, int d);

int main()
{
  int a, b, c, d;

  printf("(ax+b)(cx+d)\n");

  printf("a = ");
  scanf("%d", &a);

  printf("b = ");
  scanf("%d", &b);

  printf("c = ");
  scanf("%d", &c);

  printf("d = ");
  scanf("%d", &d);
  
  equation(a, b, c, d);

  return 0;  
}
    
void equation(int a, int b, int c, int d)
{
  int first, second, third;

  first = a * c;
  second = (a * d) + (b * c);
  third = b * d;

  printf("(%d)X*X + (%d)X + (%d)\n", first, second, third);
}
