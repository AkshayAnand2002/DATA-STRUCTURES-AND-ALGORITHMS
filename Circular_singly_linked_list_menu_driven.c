#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *tail, *temp;
void createCLL()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    if(tail==0){//USED ONLY TAIL POINTER THAT IS POINTING TO LAST NODE BEFORE NEWNODE IS INSERTED .
        tail=newnode;//newnode is the node to be inserted.
        tail->next = newnode;//next part of tail is connected to newnode. TAIL BECOMES LAST NODE OF LINKED LIST I.E NODE BEFORE HEAD NODE.
    }
    else{
        newnode->next = tail->next;//next part of newnode is connected to next part of tail.next part of tail is the last node before newnode is innserted.
        tail->next = newnode;//next part of tail is assigned address of newnode.
        tail = newnode;//tail is assigned address of newnode.
    }
}
void display()
{
   if(tail==0)
   {
       printf("LIST is EMPTY\n");
   }
   else{
    temp = tail->next;//TEMP IS THE POINTER USED FOR TRAVERSING CLL.
   }
   while(temp->next != tail->next)//TEMP INITIALLY POINTS TO HEAD.
   {
       printf("%d ", temp->data);
       temp = temp->next;//TEMP MOVES FORWARD TO NEXT NODES.
   }
   printf("%d\n", temp->data);//THE WHILE LOOP WILL NOT PRINT DATA WHEN TEMP->NEXT = TAIL->NEXT I.E. TEMP POINTS TO LAST NODE OR NODE BEFORE HEAD OF CLL.
}
void insertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    if(tail==0){
        tail = newnode;//WHEN NO NODE IS PRESENT THEN TAIL IS ASSIGNED ADDRESS OF NEWNODE.
        tail->next = newnode;//TAIL'S NEXT PART POINTS TO ITSELF AS ONLY 1 NODE IN CLL.
    }
    else{
        newnode->next = tail->next;//NEWNODE NEXT PART CONNECTED TO HEAD OR 1ST NODE OF CLL.
        tail->next = newnode;//TAIL IS THE NODE WHICH IS BEFORE THE NEWNODE TAIL'S NEXT PART ATTACHED TO NEWNODE.
    }
}
void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next = tail->next;//NEWNODE CONNECTED AFTER TAIL AND NEXT PART IS ASSIGNED ADDRESS OF HEAD.
    tail->next = newnode;//NEWNODE ADDED AFTER TAIL.
    tail = newnode;//TAIL IS ASSIGNED ADDRESS OF NEWNODE. AS IT IS INSERTED AT LAST.
}
void insertAtPosition(){
    int i=1, position;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));
    printf("Enter Position ");
    scanf("%d", &position);
    int l = getLength();
    if(position<1 || position> l+1){
        printf("INVALID POSITION");
    }
    else if(position == 1){
        insertAtBeginning();
    }
    else if(position == l+1){
        insertAtEnd();
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf("%d", &newnode->data);
        newnode->next=0;
        temp = tail->next;
        while(i<position-1){
            temp = temp->next;
            i++;
        }//TEMP IS POINTING TO ONE NODE BEFORE POSITION WHERE NODE OS TO BE INSERTED.
        newnode->next = temp->next;//NEWNODE'S NEXT PART IS ASSIGNED ADDRESS OF NEXT PART PF TEMP.
        temp->next = newnode;//TEMP'S NEXT PART ASSIGNED ADDRESS OF NEWNODE.
    }
}
void deleteFromBeginning()
{
    temp = tail->next;
    if(tail==0){
        printf("LIST IS EMPTY!!!\n");
    }
    else if(temp->next==temp){
        tail=0;
        free(temp);
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
}
void deleteFromEnd()
{
    struct node *current, *previous;
    current = tail->next;//CURRENT NODE ACTS AS HEAD NODE HERE.
    if(tail==0){
        printf("LIST IS EMPTY\n");
    }
    else if(current->next == current){
        tail = 0;
        free(current);
    }
    else{
        while(current->next != tail->next){
            previous = current;//PREVIOUS POINTER
            current = current->next;//CURRENT MOVES 1 PLACE TO RIGHT.
        }
        previous->next = current->next;//PREVIOUS NODE POINTS TO HEAD OR NEXT NODE OF CURRENT (CURRENT NODE--WHICH HAS REACHED THE TAIL NODE).
        tail = previous;//TAIL IS ASSIGNED ADDRESS OF PREVIOUS.
        free(current);//AS CURRENT POINTS TO LAST NODE OR NODE BEFORE THE HEAD NODE.SO IT IS DELETED AS DELETE FROM END.
    }
}
void deleteFromPosition()
{
    struct node *current, *previous;
    int position, i=1;
    printf("Enter Position ");
    scanf("%d", &position);
    int l = getLength();
    if(position<1 || position>l){
        printf("INVALID POSITION!!!\n");
    }
    else if(position==1){
        deleteFromBeginning();
    }
    else if(position==l){
        deleteFromEnd();
    }
    else{
        current = tail->next;
        while(i<position){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next;//CURRENT IS THE NODE TO BE REMOVED AND PREV'S NEXT IS ASSIGNED ADDRESS OF CURRENT'S NEXT.
        free(current);
    }
}
int getLength()
{
    int count=0;
    temp = tail->next;
    while(temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}
void reverse()
{
    struct node *current, *prev, *nextnode;
    current = tail->next;//CURRENT NODE POINTS TO NEXT NODE OF TAIL OR HEAD NODE.
    nextnode = current->next;//NEXTNODE IS ASSIGNED ADDDRESS OF CURRENT NODE TO NEXT.
    if(tail == 0){
        printf("LIST IS EMPTY!!!\n");
    }
    while(current != tail)
    {
        prev = current;//PREV IS ASSIGNED ADDRESS OF CURRENT.
        current = nextnode;//CURRENT IS ASSIGNED ADDRESS OF NEXTNODE I.E. MOVES 1 PLACE TO RIGHT.
        nextnode = current->next;//NEXTNODE MOVES TO RIGHT POSITION OF CURRENT.
        current->next = prev;//CURRENT TO NEXT IS ASSIGNED VALUE OF PREVIOUS TO MAKE CONNECTIONS WITH PREVIOUS NODE.
    }//THE LAST NODE IS TAIL POINTER AND THE NEXTNODE WILL BE THE HEAD NODE.
    nextnode->next = tail;//nextnode or head node here is pointing to last nodes.
    tail = nextnode;//tail is assigned address of head and now the list is fully reversed.
}
void main()
{
    int ch;
    do{
        printf("ENTER CHOICE\n 1.Create Node\n 2.Display\n 3.Insert At Beginning\n 4.Insert At END\n 5.Insert At Position\n 6.Delete From Beginning\n 7.Delete From END\n 8.Delete From given Position\n 9.Reverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: createCLL();
                    break;
            case 2: display();
                    break;
            case 3: insertAtBeginning();
                    break;
            case 4: insertAtEnd();
                    break;
            case 5: insertAtPosition();
                    break;
            case 6: deleteFromBeginning();
                    break;
            case 7: deleteFromEnd();
                    break;
           case 8: deleteFromPosition();
                    break;
            case 9: reverse();
                    break;
            default: printf("INVALID CHOICE");
        }
    }while(ch!=0);
}
