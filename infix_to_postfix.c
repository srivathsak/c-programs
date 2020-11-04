#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 20
char stack[SIZE];
int top = -1;
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.\n");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;
	if(top <0)
	{
		printf("\nInvalid Infix Expression\n");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int check_operator(char symbol)
{
	if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}
int precedence(char symbol)
{
  if(symbol=='^')
	{
		return 3;
	}
	else if(symbol=='*'||symbol=='/')
	{
		return 2;
	}
	else if(symbol=='+'||symbol=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i=0, j=0;
	char *item, x;
	push('(');
	strcat(infix_exp,")");
	item=infix_exp;
	while(*item != '\0')
	{
		if(*item == '(')
		{
			push(*item);
		}
		else if(isalnum(*item))
		{
			postfix_exp[j] = *item;
			j++;
		}
		else if(check_operator(*item) == 1)
		{
			while(precedence(stack[top])>=precedence(*item))
			{
				postfix_exp[j]=pop();
				j++;
			}
			push(*item);
		}
		else if(*item == ')')
		{
			while((x=pop()) != '(')
			{
				postfix_exp[j] = x;
				j++;
			}
		}
		else
		{
			printf("\nInvalid Infix Expression.\n");
			getchar();
			exit(1);
		}
		item++;
	}
	postfix_exp[j] = '\0';
}
int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nEnter Infix expression :  ");
	scanf("%s",infix);
	InfixToPostfix(infix,postfix);
	printf("\nPostfix Expression :  ");
	puts(postfix);
  printf("\n\n");
	return 0;
}
