#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int numbers[50],tn=-1,to=-1;
char op[50];
void push_num(int n){//to push nos. or digits
	numbers[++tn]=n;//tn counter or pointer initially points to -1.
}
void push_op(char ch){//to push operators.
	op[++to]=ch;//to counter or pointer initially points to -1.
}
int pop_num(){//to pop digits.
	return numbers[tn--];
}
char pop_op(){//to pop operators
	return op[to--];
}
int infix_eval(int numbers[50],char op[50]){
	int x,y;
	char ope;
	//taking first 2 operands.
	x=pop_num();
	y=pop_num();
	//taking the operator between them.
	ope=pop_op();
	//executing the operation
	switch(ope){
		case '+':
			    return x+y;
		case '-':
			    return y-x;	
		case '*':
			    return x*y;
		case '/':
			    if(x==0){
			    	printf("CAN'T DIVIDE BY ZERO.\n");
			    	exit(0);
				}
				else{
					return y/x;
				}
	}
	return 0;
}
//function to check whether the character is operator or not.
int is_operator(char ch){
	return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}
//the precedence of operators
int precedence(char c){
	switch(c){
		case '+':
			return 1;
		case '-':
			return 1;
	    case '*':
	    	return 2;
	    case '/':
	    	return 2;
	    case '^':
	    	return 3;
	}
	return -1;
}
//function to evaluate an infix expression.
int eval(char exp[20]){
	int i,num,output,r;
	char c;
	for(i=0;exp[i]!='\0';i++){
		//taking each character from expression
		c=exp[i];
		//checking if it is number
		if(isdigit(c)!=0){
			num=0;
			while(isdigit(c)){
				num=num*10+(c-'0');
				i++;
				if(i<strlen(exp)){
					c=exp[i];
			    }
				else
				    break;
			}
				i--;
				//pushing the number into stack of nos.
				push_num(num);
			}
			else if(c=='('){
				//pushing operators into stack
				push_op(c);
			}
			//if we get close bracket calculate the entire bracket.
			else if(c==')'){
				while(op[to] !='('){
					r=infix_eval(numbers,op);
					//pushing the result back to stack.
					push_num(r);
				}
				pop_op();
			}
			//if the current character is operator.
			else if(is_operator(c)){
				//evaluating the expression
				while(to != -1 && precedence(c)<=precedence(op[to])){
					output=infix_eval(numbers,op);
					//pushing the result back to stack.
					push_num(output);
				}
				//pushing the current operator to stack
				push_op(c);
			}
		}
		//if there is any remaining expression evaluate them.
		while(to!=-1){
			output=infix_eval(numbers,op);
			//pushing it back to stack
			push_num(output);
		}
		return pop_num();
	}
	int main(){
		char exp[50];
		//taking expression
		printf("ENTER INFIX EXPRESSION TO EVALUATE: ");
		gets(exp);
		printf("%d",eval(exp));
	}
//https://mycareerwise.com/programming/category/stack/infix-evaluation-274
