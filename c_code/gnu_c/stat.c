 #include <sys/types.h>
 #include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>

int main( int argc, char **argv)
{
 

struct stat st;
stat(argv[1], &st );

printf("%ld", st.st_size);





return 0;
}

