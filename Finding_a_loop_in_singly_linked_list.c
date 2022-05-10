/*Algorithm to detect cycle in a linked list--
Let "head" be the head pointer of given linked list.
Let, "slow" and "fast" be two node pointers pointing to the head node of linked list.
In every iteration, the "slow" pointer moves ahead by one node(slow = slow->next;) whereas "fast" pointer moves two nodes at a time(fast = fast->next->next;).
If linked list contains a loop, "slow" and "fast" pointers will eventually meet at the same node, thus indicating that the linked list contains a loop.
If pointers do not meet then linked list doesn’t have loop.
This algorithm is known as Floyd’s Cycle-Finding Algorithm.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
void initialize(){
	head=NULL;
}
void insertatbeginning(int num){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=head;
	head=newnode;
	printf("INSERTED ELEMENT: %d\n",num);
}
void findloop(struct node *head){
	struct node *slow,*fast;
	slow=fast=head;//slow and fast initially point to head.
	while(slow && fast && fast->next){
		//slow moves ahead by 1 node and fast moves ahead 2 nodes at a time.
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast){
			printf("LINKED LIST CONTAINS A LOOP.\n");
			return;
		}	
	}
	printf("NO LOOP IN THE LINKED LIST.\n");
}
void printlinkedlist(struct node *nodeptr){
	while(nodeptr != NULL){
		printf("%d",nodeptr->data);
		nodeptr=nodeptr->next;
		if(nodeptr != NULL){
			printf("->");
		}
	}
}
int main(){
	initialize();
	insertatbeginning(8);
	insertatbeginning(3);
	insertatbeginning(2);
	insertatbeginning(7);
	insertatbeginning(9);
	//below creating a loop in the linked list by setting next pointer of last node to second node from head.
	head->next->next->next->next->next=head->next;//this line makes loop in the linked list.
	findloop(head);
	return 0;
}
