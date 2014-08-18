/* main.c */
#include "adrb.h"

int main()
{
  struct tree **root;
  char chose[MAXLEN];
  int item_num;
  int i;

  *root = make_tree(item_num);
  if(*root != NULL) {
    if( strcmp( (*root)->value->name, "ZZZZ") == 0 && strcmp( (*root)->value->posc, "ZZZZ") == 0  )
      return -1;
  }

  greet();

  i = 0;
  while(i != 1) {
    printf("����ɽ��\n");
    print_history(*root, 0);
    printf("\n��ǽ������ɽ�����ޤ����ֹ�����Ϥ��Ƥ���������\n");
    printf("0: ��������Ͽ����Ͽ\n1: ��¸����Ͽ�θ���\n2: ��¸����Ͽ�ν���\n3: ��¸����Ͽ�κ��\n");
    printf("4: ����ɽ��\n5: ��λ \n");
    printf("> ");

    if( scanf("%s", chose) == EOF ) {
      printf("���ϥ��顼�Ǥ�!\n");
      continue;
    };
    if(strlen(chose) > 1) {
      printf("���ϥ��顼�Ǥ�!\n");
      continue;
    }
    switch(chose[0]) {
    case '0':
      add_adrb(root, item_num); 
      break;
    case '1':
      reference_adrb(root);
      break;
    case '2':
      fix_adrb(root);
      break;
    case '3':
      delete_adrb(root);
      break;
    case '4':
      list_adrb(root);
      break;
    case '5':
      i = 1;
      break;
    default:
      printf("���ϥ��顼�Ǥ�!\n");
      break;
    }
  }

  goodbye();

  return 0;
}

void greet(void)
{
  time_t timer;
  struct tm *t_st;
  
  time(&timer); 
  t_st = localtime(&timer); 
  
  if(  3 <= t_st->tm_hour && t_st->tm_hour < 10 )
    printf("���Ϥ褦�������ޤ���\n");
  if( 10 <= t_st->tm_hour && t_st->tm_hour < 18 )
    printf("����ˤ��ϡ�\n");
  if( 18 <= t_st->tm_hour )
    printf("����Ф�\n");
  
  printf("������%d��%2d�� ", t_st->tm_mon+1, t_st->tm_mday );
  switch(t_st->tm_wday) {
  case 0:
    printf("������ ");
    break;
  case 1:
    printf("������ ");
    break;
  case 2:
    printf("������ ");
    break;
  case 3:
    printf("������ ");
    break;
  case 4:
    printf("������ ");
      break;
  case 5:
    printf("������ ");
      break;
  case 6:
    printf("������ ");
      break;
  }  
  printf("�����%2d��%2dʬ�Ǥ���\n\n", t_st->tm_hour, t_st->tm_min);
}

void goodbye(void)
{
  time_t timer;
  struct tm *t_st;
  
  time(&timer); 
  t_st = localtime(&timer);
  if(  3 <= t_st->tm_hour && t_st->tm_hour < 10 )
    printf("\n�����%2d��%2dʬ�ˤʤ�ޤ����褤������\n", t_st->tm_hour, t_st->tm_min);
  if( 10 <= t_st->tm_hour && t_st->tm_hour < 18 )
    printf("\n�����%2d��%2dʬ�ˤʤ�ޤ����褤������\n", t_st->tm_hour, t_st->tm_min);
  if( 18 <= t_st->tm_hour  )
    printf("\n�����%2d��%2dʬ�ˤʤ�ޤ��������������Ĥ��줵�ޤǤ�����\n", t_st->tm_hour, t_st->tm_min);

  printf("��λ���ޤ���\n");
}
