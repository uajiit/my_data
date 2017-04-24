#include<stdio.h>
 int main()
{
struct 
{
int x;
int y;
}value1={10,20}, value = {10, 20};
printf("%d, %d \n", value1.x, value1.y);
struct {
int x; 
char a;

} value2= {10, 'a'};
printf("%d %d \n", value2.x, value2. a);

struct value3 {
int x; 
char a;

}value3={10,20};

printf("%d %d \n", value3.x, value3. a);

printf("%d, %d \n", value.x, value.y);

struct value4
{
int a;
char *name;
char *address;
}b={10,"hello"}, *w =&b, y={10, " HI", " AGAIN HELLO" };
printf(" %d %s \n", w->a, w->name ); 
printf(" %d %s %s \n", y.a, y.name, y.address);
struct value5
{
int a;
char *name;
char *address;
struct value5 *next;
} x={10, "hello", " hyderabad", NULL} ;
printf(" %d %s %s %d \n", x.a, x.name, x.address,x.next ); 





return 0;
}
