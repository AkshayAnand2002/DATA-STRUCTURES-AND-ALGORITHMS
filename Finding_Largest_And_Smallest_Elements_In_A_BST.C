//FINDING LARGEST AND SMALLEST ELEMENTS IN A BST.
/*
Problem Solution
1. We can easily find the smallest and the largest value in a BST using it’s properties and inorder traversal.
2. Inorder traversal of a BST gives a sequence of nodes arranged in ascending order of their values because in a BST 
the left child is always smaller and the right child is always greater than it’s parent.
3. So for the smallest value we need to find the extreme left or the leftmost node in leftsubtree and for the largest 
value we need to find the extreme right or the rightmost node in rightsubtree.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *left, *right;
};
struct node *createnode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %d ",root->info);
        inorder(root->right);
    }
}
void smallest(struct node *root)
{
    while(root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    printf("\nSmallest value is %d\n", root->info);
}
void largest(struct node *root)
{
    while (root != NULL && root->right != NULL)
    {
        root = root->right;
    }
    printf("\nLargest value is %d", root->info);
}
/*
 * Main Function
 */
int main()
{
    /* Creating first Tree. */
    struct node *newnode = createnode(25);
    newnode->left = createnode(17);
    newnode->right = createnode(35);
    newnode->left->left = createnode(13);
    newnode->left->right = createnode(19);
    newnode->right->left = createnode(27);
    newnode->right->right = createnode(55);
    /* Sample Tree 1:
     *               25
     *             /    \
     *            17     35
     *           / \     / \
     *         13  19   27 55
     */
    printf("Inorder traversal of tree 1 :");
    inorder(newnode);
    largest(newnode);
    smallest(newnode);
 
    /* Creating second Tree. */
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
    /* Sample Tree 2:   Right Skewed Tree (Unbalanced).
     *               1
     *                \
     *                 2
     *                  \
     *                   3
     *                    \
     *                     4
     *                      \
     *                       5
     */
    printf("\nInorder traversal of tree 2 :");
    inorder(node);
    largest(node);
    smallest(node);
 
    /* Creating third Tree. */
    struct node *root = createnode(15);
    /* Sample Tree 3- Tree having just one root node.
     *              15
     */
    printf("\nInorder traversal of tree 3 :");
    inorder(root);
    largest(root);
    smallest(root);
    return 0;
}
/*
Program Explanation
Program contains four important functions.

1. createnode(key);
This function helps to create a new node by allocating it a memory dynamically. It has just one parameter which is “key” which assigns value to the node thereby creating a fresh node having left and right child as “NULL”.

2. inorder(struct node *root);
This function helps to traverse the whole tree. First we recursively traverse the left subtree, then print the value of the node and then we recursively traverse the right subtree.

3. largest(struct node *root)
(a). Inorder traversal of a BST gives a sequence of nodes arranged in increasing order of their values because in BST the left child of a node is always smaller and the right child of a node is always greater than it’s parent.
(b). So the largest node in a BST will be the last node in the right subtree.
(c). That is what we are doing in largest() function, we are making the root = root->right so that we can reach the extreme right node or the last node in a right subtree.
(d). The last node in a right subtree will not have any child, therefore the while condition is going to terminate as root->right will become = NULL.

4. smallest(struct node *root)
(a). The smallest node in a Binary Search Tree will be the leftmost node in leftsubtree, so we keep on traversing the leftsubtree tree till we reach the leftmost node (root = root->left), and when we encounter the leftmost node we print it’s value and terminate the loop as root->left will become NULL.

Runtime Test Cases
Inorder traversal of tree 1 : 13  17  19  25  27  35  55
Largest value is 55
Smallest value is 13
 
Inorder traversal of tree 2 : 1  2  3  4  5
Largest value is 5
Smallest value is 1
 
Inorder traversal of tree 3 : 15
Largest value is 15
Smallest value is 15
*/
