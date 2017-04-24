 /* WAP Producer thread and consumer thread synchronization using Pthreads and Semaphores and mutex? */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <pthread.h>
 #include <semaphore.h>
#include<string.h>
void *producer1(); 
void *producer2();
void *consumer();
int count=0;
char buff[5];
sem_t a_sem,b_sem;
pthread_mutex_t lock;
 int main( int argc, char * argv[])
{
void * a_result, *b_result, *c_result ;
int ret;
pthread_t a_thread, b_thread, c_thread ;
sem_init(&a_sem,0, 5);
sem_init(&b_sem,0, 0);
ret= pthread_create( &a_thread, NULL, producer1, NULL);
if(ret !=0)
{
 perror(" ");
 exit( EXIT_FAILURE);
}

ret= pthread_create( &b_thread, NULL, producer2, NULL);
if(ret !=0)
{
 perror(" ");
 exit( EXIT_FAILURE);
}
ret= pthread_create( &c_thread, NULL, consumer, NULL);
if(ret !=0)
{
  perror(" ");
 exit( EXIT_FAILURE);
}
printf("wait for thread join");
ret=pthread_join(a_thread, &a_result);

ret= pthread_join(b_thread, &b_result);
if( ret !=0)
{
  perror(" ");
  exit( EXIT_FAILURE);
}
ret= pthread_join(c_thread, &c_result);
if( ret !=0)
{
  perror(" ");
  exit( EXIT_FAILURE);
}


return 0;
}


void *producer1()
{
int in=0;
char ch='A';


while(1)
{
sem_wait(&a_sem);
pthread_mutex_lock(&lock);
buff[in]=ch++; 
in=(in+1)%5;
if ( in ==0)
{
  ch='A';
   
   printf(" First thread %s \n", buff);
}
pthread_mutex_unlock(&lock);
sem_post(&b_sem);
}

pthread_exit("a_thread terminated");
}



void *producer2()
{
int in=0;
char ch='1';

while(1)
{

sem_wait(&a_sem);
pthread_mutex_lock(&lock);

buff[in]=ch++; 
in=(in+1)%5;
if ( in ==0)
{
  ch='1';
   
   printf(" Second thread %s \n", buff);
}
pthread_mutex_unlock(&lock);
sem_post(&b_sem);
}

pthread_exit("a_thread terminated");
}

void *consumer()
{
int out=0;
char data[5];

while(1)
{
sem_wait(&b_sem);
pthread_mutex_lock(&lock);
data[out]=buff[out];
out= (out+1)%5;
if( out == 0)
{

printf("third thread %s\n", data);

}
pthread_mutex_unlock(&lock);
//memset(buff, '\0', sizeof(buff));
sem_post(&a_sem);
}

pthread_exit("c_thread terminated");
}
