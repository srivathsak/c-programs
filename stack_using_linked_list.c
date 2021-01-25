#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
int info;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("OUT OF MEMEORY \n\n");
exit(0);
}
return x;
}
NODE insert_front(int item,NODE first)
{
NODE temp;
temp=getnode();
temp->info=item;
temp->link=first;
return temp;
}
void display(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("STACK IS EMPTY\n\n");
return;
}
printf("\nTHE ELEMENTS ARE : ");
temp=first;
while(temp!=NULL)
{
printf("%d\t",temp->info);
temp=temp->link;
}
printf("\n\n");
}
NODE delfront(NODE first)
{
NODE temp;
if(first==NULL)
{
printf("\nSTACK IS EMPTY\n\n");
return first;
}
temp=first;
first=first->link;
printf("\nDELETED ITEM =%d\n\n",temp->info);
free(temp);
return first;
}
void main()
{
NODE first;
int choice, item;
first=NULL;
for(;;)
{
printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("$ > ");
scanf("%d",&choice);
switch(choice)
{
case 1: printf ("\nEnter the item to be inserted: ");
 scanf("%d",&item);
 first=insert_front(item,first);
 printf("%d is succesfully inserted into stack\n\n",item);
break;
case 2: first=delfront(first);
break;
case 3: display(first);
break;
case 4: exit (0);
default: printf("\nINVALID CHOICE\n\n");
}
}
}
