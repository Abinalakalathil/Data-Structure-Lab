#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head=NULL;

void create();
void insert_beg();
void insert_pos();
void insert_end();
void delete_beg();
void delete_pos();
void delete_end();
void delete_all();
void search();
void display();
void main()
{
int ch;
do
{
printf("\n!!!OPERATIONS ON SINGLY LINKEDLISTS!!!\n");
printf("\n1.Create\n2.Insert a node at the begining\n3.Insert a node at specified position\n4.Insert a node at the end\n5.Delete a node from the begining\n6.Delete a node from specified position\n7.Delete a node from the end\n8.Delete the entire linklist\n9.Search for an element\n10.Display the linklist\n11.Exit\n");
printf("\nenter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
insert_beg();
break;
case 3:
insert_pos();
break;
case 4:
insert_end();
break;
case 5:
delete_beg();
break;
case 6:
delete_pos();
break;
case 7:
delete_end();
break;
case 8:
delete_all();
break;
case 9:
search();
break;
case 10:
display();
break;
case 11:
exit(0);
break;
default:
printf("\ninvalid choice!");
break;
}
}
while(ch!=11);
}
void create()
{
struct node *temp,*ptr;
temp=(struct node *)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("\nmemory cannot be allocated\n");
}
printf("\nenter the value:");
scanf("%d",&temp->data);
temp->next=NULL;
if(head==NULL)
{
head=temp;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
}
void insert_beg()
{
struct node *ptr;
int item;
ptr=(struct node*)malloc(sizeof(struct node*));
if(ptr==NULL)
{
printf("\noverflow!");
}
else
{
printf("\nenter the value:");
scanf("%d",&item);
ptr->data=item;
ptr->next=head;
head=ptr;
printf("\nnode is inserted!");
}
}
void insert_pos()
{
int i,loc,item;
struct node *ptr,*temp;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\noverflow!");
}
else
{
printf("\nenter the value:");
scanf("%d",&item);
ptr->data=item;
printf("\nenter the location after which you want to insert:");
scanf("%d",&loc);
temp=head;
for(i=0;i<loc;i++)
{
temp=temp->next;
if(temp==NULL)
{
printf("\nnode can't be inserted!");
return;
}
}
ptr->next=temp->next;
temp->next=ptr;
printf("\nnode is inserted!");
}
}
void insert_end()
{
struct node *ptr,*temp;
int item;
ptr=(struct node*)malloc(sizeof(struct node));
if(ptr==NULL)
{
printf("\noverflow");
}
else
{
printf("\nenter the value:");
scanf("%d",&item);
ptr->data=item;
if(head==NULL)
{
ptr->next=NULL;
head=ptr;
printf("\nnode inserted!");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=ptr;
ptr->next=NULL;
printf("\nnode inserted!");
}
}
}
void delete_beg()
{
struct node *ptr;
if(head==NULL)
{
printf("\nlist is empty!");
}
else
{
ptr=head;
head=ptr->next;
free(ptr);
printf("\nnode deleted from beginning!");
}
}
void delete_pos()
{
struct node *ptr,*ptr1;
int loc,i;
printf("\nenter location of node after which deletion is to be performed:");
scanf("%d",&loc);
ptr=head;
for(i=0;i<loc;i++)
{
ptr1=ptr;
ptr=ptr->next;
if(ptr==NULL)
{
printf("\ncan't delete!");
return;
}
}
ptr1->next=ptr->next;
free(ptr);
printf("\ndeleted node %d",loc+1);
}
void delete_end()
{
struct node *ptr,*ptr1;
if(head==NULL)
{
printf("\nlist is empty!");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("\nonly node of the list is deleted");
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr1=ptr;
ptr=ptr->next;
}
ptr1->next=NULL;
free(ptr);
printf("\ndeleted node from the last!");
}
}
void delete_all()
{
struct node *temp;
while(head!=NULL)
{
temp=head;
head=head->next;
free(temp);
}
printf("\nsuccessfully deleted entire nodes of linked list!");
}
void search()
{
struct node *ptr;
int item,i=0,flag=0;
ptr=head;
if(ptr==NULL)
{
printf("\nempty list!");
}
else
{
printf("\nenter item to be searched?\n");
scanf("%d",&item);
while(ptr!=NULL)
{
if(ptr->data==item)
{
printf("\nitem found at location %d",i+1);
flag=0;
}
else
{
flag=1;
}
i++;
ptr=ptr->next;
}
if(flag==1)
{
printf("\nitem not found!");
}
}
}
void display()
{
struct node *ptr;
ptr=head;
if(ptr==NULL)
{
printf("\nno dataitems found so nothing to print!");
}
else
{
printf("\nprinting values ...\n");
while(ptr!=NULL)
{
printf("\n%d",ptr->data);
ptr=ptr->next;
}
}
}









