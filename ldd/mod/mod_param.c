#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/version.h>
int value=3;
module_param(value, int, 0);

static int  __init  moduleparam_init(void)
{

printk(KERN_ALERT " hello %d " , value);
return 0; 
}

static  void __exit  moduleparam_exit(void)
{
printk(KERN_ALERT "module unloaded\n");

}

module_init(moduleparam_init);
module_exit(moduleparam_exit);

MODULE_AUTHOR("AJIT UPADHYAY ");
MODULE_LICENSE("GPLV2");


