#### /dev vfs
- /dev is a virtual file system holding interfaces of drivers
- Drivers type: characer, block and network
- Each device has there own unique pair of major and minor device numbers
- `cat /proc/devices` - Check all Major Device numbers
- `sudo mknod <device_name> <device_type c|b|n> <Major_number> <Minor_number>` - Create new device file
- Device files are linked to driver with their major and minor device number not with their name
- Every Major device can have 256 Minor Device numbers
