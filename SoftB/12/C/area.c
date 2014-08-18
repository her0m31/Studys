/* area.c */
#include <stdio.h>

#define N 3

struct point{
  float x;
  float y;
};

struct point define_point(float x, float y);

float triangle_area(struct point p1, struct point p2, struct point p3);

int main()
{
  struct point p1;
  struct point p2;
  struct point p3;
 
  p1 = define_point(1.0, 2.0);
  p2 = define_point(5.0, 3.0);
  p3 = define_point(-2.0, 3.0);

  printf("area = %f cm2\n", triangle_area(p1, p2, p3));    
 
  return 0; 
}

struct point define_point(float x, float y)
{
  struct point p;

  p.x = x;
  p.y = y;

  return p;
}

float triangle_area(struct point p1, struct point p2, struct point p3)
{
  return ((p2.x - p1.x)*(p3.y - p1.y) 
          - (p3.x - p1.x)*(p2.y - p1.y)) / 2.0;
}
