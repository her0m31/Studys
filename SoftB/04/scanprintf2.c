/* scanprintf2.c */
#include <stdio.h>
/* �ץ�ȥ�������� */
float plus(float c, float d);
float minus(float c, float d);
float mul(float c, float d);
float div(float c, float d);


int main()
{
  float c, d; 			                                        /* ���� */

  printf(" Input a  number, please? ");
  scanf("%f", &c);		                                        /* ���������� */

  printf(" Input a  number2, please?  ");
  scanf("%f", &d);		                                        /* ���������� */
  
  printf(" c + d = %.4f     %e\n", plus(c, d),  plus(c, d));            /* c+d����� */

  printf(" c - d = %.4f     %e\n", minus(c, d), minus(c, d));           /* c-d����� */

  printf(" c * d = %.4f     %e\n", mul(c, d), mul(c, d));              /* c*d����� */
 
  if (d == 0)
    printf(" Unknown.\n");	                                        /* d��0���������줿�� */
  else
  printf(" c / d = %.4f     %e\n", div(c, d), div(c, d));               /* ����ʳ��λ� */
 
  return 0;
}

/* c+d�δؿ� */
float plus(float c, float d)
{
  return c + d;
}
/* c-d�δؿ� */
float minus(float c, float d)
{
  return c - d;
}
/* c*d�δؿ� */
float mul(float c, float d)
{
  return c * d;
}
/* c/d�δؿ� */
float div(float c, float d)
{
  return c / d;
}
