#include<stdio.h>
#include<stdlib.h> 
#define MAX 5
void insert();
void delete();
void display();
int Isempty();
void sort();
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
void sort()
{
         int i,j,temp;
	 for(i=front;i<=rear;i++)
	 {
		 for(j=i+1;j<=rear;j++)
		 {
			 if(queue[i]>queue[j])
			 {
				 temp = queue[i];
				 queue[i] = queue[j];
				 queue[j]=temp;
			 }
		 }
	 }
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
        if (rear == MAX - 1)
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
			rear+=1;
		}
	       	printf("\nEnter the Element to be Inserted : ");
                scanf("%d", &add_item);
                queue[rear] = add_item;
                sort();
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
		printf("Element deleted from queue is : %d\n",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
            printf("\nElement deleted from queue is : %d\n", queue[front]);
            front = front + 1;
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
            for (i = front; i <= rear; i++)
	    {
                printf("%d  ",queue[i]);
	    }
            printf("\n");
        }
} 
