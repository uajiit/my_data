# include <unistd.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
#include<stdlib.h>

int main( int argc, char *argv[])
{
	int fd,i,ret,j;
	unsigned char *filedata= NULL,*temp1,*temp2;
	struct stat sc;
	if( argc==1)
	{
		printf(" mmap() unable to execute command");
		exit(1);
	}



	if(argc !=1 )
	{

		for(i=1; i<=argc-1;i++  )
		{
                        *filedata=NULL;
			if ((fd = open(argv[i],O_RDWR))<0)
			{ 
				perror( " File Opening error");
				exit(1); 
			}

			stat(argv[i],&sc);
			filedata = (char *) mmap((void*)0, sc.st_size,PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);	

			if(filedata == NULL)
			{
				perror(" Read eorror ");
				return -1;
			}



			temp1 = filedata;
                        temp2=filedata;

			while((*temp2) !=EOF )
			   printf("%c", *(temp2++));
			
		//close(fd);
           
		  j= munmap(temp1,sc.st_size);

			if( j != 0)
				printf(" failed to unmap\n");
                                j= munmap(temp1,sc.st_size);	
	
		}
              

        close(fd);          
	}
	return 0;
}
