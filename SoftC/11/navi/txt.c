#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 999
#define END_OF_PATH -1

struct node{
  int dist;
  int flag;
  int path;
  char *name;
};

struct edge{
  int dst;
  int weight;
  char *line;
  struct edge *next;
};

struct node *node_dat;
struct edge **list;
int nodes;

void insert_cell(struct edge **ptr, int dst, int weight, char *line)
{
  struct edge *new;
  
  new = (struct edge *)malloc(sizeof (struct edge));
  new->dst = dst;
  new->weight = weight;
  
  if(line == NULL)
    new->line = NULL;
  else {
    new->line = (char *)malloc((strlen(line) + 1) * sizeof(char));
    strcpy(new->line,line);
  }
  
  new->next = *ptr;
  *ptr = new;
}

void read_station()
{
  int n;
  char station[80];
  FILE *fp;
  
  fp = fopen("station.dat","r");
  if(fp == NULL){
    fprintf(stderr,"Can not open file.\n");
    exit(1);
  }
  
  fscanf(fp,"%d",&n);
  nodes = n;
  node_dat = (struct node *)malloc(nodes * sizeof(struct node));
  while(fscanf(fp,"%d %s",&n,&station) != EOF){
    node_dat[n].name = (char *)malloc((strlen(station) + 1) * sizeof(char));
    strcpy(node_dat[n].name,station);
  }
  
  for (n = 0; n < nodes; n++) {
    node_dat[n].dist = INF;
    node_dat[n].flag = 0;
  }
  
  fclose(fp);
} 

void read_line()
{
  int u,v,weight;
  int len;
  char line[80];
  FILE *fp;
  
  fp = fopen("line.dat","r");
  if(fp == NULL){
    fprintf(stderr,"Can not open file.\n");
    exit(1);
  }
  
  list = (struct edge **) malloc (nodes * sizeof(struct edge *));
  for(u = 0; u < nodes; u++)
    list[u] = NULL;
  
  while(fscanf(fp,"%d %d %d",&u,&v,&weight)!= EOF){
    fgets(line,80,fp);
    len = strlen(line);
    if(line[len -1] == '\n')
      line[len -1] = '\0';
    insert_cell(&(list[u]),v,weight,line);
    insert_cell(&(list[v]),u,weight,line);
  }
  
  fclose(fp);
}

void dijkstra(int start, int end)
{
  int u,x;
  int min;
  struct edge *ptr;
  
  node_dat[start].flag = 1;
  for(ptr = list[start]; ptr != NULL; ptr = ptr->next)
    
    if( ptr->weight < node_dat[ptr->dst].dist) {
      node_dat[ptr->dst].dist = ptr->weight;
      node_dat[ptr->dst].path = start;
    }
  
  node_dat[start].dist = 0;
  node_dat[start].path = END_OF_PATH;
  u = start;
  while(u != end) {
    min = INF;
    for(x = 0; x < nodes; x++) {
      if(node_dat[x].flag != 1 && min > node_dat[x].dist) {
        min = node_dat[x].dist;
        u = x;
      }
    }

    node_dat[u].flag = 1;
    for(ptr = list[u]; ptr != NULL; ptr = ptr->next) {
      if(node_dat[ptr->dst].dist > node_dat[u].dist + ptr->weight) {
        node_dat[ptr->dst].dist = node_dat[u].dist + ptr->weight;
        node_dat[ptr->dst].path = u;
      }
    }
  }
}

void make_path(struct edge **ptr, int start, int end)
{
  int n;
  int min;
  struct edge *work, *tmp;
  
  *ptr = NULL;
  insert_cell(ptr,end,0,NULL);
  for(n = end; node_dat[n].path != END_OF_PATH; n = node_dat[n].path) {
    min = INF;
    for(work = list[n]; work != NULL; work = work->next) {
      if(min > node_dat[work->dst].dist && node_dat[n].path == work->dst) {
        min = node_dat[work->dst].dist;
        tmp = work;
      }
    }
    insert_cell( ptr, tmp->dst, tmp->weight, tmp->line);
  }
}

int check_start(char *name)
{
  int i;

  for(i = 0; i < nodes; i++) {
    if(strcmp(node_dat[i].name,name) == 0){
      return i;
    }
  }

  printf("Start point is not registered.\n");
  
  exit(1);
}

int check_end(char *name) 
{
  int i;

  for(i = 0; i < nodes; i++) {
    if(strcmp(node_dat[i].name,name) == 0) {
      return i;
    }
  }
  
  printf("Destination point is not registered.\n");
 
  exit(1);
}

void output(struct edge *path, int start, int end)
{
  struct edge *ptr, *work;

  printf("The shortest path from %s to %s\n", node_dat[start].name, node_dat[end].name);
  
  for(ptr = path; ptr->next != NULL; ptr = ptr->next){
    work = ptr->next;
    printf(" %17s -> %17s ",node_dat[ptr->dst].name, node_dat[work->dst].name);
    printf("by %19s for %3d [min.]\n",ptr->line ,ptr->weight);
  }
  
  printf("Total time required ... %d[min.]\n" , node_dat[ptr->dst].dist);
}

#include<stdio.h>
int main(int argc, char *argv[])
{ 
  int start,end;
  struct edge *path;
  struct edge **p;
  int i;
  
  if(argc != 3){
    printf("Please give a start point and a destination as argumrnts.\n");
    return -1;
  }
  read_station();
  start = check_start(argv[1]);
  end = check_end(argv[2]);
  read_line();
  /*
  for(i = 0; i < nodes; i++)
    printf("%2d %3d %d %2d %s\n", i, node_dat[i].dist, node_dat[i].flag, node_dat[i].path, node_dat[i].name);
  */
  for(i = 0; i < nodes; i++) {
   
    for( p = &list[i];  *p != NULL;  p = &((*p)->next) )
      printf("node %d: %2d %3d %s\n", i, (*p)->dst, (*p)->weight, (*p)->line);
    
    printf("\n");
  } 
  
  

  dijkstra(start,end);
  
  /*
  printf("\n");
  for(i = 0; i < nodes; i++)
    printf("%2d %3d %d %2d %s\n", i, node_dat[i].dist, node_dat[i].flag, node_dat[i].path, node_dat[i].name);
  */

  make_path(&path,start,end);
  output(path,start,end);
  
  return 0;
}
