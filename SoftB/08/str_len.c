/* str_len.c */
#include <stdio.h>

int str_length(char str[]);

int main()
{
  char str[80];

  printf("Input a string: ");
  scanf("%s", str);

  printf("Number of characters: %d\n", str_length(str));

  return 0;
}


int str_length(char str[])
{
  int i;

  for (i = 0; str[i] != '\0'; i++);

  return i;
}
