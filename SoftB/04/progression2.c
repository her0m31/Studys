/* progression2.c */
#include <stdio.h>
/* �ץ�ȥ�������� */
int answer(int n);
int answer2(int n);
int answer3(int n, int r);

int main()
{
  int n, r;                                                           /* ���� */

  printf(" Input a first number, please? ");                          /* ���������� */
  scanf("%d", &n);

  printf("The first progression is %d.\n",answer(n) );                /* i��������� */ 

  printf("The second progression is %d.\n", answer2(n));              /* i�λ������� */


  printf(" Input a first number, please?  ");                        /* ���������� */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                       /* ���������� */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r));              /* r��i������ */
 
  return 0;
}
/* i�����δؿ� */
int answer(int n)
{
  return ((n * (n + 1) * ((2 * n) + 1)) / 6);
}
/* i�λ���δؿ� */
int answer2(int n)
{
  return ((n * (n + 1) / 2) * (n * (n + 1)) / 2);
}
/* r��i��δؿ� */
int answer3(int n, int r)
{
  int i, a = r;

  if(r == 1)
    return n;
  else{
    for(i = 1; i < n; i++)
       a *= r;
   return ((a - 1) / (r - 1));
  }
}
