#include<stdio.h>
#include<stdlib.h>
int q[10],f=-1,r=-1;
void insertion(int x){
	//CHECKING CIRCULAR QUEUE IS FULL OR NOT :- if(((front==0) && (rear==MAX-1)) || (front==rear+1)) then circular queue is full.
	if(((r==9) && (f==0)) || (f==r+1)){
		printf("CIRCULAR QUEUE IS FULL.\n");
	}
	else{
		r=(r+1)%10;//rear=(rear+1)%size;
		q[r]=x;
		if(f==-1){
			f=0;//make front as 0 if front was at -1 i.e. circular queue was empty.
		}
	}
}
void deletion(){
	//CIRCULAR QUEUE IS EMPTY :- if(front == -1)
	if(f==-1){
		printf("CIRCULAR QUEUE IS EMPTY.");
	}
	else{
		//CIRCULAR QUEUE HAS ONLY ONE ELEMENT :- if(front==rear)
		if(f==r){
			f=-1;//front and rear are set to -1 to delete the only element that was present in the circular queue.
			r=-1;
		}
		else{
			f=(f+1)%10;//this statement works for all cases when f==MAX-1 then it should next point to 0 else front=front+1;
			//We can write belo code in place of above code as both are same only.
			/*if(front == MAX-1)
			front = 0;
		    else
			front = front+1;*/
		}
	}
}
void display(){
	int i;
	if(f<=r){//rear occurs to the right of front i.e. rear = 9 and front = 2. 
		for(i=f;i<=r;i++){
			printf("%3d",q[i]);
		}
	}
	else{
		//below writing the conditions when front occurs to the right of rear i.e. front=9 and rear=2.
		for(i=f;i<9;i++){//printing all elements fron front to (last i.e. MAXSIZE-1).
			printf("%3d",q[i]);
		for(i=0;i<=r;i++){//printing all elements from 0 to rear.
			printf("%3d",q[i]);
		}
		}
	}
}
int main(){
	int x,ch;
	while(1){
	printf("\n1.INSERTION\n2.DELETION\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("\nENTER ELEMENT TO BE INSERTED: ");
		        scanf("%d",&x);
		        insertion(x);
		        break;
		case 2:deletion();
		       break;
		case 3: display();
		        break;
		case 4: exit(0);
		default: printf("INVALID CHOICE.");
	}}
}
