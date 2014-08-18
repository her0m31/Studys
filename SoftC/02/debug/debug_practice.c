/* debug_practice.c */
#include <stdio.h>

void string_cat(char *str, char *append)
{
  while (*str != '\0') {
    str++;
  }
  while (*append != '\0') {
    *str = *append;
    str++;
    append++;
  }
  *str = '\0';
}

int main()
{
  char result[20] = "";

  string_cat(result, "strawberry");
  string_cat(result, " ");
  string_cat(result, "parfait");
  printf("%s\n", result);

  return 0;
}
