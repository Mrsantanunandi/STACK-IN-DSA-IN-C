#include <stdio.h>
#include <string.h>
#define N 50
int stack[N];
int top=-1;
char infix[N];
void push(char x)
{
	if(top==N-1)
	{
		printf("\nStack Overflow!");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
char pop()
{
	int ch;
	if(top==-1)
	{
		printf("\nstack Underflow!");
		return '\0';
	}
	else
	{
		ch=stack[top];
		top--;
		return ch;
	}
}
char peep()
{
	if(top==-1)
	{
		printf("\nstack is empty");
		return '\0';
	}
	else
	{
		return stack[top];
	}
}

int parenthesis_cheack(char infix[])
{
	int i=0;
	char symbol;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(symbol=='(' || symbol=='{' || symbol=='[')
		{
			push(symbol);
		}
		else if(symbol==')' || symbol=='}' || symbol==']')
		{
			char next=peep();
			if((symbol=='(' && next==')') || (symbol=='{' && next=='}') || (symbol=='[' && next==']'))
			{
				pop();
			}
			else 	
			{
				return 0;
			}
		}
	}
	return top== -1;
}
int main()

{
	printf("\nEnter the infix Equation:");
	scanf("%s",infix);
	printf("\The Enetered infix Equation is: %s",infix);
	if(parenthesis_cheack(infix))
	{
		printf("\nThe Equation is unbalanced");
	}
	else
	{
		printf("\nThe Equation is balanced");
	}
	return 0;
}
