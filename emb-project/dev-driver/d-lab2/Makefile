obj-m := hello_module.o
KDIR := /home/shj/guswns8431-4th-industrial-smart-convergence-sw-developer-training-course/emb-project/dev-driver
PWD := $(shell pwd)

all: driver
driver:
$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf *.o

