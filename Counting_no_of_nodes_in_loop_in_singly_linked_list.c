// C program to count number of nodes 
// in loop in a linked list if loop is 
// present 
#include<stdio.h> 
#include<stdlib.h> 
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
// Returns count of nodes present in loop. 
int countNodes(struct Node *n) 
{ 
   int res = 1; 
   struct Node *temp = n; 
   while (temp->next != n) 
   { 
      res++; 
      temp = temp->next; 
   } 
   return res; 
} 
/* This function detects and counts loop 
   nodes in the list. If loop is not there 
   in then returns 0 */
int countNodesinLoop(struct Node *list) 
{ 
    struct Node  *slow_p = list, *fast_p = list; 
    while (slow_p && fast_p && fast_p->next) 
    { 
        slow_p = slow_p->next; 
        fast_p  = fast_p->next->next; 
        /* If slow_p and fast_p meet at some point 
           then there is a loop */
        if (slow_p == fast_p) 
            return countNodes(slow_p); 
    } 
    /* Return 0 to indicate that there is no loop*/
    return 0; 
} 
struct Node *newNode(int key) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
/* Driver program to test above function*/
int main() 
{ 
    struct Node *head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next; //making next pointer of last node point to second node of list. 
    printf("%d", countNodesinLoop(head)); 
    return 0; 
} 
/*
We know that Floyd’s Cycle detection algorithm terminates when fast and slow pointers meet at a common point. 
We also know that this common point is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram).
We store the address of this common point in a pointer variable say ptr. 
Then we initialize a counter with 1 and start from the common point and keeps on visiting next node and increasing the counter till we again reach the common point(ptr). 
At that point, the value of the counter will be equal to the length of the loop.
*/
