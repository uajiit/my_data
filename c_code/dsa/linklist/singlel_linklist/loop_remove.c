// program to  loop  remove from  link list.
#include "headers.h"

void loop( struct link_list *start)
{
 struct link_list *current= start;
 struct link_list *next= start;
 while(next->node != NULL )
  {
     current = current->node;
     next= next->node->node;
     /* if address of current node is equal to next node */
     if ( current == next)
        {
         flag=1;
         
       }
      else
        {
         flag=0;
        }
/*
      if (flag == 1)
         {
           fix=current; 
          while( fix != current->node && current ->node == current->node->node)              current= current->node;
         }

*/

  }
if(flag==1)
 printf("loop exist in link list \n");

else
  printf("loop does not exist in link list\n ");

return;
}

