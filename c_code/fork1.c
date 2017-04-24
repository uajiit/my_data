#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int pid;
pid= fork();

if( pid==0)
{
printf(" child waitig status\n");
exit(0);
}

else 
{
sleep(14);
printf(" waiting for child to exit\n");
wait(0);
}
//getchar();
}
