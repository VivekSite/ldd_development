#### Kernel Log Level

- source - `https://www.kernel.org/doc/html/latest/core-api/printk-basics.html`
- `suod dmesg -l 1` - specify the log level here it is 1 for alert messages

| Name         | String | Alias Function |
| ------------ | ------ | -------------- |
| KERN_EMERG   | "0"    | pr_emerg()     |
| KERN_ALERT   | "1"    | pr_alert()     |
| KERN_CRIT    | "2"    | pr_crit()      |
| KERN_ERR     | "3"    | pr_err()       |
| KERN_WARNING | "4"    | pr_warn()      |
| KERN_NOTICE  | "5"    | pr_notice()    |
| KERN_INFO    | "6"    | pr_info()      |
| KERN_DEBUG   | "7"    | pr_debug()     |
| KERN_DEFAULT | ""     |                |
| KERN_CONT    | "c"    | pr_cont()      |
