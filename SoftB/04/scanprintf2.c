/* scanprintf2.c */
#include <stdio.h>
/* プロトタイプ宣言 */
float plus(float c, float d);
float minus(float c, float d);
float mul(float c, float d);
float div(float c, float d);


int main()
{
  float c, d; 			                                        /* 入力 */

  printf(" Input a  number, please? ");
  scanf("%f", &c);		                                        /* 数字を入力 */

  printf(" Input a  number2, please?  ");
  scanf("%f", &d);		                                        /* 数字を入力 */
  
  printf(" c + d = %.4f     %e\n", plus(c, d),  plus(c, d));            /* c+dを出力 */

  printf(" c - d = %.4f     %e\n", minus(c, d), minus(c, d));           /* c-dを出力 */

  printf(" c * d = %.4f     %e\n", mul(c, d), mul(c, d));              /* c*dを出力 */
 
  if (d == 0)
    printf(" Unknown.\n");	                                        /* dに0が代入された時 */
  else
  printf(" c / d = %.4f     %e\n", div(c, d), div(c, d));               /* それ以外の時 */
 
  return 0;
}

/* c+dの関数 */
float plus(float c, float d)
{
  return c + d;
}
/* c-dの関数 */
float minus(float c, float d)
{
  return c - d;
}
/* c*dの関数 */
float mul(float c, float d)
{
  return c * d;
}
/* c/dの関数 */
float div(float c, float d)
{
  return c / d;
}
