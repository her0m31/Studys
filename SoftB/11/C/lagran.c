/* lagran.c */
#include<stdio.h>

#define N 10

struct sinx {
  double x1;
  double fx;
};

double lagrange(struct sinx *val, int x);

int main()
{
  int i;

  float x = 45.0;

  struct sinx value[N] = {{0.0,  0.000000}, {10.0, 0.173648},
                          {20.0, 0.342020}, {30.0, 0.500000},
                          {40.0, 0.642788}, {50.0, 0.766044},
                          {60.0, 0.866025}, {70.0, 0.939693},
                          {80.0, 0.984807}, {90.0, 1.000000}};

  printf("f(%d¡ë) = %f\n",(int)x, lagrange(value, x));
  
  return 0;
}

double lagrange(struct sinx *val, int x)
{
  int i, j;
  double sum, prod, tem;
  
  sum = 0.000000;
  for (i = 0; i < N; i++) {
    tem = 1.0;
    for (j = 0; j < N; j++){
      if (j != i){
        tem *= (x - val[j].x1) / (val[i].x1 - val[j].x1);
      }
    }
    sum += (val[i].fx) * tem;
  }
  return sum;
}
