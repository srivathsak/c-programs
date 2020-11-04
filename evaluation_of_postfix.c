#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 20
char postfix[SIZE];
double stack[SIZE];
int top = -1;
void push(double n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("\nStack is Full! Invalid Operation\n");
		exit(0);
	}
}
double pop()
{	
	double n;
	if (top > -1)
	{
		n = stack[top--];
		return n;
	}
	else
	{
		printf("\nStack is Empty! Invalid Operation\n");
		exit(0);
	}
}

int main()
{
	int i;
        double  a, b, result, eval;
	char *ch;
	printf("\nEnter The Postfix Expression: ");
	scanf("%s",postfix);
	ch = postfix;
	while(*ch!='\0')
	{
		if(isdigit(*ch))
		{
			push((*ch)-'0');
		}
		else if(*ch =='+'||*ch =='-'||*ch =='*'||*ch =='/'||*ch=='^'||*ch=='$')
		{
			b = pop();
			a = pop();
			
			switch(*ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
				case '^': 
				case '$': result = pow(a,b);
					  break;
			}
			push(result);
		}
                 else{
                    printf("\n Invalid Operation \n\n");
		    exit(0);
                 }
                 ch++;		
	}
	eval = pop();
	printf("\nThe Result is:  %f",eval);
	printf("\n\n");
	return 0;
}
