/* euclid.c */
#include "euclid.h"

int gcd(int a, int b)
{ 
  int r;
  
  if(b == 0)
    r = a;
  else
    r = gcd(b, a%b);
  
  return r;
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}
