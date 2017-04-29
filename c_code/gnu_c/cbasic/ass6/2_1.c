#include<stdio.h>
#include <stdlib.h>
extern void str_rev( char *str)
{
int i=0;
 int count=0;
char *str1;
str1= (char *)malloc( 100*sizeof(char));
while(*(str + (count++))!= '\0');
  --count;
while((count--) !=0)
 {
  *(str1+(i++)) = *(str+count);
 }
str1[i]='\0' ;
printf("%s\n", &str1[0]);
// return str1;

}
