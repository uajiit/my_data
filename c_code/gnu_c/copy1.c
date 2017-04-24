#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include<stdlib.h>
int main(int argc ,char *argv[])
{
      int fd,rd,wr,op,rop,ch,des,test,mk,cr;
      struct stat SourceFileInfo,DistFileInfo,TesterInfo;
      char buff[5],i;
      char destpath[20];
  
      char PresentPath[50];
      char *cwd;
      if(argc!=3)
          {   
	    cwd=getcwd(PresentPath,1024);         
              test=open(argv[argc-1],O_RDONLY);    
		fstat(test,&TesterInfo);
		if(S_ISDIR(TesterInfo.st_mode))
		{
                   for(i=1;i<argc-1;i++)
			{
				op=open(argv[i],O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO );
				      chdir(argv[argc-1]);
                                      cr=open(argv[i], O_WRONLY | O_CREAT ,S_IRWXU | S_IRWXG | S_IRWXO);
                                while (rd=(read(op,&buff,5)) > 0)
				{ 
                                      wr= write(cr,&buff,5);		
				}
                                      close(cr);
 				      chdir(cwd);
                                       close(op);
			}
		}
               
    else if(argc==2)
               printf("%s :missing destination file operand after ‘%s’ \n Try 'cp --help' for more information.\n",*(argv+0),*(argv+1));
            else if (argc==1) printf("%s :missing file operand \nTry 'cp --help' for more information.\n",argv[0]);		
            
else
            printf("%s: target ‘%s’ is not a directory\n",*argv,*(argv+(argc-1)));
	  }
        else
          {
	    op = open( argv[1],O_RDONLY);
	    fstat(op,&SourceFileInfo);
	    if(S_ISDIR(SourceFileInfo.st_mode))
	    {
		printf("%s: omitting directory ‘%s'\n",argv[0],argv[1]);
	    }
		if(op<0)
		 {
            	 perror("file not open\n");
		  exit(1);
		 }

		des=open( argv[2],O_RDONLY , S_IRWXU | S_IRWXG | S_IRWXO );
		fstat(des,&DistFileInfo);
                    if(S_ISDIR(DistFileInfo.st_mode))
                     {
			ch=chdir(argv[2]);
			rop = open(argv[1], O_WRONLY | O_CREAT , S_IRWXU | S_IRWXG | S_IRWXO);
		     }
                     else
 		     {
			  rop = open(argv[2], O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO );	
		     }
	        if(rop<0) 
		{		
 		perror("creating file fail");
                exit(1);
            	}
		while ((rd =read(op,buff,5)) >0)
                 {
		   if(rd<0)
                   {
	           perror("read file");
                    exit(1);
                   }
                wr = write(rop,buff,rd);
                 if(wr<0)  
			{
			perror("writing fial");exit(1);
	                } 
                }
             close(op);
             close(rop);  
             exit(0);
	  }       
            
  }

