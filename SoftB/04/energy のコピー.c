/* energy.c */
#include <stdio.h>

int main()
{
  double c = 299792458.0;	                           /* 光速 */
  double m;			                           /* 重さ */

  printf("weight?\n");		                           /* 重さを入力 */
  scanf("%lf", &m);

  printf(" E = %e\n", (m * (c * c)));                      /* 計算結果を出力 */
  
  return 0;
}
