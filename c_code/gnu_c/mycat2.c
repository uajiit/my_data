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

char buff[1000];

if (argc ==1)
{
ret=read (0, buff , 1000);
write( 1, buff,ret);  

exit(0);
}
i=1;
for(argc; (argc-1) >=1; argc--)
{

fd= open(argv[i],O_RDWR| O_CREAT, 0700);

if(fd<0)
{
perror(" FILE ONENING EROOR");
exit(1);

}


while((ret =read(fd, buff, 10))!= 0)
{

if(ret<0)
{
perror(" Read Error");
 exit(1);
}
if(write(1,buff,  ret )< 0)
{
perror( " Write  Error");
exit(1);
}


}

i++;
}

close(fd);
return 0;
}
