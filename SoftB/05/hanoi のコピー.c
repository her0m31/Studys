/* hanoi.c */
#include <stdio.h>

int hanoi(int dis, int a, int b, int c);

int main()
{
  int dis, a, b, c;

  printf("How Many Disk? : ");
  scanf("%d", &dis);

  printf("From Where? [1-3] : ");
  scanf("%d", &a);

  printf("To where? [1-3] : ");
  scanf("%d", &b);

  if (a == b)
      return printf("Have the same start and finish\n");
  else{
    c = 6 - (a + b);
    printf("", hanoi(dis, a, b, c));

    return 0;
  }
}


int hanoi(int dis, int a, int b, int c)
{
  if (dis > 0)
    return hanoi(dis - 1, a, c, b),  printf("Move disk %d from pole %d to pole %d\n", dis, a, b), hanoi(dis - 1, c, b, a);
}
