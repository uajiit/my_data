//Write a program to input a number and count the digits in it.
#include<stdio.h>
int main(int argc, char *argv[])
{
int a,b=0,c,count1=0,count=0;
printf("Enter the number");
scanf("%d", &a);

if(c=a)
{
while(a != 0)
{
 b=b*10 + a%10;
  a= a/10;
 count1= count1+1;
}
printf(" No. of digit is  %d\n", count1);
printf(" No. in Reverse order is  %d\n", b);
if (c==b)
printf("The given No. is a penindrome number\n");
else 
printf("The given No. is  not a penindrome number\n");
}
else
  printf("No. of digits is 1\n");




return 0;
}
