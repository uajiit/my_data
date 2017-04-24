#include<stdio.h>
#include<signal.h>
void abc();
int main( int argc, char *argv[])
{

signal(SIGINT, abc);

signal(SIGINT, abc);
signal( SIGINT,abc);
for(;;);
return 0;
}

void abc()
{
printf("ping me \n");

}
