 /* WAP Producer thread and consumer thread synchronization using Pthreads and Semaphores? */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <pthread.h>
 #include <semaphore.h>
void *producer(); 
void *consumer();
int count=0;
char buff[5];
sem_t a_sem,b_sem;
 int main( int argc, char * argv[])
{
void *a_result;
pthread_t a_thread, b_thread;
sem_init(&a_sem,0, 5);
sem_init(&b_sem,0, 0);
pthread_create( &a_thread, NULL, producer, NULL);

pthread_create( &b_thread, NULL, consumer, NULL);

pthread_join(a_thread, &a_result );
pthread_join(b_thread, &a_result);

return 0;
}


void *producer()
{
int in=0;
char ch='A';
while(1)
{
sem_wait(&a_sem);

buff[in]=ch++; 
in=(in+1)%5;
if ( in ==0)
{
  ch='A';
   
   printf(" First thread %s \n", buff);
}

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

data[out]=buff[out];
out= (out+1)%5;
if( out == 0)
{

printf("second thread %s\n", data);

}
sem_post(&a_sem);
}
pthread_exit("b_thread terminated");
}
