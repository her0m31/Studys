/* rev.c */
#include <stdio.h>

void displaymap (int a[8][8]);
int reverse (int a[8][8], int c, int x, int y, int dx, int dy);


int
main ()
{
  int dx, dy;
  int x = 4;
  int y = 2;
  int c = 1;
  int a[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 1, -1, 0, 0, 0},
                 {0, 0, 0, -1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0}};

  displaymap (a);
  
  a[x][y] = c;
  
  for (dy = -1; dy < 2; dy++){
      for (dx = -1; dx < 2; dx++){
	  reverse (a, c, x + dx, y + dy, dx, dy);
      }
  }
  
  printf ("\n");
  displaymap (a);
  
  return 0;
}

void displaymap (int a[8][8])
{
  int i, j;
  char c[] = "X-0";

  for (j = 0; j < 8; j++){
    for (i = 0; i < 8; i++)
      printf (" %c", c[a[i][j] + 1]);
    printf ("\n");
  }
}

int
reverse (int a[8][8], int c, int x, int y, int dx, int dy)
{
  if (x < 0 || y < 0 || 7 < x || 7 < y)
    return 0;
  else if (a[x][y] == 0)
    return 0;
  else if (a[x][y] == c)
    return c;
  else{
    if (reverse (a, c, x + dx, y + dy, dx, dy) == c){
      a[x][y] = -a[x][y];
      return c;
    }
    else
      return 0;
  }
}
