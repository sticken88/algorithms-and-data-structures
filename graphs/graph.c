#include <stdio.h>
#include <stdlib.h>

#include "graph.h"


graph *graph_init(int nodes){

	graph *gr;
	int i;

    // allocate memory for the structure
    gr = (graph *)malloc(sizeof(*gr));
    if(gr == NULL){
    	printf("Error while allocating memory for the graph structure, closing..\n");
    	return gr;
    }

    // set the number of nodes
    gr->num_nodes = nodes;

    // memory allocation for the main list of nodes
    gr->nodes = (graph_node **)malloc(gr->num_nodes * sizeof(graph_node*));
    if(gr->nodes == NULL){
    	printf("Unable to allocate memory for the edges of the graph, closing..\n");
    	return NULL;
    }

    // for each entry we need to create a node and set the pointer accordingly
    for(i = 0; i<gr->num_nodes; i++){
    	gr->nodes[i] = create_graph_node(-1);
    	// if the new node is NULL, return and exit
    	if(gr->nodes[i] == NULL){
    		return NULL;
    	}  	
    }

	return gr;
}

graph *graph_add_node(graph *gr, int node_index, int new_value){

	graph_node *new_node = create_graph_node(new_value);

    // memory not available
	if(new_node == NULL){
		return NULL;
	}

	new_node->next = gr->nodes[node_index]->next;
	gr->nodes[node_index]->next = new_node;

	return gr;
}

/*
 * Function that creates a new node to be inserted into the list
 * @param: new_value, a int containing the new value that must be inserted
 * @return: the new created node, if malloc is successful
 */
graph_node *create_graph_node(int new_value){

	// declare the new pointers
	graph_node *new_node;
	// allocate memory
	new_node = (graph_node *)malloc(sizeof(*new_node));
	// check for errors
	if(new_node == NULL){
		printf("Error in new graph node memory allocation..\n");
		return new_node;
	}

	//everything is ok
	new_node->value = new_value;
	new_node->visited = 0;
	new_node->next = NULL;

	return new_node;
}


void depth_first_search(graph *gr, int node_index){

     graph_node *node = gr->nodes[node_index];

     node->visited = 1;
     printf("[Val] %d\n", node->value);

	 while(node != NULL){
	 	// we've never seen this node before, recurr
	 	if(node->visited == 0){
	 		depth_first_search(gr, node->value);
	 	}
	 	node = node->next;
	 }
}

void print_graph(graph *gr){

	int i;

	for(i=0; i<gr->num_nodes; i++){
		printf("Node: %d, list: ", gr->nodes[i]->value);
		graph_node * node = gr->nodes[i]->next;

		while(node != NULL){
			printf("%d ", node->value);
			node = node->next;
		}
		printf("\n");
	}
}