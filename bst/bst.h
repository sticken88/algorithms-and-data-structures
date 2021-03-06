#ifndef __BST_FUNCTIONS__
#define __BST_FUNCTIONS__

/*
 * BST node struct definition
 */
typedef struct t_node
{
   int data;
   struct t_node *left;
   struct t_node *right;
}bst_node;

// Functions prototypes
bst_node *create_node(int data); // DONE
bst_node *search_data(bst_node *node, int data); //DONE
bst_node *get_maximum(bst_node *node); // DONE
bst_node *get_minimum(bst_node *node); // DONE
bst_node *insert(bst_node *node, int data); // DONE
bst_node *in_order_predecessor(bst_node *node, int data); // DONE
bst_node *in_order_successor(bst_node *node, int data); // DONE
void get_predecessors(bst_node *root, bst_node *node); // DONE
void get_successors(bst_node *root, bst_node *node); // DONE
int *delete(int data);
void bst_print(bst_node *node, int level); // DONE

#endif
