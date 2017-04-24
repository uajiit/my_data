#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

void *producer();
void *consumer();
int counter = 0;
char buffer[5];

#define SIGUSER1 10
#define SIGUSER2 12 
pthread_t a_thread,b_thread; 
int main() {
  
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

void  *producer() {

    
    int in = 0; 
    char ch='A';
    while(1)
	{
               signal( 12, con_data);
               
	//	printf ("producer: counter:%d\n",counter); 
		while(counter == 5)
                  {
                    
                    pthread_kill( b_thread,10); 
                    //signal( SIGUSER1 , b_thread);
                    //exit(0);
                 }
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0 )
		{
		//ch='A';
		printf("p:%s\n",buffer);
		}

		counter++;
          
	}
      
   
  	
  }
void  * consumer() {
    int out = 0;
    char data[5];
    //
    
    while(1)
	{
            signal( 10 , con_data);
     		while(counter == 0)
                {
                  
                  
                  pthread_kill(a_thread,12);
              
                  //exit(0);
                }
		data[out] = buffer[out];
		out = (out+1)% 5;
		if (out == 0)
		printf ("\t:c:%s\n",data); 
		counter--;
	}
   //pthread_exit("exit");	
}

void con_data()
{

 int in = 0; 
    char ch='A';
    while(1)
	{
               
               
	 while(counter == 5)
                                     
               pause();
                 
		buffer[in]=ch;
		in = (in+1)% 5;
		ch++;
		if (in == 0 )
		printf("p:%s\n",buffer);
		
                else
		counter++;
          
	}

}



