// WAP producer process and consumer process synchronization using Shared Memory, fork() and named semaphores.
#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
int sem_fd;
int main( int argc, char *argv[])
{
	int shm_fd ;
	key_t key= IPC_PRIVATE;
	int flag = IPC_CREAT|IPC_EXCL| 0644;
	if ((shm_fd= shmget(IPC_PRIVATE, 1024,IPC_CREAT|0777)) ==-1)
               {
                   perror("");
                    exit(1);
               } 
  
          ptr= (char *)shmat(shm_fd, 0,0) 



        sem_fd= semget(key, 2, flag );
        if(sem_fd<0)
           {
           perror("semaphore creation fails");
           exit(0);
           }
       pid= fork()
        switch(pid)
                {
                   case -1: perror(" ");
                            exit(1);
                   case 0: sleep(2); 
                           consumer();
                           break; 
                      
                   default: producer();
                            wait(0);
                }

       
        

return 0;
}

void producer()
{

              
	strcpy(ptr,"hello");
        printf("producer data: %s \n", ptr);
         
           
        
   //     exit(0);             
}


void consumer()
{
  
 printf( "consumer data: %s\n",ptr );
  shmdt(ptr);	   
    
  exit(0);
}

void shm_del()
{
  shmdt(ptr);
  shmctl(shm_fd,IPC_RMID,0);
  exit(0);
}


