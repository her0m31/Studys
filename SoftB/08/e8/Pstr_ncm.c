/* Pstr_ncm.c */
#include <stdio.h>

int str_ncmp(char *src1, char *src2, int n);

int main()
{
  int n;
  char str1[80];
  char str2[80];

  printf("Input a string 1: ");
  scanf("%s", str1);

  printf("Input a string 2: ");
  scanf("%s", str2);

  printf("Number of comparison?: ");
  scanf("%d", &n);

  if (str_ncmp(str1, str2, n) == 1){
    printf(" Something different\n" );
  }
  else{
    printf(" Same\n" );
  }

  return 0;
}

int str_ncmp(char *src1, char *src2, int n)
{
  int i;
  
  for (i = 0; i != n; i++){
    if (*src1++ != *src2++){
      return 1;
    }
  }
  return 0;
}
