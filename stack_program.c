#include<stdio.h>
#include<stdlib.h>
#define stack_size 5
int s[stack_size];
int top = -1;
int item;
void push()
{
	if(top==stack_size-1)
  {
		puts("\tSTACK IS FULL");
	}
	else
  {
		printf("\tEnter the Element To Push : ");
		scanf("%d",&item);
		top = top+1;
		s[top]=item;
		printf("\t%d is Succesfully Pushed Into Stack.\n",item);
	}
}
void pop()
{
	int trash;
	if (top == -1)
	{
		puts("\tSTACK IS EMPTY");
	}
	else
	{
		trash = s[top];
		printf("\t%d is deleted from the stack\n\n",s[top]);
		top =top-1;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		puts("\tSTACK IS EMPTY");
	}
	else
	{
		puts("\t STACK ELEMENTS ARE");
		for(i=top;i>=0;i--)
    {
			printf("\t\t| %d |\n",s[i]);
		}
		puts("\t\t------\n");
	}
}
int main()
{
	int n;
	while(1)
	{
    puts("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
    printf("$ > ");
	  scanf("%d",&n);
    switch(n)
	  {
      case 1 : push();
		           break;
	    case 2 : pop();
		           break;
	    case 3 : display();
		           break;
	    case 4 : exit(0);
      default : puts("\t\tINVALID CHOICE");
	   }
	 }
        return 0;
}
