#include <stdio.h>
#include <stdlib.h>

#include "list.h"


/*
 * Function that creates a new node to be inserted into tjhe list
 * @param: new_value, a int containing the new value that must be inserted
 * @return: the new created node, if malloc is successful
 */
list_node *create_node(int new_value){

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
	new_node->previous = NULL;

	return new_node;
}


/*
 * Function that inserts a new value inside the list.
 * It creates a new node and inserts it at the beginning of the list
 * @param: head, the pointer to the beginning of the list
 * @param: tail, the pointer to the end of the list
 * @param: new_value, a int containing the new value that must be inserted
 */
void insert_node_head(list_node **head, list_node **tail, int new_value){

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
 * @param: head, the pointer to the beginning of the lis
 * @param: tail, the pointer to the end of the list
 * @param: new_value, a int containing the new value that must be inserted
 */
void insert_node_tail(list_node **head, list_node **tail, int new_value){

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
 *
 */
void insert_node_circular(list_node **head, list_node **tail, int new_value){

	list_node *new_node = create_node(new_value);

    /* in this way the tail is properly initialized and the head is initialized after the
    *  if statement
    */
    if(*head == NULL){
    	*tail = new_node;
    }

	new_node->next = *head;
	*head = new_node;
	(*tail)->next = *head;
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
 * @param node: the head of the list that,ust be printed out
 */
void print_list(list_node *node){
	if(node == NULL){
		printf("Empty list, nothing to print..\n");
	}else{
		while(node != NULL){
			printf("%d\n", node->value);
			node = node->next;
		}
		printf("\n");
    }
}


/*
 * Prints out the circular list
 */
void print_circular_list(list_node *node, list_node *tail){
	while(node != tail->next){
		printf("%d\n", node->value);
		node = node->next;
	}
}


/*
 * Queue functions implementation
 */
queue_t *queue_create(void){
    
    // alloc the memory
	queue_t *queue = (queue_t *)malloc(sizeof(*queue));
	// if the queue isn't properly initialized due to memory not available
	if(!queue){
		return queue;
	}

	//initialize the internal fields
	queue->head = NULL;
	queue->tail = NULL;
	queue->nodes = 0;

	return queue;
}


/*
 * Insert a new node inside the queue
 * First of all we create a new node, then we make it point to the current tail.
 * The current tail has to point to the new created node by using the 'previous' link
 * At the end the tail is updated with the new inserted node
 */
void enqueue(queue_t **queue, int new_value){

	// first of all a new node must be created, as usual
	list_node *new_node = create_node(new_value);

    // first node of the queue
	if(!(*queue)->nodes){
		(*queue)->head = new_node;
		(*queue)->tail = new_node;
	}else{
		new_node->next = (*queue)->tail;
		// the old tail must point to the new one thanks to the 'previous' link
		(*queue)->tail->previous = new_node;
    }
	// now we can properly update the tail of the queue
	(*queue)->tail = new_node;
	// update the number of nodes in the queue
	(*queue)->nodes++;
}


/*
 * Remove a node from the queue
 */
int dequeue(queue_t **queue){

	/* check if the queue is empty
	 * if yes, just return NULL
	 */
	if(!(*queue)->nodes){
		printf("Empty queue..\n");
		return (-1);
	}

    int _value;

	if((*queue)->nodes == 1){
		_value = (*queue)->head->value; 
		// free memory (just one time because head == tail in this case)
		free((*queue)->head);
		// set pointer to NULL
		(*queue)->head = (*queue)->tail = NULL;
		(*queue)->nodes--;
		return _value;
	}

	// get the head node and the value
	list_node *_head = (*queue)->head;
	_value = _head->value;
	// update the head	
	(*queue)->head = (*queue)->head->previous; 
	(*queue)->head->next = NULL;
	// update the number of nodes in the queue
	(*queue)->nodes--;

	//free the memory
	free(_head);
	_head = NULL;

	return _value;
}


/*
 * Print the queue
 */
void queue_print(queue_t *queue){
	while(queue->head != NULL){
		printf("%d ", queue->head->value);
		queue->head = queue->head->previous;
	}
	printf("\n");
}

/*
 * It destroys the queue by calling dequeue until the queue is empty
 */
void queue_destroy(queue_t **queue){

	// fictious value
	int _val;
	//loop over the queue and dequeue every value
	while((*queue)->nodes){
		_val = dequeue(queue);
		printf("ESTRATTO: %d\n", _val);
	}
    // finally the queue structure is destroyed
	free(*queue);
	*queue = NULL;

	// print out this achievement :)
	printf("Queue destroyed..\n");
}

/*
 * Stack functions implementation
 */
stack_t *stack_create(void){

	//allocate memory for the new structure
	stack_t *stack = (stack_t *)malloc(sizeof(*stack));
	// if the stack isn't properly initialized due to memory not available
	if(!stack){
		return stack;
	}

	//initialize the internal fields
	stack->head = NULL;
	stack->nodes = 0;

	return stack;
}


/*
 * Pushing a new value on top of the stack
 */
void push(stack_t **stack, int new_value){

	// create the new node to be inserted
	list_node *new_node = create_node(new_value);
	if(!new_node)exit(1);

	// insert it
	new_node->next = (*stack)->head;
	(*stack)->head = new_node;
	(*stack)->nodes++;
}


/*
 * Returns the first element (if any) of the stack
 */
int pop(stack_t **stack){

	//check for the number of nodes
	if(!(*stack)->nodes){
		printf("Empty stack..\n");
		return (-1);
	}else{
		// get the value in the first element
		list_node *node = (*stack)->head;
		int value = node->value;

		//update the head
		(*stack)->head = (*stack)->head->next;
		// decrease the counter
		(*stack)->nodes--;
		//free memory
		free(node);
		node = NULL;

		return value;
	}
}


/*
 * It just prints out the stack content
 */
void stack_print(stack_t *stack){
	while(stack->head){
		printf("[Val]: %d\n", stack->head->value);
		stack->head = stack->head->next;
	}
	printf("\n");
}


/*
 * It frees the memory requested for the entire stack
 * It reuses the pop function until the stack is empty
 */
void stack_destroy(stack_t **stack){

    // it's just a fictious value. We reuse the pop function defined before
    int _val;
    // loop over the stack
    while((*stack)->nodes){
    	_val = pop(stack);    	
    }
    // finally the stack structure is destroyed
	free(*stack);
	*stack = NULL;

	// print out this achievement :)
	printf("Stack destroyed..\n");
}