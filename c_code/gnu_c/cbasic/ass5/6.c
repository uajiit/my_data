// program to covert little endian to big indian
#include<stdio.h>
int main()
{
 int a, b;
printf("Enter the number \n");
fscanf(stdin," %x", &a);
fprintf(stdout,"Entered number of conversion is %x \n", a);

b= ((a & 0x000000ff) <<24 )| ((a & (0x0000ff00))<<8) | ((a & (0x00ff0000))>> 8)  | ((a & 0xff000000)>> 24);
fprintf(stdout ," number is big endian format is  %x \n", b); 

return 0;
}
