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
int temp1,temp2,ret,count=1;
fd =open(argv[1], O_RDWR);
while(1)
{
   ret=read(fd,&buff,1);
     
   //write(1,buff,ret); 
   temp1=count++;
   
    if(ret ==0)
       break;
}


  while(1)    
     { 

  //     temp2=count--;
       
       if(buff != '\n')
         {
           
            
          if ( temp1-temp2 == 9)
           {
              while(1)
                {
                 count=1;
                ret=read(fd, &buff, 1);
                write(1, &buff, ret); 
                if(ret==0)
                exit(0);
                if( buff== '\n')    
                  count++;
                 if(count == 10)
                  exit(0); 
                }
       }
  }
}

close(fd);
return 0;
}
