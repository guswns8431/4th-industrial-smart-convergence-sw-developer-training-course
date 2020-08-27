/*Module example
FIle : hello_module.c
*/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SHJ");
static int module_begin(void)
{
	printk(KERN_ALERT "Hello World\n");
	return 0;
}

static int module_end(void)
{
	printk(KERN_ALERT "Exit Module\n");
	return 0;
}

module_init(module_begin);
module_exit(module_end);
