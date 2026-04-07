obj-m += hello_world_1.o kprobes_test.o kprobes_simu.o kprobes_reenter.o \
kprobes_blacklist.o kprobes_l_sys.o kprobes_ds.o \
kprobes_recursive.o kprobes_asm.o kprobes_patch.o

KERN_VERSION = 6.19.0-rc5-gd2b76dd32049

all:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" modules

clean:
	make -C /lib/modules/$(KERN_VERSION)/build M=$(PWD) ARCH=openrisc CROSS_COMPILE="or1k-buildroot-linux-gnu-" clean
