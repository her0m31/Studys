/* main5.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

int main()
{
  char data[5];
  float l, r;
  
  while((scanf("%s", data)) != EOF){
// �黻�Ҥ����Ϥ��줿��硢�����å����飲�Ĥο��ͤ���Ф�����˱黻��Ԥ���̤򥹥��å����Ѥ�
    if       ( strcmp(data, "+") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l + r);
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "-") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l - r);
      else{
        fprintf(stderr, stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "*") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l * r);
      else{
        fprintf(stderr,  "error!\n");
        return -1;
      }
    } else if( strcmp(data, "/") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l / r);
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "%") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(fmod(l, r));
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "^") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(pow(l, r));
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else{
// ���ͤ����Ϥ��줿��硢�����ͤ򥹥��å����Ѥ� 
      if( push(atof(data)) == 0){
        fprintf(stderr, "error!\n");
        return -1;          
      }
    }
  }

  if(pop(&r) != 0){
    if(pop(&r) == 0){
      fprintf("error!\n");
      return -1;   
    }
    else
      printf("%.2f\n", r);
  }
  else{
    fprintf("error!\n");
    return -1; 
  } 
  
  return 0;
}
