/*
Algorithm to find the height of a binary tree using recursion
If the binary tree is empty, then return 0.
Else
Get the maximum height of the left subtree recursively. Function height_of_binary_tree (tree->left-subtree)
Get the maximum height of the right subtree recursively. height_of_binary_tree (tree->right-subtree)
Get the max of maximum heights of left and right subtrees. Add 1 to it for the current node.
max_height = max(max_height of left subtree, maximum_height of right subtree) + 1
Return maximum_height.
*/
// C program to find the height of a binary tree
/*
#include<stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *newNode(int data)
{
struct node *temp = (struct node *) malloc(sizeof(struct node));
temp -> data = data;
temp -> left = NULL;
temp -> right = NULL;
return temp;
};
int height_of_binary_tree(struct node *node)
{
if(node == NULL)
return 0;
else
{
int left_side;
int right_side;
left_side = height_of_binary_tree(node -> left);
right_side = height_of_binary_tree(node -> right);
if(left_side > right_side)
{
return left_side + 1;

}
else
return right_side + 1;
}
}

void insert_node(struct node *root, int n1, int n2, char lr)
{
if(root == NULL)
return;
if(root -> data == n1)
{
switch(lr)
{
case �l� :root -> left = newNode(n2);
break;
case �r� : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root -> left, n1, n2, lr);
insert_node(root -> right, n1, n2, lr);
}
}

void inorder(struct node *root)
{
if(root == NULL)
return;
inorder(root -> left);
printf(�%d �, root -> data);
inorder(root -> right);
}

int main()
{
struct node *root = NULL;
int n;
scanf(�%d�,&n);
while(n�)
{
char lr;
int n1,n2;
scanf(�%d�,&n1);
scanf(�%d�,&n2);
scanf(� %c�,&lr);
if(root == NULL)
{
root = newNode(n1);
switch(lr)
{
case �l� :root -> left = newNode(n2);
break;
case �r� : root -> right = newNode(n2);
break;
}
}
else
{
insert_node(root,n1,n2,lr);
}
}
inorder(root);
printf(�\n�);
printf(�\nHeight of binary tree : %d� , height_of_binary_tree(root));
printf(�\n�);
return 0;
}

*/
