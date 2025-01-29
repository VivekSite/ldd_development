#### Register a character device
```
// Register a device
register_chrdev(0, "hello_cdev", &fops);

1st - Major device number (0 means assign number dynamically)
		- if 0 then returns the device number otherwise it will return zero on success
2nd - Device Label which appear in /proc/devices
3rd - File operations object

// Unregister a device
unregister_chrdev(major, "hello_cdev");

1st - Major device number
2nd - Device Label which appear in /proc/devices
```
- `sudo mknod /dev/hello0 c 236 0` - Create a device file with major number 236 and minor 0
- `cat /dev/hello0` - Run read operation on created Char driver
- Definition for file_operations struct `https://elixir.bootlin.com/linux/v6.13/source/include/linux/fs.h#L2071`

