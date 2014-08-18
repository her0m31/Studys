/* add.c */
#include "adrb.h"

void add_adrb(struct tree **root, int item_num)
{
  FILE *fp;
  char items[5][MAXLEN]; 
  char chose[MAXLEN];
  struct adrb *data = NULL;
  int flag_i, flag_j;

  flag_i = 0;
  flag_j = 0;
  while( flag_i != 1) {
    printf("�ɲä��뽻��Ͽ��ֻ�̾�ס�͹���ֹ�סֽ���ס������ֹ�ס֥᡼�륢�ɥ쥹�פν�����Ϥ��Ƥ���������");
    printf("\n> ");
    if( scanf("%s %s %s %s %s", items[0], items[1], items[2], items[3], items[4] ) == EOF ) {
      printf("\n���ϥ��顼�Ǥ�!\n");;
      flag_j = 0;
      while( flag_j != 1 ) {
        printf("����Ͽ���ɲä�³���ޤ�����\n");
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
      continue;
    }

    data = create_adrb( items[0], items[1], items[2], items[3], items[4], 0);
    add_node( root, create_node(data), item_num );
    
    printf("��Ͽ��λ\n");
    printf("������Ͽ����Ƥ��뽻��Ͽ����\n");
    print_adrb(*root);
  
    flag_j = 0;
    while( flag_j != 1 ) {
      printf("\n����Ͽ���ɲä�³���ޤ�����\n");
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
  
  fp = fopen( "adrb.dat", "w");
  if( fp == NULL ) {
    fprintf(stderr, "Cannot open file: adrb.dat\n");
    return;
  }
  save_file( fp, root );
  fclose(fp);
  
  printf("����Ͽ���ɲä�λ���ޤ���\n\n");
}

void add_node(struct tree **root, struct tree *new_node, int item_num )
{
  if(item_num == 0) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->name, new_node->value->name) > 0 )
      add_node( &((*root)->child_l), new_node, item_num);
    else
      add_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 1) {
    if(*root == NULL)
      *root = new_node;
    else  if( strcmp( (*root)->value->posc, new_node->value->posc) > 0 )
      add_node( &((*root)->child_l), new_node, item_num);
    else
      add_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 2) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->adre, new_node->value->adre) > 0 )
      add_node( &((*root)->child_l), new_node, item_num);
    else
      add_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 3) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->tell, new_node->value->tell) > 0 )
      add_node( &((*root)->child_l), new_node, item_num);
    else
      add_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 4) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->mail, new_node->value->mail) > 0 )
      add_node( &((*root)->child_l), new_node, item_num);
    else
      add_node( &((*root)->child_r), new_node, item_num);
  }
}

void add_rev_node(struct tree **root, struct tree *new_node, int item_num )
{
  if(item_num == 0) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->name, new_node->value->name) < 0 )
      add_rev_node( &((*root)->child_l), new_node, item_num);
    else
      add_rev_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 1) {
    if(*root == NULL)
      *root = new_node;
    else  if( strcmp( (*root)->value->posc, new_node->value->posc) < 0 )
      add_rev_node( &((*root)->child_l), new_node, item_num);
    else
      add_rev_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 2) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->adre, new_node->value->adre) < 0 )
      add_rev_node( &((*root)->child_l), new_node, item_num);
    else
      add_rev_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 3) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->tell, new_node->value->tell) < 0 )
      add_rev_node( &((*root)->child_l), new_node, item_num);
    else
      add_rev_node( &((*root)->child_r), new_node, item_num);
  }
  if(item_num == 4) {
    if(*root == NULL)
      *root = new_node;
    else if( strcmp( (*root)->value->mail, new_node->value->mail) < 0 )
      add_rev_node( &((*root)->child_l), new_node, item_num);
    else
      add_rev_node( &((*root)->child_r), new_node, item_num);
  }
}

struct adrb *create_adrb(char *name, char *posc, char *adre, char *tell, char *mail, int count)
{
  struct adrb *data;

  data = ( struct adrb * )malloc( sizeof( struct adrb ) );
  data->name = (char *)malloc(strlen(name) + 1);
  strcpy(data->name, name);
  
  data->posc = (char *)malloc(strlen(posc) + 1);
  strcpy(data->posc, posc);
  
  data->adre = (char *)malloc(strlen(adre) + 1);
  strcpy(data->adre, adre);
  
  data->tell = (char *)malloc(strlen(tell) + 1);
  strcpy(data->tell, tell);
  
  data->mail = (char *)malloc(strlen(mail) + 1);
  strcpy(data->mail, mail);
  
  data->count = count;

  return data;
}
