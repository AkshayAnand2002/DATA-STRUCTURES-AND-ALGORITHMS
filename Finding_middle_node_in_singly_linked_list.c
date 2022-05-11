/*Find middle node of a linked list using slow and fast pointer.
Algorithm to print middle node of linked list---
Let "head" be the head pointer of given linked list.
We will use two pointers "front" and "back" pointer. Initially, set both pointer to head node.
Using a loop, traverse linked list until fast pointer reached last node of linked list.(fast != NULL && fast->next != NULL)
In every iteration, slow pointer will move one node whereas fast pointer will move two node.
When fast pointer reaches last node then slow pointer will be pointing to middle node.
In this program, we will use a user defined function "printMiddleNode" which takes head node of a linked list as input and print middle node by implementing above mentioned algorithm.
*/
#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
} *head;
void initialize(){
    head = NULL;
}
/*Given a Inserts a node in front of a singly linked list. */
void insert(int num) {//this function does insertion at beginning .
    /* Create a new Linked List node */
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
    /* Next pointer of new node will point to head node of linked list  */
    newNode->next = head;
    /* make new node as new head of linked list */
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
void printMiddleNode(struct node *head){
    /* Input Validation */
    if(head == NULL){
        printf("Error : Invalid Input !!!!\n");
        return INT_MIN;
    }
    struct node *slow, *fast;
    slow = fast = head;
    /* In every iteration, slow pointer will move one node whereas
     fast pointer will move two node. When fast pointer reaches 
     last node then slow pointer will be pointing to middle node */
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    } 
    printf("\nMiddle Node : %d\n", slow->data);
}
/*
Prints a linked list from head node till tail node 
*/
void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
int main() {
    initialize();
    /* Creating a linked List*/
    insert(3);  
    insert(7); 
    insert(12); 
    insert(5);
    insert(9);
    printf("\nLinked List\n");
    printLinkedList(head);
    /* Printing Middle Node of Linked List */
    printMiddleNode(head);
    return 0;
}
