#include "function.h"

void sub_function(struct cell_f **pointer)
{
  FILE *fp;
  char string[MAX];
  char sub_title[MAXLEN];
  int i;
  struct cell_f *p, *q;

  struct cell_f *head = NULL;
  struct cell_f **result;

  struct cell_f *h_f = NULL;

  char main[MAXLEN];
  char sub[MAXLEN];

  /* ���������� */

  printf("�����Ȥ����ɽ�����ޤ���\n");
  
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

  else
    printf("%s %s %s %s %d\n", p->main_title, p->sub_title, p->date, p->path, p->category);

   sprintf(sub_title, "%s%s", p->path, p->main_title);


  /* ���������� */

  if ((fp = fopen(sub_title, "r")) == NULL){
    fprintf(stderr, "Cannot open file: %s\n", sub_title);
    return;
  }

  while(fgets(string, MAX - 1, fp) != NULL){
    for(i = 0; string[i] != '/'; i++){
    }
    if(string[i + 1] == '*')
      printf("%s", string);
  }

  /* ���������� */
  fclose(fp);
}