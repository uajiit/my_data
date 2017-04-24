// program to check whether a nuber is even or odd
#include<stdio.h>
int main()
{
int a;
 while(1)
{
 printf("Enter the number \n");
  scanf(" %d", &a);
  if ((a & 0x1) == 0x0)
  fprintf(stdout ," %d is even number \n", a);

  else
   fprintf(stdout, " %d is odd number \n ",a);
}






return 0;
}
