//How to reverse the bits in an interger?
#include<stdio.h>
 int main()
{
int a =5 ,b,i, c=0;

 for(i=0; i<=31;i++)
{
  b= (a >>i)&0x1;
  c= c | b<< 31-i;
}
printf("%x\n", c);
return 0;
}
