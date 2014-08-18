#include "function.h"

void delete_category(struct cell_c **pointer)
{
  struct cell_c *p, *q;
  int a;
  int number;
  char category[MAXLEN];

  p = *pointer;

  printf("�������ʬ����ܤ򸡺����ޤ���\n");

  print_c(p);

  printf("�������ʬ����ܤ�ʬ������ֹ�����Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%d", &number);

  printf("�������ʬ�����̾�����Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%s", category);

  while(p != NULL && p->number != number && (strcmp(p->category, category)) != 0){
    q = p;

    p = p->next;
  }

  if(p == NULL){
    printf("���פ���ʬ����ܤϤ���ޤ���Ǥ�����\n");
    return;
  }

  else{
    printf("%d %s\n", p->number, p->category);
    printf("����ʬ����ܤ������˺�����ޤ�����");
    printf("0: Yes 1: No\n");
    printf(">");

    scanf("%d", &a);

    if(a == 1){
      printf("����򥭥�󥻥뤷�ޤ�����");
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
      printf("�������λ���ޤ�����\n");
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