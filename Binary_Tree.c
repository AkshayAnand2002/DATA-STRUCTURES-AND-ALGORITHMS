//FULL BINARY TREE - EVERY PARENT OR INTERNAL NODE HAS 0 OR 2 CHILDREN.
//PERFECT BINARY TREE - EVERY INTERNAL NODE HAS EXACTLY 2 CHILD NODES AND ALL LEAF NODES ARE AT SAME LEVEL.
//COMPLETE BINARY TREE - EVERY LEVEL MUST BE COMPLETELY FULLED. ALL LEAF ELEMENTS MUST LEAN TOWARDS THE LEFT. THE LAST LEAF ELEMENT MIGHT
//NOT HAVE RIGHT SIBLING I.E. A COMPLETE BINARY TREE DOES NOT HAVE TO BE A FULL BINARY TREE.
// Tree traversal in C
#include <stdio.h>
#include <stdlib.h>
struct node {
  int item;
  struct node* left;
  struct node* right;
};
// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}
// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}
// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}
// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}
int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 0);
  printf("Inorder traversal \n");
  inorderTraversal(root);
  printf("\nPreorder traversal \n");
  preorderTraversal(root);
  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}
