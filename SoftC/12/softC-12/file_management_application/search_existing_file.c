#include "function.h"

void search_f(struct cell_f **h_f, struct cell_f **pointer)
{
  struct cell_f *head = NULL;
  struct cell_f **result;

  char data[MAXLEN];
  char key[MAXLEN];


  printf("�ɤΥǡ����Ǹ������ޤ��������������Ϥ��Ƥ���������\n");
  printf("0: �����ȥ� 1: �������ȥ� 2: �������� 3: �ѥ�̾ 4: ʬ�����̾\n");
  printf(">");
  scanf("%s", data);

  if(strlen(data) > 1){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }

  if('0' >= data[0] || data[0] >= '4'){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }

  printf("���������Ϥ��Ƥ���������\n");
  printf(">");
  scanf("%s", key);

  result = search_file(h_f, (*pointer), atoi(data), key);

  if((*result) == NULL){
    printf("���פ���ǡ����Ϥ���ޤ���Ǥ�����\n");
    return;
  }
  else if((*result)->next != NULL)
    sort(result);

  print_f((*result));
}

/* �ե�������ܤ��ꥹ�Ȥ��� */
struct cell_f **search_file(struct cell_f **h_f, struct cell_f *pointer, int number, char *key)
{
  struct cell_f **p;
  char main[MAXLEN], sub[MAXLEN], date[MAXLEN], path[MAXLEN];
  int category;

  p = h_f;

  if(pointer == NULL)
    return NULL;

  if(number == 0){
    while(pointer != NULL){
      if(strcmp(pointer->main_title, key) == 0){
        strcpy(main, pointer->main_title);
        strcpy(sub, pointer->sub_title);
        strcpy(date, pointer->date);
        strcpy(path, pointer->path);
        category = pointer->category;

        insert_cell_f(p, main, sub, date, path, category);
        p = &((*p)->next);
      }
      pointer = pointer->next;
    }
    return h_f;
  }
	
  else if(number == 1){
    while(pointer != NULL){
      if(strcmp(pointer->sub_title, key) == 0){
        strcpy(main, pointer->main_title);
        strcpy(sub, pointer->sub_title);
        strcpy(date, pointer->date);
        strcpy(path, pointer->path);
        category = pointer->category;

        insert_cell_f(p, main, sub, date, path, category);
        p = &((*p)->next);
      }
      pointer = pointer->next;
    }
    return h_f;
  }

  else if(number == 2){
    while(pointer != NULL){
      if(strcmp(pointer->date, key) == 0){
        strcpy(main, pointer->main_title);
        strcpy(sub, pointer->sub_title);
        strcpy(date, pointer->date);
        strcpy(path, pointer->path);
        category = pointer->category;

        insert_cell_f(p, main, sub, date, path, category);
        p = &((*p)->next);
      }
      pointer = pointer->next;
    }
    return h_f;
  }

  else if(number == 3){
    while(pointer != NULL){
      if(strcmp(pointer->path, key) == 0){
        strcpy(main, pointer->main_title);
        strcpy(sub, pointer->sub_title);
        strcpy(date, pointer->date);
        strcpy(path, pointer->path);
        category = pointer->category;

        insert_cell_f(p, main, sub, date, path, category);
        p = &((*p)->next);
      }
      pointer = pointer->next;
    }
    return h_f;
  }

  else if(number == 4){
    while(pointer != NULL){
      if(pointer->category == atoi(key)){
        strcpy(main, pointer->main_title);
        strcpy(sub, pointer->sub_title);
        strcpy(date, pointer->date);
        strcpy(path, pointer->path);
        category = pointer->category;

        insert_cell_f(p, main, sub, date, path, category);
        p = &((*p)->next);
      }
      pointer = pointer->next;
    }
    return h_f;
  }
}
