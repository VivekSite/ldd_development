#include <linux/module.h>
#include <linux/init.h>
#include <linux/hrtimer.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("A simple LKM using High Resolution Timers");

// hr timer
static struct hrtimer my_hrtimer;
u64 start_t;

static enum hrtimer_restart test_hrtimer_handler(struct hrtimer *timer) {
	// Get current time
	u64 now_t = jiffies;
	printk("start_t - now_t = %u\n", jiffies_to_msecs(now_t - start_t));

	return HRTIMER_NORESTART;
}

static int __init my_init(void)
{
	printk("DEBUG_PRING_1\n");

	// Initialize hrtimer
	hrtimer_init(&my_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	my_hrtimer.function = &test_hrtimer_handler;
	start_t = jiffies;
	hrtimer_start(&my_hrtimer, ms_to_ktime(100), HRTIMER_MODE_REL);

	printk("DEBUG_PRING_2\n");
	return 0;
}

static void __exit my_exit(void)
{
	printk("Bye, Mr. Kernel!\n");
	hrtimer_cancel(&my_hrtimer);
}

module_init(my_init);
module_exit(my_exit);
