//Write a functionsetbits(x,p,n,y)that returns x with then bits that begin at position p 
//set to the rightmost n bits of y, leaving the other bits unchanged
#include<stdio.h>
funsetbit( int x, int p, int n, int y)
{
	int y1=0x0, i=n;
	while(i!=0 )
	{
		y1= y1| (y& (0x1<<(n-i)));
		i--;
	}
	//printf("%x\n",y1);
	return (x|(y1<<(p-n)));
}

int main()
{
	int x=0xAA,y=0xA7,n=3,p=6;

	printf("%x \n",funsetbit(x,p,n,y));

	return 0;
}
