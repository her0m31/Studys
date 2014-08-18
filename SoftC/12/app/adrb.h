/* adrb.h */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXLEN 200
struct adrb {
  char *name;
  char *posc;
  char *adre;
  char *tell;
  char *mail;
  int count;
};
struct tree {
  struct adrb *value;
  struct tree *child_l;
  struct tree *child_r;
};
void greet(void);
void goodbye(void);
/* make_tree.c */
struct tree *create_node(struct adrb *new_adrb);
struct tree *make_tree(int item_num);
struct tree *make_rev_tree(int item_num);
/* add.c */
void add_adrb(struct tree **root, int item_num);
void add_node(struct tree **root, struct tree *new_node, int item_num);
void add_rev_node(struct tree **root, struct tree *new_node, int item_num );
struct adrb *create_adrb(char *name, char *posc, char *adre, char *tell, char *mail, int count);
/* reference.c */
void reference_adrb(struct tree **root);
/* print.c */
void save_file(FILE *fp, struct tree **root);
void print_adrb(struct tree *root);
void print_history(struct tree *root, int count);
void print_match(struct tree *root, struct adrb **data, char *key, int num, int *count);
/* search.c */
struct adrb *search_adrb(struct tree *root, char *key, int items);
/* fix_adrb.c */
void fix_adrb(struct tree **root);
void fix_item(struct adrb *data, char *items, int item_num);
/* delete.c */
void delete_adrb(struct tree **root);
struct tree *delete_min(struct tree **root);
/* up_down.c */
void down_print(struct tree *root);
void up_print(struct tree *root);
/* list_adrb.c */
void list_adrb(struct tree **root);
