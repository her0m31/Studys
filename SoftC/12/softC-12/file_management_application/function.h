#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell_f{
  char *main_title;
  char *sub_title;
  char *date;
  char *path;
  int category;
  struct cell_f *next;
};

struct cell_c{
  int number;
  char *category;
  struct cell_c *next;
};

#define MAXLEN 100
#define MAX 2000

void insert_cell_f(struct cell_f **pointer, char *main_title, char *sub_title, char *date, char *path, int category);
struct cell_f **make_original_file_list(struct cell_f **pointer, FILE *fp);

void insert_cell_c(struct cell_c **pointer, int new_number, char *new_category);
struct cell_c **make_original_category_list(struct cell_c **pointer, FILE *fp);

void insert_cell_file(struct cell_c **p, struct cell_f **pointer);

void delete_file(struct cell_f **pointer);

void insert_cell_category(struct cell_c **pointer);
int search_n(struct cell_c *a, int n);
int search_c(struct cell_c *a, char *category);

void delete_category(struct cell_c **pointer);
void replace_number(struct cell_c *pointer);

void rename_file(struct cell_f **pointer);

void sort(struct cell_f **pointer);

struct cell_f *search(struct cell_f *pointer, int n);
void change(struct cell_f *data, int x, int y);

void category_a(struct cell_f **pointer);
void downheap_category_a(struct cell_f *data, int v, int n);

void category_d(struct cell_f **pointer);
void downheap_category_d(struct cell_f *data, int v, int n);

void date_a(struct cell_f **p);
void downheap_date_a(struct cell_f *data, int v, int n);

void date_d(struct cell_f **pointer);
void downheap_date_d(struct cell_f *data, int v, int n);

void m_a_sub_a(struct cell_f **pointer);
void downheap_main_a_sub_a(struct cell_f *data, int v, int n);

void m_a_sub_d(struct cell_f **pointer);
void downheap_main_a_sub_d(struct cell_f *data, int v, int n);

void m_d_sub_a(struct cell_f **pointer);
void downheap_main_d_sub_a(struct cell_f *data, int v, int n);

void m_d_sub_d(struct cell_f **pointer);
void downheap_main_d_sub_d(struct cell_f *data, int v, int n);

void path_a(struct cell_f **pointer);
void downheap_path_a(struct cell_f *data, int v, int n);

void path_d(struct cell_f **pointer);
void downheap_path_d(struct cell_f *data, int v, int n);

void print_f(struct cell_f *p);
void print_c(struct cell_c *p);

void search_f(struct cell_f **h_f, struct cell_f **pointer);
struct cell_f **search_file(struct cell_f **h_f, struct cell_f *pointer, int number, char *key);

void delete_cell(struct cell_f **pointer);

void sub_function(struct cell_f **pointer);

void insert_cell_new_category(struct cell_c **pointer, char *new_category);
