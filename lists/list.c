#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/*
 * Function that creates a new node to be inserted into tjhe list
 * @param: new_value, a float containing the new value that must be inserted
 * @return: the new created node, if malloc is successful
 */
list_node *create_node(float new_value){

	// declare the new pointers
	list_node *new_node;
	// allocate memory
	new_node = (list_node *)malloc(sizeof(*new_node));
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


/*
 * Function that inserts a new value inside the list.
 * It creates a new node and inserts it at the beginning of the list
 * @param: head, the pointer to the beginning of the list
 * @param: tail, the pointer to the end of the list
 * @param: new_value, a float containing the new value that must be inserted
 */
void insert_node_head(list_node **head, list_node **tail, float new_value){

	// create the new node
	list_node *new_node = create_node(new_value);

	// insert it into the list
	// it's the very first node of the list, so the tail must be initialized properly
	if(*head == NULL){
		*tail = new_node;
	}

	new_node->next = *head;
	*head = new_node;
}


/*
 * Function that inserts a new value inside the list.
 * It creates a new node and inserts it at the end of the list
 * @param: tail, the pointer to the end of the list
 * @param: new_value, a float containing the new value that must be inserted
 */
void insert_node_tail(list_node **head, list_node **tail, float new_value){

	// create the new node
	list_node *new_node = create_node(new_value);

    // check if this is the first node of the list
    if(*tail == NULL){
    	*head = new_node;
    }else{
	    (*tail)->next = new_node;
    }

    // this line it's necessary in both if and else
    *tail = new_node;
}


/*
 * Function used to reverse a list
 * @param: head, pointer to the beginning of the list
 * @param: tail, pointer to the end of the list
 */
void reverse_list(list_node **head, list_node **tail){

	if(*head == NULL){
		printf("Empty list, nothing to revert..\n");
	}else{
		// temporary pointers necessary to reverse the list
		list_node *tmp, *fh;
		// the new tail is the old head
		*tail = *head;
		fh = (*head)->next;
		(*head)->next = NULL;

		while(fh != NULL){
		  tmp = fh->next;
		  fh->next = *head;
		  *head = fh;
		  fh = tmp;
		}
    }
}


/*
 * Function that prints out the content of the list
 */
void print_list(list_node *node){
	if(node == NULL){
		printf("Empty list, nothing to print..\n");
	}else{
		while(node != NULL){
			printf("%f\n", node->value);
			node = node->next;
		}
		printf("\n");
    }
}

/*
void insert_node();
void delete_node();
void reverse_list(list_node *node);
void sort_list(list_node *node);
void print_list(list_node *head);*/
