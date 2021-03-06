#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"


/*
 * Initialize graph structure
 */
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

    // initialize the queue that will be used to implement breadth-first-search
    gr->queue = queue_create();

    // memory allocation for the main list of nodes
    gr->nodes = (graph_node **)malloc(gr->num_nodes * sizeof(graph_node*));
    if(gr->nodes == NULL){
    	printf("Unable to allocate memory for the edges of the graph, closing..\n");
    	return NULL;
    }

    // for each entry we need to create a node and set the pointer accordingly
    for(i = 0; i<gr->num_nodes; i++){
    	gr->nodes[i] = create_graph_node(-1, INT_MAX);
    	// if the new node is NULL, return and exit
    	if(gr->nodes[i] == NULL){
    		return NULL;
    	}  	
    }

	return gr;
}


/*
 * Function that adds a new node in the graph
 */
graph *graph_add_node(graph *gr, int node_index, int new_value, int weight){

	graph_node *new_node = create_graph_node(new_value, weight);

    // memory not available
	if(new_node == NULL){
		return NULL;
	}

    // Inserted on top of the list
	new_node->next = gr->nodes[node_index]->next;
	gr->nodes[node_index]->next = new_node;

	return gr;
}


/*
 * Function that creates a new node to be inserted into the list
 * @param: new_value, a int containing the new value that must be inserted
 * @return: the new created node, if malloc is successful
 */
graph_node *create_graph_node(int new_value, int weight){

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
	new_node->distance = weight;
	new_node->next = NULL;

	return new_node;
}


/*
 * Graph traversal with a depth-first-search approach
 */
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


/*
 * Graph traversal with a breadth-first-search approach
 */
void breadth_first_search(graph *gr){

    // insert the first node in the queue
    enqueue(&(gr->queue), gr->nodes[0]->value);
    // while the queue has item inside
	while(gr->queue->nodes){
		// get the value; it will be used like an index to access the array of nodes
		int value = dequeue(&(gr->queue));
		// print out the dequeued value
		printf("[Val] %d\n", value);
		// once we dequeue a value from the list we need to mark it as 'visited'
		gr->nodes[value]->visited = 1;
		
		// now loop over the adjacency list and insert every value inside the queue
		graph_node *node = gr->nodes[value]->next;
		while(node != NULL){
			// enqueue every value
			enqueue(&(gr->queue), node->value);
			node = node->next;
		}
	}
}


/*
 * Prints out the graph
 */
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


/*
 * Visit the graph and prints out a minimum spanning tree
 */
void dijkstra(graph *gr, int starting){

	int i, index, dist, val;

	// the distance from 'starting' to itself is 0
	gr->nodes[starting]->distance = 0;

    // index will be updated afterwards but at the beginning we start from the first node we want
	index = starting;

	while(!gr->nodes[index]->visited){

        // in this way we're not gonna process it again 
		gr->nodes[index]->visited = 1;

		// loop over the adjacency list for the current node
		graph_node *node = gr->nodes[index]->next;
		while(node != NULL){
			// get the index
			val = node->value;
            /* Relax the distances
             * If the dist(index, val) is greater than dist(index, index) + weight(index, next node)
             * then update.
             * gr->nodes[val]->distance stores the current distance between 'starting' and 'val'
             */
			if(gr->nodes[val]->distance > gr->nodes[index]->distance + node->distance){
				gr->nodes[val]->distance = gr->nodes[index]->distance + node->distance;
			}
			node = node->next;
		}


        // detect the index corresponding to the next node to process
        dist = INT_MAX;
		for(i=0; i<gr->num_nodes; i++){
			if((gr->nodes[i]->visited == 0) && (dist > gr->nodes[i]->distance)){
				index = i;
				dist = gr->nodes[i]->distance;
			}
		}
	}
}