#define NODES 9
#define MAX_EDGES 36
struct cell {
  int value;
  struct cell *next;
};
int adjacency(char filename[], int edges[MAX_EDGES][2],
              struct cell *adjacency_list[]);
int insert(struct cell **pointer, int new_value);
