/* fre.c */
#include <stdio.h>

int main()
{
  int i, y[3] = {0,0,0};
  float x;
  char z[] = "*";
  

  for (i = 0; i < 10; i++){
    scanf("%f", &x);

    x = (int)x;
    
    while (0 == x){
      y[0]++;
      break;
    }

    while (1 == x){
      y[1]++;
      break;
    }

    while (2 == x){
      y[2]++;
      break;
    }
  }

   
  printf("Interval | Frequency\n");
  printf("---------+----------\n");
  printf("[0, 1)   | ");
  for (i = 1; i <= y[0]; i++){
    printf("%s", z);
  }
  printf("\n");
  printf("[0, 2)   | ");
  for (i = 1; i <= y[1]; i++){
    printf("%s", z);
  }
  printf("\n");
  printf("[0, 3)   | ");
  for (i = 1; i <= y[2]; i++){
    printf("%s", z);
  }
  printf("\n");

    return 0;
}
