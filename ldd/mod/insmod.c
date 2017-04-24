#include<stdio.h>   
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include<linux/version.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int fd;
	char *var;
	struct stat sc;
	fd = open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("");
		exit(0);
	}
	fstat(fd, &sc);
	var= (char * )mmap((void *) 0,sc.st_size,PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);
	init_module(var, sc.st_size,);
	return 0;
}


