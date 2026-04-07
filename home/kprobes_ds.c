#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>

// WARNING: Addresses might be different after rebuilding the kernel!

static struct kprobe kp = {
    .addr = 0xc014837c, // l.or preceded by l.jal
};

static int my_pre_handler(struct kprobe *p, struct pt_regs *regs) {
    printk(KERN_INFO "Running prehandler for insn in delay slot\n");
    return 0;
}

static int __init init_fn(void) {
    int ret;

    kp.pre_handler = my_pre_handler;
    ret = register_kprobe(&kp);
    if (ret < 0) {
        printk(KERN_INFO "Failed to register kprobe (%d)\n", ret);
        return ret;
    }

    printk(KERN_INFO "Successfully registered kprobes\n");
    return 0;
}

static void __exit exit_fn(void) {
    unregister_kprobe(&kp);
    printk(KERN_INFO "Successfully unregistered kprobes\n");
}

module_init(init_fn);
module_exit(exit_fn);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("valdaarhun");
MODULE_DESCRIPTION("Out-of-line bp");
