#include<stdio.h>
#include "headers.h"
#include<stdlib.h>

struct node *create(struct node *start)
{
  struct node *current, *temp;
  char option;
  int data;
  if (start !=NULL)
  {
    printf("linklist already exist\n");
     
    return start; 
  }
   
  current = start;
  current = (struct node *)malloc(sizeof(struct node));
  if(current != NULL){
  printf("Enter the element\n");
  scanf(" %d", &data);
    current->info= data;
    current->prev=start;
    current->next=NULL;
    start=current; // start point to current which in not NULL
   printf("\n");
   }
  while(current !=NULL)
   {
  
   printf("do you want to insert more element \n press Y for yes and N for No:");
   scanf(" %c", &option);
   printf("\n");
   if(option =='N'|| option == 'n')
     {
     current->next=NULL;
     break;
     }
   else
      current->next= addatend(start);// save the return address in the current link; 
      temp= current;
      /* create the address of  next node*/
      current=current->next; //address of next element
      current->prev=temp;
   }
  
 
 return start;
}
/*
struct node *addatend(struct node *start)
{

struct node *current, *temp;
temp=start;
if(temp== NULL)
{
printf("linklist not exist\n");
}
while(temp !=NULL)
{

temp=temp->link;

}

current= malloc(sizeof(struct node));
temp->link=current;
printf("Enter the data to add\n");
scanf("%d",&(current->info));
current->link=NULL;
return current;
}

*/


