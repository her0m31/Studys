/* union.c */
#include <stdio.h>

#define N 100

union op_1 {
  float a[N][N];
  float x[N][N];
};

union op_2 {
  float b[N][N];
  float y[N][N];
};

int main()
{
  int n;
  int i, j, k;
  float c[N][N];
  float z[N][N];
  
  union op_1 mat1;
  union op_2 mat2;
  
  /* ������������ */
  scanf("%d", &n);

  /* ����A */ 
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%f", &mat1.a[i][j]);
    }
  }
  
  /* ����B */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%f", &mat2.b[i][j]);
    }
  }
  
  /* ��C */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = mat1.a[i][j] + mat2.b[i][j];
    }
  }
  
  /* ����X */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%f", &mat1.x[i][j]);
    }
  }
  
  /* ����Y */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%f", &mat2.y[i][j]);
    }
  }
  
  /* ��Z */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      z[i][j] = 0;
      for (k = 0; k < n; k++) {
        z[i][j] += mat1.x[i][k] * mat2.y[k][j];
      }
    }
  }
  
  printf("A + B = C\n");
  printf("��C\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f\t", c[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  printf("X * Y = Z\n");
  printf("��Z\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f\t", z[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
