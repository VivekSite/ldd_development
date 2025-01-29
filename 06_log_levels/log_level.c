#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("Example Uses of Kernel Log Levels");

static int __init my_init(void)
{
	printk(KERN_ALERT "log_level: This is a Alert log message\n");
	printk(KERN_CRIT "log_level: This is a Critical log message\n");
	printk(KERN_ERR "log_level: This is a Error log message\n");
	printk(KERN_WARNING "log_level: This is a Warning log message\n");
	printk(KERN_NOTICE "log_level: This is a Notice log message\n");
	printk(KERN_INFO "log_level: This is a Information log message\n");
	printk(KERN_DEBUG "log_level: This is a Debug log message\n");
	return 0;
}

static void __exit my_exit(void)
{
	pr_emerg("log_level: Module is unloaded!\n");  // Use macro for Emergency log
}

module_init(my_init);
module_exit(my_exit);
