/*Algorithm :
We take two stacks say stack1 and stack2.
stack1 will be working as the main queue and stack2 will help us in reversing the order of stack1.
For enqueue operation , We will simply push the element let say x into stack1.
For dequeue operation ,  
If both the stack1 and stack2 are empty then we need to print that queue is empty.
If stack2 is empty then we need to push all the elements from stack1 to stack2 .
Pop the element from stack2 and return it. I.E. FOR DEQUEUE OPERATIONS POP ALL ELEMENTS FROM STACK 1 AND PUSH THAT ELEMENT IN STACK 2
AFTER EMPTY THE STACK 1, TOP ELEMENT OF STACK 2 IS THE DEQUEUED ELEMENT.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100			// size for arrays representing stack1 and stack2
int stack1[N], stack2[N];	// array representing stacks of size N
int top_stack1 = -1;		// top for stack1
int top_stack2 = -1;		// top for stack2
int count = 0;			// For keeping the count of element present in queue
void push_stack1 (int data)
{
  if (top_stack1 == N - 1)
   {
      printf ("Stack1 is overflow");
      return;
   } 
  else
  {
    top_stack1++;
    stack1[top_stack1] = data;
  }
 return;
}
void push_stack2 (int data)
{
  if (top_stack2 == N - 1)
   {
      printf ("Stack2 is overflow");
      return;
    }
 else
    {
      top_stack2++;
      stack2[top_stack2] = data;
    }
 return;
}
int pop_stack1 ()
{
  if (top_stack1 == -1)
  {
      printf ("Stack1 is underflow\n");
      return -1;
  }
  return stack1[top_stack1--];
}
int pop_stack2 ()
{
 if (top_stack2 == -1)
 {
    printf ("Stack2 is underflow\n");
    return -1;
 } 
 return stack2[top_stack2--];
}
void enqueue (int data)
{
  push_stack1 (data);
  count++;
} 
void dequeue ()
{
  if (top_stack1 == -1 && top_stack2 == -1)
    printf ("Queue is empty\n");
  else
    {
      for (int i = 0; i < count; i++){
	   int temp = pop_stack1 ();
	   push_stack2 (temp);
	  } 
      int x = pop_stack2 ();
      printf ("Dequeued element is %d\n", x);
      count--;
      for (int i = 0; i < count; i++){
	  int temp = pop_stack2 ();
	  push_stack1 (temp);
      } 
    } 
} 
 void display ()
{
  if (top_stack1 == -1)
    {
      printf ("Queue is empty \n");
      return;
    }
  for (int i = 0; i <= top_stack1; i++)
    printf ("%d ", stack1[i]);
  printf ("\n");  
} 
void top ()
{
  printf ("Top element of queue is %d ", stack1[0]);
} 
int main ()
{
 enqueue (3);
 enqueue (45);
 enqueue (-1);
 display();
 dequeue ();
 enqueue (-1);
 display ();
 return 0;
}
