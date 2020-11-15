#include <stdio.h>
#include<stdlib.h> 
#define MAX 5
void insert();
void delete();
void display();
int Isempty();
int queue[MAX];
int rear = - 1;
int front = - 1;
int main()
{
	int choice;
        while (1)
        {
            printf("\n1.INSERT\n");
            printf("2.DELETE\n");
            printf("3.DISPLAY\n");
            printf("4.EXIT \n");
            printf("$ > ");
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                insert();
                break;
                case 2:
                delete();
                break;
                case 3:
                display();
                break;
                case 4:
                exit(0);
                default:
                printf("\nInvalid Choice \n");
            } 
        } 
        return 0;
} 
int Isempty()
{
	if(front==-1&&rear==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert()
{
	int add_item;
        if ((rear+1)%MAX == front)
	{
        printf("\nQueue Overflow \n");
	return;
	}
        else
        {
		if(Isempty())
		{
			front=0;
			rear=0;
		}
		else
		{
			rear=(rear+1)%MAX;
		}
	       	printf("\nEnter the Element to be Inserted : ");
                scanf("%d", &add_item);
                queue[rear] = add_item;
		printf("%d is Inserted Into Queue\n",add_item);
        }
} 
void delete()
{
        if (Isempty())
        {
            printf("\nQueue Underflow \n");
            return ;
        }
        else if(front==rear)
        {
		printf("\nElement deleted from queue is : %d\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
            printf("\nElement deleted from queue is : %d\n", queue[front]);
            front = (front + 1)%MAX;
        }
} 
void display()
{
        int i;
        if (Isempty())
	{
            printf("\nQueue is Empty \n");
	}
        else
        {
            printf("\nQueue is : ");
            for (i = front; i!=rear; i=(i+1)%MAX)
	    {
                printf("%d  ",queue[i]);
	    }
            printf("%d",queue[i]);
            printf("\n");
        }
} 

