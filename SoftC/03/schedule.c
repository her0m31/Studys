/* schedule.c */
#include <stdio.h>
#include <string.h>

struct schedule {
  int month;
  int mday;
  char memo[80];
};

int main()
{
  FILE *fp;		
  struct schedule sch[20];
  char dat[80];
  int l = 0;
  int i = 0; 
  int f = 0;
  int mon;
  char koyomi[][10] = {"January", "February", "March", "April", "May", "June",  
                       "July", "August", "September","October", "November", "December"};
  
  printf("What month do you want to check? [1 - 12] : ");
  scanf("%2d", &mon);
  
  printf("Your Schedule in %s\n", koyomi[mon - 1]);
  
  fp = fopen("schedule.dat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't open file : schedule.dat\n");
    return -1;
  }
  
  for(f = 0; fgets(dat, 79, fp) != NULL; f++){
    if(dat[strlen(dat) - 1] == '\n')
      dat[strlen(dat) - 1] = '\0';
    
    sscanf(dat, "%3d%3d", &sch[f].month, &sch[f].mday);
    
    strcpy(sch[f].memo, dat + 6);
    
  }
  
  fclose(fp);
  
  i = f;
  for(f = 0; f < i; f++){
    if(mon == sch[f].month)      
      printf("%s %2d : %s\n", koyomi[sch[f].month - 1], sch[f].mday, sch[f].memo);  
  }
  
  return 0;
}
