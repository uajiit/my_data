#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include<signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>

#define SIZE 26
void producer();
void consumer();
char buffer[SIZE];
 int pid;
char *ptr; 
int shm_fd;

void shm_del();
int main( int argc, char* argv[])
{
if ((shm_fd= shmget(IPC_PRIVATE, 1024,IPC_CREAT|0777)) ==-1)
    {
      perror("");
      exit(1);
    } 
  
ptr= (char *)shmat(shm_fd, 0,0);
    
       pid=fork();
     
	switch(pid)
	{

		case -1: perror("");
			 break;

		case 0: sleep(2); 
                        consumer();
                        break;
                default : producer();
                           wait(0);
                 	         

	}

	return 0;
}

void producer()
{
    //ptr= (char *)shmat(shm_fd, 0,0);
	strcpy(ptr,"hello");
        printf("producer data: %s \n", ptr);
        signal(SIGUSR1, shm_del); 
        pause();      
        
   //     exit(0);             
}


void consumer()
{
 //char *data;
 
  //data= ptr;
  printf( "consumer data: %s\n",ptr );
  shmdt(ptr); // we detch the ptr first from the child	   
  kill(getppid() , SIGUSR1);
  
  exit(0);
}

void shm_del()
{
  shmdt(ptr);// after detaching  child ptr, we detach the ptr of parent
  shmctl(shm_fd,IPC_RMID,0);
  exit(0);
}

