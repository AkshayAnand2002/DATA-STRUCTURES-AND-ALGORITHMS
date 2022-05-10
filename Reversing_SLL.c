#include <stdio.h>
#include <stdlib.h>
struct node {
    int data; //Data part
    struct node *next; //Address part
}*head;
void createList(int n);
void reverseList();
void displayList();
int main()
{
    int n, choice;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in the list \n");
    displayList();
    printf("\nPress 1 to reverse the order of singly linked list\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        reverseList();
    }
    printf("\nData in the list\n");
    displayList();
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }
    head = (struct node *)malloc(sizeof(struct node));
    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL; 
        temp = head;
        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL
                temp->next = newNode; // Link previous node i.e. temp(pointing to head) to the newNode
                temp = temp->next;
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/*
 * Reverse the order of nodes of a singly linked list
 */
void reverseList()
{
    struct node *prevNode, *curNode;
    if(head != NULL)
    {
        prevNode = head;//previous node points to head.
        curNode = head->next;//current node points 1 place after head pointer.
        head = head->next;//head pointer moved 1 place to right.

        prevNode->next = NULL; // Make first node as last node, for this we made link part to be NULL 

        while(head != NULL)//repeating process till head is NULL.
        {
            head = head->next;//moved 1 place to right.
            curNode->next = prevNode;//started adding reversed nodes as curnode which is to the right of prevnode is getting attached to the previous node.
            prevNode = curNode;//moving to next nodes by making prevnnode point to curnode
            curNode = head;//moving to next nodes by making curnode point to head.
        }
        head = prevNode; // Make last node as head i.e. to attach last node left.
        printf("SUCCESSFULLY REVERSED LIST\n");
    }
}
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
