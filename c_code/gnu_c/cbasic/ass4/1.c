#include<stdio.h>
#define SIZE 100
int main()
{

struct abc{
int i;
int a[SIZE];
}xyz;

printf("\n....................list of numbers are.....................\n");
for ( xyz.i=1; xyz.i<= SIZE ; (xyz.i)++)
printf(" %d \t ",xyz.a[xyz.i]= xyz.i);
printf("\n....................list of Even numbers are.....................\n");
for ( xyz.i=1; xyz.i<= SIZE ; (xyz.i)++)
if (xyz.a[xyz.i] %2 ==0)
printf(" %d \t ",xyz.a[xyz.i]);
printf("\n...................list of  odd numbers are......................\n");
for ( xyz.i=1; xyz.i<= SIZE ; (xyz.i)++)
if (xyz.a[xyz.i] %2 != 0 )
printf(" %d \t ",xyz.a[xyz.i]);
printf("\n..................list of numbers  after adding 5 to each ..........\n");
for ( xyz.i=1; xyz.i<= SIZE ; (xyz.i)++)

printf(" %d \t ",xyz.a[xyz.i] +=5);



}
