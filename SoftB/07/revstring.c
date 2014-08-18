/* revstring.c */
#include <stdio.h>

int main()
{
  int i, j;
  char a[] = "orange";
  char b[80];

  for (j = 0; a[j] != '\0'; j++);
  
  for (i = 0; a[i] != '\0'; i++){
    b[i] = a[--j];
  }
  b[i] = '\0';

  printf("a: %s\n", a);
  printf("b: %s\n", b);

  return 0;
}
