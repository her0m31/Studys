/* linked.h */
struct cell{
  int value;
  struct cell *next;
};
int insert_cell(struct cell **pointer, int new_value);
void delete_cell(struct cell **pointer);
