#include <stdio.h>
#include <stdlib.h>
// Basic struct of Tree 
struct node 
{ 
    int val; 
    struct node *left, *right; 
}; 
// Function to create a new Node
struct node* newNode(int item) 
{
    struct node* temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
// A sample C function to check if a given node exists in a binary search tree or not
int search(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){
        // checking condition and passing right subtree & recusing 
        if (value > root->val) 
            root = root->right; 
        // checking condition and passing left subtree & recusing 
        else if (value < root->val) 
            root = root->left; 
        else
            return 1; // if the value is found return 1 
    } 
    return 0; 
} 
int main() 
{ 
    /*Root is created first*/
    struct node* root = newNode(21);
    root->left = newNode(16);
    root->right = newNode(25);
    root->left->left = newNode(10);
    root->left->right = newNode(18);
    root->right->left = newNode(22);
    root->right->right = newNode(28);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(12);
    int item = 10;
    // Function to find item in the tree
    int found = search(root,item);
    if(found)
        printf("%d value is found in the tree",item);
    else
        printf("%d value not found",item);
    return 0; 
}
