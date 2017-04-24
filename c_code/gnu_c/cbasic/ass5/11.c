//WAP Check if the 20th bit of a 32 bit integer is on or off
#include<stdio.h>
int main()
{
int a; 
printf("Enter the number");
scanf("%d",&a);
if((a & (1<<20-1))==1)
printf("Bit is set");
else
 printf("Bit  is clear");


return 0;
}
