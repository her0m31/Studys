/* eria.c */
#include <stdio.h>

float max(float a, float b, float c);
float min(float a, float b, float c);
float absolute(float a);
float rectangle_area(float px1, float px2, float px3, float py1, float py2, float py3);
float triangle_area(float xa, float xb, float ya, float yb);

int main()
{
  float x1, x2, x3;
  float y1, y2, y3;
  float ans;

  /* P1 */
  scanf("%f", &x1);
  scanf("%f", &y1);
  
  /* P2 */
  scanf("%f", &x2);
  scanf("%f", &y2);
  
  /* P3 */
  scanf("%f", &x3);
  scanf("%f", &y3);
  
  ans = rectangle_area(x1, x2, x3, y1, y2, y3) - triangle_area(x1, x2, y1, y2)
                - triangle_area(x2, x3, y2, y3) - triangle_area(x3, x1, y3, y1);
  
  printf("S = %f\n", ans);
  
  return 0; 
}

float triangle_area(float xa, float xb, float ya, float yb)
{ 
  return (absolute(xa - xb) * absolute(ya - yb)) / 2.0;
}

float rectangle_area(float px1, float px2, float px3, float py1, float py2, float py3)
{
  float x_max, x_min, y_max, y_min;
  
  x_max = max(px1, px2, px3);
  x_min = min(px1, px2, px3);
  y_max = max(py1, py2, py3);
  y_min = min(py1, py2, py3);
  
  return (x_max - x_min) * (y_max - y_min);
}

float max(float a, float b, float c)
{
  float max;
  if (a < b)
    max = b;
  else 
    max = a;
  
  if (max < c)
    return c;
  else 
    return max;
}

float min(float a, float b, float c)
{
  float min;
  if (a < b)
    min = a;
  else 
    min = b;
  
  if (min < c)
    return min;
  else 
    return c;
}

float absolute(float a)
{
  if(a < 0.0)
    return -a;
  else
    return  a;
}
