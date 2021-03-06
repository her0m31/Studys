#include "function.h"

void delete_category(struct cell_c **pointer)
{
  struct cell_c *p, *q;
  int a;
  int number;
  char category[MAXLEN];

  p = *pointer;

  printf("削除する分類項目を検索します。\n");

  print_c(p);

  printf("削除する分類項目の分類項目番号を入力してください。\n");
  printf(">");
  scanf("%d", &number);

  printf("削除する分類項目名を入力してください。\n");
  printf(">");
  scanf("%s", category);

  while(p != NULL && p->number != number && (strcmp(p->category, category)) != 0){
    q = p;

    p = p->next;
  }

  if(p == NULL){
    printf("一致する分類項目はありませんでした。\n");
    return;
  }

  else{
    printf("%d %s\n", p->number, p->category);
    printf("この分類項目を本当に削除しますか？");
    printf("0: Yes 1: No\n");
    printf(">");

    scanf("%d", &a);

    if(a == 1){
      printf("削除をキャンセルしました。");
      return;
    }

    else if(a == 0){
      if(p == *pointer){
        *pointer = p->next;
        free((void *)p);
      }
      else{
        q->next = p->next;
        free(p);
      }
      printf("削除が完了しました。\n");
      replace_number(q->next);
    }
  }
}

void replace_number(struct cell_c *pointer)
{
  while(pointer != NULL){
    pointer->number = pointer->number - 1;
    pointer = pointer->next;
  }
}
