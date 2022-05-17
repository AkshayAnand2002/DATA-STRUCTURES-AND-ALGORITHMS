#include<stdio.h>
#include<conio.h>
#include<string.h>
int s[50];
int top=0;
void push(int ch);
int pop();
int main()
{
	int a,b,c,i;
	char postfix[50];
	printf("Enter the postfix string: ");
	gets(postfix);

	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]=='+')
		{
			c=pop()+pop();
			push(c);
		}
		else if(postfix[i]=='-')
		{
			a=pop();
			b=pop();
			c=b-a;
			push(c);
		}
		else if(postfix[i]=='*')
		{	
			a=pop();
			b=pop();
			c=b*a;
			push(c);
		}
		else if(postfix[i]=='/')
		{
			a=pop();
			b=pop();
			c=b/a;
			push(c);
		}
		else
		{
			push(postfix[i]-48);
		}
	}
	printf("\nPostfix expression = %s",postfix);
	printf("\nFinal ans = %d",pop());
	return 0;
}
void push(int ch)
{
	top++;
	s[top]=ch;
}
int pop()
{
	int ch;
	ch=s[top];
	top=top-1;
	return(ch);
}
