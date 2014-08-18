#include "function.h"

void delete_file(struct cell_f **pointer)
{
  struct cell_f *p, *q;
  char a[MAXLEN];
  char main[MAXLEN], sub[MAXLEN];

  printf("�������ե�����򸡺����ޤ���\n");

  printf("�������ե�����Υ����ȥ�̾�����Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%s", main);

  printf("�������ե�������������ȥ�̾�����Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%s", sub);

  p = *pointer;

  while(p != NULL && (strcmp(p->main_title, main)) != 0 && (strcmp(p->sub_title, sub)) != 0){
    q = p;
    p = p->next;
  }

  if(p == NULL){
    printf("���פ���ե�����Ϥ���ޤ���Ǥ�����\n");
    return;
  }

  else{
    printf("%s %s %s %s %d\n", p->main_title, p->sub_title, p->date, p->path, p->category);
    printf("���Υե�����������˺�����ޤ�����");
    printf("0: Yes 1: No\n");
    printf(">");

    scanf("%s", a);

    if(strlen(a) > 1){
      printf("���ϥ��顼�Ǥ���\n");
      return;
    }

    if(atoi(a) == 1){
      printf("����򥭥�󥻥뤷�ޤ�����");
      return;
    }

    else if(atoi(a) == 0){
      if(p == *pointer){
        *pointer = p->next;
        free((void *)p);
      }
      else{
        q->next = p->next;
        free((void *)p);
      }

      printf("�������λ���ޤ�����\n");
      printf("�ե����������ɽ�����ޤ���\n");
      print_f((*pointer));
    }
  }
}
