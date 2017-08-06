#include<stdio.h>
#include"headers.h"

void operation(int n);
struct node *start=NULL;
int main()
{
int n;
while(1)
{

printf("Enter 1 for create the linklist\n ");
printf("Enter 2 for delete the  linklist\n ");
printf("Enter 3 for display the linklist\n ");
printf("Enter 4 for  insert into the link list \n ");
printf("Enter 5 for remove the element from the linklist\n");
printf("Enter 6 to display is reverse\n");

printf("press 7 for stop operation\n");
scanf(" %d",&n);
if (n== 7)
break;

operation(n);
printf("\n");
}

printf("Good bye\n");
return 0;
}

void operation(int n)
{
switch(n)
{
case 1:
       start= create(start);
        break;
case 2:
      //delete();
      break;
case 3:
      display(start);
      break;
case 4:
       //insert();
       break;
case 5:
       //remove();
       break;

case 6: rev_linklist_display(start);
         break;

}

}

