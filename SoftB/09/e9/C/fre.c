/* fre.c */
#include <stdio.h>

int main()
{
  int i, n, y[3] = {0,0,0};
  float x;
  char z[] = "*";

  for (i = 0; i < 10; i++){
    scanf("%f", &x);
    y[(int)x]++;
  }

  printf("Interval | Frequency\n");
  printf("---------+----------\n");
  
  for (n = 0; n < 3; n++){
    printf("[%d, %d)   | ", n, n + 1);
    for (i = 0; i < y[n]; i++){
      printf("%s", z);
    }
    printf("\n");
  }

  return 0;
}
