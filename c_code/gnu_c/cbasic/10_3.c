#include<stdio.h>
int main( int argc, char *argv[])
{
int n,i,j,k,p;
printf(" Enter the number of lines \n");
scanf("%d", &n);
for( i=1; i<=n; i++)
{
for(j=n; j>i; j--)
printf(" ");
for(j=0; j<i;j++)
printf("%d", p=i+j);
for(k=1;k <=i-1;k++ )
printf("%d",--p);
printf("\n");
}
for( i=1; i<=n-1; i++)
{
for(j=1; j<=i; j++)
printf(" ");
for(j=1; j<=n-i;j++)
printf("%d", );
for(k=1;k < n-(i);k++ )
printf("%d", (--p)-2);

printf("\n");
}






return 0;
}

