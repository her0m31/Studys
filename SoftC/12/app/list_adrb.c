/* list_adrb.c */
#include "adrb.h"

void list_adrb(struct tree **root)
{
  char chose[MAXLEN];
  int flag_j;

  flag_j = 0;
  while(flag_j != 1) {
    printf("����Ͽ������ɽ�����ޤ����ֹ�����Ϥ��Ƥ���������\n");
    printf("0: ����ɽ��\t1: �������ɽ��\t2: �߽����ɽ��\n");
    printf("> ");
    if( scanf("%s", chose) == EOF ) {
      printf("���ϥ��顼�Ǥ�!\n");
      return;
    };
    if(strlen(chose) != 1) {
      printf("���ϥ��顼�Ǥ�!\n");
      return;
    }
    switch(chose[0]) {
    case '0':
      flag_j = 1;
      break;
    case '1':
      flag_j = 1;
      break;
    case '2':
      flag_j = 1;
      break; 
    default:
      printf("���ϥ��顼�Ǥ�!\n");
      break;
    }
  }
  
  switch(chose[0]) {
  case '0':
    printf("����ɽ��\n");
    print_adrb(*root);
    break;
  case '1':
    printf("�������ɽ��\n");
    up_print(*root);
    break;
  case '2': 
    printf("�߽����ɽ��\n");
    down_print(*root);
    break;
  default:
    printf("���ϥ��顼�Ǥ�!\n");
    break;
  }
  printf("\n");
  
  return;
}
