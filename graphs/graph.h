#ifndef __GRAPH_FUNCTIONS__
#define __GRAPH_FUNCTIONS__


/*
 graph node struct definition
 */
typedef struct g_node{
	int value;
    struct g_node *next;
}graph_node;

/*
 * graph struct definition
 */
typedef struct g{
	int num_nodes;
	graph_node **nodes;
}graph;


graph *graph_init(int nodes); // DONE
graph_node *create_node(int new_value); // DONE
void graph_add_node(int node_index, int new_val);

#endif