/*Algorithm to remove duplicates from a linked list (sorted)
Input the number of elements of the linked list.
Input the elements of the linked list in sorted order.
Traverse from the head of the sorted linked list.
While traversing, compare the current node with the next node.
If data of the next node is the same as the current node then delete the next node.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
/* Function to insert a node */
void insert_elements(struct node** head, int new_data)
{
struct node* new_node = (struct node*) malloc(sizeof(struct node));
new_node -> data = new_data;
new_node -> next = (*head);
(*head) = new_node;
}
//THE ABOVE FUNCTION DOES INSERT AT BEGINNING TYPE OF FUNCTION.
/* Function to print nodes */
void display_list(struct node *node)
{
while (node!=NULL)
{
printf("%d ", node->data);
node = node -> next;
}
}
/* Function to remove duplicates from a sorted list */
void remove_duplicate_elements(struct node* head)
{
struct node* current = head;
struct node* next_next;
if (current == NULL)
return;
while (current -> next != NULL)
{
/* Compare current node with its next */
if (current -> data == current -> next -> data)
{
next_next = current -> next -> next;
free(current -> next);
current -> next = next_next;
}
else
{
current = current -> next;
}
}
}
int main()
{
struct node* head = NULL;
int n;
printf("\nEnter the total number of elements : ");
scanf("%d", &n);
printf("\nEnter the sorted linked list : ");
int i;
for(i = 0; i < n; i++)
{
int data;
scanf("%d", &data);
insert_elements(&head, data);
}
printf("\nLinked list before removing duplicates : ");
display_list(head);
printf("\n");
remove_duplicate_elements(head);
printf("\nLinked list after removing duplicates : ");
display_list(head);
printf("\n");
return 0;
}
