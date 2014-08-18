/* main2.c */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main()
{
  int i;
  char data[5];
  float l;
  float r;
  
  while((scanf("%s", data)) != EOF){
 // 演算子が入力された場合、スタックから２つの数値を取り出した後に演算を行い結果をスタックに積む
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
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "*") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l * r);
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( strcmp(data, "/") == 0){
      if( pop(&r) != 0 && pop(&l) != 0 )
        push(l / r);
      else{
        fprintf(stderr, "error!\n");
        return -1;
      }
    } else if( atof(data) == 0 ){
      fprintf(stderr, "error!\n");
      return -1;        
    } else{
// 数値が入力された場合、その値をスタックに積む 
      if( push(atof(data)) == 0){
        fprintf(stderr, "error!\n");
        return -1;          
      }
    }
  }
  
  if(pop(&r) != 0){
    if(pop(&r) == 0){
      fprintf(stderr, "error!\n");
      return -1;   
    }
    else
      printf("%.2f\n", r);
  }
  else{
    fprintf(stderr, "error!\n");
    return -1; 
  }  

  return 0;
}
