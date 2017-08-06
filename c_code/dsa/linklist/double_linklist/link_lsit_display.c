#include<stdio.h>
#include<stdlib.h>
#include"headers.h"
void display(struct node *start)
{

struct node *current;
current=start;
//current = (struct node *) malloc(sizeof(struct node));
printf("start:%p\n", start);
while(current !=NULL)
{

printf("|prev-address:%p|data:%d| next-address :%p|\n",current->prev, current->info,current->next);

current= current->next;
 
printf("next:%p\n",current);
}

printf ("\n");



}

