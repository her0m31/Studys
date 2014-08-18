#include "function.h"

void sort(struct cell_f **pointer)
{
  char c[MAXLEN];

  printf("ʣ���Υե����뤬ɽ������ޤ�����������ˡ�����򤷤Ƥ���������\n");
  printf("0: �����ȥ뾺���������ȥ뾺�� 1: �����ȥ뾺���������ȥ�߽� 2: �����ȥ�߽��������ȥ뾺�� 3: �����ȥ�߽��������ȥ�߽� 4: �������վ��� 5: �������չ߽� 6: �ѥ�̾���� 7: �ѥ�̾�߽� 8: ʬ��̾�߽� 9: ʬ��̾�߽�\n");
  printf(">");
  scanf("%s", c);

  if(strlen(c) > 1){
    printf("���ϥ��顼�Ǥ���\n");
    return;
  }

  switch (c[0]) {
  case '0':
    m_a_sub_a(pointer);

  case '1':
    m_a_sub_d(pointer);

  case '2':
    m_d_sub_a(pointer);

  case '3':
    m_d_sub_d(pointer);

  case '4':
    date_a(pointer);

  case '5':
    date_d(pointer);

  case '6':
    path_a(pointer);

  case '7':
    path_d(pointer);

  case '8':
    category_a(pointer);

  case '9':
    category_d(pointer);

  default:
    printf("���ϥ��顼�Ǥ���\n");
  }

}

/* ���ꤵ�줿�Ρ��ɤؤΥݥ��󥿤��֤� */
struct cell_f *search(struct cell_f *pointer, int n)
{
  int i;

  if(pointer == NULL)
    return NULL;
  else if(n == 1)
    return pointer;
  else{
    for(i = 0; i < n - 1; i++)
      pointer = pointer->next;
  }

  return pointer;
}

/* ���Ǥ������ؤ� */
void change(struct cell_f *data, int x, int y)
{
  struct cell_f *tmp, *a, *b;

  tmp = (struct cell_f *)malloc(sizeof(struct cell_f));

  a = search(data, x);
  b = search(data, y);

  tmp->main_title = a->main_title;
  tmp->sub_title = a->sub_title;
  tmp->date = a->date;
  tmp->path = a->path;
  tmp->category = a->category;

  a->main_title = b->main_title;
  a->sub_title = b->sub_title;
  a->date = b->date;
  a->path = b->path;
  a->category = b->category;

  b->main_title = tmp->main_title;
  b->sub_title = tmp->sub_title;
  b->date = tmp->date;
  b->path = tmp->path;
  b->category = tmp->category;
}

void category_a(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_category_a((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_category_a((*pointer), 1, j - 1);
  }
}

void downheap_category_a(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  if(right != NULL && (left->category <= right->category) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  if(upper->category <= lower->category){
    change(data, v, w);
    downheap_category_a(data, w, n);
  }
}

void category_d(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_category_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_category_d((*pointer), 1, j - 1);
  }
}

void downheap_category_d(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && (left->category >= right->category) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if(upper->category >= lower->category){
    change(data, v, w);
    downheap_category_d(data, w, n);
  }
}

void date_a(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_date_a((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_date_a((*pointer), 1, j - 1);
  }
}

void downheap_date_a(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && ((strcmp(left->date, right->date)) < 0) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->date, lower->date)) <= 0){
    change(data, v, w);
    downheap_date_a(data, w, n);
  }
}

void date_d(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_date_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_date_d((*pointer), 1, j - 1);
  }
}

void downheap_date_d(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && ((strcmp(left->date, right->date)) > 0) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->date, lower->date)) >= 0){
    change(data, v, w);
    downheap_date_d(data, w, n);
  }
}

void m_a_sub_a(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_main_a_sub_a((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_main_a_sub_a((*pointer), 1, j - 1);
  }
}

void downheap_main_a_sub_a(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && (((strcmp(left->main_title, right->main_title)) < 0) || ((strcmp(left->main_title, right->main_title)) == 0) && ((strcmp(left->sub_title, right->sub_title)) < 0)) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->main_title, lower->main_title)) == 0){
    if((strcmp(upper->sub_title, lower->sub_title)) < 0){
      change(data, v, w);
      downheap_main_a_sub_a(data, w, n);
    }
  }

  else if((strcmp(upper->main_title, lower->main_title)) < 0){
    change(data, v, w);
    downheap_main_a_sub_a(data, w, n);
  }
}

