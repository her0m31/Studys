#include "function.h"

void rename_file(struct cell_f **pointer)
{
  struct cell_f *p, *q;
  int data;
  char key[MAXLEN];
  char main[MAXLEN], sub[MAXLEN];

  printf("修正するファイルを検索します。\n");

  printf("修正するファイルのタイトル名を入力してください。\n");
  printf(">");
  scanf("%s", main);

  printf("修正するファイルの副タイトル名を入力してください。\n");
  printf(">");
  scanf("%s", sub);


  p = *pointer;

  while(p != NULL && (strcmp(p->main_title, main)) != 0 && (strcmp(p->sub_title, sub)) != 0){
    q = p;
    p = p->next;
  }

  if(p == NULL){
    printf("一致するファイルはありませんでした。\n");
    return;
  }

  else{
    printf("%s %s %s %s %d\n", p->main_title, p->sub_title, p->date, p->path, p->category);
    printf("修正する項目を選択してください。\n");
    printf("0: タイトル 1: 副タイトル 2: 作成日付 3: パス名 4: 分類項目名\n");
    printf(">");
    scanf("%d", &data);
    if(0 >= data && data >= 4){
      printf("入力が間違っています。\n");
      return;
    }

    printf("修正後のデータを入力してください。\n");
    printf(">");
    scanf("%s", key);

    if(data == 0)
      strcpy((*pointer)->main_title, key);
	
    else if(data == 1)
      strcpy(p->sub_title, key);

    else if(data == 2)
      strcpy(p->date, key);

    else if(data == 3)
      strcpy(p->path, key);

    else if(data == 4)
      p->category = atoi(key);

    printf("データの修正が完了しました。\n");
  }
}
