#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *ptr;
void insert_begin(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if (head== NULL)
	{
		head=temp;//list is empty so inserted node i.e. temp becomes first and last node.
	}
	else
	{
		temp->next=head;//temp is pointer pointing to inserted node. need to change null address to temp.
		head=temp;//move head pointer to temp as head is first node.
	}
}
void insert_end(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;//ptr-pointer other than head to point to 1st node.
		//ptr-pointer other than head to point to 1st node.
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;//ptr is the last node till new node was not attached.
		temp->next=NULL;//Attaching new nodes exit part is NULL.
	}
}

void insert_After_specified_ele(int value,int ele)
{
	struct node *temp;// temp-pointer to be inserted at position
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;//ptr starting from head.
		while(ptr->data != ele)
		{
			ptr=ptr->next;//ptr is the node after which we want to insert temp.
		}
		temp->next=ptr->next;//temp's next part assigned address.
		ptr->next=temp;
	}
	
}

void delete_begin()
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible\n");
	}
	else
	{
		ptr=head;//ptr assigned head address.
		head=head->next;//head pointer moved one place to right
		ptr->next=NULL;//next pointer made NULL to remove.
		free(ptr);//freed ptr.
	}
}
void delete_end()
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible\n");
	}
	else
	{
		struct node *p; 
		ptr=head;//ptr-used to store inserted node and p-used to point previous pointer.
		while(ptr->next != NULL)
		{
		p=ptr;//p is assigned ptr address.
		ptr=ptr->next;//ptr moves to next place.
		}
		//when ptr reaches last value ,p's next value assigned NULL to remove connection with last node.
		p->next=NULL;
		free(ptr);
	}
}

void delete_element(int ele)
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p; 
		ptr=head;
		while(ptr->data != ele)
		{
			p=ptr;//p stores ptr address before it moves to next positions.
			ptr=ptr->next;
		}
		p->next=ptr->next;//p-pointer storing address of previous element of ptr.
		//This command removes ptr from list and p is attached to next node of ptr.
		free(ptr);
	}
}
void display()
{
	if (head== NULL)
	{
		printf("List is Empty.\n");
	}
	else
	{
		ptr=head;//ptr assigned head address.
		while( ptr != NULL)
		{
			printf("-> %d", ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void main()
{
	int value,ele,ch;
	printf("1. Insert_begin \n");
	printf("2. Insert_end \n");
	printf("3. Insert_After_specified_element \n");
	printf("4. delete_begin \n");
	printf("5. delete_end \n");
	printf("6. delete_element \n");
	printf("7. exit \n");
	
	while(1)
	{
		printf("Enter the Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("Enter the value: ");
					scanf("%d",&value);
					insert_begin(value);
					display();
					break;
				}
				case 2:
				{
					printf("Enter the value: ");
					scanf("%d",&value);
					insert_end(value);
					display();
					break;
				}	
				case 3:
					{
					printf("Enter the value: ");
					scanf("%d",&value);
					printf("After which element u want to insert: ");
					scanf("%d",&ele);
					insert_After_specified_ele(value,ele);
					display();
					break;
				}
				case 4:
					{
					delete_begin();
					display();
					break;
				}
				case 5:
				{
					delete_end();
					display();
					break;
				}
				case 6:
				{
					printf("Enter the element you want to delete: ");
					scanf("%d",&ele);
					delete_element(ele);
					display();
					break;
				}	
				case 7:
					exit(0);
								
				}
		}
	}
