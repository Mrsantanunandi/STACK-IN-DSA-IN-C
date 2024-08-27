#include<stdio.h>
#define MAX 50
int stack[MAX];
int top=-1;
void push()
{
	int x;
	printf("\nEnter the item: ");
	scanf("%d",&x);
	if(top==MAX-1)
	{
		printf("\n STACK OVER FLOW!!");
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
void pop()
{
	int item;
	if(top==-1)
	{
		printf("\nSTACK UNDER FLOW !!");
	}
	else
	{
		item=stack[top];
		top--;
		printf("\nTHE POPED ITEM IS %d",item);
	}
}
void peep()
{	
	if(top==-1)
	{
		printf("\nThe stack is empty!!");
	}
	else
	{
		printf("\nTHE TOP ELEMENT IS %d ",stack[top]);
	}
}
void display()
{
	int i;
	printf("\nThe STACK is: \n");
	for(i=top;i>=0;i--)
	{
		printf("%d \t",stack[i]);
	}
}
void main()
{
	push();
	push();
	push();
	push();
	display();
	pop();
	pop();
	display();
	peep();
	display();
}
