/* seiza.c */
#include <stdio.h>

int cale(int *month, int *day);
void seiza(int month, int day);

int main()
{
  
  int tuki,niti;
  printf("Enter your birthday[mm/dd] : ");
  scanf("%d/%d", &tuki, &niti);
  
  if( cale(&tuki, &niti) == 0){
    seiza(tuki, niti);
  }
  return 0;
}

int cale(int *month, int *day)
{
  int d[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  char *mon[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", 
"Dec"};
  
  if(1 <= *month && *month <= 12 && 1 <= *day && *day <= d[*month - 1]){
    printf("your birthday is %s.%d.\n", mon[*month - 1], *day);
    return 0;
  }else{
    printf("Error : strange data was enterd.\n");
    return -1;
  }
}

void seiza(int month, int day)
{
  char *con[] = {"CAPRICORN", "AQUARIUS", "PICES", "ARIES", "TAURUS","GEMINI", "CANCER", "LEO",
 "VIRGO", "LIBRA", "ACORPIO","SAGITTARIUS"};
  
  int x[] = {19, 18, 20, 19, 20, 21, 22, 22, 22, 23,21, 21};
  
  if( x[month - 1] > day)
    month --;
  else if(month == 12)
    month = 0;
  
  printf("Therefore,your constellation is the %s.\n", con[month]);
}
