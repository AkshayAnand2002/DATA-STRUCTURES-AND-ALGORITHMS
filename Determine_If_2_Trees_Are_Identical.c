/*Two trees are identical when they have same data and arrangement of data is also same. 
To identify if two trees are identical, we need to traverse both trees simultaneously, and while traversing we need to compare data and children of the trees. 
Algorithm:-
sameTree(tree1, tree2)
1. If both trees are empty then return 1.
2. Else If both trees are non -empty
     (a) Check data of the root nodes (tree1->data ==  tree2->data)
     (b) Check left subtrees recursively  i.e., call sameTree( 
          tree1->left_subtree, tree2->left_subtree)
     (c) Check right subtrees recursively  i.e., call sameTree( 
          tree1->right_subtree, tree2->right_subtree)
     (d) If a,b and c are true then return 1.
3  Else return 0 (one is empty and other is not)
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
//creating newnode
struct node* newnode(int data){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);
}
//given 2 trees return true if they are structurally identical.
int identicaltrees(struct node* a,struct node* b){
	//both empty trees
	if(a==NULL && b==NULL)
	   return 1;
	//both non-empty then compare them.
	if(a!=NULL && b!=NULL){
		return
		(
		a->data == b->data && 
		identicaltrees(a->left,b->left) &&
		identicaltrees(a->right,b->right)
		);
	}
	//if one tree is empty and other is not empty return false or 0.
	return 0;
}
int main(){
	struct node *root1 = newnode(1);
	struct node *root2 = newnode(1);
	root1->left=newnode(2);
	root1->right=newnode(3);
	root1->left->left=newnode(7);//THIS SHOULD BE 4 FOR THE TREE TO BE IDENTICAL.
	root1->left->right=newnode(5); 
	//now for second tree.
	root2->left=newnode(2);
	root2->right=newnode(3);
	root2->left->left=newnode(4);
	root2->left->right=newnode(5);
	//now checking
	if(identicaltrees(root1,root2)){
		printf("BOTH THE TREES ARE IDENTICAL.");
	} 
	else{
		printf("TREES ARE NOT IDENTICAL.");
	}
	return 0;
}
