#include<stdio.h>
#include<conio.h>
int s[20];
int top=0;
void push(int t);
int pop();
int main(){
	int i;
	long fact = 1;
	int n;
	printf("ENTER N = ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		push(i);
	}
	for(i=1;i<=n;i++){
		fact=(long)fact*pop();
	}
	printf("FACTORIAL OF %d = %ld",n,fact);
	return 0;
}
void push(int t){
	top++;
	s[top]=t;
}
int pop(){
	int x;
	x=s[top];
	top=top-1;
	return x;
}
