
 #include <unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>

 
//int pid;
/*
char mysystem(char*);
main()
{
	mysystem("sudo poweroff");
}

char  mysystem(char *value)
{
*/
main()
{
int ret;
char *const value[]= {"/sbin/bash", "sudo poweroff", NULL};

//execl("/bin/sh" ,"sh","-c" ,value, NULL);

execve("/sbin/bash", value,NULL);













return 0;
}
