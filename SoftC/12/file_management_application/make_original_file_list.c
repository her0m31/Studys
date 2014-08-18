#include "function.h"

void insert_cell_f(struct cell_f **pointer, char *main_title, char *sub_title, char *date, char *path, int category)
{
  struct cell_f *new_cell;

  new_cell = (struct cell_f *)malloc(sizeof(struct cell_f));

  new_cell->main_title = (char *)malloc(strlen(main_title) + 1);
  new_cell->sub_title = (char *)malloc(strlen(sub_title) + 1);
  new_cell->date = (char *)malloc(strlen(date) + 1);
  new_cell->path = (char *)malloc(strlen(path) + 1);

  strcpy(new_cell->main_title, main_title);
  strcpy(new_cell->sub_title, sub_title);
  strcpy(new_cell->date, date);
  strcpy(new_cell->path, path);
  new_cell->category = category;

  new_cell->next = *pointer;
  *pointer = new_cell;
}

struct cell_f **make_original_file_list(struct cell_f **pointer, FILE *fp)
{
  struct cell_f **p;
  int category;
  char main[MAXLEN], sub[MAXLEN], date[MAXLEN], path[MAXLEN];

  p = pointer;

  while(fscanf(fp, "%s %s %s %s %d", main, sub, date, path, &category) != EOF){
    insert_cell_f(p, main, sub, date, path, category);
    p = &((*p)->next);
  }

  return pointer;
}
