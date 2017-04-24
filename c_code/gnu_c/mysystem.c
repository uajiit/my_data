#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
char mysystem(char*);
main()
{
	mysystem("sudo poweroff");
}
char  mysystem(char *value)
{
pid_t ret;
	//getchar();
	ret=fork();
	//getchar();
	switch(ret)
	{
		case -1:
			perror("fork failed\n");
			return -1;
			break;
		case 0:
                        // execve("/bin/ls",argv,NULL);
			execl("/bin/sh","sh","-c",value,NULL);
			exit(0);
			break;
		default:
			wait(NULL);
			printf("parent process\n");
	}
	return 0;
}

