#include <stdio.h>

#define NUM_DATA 8

void InsSort(int num[ ], int n) ;
void ShowData(int num[ ], int n);
void main(void);

void InsSort(int num[ ], int n)
{
  int i, j, temp;
  
  for (i = 1; i < n; i++) {     
    temp = num[i];         
    for (j = i; j > 0 && num[j-1] > temp; j--) 
      num[j] = num[j -1];         
    
    num[j] = temp;           
    ShowData(num, NUM_DATA); 
  }
}

void ShowData(int num[ ], int n)
{
  while (n--)
    printf("%d  ", *num++);
  printf("\n");
}

void main(void)
{
  int num[ ] = {3, 7, 1, 5, 4, 2, 6, 0};
  
  printf("    ShowData(num, NUM_DATA);
    printf("\n");

    InsSort(num, NUM_DATA);
    printf("\n");

    printf("    ShowData(num, NUM_DATA);
         printf("\n");
         }
