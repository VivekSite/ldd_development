#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("Implement Open and Release operations for chrdevice");

static int major;

static int my_open (struct inode *inode, struct file *file_p) {
	pr_info("open_release_cdev: Major: %d, Minor %d\n", imajor(inode), iminor(inode));

	pr_info("open_release_cdev: file_p->f_pos: %lld\n", file_p->f_pos);
	pr_info("open_release_cdev: file_p->f_mode: 0x%x\n", file_p->f_mode);
	pr_info("open_release_cdev: file_p->f_flags: 0x%x\n", file_p->f_flags);

	return 0;
}

static int my_release (struct inode *inode, struct file *file) {
	pr_info("open_release_cdev: File is closed\n");
	return 0;
}

static struct file_operations fops = {
	.open = my_open,
	.release = my_release,
};

static int __init my_init(void)
{
	major = register_chrdev(0, "open_release_cdev", &fops);
	if (major < 0)
	{
		printk("open_release_cdev: Error registering chrdev\n");
		return major;
	}

	printk("open_release_cdev: Major Device Number: %d\n", major);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_chrdev(major, "open_release_cdev");
}

module_init(my_init);
module_exit(my_exit);
