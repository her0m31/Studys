#include "function.h"

void insert_cell_file(struct cell_c **p, struct cell_f **pointer)
{
  char main_title[MAXLEN], sub_title[MAXLEN], date[MAXLEN], path[MAXLEN], category[MAXLEN];
  int s_n;

  printf("新しいファイルを登録します。\n");

  printf("ファイルのタイトル名を入力してください。(例: softC)\n>");
  scanf("%s", main_title);

  printf("ファイルの副タイトル名を入力してください。(例: メインルーチン)\n>");
  scanf("%s", sub_title);

  printf("ファイルの作成日付を入力してください。(例: 10/18/2010)\n>");
  scanf("%s", date);

  printf("ファイルのパス名を入力してください。(例: /g031h105/softC)\n>");
  scanf("%s", path);

  printf("ファイルの分類番号を入力してください。(例: 3)\n>");
  scanf("%s", category);

  if(strlen(category) > 1){
    printf("入力エラーです。\n");
    return;
  }

  s_n = 0;
  while(s_n != 1){
    if((s_n = (search_n((*p), atoi(category)))) != 1){
      printf("その分類番号は登録されていません。\n");
      printf("ファイルの分類番号を入力してください。(例: 3)\n>");
      scanf("%s%*c", category);
    }
    if(strlen(category) > 1){
      printf("入力エラーです。\n");
      return;
    }
  }

  insert_cell_f(pointer, main_title, sub_title, date, path, atoi(category));

  printf("ファイルを登録しました。\n");
  printf("%s %s %s %s %d\n", (*pointer)->main_title, (*pointer)->sub_title, (*pointer)->date, (*pointer)->path, (*pointer)->category);
}