void m_a_sub_d(struct cell_f **pointer)
{
  int i, j, k;
  struct cell_f *q;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_main_a_sub_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_main_a_sub_d((*pointer), 1, j - 1);
  }
}

void downheap_main_a_sub_d(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && (((strcmp(left->main_title, right->main_title)) < 0) || ((strcmp(left->main_title, right->main_title)) == 0) && ((strcmp(left->sub_title, right->sub_title)) > 0)) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->main_title, lower->main_title)) == 0){
    if((strcmp(upper->sub_title, lower->sub_title)) > 0){
      change(data, v, w);
      downheap_main_a_sub_d(data, w, n);
    }
  }

  else if((strcmp(upper->main_title, lower->main_title)) < 0){
    change(data, v, w);
    downheap_main_a_sub_d(data, w, n);
  }
}

void m_d_sub_a(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--)
    downheap_main_a_sub_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_main_a_sub_d((*pointer), 1, j - 1);
  }
}

void downheap_main_d_sub_a(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && (((strcmp(left->main_title, right->main_title)) > 0) || ((strcmp(left->main_title, right->main_title)) == 0) && ((strcmp(left->sub_title, right->sub_title)) < 0)) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->main_title, lower->main_title)) == 0){
    if((strcmp(upper->sub_title, lower->sub_title)) < 0){
      change(data, v, w);
      downheap_main_a_sub_d(data, w, n);
    }
  }

  else if((strcmp(upper->main_title, lower->main_title)) > 0){
    change(data, v, w);
    downheap_main_a_sub_d(data, w, n);
  }
}

void m_d_sub_d(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_main_d_sub_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_main_d_sub_d((*pointer), 1, j - 1);
  }
}

void downheap_main_d_sub_d(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && (((strcmp(left->main_title, right->main_title)) > 0) || ((strcmp(left->main_title, right->main_title)) == 0) && ((strcmp(left->sub_title, right->sub_title)) > 0)) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->main_title, lower->main_title)) == 0){
    if((strcmp(upper->sub_title, lower->sub_title)) > 0){
      change(data, v, w);
      downheap_main_d_sub_d(data, w, n);
    }
  }

  else if((strcmp(upper->main_title, lower->main_title)) > 0){
    change(data, v, w);
    downheap_main_d_sub_d(data, w, n);
  }
}

void path_a(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;
	
  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_path_a((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_path_a((*pointer), 1, j - 1);
  }
}

void downheap_path_a(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && ((strcmp(left->path, right->path)) < 0) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);    
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->path, lower->path)) <= 0){
    change(data, v, w);
    downheap_path_a(data, w, n);
  }
}

void path_d(struct cell_f **pointer)
{
  struct cell_f *q;
  int i, j, k;

  q = (*pointer);

  for(k = 0; q != NULL; k++)
    q = q->next;

  for (i = k; 0 < i; i--) 
    downheap_path_d((*pointer), i, k);

  for (j = k; 1 < j; j--){
    change((*pointer), 1, j);
    downheap_path_d((*pointer), 1, j - 1);
  }
}

void downheap_path_d(struct cell_f *data, int v, int n)
{
  int w;
  struct cell_f *left, *right, *upper, *lower;

  /* v���ҥΡ��ɤ�����ʤ���� */
  if(v > n / 2)
    return;

  left = search(data, 2 * v);
  right = search(data, 2 * v + 1);

  /* ���λҥΡ��ɤ����뤫�ı��λҤ������礭����� */
  if(right != NULL && ((strcmp(left->path, right->path)) > 0) && (2 * v + 1) <= n)
    w = 2 * v + 1;
	
  else
    w = 2 * v;

  upper = search(data, v);
  lower = search(data, w);

  /* v����w���ͤ��礭�� */
  if((strcmp(upper->path, lower->path)) >= 0){
    change(data, v, w);
    downheap_path_d(data, w, n);
  }
}
