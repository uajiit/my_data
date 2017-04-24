# include <unistd.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int main(){
	int fd,i,ret;
	unsigned char *filedata= NULL,*temp;
        struct stat sc;
	fd = open("abc",O_RDWR);
	
        stat("abc",&sc);
	filedata = (char *) mmap((void*)0, sc.st_size,PROT_READ|PROT_WRITE, MAP_SHARED,fd,0);	

	if(filedata == NULL){
		perror(" Read eorror ");
		return -1;
	}


	// now we can access the content of the file as if it is part of
	// our process starting from the memory pointed by filedata.
	temp = filedata;
	for(i=0;i<sc.st_size;i++,filedata++)
	{
		
	      printf("%c", *filedata);
              if(*filedata== EOF)
                    break;
	}
//	if(msync(temp,100,MS_SYNC)!=0)
//		perror("msync : ");
	
	i = munmap(temp,sc.st_size);
	//getchar();
	if( i != 0)
		printf(" failed to unmap\n");
}
