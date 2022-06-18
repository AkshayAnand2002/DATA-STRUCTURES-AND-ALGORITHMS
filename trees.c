#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *createNode(int val)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node *search(struct node *root,int val)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==val)
		return root;
	struct node *ans=search(root->left,val);
	if(ans==NULL)
		ans=search(root->right,val);
	return ans;	
}
//a=1 left
// a=2 right
struct node *insert(int val1,int val2,struct node *root,int a)
{
	struct node *temp=createNode(val1);
	struct node *child=search(root,val2);
	if(child!=NULL)
		printf("%d\n", child->data);  
	if(child!=NULL)
	{
		if(a==1)
		{
			child->left=temp;
		}
		else if(a==2)
		{
			child->right=temp;
		}

	}
	else
		printf("%d not Found....\n",val2);
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
int main()
{
	struct node *root=NULL,*temp=createNode(1);
	root=temp;
	while(1)
	{
		int ch;
		printf("\nMENU CHOICES\n1.InsertNode\n2.inorder\n3.Exit");
		printf("\nEnter Your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				int val1,val2,a;
				printf("\nEnter value of new node:");
				scanf("%d",&val1);
				printf("\nEnter value of node where node is to be inserted:");
				scanf("%d",&val2);
				printf("\n1.Left\n2.Right\n Enter Choice:");
				scanf("%d",&a);
				insert(val1,val2,root,a);
				break;	
				
			}
			case 2:
			{
				inorder(root);
				break;
			}
			case3:
			{
				return 0;
			}
		
		}
	}

}
