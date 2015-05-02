#ifndef __BST_FUNCTIONS__
#define __BST_FUNCTIONS__

/*
 * BST node struct definition
 */
typedef struct node
{
   int *data;
   struct node *left;
   struct node *right;
}bst_node;

// Functions prototypes

bst_node *create_bst(int data); // DONE
bst_node *create_node(int data); // DONE
bst_node *search_data(bst_node *node, int data); //DONE
void insert(bst_node *node, int data); // DONE
int *in_order_predecessor(int data);
int *in_order_successor(int data);
int *delete(int data);
void bst_print(bst_node *node);

#endif
