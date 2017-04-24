#include<stdio.h>
#define mysize(x) (char*)( &x +1)- (char*)(&x)

int main()
{

int b=14;
printf("%d", mysize(b));

return 0;
}
