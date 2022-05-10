#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define CAPACITY 10000
struct stack{//stack node structure
	int data;
	struct stack *next;
}*top;
//stack size
int size = 0;
void push(int element);
int pop();
int main(){
	int choice,data;
	while(1){
		printf("STACK IMPLEMENTATION BY LINKED LIST---\n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.SIZE\n");
		printf("4.EXIT\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("ENTER DATA TO PUSH INTO STACK: ");
			        scanf("%d",&data);
			        push(data);//push elements to stack.
			        break;
			case 2: data = pop();
			        //below checking for stack is empty or not.
			        if(data != INT_MIN)
			           printf("DATA => %d\n",data);
			        break;
			case 3: printf("STACK SIZE : %d\n",size);//we directly find size by size variable. It will always contain the current size of stack.
			        break;
			case 4: printf("EXIT.");
			        exit(0);
			        break;
			default: printf("INVALID CHOICE.");
		}
		printf("\n\n");//to give space between all the above lines and next time when all the above lines are printed on the screen.
	}
	return 0;
}
//function to push element into stack.
void push(int element){
	//checking stack overflow.
	if(size >= CAPACITY){
		printf("STACK OVERFLOW OCCURS.\n");
		return;
	}
	//creating a new node and push to stack.
	struct stack * newnode = (struct stack *)malloc(sizeof(struct stack));
	//assigning data to newnode in stack
	newnode->data=element;
	//link new node with current top element 
	newnode->next=top;
	//make sure top of the stack should always be newnode.
	top=newnode;
	//increment element count in stack
	size++;
	printf("DATA PUSHED TO STACK.\n");
}
int pop(){
	int data=0;
	struct stack * topnode;
	//checking stack underflow.
	if(size<=0 || !top){
		printf("STACK IS EMPTY.\n");
//throw stack error or exception , return minimum integer value as error value check if return integer is INT_MIN then stack is empty.
		return INT_MIN;
	}
	//copy reference of stack top to some temp variable. Since we need to delete current stack top and make next to top element as stack top.
	topnode = top;
	//below line for copying data from stack top element.
	data= top->data;
	//delete previous topmost stack element from memory.
	free(topnode);
	//decrement stack size.
	size--;
	return data; 
}
