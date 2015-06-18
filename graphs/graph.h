#ifndef __GRAPH_FUNCTIONS__
#define __GRAPH_FUNCTIONS__


/*
 Linked list struct node definition
 */
typedef struct g_node{
	float value;
    struct g_node *next;
}graph_node;


graph_node *create_node(float new_value);

#endif