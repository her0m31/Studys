/* itoa.c */
#include <stdio.h>

void itoa(int dst, char *src);

int main()
{
  int n;
  char str[80];

  printf("Input a number: ");
  scanf("%d", &n);

  itoa(n, str);
  
  printf("string: %s\n", str);

  return 0;
}

void itoa(int dst, char *src)
{
  char *str1 = src;
  char *str2 = '\0';
  char exc;
  int mod;
  int udst;
  
  if(dst < 0){
    udst = -dst;
    *str1 = '-';
    ++str1;
  }else{
    udst = dst;
  }
  
  str2 = str1;
  
  do{
    mod = (udst % 10) + '0';
    *str2 = mod;
    udst /= 10;
    str2++;
  }while(udst != 0);

  *str2 = '\0';

  while( str1 < --str2 ){
    exc  = *str1;
    *str1 = *str2;
    *str2 = exc;
    ++str1;
  }
}
