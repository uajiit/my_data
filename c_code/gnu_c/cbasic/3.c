#include<stdio.h>
int main(int argc, char **argv)
{
	struct abc{
		int a[10];
		int i;
		int j,temp;

	}xyz;

	for((xyz.i)=0; (xyz.i)<10; (xyz.i)++)
		scanf("%d", &xyz.a[xyz.i]);
	for((xyz.i)=0; (xyz.i)<9; (xyz.i)++)
		for((xyz.j)=xyz.i;(xyz.j)<10;(xyz.j)++)
			if((xyz.a[xyz.i])>(xyz.a[xyz.j]))
			{
				xyz.temp=xyz.a[xyz.i];
				xyz.a[xyz.i]=xyz.a[xyz.j];
				xyz.a[xyz.j]=xyz.temp;
			}     
	printf(" Numbers in accending order is \n" );

	for((xyz.i)=0; (xyz.i)< 10; (xyz.i)++)
		printf("%d  ", xyz.a[xyz.i]);
	printf("\nSmallest Number is %d and  Biggest is  %d", xyz.a[0], xyz.a[9]);


	return 0;
}
