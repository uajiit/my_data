 #include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <linux/fb.h>
 #include <sys/mman.h>
 #include <sys/ioctl.h>
#include< linux/input.c>
int main()
{

int evfd;
evfd = open("/dev/input/event0", O_RDWR)
     if (evfd == -1) 
        {
           perror("Error: cannot open event0 device");
            exit(1);
        }
  if (ioctl(evfd,) == -1) {
         perror("Error reading fixed information");
         exit(2);
     }









return 0;
}
