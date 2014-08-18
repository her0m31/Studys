/* composition_2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 100

int main()
{
  FILE *fp;
  int wor = 0;
  int wor2 = 0;
  int i, f;
  int cha = 0; 
  char *words[MAXWORDS];
  char txt[15];
  
  fp = fopen("intro.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file: intro.txt\n");
    return -1;
  }
  
  i = 0;
  while ((wor =  getc(fp)) != EOF) {  
    if(wor != ',' && wor != '.' && wor != '\n' && wor != ' ') {
      txt[cha] = wor;
      cha++;
    }
    
    if((wor2 != ',' && wor2 != '.' && wor2 != '\n' && wor2 != ' ') 
       && (wor == '\n' || wor == ' ' || wor == '.' || wor == ',')) {
      txt[cha] = '\0';
      for (f = 0; f < i; f++){
        if (strcmp(words[f], txt) == 0){
          cha = 0;
          break;
        }
      }
      
      if(f == i) { 
        words[i] = (char *)malloc(sizeof(char) * (cha + 1));
        strcpy(words[i], txt);
        i++;
        cha = 0;
      }
    }
    wor2 = wor;
  }
  
  fclose(fp);
  
  f = i;
  for (i = 0; i < f; i++){
    printf("%s\n", words[i]);
    free((void *)words[i]);
  }
  
  return 0;
}
