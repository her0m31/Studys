/* fib.c */
#include <stdio.h>

int fib(int n);			               /* プロトタイプ宣言 */

int main()
{
  int n;			               /* 入力 */

  printf("which number?  ");	               /* 数字を入力 */
  scanf("%d", &n);

  printf("fib(%d) = %d\n", n, fib(n));         /* 計算結果を出力 */

  return 0;
}

int fib(int n)			               /* fib関数 */
{
  if (n > 1)
    return fib(n - 1) + fib(n - 2);            /* 関数の再起呼出 */
  else if (n == 0)
    return 0;			               /* 0が入力されたとき */
  else if (n == 1)
    return 1;			               /* 1が入力されたとき */
}
