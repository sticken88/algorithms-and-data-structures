#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

/*
 * Function that creates a new node to be inserted into tjhe list
 * @param: new_value, a float containing the new value that must be inserted
 * @return: the new created node, if malloc is successful
 */
graph_node *create_node(float new_value){

	// declare the new pointers
	graph_node *new_node;
	// allocate memory
	new_node = (graph_node *)malloc(sizeof(*new_node));
	// check for errors
	if(new_node == NULL){
		printf("Error in new node memory allocation..\n");
		return new_node;
	}

	//everything is ok
	new_node->value = new_value;
	new_node->next = NULL;

	return new_node;
}