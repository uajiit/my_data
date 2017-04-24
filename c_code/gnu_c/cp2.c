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



int main( int argc, char *argv[])
{
	int i,fd,fd1,fd2,ret;
	char buff[10];
	//char cwd[1024];
   const char  *path ;
 char *temp;
char PresentPath[50];
char *cwd;
DIR *op;
//------------part 1-------------------------------------------------	
if (argc==1)
	{
		printf("cp: missing file operand\nTry 'cp --help' for more information. \n");
		exit(1);

	}

//-----------part 2----------------------------------------------------
	if (argc==2)
	{
		printf("missing destination file operand after '%s'\n Try 'cp --help' for more information\n ", argv[1]);
		exit(1);
	}
//--------------------part 3------------------------------------------
	if(argc==3)
	{

		if((fd1= open(argv[1], O_RDONLY))<0)
		{
			perror(" source file does not exist");
			exit(1);

		}

		if((fd2=open(argv[2],O_WRONLY|O_CREAT, 0777))<0)
		{
			perror("destination file creation fails");
			exit(1);
		}
		while( (ret=read(fd1, buff,10))> 0)
		{

			if (write(fd2,buff,ret) != ret)
			{
				printf(" write error" );
				exit(1);
			}

			if(ret==0)
			{
				close(fd2);
				close(fd1);
				exit(0);
			}
		}

		

	}
//-------------------- part 4-----------------------------------------------

if((*(argv[argc-1])=='/') && (*(argv[argc-1]+strlen(argv[argc-1])-1)=='/'))  

   {
 
        
         cwd=getcwd(PresentPath,1024);       
            
         if(mkdir( argv[argc-1], 0777)<0)
			{
				printf("directory creation fails\n");
				exit(1);
		       }

         
	for (i=1; i<= argc-2; i++)
		{
                        //path1=argv[1];
                           
                       
			if((fd1= open(argv[i], O_RDONLY))<0)
			{
				perror(" File opening error");
				exit(1);

			}
             
                      
		 //if((op= opendir(argv[argc-1]))==0)
                   //   {
                     //    perror("directory opening fails");
                       //           exit(1);


 //                     }
                        path= argv[argc-1];
                        if(chdir(path)==0)			
                           {
                             //strcpy(*temp, *argv[i]);

                        if ((fd2=open(argv[i],O_WRONLY|O_CREAT, 0777 ))<0)
			{
				perror(" file creation in directory fails");
				exit(1);

			}
                         

			while( (ret=read(fd1, buff,10))!= 0)
			{

				if (write(fd2,buff,ret) != ret)
				{
					printf(" write error" );
					exit(1);
 				}

					//close(fd2);
					//closedir(op);
                                        //chdir(cwd);
			}

                       //close(fd2);
                       //close(fd1);
		       //closedir(op);
                      // chdir(cwd);
                        }

                    close(fd2);
                    close(fd1);
		       //closedir(op);
                    chdir(cwd);
		}
       //close(fd1);
       //close(fd2);
        exit(0);
            
	}
 

 return 0; 
}


