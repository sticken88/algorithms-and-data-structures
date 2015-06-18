#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"

#define LEN 50

int main(int argc, char **argv){

  // user didn't specify the input file name containing the graph structure
  if(argc != 2){
     printf("Usage: ./graph_client <file_name>..");
     return(1);
  }

  FILE *fpr = NULL;
  char line[LEN];
  int i, node_value;
  int num_nodes = 0;
  graph *gr;

  // open the file
  fpr = open_file(argv[1], "r");
  
  // just count the number of rows and, hence, the number of nodes of the graph
  while(fgets(line, LEN, fpr) != NULL){
    num_nodes++;
  }

  fclose(fpr);

  // graph initialization missing!
  gr = graph_init(num_nodes);
  if(gr == NULL){
     return(1);
  }

  // open the file again
  /*fpr = open_file(argv[1], "r");

  for(i = 0; i<graph->num_nodes; i++){
    fgets(line, LEN, fpr);
    sscanf(line, "%d ", &node_value);

    gr->nodes[i]->value = node_value;

    // read all the node adjacent to the current one
    while(sscanf(line, "%d ", &node_value) != EOF){

    }

  }

  fclose(fpr);*/



 
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