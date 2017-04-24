#include <linux/module.h>
#include <linux/kernel.h>
#include<linux/version.h>
#include<linux/spinlock.h>
#include<asm/spinlock.h>
#include<linux/semaphore.h>
//spinlock_t my_lock = SPIN_LOCK_UNLOCKED;
spinlock_t my_lock;


//#define DEFINE_SPINLOCK(x)      spinlock_t x = __SPIN_LOCK_UNLOCKED(x)
int init_module(void)
{
spin_lock_init(&my_lock);
 spin_lock(&my_lock);

printk(KERN_INFO "hello it is my first kernel moddule programming\n");
spin_unlock(&my_lock);
return 0;
}
void cleanup_module(void)
{
printk(KERN_INFO "bye bye cruel world\n");
}
MODULE_LICENCE("GPL" );
MODULE_AUTHOR(" Ajit Upadhay");
