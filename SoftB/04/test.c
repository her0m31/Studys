/* progression.c */
#include <stdio.h>
/* プロトタイプ宣言 */
int answer(int n);
int main()
{
  int n, r;			                                      /* 入力 */

  printf(" Input a first number, please?  ");                         /* 数字を入力 */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                        /* 数字を入力 */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r)); /* rのi乗を出力 */
 
  return 0;
}

/* rのi乗の関数 */
int answer3(int n, int r)
{
  int i, a = 1;
  int answer3 = 1;

  for (i = 1; i < n; i++){
    answer3 += (a * r);
    a = (a * r);
  }

  return answer3;  
}
