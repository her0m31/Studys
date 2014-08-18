/* bst.h */

struct student {
  char *name;
  char *posc;
  char *adre;
  char *tell;
  char *mail;
};

struct node {
  struct student *value;
  struct node *child_l;
  struct node *child_r;
};

struct node *create_node(struct student *new_student);
struct student *search_node(struct node *pointer, char *key);
void add_node(struct node **pointer, struct node *new_node);
