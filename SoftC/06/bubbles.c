/* bubbles.c */

void bubbles(int n[], int num)
{
  int temp;
  int i,j;
  
  for(i = 0; i < num - 2; i++){
    for(j = num - 1; i < j; j--){
      if(n[j - 1] > n[j]){
        temp     = n[j];
        n[j]     = n[j -1];
        n[j - 1] = temp;
      }
    }
  }
}
