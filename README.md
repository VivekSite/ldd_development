### Frequently Used Command
#### Load/Remove Modules
- `sudo insmod *.ko`														- Load module
- `sudo rmmod <module_name>`										- Remove module from kernel

- `sudo modprobe *.ko`													- Load module along with its dependencies
- `sudo modprobe -r <module_name>`							- Remove kernel module
- `sudo modprobe --show-depends <module_name>` 	- Show module dependencies

#### Kernel Logs
- `sudo dmesg`								- Display kernel logs
- `sudo dmesg -w`							- Display previous kernel logs and watch
- `sudo dmesg -W`							- Watch for new kernel logs
- `sudo dmesg | tail`					- Display last lines of kernel logs
- `sudo dmesg | tail -n 1`		- Display last one line of kernel logs

#### Get Modules Info
- `lsmod`											- List all kernel modules
- `sudo modinfo *.ko`					- Get information of kernel module
- `sudo modinfo modulename`		- Get information of built-in kernel module by name
