/*
1)Reverse the two number lists.
2)Simulate addition on nodes one by one. Append each node before the already calculated sum nodes.( You will better understand this step in code)
3)In the end we will get the final answer and we can return the head node.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
// Function to create a new node with given data
Node* newNode(int data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}
/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = newNode(new_data);
	/* link the old list off the new node */
	new_node->next = (*head_ref);
	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
void printList(Node* n)
{
	while (n) {
		printf("%d ", n->data);
		n = n->next;
	}
	printf("\n");
}
Node* reverseList(Node* list)
{
	Node *prev = NULL, *cur = list, *next = NULL;
	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
Node* addTwoLists(Node* first, Node* second)
{
	// code here
	first = reverseList(first);
	second = reverseList(second);
	int carry = 0;
	Node *head = NULL, *prev = NULL;
	Node* sum = NULL;
	while (first != NULL || second != NULL || carry == 1)
	// if any one of these is left we are stil left with
	// addition
	{
		int newVal = carry;
		if (first)
			newVal += first->data;
		if (second)
			newVal += second->data;
		// to be used in the next node calculation
		carry = newVal / 10;
		newVal = newVal % 10;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = newVal;
		// appending in the beginning of the final ans list,
		// this way we do not have to reverse in the end
		newNode->next = sum;
		sum = newNode;
		// initialising nodes for next iteration
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}
	return sum;
}
int main()
{
	Node* first = NULL;
	Node* second = NULL;
	push(&first, 9);
	push(&first, 8);
	push(&first, 7);
	push(&second, 1);
	push(&second, 2);
	push(&second, 3);
	Node* ans = addTwoLists(first, second);
	printf("Sum is : ");
	printList(ans);
	return 0;
}
