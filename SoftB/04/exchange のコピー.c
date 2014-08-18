/* exchange.c(為替) */
#include <stdio.h>

int main()
{
  char c;			                /* 入力用 */
  float yen;			                /* 日本円 */
  float answer;			                /* 変換後 */
  float cy;			                /* 変数用 */

  printf(" How many yen?  ");
  scanf("%f", &yen);		                /* 何円かを入力 */

  printf(" Which currency?  ");
  scanf("%*c %c", &c);	       	                /* 通貨の頭文字を入力 */

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
