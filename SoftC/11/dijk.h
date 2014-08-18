/* dijk.h */
#define NODES 9
#define INF 999
struct node {
  int dist;
  int flag;
};
int adjacency(char file[], int matrix[][NODES]);
int dijkstra(int start, int end, struct node node_dat[], int matrix[][NODES]);
