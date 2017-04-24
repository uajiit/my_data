#include<stdio.h>

#include"dev_header.h"
void dev_open();
int dev_read();
int dev_write(int i);
struct dev_opr dev_value ={
.open = dev_open,
.read=dev_read,
.write=dev_write,
};


void dev_open()
{
printf("device is open successfully\n");
}

int dev_read()
{
int k;
printf("enter the data  to read from memory \n ");

fscanf(stdin," %d", &k);
return k;

}


int dev_write(int i)
{

printf("%d \n", i);

return 0;
}

int main()
{
struct dev_opr *fptr= &dev_value;
int j;
fptr->open();
j=fptr->read();
fptr->write(j);
return 0;
}
