#include <stdio.h>
#include <errno.h>

#include "bst.h"


/** \brief Create a new BST root node
 *
 * It calls create_node to create the first node of the BST
 *
 * @param data: int holding the value to copy
 * @return BST root node
 *
 */
bst_node *create_bst(int data)
{
   return create_node(data);
}

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

   new_node = (bst_node *)calloc(sizeof(bst_node));
   // check the result of the memory allocation
   if(new_node == NULL){
     print("Error while trying to allocate memory for a new node..\n");
     print("[Error]: %s\n", strerror(errno));
     exit(0);
   }

   new_node->data = (int *)calloc(sizeof(int));
   // check the result of the memory allocation
   if(new_node->data == NULL){
     print("Error while trying to allocate memory for the data field of a new node..\n");
     print("[Error]: %s\n", strerror(errno));
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
 *
 */
void insert(bst_node *node, int data)
{
   // no matches, insert it
   if(node == NULL){
     node = create_node(data);
   }

   // recursively visit the left subtree
   if(data < node->data){
      insert(node->left, data);
   }

   // recursively visit the right subtree
   if(data > node->data){
      insert(node->right, data);
   }
}


/** \brief Look for the in-order predecessor
 *
 * Look for the in-order predecessor of a given node.
 * The in-order predecessor of a node is defined as the right most child in the
 * left subtree
 *
 * @param data: the key of the node whose in-order predecessor we are looking for
 * @return node: bst_node pointer to the node
 *
 */
bst_node *in_order_predecessor(bst_node *node, int data)
{
  bst_node *predecessor = NULL;
   
   if(node == NULL){
     return NULL;
   }

   // found the node, look for its predecessor
   if(data == node->data){
      bst_node *left_root = node->left;
      // if null check what to do
      if(left_root == NULL){
      }

      // loop until we reach the last node
      while(left_root->right->right != NULL){
        predecessor = left_root->right;
        // move the pointer
	left_root = left_root->right;
      }    
      // return the node
      return predecessor;
   }

   // recursively visit the left subtree
   if(data < node->data){
      return in_order_predecessor(node->left, data);
   }

   // recursively visit the right subtree
   if(data > node->data){
      return in_order_predecessor(node->right, data);
   }
}
