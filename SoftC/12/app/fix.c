/* fix.c */
#include "adrb.h"

void fix_adrb(struct tree **root)
{
  FILE *fp;
  char chose[MAXLEN];
  char items[2][MAXLEN];
  struct adrb *data[MAXLEN];
  struct tree **view;
  struct tree *temp;
  int loop_main, loop_sub, flag_x;
  int i, j, num;
  
  data[0] = NULL;
  loop_main = 0;
  while( loop_main != 1 ) {
    
    loop_sub = 0;
    while(loop_sub != 1) {
      loop_sub = 1;
      printf("修正する住所録を検索します…\n");
      printf("修正したい住所録の「氏名」を入力してください。終了するには「Ctrlキーを押しながらDを押してください」。\n");
      printf("> ");
      if( scanf("%s", items[0] ) == EOF ) {
        printf("住所録の修正を終了します…\n\n");
        return;
      }
    }
    
    i = 0;
    print_match(*root, data, items[0], 0, &i);

    if( data[0] == NULL ) {
      printf("一致する住所録はありませんでした…\n\n"); 
      continue;
    } else {
      printf("一致する住所録があります…\n");
      for(j = 0; j < i; j++)
        printf("・%2d: %s\t%s\t%s\t%s\t%s\n", j+1, data[j]->name, data[j]->posc, data[j]->adre, data[j]->tell, data[j]->mail); 
    }
    
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("\nどの住所録を修正しますか?左の番号を入力してください。修正せずに終了するには「Ctrlキーを押しながらDを押してください」。\n"); 
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("住所録の修正を終了します…\n\n");
        return;
      };
      if(strlen(chose) != 1) {
        printf("入力エラーです!\n");
        continue;
      }
      if( atoi(chose) < 1 || i < atoi(chose) ) {
        printf("入力エラーです!\n");
        continue;
      }
      printf("次の住所録が選択されました。\n");
      printf("・%2d: %s\t%s\t%s\t%s\t%s\n", atoi(chose), data[atoi(chose)-1]->name, data[atoi(chose)-1]->posc, data[atoi(chose)-1]->adre, data[atoi(chose)-1]->tell, data[atoi(chose)-1]->mail); 
      num = atoi(chose) - 1;
      loop_sub = 1;
    }
    
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("\nどの項目を修正しますか?番号を入力してください。修正せずに終了するには5を入力してください。\n"); 
      printf("0: 氏名\n1: 郵便番号\n2: 住所\n3: 電話番号\n4: メールアドレス\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("入力エラーです!\n");
        continue;
      };
      if(strlen(chose) != 1) {
        printf("入力エラーです!\n");
        continue;
      }
      switch(chose[0]) {
      case '0':
        loop_sub = 1;
        break;
      case '1':
        loop_sub = 1;
        break;
      case '2':
        loop_sub = 1;
        break;
      case '3':
        loop_sub = 1;
        break;
      case '4':
        loop_sub = 1;
        break;
      case '5': 
        printf("住所録の修正を終了します…\n\n");
        return;
      default:
        printf("入力エラーです!\n");
        break;
      }  
    }
    
    loop_sub = 0;
    while(loop_sub != 1) {
      loop_sub = 1;
      printf("修正してください。\n");
      printf("> ");
      if( scanf("%s", items[1]) == EOF ) {
        printf("入力エラーです!\n\n");
        loop_sub = 0;
        continue;
      }
    }
    
    fix_item( data[num], items[1], atoi(chose) );
    printf("修正完了\n");
    print_adrb(*root);
    printf("\n");
  
    fp = fopen( "adrb.dat", "w");
    if( fp == NULL ) {
      return;
    }
    save_file( fp, root );
    fclose(fp); 
  
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("住所録の修正を続けますか？番号を入力してください！\n");
      printf("0: Yes\n1: No\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("入力エラーです!\n");
        continue;
      };
      if( strlen(chose) != 1) {
        printf("入力エラーです。\n");
        continue;
      }
      switch(chose[0]) {
      case '0':
        loop_sub = 1;
        break;
      case '1':
        loop_sub = loop_main = 1;
        break;
      default:
        printf("入力エラーです!\n");
        break;
      }
    }
    
  }
  printf("住所録の修正を終了します…\n\n");
}


void fix_item(struct adrb *data, char *items, int item_num)
{   
  if(item_num == 0) {  
    data->name = (char *)malloc(strlen(items) + 1);
    strcpy( data->name, items);
  }
  if(item_num == 1) {
    data->posc = (char *)malloc(strlen(items) + 1);
    strcpy( data->posc, items); 
  }
  if(item_num == 2) {
    data->adre = (char *)malloc(strlen(items) + 1);
    strcpy( data->adre, items);
  }
  if(item_num == 3) {
    data->tell = (char *)malloc(strlen(items) + 1);
    strcpy( data->tell, items);
  }
  if(item_num == 4) {
    data->mail = (char *)malloc(strlen(items) + 1);
    strcpy( data->mail, items);
  }
}
