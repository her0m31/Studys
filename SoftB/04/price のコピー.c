/* price.c */
#include <stdio.h>

int main()
{
  char c;		                       /* ������ */
  int  n;		                       /* ������ */
  int price;			               /* ���� */
  int up;			               /* ñ�� */

  printf(" banana? apple? orange? ");
  scanf("%c", &c);		               /* 1ʸ������ */

  if (c == 'a')
    up = 125;			               /* �Ӹ�����ʤ����� */
  else if (c == 'b')
    up = 60;			               /* �Хʥʤ����ʤ����� */
  else if (c == 'o')
    up = 82;			               /* ����󥸤����ʤ����� */
  else {
    printf(" Unknown.\n");		     /* ��Τɤ�Ǥ�ʤ��� */
    return 0;
  }
 
 printf(" how many? ");
 scanf("%d", &n);		               /* �Ŀ����� */

 price = (up * n);
 printf("price %d\n", price);	               /* ���ʤ���� */
	
 return 0;
}
