#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>

static struct kprobe kp1 = {
    .addr = 0xc01484e8, // l.jal
};

static struct kprobe kp2 = {
    .addr = 0xc01484f4, // l.bf
};

static int my_pre_handler(struct kprobe *p, struct pt_regs *regs) {
    printk(KERN_INFO "Running prehandler for emulated instruction\n");
    return 0;
}

static void my_post_handler(struct kprobe *p, struct pt_regs *regs, unsigned long flags) {
    printk(KERN_INFO "Inside post-handler... Finishing KProbe processing\n");
}

static int __init init_fn(void) {
    int ret;

    kp1.pre_handler = my_pre_handler;
    kp1.post_handler = my_post_handler;
    ret = register_kprobe(&kp1);
    if (ret < 0) {
        printk(KERN_INFO "Failed to register kprobe (%d)\n", ret);
        return ret;
    }

    kp2.pre_handler = my_pre_handler;
    kp2.post_handler = my_post_handler;
    ret = register_kprobe(&kp2);
    if (ret < 0) {
        printk(KERN_INFO "Failed to register kprobe (%d)\n", ret);
        unregister_kprobe(&kp1);
        return ret;
    }

    printk(KERN_INFO "Successfully registered kprobes\n");
    return 0;
}

static void __exit exit_fn(void) {
    unregister_kprobe(&kp1);
    unregister_kprobe(&kp2);
    printk(KERN_INFO "Successfully unregistered kprobes\n");
}

module_init(init_fn);
module_exit(exit_fn);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("valdaarhun");
MODULE_DESCRIPTION("Out-of-line bp");
