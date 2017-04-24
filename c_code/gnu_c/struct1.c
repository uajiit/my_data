#include<stdio.h>
int main( int argc, char *argv[])
{
int d=10;
 
struct abc7
{
int a;
int b; 
int *c;
struct abc *my_next;

}y={ 10, 20},*z;
y.c=&d;

struct abc
{

int d2;
int e;
int *g; 


}h={10,4,NULL}, *my_next=&h;
printf("%d\n",*(y.c));
printf("%d",  (*(z).my_next)->e);
//printf("%d", (y.my_next)->d2);
return 0;

}

