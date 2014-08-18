/* str_swa.c */
#include <stdio.h>

void str_swap(char *dst, char *src);

int main()
{
  char str1[80], str2[80];
  
  printf("Input a string1: ");
  scanf("%s", str1);

  printf("Input a string2: ");
  scanf("%s", str2);

  str_swap(str1, str2);

  printf("string1: %s\n", str1);

  printf("string2: %s\n", str2);

  return 0;
}


void str_swap(char *dst, char *src)
{
  char swap[80];
  int i;

  for (i = 0; *(dst + i) != '\0'; i++){
    swap[i] = *(dst + i);
  }
  swap[i] = '\0';
  
  for (i = 0; *(src + i) != '\0'; i++){
    *(dst + i) = *(src + i);
  }
  *(dst + i) = '\0';
  
  for (i = 0; swap[i] != '\0'; i++){
    *(src + i) = swap[i];
  }
  *(src  + i)= '\0';
}
