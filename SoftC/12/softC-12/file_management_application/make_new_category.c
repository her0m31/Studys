#include "function.h"

void insert_cell_category(struct cell_c **pointer)
{
  int i;
  char new_category[MAXLEN];

  i = 0;
  while(i != 1){
    print_c((*pointer));

    printf("ʬ�����̾�����Ϥ��Ƥ���������\n");
    printf(">");
    scanf("%s", new_category);
    if(search_c((*pointer), new_category) == 1){
      printf("����ʬ����ܤϴ�����Ͽ����Ƥ��ޤ���\n");
      return;
    }
    insert_cell_new_category(pointer, new_category);
    pointer = &((*pointer)->next);
    printf("��Ͽ����λ���ޤ�����\n");
    i++;
  }
	
}

int search_n(struct cell_c *a, int n)
{
  while(a != NULL){
    if(a->number == n)
      return 1;
    else
      a = a->next;
  }

  return 0;
}

int search_c(struct cell_c *a, char *category)
{
  while(a != NULL){
    if((strcmp(a->category, category)) == 0)
      return 1;
    else
      a = a->next;
  }

  return 0;
}

void insert_cell_new_category(struct cell_c **pointer, char *new_category)
{
  struct cell_c **p;

  p = pointer;

  while((*p)->next != NULL){
    p = &((*p)->next);
  }

  insert_cell_c(&((*p)->next), (*p)->number + 1, new_category);

  print_c((*pointer));
}