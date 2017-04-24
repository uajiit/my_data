//Strlen – string length
#include<stdlib.h>
#include<stdio.h>
#include"header.h"
int main()
{
 
 char *ptr;
ptr=(char *)malloc(100*sizeof(char));
printf("Enter the String\n");
scanf("%s", ptr);
printf("%d\n", my_strlen(ptr));
free(ptr);
}
