obj-m:=test.o
KERNELDIR := /lib/modules/2.6.38-12-generic/build
PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
clean:
	rm -rf *o .depend .*.cmd *.ko *.mod.c .tmp_versions
