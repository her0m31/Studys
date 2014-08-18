/* lab_ml.c */
#include <stdio.h>
#include <string.h>

int main()
{
  FILE *fp;
  char sid[26]; 
  char dat[26];
  char num[4];
  int f;   
  int fac; 
  int yea;
  
  printf("ID : %s", sid);
  scanf("%s", sid);
  
  if (strlen(sid) != 10){
    printf("Please enter the ID is 10 characters.\n");
    return 0;
  }
  
  sscanf(sid, "%3d%4d%3s", &fac, &yea, num);
  
  if(fac != 31){
    printf("The software other than a faculty.\n");    
    return 0;
  }
  
  if(yea < 1998){
    printf("Admission year is wrong.\n");
    return 0;
  }

  yea = 'a' + yea % 26;
  
  sprintf(sid, "g0%d%c%s@s.iwate-pu.ac.jp", fac, yea, num);  
  
  fp = fopen("lab_ml.dat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file : lab_ml.dat\n");
    return -1;
  }
  
  while ( fgets(dat, sizeof(dat), fp) != NULL){
    if (strcmp(sid, dat) == 0){
      printf("%s\n", sid);
      printf("Belongs.\n");
      fclose(fp);
      return 0;
    }
  } 
  fclose(fp);
  
  printf("%s\n", sid);
  printf("Not belongs.\n");
  
  return 0;
}
