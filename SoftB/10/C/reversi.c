/* reversi.c */
#include <stdio.h>

void displaymap(int a[8][8]);
int reverse(int a[8][8], int c, int x, int y, int dx, int dy, int *g);

int main()
{
  int x, y, i, dx, dy;
  int c = 1;
  int q[] = {2, 0, 2};
  int g = 0;
  char d[] = "X-0";
  int a[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 1, -1, 0, 0, 0},
                 {0, 0, 0, -1, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0}};


  for(i = 0; i < 60; i++){
    displaymap(a);
    printf("turn: %d (O:%d, X:%d)\n", i, q[-c + 1], q[c + 1]);
    printf("\n");  

    printf("%c x y >", d[c + 1]);
    scanf("%d" "%d", &x, &y);

    if (x < 0 || y < 0 || 7 < x || 7 < y){
      printf("Can't put it here\n");
      i--;
      continue;
    }

    if (a[x][y] != 0){
      printf("Can't put it here\n");
      i--;
      continue;
    }

    g = 0;
    for (dy = -1; dy < 2; dy++){
      for (dx = -1; dx < 2; dx++)
        reverse(a, c, x + dx, y + dy, dx, dy, &g);
    }
    
    if (g == 0){
      printf("Can't put it here\n");
      i--;
      continue;
    }

    a[x][y] = c;

    q[c + 1] = q[c + 1] + g + 1;
    q[-c + 1]  = q[-c + 1] - g;

    if (q[c + 1] == 0 || q[-c + 1] == 0){
      displaymap(a);
      break;
    }
    printf("\n");
    c = -c;
  }
  
  if (q[c + 1] < q[-c + 1])
    printf("WIN : X\n");
  else if (q[-c + 1] < q[c + 1])
    printf("WIN : O\n");

  return 0;
}

void displaymap(int a[8][8])
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

int reverse(int a[8][8], int c, int x, int y, int dx, int dy, int *g)
{
  if (x < 0 || y < 0 || 7 < x || 7 < y)
    return 0;
  else if (a[x][y] == 0)
    return 0;
  else if (a[x][y] == c)
    return c;
  else{
    if (reverse(a, c, x + dx, y + dy, dx, dy, g) == c){
      a[x][y] =  -a[x][y];
      *g += 1;
      return c;
    }
    else
      return 0;
  }
}
