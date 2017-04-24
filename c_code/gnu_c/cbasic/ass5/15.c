//WAP Swap any two numbers using bitwise operators. How it works
#include<stdio.h>
int main()
{
 int a, b;
printf("Enter the number\n");
scanf("%d %d", &a, &b);
printf(" before swaping a=%d, b=%d\n", a, b);
a= a^b;
b= a^b ; // b=(a+b) -b
a= a^b ; // a= (a+b) -(b=a)
printf(" after swaping a=%d  and b=%d \n",a,b);
return 0;
}
