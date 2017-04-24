#include<stdio.h>
#define SIZE 10
int main()
{
	int i,j;
	float a[SIZE],temp;
	printf("Enter the elentes of array");
	for (i=0; i<10;i++)
		scanf("\n%f", &a[i]);
	//big=a[0];
	for(i=0; i<SIZE-1;i++  )
		for( j= i+1; j< SIZE; j++)
		{
			if( a[i]> a[j])
			{
				temp = a[i];   
				a[i]= a[j];
				a[j]= temp;
			}
		}
	for(i=0; i<10; i++)
		printf("%f \t", a[i]);
 printf(" smaller=%f and BIgger=%f \t", a[0], a[9]);
	return 0;
}
