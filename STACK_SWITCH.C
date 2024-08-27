#include<stdio.h>
#include<stdlib.h>
#define N 30
int main()
{
	int stack[N];
	int top=-1;
	int i,ch;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					int x;
					printf("\nEnter the item: ");
					scanf("%d",&x);
					if(top==N-1)
					{
						printf("\n STACK OVER FLOW!!");
					}
					else
					{
						top++;
						stack[top]=x;
					}
					break;
			case 2:
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
						break;
			case 3:
					if(top==-1)
					{
						printf("\nThe stack is empty!!");
					}
					else
					{
						printf("\nTHE TOP ELEMENT IS %d ",stack[top]);
					}
					break;
			case 4:
					int i;
					printf("\nThe STACK is: \n");
					for(i=top;i>=0;i--)
					{
						printf("%d \t",stack[i]);
					}
					break;
			case 5:
				exit(0);
				default:
					printf("\nInvalid Choice !!");
					break;
		}
	}
	return 0;
}
