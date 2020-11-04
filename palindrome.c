#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
char stack[SIZE];
int top=-1;
void push(char item)
{
	if(top==SIZE-1)
	{
		printf("Entered String is too Long\n");
		exit(0);
	}
	else{
		stack[++top]=item;
	}
}
char pop()
{
	char item;
	item=stack[top--];
	return item;
}

int checkpalindrome(char str[],char revstr[])
{
	char *ch;
	int i=0,flag=1;
	ch = str;
	while(*ch!='\0')
	{
		push(*ch);
		ch++;
	}
	while(top!=-1)
	{
		revstr[i]=pop();
		if(revstr[i]!=str[i])
		{
			flag=0;
			break;
		}
		i++;
	}
	return flag;
}
int main()
{
	int a;
	char str[SIZE],revstr[SIZE];	
	printf("\nEnter a string : ");
	scanf("%s",str);
	a=checkpalindrome(str,revstr);
	if(a==1)
	{
		printf("\n\tString is Palindrome\n\n");
		exit(0);
	}
	printf("\n\tString is NOT Palindrome\n\n");
	return 0;
}
