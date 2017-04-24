
%-----------------head commmand-----------------------------%

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
int fd,i;
 char buff;
int ret,count=1;
fd =open(argv[1], O_RDONLY);
  while(1)
  {
   ret=read(fd, &buff, 1);
    write(1, &buff, ret); 
    if(ret== 0)
       exit(0);
    if(buff== '\n')    
     count++;
     if(count == 10)
       exit(0); 
  }

return 0;
}
