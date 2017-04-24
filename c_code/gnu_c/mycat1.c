#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 #include <unistd.h>
 #include <unistd.h>
#include <stdio.h>


int main( int argc, char **argv)
{

int fd, ret,i;

char buff[1300];



fd= open(argv[1],O_RDWR);

if(fd<0)
{
perror("Error");
exit(1);

}

ret=read(fd, buff, 1300);
while(ret != 0)
{

if(write(1,buff,  ret )< 0)
{
perror( " Write  Error");
exit(1);
}

if(ret=read(fd, buff, 1300)<0)
{

 perror(" Read Error");
 exit(1);
}



}


close(fd);
return 0;
}
