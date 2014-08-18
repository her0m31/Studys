/* list_adrb.c */
#include "adrb.h"

void list_adrb(struct tree **root)
{
  char chose[MAXLEN];
  int flag_j;

  flag_j = 0;
  while(flag_j != 1) {
    printf("住所録一覧を表示します。番号を入力してください。\n");
    printf("0: 一覧表示\t1: 昇順一覧表示\t2: 降順一覧表示\n");
    printf("> ");
    if( scanf("%s", chose) == EOF ) {
      printf("入力エラーです!\n");
      return;
    };
    if(strlen(chose) != 1) {
      printf("入力エラーです!\n");
      return;
    }
    switch(chose[0]) {
    case '0':
      flag_j = 1;
      break;
    case '1':
      flag_j = 1;
      break;
    case '2':
      flag_j = 1;
      break; 
    default:
      printf("入力エラーです!\n");
      break;
    }
  }
  
  switch(chose[0]) {
  case '0':
    printf("一覧表示\n");
    print_adrb(*root);
    break;
  case '1':
    printf("昇順一覧表示\n");
    up_print(*root);
    break;
  case '2': 
    printf("降順一覧表示\n");
    down_print(*root);
    break;
  default:
    printf("入力エラーです!\n");
    break;
  }
  printf("\n");
  
  return;
}
