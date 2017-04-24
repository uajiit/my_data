#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/syscall.h>
#include<signal.h>
#include<sys/types.h>
void *producer(void *arg);
void *consumer(void *arg);
//void *pro
//void mysig(int);
void myprod(int);
void mycon(int);
int counter=0;
int tp;
int tc;
//sem_t full,empty;
char buffer[5];
int main()
{
	int ret;
	pthread_t t1,t2;
	void *thread_result;
	//sem_init(&full,0,0);
	//sem_init(&empty,0,5);
	ret=pthread_create(&t1,NULL,producer,NULL);
	if(ret!=0)
	{
		printf("pthread creat fail\n");
		exit(EXIT_FAILURE);
	}
	ret=pthread_create(&t2,NULL,consumer,NULL);
	if(ret!=0){
		printf("pthread creat fail\n");
		exit(EXIT_FAILURE);
	}
	printf("wait for pthread join\n");
	ret=pthread_join(t1,&thread_result);
	if(ret!=0)
	{
		printf("pthread join fail\n");
		exit(EXIT_FAILURE);
	}
	ret=pthread_join(t2,&thread_result);
	if(ret!=0){
		printf("pthread join fail\n");
		exit(EXIT_FAILURE);
	}
	printf("pthread join successfully\n");
	exit(EXIT_SUCCESS);
}
void *producer(void *arg)
{
	int a=0;
	char ch='A';
	tp=syscall(SYS_gettid);
	signal(SIGUSR1,myprod);
	sleep(2);

		while(counter!=5){
			//sem_wait(&empty);
			buffer[a]=ch;
			a=(a+1)%5;
			if(a==0)
			{
				ch='A';
				printf("p:%s\n",buffer);
			}
			else
				ch++;
			counter++;
			//sem_post(&full);
		}
//		if(counter==5)
			syscall(SYS_tkill,tc,SIGUSR2);
        while(1)
           pause();
	//	pause();
	
	pthread_exit("exit");
}
void *consumer(void *arg)
{

	tc=syscall(SYS_gettid);
	signal(SIGUSR2,mycon);
	while(1)
	{
		pause();
	}
	pthread_exit("exit");
}

void mycon(int sig)
{
	int b=0;
	char data[5];
	while(counter!=0)
	{
		data[b]=buffer[b];
		b=(b+1)%5;
		if(b==0)
			printf("\tc:%s\n",data);
		//sem_post(&empty);
		counter--;
	}
	//pthread_exit("exit");
	syscall(SYS_tkill,tp,SIGUSR1);
}
void myprod(int sig)
{
int a=0;
 char ch='A';
  	while(counter!=5)
	{
                        //sem_wait(&empty);
                        buffer[a]=ch;
                        a=(a+1)%5;
                        if(a==0)
                        {
                                ch='A';
                                printf("p:%s\n",buffer);
                        }
                        else
                                ch++;
                        counter++;
                        //sem_post(&full);}

        }
         // if(counter==5)
                        syscall(SYS_tkill,tc,SIGUSR2);
}

