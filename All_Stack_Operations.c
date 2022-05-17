#include<stdio.h>
#include<conio.h>
#define N 10
int s[N+1];
int top=0;//top initially points to 0.
void push(int x);
int pop();
int peek(int i);
void change(int i,int x);
void Disp();
int main(){
	int x,i,ch=1,t;
	while(ch != 5){
		printf("ENTER 1 TO PUSH\n");
		printf("ENTER 2 TO POP\n");
		printf("ENTER 3 TO PEEK\n");
		printf("ENTER 4 TO CHANGE\n");
		printf("ENTER 5 TO EXIT\n");
		printf("ENTER 6 TO DISPLAY\n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			    printf("ENTER THE VALUE TO PUSH: ");
			    scanf("%d",&x);
			    push(x);
			    printf("\nVALUE IS PUSHED IN STACK.");
			    break;
			case 2:
				printf("\nPOP OPERATION");
				t=pop();
				printf("\nTHE VALUE POPPED IS %d.\n",t);
				break;
			case 3:
				printf("\nENTER THE INDEX OF STACK TO PRINT: ");
				scanf("%d",&i);
				t=peek(i);
				printf("\nVALUE IS %d\n",t);
				break;
			case 4:
				printf("\nENTER THE INDEX AND CHANGED VALUE: ");
				scanf("%d %d",&i,&x);
				change(i,x);
				printf("\nTHE VALUE IS CHANGED.\n");
				break;
			case 5:
				printf("\nEXIT.");
				break;
			case 6:
				Disp();
				break;
			default:
				printf("\nWRONG CHOICE.");
		}
	}
	return 0;
}
void push(int x){
	if(top==N){
		printf("\nSTACK OVERFLOW.");
		return;
	}
	top=top+1;
	s[top]=x;	
}
int pop(){
	int x;
	if(top==0){
		printf("\nSTACK UNDERFLOW.");
		return(0);
	}
	x=s[top];
	top=top-1;
	return(x);
}
int peek(int i){
	if((top-i+1)<0){
		printf("\nSTACK UNDERFLOW ON PEEK.");
		return 0;
	}
	return(s[top-i+1]);
}
void change(int i,int x){
	if((top-i+1)<0){
		printf("\nSTACK UNDERFLOW ON CHANGE.");
		return;
	}
	s[top-i+1]=x;
}
void Disp(){
	int i;
	for(i=top;i>=1;i--){
		printf("\n%d\n",s[i]);
	}
}
