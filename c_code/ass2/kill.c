#include <sys/types.h>
#include <signal.h>
#include<stdlib.h>
#include<stdio.h>
int main( int argc, char *argv[])
{
	int pid; 
	int signo;

	if(argc < 2 || argc > 3)
	{
		printf(" Operation not permited");
		exit(0);
	}
	if (argc ==2)
	{
		pid=atoi(argv[1]);
		signo=9;
		if (kill(pid,signo) != 0)
		{
			perror("");
			exit(1);
		}
	}

	if (argc ==3)
	{
		pid=atoi(argv[1]);
		signo=atoi(argv[2]);
		//if (signo > 1 || signo <64)
		if (kill(pid,signo)!= 0)
		{ 
			perror("");
			exit(1);
		}

	}
	return 0;
}
