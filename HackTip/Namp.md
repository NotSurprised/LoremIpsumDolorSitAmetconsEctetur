# nmap
```shell
ubuntu@ubuntu-virtual-machine:~$ nslookup damn.evils.in
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
Name:	damn.evils.in
Address: 140.96.173.109
```

```shell
ubuntu@ubuntu-virtual-machine:~$ nmap -p- damn.evils.in

Starting Nmap 7.60 ( https://nmap.org ) at 2018-07-31 13:23 CST
Nmap scan report for damn.evils.in (140.96.173.109)
Host is up (0.0040s latency).
Not shown: 65532 filtered ports
PORT     STATE SERVICE
80/tcp   open  http
135/tcp  open  msrpc
3389/tcp open  ms-wbt-server

Nmap done: 1 IP address (1 host up) scanned in 702.63 seconds
```

```shell
ubuntu@ubuntu-virtual-machine:~$ sudo nmap -Pn 140.96.173.109 -sV -sC -O -oX 140.96.173.109.txt -vv
[sudo] password for ubuntu: 

Starting Nmap 7.60 ( https://nmap.org ) at 2018-07-31 15:03 CST
NSE: Loaded 146 scripts for scanning.
NSE: Script Pre-scanning.
NSE: Starting runlevel 1 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 0.00s elapsed
NSE: Starting runlevel 2 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 0.00s elapsed
Initiating Parallel DNS resolution of 1 host. at 15:03
Completed Parallel DNS resolution of 1 host. at 15:03, 0.00s elapsed
Initiating SYN Stealth Scan at 15:03
Scanning 140.96.173.109 [1000 ports]
Discovered open port 135/tcp on 140.96.173.109
Discovered open port 3389/tcp on 140.96.173.109
Discovered open port 80/tcp on 140.96.173.109
Completed SYN Stealth Scan at 15:03, 14.69s elapsed (1000 total ports)
Initiating Service scan at 15:03
Scanning 3 services on 140.96.173.109
Completed Service scan at 15:03, 22.06s elapsed (3 services on 1 host)
Initiating OS detection (try #1) against 140.96.173.109
NSE: Script scanning 140.96.173.109.
NSE: Starting runlevel 1 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 4.08s elapsed
NSE: Starting runlevel 2 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 0.00s elapsed
Nmap scan report for 140.96.173.109
Host is up, received user-set (0.0024s latency).
Scanned at 2018-07-31 15:03:13 CST for 42s
Not shown: 997 filtered ports
Reason: 997 no-responses
PORT     STATE SERVICE REASON          VERSION
80/tcp   open  http    syn-ack ttl 122 Microsoft IIS httpd 8.5
| http-methods: 
|   Supported Methods: OPTIONS TRACE GET HEAD POST
|_  Potentially risky methods: TRACE
| http-robots.txt: 1 disallowed entry 
|_/
|_http-server-header: Microsoft-IIS/8.5
|_http-title: Site doesn't have a title (text/html).
135/tcp  open  msrpc   syn-ack ttl 122 Microsoft Windows RPC
3389/tcp open  ssl     syn-ack ttl 122 Microsoft SChannel TLS
| fingerprint-strings: 
|   TLSSessionReq: 
|     SG400-SE0
|     180729065128Z
|     190128065128Z0
|     SG400-SE0
|     \xf4|
|     SX4XJt
|     \xdf
|     A#6{
|     6iVbjt
|     WSin
|     $0"0
|     ObH&
|_    [\x9da
| ssl-cert: Subject: commonName=SG400-SE
| Issuer: commonName=SG400-SE
| Public Key type: rsa
| Public Key bits: 2048
| Signature Algorithm: sha256WithRSAEncryption
| Not valid before: 2018-07-29T06:51:28
| Not valid after:  2019-01-28T06:51:28
| MD5:   c43b d5d5 0cd5 fca8 c501 e8c4 5ecc b9b6
| SHA-1: c430 57d6 b2d1 369a 598f 0ac5 8002 8a6f 169b 8f17
| -----BEGIN CERTIFICATE-----
| MIIC1DCCAbygAwIBAgIQaFqxiD2qnahJYhYHCHaOuDANBgkqhkiG9w0BAQsFADAT
| MREwDwYDVQQDEwhTRzQwMC1TRTAeFw0xODA3MjkwNjUxMjhaFw0xOTAxMjgwNjUx
| MjhaMBMxETAPBgNVBAMTCFNHNDAwLVNFMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8A
| MIIBCgKCAQEAsO8EZSyzxY/8ery0ueG3QFDm/wyRDgi9TmxjrpjAPnSj1ay74J9f
| amW4jyccMQIp5dL5f5gpAQDn5vfajdtJEuJe5W41k43pLyF1yc4kn382yMjsSrs2
| bbCsv9IHAS/yd/7qXyjoXGQUkea4yw7ZNPmmC1fkr9D37+SFh5wJW4oW6uruljn0
| CVz0fMwI8lNYNFhKdBMz9yFBjDlsOR8Mi7CF7oPzumKF6X7k/VHJXN+HXQ/dTgZP
| 2ZpXuHjaJrhBIzZ7Grz0bcVjrMflFZ8vTrU2aVZianQdrT1bAkQ0IcRAyr/TuxuJ
| lETyV1Npbq2xDHtihbHe5bUrBtj5Ihr7bQIDAQABoyQwIjATBgNVHSUEDDAKBggr
| BgEFBQcDATALBgNVHQ8EBAMCBDAwDQYJKoZIhvcNAQELBQADggEBAFg8CDDWHndC
| xlOpAZ5R/6GX3nk2QZDdpBjpQcAm2xOkHWnYbJgSYneECl2kaQZcT2JIJrU9aqXL
| j8kqBkO/7J0r8T13AdkGWfRoZVbMhULvgdaO91aVqSF3/FnwfTnZ7c5QfNlE0688
| Tufrq5kH6ptVYl6mN+owF468DAYxbx77vPeU9ivMimvCWSmbbbHimIlPBKsHfQUd
| qsCutrYIHORoG88+n9i3I485lxBeBseblvSUGx0jp43leZ5x+fw3eq5bXJ1h7Xmr
| 7sj9HckuschAWJXtPv8og8DgHlVMpGSU59QhVs9MzCQ3KK/SYHU70r5ti1MMyvrp
| 5TBfR+spGPY=
|_-----END CERTIFICATE-----
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port3389-TCP:V=7.60%I=7%D=7/31%Time=5B6009CB%P=x86_64-pc-linux-gnu%r(TL
SF:SSessionReq,33C,"\x16\x03\x03\x037\x02\0\0M\x03\x03\[`\t\xc7\xf0U\xb4\x
SF:d9#\xb9\xaf\xa2\xd9C\xa0\xf9\xbc\xa0\xd0\x1a\*\x94\xa1\xffi\xed\x1c\xeb
SF:\xfa\xa4\nQ\x20\xcb4\0\0b\x9cy\x04k\x02\x1a\xb3\xd2\xc1\xeaU\x8a_\x88KZ
SF:\x84Z\x20\+\x1d\xb9\xc7\xd6A\xeb\xcf\0/\0\0\x05\xff\x01\0\x01\0\x0b\0\x
SF:02\xde\0\x02\xdb\0\x02\xd80\x82\x02\xd40\x82\x01\xbc\xa0\x03\x02\x01\x0
SF:2\x02\x10hZ\xb1\x88=\xaa\x9d\xa8Ib\x16\x07\x08v\x8e\xb80\r\x06\t\*\x86H
SF:\x86\xf7\r\x01\x01\x0b\x05\x000\x131\x110\x0f\x06\x03U\x04\x03\x13\x08S
SF:G400-SE0\x1e\x17\r180729065128Z\x17\r190128065128Z0\x131\x110\x0f\x06\x
SF:03U\x04\x03\x13\x08SG400-SE0\x82\x01\"0\r\x06\t\*\x86H\x86\xf7\r\x01\x0
SF:1\x01\x05\0\x03\x82\x01\x0f\x000\x82\x01\n\x02\x82\x01\x01\0\xb0\xef\x0
SF:4e,\xb3\xc5\x8f\xfcz\xbc\xb4\xb9\xe1\xb7@P\xe6\xff\x0c\x91\x0e\x08\xbdN
SF:lc\xae\x98\xc0>t\xa3\xd5\xac\xbb\xe0\x9f_je\xb8\x8f'\x1c1\x02\)\xe5\xd2
SF:\xf9\x7f\x98\)\x01\0\xe7\xe6\xf7\xda\x8d\xdbI\x12\xe2\^\xe5n5\x93\x8d\x
SF:e9/!u\xc9\xce\$\x9f\x7f6\xc8\xc8\xecJ\xbb6m\xb0\xac\xbf\xd2\x07\x01/\xf
SF:2w\xfe\xea_\(\xe8\\d\x14\x91\xe6\xb8\xcb\x0e\xd94\xf9\xa6\x0bW\xe4\xaf\
SF:xd0\xf7\xef\xe4\x85\x87\x9c\t\[\x8a\x16\xea\xea\xee\x969\xf4\t\\\xf4\|\
SF:xcc\x08\xf2SX4XJt\x133\xf7!A\x8c9l9\x1f\x0c\x8b\xb0\x85\xee\x83\xf3\xba
SF:b\x85\xe9~\xe4\xfdQ\xc9\\\xdf\x87\]\x0f\xddN\x06O\xd9\x9aW\xb8x\xda&\xb
SF:8A#6{\x1a\xbc\xf4m\xc5c\xac\xc7\xe5\x15\x9f/N\xb56iVbjt\x1d\xad=\[\x02D
SF:4!\xc4@\xca\xbf\xd3\xbb\x1b\x89\x94D\xf2WSin\xad\xb1\x0c{b\x85\xb1\xde\
SF:xe5\xb5\+\x06\xd8\xf9\"\x1a\xfbm\x02\x03\x01\0\x01\xa3\$0\"0\x13\x06\x0
SF:3U\x1d%\x04\x0c0\n\x06\x08\+\x06\x01\x05\x05\x07\x03\x010\x0b\x06\x03U\
SF:x1d\x0f\x04\x04\x03\x02\x0400\r\x06\t\*\x86H\x86\xf7\r\x01\x01\x0b\x05\
SF:0\x03\x82\x01\x01\0X<\x080\xd6\x1ewB\xc6S\xa9\x01\x9eQ\xff\xa1\x97\xdey
SF:6A\x90\xdd\xa4\x18\xe9A\xc0&\xdb\x13\xa4\x1di\xd8l\x98\x12bw\x84\n\]\xa
SF:4i\x06\\ObH&\xb5=j\xa5\xcb\x8f\xc9\*\x06C\xbf\xec\x9d\+\xf1=w\x01\xd9\x
SF:06Y\xf4heV\xcc\x85B\xef\x81\xd6\x8e\xf7V\x95\xa9!w\xfcY\xf0}9\xd9\xed\x
SF:ceP\|\xd9D\xd3\xaf<N\xe7\xeb\xab\x99\x07\xea\x9bUb\^\xa67\xea0\x17\x8e\
SF:xbc\x0c\x061o\x1e\xfb\xbc\xf7\x94\xf6\+\xcc\x8ak\xc2Y\)\x9bm\xb1\xe2\x9
SF:8\x89O\x04\xab\x07}\x05\x1d\xaa\xc0\xae\xb6\xb6\x08\x1c\xe4h\x1b\xcf>\x
SF:9f\xd8\xb7#\x8f9\x97\x10\^\x06\xc7\x9b\x96\xf4\x94\x1b\x1d#\xa7\x8d\xe5
SF:y\x9eq\xf9\xfc7z\xae\[\\\x9da\xedy\xab\xee\xc8\xfd\x1d\xc9\.\xb1\xc8@X\
SF:x95\xed>\xff\(\x83\xc0\xe0\x1eUL\xa4d\x94\xe7\xd4!V\xcfL\xcc\$7\(\xaf\x
SF:d2`u;\xd2\xbem\x8bS\x0c\xca\xfa\xe9\xe50_G\xeb\)\x18\xf6\x0e\0\0\0");
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running: Microsoft Windows 2012
OS CPE: cpe:/o:microsoft:windows_server_2012:r2
OS details: Microsoft Windows Server 2012 or Windows Server 2012 R2
TCP/IP fingerprint:
OS:SCAN(V=7.60%E=4%D=7/31%OT=80%CT=%CU=%PV=N%G=N%TM=5B6009DB%P=x86_64-pc-li
OS:nux-gnu)SEQ(SP=103%GCD=1%ISR=104%TI=I%TS=7)OPS(O1=M5B4NW8ST11%O2=M5B4NW8
OS:ST11%O3=M5B4NW8NNT11%O4=M5B4NW8ST11%O5=M5B4NW8ST11%O6=M5B4ST11)WIN(W1=20
OS:00%W2=2000%W3=2000%W4=2000%W5=2000%W6=2000)ECN(R=Y%DF=Y%TG=80%W=2000%O=M
OS:5B4NW8NNS%CC=Y%Q=)T1(R=Y%DF=Y%TG=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)
OS:T4(R=N)U1(R=N)IE(R=N)

Uptime guess: 1.510 days (since Mon Jul 30 02:49:52 2018)
TCP Sequence Prediction: Difficulty=259 (Good luck!)
IP ID Sequence Generation: Incremental
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

NSE: Script Post-scanning.
NSE: Starting runlevel 1 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 0.00s elapsed
NSE: Starting runlevel 2 (of 2) scan.
Initiating NSE at 15:03
Completed NSE at 15:03, 0.00s elapsed
Read data files from: /usr/bin/../share/nmap
OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 43.27 seconds
           Raw packets sent: 3046 (136.592KB) | Rcvd: 18 (892B)
```