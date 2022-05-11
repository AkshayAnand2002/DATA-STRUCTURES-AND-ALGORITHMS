#include<stdio.h>
#include<stdlib.h>
struct list
{
int data;
struct list *link;
}*start=NULL;
void creat(int);
void swap();
void disp();
void main()
{
int ch,i,n,m;
do
{
printf("\n1.create");
printf("\n2.display");
printf("\n3.Swap");
printf("\n4.exit");
printf("\nenter your choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nHow many nodes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the data: ");
scanf("%d",&m);
creat(m);
}
break;
case 2:
disp();
break;
case 4:
exit(0);
case 3:
swap();
break;
}
}
while(ch!=4);
//getch();
}
void creat(int m)
{
struct list *tmp,*q;
tmp=(struct list *)malloc(sizeof(struct list));
tmp->data=m;
tmp->link=NULL;
if(start==NULL)
start=tmp;
else
{
q=start;
while(q->link!=NULL)
{
q=q->link;
}
q->link=tmp;
}
}
void disp()
{
struct list *q;
if(start==NULL)
{
printf(“list is empty”);
}
else
{
q=start;
while(q!=NULL)
{
printf("%d->",q->data);
q=q->link;
}
}
}
void swap()
{
int m,n,i,tmp;
struct list *q,*ptr,*ptr1;
printf("\nEnter the mth and nth position: ");
scanf("%d%d",&m,&n);
for(i=1,ptr=start;i<m && ptr!=NULL;ptr=ptr->link,i++);
for(i=1,ptr1=start;i<n && ptr1!=NULL;ptr1=ptr1->link,i++);
if(ptr!=NULL && ptr1!=NULL)
{
tmp=ptr->data;
ptr->data=ptr1->data;
ptr1->data=tmp;
}
else
{
printf("\nPosition Not Found.");
}
}
