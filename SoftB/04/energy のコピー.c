/* energy.c */
#include <stdio.h>

int main()
{
  double c = 299792458.0;	                           /* ��® */
  double m;			                           /* �Ť� */

  printf("weight?\n");		                           /* �Ť������� */
  scanf("%lf", &m);

  printf(" E = %e\n", (m * (c * c)));                      /* �׻���̤���� */
  
  return 0;
}
