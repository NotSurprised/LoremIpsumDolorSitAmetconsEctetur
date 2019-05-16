# ICS

## ICS架構
* Lv5 企業網路、IT系統、對外網路、FW、IDS、IPS
* Lv4 分流處理、內部系統、網管控制台、OT系統
* DMZ WAF
* Lv3 DCS子系統
* Lv2 HMI
* Lv1 PLC、實體設備

Lv5 & Lv4 為IT層
DMZ為灰色地帶 會上許多安全服務與篩選工具
Lv3 Lv2 Lv1為號稱實體隔離的現場內網場內系統
但是實體隔離其實並不該是連不上外網就可以，應適時體現完全沒連上外網
許多廠區應實體隔離的環境為了方便遠端操作與溝通，仍會掛上VPN進行操控
此連線及未入侵提供了通道

## SCADA 系統
資料採集與監控系統 (多為遠端)
現場設備與HMI為整合

## DCS系統
分散式控制系統
現場設備與HMI整合

HMI人機介面 - FieldDevice現場設備 - PLC控制器(siemens S7)

## PLC
寫PLC的幾個主要programming method:
* c++
* ladder logic
* structure text
* function block diagram

主要攻擊在PLC的資料記憶體，資料記憶體主要儲存PLC的機台各個控制數值

## HMI
最多功能最常見的攻擊目標

## IT v.s. OT
OT沒再裝防毒軟體
OT通訊協定上百種
OT中斷影響巨大
OT強調可用性

## OT攻擊事件
Stuxnet伊朗核電廠
Mouji日本文殊核電廠
德國煉鋼廠
烏克蘭電廠
Trisis中東石油工廠
TSMC台積電產線

## 攻擊計量from ICS-CERT
```
   /
  /
 /
/
```
cyberx-labs.com
https://cyberx-labs.com/resources/risk-report-2019/#donwload-form
40%的ICS產區與網路相連
57%防毒不更新 剩下沒裝

53%使用停止支援的windows OS

## Server Attack

* SMB
    * Port:445 MS17-010 (用來當作暫存資料的block)
* SSH
    * Port:22
* FTP
    * Port:21
* RDP
* Database Service

## RF hacking tool
### WiFi
GhostTunnel V1 V2 (外部廠商自帶設備進入，即使實體線連接仍可藉由此種方式成為跳板)

hackRF

## PLC 介面 
* I2C 
* JTAG 
* UART 
* SPI

Siemens Simatic S7

## OT環境正朝IT環改變
在OT跟不上時代有經常存有漏洞的情況下
為了更有效率及工業4.0等因素
OT漸漸使用IT的protocol、環境、ethernet/IP
更加hacker-friendly

## OPC Packet Diagram

## OPC-UA
OPC Server 為一強PLC、是個分散運算中的Master、控制複數Slaves、並接受複數、最後最重要為此種分散運算式的控制工具是windows-base所以極易上手

## Modbus Communication Protocol

MTCP/IP ADU

PLC有時不可信任，會寫作記憶體位置(what?)
OT對接PLC時常有漏封包的情形(what?)

講求時效性、不驗證不保護、微秒都是差距

設備編號各廠不同

### 設備編號掃描
* namp:default 1000 port 裡，沒有 502 port，須加註開啟
* metasploit:scanner scada modbus_findunitid

### Function code 識別
* Python:scapy
* Fuzzing

### MITM
再現有連線狀況下，Hacker 最常使用 MITM 取代 HMI 跟 PLC 之間的 modbus TCP

### ARP Spoofing
沒有通訊就自己建通訊，因為內部網路為了許多持續穩定並快速的考量，並沒有做router 或 switch 的基本防護篩檢
可使用 ethercap
Modbus通訊系統可用 wireshark 擷取分析
使用 ethercap filter 做 command injection

Schneider FC-90 攻擊工具

Siemens漏洞最多，不只PLC還有HMI

工控設備通常沒有帳密管控，基本上也不登出，所以也沒人知道帳密，通常是預設值

基本上掛VPN是全廠區產線全掛，所以 VPN server 掛了全掛









