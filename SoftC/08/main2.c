/* main2.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char *argv[])
{
  struct node    *root = NULL;
  struct student *data;
  char dat[5][30];
  int i;
  
  while( scanf("%s %s %s %s %s", dat[0], dat[1], dat[2], dat[3], dat[4]) != EOF){
    data = (struct student *)malloc(sizeof(struct student));
    data->name = (char *)malloc(strlen(dat[0]) + 1);
    strcpy(data->name, dat[0]);
    
    data->posc = (char *)malloc(strlen(dat[1]) + 1);
    strcpy(data->posc, dat[1]);
    
    data->adre = (char *)malloc(strlen(dat[2]) + 1);
    strcpy(data->adre, dat[2]);
    
    data->tell = (char *)malloc(strlen(dat[3]) + 1);
    strcpy(data->tell, dat[3]);
    
    data->mail = (char *)malloc(strlen(dat[4]) + 1);
    strcpy(data->mail, dat[4]);
    
    add_node(&root, create_node(data));
  }
  
  for(i = 1; i < argc ; i++){
    data = search_node(root, argv[i]);
    if(data != NULL)
      printf("%s\t%s\t%s\t%s\n", data->name, data->posc,
             data->adre, data->tell, data->mail);
    else{
      fprintf(stderr, "error!\n");
    }
  }
  
  return 0;
}
