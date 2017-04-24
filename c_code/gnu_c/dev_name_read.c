/* assignment Number 12  */
#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <linux/input.h>


int main()
{

        int fd1;
	char name[256] = "Unknown";

	if((fd1=open("/dev/input/event0",O_RDONLY)<0)
	printf("error while open the file event7\n");
        ioctl(fd1, EVIOCGNAME(sizeof(name)), name);
        printf("Input device name: \"%s\"\n", name);

	return 0;



}
