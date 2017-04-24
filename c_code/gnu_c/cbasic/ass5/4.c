//WAP implement XOR functionality with out using XOR() operator
#include<stdio.h>
int main()
{
int a, b;
fprintf(stdout,"enter the numbers \n");
fscanf(stdin, " %x %x", &a, &b);
fprintf( stdout," %x ^ %x = %x \n",a,b ,((a &(~b)) | ((~a) &b)));
return 0;
}
