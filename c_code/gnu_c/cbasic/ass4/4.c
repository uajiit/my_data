#include<stdio.h>
int main()
{
int a1[5] = {}; 
printf(" %d \n", sizeof(a1));// size = 20;
int a2[10] = {2.4,5.6,7.3};
printf(" %d\n", sizeof(a2));// size=40
int a3[3] = {1,2,3,4,5};
printf(" %d\n", sizeof(a3));//size= 12
int a4[0] = {};
printf(" %d \n", sizeof(a4));//size=0
int a5[0] = {1,2,3,4,5};
printf(" %d \n", sizeof(a5));//size=0
int a6[] = {};
printf(" %d \n", sizeof(a6));// size= 0
int a7['a'];
printf(" %d \n", sizeof(a7));//size=4*97=388

return 0;
}
