#include"headers.h"
#include<stdio.h>
#include<stdlib.h>
struct node *addatend(struct node *start)
{

struct node *current, *temp;
temp=start;
if(temp== NULL)
{
printf("linklist not exist\n");
}
while(temp->next !=NULL)
{

temp=temp->next;

}

current= malloc(sizeof(struct node));
temp->next=current;
current->prev=temp; 
printf("Enter the data to add\n");
scanf(" %d",&(current->info));
current->next=NULL;
printf("\n");
return current;
}

