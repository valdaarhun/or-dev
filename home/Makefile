obj-m += hello_world_1.o kprobes_chdir.o kprobes_simu.o kprobes_reenter.o \
kprobes_blacklist.o kprobes_ds.o kprobes_syscall_asm.o \
kprobes_printk.o kprobes_patch.o

KERN_VERSION = 6.19.0-rc5-gb8d563d38f7e

all:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" modules

clean:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" clean
