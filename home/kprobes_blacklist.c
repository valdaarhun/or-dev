#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>

// WARNING: Addresses might be different after rebuilding the kernel!

static struct kprobe kp1 = {
    .addr = 0xc000028c, // l.mtspr
};

static struct kprobe kp2 = {
    .addr = 0xc0000204, // l.mfspr
};

static struct kprobe kp3 = {
    .addr = 0xc0002190, // l.swa
};

static struct kprobe kp4 = {
    .addr = 0xc00039ec, // l.lwa
};

static struct kprobe kp5 = {
    .addr = 0xc000f0b8, // l.rfe
};

static struct kprobe kp6 = {
    .addr = 0xc0506338, // l.sys
};

static struct kprobe kp7 = {
    .addr = 0xc04f2578, // l.csync
};

static struct kprobe kp8 = {
    .addr = 0xc008d2c8, // l.msync
};

static int __init init_fn(void) {
    int ret;

    ret = register_kprobe(&kp1);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp2);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp3);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp4);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp5);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp6);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp7);
    printk(KERN_INFO "register kprobe returned %d\n", ret);
    ret = register_kprobe(&kp8);
    printk(KERN_INFO "register kprobe returned %d\n", ret); 

    printk(KERN_INFO "Successfully registered kprobes\n");
    return 0;
}

static void __exit exit_fn(void) {
    unregister_kprobe(&kp1);
    unregister_kprobe(&kp2);
    unregister_kprobe(&kp3);
    unregister_kprobe(&kp4);
    unregister_kprobe(&kp5);
    unregister_kprobe(&kp6);
    unregister_kprobe(&kp7);
    unregister_kprobe(&kp8);
    printk(KERN_INFO "Successfully unregistered kprobes\n");
}

module_init(init_fn);
module_exit(exit_fn);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("valdaarhun");
MODULE_DESCRIPTION("Out-of-line bp");
