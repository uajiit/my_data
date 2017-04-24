#include<stdio.h>
#include<string.h>
int main()
{

char abc[6]= "hello";
char *xyz ="world";
char *ptr=abc;
printf("%s\n", ptr );
strcpy(ptr, abc);
printf(" %s\n", ptr);
ptr = xyz;
printf("%s\n", ptr );
strcpy(ptr, xyz);
printf("%s\n", ptr);
return 0;
}
