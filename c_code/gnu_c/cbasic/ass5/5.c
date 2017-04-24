//WAP to implement the sizeof operation using bitwise operator

// this code is only applicable for non-zero data.
#include<stdio.h>
int main()
{
int a=5, count=0;

while((a= (a<<1)) != 0)
 count++;
printf("%d\n", (count+1)/8);

return 0;
}
