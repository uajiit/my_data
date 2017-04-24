 #include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>

#include<string.h>
 int main(int argc, char *argv[])
{


int j,len,fd2,fd3;
char *temp;



open("ruj", O_DIRECTORY|O_CREAT,0666);





//         len = strlen(argv[argc-1]);
#if 0         
  if(mkdir("/home/ajit/rajiu3/",0777)<0)
			{
				perror("directory creation fails");
				exit(1);
                        }
#endif
  //              for (j=0; j<= len;j++)	  
                        
    //                {
      //                if (j!=len)
        //              *(temp+j)= *(argv[argc-1]+j);
          //            else
            //             *(temp+len)= '\0';
                         
              //       }
                //      printf("%s\n",temp);
#if 0                 
for (j=0; j<= len;j++)	  
                        
                    {
                      if (j!=len)
                      temp[j]= *(argv[argc-1]+j);
                      else
                         temp[len]= '\0';
                         
                     }    
 if((fd2= open("/home/ajit/raju3/",0666))<0)
                         { 
                            perror(" directory opening fails");
                            exit(1);

			}

                        if ((fd3=creat("/home/ajit/rajiu3/aj",0777 ))<0)
			{
				perror(" file creation in directory fails");
				exit(1);

			}
                         

#endif



//close(fd3);
//close(fd2);
exit(0);
}
