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
  int i, node_value;
  int num_nodes = 0;
  graph *gr = NULL;

  // open the file
  fpr = open_file(argv[1], "r");
  
  // just count the number of rows and, hence, the number of nodes of the graph
  while(fgets(line, LEN, fpr) != NULL){
    num_nodes++;
  }

  fclose(fpr);

  // graph initialization missing!
  //gr = graph_init(num_nodes);
  if(gr == NULL){
     return(1);
  }

  // open the file again
  fpr = open_file(argv[1], "r");

  for(i = 0; i<gr->num_nodes; i++){
     fgets(line, LEN, fpr);
     sscanf(line, "%d ", &node_value);

     gr->nodes[i]->value = node_value;

     // read all the node adjacent to the current one
     while(sscanf(line, "%d ", &node_value) != EOF){
        // insert a new node in the adjency list for the current node
        gr = graph_add_node(gr, i, node_value);
        if(gr == NULL){
           return(1);
        }
     }
  }

  fclose(fpr);


  for(i = 0; i<gr->num_nodes; i++){
     printf("Node: %d\n", gr->nodes[i]->value);
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