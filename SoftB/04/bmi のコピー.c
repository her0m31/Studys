/* bmi.c */
#include <stdio.h>

int main()
{
  float t, m;			            /* ������ */
  float bmi = 22.0;		            /* ɸ��BMI */

  printf(" Height?  ");		            /* ��Ĺ������ */
  scanf("%f", &t);

  printf(" Weight?  ");		            /* �νŤ����� */
  scanf("%f", &m);

  printf(" BMI = %f\n", (m / (t * t)));	    /* BM�ͤ���� */
  printf(" Standard Weight = %f\n", ((t * t) * bmi));      /* ɸ���νŤ���� */

  return 0;
}
