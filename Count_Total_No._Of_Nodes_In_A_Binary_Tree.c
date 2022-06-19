/*
Problem Solution
1. In order to count the number of nodes in a tree we just need to traverse the whole tree once. We can use any of the traversal techniques to count the number of nodes.
2. We have to take a count variable and initialize it with 0 and for each node which we traverse we just have to increase the value of count.
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
static int count = 0;
int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}
/*
 * Main Function
 */
int main()
{
    /* Creating first Tree. */
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
    /* Sample Tree 1:
     *                25
     *             /    \
     *            27     19
     *           / \     / \
     *         17  91   13 55
     */
    printf("Number of nodes in tree 1 = %d ",countnodes(newnode));
    printf("\n");
    count = 0;
 
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
    printf("Number of nodes in tree 2 = %d ",countnodes(node));
    printf("\n");
    count = 0;
 
    /* Creating third Tree. */
    struct node *root = createnode(15);
    /* Sample Tree 3- Tree having just one root node.
     *              15
     */
    printf("Number of nodes in tree 3 = %d",countnodes(root));
    return 0;
}
/*
1. createnode(key);
This function helps to create a new node by allocating it a memory dynamically. It has just one parameter which is “key” which assigns value to the node thereby creating a fresh node having left and right child as “NULL”.

2. countnodes(struct node *root);
In this function we have traversed the left and right subtree and increased the count variable which counts the total number of nodes present in the left and the right subtree. The traversal technique which we have used here is inorder traversal of a tree, by first passing root->left then instead of printing the root->data as a next step of inorder traversal we increase the count variable and then we have passed the root->right to traverse the right subtree and count the total number of nodes present in the right subtree.

Runtime Test Cases
Number of nodes in tree 1 = 7
Number of nodes in tree 2 = 5
Number of nodes in tree 3 = 1
*/
