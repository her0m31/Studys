/* str_con.c */
#include <stdio.h>

void str_connect(char dst[], char src1[], char src2[]);

int main()
{
  char str1[80];
  char str2[80];
  char dst[160];

  printf("Input a string 1: ");
  scanf("%s", str1);
  
  printf("Input a string 2: ");
  scanf("%s", str2);

  str_connect(dst, str1, str2);
  
  printf("String concatenation: %s\n", dst);
  
  return 0;
}

void str_connect(char dst[], char src1[], char src2[])
{
  int i, n;

  i = 0;
  n = 0;
  while (src1[n] != '\0'){
      dst[i++] = src1[n++];
   }

  n = 0;
  while (src2[n] != '\0'){
      dst[i++] = src2[n++];
  }

  dst[i] = '\0';
}
