/*Binary Search Tree is a node-based binary tree data structure which has the following properties:
The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.
Thus, a binary search tree (BST) divides all its sub-trees into two segments; left sub-tree and right sub-tree and can be defined as
left_subtree (keys) <= node (key) <= right_subtree (keys)
Primary operations of a binary search  tree are following.
Search - search an element in a tree.
Insert - insert an element in a tree.
Preorder Traversal - traverse a tree in a preorder manner.
Inorder Traversal - traverse a tree in an inorder manner.
Postorder Traversal - traverse a tree in a postorder manner
Define a node having some data, references to its left and right child nodes.
struct node
{
int data;
struct node *leftChild;
struct node *rightChild;
};
ALGORITHM:
Step 1: Start.
Step 2: Create a Binary Search Tree for N elements.
Step 3: Traverse the tree in inorder.
Step 4: Traverse the tree in preorder
Step 6: Traverse the tree in postorder.
Step 7: Search the given key element in the BST.
Step 8: Delete an element from BST.
Step 9: Stop
*/
#include<stdio.h>
#include<stdlib.h>
struct BST{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST NODE;
NODE *node;
NODE* createtree(NODE *node,int data)
{
if(node == NULL){
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
if(data <(node->data)){
	node->left=createtree(node->left,data);
}
else if(data > node->data){
	node->right = createtree(node->right,data);
}
return node;
}
NODE* search(NODE *node,int data){
	if(node==NULL){
		printf("\nELEMENT NOT FOUND.");
	}
	else if(data < node->data){
		node->left=search(node->left,data);
	}
	else if(data > node->data){
		node->right=search(node->right,data);
	}
	else{
		printf("\nELEMENT FOUND IS : %d.",node->data);
	}
	return node;
}
void inorder(NODE *node){
	if(node != NULL){
		inorder(node->left);
		printf("%d\t",node->data);
		inorder(node->right);
	}
}
void preorder(NODE *node){
	if(node != NULL){
		printf("%d\t",node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(NODE *node){
	if(node != NULL){
		postorder(node->left);
		postorder(node->right);
		printf("%d\t",node->data);
	}
}
NODE* findmin(NODE *node){
	if(node==NULL){
		return NULL;
	}
	if(node->left){
		return findmin(node->left);
	}
	else{
		return node;
	}
}
NODE *del(NODE *node,int data){
	NODE *temp;
	if(node==NULL){
		printf("\nELEMENT NOT FOUND.");
	}
	else if(data<node->data){
		node->left=del(node->left,data);
	}
	else if(data>node->data){
		node->right=del(node->right,data);
	}
	else{
//NOW WE CAN DELETE THIS NODE AND REPLACE IT WITH EITHER MINIMUM ELEMENT IN RIGHT SUBTREE I.E. INORDER SUCCESSOR OR MAXIMUM ELEMENT IN THE LEFT SUBTREE I.E. INORDER 
//PREDECESSOR.
if(node->right && node->left)
{ /* Here we will replace with minimum element in the right sub tree */
temp = findmin(node->right);
node -> data = temp->data;
/* As we replaced it with some other node, we have to delete that node */
node -> right = del(node->right,temp->data);
}
else{
/* If there is only one or zero children then we can directly remove it from the tree and connect its parent to its child */
temp = node;
if(node->left == NULL){
node = node->right;
}
else if(node->right == NULL){
node = node->left;
}
free(temp); /* temp is longer required */
}
}
return node;
}
void main()
{
int data, ch, i, n;
NODE *root=NULL;
while (1)
{
printf("\n1.Insertion in Binary Search Tree");
printf("\n2.Search Element in Binary Search Tree");
printf("\n3.Delete Element in Binary Search Tree");
printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1: printf("\nEnter N value: " );
scanf("%d", &n);
printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");
for(i=0; i<n; i++)
{
scanf("%d", &data);
root=createtree(root, data);
}
break;
case 2: printf("\nEnter the element to search: ");
scanf("%d", &data);
root=search(root, data);
break;
case 3: printf("\nEnter the element to delete: ");
scanf("%d", &data);
root=del(root, data);
break;
case 4: printf("\nInorder Traversal: \n");
inorder(root);
break;
case 5: printf("\nPreorder Traversal: \n");
preorder(root);
break;
case 6: printf("\nPostorder Traversal: \n");
postorder(root);
break;
case 7: exit(0);
default:printf("\nWrong option");
break;
}
}
} 
