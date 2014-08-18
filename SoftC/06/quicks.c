/* quicks.c */

void quicks(int n[], int start, int end)
{
  int temp;
  int pivo;
  int i;
  int j;
  
  i = start;
  j = end;
  
  /* �ԥܥåȤη��� */
  pivo = n[(start + end) / 2];
  
  while(i < j){
    
    /* ��������������Ǥ�õ�� */
    while(n[i] < pivo)
      i++;
    
    /* ��������������Ǥ�õ�� */
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
  /* �������˥����ȤǤ������Ǥ�����кƵ� */ 
  if(start <  i-1)
    quicks(n, start, i-1);
  /* �������˥����ȤǤ������Ǥ�����кƵ� */  
  if(i < end) 
    quicks(n, i, end); 
}
