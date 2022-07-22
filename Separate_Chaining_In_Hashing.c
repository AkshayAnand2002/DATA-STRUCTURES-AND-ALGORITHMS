#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
struct node	{
	int data;
	struct node *next;
};
struct node *chain[SIZE];//making array of linked list.
void init(){
	int i;
	for(i=0;i<SIZE;i++){
		chain[i]=NULL;//ASSIGNED NULL TO ALL CHAIN VALUES INITIALLY.
	}
}
void insert(int value){
	//create a new node with value.
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	//calculate hash key
	int key = value % SIZE;
	//check if chain[key] is empty.
	if(chain[key]==NULL){
		chain[key]=newnode;
	}
	//collision
	else{
		//add node at the end of chain[key].
		struct node *temp = chain[key];
		while(temp->next){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void print(){
	int i;
	for(i=0;i<SIZE;i++){
		struct node *temp = chain[i];
		printf("chain[%d]->",i);
		while(temp){
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main()
{
    //init array of list to NULL
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    print();
    return 0;
}
