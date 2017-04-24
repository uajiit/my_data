#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
#include <errno.h>
#include <unistd.h>


int main()
{
char *ptr;
int shm_fd;
shm_fd= shmget( 1, 1, IPC_CREAT| 0666);
ptr= (char *) shmat( shm_fd,0,0); 
read(0,ptr, 10);
write(1,ptr, 10);
shmdt(ptr);
 if (write(1,ptr, 10) < 0)
  perror(" error:");

exit(0);
}
