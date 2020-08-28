MODULE_NAME = timer_irq
ifeq ($(KERNELRELEASE),)

CROSS_COMPILE = aarch64-linux-gnu- 
CC= $(CROOS_COMPILE)gcc
PWD = $(shell pwd)
KDIR = $(shell uname -r)
CFLAGS = -I$(KDIR)/build
APP_NAME = timer_irq_test

output = $(MODULE_NAME).ko $(APP_NAME)

all: $(output)
$(MODULE_NAME).ko: $(MODULE_NAME).c
	$(MAKE) -C /lib/modules/$(KDIR)/build M=$(PWD) modules
$(APP_NAME): $(APP_NAME).c
	$(CC) $< -o $@

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -rf $(APP_NAME)
install:
	cp -/$(MODULE_NAME).ko ~/$(APP_NAME) /srv/nfs4

else
obj-m := $(MODULE_NAME).o
endif
