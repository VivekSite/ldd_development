#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("This is a simple hello world module.");

/**
 * A CallBack Function which Get invoked when module is loaded
 * 
 * Static keyword limits the scope of the function to the current source file 
 * __init is a macro to increase the readability of module
 */
static int __init my_init(void)
{
	printk("Hello vivek, the module is loaded\n");
	return 0;
}


/**
 * A CallBack Function which Get invoked when module is removed
 * 
 * Static keyword limits the scope of the function to the current source file 
 * The __exit macro ensures that the function is only used when unloading the 
 * module and is removed from built-in modules to save space.
 */
static void __exit my_exit(void)
{
	printk("Bye, Mr. Kernel!\n");
}

module_init(my_init);
module_exit(my_exit);
