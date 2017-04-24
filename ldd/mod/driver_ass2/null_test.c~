#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
 int fd;
 char buff[100];
fd=open("/dev/mynull", O_RDWR);
if(fd<0)
{
 printf(" device can't open\n");
 exit(1);
}
write(fd, "abc", 3)
read(fd,buff, 100);
printf(" message from null driver is %s", buff);
return 0;

}
