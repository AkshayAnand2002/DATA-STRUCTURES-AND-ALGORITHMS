#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*newnode,*temp;
void createnode(){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("ENTER DATA: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(head==0){
		head=temp=newnode;//list is empty so inserted node i.e. newnode becomes first and last node.
	}
	else{
		temp->next=newnode;//temp is a pointer used for travering the singly linked list. 
		temp=newnode;//newnode's address is assigned to temp to attach newnode at required position.
	}
}
void display(){
    struct node *temp;
	temp=head;
	while(temp !=0){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void insertatbeginning(){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("ENTER DATA AT BEGINNING: ");
	scanf("%d",&newnode->data);
	newnode->next= head;
	head=newnode;
}
void insertatend(){
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("ENTER DATA AT END: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	temp=head;//temp is assigned head address for traversal of list.
	while(temp->next != 0){
		temp=temp->next;
	}
	temp->next=newnode;//temp->next is assigned address of newnode.
}
int getlength(){
	temp=head;
	int count=0;
	while(temp !=0){
		count++;
		temp=temp->next;
	}
	return count;
}
void insertaftergivenposition(){
	int position,i=1;
	printf("ENTER POSITION: ");
	scanf("%d",&position);
	if(position > getlength()){
		printf("INVALID POSITION.");
	}
	else{
		temp=head;
		while(i<position-1){
			temp=temp->next;
			i++;
		}
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("ENTER DATA: ");
	scanf("%d",&newnode->data);
	newnode->next=temp->next;//newnode which is to be inserted is assigned address of the node which comes after the node to be inserted.
	temp->next=newnode;//temp is the node after which we want to insert newnode so temp->next is assigned address of newnnode.
}
void deletefrombeginning(){
	struct node *temp;
	temp=head;
	head=head->next;
	free(temp);
}
void deletefromend(){
	struct node *prevnode;
	temp=head;
	while(temp->next != 0){
		prevnode=temp;
		temp=temp->next;
	}
	if(temp==head){
		head=0;
	}
	else{
		 prevnode->next=0;
	}
	free(temp);
}
void deletefromposition(){
	struct node *nextnode;
	int position,i=1;
	printf("ENTER POSITION: ");
	scanf("%d",&position);
	if(position > getlength()){
		printf("INVALID POSITION.\n");
	}
	else if(position == 1){
		deletefrombeginning();
	}
	else if(position == getlength()){
		deletefromend();
	}
	else{
		temp=head;
		while(i<position-1){
			temp=temp->next;
			i++;
		}
		nextnode=temp->next;//pointer for keeping address of node to be deleted.
		temp->next=nextnode->next;//temp's next part is attached with the node which is after the node to be deleted.
		free(nextnode);
	}
}
void reverse(){
	struct node *prevnode,*currentnode,*nextnode;
	prevnode=0;
	currentnode=nextnode=head;
	while(nextnode !=0){//prevnode used as list is getting reversed and addresses now stored is the address of the previous node.
//nextnode used to keep access of nextnode as if this is not used link of nodes can't be accessed.
		nextnode=nextnode->next;//nextnode moved one place to right.
		currentnode->next=prevnode;//currentnode pointing to null as its next part is assigned null value. for the nodes later in list this line makes it 
		//point to address of previous node.
		prevnode=currentnode;//prevnode assigned address of current node which stored the address of currentnode before it was changed to null.
		//for later nodes it always points to node before current node i.e left node of current node.
		currentnode=nextnode;//currentnode made to point to nextnode .i.e moved one place or one mode to right.
	}
	head=prevnode;//head which was pointing to head when list was not reversed is made to point to last node when list was not reversed or the first node of reversed list 
	//by prevnode as other pointers at last become zero.
}
void main()
{ int ch=1;
    do
    {
        printf("Enter choice-\n 1- Create Node\n 2- Display\n 3- Insert At Beginning\n 4- Insert At End\n 5- Insert After Given Position\n 6-Delete From Beginning\n 7-Delete From End\n 8-Delete From Specific Position\n 9-Reverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: createnode();
                    break;
            case 2: display();
                    break;
            case 3: insertatbeginning();
                    break;
            case 4: insertatend();
                    break;
            case 5: insertaftergivenposition();
                    break;
            case 6: deletefrombeginning();
                    break;
            case 7: deletefromend();
                    break;
            case 8: deletefromposition();
                    break;
            case 9: reverse();
                    break;
            default: printf("INVALID CHOICE.");
        }
    }
    while(ch!=0);
}
