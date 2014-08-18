/*medal.c*/
#include <stdio.h>

double price(double price, double sg, double r, double t);
double sg(double sg, double r, double t);
double volume(double r, double t);

int main()
{
  double r, t, a;
  
  printf("Input the radius ");
  scanf("%lf", &r);

  printf("Input the thickness ");
  scanf("%lf", &t);
  
  printf("gold   %f\n", price(1324.0, 19.3, r, t));

  printf("silver %f\n", price(17.76, 10.5, r, t));

  printf("copper %f\n", price(0.2211, 8.93, r, t));

  
  return 0;
}

double price(double price, double g, double r, double t)
{
  return (price * sg(g, r, t));
}

double sg(double sg, double r, double t)
{ 
  return (sg * volume(r, t));
}

double volume(double r, double t)
{
  double pi = 3.14159265358979323846;
  
  return pi * (r * r) * t;
}
