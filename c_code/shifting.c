#include<stdio.h>
int main()
{
int a=0x1234;
  
 //a= (a& 0x0f0f)<<4|(a& 0xf0f0)>>4;
a= (a& 0xf)<<4|(a& 0xf0)>>4| (a& 0xf000)>>4| (a&0x0f00)<<4 ;
  
printf("%x",a);

}
