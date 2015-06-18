#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void){

  list_node *head, *tail;

  // initialize pointers
  head = NULL;
  tail = NULL;

  int i;

  for(i=0; i<10; i++){
    insert_node_circular(&head, &tail, i);
  }

  printf("%f\n", tail->value);
  print_circular_list(head, tail);
  //reverse_list(&head, &tail);
  //print_list(head);

  return (0);
}