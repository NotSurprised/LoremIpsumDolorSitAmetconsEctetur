# **BLE study**

```shell
ubuntu@ubuntu-virtual-machine:~$ sudo apt-get install blueman bluez:i386 bluetooth
ubuntu@ubuntu-virtual-machine:~$ hcitool dev
Devices:
	hci0	00:15:83:F3:43:90
ubuntu@ubuntu-virtual-machine:~$ sudo hciconfig hci0 up
ubuntu@ubuntu-virtual-machine:~$ sudo hcitool lescan
```

```c
//if Error: connect error: Connection refused (111)
//append /etc/bluetooth/main.config
//cd /etc/bluetooth/main.config
//sudo chmod 777 main.conf
EnableLE = true

AttributeServer = true

DisablePlugins = pnat
```

```shell
service bluetooth restart

sudo hciconfig hci0 down

sudo hciconfig hci0 up
```

```shell
gatttool -I -b FA:F2:FD:B7:39:83
[FA:F2:FD:B7:39:83][LE]> connect
Attempting to connect to FA:F2:FD:B7:39:83
Error: connect error: Function not implemented (38)
```