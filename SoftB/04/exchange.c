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

  if (c == 'u'){		                /* u�����Ϥ��줿�� */
    cy = 90.66;
    printf("USD = ");
  }
  else if (c == 'g'){		                /* g�����Ϥ��줿�� */
    cy = 149.00;
    printf("GBP = ");
  }
  else if (c == 'e'){		                /* e�����Ϥ��줿�� */
    cy = 135.43;
    printf("EUR = ");
  }
  else if (c == 'k'){		                /* k�����Ϥ��줿�� */
    cy = 0.08;
    printf("KRW = ");
  } 
  else {			                /* ����ʳ��λ� */
    printf(" Unknown.\n");
    return 0;
  }
  answer = (yen / cy);		                /* ���� */
  printf("%.2f\n", answer);	                /* �Ѵ����줿��ۤ���� */

  return 0;
}
