/* main1.c */
#include <stdio.h>
#include "sort.h"

#define N 10

int main()
{
  int n[N] = {7, 20, 1, 18, 9, 15, 24, 10, 3, 12};

  bubbles(n, N);

  return 0;
}
