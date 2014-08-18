/* tax.c */
#include <stdio.h>

#ifndef Tax
#define Tax 0.05
#endif
#define include_tax(x) ((x) * (1.00 + Tax))

int main()
{
  int price;

  printf("Input Price\n");
  scanf("%d", &price);

  printf("Price including tax %d\n", (int)include_tax(price));

  return 0;
}
