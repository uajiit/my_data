
struct node * linklist_rev(struct node *start)
{




// set the starting point 

prev=NULL;
current= start;
next=current->link;// save the next location into next;
while(1)
{

// always operate on current node

current->link= prev; /*  current link  point to the prev(I.e backward link); 
                      *  it also broken the  forward link 
                      *  between   current and next */

//before moving to next step set prev=current
//otherwise current address will change; 
prev=current;
//now next node address is save into next;
current= next;
next= current->link;// the purpose of next is hold the address of next location

if(current->link ==NULL)
  {
   
    start = current;
    break;
}

return  start;

}










}

