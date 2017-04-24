#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
//////////////////////////////////////
void mysighandler(int);
void mysighandler1(int);
int child(void);
void control(void);
int parent(void);
//////////////////////////////////
char *msg;
int shmid;
pid_t childpid;
int i=1;
/****************************************************/
void main()
{


    if((shmid=shmget(20,1024,666|IPC_CREAT))==-1) 
        {
                perror("shmget");
                exit(1);
        }

     childpid=fork();
     if(childpid==-1)
     {
        perror("fork");
            exit(1);
     }
     if(childpid==0)
         child();
    else
         parent();
}
/*******************************************************/
void mysighandler(int sig)
{
    printf("child process............\n");
        msg=shmat(shmid,0,0);
    printf("Data written in the shared memory is:%s\n",msg);
    printf("******************************************\n");
    shmdt(msg);
        kill(getppid(),SIGALRM);
}
/*******************************************************/
void mysighandler1(int sig)
{
    printf("parent process..........\n");
          msg=shmat(shmid,0,0);
          printf("Enter the data you want to write into shared memory\n");
          fgets(msg,1024,stdin);

    printf("Data successfully written\n");
          shmdt(msg);
          kill(childpid,SIGALRM);          
}
/********************child process*********************/
int child(void)
{
  signal(SIGALRM,mysighandler);
         while(i<=3)
        {
             pause();
              i++;
        }
          exit(0);
}
/****************parent process************************/
int parent(void)
{
     signal(SIGALRM,mysighandler1);

          printf("parent process..........\n");
          msg=shmat(shmid,0,0);
          printf("Enter the data you want to write into shared memory\n");
          fgets(msg,1024,stdin);
          kill(childpid,SIGALRM);
          printf("Data successfully written\n");
          shmdt(msg);
          while(i<=3)
        {
             pause();
         i++;
        }
          wait(NULL);

               control();

}
void control(void)
{
        getchar();
        if(shmctl(shmid,IPC_RMID,0)==-1)
        {
        perror("shmctl");
        exit(1);
        }
             printf("shared memory removed successfully\n");
} 
