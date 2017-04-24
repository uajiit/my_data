#include<stdio.h>
#include <stdlib.h>

struct link_list
{
int data;
struct link_list *next;
} *node;
struct link_list *head= NULL;

void insert(int data)
{
 
node= (struct link_list *) malloc(sizeof( struct link_list));

node->data= data;
node->next=head;
head = node;
}

void print()
{

struct link_list *ptr= head;  
while( ptr != NULL)
{
printf(" %d ", ptr->data);
ptr= ptr->next;
}

}




int main()
{


insert(2 );
insert(3);

print();
 
return 0;
}
