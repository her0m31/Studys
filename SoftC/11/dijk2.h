/* dijk2.h */
#define END_OF_PATH -1
#define NODES 9
#define INF 999
struct node {
  int dist;
  int flag;
  int path;
};
int adjacency(char file[], int matrix[][NODES]);
void dijkstra(int start, int end, struct node node_dat[], int matrix[][NODES]);
