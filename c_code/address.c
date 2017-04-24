#include<stdio.h>
int main()
{

int a='a';
int *p=&a;
printf("%d", &a+1);
printf("%u \n", sizeof(a));
printf(" %ld \n", (p+1)- (p+0));

return 0;
}
