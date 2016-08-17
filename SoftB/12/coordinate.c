/* coordinate.c */
#include <stdio.h>

struct point{
  int x;
  int y;
};

struct point define_point(int x, int y);

void put_point(struct point r);

int main()
{
  int i, j;
  struct point p1;
  struct point p2;
  struct point p3;
 
  p1 = define_point(1, 2);
  p2 = define_point(5, 4);
  p3 = define_point(-2, 3);
    
  printf("p1 = ");
  put_point(p1);
  printf("\n");
 
  printf("p2 = ");
  put_point(p2);
  printf("\n");
 
  printf("p3 = ");
  put_point(p3);
  printf("\n");

  return 0; 
}

struct point define_point(int x, int y)
{
  struct point r;

  r.x = x;
  r.y = y;

  return r;
}

void put_point(struct point r)
{
  printf("(%d, %d)", r.x, r.y);
}
