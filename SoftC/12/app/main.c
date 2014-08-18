/* main.c */
#include "adrb.h"

int main()
{
  struct tree **root;
  char chose[MAXLEN];
  int item_num;
  int i;

  *root = make_tree(item_num);
  if(*root != NULL) {
    if( strcmp( (*root)->value->name, "ZZZZ") == 0 && strcmp( (*root)->value->posc, "ZZZZ") == 0  )
      return -1;
  }

  greet();

  i = 0;
  while(i != 1) {
    printf("履歴表示\n");
    print_history(*root, 0);
    printf("\n機能一覧を表示します。番号を入力してください。\n");
    printf("0: 新規住所録の登録\n1: 既存住所録の検索\n2: 既存住所録の修正\n3: 既存住所録の削除\n");
    printf("4: 一覧表示\n5: 終了 \n");
    printf("> ");

    if( scanf("%s", chose) == EOF ) {
      printf("入力エラーです!\n");
      continue;
    };
    if(strlen(chose) > 1) {
      printf("入力エラーです!\n");
      continue;
    }
    switch(chose[0]) {
    case '0':
      add_adrb(root, item_num); 
      break;
    case '1':
      reference_adrb(root);
      break;
    case '2':
      fix_adrb(root);
      break;
    case '3':
      delete_adrb(root);
      break;
    case '4':
      list_adrb(root);
      break;
    case '5':
      i = 1;
      break;
    default:
      printf("入力エラーです!\n");
      break;
    }
  }

  goodbye();

  return 0;
}

void greet(void)
{
  time_t timer;
  struct tm *t_st;
  
  time(&timer); 
  t_st = localtime(&timer); 
  
  if(  3 <= t_st->tm_hour && t_st->tm_hour < 10 )
    printf("おはようございます！\n");
  if( 10 <= t_st->tm_hour && t_st->tm_hour < 18 )
    printf("こんにちは！\n");
  if( 18 <= t_st->tm_hour )
    printf("こんばんわ！\n");
  
  printf("今日は%d月%2d日 ", t_st->tm_mon+1, t_st->tm_mday );
  switch(t_st->tm_wday) {
  case 0:
    printf("日曜日 ");
    break;
  case 1:
    printf("月曜日 ");
    break;
  case 2:
    printf("火曜日 ");
    break;
  case 3:
    printf("水曜日 ");
    break;
  case 4:
    printf("木曜日 ");
      break;
  case 5:
    printf("金曜日 ");
      break;
  case 6:
    printf("土曜日 ");
      break;
  }  
  printf("時刻は%2d時%2d分です！\n\n", t_st->tm_hour, t_st->tm_min);
}

void goodbye(void)
{
  time_t timer;
  struct tm *t_st;
  
  time(&timer); 
  t_st = localtime(&timer);
  if(  3 <= t_st->tm_hour && t_st->tm_hour < 10 )
    printf("\n時刻は%2d時%2d分になります。よい一日を！\n", t_st->tm_hour, t_st->tm_min);
  if( 10 <= t_st->tm_hour && t_st->tm_hour < 18 )
    printf("\n時刻は%2d時%2d分になります。よい一日を！\n", t_st->tm_hour, t_st->tm_min);
  if( 18 <= t_st->tm_hour  )
    printf("\n時刻は%2d時%2d分になります。今日一日おつかれさまでした！\n", t_st->tm_hour, t_st->tm_min);

  printf("終了します…\n");
}
