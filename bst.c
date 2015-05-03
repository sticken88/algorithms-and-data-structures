#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "bst.h"


/** \brief Create a new generic BST node
 *
 * It allcoates memory for a new node and initializes its content with the parameter
 *
 * @param data: int holding the value to copy
 * @return new_node: bst_node pointer to the new node
 *
 */
bst_node *create_node(int data)
{
   bst_node *new_node;

   new_node = (bst_node *)malloc(sizeof(bst_node));
   // check the result of the memory allocation
   if(new_node == NULL){
     printf("Error while trying to allocate memory for a new node..\n");
     printf("[Error]: %s\n", strerror(errno));
     exit(0);
   }

   // everything is ok, copy the data and initialize pointers
   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;

   return new_node;
}


/** \brief Search for a node inside the BST
 *
 * Searches for a node inside the BST based on the requested key
 *
 * @param node: bst_node pointer to the node starting from we want to search
 * @param data: int holding the value to look for
 * @return bst_node pointer to the node which has been found
 *
 */
bst_node *search_data(bst_node *node, int data)
{
   // no matches
   if(node == NULL){
     return NULL;
   }

   // found it
   if(node->data == data){
     return node;
   }

   // recursively search on the left subtree
   if(data < node->data){
     return search_data(node->left, data);
   }

   // recursively search on the right subtree
   if(data > node->data){
     return search_data(node->right, data);
   }
}


/** \brief Insert a new node inside the BST
 *
 * It creates a new node and insert it inside the BST
 *
 * @param node: bst_node pointer to the node starting from we want to search to insert the new node
 * @param data: int holding the value to insert
 * @return node: the root of the tree
 *
 */
bst_node *insert(bst_node *node, int data)
{
   // no matches, insert it
   if(node == NULL){
      return create_node(data);
   }

   // recursively visit the left subtree
   if(data < node->data){
      //printf("Data: %d, new data: %d..\n", node->data, data);
      node->left = insert(node->left, data);
   }

   // recursively visit the right subtree
   if(data > node->data){
    //printf("Data: %d, new data: %d..\n", node->data, data);
      node->right = insert(node->right, data);      
   }

   // it returns the root eventually
   return node;
}


/** \brief Search the node containing the maximum value in a (sub)tree
 *
 * Search the node holding the maximum value inside a (sub)tree. Useful when 
 * implementing functions that return predecessor and successor.
 *
 * @param node: the node where to start looking for the maximum
 * @return max_node: bst_node pointer to the node holding the maximum
 *
 */
bst_node *get_maximum(bst_node *node)
{
   //we cannot go further anymore
   if(node->right == NULL){
      return node;
   }
   // go further
   return get_maximum(node->right);
}


/** \brief Search the node containing the minimum value in a (sub)tree
 *
 * Search the node holding the minimum value inside a (sub)tree. Useful when 
 * implementing functions that return predecessor and successor.
 *
 * @param node: the node where to start looking for the minimum
 * @return min_node: bst_node pointer to the node holding the minimum
 *
 */
bst_node *get_minimum(bst_node *node)
{
   //we cannot go further anymore
   if(node->left == NULL){
      return node;
   }
   // go further
   return get_minimum(node->left);
}


/** \brief Look for the in-order predecessor
 *
 * Look for the in-order predecessor of a given node.
 * The in-order predecessor of a node is defined as the right most child (the maximum) in the
 * left subtree. If the node doesn't have any child then the predecessor is defined as the first ancestor
 * whose value is lower than the one in the node we want to find the predecessor of.
 *
 * @param data: the key of the node whose in-order predecessor we are looking for
 * @return predecessor: bst_node pointer to the predecessornode
 *
 */
bst_node *in_order_predecessor(bst_node *node, int data)
{
   if(node == NULL){
     return NULL;
   }

   // found the node, look for its predecessor
   if(data == node->data){
      // if null the node hasn't a left subtree: the predecessor is an ancestor
      if(node->left == NULL){          
         return NULL;
      }
      // the predecessor is the maximum inside the left (sub)tree
      return get_maximum(node->left);
   }

   // recursively visit the left subtree
   if(data < node->data){
      return in_order_predecessor(node->left, data);
   }

   // recursively visit the right subtree
   if(data > node->data){
      bst_node *predecessor = in_order_predecessor(node->right, data);
      if(predecessor == NULL){
         predecessor = node;
      }
      return predecessor;
   }
}


/** \brief Look for the in-order successor
 *
 * Look for the in-order successor of a given node.
 * The in-order successor of a node is defined as the left most child (the minimum) in the
 * right subtree. If the node doesn't have any child, the successor is defined as the first ancestor 
 * whose value is greater than the one in the node we want to find the successor of.
 *
 * @param data: the key of the node whose in-order successor we are looking for
 * @return successor: bst_node pointer to the successor
 *
 */
bst_node *in_order_successor(bst_node *node, int data)
{
   if(node == NULL){
      return NULL;
   }

   // found it, look for the successor
   if(data == node->data){
      // the node doesn't have right children: the successor is an ancestor
      if(node->right == NULL){
         return NULL;
      }
      // otherwise we look for the minimum
      return get_minimum(node->right);
   }
   // visit the left (sub)tree
   if(data < node->data){
      bst_node *successor = in_order_successor(node->left, data);
      if(successor == NULL){
         // then the current node is the successor
         successor = node;
      }
      return successor;
   }

   // visit the right (sub)tree
   if(data > node->data){
      return in_order_successor(node->right, data);
   }
}


/** \brief Print the BST
 *
 * Prints the BST in-order
 *
 * @param node: the current note we want to print
 *
 */
void bst_print(bst_node *node, int level){
   if(node == NULL){
      return;
   }
   int i;
   bst_print(node->left, level+1);
   for(i=0; i<level; i++){
      printf(" ");
   }
   printf("[Level %d]: %d\n", level, node->data);
   bst_print(node->right, level+1);

}


/** \brief Print the predecessors of the entire tree
 *
 * It traverse the tree and compute the in_order predecessor for every node in the tree
 *
 * @param node: the current note we want to compute the in_order predecessor of
 *
 */
void get_predecessors(bst_node *root, bst_node *node)
{
   // doesn't make sense to recurr here
   if(node->left != NULL){
      get_predecessors(root, node->left);
   }

   bst_node *predecessor = in_order_predecessor(root, node->data);
   if(predecessor == NULL){
      printf("Node with value %d doesn't have any predecessor..\n", node->data);
   }else{
      printf("Node with value %d has predecessor with value %d..\n", node->data, predecessor->data);
   }

   // doesn't make sense to recurr here
   if(node->right != NULL){
      get_predecessors(root, node->right);
   }
}


/*void get_predecessors(bst_node *node)
{
  
}*/