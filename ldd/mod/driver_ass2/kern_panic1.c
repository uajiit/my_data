//write a module program to create a kernel panic
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/version.h>
#include<linux/fs.h>
#define MAJOR  60
#define NAME "null_device"
static int null_init(void);
static void null_exit(void);
int dev_open(struct inode *ino , struct file *filp );
int dev_read(struct file *filp, char __user *usr, size_t len, loff_t *off);
ssize_t dev_write(struct file *filp, const char __user *usr, size_t len , loff_t *off);
int  dev_release(struct inode *ino, struct file *filp);


struct file_operations f_op={
//.owner = THIS_MODULE, 
.open=dev_open,
.read=dev_read,
.write= dev_write,
.release=dev_release,
};
struct file_operations *fptr=&f_op;

int dev_open(struct inode *ino , struct file *filp )
{
printk( KERN_INFO "device opened \n");
return 0;
}

int dev_read(struct file *filp, char __user *usr, size_t len, loff_t *off)
{
printk(KERN_INFO "trying to read from the device\n");
return 0;
}

ssize_t  dev_write(struct file *filp, const char __user *usr, size_t len , loff_t *off)
{
printk(KERN_INFO "trying to write to the device\n");
return 0;
}

int  dev_release(struct inode *ino, struct file *filp)
{
printk(KERN_INFO "device closed \n");
return 0;
}


static int null_init(void)
{
int ret;
ret=register_chrdev(MAJOR, NAME ,fptr);
if(ret<0)
   {
    printk(KERN_ALERT "device registration fails"); 
    return -EPERM;   
   }
printk(KERN_INFO " device no %d is properly registerd", MAJOR);
//fptr->write=NULL;
return 0;
}

static void null_exit(void)
{
 unregister_chrdev(MAJOR, NAME );
 printk(KERN_INFO " device  no  %d is unloded", MAJOR);
}

module_init(null_init);
module_exit(null_exit);
MODULE_AUTHOR("Ajit Upadhayay");
MODULE_LICENSE("GPLV2");



