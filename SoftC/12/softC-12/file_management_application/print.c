#include "function.h"

void print_f(struct cell_f *p)
{
  if(p == NULL){
    printf("一致するファイルはありませんでした。\n");
    return;
  }

  while(p != NULL){
    printf("%s %s %s %s %d\n", p->main_title, p->sub_title, p->date, p->path, p->category);
    p = p->next;
  }
}

void print_c(struct cell_c *p)
{
  if(p == NULL){
    printf("一致する分類項目はありませんでした。\n");
    return;
  }

  while(p != NULL){
    printf("%d %s\n", p->number, p->category);
    p = p->next;
  }
}
