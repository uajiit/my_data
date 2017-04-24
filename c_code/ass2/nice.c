#include <unistd.h>
#include<stdio.h>
//  int nice(int inc);
int main(int argc, char *argv[])
{

	int pid, inc;
	char  *new_arg[]={NULL};
	pid=fork();
	if( pid ==0)
	{
		inc= atoi(argv[2] );
		nice(inc);
		new_arg[0]= argv[1];
		execve(argv[1],new_arg, NULL);

	}
	else
		wait(0);
	return 0;
}
