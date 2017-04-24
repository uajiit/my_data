#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include"dev.h"


EXPORT_SYMBOL(dev2_init2);
EXPORT_SYMBOL(dev2_exit2);
struct dev_ops dev2={
.open=dev2_open,
.close=dev2_close,
};
struct dev_ops *fptr=&dev2;

void dev2_open( void)
{
printk(" dev2 module open \n");
}

void dev2_close( void )
{
printk(" dev2 module unloded \n");

}


 int dev2_init2(void)
{
printk(" dev2 module init implemented \n");
fptr->open();

return 0;
}

void dev2_exit2(void)
{
fptr->close();
}
//module_init(dev2_init);
//module_exit(dev2_exit);

