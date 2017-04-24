//Write a program to reverse a. Odd bits of an integer b. Even bits of an integer
#include<stdio.h>
int main()
{
int a, i =0, b=0xffff;
printf("Enter the value of a");
fscanf(stdin, " %d", &a);
for (i=0; i< 31; i++)
b=  ((a&(1<<i))<<1 | ( a & (1<<(i+1)))>>1);
fprintf(stdout," %d\n", b);
return 0;
}
