obj-m += hello_world_1.o kprobes_blacklist.o kprobes_chdir.o kprobes_patch.o \
kprobes_printk.o kprobes_reenter.o kprobes_syscall_asm.o

KERN_VERSION = 7.2.0-rc7-g62455cff49c1-dirty

all:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" modules

clean:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" clean
