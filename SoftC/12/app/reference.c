/* reference.c */
#include "adrb.h"

void reference_adrb(struct tree **root)
{ 
  FILE *fp;
  char chose[MAXLEN];
  char items[MAXLEN];
  struct adrb *data[MAXLEN];
  int flag_i, flag_j;
  int num;
  int i, j;
  
  flag_i = 0;
  flag_j = 0;
  while(flag_i != 1) {
    flag_j = 0;
    while(flag_j != 1) {
      printf("どの項目で検索しますか?番号を入力してください。また、終了するには5を入力してください\n");
      printf("0: 氏名\n1: 郵便番号\n2: 住所\n3: 電話番号\n4: メールアドレス\n");
      printf("> ");
      if( scanf("%s", chose) == EOF) {
        printf("\n入力エラーです!\n");
        continue;
      };
      if( strlen(chose) != 1 ) {
        printf("入力エラーです。\n");
        continue;
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
      case '3':
        flag_j = 1;
        break;
      case '4':
        flag_j = 1;
        break;
      case '5':
        flag_i = flag_j = 1;
        break;
      default:
        printf("入力エラーです!\n");
        break;
      }
    }
    if(flag_i == 1)
      continue;
    
    num = atoi(chose);
    *root = make_tree( num );
    
    flag_j = 0;
    while(flag_j != 1) {
      flag_j = 1;
      printf("検索ワードを入力してください。\n");
      printf("> ");
      if( scanf("%s", items) == EOF) {
        printf("\n入力エラーです!\n");
        flag_j = 0;
        continue;
      } 
    }

    i = 0;
    data[0] = NULL;
    print_match( *root, data, items, num, &i); 
    
    if( data[0] == NULL ) {
      fprintf(stderr, "住所録が見付かりませんでした...(検索ワード: %s)\n\n", items);
      continue;
    }else {
      printf("一致した住所録(検索ワード: %s)\n", items);
      for(j = 0; j < i; j++)
        printf("・%2d: %s\t%s\t%s\t%s\t%s\n", j+1, data[j]->name, data[j]->posc, data[j]->adre, data[j]->tell, data[j]->mail); 
      printf("\n");
    }
  }
  
  fp = fopen( "adrb.dat", "w");
  if( fp == NULL ) {
    fprintf(stderr, "Cannot open file: adrb.dat\n");
    return;
  }
  save_file( fp, root );
  fclose(fp);
  
  printf("住所録の参照を終了します…\n\n");
}
