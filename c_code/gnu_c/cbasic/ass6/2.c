//Strrev – string reverse
#include<stdio.h>
#include <stdlib.h>

void str_rev( char *);
#define SIZE 100
int main()
{
char str[100];
printf("enter the string \n");
scanf("%s",str);
 //printf("%s", str_rev(str));
str_rev(str);
//printf("hello");

}


