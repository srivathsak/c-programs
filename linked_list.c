#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
struct node
{
int info;
struct node*link;
};
typedef struct node* NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("\n\nOUT OF MEMEORY \n\n");
exit(0);
}
return x;
}
NODE insertfront(int item,NODE first)
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
printf("\nLIST IS EMPTY\n\n");
return;
}
printf("\n\nTHE CONTENTS ARE\n");
temp=first;
while(temp!=NULL)
{
printf("%d\t",temp->info);
temp=temp->link;
}
printf("\n\n");
}
NODE delfront(NODE first) //FUNCTION TO DELETE FIRST NODE
{
NODE temp;
if(first==NULL)
{
printf("\n\nLIST IS EMPTY\n\n");
return first;
}
temp=first;
first=first->link;
printf("\n\nDELETED ITEM =%d\n\n",temp->info);
free(temp);
return first;
}
NODE insertrear(int item,NODE first)
{
NODE temp,cur;
temp=getnode();
temp->info=item;
temp->link=NULL;
if(first==NULL)
{
return temp;
}
cur=first;
while(cur->link!=NULL)
{
cur=cur->link;
}
cur->link=temp;
return first;
}
NODE delrear(NODE first)
{
NODE cur,prev;
if(first==NULL)
{
printf("\n\nLIST IS EMPTY\n\n");
return first;
}
if(first->link==NULL)
{
printf("\n\nDELETED ITEM IS %d\n\n",first->info);
free(first);
first=NULL;
return first;
}
prev=NULL;
cur=first;
while (cur->link!=NULL)
{
prev=cur;
cur=cur->link;
}
printf("\n\nDELETED ITEM %d\n\n",cur->info);
free(cur);
prev->link=NULL;
return first;
}
NODE insertpos(int item,int pos,NODE first)
{
NODE temp,prev,cur;
int counter;
temp=getnode();
temp->info=item;
temp->link=NULL;
if (first==NULL &&pos==1)
return temp;
if(first==NULL)
{
printf("\n\nINVALID POSITION\n\n");
return first;
}
if(pos==1)
{
temp->link=first;
return temp;
}
counter=1;
prev=NULL;
cur=first;
while(cur!=NULL&&counter!=pos)
{
  prev=cur;
cur=cur->link;
counter++;
}
if(counter==pos)
{
prev->link=temp;
temp->link=cur;
return first;
}
else
printf("\n\nINVALID POSITION\n\n");
return first;
}
NODE delinfo(int item,NODE first)
{
NODE prev,cur;
if(first==NULL)
{
printf("\n\nLIST IS EMPTY\n\n");
return NULL;
}
if(item==first->info)
{
cur=first;
first=first->link;
free(cur);
return first;
}
prev=NULL;
cur=first;
while(cur!=NULL&&item!=cur->info)
{
prev=cur;
cur=cur->link;
}
if(cur==NULL)
{
printf("\n\nITEM NOT FOUND\n\n");
return first;
}
prev->link=cur->link;
free(cur);
return first;
}
NODE delpos(int pos,NODE first)
{
NODE cur,prev;
int counter;
if(first==NULL)
{
printf("\n\nLIST IS EMPTY\n\n");
return NULL;
}
if(pos==1)
{
cur=first;
first=first->link;
free(cur);
return first;
}
prev=NULL;
cur=first;
counter=1;
while(cur!=NULL&&counter!=pos)
{
prev=cur;
cur=cur->link;
counter++;
}
if(cur==NULL)
{printf("\n\nINVALID POSITION\n\n");
return first;
}
else
prev->link=cur->link;
free(cur);
return first;
}
void search(int item,NODE first)
{
NODE cur;
int pos;
if(first==NULL)
{
printf("\n\nLIST EMPTY\n\n");
return;
}
cur=first;
pos=1;
while(cur!=NULL&&item!=cur->info)
{
cur=cur->link;//POINT CUR TO NEXT NODE
pos++;
}
if(cur==NULL)//END OF LL NIOT FOUND
{
printf("\n\nSEARCH UNSUCCESSFUL\n");
return;
}
printf("SEARCH SUCCESSFUL &ITEM FOUND AT %d\n\n",pos-1);
}
int main()
{NODE first=NULL;
  int ch,item,pos;
pos=0;
while(1)
{
printf("\nENTER YOUR CHOICE\n");
printf("1.INSERT AT FRONT END\n2.INSERT AT REAR END\n3.DELETE AT FRONT END\n");
printf("4.DELETE AT REAR END\n5.INSERT AT SPECIFIED POSITION\n");
printf("6.DELETE A PARTICULAR ELEMENT\n");
printf("7.DELETE AT SPECIFIED POSITION\n");
printf("8.SEARCH FOR A PARTICULAR ELEMENT\n");
printf("9.DISPLAYING THE LINKED LIST\n");
printf("10.EXIT\n$ > ");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\nENTER THE ELEMENT : ");
 scanf("%d",&item);
 first=insertfront(item,first);
 break;
case 2:printf("\nENTER THE ELEMENT : ");
 scanf("%d",&item);
 first=insertrear(item,first);
 break;
case 3:first=delfront(first);
 break;
case 4:first=delrear(first);
 break;
case 5:printf("\nENTER THE ITEM TO BE INSERTED : ");
 scanf("%d",&item);
 printf("\nENTER THE POSITION OF INSERTION : ");
 scanf("%d",&pos);
 first=insertpos(item,pos,first);
 break;
case 6:printf("\nENTER THE ELEMENT TO BE DELETED : ");
 scanf("%d",&item);
 first=delinfo(item,first);
 break;
case 7:printf("\nENTER THE POSITION OF DELETION : ");
 scanf("%d",&pos);
 first=delpos(pos,first);
 break;
case 8:printf("\nENTER THE SEARCH ELEMENT : ");
 scanf("%d",&item);
 search(item,first);
 break;
case 9: display(first);
 break;
case 10:exit(0);
default:printf("\n\nWRONG CHOICE!!TRY AGAIN\n\n");
}
}
return 0;
}
