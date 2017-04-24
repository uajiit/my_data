#include<stdio.h>
int main()
{
 double a=4;
int i=0;
double *p1= &a;
char *p2;
p2=p1; 
p1++;
while(1)
{
if(p2++ ==p1 )
{
 break;
}
i++;
}

printf(" %d", i);

}
