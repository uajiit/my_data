#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include<stdlib.h>
int main()
{
int semid;
if (semid=semget( 0x24, 5, IPC_CREAT| 0666)<0)
{
  perror("");
  exit(1);
}
while(1);

}

