/* reference.c */
#include "adrb.h"

void reference_adrb(struct tree **root)
{ 
  FILE *fp;
  char chose[MAXLEN];
  char items[MAXLEN];
  struct adrb *data[MAXLEN];
  int flag_i, flag_j;
  int num;
  int i, j;
  
  flag_i = 0;
  flag_j = 0;
  while(flag_i != 1) {
    flag_j = 0;
    while(flag_j != 1) {
      printf("�ɤι��ܤǸ������ޤ���?�ֹ�����Ϥ��Ƥ����������ޤ�����λ����ˤ�5�����Ϥ��Ƥ�������\n");
      printf("0: ��̾\n1: ͹���ֹ�\n2: ����\n3: �����ֹ�\n4: �᡼�륢�ɥ쥹\n");
      printf("> ");
      if( scanf("%s", chose) == EOF) {
        printf("\n���ϥ��顼�Ǥ�!\n");
        continue;
      };
      if( strlen(chose) != 1 ) {
        printf("���ϥ��顼�Ǥ���\n");
        continue;
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
      case '3':
        flag_j = 1;
        break;
      case '4':
        flag_j = 1;
        break;
      case '5':
        flag_i = flag_j = 1;
        break;
      default:
        printf("���ϥ��顼�Ǥ�!\n");
        break;
      }
    }
    if(flag_i == 1)
      continue;
    
    num = atoi(chose);
    *root = make_tree( num );
    
    flag_j = 0;
    while(flag_j != 1) {
      flag_j = 1;
      printf("������ɤ����Ϥ��Ƥ���������\n");
      printf("> ");
      if( scanf("%s", items) == EOF) {
        printf("\n���ϥ��顼�Ǥ�!\n");
        flag_j = 0;
        continue;
      } 
    }

    i = 0;
    data[0] = NULL;
    print_match( *root, data, items, num, &i); 
    
    if( data[0] == NULL ) {
      fprintf(stderr, "����Ͽ�����դ���ޤ���Ǥ���...(�������: %s)\n\n", items);
      continue;
    }else {
      printf("���פ�������Ͽ(�������: %s)\n", items);
      for(j = 0; j < i; j++)
        printf("��%2d: %s\t%s\t%s\t%s\t%s\n", j+1, data[j]->name, data[j]->posc, data[j]->adre, data[j]->tell, data[j]->mail); 
      printf("\n");
    }
  }
  
  fp = fopen( "adrb.dat", "w");
  if( fp == NULL ) {
    fprintf(stderr, "Cannot open file: adrb.dat\n");
    return;
  }
  save_file( fp, root );
  fclose(fp);
  
  printf("����Ͽ�λ��Ȥ�λ���ޤ���\n\n");
}
