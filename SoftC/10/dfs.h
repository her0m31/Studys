/* dfs.h */
#define NODES 9 
struct edge {
  int start_node;
  int end_node;
};
int adjacency(char file[], int matrix[][NODES]);
void df_search(int u, int *df_flag, int *edge_cnt,
               struct edge df_tree[], int matrix[][NODES]);
