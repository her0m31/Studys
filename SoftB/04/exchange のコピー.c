/* exchange.c(����) */
#include <stdio.h>

int main()
{
  char c;			                /* ������ */
  float yen;			                /* ���ܱ� */
  float answer;			                /* �Ѵ��� */
  float cy;			                /* �ѿ��� */

  printf(" How many yen?  ");
  scanf("%f", &yen);		                /* ���ߤ������� */

  printf(" Which currency?  ");
  scanf("%*c %c", &c);	       	                /* �̲ߤ�Ƭʸ�������� */

  if (c == 'u'){
    cy = 90.66;
    printf("USD = ");
  }
  else if (c == 'g'){
    cy = 149.00;
    printf("GBP = ");
  }
  else if (c == 'e'){
    cy = 135.43;
    printf("EUR = ");
  }
  else if (c == 'k'){
    cy = 0.08;
    printf("KRW = ");
  } 
  else {
    printf(" Unknown.\n");
    return 0;
  }
  answer = (yen * cy);
  printf("%.2f\n", answer);

  return 0;
}
