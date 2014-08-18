/* up_down.c */
#include "adrb.h"

void up_print(struct tree *root)
{
  FILE *fp;
  char chose[MAXLEN];

  printf("どの項目で昇順表示しますか?番号を入力してください\n");
  printf("0: 氏名\n1: 郵便番号\n2: 住所\n3: 電話番号\n4: メールアドレス\n");
  printf("> ");
 
  if( scanf("%s", chose) == EOF ) {
    printf("入力エラーです!code:1\n");
    return;
  };
  if(strlen(chose) > 1) {
    printf("入力エラーです!code:2\n");
    return;
  }
  if( 4 < atoi(chose) || atoi(chose) < 0){
    printf("入力エラーです。\n");
    return;
  }
  
  switch(chose[0]) {
  case '0':
    printf("氏名:昇順一覧表示\n");
    root = make_tree(0);
    print_adrb(root);
    break;
  case '1':
    printf("郵便番号:昇順一覧表示\n");
    root = make_tree(1);
    print_adrb(root);
    break;
  case '2': 
    printf("住所:昇順一覧表示\n");
    root = make_tree(2);
    print_adrb(root);
    break;
  case '3': 
    printf("電話番号:昇順一覧表示\n");
    root = make_tree(3);
    print_adrb(root);
    break;
  case '4': 
    printf("メールアドレス:昇順一覧表示\n");
    root = make_tree(4);
    print_adrb(root);
    break;
  default:
    printf("入力エラーです!code:3\n");
    break;
  }
  root = make_tree(0);

  return;
}


void down_print(struct tree *root)
{
  FILE *fp;
  char chose[MAXLEN];

  printf("どの項目で降順表示しますか?番号を入力してください\n");
  printf("0: 氏名\n1: 郵便番号\n2: 住所\n3: 電話番号\n4: メールアドレス\n");
  printf("> ");
 
  if( scanf("%s", chose) == EOF ) {
    printf("入力エラーです!code:1\n");
    return;
  };
  if(strlen(chose) > 1) {
    printf("入力エラーです!code:2\n");
    return;
  }
  if( 4 < atoi(chose) || atoi(chose) < 0){
    printf("入力エラーです。\n");
    return;
  }
  
  switch(chose[0]) {
  case '0':
    printf("氏名:降順一覧表示\n");
    root = make_rev_tree(0);
    print_adrb(root);
    break;
  case '1':
    printf("郵便番号:降順一覧表示\n");
    root = make_rev_tree(1);
    print_adrb(root);
    break;
  case '2': 
    printf("住所:降順一覧表示\n");
    root = make_rev_tree(2);
    print_adrb(root);
    break;
  case '3': 
    printf("電話番号:降順一覧表示\n");
    root = make_rev_tree(3);
    print_adrb(root);
    break;
  case '4': 
    printf("メールアドレス:降順一覧表示\n");
    root = make_rev_tree(4);
    print_adrb(root);
    break;
  default:
    printf("入力エラーです!code:3\n");
    break;
  }
  
  root = make_tree(0);

  return;
}
