#include <stdio.h>


main() {
  int i, count;
  int yeah1;
  int yeah2;

  scanf("%d", &yeah1 );
  scanf("%d", &yeah2 );
 
  count = 0;
  for( i = yeah1; i <= yeah2; i++) {
    if( i % 4 == 0 && i % 100 != 0 || i % 400 == 0 )
      count++;
  }

  printf("%d", count);
}
