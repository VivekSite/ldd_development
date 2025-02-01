#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>
#include <linux/gpio/consumer.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("A simple test for LKM's Timer ");

#define IO_LED 16
#define IO_OFFSET 512

static struct gpio_desc *led;

// Variable for timer
static struct timer_list my_timer; 

static void timer_callback (struct timer_list * data) {
		gpiod_set_value(led, 0); // Turn led off
}

static int __init my_init(void)
{
	printk("DEBUG_PRING_1\n");
	int status;

	led = gpio_to_desc(IO_LED + IO_OFFSET);
	if (!led) {
		printk("gpioctrl - Error getting pin %d\n", IO_LED);
		return -ENODEV;
	}

	printk("DEBUG_PRING_2\n");

	status = gpiod_direction_output(led, 0);
	if (status) {
		printk("gpioctrl - Error setting pin 20 to output\n");
		return status;
	}

	printk("DEBUG_PRING_3\n");
	// Turn LED on
	gpiod_set_value(led, 1);

	// Initialize timer
	timer_setup(&my_timer, timer_callback, 0);
	mod_timer(&my_timer, jiffies + msecs_to_jiffies(5000));

	printk("DEBUG_PRING_4\n");
	return 0;
}

static void __exit my_exit(void)
{
	printk("Bye, Mr. Kernel!\n");
	del_timer(&my_timer);
	gpiod_set_value(led, 0);
}

module_init(my_init);
module_exit(my_exit);
