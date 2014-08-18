/* malloc.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 7
#define N 15

int main(int argc, char *argv[])
{
  FILE *fp;
  char *line[MAXLINES];
  char txt[N];
  int i;
  int n;
  
  if (argc == 1){
    fprintf(stderr, "Input argument.\n");
    return -1;
  }
  
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Cannot open file: %s\n", argv[1]);
    return -1;
  }
  
  for (i = 0; (fgets(txt, N - 1, fp) != NULL); i++){
    
    line[i] = (char *)malloc(sizeof(char) * (strlen(txt) + 1));
    if (line[i] == NULL) {
      fprintf(stderr, "error!\n");
      return -1;
    }
    
    strcpy(line[i], txt);
    
    if( i == MAXLINES)
      break;
  }  
  
  n = i;
  for(i = 0; i < n; i++){
    printf("%s", line[i]);
    free((void *)line[i]);
  }
  
  return 0;
}
