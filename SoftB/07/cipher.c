/* cipher.c */
#include <stdio.h>

 int main()
{
  int i, n;
  char a[] = "bzdrzq";
  char b[100];

  for(i = 0; a[i] != '\0'; i++){
    n = (a[i] - 'a' + 1)%26;
    b[i] = 'a' + n;
  }
  b[i] = '\0';

  printf("a: %s\n", a);
  printf("b: %s\n", b);
  
  return 0;
}
