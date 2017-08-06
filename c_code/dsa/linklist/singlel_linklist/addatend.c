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
while(temp->link !=NULL)
{

temp=temp->link;

}

current= malloc(sizeof(struct node));
temp->link=current;
printf("Enter the data to add\n");
scanf(" %d",&(current->info));
current->link=NULL;
printf("\n");
return current;
}

