/* avedis.c */
#include <stdio.h>

int main()
{
  int i;
  float ave, dis, sum = 0.0, data[10];

  for (i = 0; i < 10; i++){
    scanf("%f", &data[i]);
    sum += data[i];
  }

  ave = sum / 10.0;
  printf("Average = %.2f\n", ave);

  for (i =0; i < 10; i++){
    dis += (data[i] - ave) * (data[i] - ave);
  }

  dis = dis / 10;
  printf("Distributed = %.2f\n", dis);

  return 0;
}
