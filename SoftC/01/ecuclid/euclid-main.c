/* euclid.c */
#include <stdio.h>
#include <stdlib.h>
#include "euclid.h"

int main(int argc, char *argv[])
{
  int x, y;
  int r, t;
  
  if (argc == 3){
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    r = gcd(x, y);
    t = lcm(x, y);
  }
  else{
    printf("Input a number: X Y :");
    scanf("%d %d", &x, &y); 
    r = gcd(x, y);
    t = lcm(x, y);
  }
  
  printf("ºÇÂç¸øÌó¿ô = %d, ºÇ¾®¸øÇÜ¿ô = %d\n", r, t);
  
  return 0;
}
