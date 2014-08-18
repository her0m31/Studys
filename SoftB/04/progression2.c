/* progression2.c */
#include <stdio.h>
/* プロトタイプ宣言 */
int answer(int n);
int answer2(int n);
int answer3(int n, int r);

int main()
{
  int n, r;                                                           /* 入力 */

  printf(" Input a first number, please? ");                          /* 数字を入力 */
  scanf("%d", &n);

  printf("The first progression is %d.\n",answer(n) );                /* iの二乗を出力 */ 

  printf("The second progression is %d.\n", answer2(n));              /* iの三乗を出力 */


  printf(" Input a first number, please?  ");                        /* 数字を入力 */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                       /* 数字を入力 */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r));              /* rのi乗を出力 */
 
  return 0;
}
/* iの二乗の関数 */
int answer(int n)
{
  return ((n * (n + 1) * ((2 * n) + 1)) / 6);
}
/* iの三乗の関数 */
int answer2(int n)
{
  return ((n * (n + 1) / 2) * (n * (n + 1)) / 2);
}
/* rのi乗の関数 */
int answer3(int n, int r)
{
  int i, a = r;

  if(r == 1)
    return n;
  else{
    for(i = 1; i < n; i++)
       a *= r;
   return ((a - 1) / (r - 1));
  }
}
