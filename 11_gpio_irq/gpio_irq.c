#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/gpio/consumer.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vivek Sahani");
MODULE_DESCRIPTION("A simple LKM for a gpio interrupt");

#define IO_OFFSET 512
#define IO_BUTTON 17

static struct gpio_desc *button;
int irq_number;

static irqreturn_t gpio_irq_handler(int irq, void *dev_id) {
	printk(KERN_INFO "gpio_irq: Interrupt is triggered and ISR was called!\n");
	return IRQ_HANDLED;
}

static int __init my_init(void)
{
	printk("gpio_irq: Loading module...\n");

	int status;

	// Use GPIO descriptor API
	button = gpio_to_desc(IO_BUTTON + IO_OFFSET);
	if (!button) {
		printk(KERN_ERR "gpio_irq: Failed to get GPIO descriptor for %d\n", IO_BUTTON);
		return -ENODEV;
	}

	status = gpiod_direction_input(button);
	if (status) {
		printk(KERN_ERR "gpio_irq: Failed to set GPIO %d as input\n", IO_BUTTON);
		return status;
	}

	// Setup interrupt
	irq_number = gpiod_to_irq(button);
	if (irq_number < 0) {
		printk(KERN_ERR "gpio_irq: Error mapping GPIO to IRQ\n");
		return irq_number;
	}

	// status = request_irq(irq_number, gpio_irq_handler, IRQF_TRIGGER_RISING, "my_gpio_irq", NULL);
	status = request_irq(irq_number, gpio_irq_handler, IRQF_TRIGGER_FALLING, "my_gpio_irq", NULL);
	if (status) {
		printk(KERN_ERR "gpio_irq: Error requesting interrupt %d\n", irq_number);
		return status;
	}

	printk("gpio_irq: Done!\n");
	printk("gpio_irq: GPIO %d! is mapped to irq number: %d\n", IO_BUTTON, irq_number);
	return 0;
}

static void __exit my_exit(void)
{
	printk("gpio_irq: Unloading module...\n");
	free_irq(irq_number, NULL);
	printk("gpio_irq: Done Unloading.\n");

}

module_init(my_init);
module_exit(my_exit);
