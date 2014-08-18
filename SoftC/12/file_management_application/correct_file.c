#include "function.h"

void rename_file(struct cell_f **pointer)
{
  struct cell_f *p, *q;
  int data;
  char key[MAXLEN];
  char main[MAXLEN], sub[MAXLEN];

  printf("��������ե�����򸡺����ޤ���\n");

  printf("��������ե�����Υ����ȥ�̾�����Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%s", main);

  printf("��������ե�������������ȥ�̾�����Ϥ��Ƥ���������\n");
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
    printf("����������ܤ����򤷤Ƥ���������\n");
    printf("0: �����ȥ� 1: �������ȥ� 2: �������� 3: �ѥ�̾ 4: ʬ�����̾\n");
    printf(">");
    scanf("%d", &data);
    if(0 >= data && data >= 4){
      printf("���Ϥ��ְ�äƤ��ޤ���\n");
      return;
    }

    printf("������Υǡ��������Ϥ��Ƥ���������\n");
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

    printf("�ǡ����ν�������λ���ޤ�����\n");
  }
}
