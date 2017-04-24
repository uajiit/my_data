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
char *data;
void shm_del();
int main( int argc, char* argv[])
{
char *ptr; 
if ((shm_fd= shmget(20, 1024,IPC_CREAT|0777)) ==-1)
    {
      perror("");
      exit(1);
    } 
  
ptr= (char *)shmat(shm_fd, 0,0);
    
       if (pid=fork())
         //wait(0);
         {
        strcpy(ptr,"hello");
        wait(0);
        }   
	else
          {
          sleep(2); 
          data= ptr;
          printf(" %s\n",data);
          
          }
//shmdt(ptr);
	

//shmctl(shm_fd,IPC_RMID,0);
  exit(0);
}

