#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 50
int stack[MAX];
int top=-1;
int ch;
void push(int element)
{
	if(top==MAX-1)
	{
		printf("\n STACK OVER FLOW!!");
	}
	else
	{
		top++;
		stack[top]=element;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("\nSTACK UNDER FLOW !!");
	}
	else
	{
		ch=stack[top];
		top--;
	}
	return ch;
}
int main(){
	char postfix[MAX]={'\0'},element;
	int i,a,b,result=0;
	printf("\nEnter the postfix Expression: ");
	scanf("%[^\n]s",postfix);
	printf("\nThe Entered postfix Expression is: %s ",postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		element=postfix[i];
		if(isdigit(element)){
			push(element-'0');
		}
		else if(element==' '){
			continue;
		}
		else{
			a=pop();
			b=pop();
			switch(element){
				case '^':
					result=pow(b,a);
					break;
				case '/':
					result=b/a;
					break;
				case '+':
					result=(b+a);
					break;
				case '-':
					result=b-a;
					break;
				case '*':
					result=(b*a);
					break;
					
				
			}
			push(result);
		}
	}
	printf("\nThe postfix evalution is %d",stack[top]);
	return 0;
}
