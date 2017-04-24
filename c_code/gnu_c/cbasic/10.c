#include<stdio.h>
int main( int argc, char *argv[])
{
int i,j,n;
printf(" Number of lines");
scanf("%d", &n);
for(i=1; i<=n; i++) // for  number of lines
{
for (j=1; j<=i; j++)// for each line
printf("* ");
printf("\n");
}

return 0;
}
