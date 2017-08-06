#include<stdio.h>
#include"headers.h"

void rev_linklist_display(struct node *start)
{

struct node *current,*prev;
current=start;
prev=start;
while(current->link !=NULL)// move one step forward to check the status of node
{
prev=current;
current =current->link;//current pointing to next element 
//prev->link= current; // prev->link contains address of current

}
// move back
while(1)
{
printf("DATA: %d & next-address: %p --->", current->info, current->link); 

current =prev;
prev->link=current;

prev=(struct node *) (&(prev->link) - &(((struct node *)0)->link));

//prev->link=current;

if(prev->link == start )// at the first node

break;

}

}
