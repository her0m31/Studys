/* simples.c */

void simples(int n[], int num)
{
  int i, j, k;
  int temp;
  
  for (i = 0; i < num - 1; i++) {
    k = i;
    for (j = i + 1; j < num; j++){
      if (n[k] > n[j]){
        k = j;
      }
    }
    
    temp = n[i];
    n[i] = n[k];
    n[k] = temp;
  }
}
