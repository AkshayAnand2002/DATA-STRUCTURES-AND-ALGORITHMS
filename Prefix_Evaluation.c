/*Algorithm -
Step 1: Start from the last element of the expression.
Step 2: check the current element.
Step 2.1: if it is an operand, push it to the stack.
Step 2.2: If it is an operator, pop two operands from the stack. Perform the operation and push the elements back to the stack.
Step 3: Do this till all the elements of the expression are traversed and return the top of stack which will be the result of the operation.
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int s[50];
int top=0;
void push(int ch);
int pop();
int main(){
	int a,b,c,i;
	char prefix[50];
	printf("ENTER THE PREFIX EXPRESSION: ");
	gets(prefix);
	for(i=strlen(prefix)-1;i>=0;i--){
		if(prefix[i]=='+'){
			c=pop()+pop();
			push(c);
		}
		else if(prefix[i]=='-'){
			a=pop();
			b=pop();
			c=b-a;
			push(c);
		}
		else if(prefix[i]=='*'){
			a=pop();
			b=pop();
			c=b*a;
			push(c);
		}
		else if(prefix[i]=='/'){
			a=pop();
			b=pop();
			c=b/a;
			push(c);
		}
		else{
			push(prefix[i]-48);
		}
	}
	printf("\nFINAL ANSWER = %d",pop());
	getch();
	return 0;
}
void push(int ch){
	top++;
	s[top]=ch;
}
int pop(){
	int ch;
	ch=s[top];
	top=top-1;
	return(ch);
}
