


#include<stdio.h>
int main()
{
int a=0x45678912;
int *p;
p=&a;
if ( *(char *) p == *((char *) &a))
printf(" little endian");
else 
 printf(" big endian");

return 0;
}
