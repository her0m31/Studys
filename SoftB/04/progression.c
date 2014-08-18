/* progression.c */
#include <stdio.h>
/* プロトタイプ宣言 */
int answer(int n);
int answer2(int n);
int answer3(int n, int r);

int main()
{
  int n, r;			                                      /* 入力 */

  printf(" Input a first number, please? ");
  scanf("%d", &n);		                                      /* 数字を入力 */

  printf("The first progression is %d.\n",answer(n) );                /* iの二乗を出力 */

  printf("The second progression is %d.\n", answer2(n));              /* iの三乗を出力 */

  printf(" Input a first number, please?  ");                         /* 数字を入力 */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                        /* 数字を入力 */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r)); /* rのi乗を出力 */
 
  return 0;
}
/* iの二乗の関数 */
int answer(int n)
{
  int i;
  int answer = 0;

  for (i = 1; i <= n; i++)
    answer += i * i;

  return answer;
}
/* iの三乗の関数 */
int answer2(int n)
{
  int i;
  int answer2 = 0;

  for (i = 1; i <= n; i++)
    answer2 += i * i * i;

  return answer2;
}
/* rのi乗の関数 */
int answer3(int n, int r)
{
  int i, a = 1;
  int answer3 = 1;

  for (i = 1; i < n; i++){
    answer3 += (a * r);
    a = (a * r)
  }
  
  return answer3;  
}
