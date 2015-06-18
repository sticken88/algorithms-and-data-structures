#ifndef __LIST_FUNCTIONS__
#define __LIST_FUNCTIONS__


/*
 Linked list struct node definition
 */
typedef struct l_node{
	float value;
    struct l_node *next;
}list_node;


list_node *create_node(float new_value); // DONE
void insert_node_head(list_node **head, list_node **tail, float new_value); // DONE
void insert_node_tail(list_node **head, list_node **tail, float new_value); // DONE
void insert_node_circular(list_node **head, list_node **tail, float new_value);
void delete_node(list_node **head, float value);
void reverse_list(list_node **head, list_node **tail); // DONE
void sort_list(list_node **node);
void print_list(list_node *node); // DONE
void print_circular_list(list_node *node, list_node *tail);
void free_list(list_node **node);

#endif