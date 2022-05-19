/*Given with n nodes the task is to print the nth node from the end of a linked list. 
The program must not change the order of nodes in a list instead it should only print the nth node from the last of a linked list.
Instead of traversing the entire list this efficient approach can be followed -
Take a temporary pointer, let’s say, temp of type node
Set this temp pointer to first node which is pointed by head pointer
Set counter to the number of nodes in a list
Move temp to temp -> next till count-n
Display temp -> data
If we use this approach, than count will be 5 and program will iterate the loop till 5-3 i.e. 2, 
so starting from 10 on 0th location than to 20 on 1st location and 30 on 2nd location which is the result. 
So by this approach there is no need to traverse the entire list till end which will save space and memory.
*/
#include<stdio.h>
#include<stdlib.h>
//structure of a node
struct node{
   int data;
   struct node *next;
}*head,*temp;
int count=0;
//function for inserting nodes into a list
void insert(int val){
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->next = NULL;
   if(head == NULL){
      head = newnode;
      temp = head;
      count++;
   } else {
      temp->next=newnode;
      temp=temp->next;
      count++;
   }
}
//function for displaying a list
void display(){
   if(head==NULL)
      printf("no node ");
   else {
      temp=head;
      while(temp!=NULL) {
         printf("%d ",temp->data);
         temp=temp->next;
      }
   }
}
//function for finding 3rd node from the last of a linked list
void last(int n){
   int i;
   temp=head;
   for(i=0;i<count-n;i++){
      temp=temp->next;
   }
   printf("\n%drd node from the end of linked list is : %d" ,n,temp->data);
}
int main(){
   //creating list
   struct node* head = NULL;
   int n=3;
   //inserting elements into a list
   insert(1);
   insert(2);
   insert(3);
   insert(4);
   insert(5);
   insert(6);
   //displaying the list
   printf("\nlinked list is : ");
   display();
   //calling function for finding nth element in a list from last
   last(n);
   return 0;
}
