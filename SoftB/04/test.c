/* progression.c */
#include <stdio.h>
/* �ץ�ȥ�������� */
int answer(int n);
int main()
{
  int n, r;			                                      /* ���� */

  printf(" Input a first number, please?  ");                         /* ���������� */
  scanf("%d", &n);

  printf(" Input a second number, please?  ");                        /* ���������� */
  scanf("%d", &r);

  printf("The third progression is %d.\n", answer3(n, r)); /* r��i������ */
 
  return 0;
}

/* r��i��δؿ� */
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
