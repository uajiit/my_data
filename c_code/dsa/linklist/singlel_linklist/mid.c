#include "headers.h"

struct node *mid_term( struct node *start)
{
 struct node *current= start;
 struct node *next= start;
 while(next->link != NULL )
  {
     current=current->link;
     next=current->link->link;
     
     
  }
  
return  current;
}




