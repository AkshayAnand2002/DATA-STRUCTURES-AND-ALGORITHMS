//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node* createNode(){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	return (newNode);
}
void insertNodeAtEnd(){//insert at end function
	struct node *temp,*ptr;
	temp=createNode();
	printf("enter the data you want to insert:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else{
		ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
	       ptr->next=temp;
	     }
}
void viewList(){
	struct node* temp=head;
	if(temp==NULL){
		printf("List is empty. Please insert some data in list \n");
	}
	else{
	    printf("Our list is : \n");
		while(temp->next!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("%d \t",temp->data);
	}
}
void findMiddle(){
       struct node* t= head;
    int elements=0;
    while(t){
        t=t->next;
        elements++;
    }
    int middle = elements/2;
    t=head;
    for (int i = 1; i < middle + 1; i++) 
        t = t->next; 
    printf("middle number of list is :\n ");
    printf("%d",t->data);
}
int menu(){
	int choice;
	printf("\n 1.Add value to the list at end");
	printf("\n 2.Travesre/View List");
	printf("\n 3.Print Middle element of a list ");
	printf("\n 4.exit");
	printf("\n Please enter your choice: \t");
	scanf("%d",&choice);
	return(choice);
}
 void main(){
	while(1){
		switch(menu()){
			case 1:
				insertNodeAtEnd();
				break;
			case 2:
			    viewList();
			    break;
			case 3:
			   findMiddle();
			    break;
			case 4:
				exit(0);
			default:
				printf("invalid choice");
		      }
//			getch();
		  }
} 
