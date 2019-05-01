# BambooFox Forensic IR Training
###### tags: `Review`

Cycarrier's researcher-Bletchley

Moloch IR workshop

VM ac:  forensic
VM psw: forensic

Then start the service
```
systemctl start elasticsearch
systemctl start molochviewer
```

It's already install in VM, beter install by yourself:
https://blog.csdn.net/zhuguorong11/article/details/71813274
Auto install package:
https://molo.ch/#downloads
Or more hand-made style -- clone the repository:
https://github.com/aol/moloch
```
git clone https://github.com/aol/moloch
cd moloch
./easybutton-build.sh --install
make config
```
Its requirements:
* python (already installed in ubuntu)
* elasticsearch (JDK)
* nodejs

![](https://i.imgur.com/4VX8gUc.png)

http://0.0.0.0:8005/status
![](https://i.imgur.com/9aYbj3L.png)

smb.fn == "*.exe" || smb.fn == "*.dll"
![](https://i.imgur.com/N3rD4mp.png)

smb.fn == "*psexesvc.exe*"
![](https://i.imgur.com/tvIfMmu.png)

smb.fn == "*.exe" || smb.fn == "*.dll" && protocols == smb
![](https://i.imgur.com/S9qIlUd.png)

![](https://i.imgur.com/82S7Kyy.png)

![](https://i.imgur.com/CcyNBFj.png)

ip == 192.168.137.41 && ip 192.168.137.21
![](https://i.imgur.com/FyQ0g39.png)
Attacker change the encode page to fit the env.

![](https://i.imgur.com/oOlvGrR.png)
bitsadmin not really a malware, but a system admin tool
The attacker uses bitsadmin to transfer some executables

![](https://i.imgur.com/86qKzT5.png)
