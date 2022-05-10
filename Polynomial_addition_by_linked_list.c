#include<stdio.h>
#include<stdlib.h>
struct node
{
	float coeff;
	int expo;
	struct node *next;	
};
struct node *insert(struct node *head,float co,int ex)
{
	struct node *temp;
	struct node *newp=(struct node *)malloc(sizeof(struct node));
	newp->coeff=co;
	newp->expo=ex;
	newp->next=NULL;	
	if(head==NULL || ex>head->expo)
	{
	newp->next=head;
	head=newp;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL && temp->next->expo>=ex)
		{
			temp=temp->next;
		}
		newp->next=temp->next;
		temp->next=newp;
	
	}
		return head;
}
struct node *create(struct node *head)
{
	int n,i,ex;
	float co;
	printf("please enter the number of nodes :\t--==> ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the co.eff for the node %d :\t--==> ",i+1);
		scanf("%f",&co);
		printf("enter the exponential for the node %d :\t--==> ",i+1);
		scanf("%d",&ex);
		head=insert(head,co,ex);
	}
	return head;	
}
void polyadd(struct node *head1,struct node *head2)
{
	struct node *ptr1=head1;
	struct node *ptr2=head2;
	struct node *head3=NULL;	
	if(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->expo==ptr2->expo)
		{
			head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->expo);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->expo>ptr2->expo)
		{
			head3=insert(head3,ptr1->coeff,ptr1->expo);
			ptr1=ptr1->next;
		}
		else if(ptr2->expo>ptr1->expo)
		{
			head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->next;
		}	
	}
	while(ptr1!=NULL)
	{
		head3=insert(head3,ptr1->coeff,ptr1->expo);
		ptr1=ptr1->next;
	}
		while(ptr2!=NULL)
	{
		head3=insert(head3,ptr2->coeff,ptr2->expo);
			ptr2=ptr2->next;
	}
	printf("\n\nADDED POLYNOMIALS IS\n");
	print(head3);
}

void print(struct node *head3)
{
	struct node * temp=head3;
	if(head3=NULL)
	printf("no polynomials");
	while(temp!=NULL)
	{
		printf("(%.1f)^%d",temp->coeff,temp->expo);
		temp=temp->next;
		if(temp!=NULL)
		{
			printf("+");
		}
		else
		printf("\n");
	}
}
int main()
{
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	printf("POLYNOMIAL 1\n\n");
	head1=create(head1);
	printf("\n\n\nPOLYNOMIAL 2\n\n");
	head2=create(head2);
	polyadd(head1,head2);
	return 0;
}
