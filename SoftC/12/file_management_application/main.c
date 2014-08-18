#include "function.h"

int main()
{
  int i;
  char chose[MAXLEN];
  struct cell_f **f;
  struct cell_c **c;
  struct cell_f *head_f = NULL;
  struct cell_c *head_c = NULL;
  struct cell_f *h_f = NULL;
  FILE *fp_f, *fp_c;

  printf("Welcome!\n");

  if ((fp_f = fopen("original_file.dat", "r")) == NULL){
    fprintf(stderr, "Cannot open file: original_filet.dat\n");
    return;
  }

  if ((fp_c = fopen("category_list.dat", "r")) == NULL){
    fprintf(stderr, "Cannot open file: category_list.dat\n");
    return;
  }


  f = make_original_file_list(&head_f, fp_f);
  c = make_original_category_list(&head_c, fp_c);

  i = 0;

  while(i != 1){
    printf("機能一覧を表示します。\n");
    printf("0: 新規ファイルの登録 \n1: 既存ファイルの削除 \n2: 任意のファイル、任意の項目への修正 \n3: 既存のファイルの検索 \n4: 新たな分類項目の追加 \n5: 既存の分類項目の削除 \n6: 任意のファイルのコメント抽出\n");
    printf(">");
    scanf("%s", chose);

    if(strlen(chose) > 1){
      printf("入力エラーです。\n");
      continue;
    }

    switch (chose[0]) {
    case '0':
      insert_cell_file(c, f);
      break;

    case '1':
      delete_file(f);
      break;

    case '2':
      rename_file(f);
      break;

    case '3':
      search_f(&h_f, f);
      delete_cell(&h_f);
      break;

    case '4':
      insert_cell_category(c);
      break;

    case '5':
      delete_category(c);
      break;

    case '6':
      sub_function(f);
      break;

    default:
      printf("入力エラーです。\n");
      break;

    }

    printf("アプリケーションの実行を続けますか？\n");
    printf("0: Yes 1: No\n");
    printf(">");
    scanf("%d", &i);
    while(i != 0 && i != 1){
      printf("アプリケーションの実行を続けますか？\n");
      printf("0: Yes 1: No\n");
      printf(">");
      scanf("%d", &i);
    }
  }

  fclose(fp_f);
  fclose(fp_c);

  if ((fp_f = fopen("original_file.dat", "w")) == NULL){
    fprintf(stderr, "Cannot open file: original_filet.dat\n");
    return;
  }

  if ((fp_c = fopen("category_list.dat", "w")) == NULL){
    fprintf(stderr, "Cannot open file: original_filet.dat\n");
    return;
  }

  while((*f) != NULL){
    fprintf(fp_f, "%s %s %s %s %d\n", (*f)->main_title, (*f)->sub_title, (*f)->date, (*f)->path, (*f)->category);
    (*f) = (*f)->next;
  }

  while((*c) != NULL){
    fprintf(fp_c, "%d %s\n", (*c)->number, (*c)->category);
    (*c) = (*c)->next;
  }

  fclose(fp_f);
  fclose(fp_c);

  return 0;
}
