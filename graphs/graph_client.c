#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define LEN 50

FILE *open_file(char *name, char *mode);

int main(int argc, char **argv){

  // user didn't specify the input file name containing the graph structure
  if(argc != 2){
     printf("Usage: ./main <file_name>..\n");
     return(1);
  }

  FILE *fpr = NULL;
  char line[LEN];
  int i, j, node_value, edges, list_value, weight;
  int num_nodes = 8;
  graph *gr = NULL;


  // graph initialization
  gr = graph_init(num_nodes);
  if(gr == NULL){
     return(1);
  }

  // open the file again
  fpr = open_file(argv[1], "r");
  i = 0;
  while(fscanf(fpr, "%d %d", &node_value, &edges) != EOF){

     gr->nodes[i]->value = node_value;
     
     // read all the node adjacent to the current one
     for(j = 0; j<edges; j++){
        fscanf(fpr, "%d %d", &list_value, &weight);
        gr = graph_add_node(gr, i, list_value, weight);
        if(gr == NULL){
           return(1);
        }
     }
     i++;
  }

  fclose(fpr);

  //print_graph(gr);

  //depth_first_search(gr, 0);
  //breadth_first_search(gr);
  dijkstra(gr, 0);

  for(j=0; j<gr->num_nodes; j++){
    printf("Node: %d\tweight: %d\n", gr->nodes[j]->value, gr->nodes[j]->distance);
  }
 
  return (0);
}

FILE *open_file(char *name, char *mode){
   FILE *fp;
   fp = fopen(name, mode);
   if(fp == NULL){
      printf("Unable to open '%s' file, closing..\n", name);
      exit(1);
   }
   return fp;
}