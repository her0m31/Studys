/* scanprintf.c */
#include <stdio.h>
/* �ץ�ȥ�������� */
int plus(int a, int b);
int minus(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main()
{
  int a, b;			                                    /* ���� */

  printf(" Input a  number, please? ");
  scanf("%d", &a);		                                    /* 1���ܤο��������� */

  printf(" Input a  number2, please?  ");
  scanf("%d", &b);		                                    /* 2���ܤο��������� */
  
  printf(" a + b = %d    %x\n", plus(a, b),  plus(a, b));          /* a+b����� */

  printf(" a - b = %d    %x\n", minus(a, b), minus(a, b));         /* a-b����� */

  printf(" a * b = %d     %x\n", mul(a, b), mul(a, b));            /* a*b����� */
 
  if (b == 0)
    printf(" Unknown.\n");	                                    /* b��0�ξ�� */
  else
  printf(" a / b = %d    %x\n", div(a, b), div(a, b));	             /* ����ʳ��λ� */
 
  return 0;
}
/* a+b�δؿ� */
int plus(int a, int b)
{
  return a + b;
}
/* a-b�δؿ� */
int minus(int a, int b)
{
  return a - b;
}
/* a*b�δؿ� */
int mul(int a, int b)
{
  return a * b;
}
/* a/b�δؿ� */
int div(int a, int b)
{
  return a / b;
}
