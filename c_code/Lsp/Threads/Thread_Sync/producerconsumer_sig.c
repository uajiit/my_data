#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void *producer(void *arg);
void *consumer(void *arg);
int counter = 0;
char buffer[5];

int main() {
   


signal(SIGALARM, producer);

pause();
   
 





}

void producer() {

    
    int in = 0; 
    char ch='A';
    while(1)
	{
	//	printf ("producer: counter:%d\n",counter); 
		while(counter == 5)
                  {
                    pthread_kill(producer,SIGUSER1);
                    signal( SIGUSER2 , consumer);
                 }
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0 )
		{
		ch='A';
		printf("p:%s\n",buffer);
		}

		counter++;
	}
      
   
  	
  }
void consumer(void *arg) {
    int out = 0;
    char data[5];
    while(1)
	{
		while(counter == 0)
                {
                   pthread_kill(consumer,SIGUSER1);
                   signal( SIGUSER2, producer);
                 
                }
		data[out] = buffer[out];
		out = (out+1)% 5;
		if (out == 0)
		printf ("\t:c:%s\n",data); 
		counter--;
	}
   //pthread_exit("exit");	
}
