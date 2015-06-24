#ifndef __LIST_FUNCTIONS__
#define __LIST_FUNCTIONS__


/*
 * Linked list struct node definition
 */
typedef struct l_node{
	int value;
    struct l_node *next;
    struct l_node *previous;
}list_node;


/*
 * Queue structure definition
 */
typedef struct q{
	list_node *head;
	list_node *tail;
	int nodes;
}queue_t;


/*
 * Stack structure definition
 */
typedef struct s{
	list_node *head;
	int nodes;
}stack_t;


list_node *create_node(int new_value); // DONE
void insert_node_head(list_node **head, list_node **tail, int new_value); // DONE
void insert_node_tail(list_node **head, list_node **tail, int new_value); // DONE
void insert_node_circular(list_node **head, list_node **tail, int new_value);
void delete_node(list_node **head, int value);
void reverse_list(list_node **head, list_node **tail); // DONE
void sort_list(list_node **node);
void print_list(list_node *node); // DONE
void print_circular_list(list_node *node, list_node *tail);
void free_list(list_node **node);

/*
 * Queue function signatures
 */
queue_t *queue_create(void); // DONE
void enqueue(queue_t **queue, int new_value); // DONE
list_node *dequeue(queue_t **queue); // DONE
void queue_print(queue_t *queue); // DONE
void queue_destroy(queue_t *queue);


/*
 * Stack function signatures
 */
stack_t *stack_create(void);
void push(stack_t **stack, int new_value);
int pop(stack_t **stack);
void stack_print(stack_t *stack);
void stack_destroy(stack_t *stack);

#endif