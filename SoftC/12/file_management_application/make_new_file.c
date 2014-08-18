#include "function.h"

void insert_cell_file(struct cell_c **p, struct cell_f **pointer)
{
  char main_title[MAXLEN], sub_title[MAXLEN], date[MAXLEN], path[MAXLEN], category[MAXLEN];
  int s_n;

  printf("�������ե��������Ͽ���ޤ���\n");

  printf("�ե�����Υ����ȥ�̾�����Ϥ��Ƥ���������(��: softC)\n>");
  scanf("%s", main_title);

  printf("�ե�������������ȥ�̾�����Ϥ��Ƥ���������(��: �ᥤ��롼����)\n>");
  scanf("%s", sub_title);

  printf("�ե�����κ������դ����Ϥ��Ƥ���������(��: 10/18/2010)\n>");
  scanf("%s", date);

  printf("�ե�����Υѥ�̾�����Ϥ��Ƥ���������(��: /g031h105/softC)\n>");
  scanf("%s", path);

  printf("�ե������ʬ���ֹ�����Ϥ��Ƥ���������(��: 3)\n>");
  scanf("%s", category);

  if(strlen(category) > 1){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }

  s_n = 0;
  while(s_n != 1){
    if((s_n = (search_n((*p), atoi(category)))) != 1){
      printf("����ʬ���ֹ����Ͽ����Ƥ��ޤ���\n");
      printf("�ե������ʬ���ֹ�����Ϥ��Ƥ���������(��: 3)\n>");
      scanf("%s%*c", category);
    }
    if(strlen(category) > 1){
      printf("���ϥ��顼�Ǥ���\n");
      return;
    }
  }

  insert_cell_f(pointer, main_title, sub_title, date, path, atoi(category));

  printf("�ե��������Ͽ���ޤ�����\n");
  printf("%s %s %s %s %d\n", (*pointer)->main_title, (*pointer)->sub_title, (*pointer)->date, (*pointer)->path, (*pointer)->category);
}
