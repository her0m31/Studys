/* montecarlo.c */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  int num;
  int n;
  double x, y;
  double pi;
  unsigned int seed;

  if(argc == 1){
    fprintf(stderr, "Input argument.\n");
    return -1;
  }
  
  if(argc > 2){
    fprintf(stderr, "One input argument.\n");    
    return -1;
  }

  num = atoi(argv[1]);
  
  printf("seed = ");
  scanf("%d", &seed);
  
  srand(seed);
  
  n = 0.0;
  for(i = 0; i <= num; i++) {
    x = ((double)rand()) / ((double)RAND_MAX + 1.0);
    y = ((double)rand()) / ((double)RAND_MAX + 1.0);        
    
    if((x * x + y * y) < 1.0) {                     
      n++;                                 
    }
  }
  
  pi = (double)n / (double)num * 4.0;
  
  printf("%f\n", pi);
  
  return 0;
}
