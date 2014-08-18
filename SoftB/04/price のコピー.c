/* price.c */
#include <stdio.h>

int main()
{
  char c;		                       /* 入力用 */
  int  n;		                       /* 入力用 */
  int price;			               /* 値段 */
  int up;			               /* 単価 */

  printf(" banana? apple? orange? ");
  scanf("%c", &c);		               /* 1文字入力 */

  if (c == 'a')
    up = 125;			               /* 林檎の値段を代入 */
  else if (c == 'b')
    up = 60;			               /* バナナの値段を代入 */
  else if (c == 'o')
    up = 82;			               /* オレンジの値段を代入 */
  else {
    printf(" Unknown.\n");		     /* 上のどれでもない時 */
    return 0;
  }
 
 printf(" how many? ");
 scanf("%d", &n);		               /* 個数入力 */

 price = (up * n);
 printf("price %d\n", price);	               /* 値段を出力 */
	
 return 0;
}
