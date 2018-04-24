# **Expand Linux Disk**

```shell=
sudo fdisk /dev/sda

Command (m for help): n

Command action
   e   extended
   p   primary partition (1-4)
p

Partition number (1-4): 3

First cylinder (1045-2610, default 1045): 
Using default value 1045

Last cylinder or +size or +sizeM or +sizeK (1045-2610, default 2610): 
Using default value 2610

Command (m for help): p

Disk /dev/sda: 21.4 GB, 21474836480 bytes
255 heads, 63 sectors/track, 2610 cylinders
Units = cylinders of 16065 * 512 = 8225280 bytes

   Device Boot      Start         End      Blocks   Id  System
/dev/sda1   *           1          13      104391   83  Linux
/dev/sda2              14        1044     8281507+  8e  Linux LVM
/dev/sda3            1045        2610    12578895   83  Linux

Command (m for help): w
The partition table has been altered!

Calling ioctl() to re-read partition table.
```

```shell=
sudo apt-get install system-config-lvm
```

Then use Volume Management to add/format new volume.

※Attention: these method can't expand system volume, only can add new space to store some beings.