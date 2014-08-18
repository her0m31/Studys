/* delete.c */
#include "adrb.h"

void delete_adrb(struct tree **root)
{
  FILE *fp;
  struct tree **view;
  struct tree *temp;
  char chose[MAXLEN];
  char items[2][MAXLEN];
  int flag_i, flag_j, flag_x;
  
  flag_i = 0;
  flag_j = 0;
  while(flag_i != 1) {
    flag_j = 0;
    while(flag_j != 1) {
      flag_j = 1;
      printf("������뽻��Ͽ�򸡺����ޤ���\n");
      printf("������뽻��Ͽ��ֻ�̾�ס֥᡼�륢�ɥ쥹�פν�����Ϥ��Ƥ���������\n");
      printf("> ");
      if( scanf("%s %s", items[0], items[1] ) == EOF ) {
        printf("\n���ϥ��顼�Ǥ�!\n");;
        flag_j = 0;
        continue;
      }
    }
    
    flag_x = 0;
    view = root;
    while( *view != NULL ) {
      if( strcmp( (*view)->value->name, items[0] ) == 0 && strcmp( (*view)->value->mail, items[1] ) == 0 ) {
        flag_x = 1;
        printf("���פ��뽻��Ͽ������ޤ���\n");
        printf("��%s\t%s\t%s\t%s\t%s\n", (*view)->value->name, (*view)->value->posc, (*view)->value->adre, (*view)->value->tell, (*view)->value->mail); 
        
        flag_j = 0;
        while( flag_j != 1 ) {
          printf("�����˺�����ޤ���?�ֹ�����Ϥ��Ƥ���������\n0: YES\n1: NO\n"); 
          printf("> ");
          if( scanf("%s", chose) == EOF) {
            printf("\n���ϥ��顼�Ǥ�!\n");
            continue;
          };
          if( strlen(chose) != 1 ) {
            printf("���ϥ��顼�Ǥ�!\n");
            continue;
          }
          switch(chose[0]) {
          case '0':
            flag_j = 1;
            break;
          case '1':
            printf("������ޤ���Ǥ�����\n");
            flag_j = flag_i = 1;
            break;
          default:
            printf("���ϥ��顼�Ǥ�!\n");
            break;
          }
        }
        if(flag_i == 1) {
          flag_i = 0;
          break;
        }
        
        temp = *view;
        if( temp->child_l == NULL && temp->child_r == NULL ) 
          *view = NULL;
        else if( temp->child_l == NULL )
          *view = temp->child_r;
        else if( temp->child_r == NULL )
          *view = temp->child_l;
        else {
          *view            = delete_min( &(temp->child_r) );
          (*view)->child_r = temp->child_r;
          (*view)->child_l = temp->child_l;
        }
        
        free(temp);
        printf("�����λ\n");
        print_adrb(*root);
        printf("\n");
        
        fp = fopen( "adrb.dat", "w");
        if( fp == NULL ) {
          fprintf(stderr, "Cannot open file: adrb.dat\n");
          return;
        }
        save_file( fp, root );
        fclose(fp);
        break;
      } else {
        if( strcmp(items[0], (*view)->value->name) < 0 )
          view = &(*view)->child_l;
        else
          view = &(*view)->child_r;
      }
    }
    if( flag_x == 0 )
      printf("���פ��뽻��Ͽ�Ϥ���ޤ���Ǥ�����\n");
     
    flag_j = 0;
    while( flag_j != 1 ) {
      printf("����Ͽ�κ����³���ޤ������ֹ�����Ϥ��Ƥ���������\n");
      printf("0: Yes\n1: No\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("\n���ϥ��顼�Ǥ�!\n");
        continue;
      };
      if( strlen(chose) != 1) {
        printf("���ϥ��顼�Ǥ���\n");
        continue;
      }
      switch(chose[0]) {
      case '0':
        flag_j = 1;
        break;
      case '1':
        flag_j = flag_i = 1;
        break;
      default:
        printf("���ϥ��顼�Ǥ�!\n");
        break;
      }
    }    
  }

  printf("����Ͽ�κ����λ���ޤ���\n\n");
}

struct tree *delete_min(struct tree **root)
{
  struct tree *temp;
  
  while( (*root)->child_l != NULL )
    root = &((*root)->child_l);
  
  temp = *root; 
  *root = (*root)->child_r;
  return temp;
}
