#include<stdio.h>
#include<stdlib.h>
struct node{
	int item;
	struct node *left;//to represent left subtree
	struct node *right;//to represent right subtree
};
//Inorder Traversal
void inorder(struct node *root){
	if(root == NULL)
	   return;
	inorder(root->left);
	printf(" %d ",root->item);
	inorder(root->right);
}
//Preorder Traversal
void preorder(struct node *root){
	if(root == NULL)
	   return;
	printf(" %d ",root->item);
	preorder(root->left);
	preorder(root->right);
}
//Postorder Traversal
void postorder(struct node *root){
	if(root == NULL)
	   return;
	postorder(root->left);
	postorder(root->right);
	printf(" %d ",root->item);
}
//create a new node
struct node *createnode(item){
	struct node *newnode = malloc(sizeof(struct node));
	newnode->item=item;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
//insert a node at the left
struct node *insertatleft(struct node *root,int item){
	root->left=createnode(item);
	return root->left;
}
//insert node at the right
struct node *insertatright(struct node *root,int item){
	root->right=createnode(item);
	return root->right;
}
int main(){
	struct node *root=createnode(2);
	insertatleft(root,5);
	insertatright(root,6);
	insertatleft(root->left,9);
	insertatright(root->left,4);
	printf("Inorder Traversal: ");
	inorder(root);
	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);
}
