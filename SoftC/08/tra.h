/* tra.h */

struct node {
  int value;
  struct node *child_l;
  struct node *child_r;
};
struct node *create_node(int value);
void pre_search_node(struct node *pointer);
void ino_search_node(struct node *pointer);
void pos_search_node(struct node *pointer);
void add_node(struct node **pointer, struct node *new_node);
