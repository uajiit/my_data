#include<stdio.h>

short int todate(int date, int month, int year)
{
short int date_new=((short int )(date & 0x0000000F)) <<12 ;
//printf(" %u", date_new);     
short int month_new=((short int)(month &0x0000001F)) << 7 ;
short int year_new= ((short int) (year &0x0000007F)) ;
return (date_new | month_new|year_new);
}

void extractdate( short int x)
{

printf("month = %d\n", (x &0xf000) >> 12);

}

void extractmonth( short int x )
{

printf("date =%d \n", (x & 0x0f80)>>7);


}

void extractyear(short int x )
{


printf("year=%d \n", (x&0x007f));

}


int main( )
{
short int x;
int date= 1,month= 04,year=17;
x=todate( month ,date, year);
printf("%x \n", x);

printf("%u-%u-%u \n", ((x& 0xf000)>> 12), (x & 0x0f80)>>7, (x& 0x007f));
extractdate(x);
extractmonth( x);
extractyear(x);




return 0;
}



