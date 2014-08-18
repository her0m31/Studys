/* up_down.c */
#include "adrb.h"

void up_print(struct tree *root)
{
  FILE *fp;
  char chose[MAXLEN];

  printf("�ɤι��ܤǾ���ɽ�����ޤ���?�ֹ�����Ϥ��Ƥ�������\n");
  printf("0: ��̾\n1: ͹���ֹ�\n2: ����\n3: �����ֹ�\n4: �᡼�륢�ɥ쥹\n");
  printf("> ");
 
  if( scanf("%s", chose) == EOF ) {
    printf("���ϥ��顼�Ǥ�!code:1\n");
    return;
  };
  if(strlen(chose) > 1) {
    printf("���ϥ��顼�Ǥ�!code:2\n");
    return;
  }
  if( 4 < atoi(chose) || atoi(chose) < 0){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }
  
  switch(chose[0]) {
  case '0':
    printf("��̾:�������ɽ��\n");
    root = make_tree(0);
    print_adrb(root);
    break;
  case '1':
    printf("͹���ֹ�:�������ɽ��\n");
    root = make_tree(1);
    print_adrb(root);
    break;
  case '2': 
    printf("����:�������ɽ��\n");
    root = make_tree(2);
    print_adrb(root);
    break;
  case '3': 
    printf("�����ֹ�:�������ɽ��\n");
    root = make_tree(3);
    print_adrb(root);
    break;
  case '4': 
    printf("�᡼�륢�ɥ쥹:�������ɽ��\n");
    root = make_tree(4);
    print_adrb(root);
    break;
  default:
    printf("���ϥ��顼�Ǥ�!code:3\n");
    break;
  }
  root = make_tree(0);

  return;
}


void down_print(struct tree *root)
{
  FILE *fp;
  char chose[MAXLEN];

  printf("�ɤι��ܤǹ߽�ɽ�����ޤ���?�ֹ�����Ϥ��Ƥ�������\n");
  printf("0: ��̾\n1: ͹���ֹ�\n2: ����\n3: �����ֹ�\n4: �᡼�륢�ɥ쥹\n");
  printf("> ");
 
  if( scanf("%s", chose) == EOF ) {
    printf("���ϥ��顼�Ǥ�!code:1\n");
    return;
  };
  if(strlen(chose) > 1) {
    printf("���ϥ��顼�Ǥ�!code:2\n");
    return;
  }
  if( 4 < atoi(chose) || atoi(chose) < 0){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }
  
  switch(chose[0]) {
  case '0':
    printf("��̾:�߽����ɽ��\n");
    root = make_rev_tree(0);
    print_adrb(root);
    break;
  case '1':
    printf("͹���ֹ�:�߽����ɽ��\n");
    root = make_rev_tree(1);
    print_adrb(root);
    break;
  case '2': 
    printf("����:�߽����ɽ��\n");
    root = make_rev_tree(2);
    print_adrb(root);
    break;
  case '3': 
    printf("�����ֹ�:�߽����ɽ��\n");
    root = make_rev_tree(3);
    print_adrb(root);
    break;
  case '4': 
    printf("�᡼�륢�ɥ쥹:�߽����ɽ��\n");
    root = make_rev_tree(4);
    print_adrb(root);
    break;
  default:
    printf("���ϥ��顼�Ǥ�!code:3\n");
    break;
  }
  
  root = make_tree(0);

  return;
}
