//FINDING MAXIMUM ELEMENT IN A BINARY TREE WITHOUT RECURSION.
/*
The property of level order traversal is that it passes through each element of the binary tree. 
Utilizing this property we can keep a track of the maximum element encountered in complete traversal. 
Then simply return the element. 
Here is an implementation to find the maximum element without using recursion.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
#include<stdio.h>
#define MIN -65535
int findMaxInTreeNonRecursive(struct binaryTreeNode * root)
{
    // Initialize max with a very less value;
    int max = MIN;
 
    // Level Order Traversal
    struct binaryTreeNode * temp = NULL;
    struct queue * Q = NULL;
    if(root == NULL)
        return;
 
    Q = enQueue(Q, root);
 
    while(!isQueueEmpty(Q))
    {
        temp = Q -> front -> data;
 
        Q = deQueue(Q);
 
        // Find the max value
        if(temp -> data > max)
            max = temp -> data;
 
        if(temp -> left)
            Q = enQueue(Q, temp -> left);
        if(temp -> right)
            Q = enQueue(Q, temp -> right);
    }
    free(Q);
 
    return max;
}
Time Complexity:- O(n)
Space Complexity:- O(n)
*/
#include<stdio.h>
#define MIN -65535

struct binaryTreeNode{
	int data;
	struct binaryTreeNode * left;
	struct binaryTreeNode * right;
};

struct node
{
	struct binaryTreeNode * data;
	struct node * next;
};

struct queue
{
	struct node * front;
	struct node * rear;
};

struct queue * enQueue(struct queue * q, struct binaryTreeNode * num)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = num;
	temp -> next = NULL;
	if(q == NULL)
	{
		q = (struct queue*)malloc(sizeof(struct queue));		
		q -> front = temp;
	}
	else
		q -> rear -> next = temp;
	q -> rear = temp;
	//Code obtained from http://www.studyalgorithms,com
	//Feel free to copy but please acknowledge the site wherever possible
	return q;
}

struct queue * deQueue(struct queue * q)
{
	struct node * temp = q->front;
	q -> front = q->front->next;
	free(temp);
	if(q->front == NULL)
		return NULL;
	else
		return q;
}

int isQueueEmpty(struct queue * q)
{
	if(q)
		return 0;
	else
		return 1;
}

int findMaxInTree(struct binaryTreeNode * root)
{
	// A variable for root value
	int root_val;
	
	// Variable to store values in left and right tree
	int left, right;
	
	// Initialize it with a minimum value
	int max = MIN;
	
	if(root != NULL)
	{
		// Get the root value
		root_val = root -> data;
		
		// Find the maximum value in left sub-tree
		left = findMaxInTree(root -> left);
		
		// Find the maximum value in right sub-tree
		right = findMaxInTree(root -> right);
		
		// Now find the largest of 3 values
		// Find which is big among left and right
		if(left > right)
			max = left;
		else
			max = right;
		
		// Compare the max with root value
		if(root_val > max)
			max = root_val;
	}
	
	return max;
}

int findMaxInTreeNonRecursive(struct binaryTreeNode * root)
{
	// Initialize max with a very less value;
	int max = MIN;
	
	// Level Order Traversal
	struct binaryTreeNode * temp = NULL;
	struct queue * Q = NULL;
	if(root == NULL)
		return;
		
	Q = enQueue(Q, root);
	
	while(!isQueueEmpty(Q))
	{
		temp = Q -> front -> data;
		
		Q = deQueue(Q);

		// Find the max value
		if(temp -> data > max)
			max = temp -> data;
		
		if(temp -> left)
			Q = enQueue(Q, temp -> left);
		if(temp -> right)
			Q = enQueue(Q, temp -> right);
	}
	free(Q);
	
	return max;
}

// Test the above functions
int main(void)
{
	// Initialize the tree
	struct binaryTreeNode * root = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	root-> data = 1;
	struct binaryTreeNode * l = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	l -> data = 2;
	struct binaryTreeNode * ll = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	ll -> data = 4;
	ll -> left = ll -> right = NULL;
	struct binaryTreeNode * lr = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	lr -> data = 5;
	lr -> left = lr -> right = NULL;
	l -> left = ll;
	l -> right = lr;
	struct binaryTreeNode * r = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	r -> data = 3;
	struct binaryTreeNode * rl = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	rl -> data = 6;
	rl -> left = rl -> right = NULL;
	struct binaryTreeNode * rr = (struct binaryTreeNode *)malloc(sizeof(struct binaryTreeNode));
	rr -> data = 7;
	rr -> left = rr -> right = NULL;
	r -> left = rl;
	r -> right = rr;
	root -> left = l;
	root -> right = r;
	
	// Non-recursive version
	printf("max = %d",findMaxInTree(root));
	
	// Recursive version
	printf("max = %d",findMaxInTreeNonRecursive(root));

	return 0;
}
