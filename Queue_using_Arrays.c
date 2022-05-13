#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define CAPACITY 100 //QUEUE CAPACITY
int queue[CAPACITY];
unsigned int size = 0;
unsigned int rear = CAPACITY - 1;//INITIALLY REAR IS AT END.
unsigned int front = 0;
int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();
int main(){
	int ch,data;
	while(1){
		printf("QUEUE IMPLEMENTATION BY ARRAY.\n");
		printf("1.ENQUEUE\n");
		printf("2.DEQUEUE\n");
		printf("3.SIZE\n");
		printf("4.GET REAR\n");
		printf("5.GET FRONT\n");
		printf("0.EXIT\n");
		printf("SELECT AN OPTION FROM ABOVE: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nENTER DATA TO ENQUEUE: ");// Enqueue function returns 1 on success
                                                   // otherwise 0
				scanf("%d",&data);
				if(enqueue(data))
				   printf("ELEMENT ADDED TO QUEUE.");
				else
				   printf("QUEUE IS FULL.");
				break;
			case 2:
				data=dequeue();// on success dequeue returns element removed
                              // otherwise returns INT_MIN
				if(data==INT_MIN){
					printf("QUEUE IS EMPTY.");
				}
				else{
					printf("DATA=> %d",data);
				}
				break;
			case 3:
				if(isEmpty()){// isEmpty() function returns 1 if queue is emtpy 
                             // otherwise returns 0
					printf("QUEUE IS EMPTY.");
				}
				else{
					printf("QUEUE SIZE => %d",size);
				}
				break;
			case 4:
				if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Rear => %d", getRear());
                break;
            case 5:
            	 if (isEmpty())
                    printf("Queue is empty.");
                else 
                    printf("Front => %d", getFront());
                break;
            case 0: 
                 printf("EXIT.");
                 exit(0);
            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
		}
		printf("\n\n");
	}
}
int enqueue(int data)
{
    // Queue is full throw Queue out of capacity error.
    if (isFull()) 
    {
        return 0;
    }
    // Ensure rear never crosses array bounds
    rear = (rear + 1) % CAPACITY;
    // Increment queue size
    size++;
    // Enqueue new element to queue
    queue[rear] = data;
    // Successfully enqueued element to queue
    return 1;
}
int dequeue()
{
    int data = INT_MIN;
    // Queue is empty, throw Queue underflow error
    if (isEmpty())
    {
        return INT_MIN;
    }
    // Dequeue element from queue
    data = queue[front];
    // Ensure front never crosses array bounds
    front = (front + 1) % CAPACITY;
    // Decrease queue size
    size--;
    return data;
}
/**
 * Checks if queue is full or not. It returns 1 if queue is full, 
 * overwise returns 0.
 */
int isFull()
{
    return (size == CAPACITY);
}
/**
 * Checks if queue is empty or not. It returns 1 if queue is empty, 
 * otherwise returns 0.
 */
int isEmpty()
{
    return (size == 0);
}
/**
 * Gets, front of the queue. If queue is empty return INT_MAX otherwise
 * returns front of queue.
 */
int getFront()
{
    return (isEmpty())
            ? INT_MIN
            : queue[front];
}
/**
 * Gets, rear of the queue. If queue is empty return INT_MAX otherwise
 * returns rear of queue.
 */
int getRear()
{
    return (isEmpty())
            ? INT_MIN
            : queue[rear];
}
