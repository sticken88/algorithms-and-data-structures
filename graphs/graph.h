#ifndef __GRAPH_FUNCTIONS__
#define __GRAPH_FUNCTIONS__


/*
 * graph node struct definition
 */
typedef struct g_node{
	int value;
	int visited;
    struct g_node *next;
}graph_node;


/*
 * graph struct definition
 */
typedef struct g{
	int num_nodes;
	graph_node **nodes;
	queue_t *queue;
}graph;


graph *graph_init(int nodes); // DONE
graph_node *create_graph_node(int new_value); // DONE
//list_node *create_list_node(int new_value); // DONE
graph *graph_add_node(graph *gr, int node_index, int new_value); // DONE

void depth_first_search(graph *gr, int node_index);
void breadth_first_search(graph *gr);
void dijkstra(graph *gr);
void bellman_ford(graph *gr);

void print_graph(graph *gr);

#endif