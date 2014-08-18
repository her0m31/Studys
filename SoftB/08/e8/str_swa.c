/* str_awa.c */
#include <stdio.h>

void str_swap(char *ds, char *sr);
void str_copy(char *dst, char *src);

int main()
{
  char str1[80], str2[80];
  
  printf("Input a string1: ");
  scanf("%s", str1);

  printf("Input a string2: ");
  scanf("%s", str2);

  str_swap(str1, str2);

  printf("\tstring1: %s\n", str1);

  printf("\tstring2: %s\n", str2);

  return 0;
}


void str_swap(char *ds, char *sr)
{
  char ch[80];
  
  str_copy(ch, sr);
  str_copy(sr, ds);
  str_copy(ds, ch);
}

void str_copy(char *dst, char *src)
{ 
  while (*src != '\0'){
    *dst = *src;
    src++;
    dst++;
  }
  *dst = '\0';
}
