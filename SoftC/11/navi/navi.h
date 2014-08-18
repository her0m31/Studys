/* navi.h */
#define INF 999
#define EOP -1
struct node {
  int  dist;
  int  flag;
  int  path;
  char *name; 
};
struct edge {
  int  dst;
  int  weight;
  char *line;
  struct edge *next;
};
extern struct node *node_dat;
extern struct edge **list;
extern int nodes;
void read_line(void);
void read_station(void);
void dijkstra(int start, int end);
void output(struct edge *path, int start, int end);
void make_path(struct edge **ptr, int start, int end);
int insert_cell(struct edge **ptr, int dst, int weight, char *line);
int check_point(char *name);
