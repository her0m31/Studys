/* quicks.c */

void quicks(int n[], int start, int end)
{
  int temp;
  int pivo;
  int i;
  int j;
  
  i = start;
  j = end;
  
  /* ピボットの決定 */
  pivo = n[(start + end) / 2];
  
  while(i < j){
    
    /* 左方向からの要素の探索 */
    while(n[i] < pivo)
      i++;
    
    /* 右方向からの要素の探索 */
    while(pivo < n[j])
      j--;
    
    if(i < j && n[i] != n[j]){
      temp = n[i];
      n[i] = n[j];
      n[j] = temp;
      i++;
      j--;
    }  
    if(i == j || n[i] == n[j]){
      i++;
      j--;
    }
  } 
  /* 左方向にソートできる要素があれば再帰 */ 
  if(start <  i-1)
    quicks(n, start, i-1);
  /* 右方向にソートできる要素があれば再帰 */  
  if(i < end) 
    quicks(n, i, end); 
}
