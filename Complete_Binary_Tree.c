/*A complete binary tree is a binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from the left.
A complete binary tree is just like a full binary tree, but with two major differences.
All the leaf elements must lean towards the left.
The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.*/
/*
How a Complete Binary Tree is Created?
Select the first element of the list to be the root node. (no. of elements on level-I: 1)
Put the second element as a left child of the root node and the third element as the right child. (no. of elements on level-II: 2)
Put the next two elements as children of the left node of the second level. 
Again, put the next two elements as children of the right node of the second level (no. of elements on level-III: 4) elements).
Keep repeating until you reach the last element.
*/
/*Relationship between array indexes and tree element
A complete binary tree has an interesting property that we can use to find the children and parents of any node.

If the index of any element in the array is i, the element in the index 2i+1 will become the left child and 
element in 2i+2 index will become the right child. Also, the parent of any element at index i is given by the lower bound of (i-1)/2.
*/
// Checking if a binary tree is a complete binary tree in C
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int key;
  struct Node *left, *right;
};
// Node creation
struct Node *newNode(char k) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = k;
  node->right = node->left = NULL;
  return node;
}
// Count the number of nodes
int countNumNodes(struct Node *root) {
  if (root == NULL)
    return (0);
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}
// Check if the tree is a complete binary tree
bool checkComplete(struct Node *root, int index, int numberNodes) {
  // Check if the tree is complete
  if (root == NULL)
    return true;
  if (index >= numberNodes)
    return false;
  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}
int main() {
  struct Node *root = NULL;
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  int node_count = countNumNodes(root);
  int index = 0;
  if (checkComplete(root, index, node_count))
    printf("The tree is a complete binary tree\n");
  else
    printf("The tree is not a complete binary tree\n");
}
