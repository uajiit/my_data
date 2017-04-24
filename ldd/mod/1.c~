#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>
 static int hello_init(void)
{

printk(" hello ajit \n");
return 0;
}

static void hello_exit(void)
{

printk(" bye ajit \n");

}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Ajit Upadhayay");
MODULE_LICENSE("GPLV2");
