#include "function.h"

void insert_cell_c(struct cell_c **pointer,int new_number, char *new_category)
{
  struct cell_c *new_cell;

  new_cell = (struct cell_c *)malloc(sizeof(struct cell_c));
  new_cell->category = (char *)malloc(strlen(new_category) + 1);

  new_cell->number = new_number;
  strcpy(new_cell->category, new_category);
  new_cell->next = *pointer;
  *pointer = new_cell;
}

struct cell_c **make_original_category_list(struct cell_c **pointer, FILE *fp)
{
  struct cell_c **p;
  int number;
  char category[MAXLEN];

  p = pointer;

  while(fscanf(fp, "%d %s", &number, category) != EOF){
    insert_cell_c(p, number, category);
    p = &((*p)->next);
  }

  return pointer;
}
