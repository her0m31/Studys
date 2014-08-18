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
  int i;
  int answer = 0;

  for (i = 1; i <= n; i++)
    answer += i * i;

  return answer;
}

int answer2(int n)
{
  int i;
  int answer2 = 0;

  for (i = 1; i <= n; i++)
    answer2 += i * i * i;

  return answer2;
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
