/* progression.c */
#include <stdio.h>
/* �ץ�ȥ�������� */
int answer(int n);
int answer2(int n);
int answer3(int n, int r);

int main()
{
  int n, r;			                                      /* ���� */

  printf(" Input a first number, please? ");
  scanf("%d", &n);		                                      /* ���������� */

  printf("The first progression is %d.\n",answer(n) );                /* i��������� */

  printf("The second progression is %d.\n", answer2(n));              /* i�λ������� */

  printf(" Input a first number, please?  ");                         /* ���������� */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                        /* ���������� */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r)); /* r��i������ */
 
  return 0;
}
/* i�����δؿ� */
int answer(int n)
{
  int i;
  int answer = 0;

  for (i = 1; i <= n; i++)
    answer += i * i;

  return answer;
}
/* i�λ���δؿ� */
int answer2(int n)
{
  int i;
  int answer2 = 0;

  for (i = 1; i <= n; i++)
    answer2 += i * i * i;

  return answer2;
}
/* r��i��δؿ� */
int answer3(int n, int r)
{
  int i, a = 1;
  int answer3 = 1;

  for (i = 1; i < n; i++){
    answer3 += (a * r);
    a = (a * r)
  }
  
  return answer3;  
}
