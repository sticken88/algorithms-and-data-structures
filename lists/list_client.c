#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void){

  list_node *head, *tail;
  queue_t *queue;
  stack_t *stack;

  // initialize pointers
  head = NULL;
  tail = NULL;

  int i;

  queue = queue_create();
  stack = stack_create();

  for(i=0; i<10; i++){
    //insert_node_circular(&head, &tail, i);
    enqueue(&queue, i);
    push(&stack, i);
  }

  //stack_print(stack);
  stack_destroy(&stack);

  /*printf("Number of nodes: %d \n", stack->nodes);

  while(stack->nodes){
     printf("Popped element: %d\n", pop(&stack));
  }

  printf("Number of nodes: %d \n", stack->nodes);*/

  //printf("Queue nodes: %d\n", queue->nodes);

  //queue_print(queue);

  /*printf("Now extract from the queue..\n");
  while(queue->nodes){
    //printf("number of nodes: %d\n", queue->nodes);
     list_node *node = dequeue(&queue);
     printf("%d ", node->value);
  }
  printf("\n");*/

  //print_circular_list(head, tail);
  //reverse_list(&head, &tail);
  //print_list(head);

  return (0);
}