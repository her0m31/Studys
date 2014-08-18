/* map.c */
#include <stdio.h>

void displaymap(int a[][8]);

int main()
{
  int a[][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 1, -1, 0, 0, 0},
                {0, 0, 0, -1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0}};
  
  displaymap(a);
  
  return 0;
}

void displaymap(int a[][8])
{
  int i, j;
  char c[] = "X-0";
  
  for (j = 0; j < 8; j++){
    for (i = 0; i < 8; i++){
      printf(" %c",c[a[i][j] + 1]);
    }
    printf("\n");
  }
}
