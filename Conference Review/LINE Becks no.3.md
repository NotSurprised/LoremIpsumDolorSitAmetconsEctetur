# LINE Becks #3

## Windows Defender Analysis
1. check the content of the file whether malicious data include
    close()/open()/stat()/run
2. change permission to prevent user from accessing
3. replace malicious part with null/space(?)
4. (deleting entire file)

Windows Defender analysis is tiresome work
* Unexpected behevior

find oldversion in git : github/0xalexei/windowsDefender

IDA pro with symbol from blackhat resource

WDExtract

demo of attack PoC : github/iccty/AvOracle-gallery

1. get emulator of windows defend
2. us jscript engine to eval() something

1. combine statement will not detect eval("EICA"+"R")
    object sccessing will be helpful
2. parser will stop by NULL

$idx $c in body can be available

Contolleable1 : <script>...</script><body>
Secret : (secret)
Controllable2 : ...</body>

Other attack surface
* AvOracle needs some prerequisities
* false positivev triggering is still effective
* Windows IIS issue (already fix)

How to prevent
* IMO: no generic way to patch

Windows Defender is smartest, else antivirus don't have itelligent analysis


## Supply chain attack & APT malware

### Supply chain Security
APT Group attack Taiwan
* BlackTech (PLEAD)
* Winnti Group (Winnti)
* APT 27 "Lstudio" (Elise)

New trend in APT
* Suply chain 
* Synthesis

Every step your dev a project is possible to be compromised
copy code + stack overflow + text book -> Source code -> version control(git config attack) + library code -> compiler(xcodeGhost) -> static library linker -> executable -> CI(jenkinsRCE) -> executables -> dynamic library -> loader -> executing

Is stack overflow harmful? 

PSEXEC WMI Bitadmin Certutils 
check "LOLBAS" for more useful binary

### Shadow Hammer Operation

2019/01 ASUS has release update without discription

Setup.exe 9A72F971944FCB7A143017BC5C6C2DB913BBB59F923110198EBD5A78809EA5FC

AV/EDR may skip expect the ASUS signed binary

Shellcode append to end of binary and use library to call it beyond dev aware
1. first Shellcode wwas encrypted using Winnti's algorithm and hid in resource under "EXE" type
2. second shellcode locat kernel32.dll and search LoadlibraryEXW

Use GetAdaptersAddresses to list network interface to get MAC

Cycarrier bruteforce the MD5 hash of 606 hash targeted in this sample.

### Web Storage Operation

ASUS 2019/04/24 China PLEAD APT group

ASUS web storage will auto load and download the malware then install the payload

Drop file to Windows/

Obfuscation with useless function call:
* GetLastError
* GetTickCount
* ...

### Malware Trick
Find Malicious Payload in 1 sec
* Malware system call must call ntdll
* shellcode must locate dll in memory from PEB 

Attacker usually use compiler to generate Shellcode
* sRDI - convert your dll into shellcode
* MemoryModule - parse and load PE module (popular without write something into file, escape from anti-virus)

### Threat Investigating Process
investigating procedure
1. observe
2. conceive Threat Hypothesis
3. Investifate
4. check Hypothesis (skip to 6)
5. Revise Hypothesis (back to 3)
6. Confirm Hypothesis

APT Investigate process
1. Threat Hunting
    Provative&Regular investigate the attacker
    Tool: 
    * Xensor (EDR system)
    * CyCarrier (correlates the events)
2. Threat Investigate
    domain active hunting (eg. asushotfix.com)
3. Malware Analysis
4. Threat Intelligence
5. Feedback


CyCraft