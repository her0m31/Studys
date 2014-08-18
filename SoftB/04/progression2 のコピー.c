/* progression.c */
#include <stdio.h>

int main()
{
  int n, r;

  printf(" Input a first number, please? ");
  scanf("%d", &n);

  printf("The first progression is %d.\n",answer(n) );

  printf("The second progression is %d.\n", answer2(n));

  printf(" Input a first number, please?  ");
  scanf("%d", &n);

  printf(" Input a second number, please?  ");
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r));
 
  return 0;
}

int answer(int n)
{
  return ((n * (n + 1) * ((2 * n) + 1)) / 6);
}

int answer2(int n)
{
  return ((n * (n + 1) / 2) * (n * (n + 1)) / 2);
}

int answer3(int n, int r)
{
  int i, a = 2;

  for(i = 2; i <= n; i++)
    a *= r;

  return ((a - 1) / (r - 1));
}
