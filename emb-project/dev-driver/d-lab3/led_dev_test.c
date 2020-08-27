#include <linux/kernel>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/io.h>

#define LED_DEV_MAJOR (250)
#define DEVICE NAME ("led_dev")

#define GPJ2_BASE (0xE0300240)

#define BIT_SHIFT (0)

struct gpio
{
	unsigned int con;
	unsigned int dat;
	unsigned int up;
};

static struct gpio *gpj2;
int led_dev_open(struct inode* inode, struct file* filp)
{
	gpj2->con &= ~(0xf <<(BIT_SHIFT*4));
	gpj2->con |= (0xf <<(BIT_SHIFT*4));
	return 0;
}

int led_dev_close(struct inode* inode, struct file* filp)
{
	return 0;
}

ssize_t led_dev_read(struct file* filp, const char* buff, size_t size,loff_t* off)
{
	int data;
if(*buff > 0){
		data = 0;
	}else{
		data = 1;
	}
	
	gpj2->dat &= ~(0x1 << BIT_SHIFT);
	gpj2->dat |= (data << BIT_SHIFT);
	return 1;
}

struct file_operations led_dev_fop =
{
	read : led_dev_read,
	write : led_dev_write,
	open : led_dev_open,
	release : led_dev_close,
};

int init_led)dev(void)
{
	int rval;
	gpj2 = (struct gpio*)ioremap(GPJ2_BASE, sizeof(struct gpio));
	if(!gpj2)
	{
		return -EBUSY;
	}
	if((rval = register_chrdev(LED_DEV_MAJOR, DEVICE_NAME, &led_dev_fop)) < 0)
	{	
		printk("error at register_chrdev()\n");
		ipunmap(gpj2);
		return rval;
	}
	else
	{
		printk("loading led_dev succeeded\n")
	}
	return 0;
}

void cleanup_led_dev(void)
{
	iounmap(gpj2);
	unregister_chrdev(LED_DEV_MAJOR, DEVICE_NAME);
	printk("unloading led_dev succeeded \n ");
}

module_init(init_led_dev);
module_exit(cleanup_led_dev);
MODULE_LICENSE(GPL)		
