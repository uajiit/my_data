#include<stdio.h>
int main( int argc, char *argv[])
{
int n,i,j,k;
printf(" Enter the number of lines \n");
scanf("%d", &n);
for( i=1; i<=n; i++)
{
for(j=n; j>i; j--)
printf(" ");
for(j=1; j<=i;j++)
printf("%d", j  );
for(k=1;k <=i-1;k++ )
printf("%d",--j-1);
printf("\n");
}
for( i=1; i<=n; i++)
{
for(j=1; j<i; j++)
printf(" ");
for(j=1; j<=n-(i-1);j++)
printf("%d",j);
for(k=1;k <= n-(i);k++ )
printf("%d",--j-1);

printf("\n");
}






return 0;
}
