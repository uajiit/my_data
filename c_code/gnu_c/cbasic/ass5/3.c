//WAP implement addition functionality with out using ADD('+') Operator.
#include<stdio.h>
int main()
{

int a, b;
fprintf(stdout,"enter the numbers \n");
fscanf(stdin, " %d %d", &a, &b);
fprintf( stdout," %d+%d = %d \n",a, b, a- ((~b) +1));




return 0;
}
