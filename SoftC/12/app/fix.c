/* fix.c */
#include "adrb.h"

void fix_adrb(struct tree **root)
{
  FILE *fp;
  char chose[MAXLEN];
  char items[2][MAXLEN];
  struct adrb *data[MAXLEN];
  struct tree **view;
  struct tree *temp;
  int loop_main, loop_sub, flag_x;
  int i, j, num;
  
  data[0] = NULL;
  loop_main = 0;
  while( loop_main != 1 ) {
    
    loop_sub = 0;
    while(loop_sub != 1) {
      loop_sub = 1;
      printf("�������뽻��Ͽ�򸡺����ޤ���\n");
      printf("��������������Ͽ�Ρֻ�̾�פ����Ϥ��Ƥ�����������λ����ˤϡ�Ctrl�����򲡤��ʤ���D�򲡤��Ƥ��������ס�\n");
      printf("> ");
      if( scanf("%s", items[0] ) == EOF ) {
        printf("����Ͽ�ν�����λ���ޤ���\n\n");
        return;
      }
    }
    
    i = 0;
    print_match(*root, data, items[0], 0, &i);

    if( data[0] == NULL ) {
      printf("���פ��뽻��Ͽ�Ϥ���ޤ���Ǥ�����\n\n"); 
      continue;
    } else {
      printf("���פ��뽻��Ͽ������ޤ���\n");
      for(j = 0; j < i; j++)
        printf("��%2d: %s\t%s\t%s\t%s\t%s\n", j+1, data[j]->name, data[j]->posc, data[j]->adre, data[j]->tell, data[j]->mail); 
    }
    
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("\n�ɤν���Ͽ�������ޤ���?�����ֹ�����Ϥ��Ƥ������������������˽�λ����ˤϡ�Ctrl�����򲡤��ʤ���D�򲡤��Ƥ��������ס�\n"); 
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("����Ͽ�ν�����λ���ޤ���\n\n");
        return;
      };
      if(strlen(chose) != 1) {
        printf("���ϥ��顼�Ǥ�!\n");
        continue;
      }
      if( atoi(chose) < 1 || i < atoi(chose) ) {
        printf("���ϥ��顼�Ǥ�!\n");
        continue;
      }
      printf("���ν���Ͽ�����򤵤�ޤ�����\n");
      printf("��%2d: %s\t%s\t%s\t%s\t%s\n", atoi(chose), data[atoi(chose)-1]->name, data[atoi(chose)-1]->posc, data[atoi(chose)-1]->adre, data[atoi(chose)-1]->tell, data[atoi(chose)-1]->mail); 
      num = atoi(chose) - 1;
      loop_sub = 1;
    }
    
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("\n�ɤι��ܤ������ޤ���?�ֹ�����Ϥ��Ƥ������������������˽�λ����ˤ�5�����Ϥ��Ƥ���������\n"); 
      printf("0: ��̾\n1: ͹���ֹ�\n2: ����\n3: �����ֹ�\n4: �᡼�륢�ɥ쥹\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("���ϥ��顼�Ǥ�!\n");
        continue;
      };
      if(strlen(chose) != 1) {
        printf("���ϥ��顼�Ǥ�!\n");
        continue;
      }
      switch(chose[0]) {
      case '0':
        loop_sub = 1;
        break;
      case '1':
        loop_sub = 1;
        break;
      case '2':
        loop_sub = 1;
        break;
      case '3':
        loop_sub = 1;
        break;
      case '4':
        loop_sub = 1;
        break;
      case '5': 
        printf("����Ͽ�ν�����λ���ޤ���\n\n");
        return;
      default:
        printf("���ϥ��顼�Ǥ�!\n");
        break;
      }  
    }
    
    loop_sub = 0;
    while(loop_sub != 1) {
      loop_sub = 1;
      printf("�������Ƥ���������\n");
      printf("> ");
      if( scanf("%s", items[1]) == EOF ) {
        printf("���ϥ��顼�Ǥ�!\n\n");
        loop_sub = 0;
        continue;
      }
    }
    
    fix_item( data[num], items[1], atoi(chose) );
    printf("������λ\n");
    print_adrb(*root);
    printf("\n");
  
    fp = fopen( "adrb.dat", "w");
    if( fp == NULL ) {
      return;
    }
    save_file( fp, root );
    fclose(fp); 
  
    loop_sub = 0;
    while( loop_sub != 1 ) {
      printf("����Ͽ�ν�����³���ޤ������ֹ�����Ϥ��Ƥ���������\n");
      printf("0: Yes\n1: No\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("���ϥ��顼�Ǥ�!\n");
        continue;
      };
      if( strlen(chose) != 1) {
        printf("���ϥ��顼�Ǥ���\n");
        continue;
      }
      switch(chose[0]) {
      case '0':
        loop_sub = 1;
        break;
      case '1':
        loop_sub = loop_main = 1;
        break;
      default:
        printf("���ϥ��顼�Ǥ�!\n");
        break;
      }
    }
    
  }
  printf("����Ͽ�ν�����λ���ޤ���\n\n");
}


void fix_item(struct adrb *data, char *items, int item_num)
{   
  if(item_num == 0) {  
    data->name = (char *)malloc(strlen(items) + 1);
    strcpy( data->name, items);
  }
  if(item_num == 1) {
    data->posc = (char *)malloc(strlen(items) + 1);
    strcpy( data->posc, items); 
  }
  if(item_num == 2) {
    data->adre = (char *)malloc(strlen(items) + 1);
    strcpy( data->adre, items);
  }
  if(item_num == 3) {
    data->tell = (char *)malloc(strlen(items) + 1);
    strcpy( data->tell, items);
  }
  if(item_num == 4) {
    data->mail = (char *)malloc(strlen(items) + 1);
    strcpy( data->mail, items);
  }
}
