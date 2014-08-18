/* hello_to.c */
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, j;
  int index = 0;
  static char name[100];

  if (argc == 1){
    printf("Hello, everyone.\n");
    return 0;
  }

  for (i = 1; i < argc; i++) {
    for (j = 0; argv[i][j] != '\0'; j++) {
      if (index > 98){
        printf("文字列が長すぎます\n");
        return 0;
      }
      name[index++] = argv[i][j];
    }
    if (i == argc - 1)
      name[index]   = '\0';
    else
      name[index++] = ' ';
  }
  printf("Hello, %s.\n", name);
  
  return 0;
}
