/* bmi.c */
#include <stdio.h>

int main()
{
  float t, m;			            /* 入力用 */
  float bmi = 22.0;		            /* 標準BMI */

  printf(" Height?  ");		            /* 身長を入力 */
  scanf("%f", &t);

  printf(" Weight?  ");		            /* 体重を入力 */
  scanf("%f", &m);

  printf(" BMI = %f\n", (m / (t * t)));	    /* BM値を出力 */
  printf(" Standard Weight = %f\n", ((t * t) * bmi));      /* 標準体重を出力 */

  return 0;
}
