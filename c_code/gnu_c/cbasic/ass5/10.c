//WAP to count the bits set (bit value 1 ) in an integer? 
//Find out and compare different possibilities?
#include<stdio.h>
int main( int argc, char *arg[])
{
int a=15;
int i, count=0;
for(i=32;i>0;i--)
{
 if((a & (1<<i-1)) !=0) 
   count++;
}
printf("number of 1 bits are %d \n", count);

return 0;
}
