#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct stack{
	char stk[MAX];
	int top;
}s;
void push(char item){
	if(s.top ==(MAX-1)){//check top pointer is pointing to top element or not.
		printf("STACK IS FULL.");
	}
	else{
		s.top=s.top+1;//inc by 1.
		s.stk[s.top]=item;
	}
}
void pop(){
	if(s.top == -1){
		printf("STACK IS EMPTY.");
	}
	else{
		s.top=s.top-1;//reduce by 1.
	}
}
int checkpair(char val1,char val2){//for checking parenthesis balanced or not.
	return((val1=='(' && val2==')') || (val1=='[' && val2==']') || (val1=='{' && val2=='}'));
}
int checkbalanced(char expr[],int len){
	for(int i=0;i<len;i++){
		if(expr[i]=='(' || expr[i]=='[' || expr[i]=='{'){
			push(expr[i]);
		}
		else{
			if(s.top == -1){
				return 0;
			}
			else if(checkpair(s.stk[s.top],expr[i])){
				pop();
				continue;
			}
			//program will come here only if stack is not empty. If pair not found and it is not a closing parenthesis then return 0.
			return 0;
		}
	}
	return 1;
}
int main(){
	char exp[MAX]="())";
	int i=0;
	s.top=-1;
	int len = strlen(exp);
	checkbalanced(exp,len)?printf("BALANCED"):printf("NOT BALANCED");
	return 0;
}
