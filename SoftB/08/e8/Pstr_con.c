/* Pstr_con.c */
#include <stdio.h>

void str_connect(char *dst, char *src1, char *src2);

int main()
{
  char str1[80];
  char str2[80];
  char dtr[160];
  
  printf("Input a string 1: ");
  scanf("%s", str1);
  
  printf("Input a string 2: ");
  scanf("%s", str2);
  
  str_connect(dtr, str1, str2);

  printf("String concatenation: %s\n", dtr);
  
  return 0;
}

void str_connect(char *dst, char *src1, char *src2)
{
  
  while (*src1 != '\0'){
    *dst++ = *src1++;
  }
  
  while (*src2 != '\0'){
    *dst++ = *src2++;
  }
  *dst = '\0';
}

