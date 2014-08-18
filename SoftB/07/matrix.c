/* matrix.c */
# include <stdio.h>

int main()
{
  int i, j, k;
  float a[3][3], x[3], ax[3];

  for (i = 0; i < 3; i++){
    for (j = 0; j < 3; j++){
      scanf("%f", &a[i][j]);
    }
  }

  for (i = 0; i < 3; i++){
    scanf("%f", &x[i]);
  }
     
  for (i = 0; i < 3; i++){
    ax[i] = 0.0;
    for (k = 0; k < 3; k++){
      ax[i] += (a[i][k] * x[k]);
    }
  }

  for (i = 0; i < 3; i++){
    printf("%.2f\n", ax[i]);
  }
  
  return 0;
}
