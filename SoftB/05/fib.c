/* fib.c */
#include <stdio.h>

int fib(int n);			               /* �ץ�ȥ�������� */

int main()
{
  int n;			               /* ���� */

  printf("which number?  ");	               /* ���������� */
  scanf("%d", &n);

  printf("fib(%d) = %d\n", n, fib(n));         /* �׻���̤���� */

  return 0;
}

int fib(int n)			               /* fib�ؿ� */
{
  if (n > 1)
    return fib(n - 1) + fib(n - 2);            /* �ؿ��κƵ��ƽ� */
  else if (n == 0)
    return 0;			               /* 0�����Ϥ��줿�Ȥ� */
  else if (n == 1)
    return 1;			               /* 1�����Ϥ��줿�Ȥ� */
}
