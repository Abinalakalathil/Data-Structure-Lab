#include<stdio.h>
#include<conio.h>


void push();
void pop();
void display();

struct node
{
int data;
struct node *next;
};

struct node *head=NULL;

void main()
{
int ch;
do
{
printf("1:push 2:pop3:display 4:exit \n");
printf("enter your choice \n");
scanf("%d",&ch);

switch(ch)
{
case 1:
{
      push();
      break;
 }

 case 2:
    {
     pop();
     break;
     }
case 3:
    {
    display();
    break;
    }

case 4:
   {
   exit(0);
   break;
   }
default:
{
printf("invalid choice");
break;
}
}
}while(ch!=4);

getch();
}

void push()
{
int item;
struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("overflow");
}
else
{
printf("enter the value \n");
scanf("%d",&item);

if(head==NULL)
{
ptr->data=item;
ptr->next=NULL;
head=ptr;
}
else
{
ptr->data=item;
ptr->next=head;
head=ptr;
}
printf("item is pushed \n");
}
}

void pop()
{
struct node *ptr;
if(head==NULL)
{
printf("underflow condition \n");
}
else
{
ptr=head;
head=ptr->next;
free(ptr);
printf("item is poped \n");
}
}

void display()
{
struct node *ptr;
ptr=head;
if(ptr==NULL)
{
printf("empty stack \n");
}
else
{
printf("printing values...\n");
while(ptr!=NULL)
{
printf("%d",ptr->data);
ptr=ptr->next;
}
}
}
