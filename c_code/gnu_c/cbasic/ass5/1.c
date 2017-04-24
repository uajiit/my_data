#include<stdio.h>
#define BIT_SET(n,p)  n|(0x01<<p)
#define BIT_CLEAR(n,p) n & ~(0x01 <<p)  
#define BIT_TOGGLE(n,p) n^(0x01<<p)
void f(int x)
{
int i, mask;
for(i=31;i>=0;i--)
{
mask=1<<i;
putchar((x&mask)?'1':'0');
if(i%8==0)
putchar(' ');
}
}
int main()
{

int x;
x=BIT_SET(0x45678912, 5);
f(x);
x=BIT_CLEAR(0x12345678,3);
f(x);
x=BIT_TOGGLE(0xAB12ED23,2);
f(x);
return 0;
}

