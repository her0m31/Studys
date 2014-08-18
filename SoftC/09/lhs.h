/* lhs.h */
struct cell{
  int value;
  struct cell *next;
};
struct cell **get_v(struct cell **head, int n);
int insert(struct cell **pointer, int new_value);
void downheap(struct cell **head, int v, int n);
void to_heapsort(struct cell **head, int n);
