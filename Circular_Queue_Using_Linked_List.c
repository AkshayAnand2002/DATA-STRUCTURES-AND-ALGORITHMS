/*Operations on Circular Queue :
Front : Get the front item from queue.
Rear : Get the last item from queue.
enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position.
Steps:
Create a new node dynamically and insert value into it.
Check if front==NULL, if it is true then front = rear = (newly created node)
If it is false then rear=(newly created node) and rear node always contains the address of the front node.
deQueue() This function is used to delete an element from the circular queue. In a queue, the element is always deleted from front position.
Steps:
Check whether queue is empty or not means front == NULL.
If it is empty then display Queue is empty. If queue is not empty then step 3
Check if (front==rear) if it is true then set front = rear = NULL else move the front forward in queue, update address of front in rear node and return the element.
*/
/*Algorithm for Insertion and deletion operation using linked list in a circular queue
Algorithm_Enqueue---
if (FRONT == NULL)    //  Inserting in an Empty Queue
FRONT = REAR = newNode
end ifelse    
REAR -> next = newNode   //  Inserting after the last element
REAR = newNode 
end else
REAR -> next = FRONT
end Algorithm_Enqueue
--------------------------------------------------------------------------------------
Algorithm_Dequeue---
if(FRONT == NULL) //  Condition for underflow
Print “Queue Underflow”
end Dequeue
end ifelse if(FRONT == REAR) // The queue contains only one node
temp = FRONT -> data
free(temp)
FRONT = FRONT -> next
REAR -> next = FRONT
end ifelse if (FRONT == N - 1)  // If FRONT is the last node
front = 0   // Make FRONT as the first node
end if
end Dequeue
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *f = NULL;
struct node *r = NULL;
void enqueue(int d) //Insert elements in Queue
{
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	if((r==NULL)&&(f==NULL))
	{
		f = r = n;
		r->next = f;
	}
	else
	{
		r->next = n;
		r = n;
		n->next = f;
	}
} 
void dequeue() // Delete an element from Queue
{
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else if(f == r){
		f = r = NULL;
		free(t);
	}
	else{
		f = f->next;
		r->next = f;
		free(t);
	}
}
void print(){ // Print the elements of Queue
	struct node* t;
	t = f;
	if((f==NULL)&&(r==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("\n%d",t->data);
			t = t->next;
		}while(t != f);
	}
}
int main()
{
	int opt,n,i,data;
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of values you want to put: ");
				scanf("%d",&n);
				printf("\nEnter the values: ");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				print();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");
		}
	}while(opt!=0);
return 0;
}
