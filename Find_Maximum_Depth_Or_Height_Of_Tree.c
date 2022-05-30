/*Given a binary tree, find height of it. Height of empty tree is -1, height of tree with one node is 0 .
Recursively calculate height of left and right subtrees of a node and assign height to the node as max of the heights of two children plus 1.
Algorithm:-
 maxDepth()
1. If tree is empty then return -1
2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree, max depth of right subtree) + 1
     (d) Return max_depth
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
//compute maxdepth of a tree i.e. no. of nodes along the longest path from the root node down to the farthest leaf node.
int maxdepth(struct node* node){
	if(node == NULL){
		return -1;
	}
	else{
		//compute depth of each subtree.
		int ldepth = maxdepth(node->left);
		int rdepth = maxdepth(node->right);
		//use the larger one.
		if(ldepth > rdepth){
			return (ldepth+1);
		}
		else{
			return (rdepth+1);
		}
	}
}
//create new node.
struct node* newnode(int data) {
struct node* node = (struct node *)malloc(sizeof(struct node));
node->data=data;
node->left=NULL;
node->right=NULL;
return(node);
}
int main(){
	struct node* root = newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	printf("HEIGHT OF TREE IS : %d.",maxdepth(root));
	return 0;
}
