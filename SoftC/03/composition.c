/* composition.c */
#include <stdio.h>

int main()
{
  FILE *fp;
  int cha = 0, wor = 0, sen = 0, lin = 0, e = 0, f = 0; 
  
  fp = fopen("composition.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file: composition.txt\n");
    return -1;
  }
  
  while ((e = getc(fp)) != EOF){
    if (e == '\n')
      lin++;
    
    if (e == '.')
      sen++;
    
    if(e != ',' && e != '.' && e != '\n' && e != ' ')
      cha++;
    
    if( (f != ',' && f != '.' && f != '\n' && f != ' ') && 
        (e == ',' || e == '.' || e == '\n' || e == ' ') )
      wor++;    
    
    f = e;
  }

  fclose(fp);  
  
  if (f == '\n')
    lin--;
  
  printf("Characters: %d.\n", cha);
  printf("Sentences : %d.\n", sen);
  printf("Words     : %d.\n", wor);
  printf("Lines     : %d.\n", lin);
  
  return 0;
}
