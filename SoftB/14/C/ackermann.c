/* ackermann.c */
#include <stdio.h>

int acker(int m, int n);

int main()
{  
  int m, n;

  printf("A(m, n)\n");

  printf("m = ");
  scanf("%d", &m);
  
  printf("n = ");
  scanf("%d", &n);
  
  printf("A(3, 3) = %d\n", acker(m, n));
    
  return 0;
}

int acker(int m, int n)
{
  if (m == 0) 
    return n + 1;
  else if (n == 0) 
    return acker(m - 1, 1);
  else
    return acker(m - 1, acker(m, n - 1));
}
