/* push_pop.c */
#include "list1.h"
#define STACKSIZE 15

float stack[STACKSIZE];
int sp = 0;

int push(float data){
  if (STACKSIZE <= sp)
    return 0;
  else{
    stack[sp++] = data; 
    return 1; 
  }
}

int pop(float *data)
{
  if (sp <= 0)
    return 0;
  else{
    *data = stack[--sp];
    return 1;
  }
}
