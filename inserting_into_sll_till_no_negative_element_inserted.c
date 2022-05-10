#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node{
	int val;
	struct node *next;
};
struct node *create_node(int v){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val=v;
	temp->next =NULL;
	return temp;
}
struct node *insert_at_beg(struct node * h, int v){
	struct node *t;
	t=create_node(v);
	if(h==NULL){
		return t;
	}
	else{
		t->next=h;
		h=t;
		return h;
	}
}
struct node * insert_at_end(struct node *h,int v){
	struct node *t,*first =h;
	t=create_node(v);
	if(h==NULL){
		return t;
	}
	else{
		while(first->next != NULL){
			first = first->next;
		}
		first->next=t;
	}
	return h;
}
int count_node(struct node *h)
{
  int count=0;   
   while(h!=NULL)
     {
         count++;
         h = h->next;
      }
   return count;
} 

struct node * insert_at_pos(struct node * h, int v, int pos)
{
   struct node *t,*prev, *cur; 
   int count,i;
   t = create_node(v);
	if(pos==1)
	{
       		if( h==NULL)
        	return t;
       		else
        	h= insert_at_beg(h,v);
	}
	else
	{
       		count = count_node(h); 
       		if(pos>count+1)
        	{
            		printf("\n Invalid postion to insert new node");
            		printf("No of nodes in the list = %d", count);
            		exit(0);
        	}
       		else
        	{
         		 prev = cur = h;
          		 i=1;

          		while(i<pos)
           		{
             			prev =cur;
             			cur  =  cur->next;
             			i++;
            		}

        		prev->next = t;
        		t->next =cur;
      		}
	}
	return h;
}

void display_list(struct node *h)
{	
	while(h!=NULL)
     	{
         	printf("%d->", h->val);
         	h = h->next;
     	}
} 
void main()
{
   	struct node * head1= NULL;
	struct node * head2= NULL;
        int n,c, pos;
    
    while(1)
    {
         printf("\n Enter any positive integer:");
         scanf("%d", &n);
         if(n<0)
            break;
         else
         {
		printf("\n Choose List Inwhich You Want To Insert Your Node Data (1 OR 2):");
         	scanf("%d", &c);
        	//menu();
        	if(c == 1)
   		{
               		if(head1 ==NULL)
                   	head1 =  create_node(n);
            	else
            	{
                    //printf("\n Enter the position:");
                    //scanf("%d", &pos);
                    head1 =  insert_at_end(head1, n);
            	}
                    display_list(head1);  
    	}
		
		if(c == 2)
    		{
        		if(head2 == NULL)
                   	head2 =  create_node(n);
            	else
            	{
                    //printf("\n Enter the position:");
                    //scanf("%d", &pos);
                    head2 =  insert_at_end(head2, n);
            	}
                    display_list(head2);
        	}        
        }
	

    }
	struct node* current = head1;
	while(current->next != NULL)
	{
		current = current->next;
	}
		current->next=head2;
		printf("List 1:(WHEN PROGRAM EXITS LIST 1 GIVES MERGED OR CONCATENATED VALUE OF LIST2 AFTER LIST1.)");
		display_list(head1);
		printf("\n");
		printf("List 2:");
		display_list(head2);
}
