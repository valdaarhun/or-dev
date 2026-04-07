#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>

static struct kprobe kp = {
    .symbol_name = "patch_insn_write",
};

static int my_pre_handler_hello(struct kprobe *p, struct pt_regs *regs) {
    printk(KERN_INFO "Inside pre-handler... Processing KProbe (patch_insn_write)\n");
    return 0;
}

static void my_post_handler(struct kprobe *p, struct pt_regs *regs, unsigned long flags) {
    printk(KERN_INFO "Inside post-handler... Finishing KProbe processing (patch_insn_write)\n");
}

static int __init init_fn(void) {
    int ret;

    kp.pre_handler = my_pre_handler_hello;
    kp.post_handler = my_post_handler;
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
MODULE_DESCRIPTION("Simple kprobes for or1k");
