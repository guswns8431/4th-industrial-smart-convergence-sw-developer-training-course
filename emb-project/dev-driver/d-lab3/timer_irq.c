#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/clk.h>
//#include <plat/regs-timer.h> S5PV210에 관련된 헤더파일이라 기본 헤더 파일이 아님
#include <asm/io.h>

#define IRQ_TEST_MAJOR (251)
#define DEVICE_NAME ("timer_irq")
#define PWM_TIMER_BASE (0x7E00B000)
#define S3C_VA_TIMER (0)
#define TCFG0_PRESCALER0 (128)
#define TIMER0_DIVIDER (16)

#define TCFG1_MUX0_VAL(x) (S3C_TCFG1_MUX0_DIV##x)
#define TCFG1_MUX0 (TCFG1_MUX0_VAL(16))

#define PWM_FREQUENCY (2)

#define UPDATE_TIMER0_BUFFER() \
{\
	unsigned int reg;\
	reg = readl(pwm_timer_base + S3C_TCON);\
	reg |= S3C_TCON_T0MANUALPD;\
	writel(reg,pwm_timer_base + S3C_TCON);\
	reg &= ~S3C_TCON_T0MANUALUPD;\
	writel(reg, pwm_timer_base + S3C_TCON);\
}

void *pwm_timer_base;
enum timer0_mode {TIMER_SETUP, TIMER_STOP, TIMER_START};

static int timer0_operation(enum timer0_mode tt){
	int RetVqal=0;
	unsigned int reg;
	unsigned long pclk_rate;
	pclk =clk_get(NULL,"pclk");
	pclk_rate = clk_get_rate(pclk);
	clk_put(pclk);

	switch(tt){
	case TIMER_SETUP:
			reg = readl(pwm_timer_base + S3C_TCFG0);
			reg &= ~S3C_TCFG_PRESCALER0_MASK;
			reg |= TCFG0_PRESCALER0;
			writel(reg, pwm_timer_base + S3C_TCFG1);
			reg =(pclk_rate)/((TCFG0_PRESCALE0+1)*(TIMER0_DIVIDER)*PWM_FREQUENCY)
			writel(reg,pwm_timer_base + S3C_TCNTB(0));
			reg = 0;
			writel(reg, pwm_timer_base + S3C_TCMPB(0));
			reg = readl(pwm_timer_base + S3C_TCON);
			reg |= S3C_TCON_T0RELOAD;
			writel(reg,pwm_timer_base + S3C_TCON);
			UPDATE_TIMER0_BUFFER();
            break;
	case TIMER_START:
			reg = readl(pwm_timer_base + S3C_TCON);
			reg |= S3C_TCON_T0START;
			writel(reg, pwm_timer_base + S3C_TCON);
			break;
	case TIMER_STOP:
			reg = readl(pwm_timer_base + S3C_TCON);
			reg &= ~S3C_TCON_T0START;
			writel(reg, pwm_timer_base + S3C_TCON);
			break;
		}
		return RetVal;
}
irqreturn_t_on_off_led(int irq, void *dev_id)
{
	unsigned char val;
	val = gpio_get_value(S5PC1XX_GPJ2(0));
	gpio_set_value(S5PC1XXX_GPJ2(0), !val);
	return IRQ_HANDLED;
}

int irq_test_open(struct inode* inode, struct file* filp){
	timer0_operation(TIMER_SETUP);
	timer0_operation(TIMER_START)
	return 0;
}

int irq_test_close(struct indoe* inode, struct file* filp){
	timer0_operation(TIMER_STOP);
	return 0;
}

ssize_t irq_test_read(struct file *filp, char *buff, size_t size, loff_t *offset){
	if(size <4){
		return 0;
	}else{
		*((unsigned int*)buff) = readl(pwm_timer_base + S3C_TCNTO(0));
	} return sizeof(unsigned int);
}

struct file_operations irq_test_fop = {
	open : irq_test_open,
	release : irq_test_close,
	read : irq_test_read
};

int init_irq_test(void){
	int rval = 0;
	int errno;
	if(request_irq(IRQ_TIMER0, on_off_led, IRQF_TRIGGER_RISING, "irq_test", NULL) < 0)
	return -EBUSY;
	}
	if(!(pwm_timer_base = (void*)ioremap(PWM_TIMER_BASE, 0x48))){
		printk("error at ioremap\n");
		rval = -EBUSY;
		goto out;
	}
	if((errno = register_chrdev(IRQ_TEST_MAJOR, DEVICE_NAME, &irq_test_fop)) <0){
		printk("error at register_chrdev()\n");
		rval = errno;
		goto iounmap;
	} else {
		printk("loading irq_test succeede\n");
	}
	return rval;
iounmap :
	iounmap(pwm_timer_base);
out:
	return rval;
	}

void cleanup_irq_test(void){
	free_irq(IRQ_TIMER0,NULL);
	iounmap(pwm_timer_base);
	unregister_chrdev(IRQ_TEST_MAJOR, DEVICE_NAME);
	printk("unloading irq_test succeeded\n");
}
module_init(init_irq_test);
module_exit(cleanup_irq_test);
MODULE_LICENSE("GPL");
