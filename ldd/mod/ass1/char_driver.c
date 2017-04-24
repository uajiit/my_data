nclude<linux/init.h>
#include<linux/kernel.h>
#include<linux/version.h>
#inlude<linux/fs.h>
struct file_operations f_op={
.open=dev_open,
.read=dev_read,
.write= dev_write,
.release=dev_relaese,
};
struct file_operations *fptr=&f_op;

int dev_open(struct inode *, struct file * )
{
printk(" dev module open \n");
}

int dev_read(struct file *, char __user *, size_t, loff_t *)
{


}

int dev_write(struct file *, const char __user *, size_t, loff_t *)
{



}

int  dev_release(struct inode *, struct file *  )
{

printk(" dev1 module unloded \n");

}


static int dev_init(void)
{
register_chrdev(60, "first_chardev",fptr);
return 0;
}

static void dev1_exit(void)
{

unregister_chrdev(60, "first_chardev");

}
module_init(dev1_init);
module_exit(dev1_exit);
MODULE_AUTHOR("Ajit Upadhayay");
MODULE_LICENSE("GPLV2");
                                                                                                                    43,1          Bot

