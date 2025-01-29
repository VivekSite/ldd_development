#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("A sample driver for registering character device.");

static int major;

static ssize_t my_read(struct file *file, char __user *user, size_t l, loff_t *offset)
{
	printk("hello_cdev - Read is called\n");
	return 0;
}

static struct file_operations fops = {
		.read = my_read
};

static int __init my_init(void)
{
	major = register_chrdev(0, "hello_cdev", &fops);
	if (major < 0)
	{
		printk("hello_cdev - Error registering chrdev\n");
		return major;
	}

	printk("hello_cdev - Major Device Number: %d\n", major);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_chrdev(major, "hello_cdev");
}

module_init(my_init);
module_exit(my_exit);
