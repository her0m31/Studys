/* progression.c */
#include <stdio.h>

int main()
{
  int n, r;

  printf(" Input a first number, please?  ");
  scanf("%d", &n);

  printf(" Input a second number, please?  ");
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r));
 
  return 0;
}

int answer3(int n, int r)
{
  int i, a;
  int answer3 = 1 + r;
  
  a = r;
  for (i = 3; i <= n; i++){
    answer3 += (a * r);
    a = (a * r);
  }

  return answer3;
}
