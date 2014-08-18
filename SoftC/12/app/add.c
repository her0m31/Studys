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
    printf("追加する住所録を「氏名」「郵便番号」「住所」「電話番号」「メールアドレス」の順に入力してください。");
    printf("\n> ");
    if( scanf("%s %s %s %s %s", items[0], items[1], items[2], items[3], items[4] ) == EOF ) {
      printf("\n入力エラーです!\n");;
      flag_j = 0;
      while( flag_j != 1 ) {
        printf("住所録の追加を続けますか？\n");
        printf("0: Yes\n1: No\n");
        printf("> ");
        if( scanf("%s", chose) == EOF ) {
          printf("\n入力エラーです!\n");
          continue;
        };
        if( strlen(chose) != 1) {
          printf("入力エラーです。\n");
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
          printf("入力エラーです!\n");
          break;
        }
      }
      continue;
    }

    data = create_adrb( items[0], items[1], items[2], items[3], items[4], 0);
    add_node( root, create_node(data), item_num );
    
    printf("登録完了\n");
    printf("現在登録されている住所録一覧\n");
    print_adrb(*root);
  
    flag_j = 0;
    while( flag_j != 1 ) {
      printf("\n住所録の追加を続けますか？\n");
      printf("0: Yes\n1: No\n");
      printf("> ");
      if( scanf("%s", chose) == EOF ) {
        printf("入力エラーです!\n");
        continue;
      };
      if( strlen(chose) != 1) {
        printf("入力エラーです。\n");
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
        printf("入力エラーです!\n");
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
  
  printf("住所録の追加を終了します…\n\n");
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
