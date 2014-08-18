/* scanprintf.c */
#include <stdio.h>
/* プロトタイプ宣言 */
int plus(int a, int b);
int minus(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main()
{
  int a, b;			                                    /* 入力 */

  printf(" Input a  number, please? ");
  scanf("%d", &a);		                                    /* 1つ目の数字を入力 */

  printf(" Input a  number2, please?  ");
  scanf("%d", &b);		                                    /* 2つ目の数字を入力 */
  
  printf(" a + b = %d    %x\n", plus(a, b),  plus(a, b));          /* a+bを出力 */

  printf(" a - b = %d    %x\n", minus(a, b), minus(a, b));         /* a-bを出力 */

  printf(" a * b = %d     %x\n", mul(a, b), mul(a, b));            /* a*bを出力 */
 
  if (b == 0)
    printf(" Unknown.\n");	                                    /* bが0の場合 */
  else
  printf(" a / b = %d    %x\n", div(a, b), div(a, b));	             /* それ以外の時 */
 
  return 0;
}
/* a+bの関数 */
int plus(int a, int b)
{
  return a + b;
}
/* a-bの関数 */
int minus(int a, int b)
{
  return a - b;
}
/* a*bの関数 */
int mul(int a, int b)
{
  return a * b;
}
/* a/bの関数 */
int div(int a, int b)
{
  return a / b;
}
