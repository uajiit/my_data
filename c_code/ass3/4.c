#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void *producer();
void *consumer();
void pro_data();
void con_data();
int counter = 0;
char buffer[5];

pthread_t a_thread,b_thread; 
int main()
 {

	int res;

	void *thread_result;

	res = pthread_create(&a_thread, NULL, producer, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&b_thread, NULL, consumer, NULL);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Wait for pthread_join\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_join(b_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	exit(EXIT_SUCCESS);


}

void *producer() { 
 signal( SIGUSR1, pro_data);
  
	while(1)                 
	{
		pause(); 
	}

	pthread_exit("exit");

}


void  *consumer() {
   /* it should not happen, that signal is raised before waiting for signal, 
   hence ,sleep is used for give the first time slice to producer thread. */
        sleep(1); 
	pthread_kill(a_thread,SIGUSR1);
        
        signal(SIGUSR2, con_data);      
        while(1)
	{
		
		pause();
	}
	pthread_exit("exit"); 

}




void pro_data() 
{


	int in = 0; 
	char ch='A';

	while(counter !=5)

	{
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0 )
		{
			ch='A';
			printf("producer:%s\n",buffer);
		}
		else
			counter++;

	}

	pthread_kill(b_thread,SIGUSR2);     


}


void con_data() 
{
	int out = 0;
	char data[5];

	while(counter != 0)
	{

		data[out] = buffer[out];
		out = (out+1)% 5;
		if (out == 0)
			printf ("\t:consumer:%s\n",data); 
		else
			counter--;
	}

	pthread_kill(a_thread,SIGUSR1);


}


















