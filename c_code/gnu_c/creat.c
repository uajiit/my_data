#inlude<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 #include <unistd.h>
 #include <unistd.h>
#include <stdio.h>


int main( int argc, char **argv)
{


int fd;


fd= open(argv[1],O_RDWR|O_CREAT, 00700);
close(fd);
}
