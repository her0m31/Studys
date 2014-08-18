/* matrix.c */
# include <stdio.h>

main()
{
  int i, j, k;
  float a[3][3], x[3][1], ax[3][1];

  for (i = 0; i < 3; i++){
  
    for (j = 0; j < 3; j++){
      scanf("%f", &a[i][j]);
      scanf("%f", &x[j][1]);
    }
    
    ax[i][1] = 0;
    for (k = 0; k < 3; k++){
      ax[i][1] += a[i][k] * x[k][1];
    }
    
    printf("%.2f\n", ax[i][1]);
    
  }
  return 0;
}
