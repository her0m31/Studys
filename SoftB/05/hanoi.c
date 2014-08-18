/* hanoi.c */
#include <stdio.h>

int hanoi(int n, int from, int to);


int main()
{
  int n, from, to;		                     

  printf("How Many Disk? : ");	                   
  scanf("%d", &n);

  printf("From Where? [1-3] : ");                   
  scanf("%d", &from);

  printf("To where? [1-3] : ");	                  
  scanf("%d", &to);

 
  if (from == to)
      return printf("Have the same start and finish\n");
  else 
    hanoi(n, from, to);

    return 0;	                    
}


hanoi(int n, int from, int to)	       /*�ϥΥ��ؿ�*/
{
  if (n > 1)		  
    hanoi(n - 1, from, 6 - (from + to));    /*����n�ξ��n-1��α��פ���3����˰�ư*/

  printf("Move disk %d from pole %d to pole %d\n", n, from, to);/*����n����Ū�����*/
    
  if (n > 1)  
    hanoi(n - 1, 6 - (from + to), to); /*��3�����n-1��α��פ���Ū�����*/
}
