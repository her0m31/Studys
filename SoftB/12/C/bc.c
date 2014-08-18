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
  
  printf("n = ");
  scanf("%d", &n);
  printf("\n");
  
  printf("A + B = C\n");
  
  printf("π‘ŒÛA\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("A[%d][%d]= ", i + 1, j + 1);
      scanf("%f", &mat1.a[i][j]);
    }
  }
  
  printf("π‘ŒÛB\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("B[%d][%d]= ", i + 1, j + 1);
      scanf("%f", &mat2.b[i][j]);
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = mat1.a[i][j] + mat2.b[i][j];
    }
  }
  
  printf("œ¬C\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f\t", c[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  printf("X * Y = Z\n");
  
  printf("π‘ŒÛX\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("X[%d][%d]= ", i + 1, j + 1);
      scanf("%f", &mat1.x[i][j]);
    }
  }
  
  printf("π‘ŒÛY\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("Y[%d][%d]= ", i + 1, j + 1);
      scanf("%f", &mat2.y[i][j]);
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      z[i][j] = 0;
      for (k = 0; k < n; k++) {
        z[i][j] += mat1.x[i][k] * mat2.y[k][j];
      }
    }
  }
  
  printf("¿—Z\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%f\t", z[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
