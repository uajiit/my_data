// multipication by 9

#include<stdio.h>
int main()
{
int a;
printf("Enter the number \n");
fscanf(stdin,"%d", &a);

fprintf(stdout,"%d", (a<<3) +a);


return 0;
}
