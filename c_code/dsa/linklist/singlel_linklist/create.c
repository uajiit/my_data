#include<stdio.h>
#include "headers.h"
#include<stdlib.h>

struct node *create(struct node *start)
{
  struct node *current;
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
    current->link=NULL;
    start =current;
   printf("\n");
   }
  while(current !=NULL)
   {
  
   printf("do you want to insert more element \n press Y for yes and N for No:");
   scanf(" %c", &option);
   printf("\n");
   if(option =='N'|| option == 'n')
     {
     current->link=NULL;
     break;
     }
   else
      current->link= addatend(start);// save the return address in the current link; 
      current=current->link; //address of next element
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


