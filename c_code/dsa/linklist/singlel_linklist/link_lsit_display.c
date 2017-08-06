#include<stdio.h>
#include<stdlib.h>
#include"headers.h"
void display(struct node *start)
{

struct node *current;
current=start;
//current = (struct node *) malloc(sizeof(struct node));
while(current !=NULL)
{

printf("data:%d next-address :%p -----> ", current->info,current->link);
current= current->link;
}

printf ("\n");



}

