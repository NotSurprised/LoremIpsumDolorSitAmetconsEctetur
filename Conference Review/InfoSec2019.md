# InfoSec 2019
## 從執法角度思考銀行提款機盜領威脅的犯罪調查與數位鑑識
Exif tool
authorship

## XML XXE XEE Xpath
DTD document type definition
external DTD
* Tamper (XML Injection)
* Send (XXE、XEE)
* Extract (Xpath)

XML Tag Injection

XML eXternal Entity


## Hacking Jenkins
對於 紅隊演練(Red Team) 來說, Jenkins 更是兵家必爭之地, 只要能掌握企業暴露在外的 Jenkins 即可掌握大量的原始碼, 登入憑證甚至控制大量的 Jenkins 節點!

### Jenkins On the Net
Microsoft jenkins on public network

### Java Web
web.xml

### Java problem
#### Inherit Object
可以串
#### WhiteList Bypass
檢測很嚴 但只測prefix 路徑
如果一直合法的串出一個 Search Object 就可以 bypass

前面所提到的 ANONYMOUS_READ, 其中 True 與 False 間最大的不同在於當在禁止的狀況下, 最初的入口點會透過 jenkins.model.Jenkins#getTarget() 多做一個基於白名單的 URL 前綴檢查, 這個白名單如下:
```
private static final ImmutableSet<String> ALWAYS_READABLE_PATHS = ImmutableSet.of(
    "/login",
    "/logout",
    "/accessDenied",
    "/adjuncts/",
    "/error",
    "/oops",
    "/signup",
    "/tcpSlaveAgentListener",
    "/federatedLoginService/",
    "/securityRealm",
    "/instance-identity"
);
```
這也代表著一開始可選的入口限制更嚴格選擇更少, 但如果能在一個白名單上的入口找到其他物件參考, 跳到非白名單上的成員豈不可以繞過前述的 URL 前綴限制? 可能有點難理解, 這裡先來一個簡單的範例來解釋 Jenkins 的動態路由機制:

http://jenkin.local/adjuncts/whatever/class/classLoader/resource/index.jsp/content
以上網址會依序執行下列方法
```
jenkins.model.Jenkins.getAdjuncts("whatever") 
.getClass()
.getClassLoader()
.getResource("index.jsp")
.getContent()
```

### Groovy
#### Meta-Programming
Compiletime meta-programming
Runtime meta-programming

### @ASTTest
### @Grab
### @GrabResolve
讓Jenkins可以import任意的jar檔

## LTE Kuon
Haiwei BKS3900LMT
Null/ZUC

Borland
sprintf printf

#若渴
## Censys
ZMAP
Modbus

## Infrastructure leaking of DNS Severs
Github/InfraLeakingURL 

## APT常見打法
* 從Web
* 從VPN
* DDoS強迫下架防禦工具以換取運行效能

常犯錯誤:
1. 以為下線的機器其實還在聯網
2. 

Basic Info
File Behavior

斷網分析 聯網分析

Vmware 從 Guest 打回 Host

Yara Exploit

SandBox,VM
Debugger

Vmmap

Moloch

MITM Proxy

Winhex

TCPViewer/Nirsoft TCPLogView(有log)

## OnePassword
OnePassword 的 WhitePaper
Recovery Group 可以取得所有人的Key
OnePassword能做的只有在server端控管資料授權
但Admin通常為 Recovery Group
亦可將自己嫁入任何群組
並獲得所有資料授權
如此 RcoveryGroup 中的網管 Admin 即可獲得所有人的解密資料

QT 每層框架有好幾層的 cache
