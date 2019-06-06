# TW Beck No.2

## Webkit fuzzing for fun - Cheol Ung Lee (chpie) / GrayLab

exsi-unlocker
RaspberryPi cluster
### Open-source fuzzers
* General
  * OSS-Fuzz
* Browser
  * Domato
  * Jsfunfuzz
  
### For HTML rendering:
```
# xvfb-run ./minibrowser
```

### To minimize corpse
Github: Mozilla lithium

### Kubernetes
```
# kubectl get node
# kubectl get pod
# kubectl edit deloyment
# kubectl get service
# kubectl describe service
# kubevtl delete pod --all
# kubectl run fuzz
```

### K3s + Domato vanilla
https://k3s.org

## MITRE ATT&CK: What You Need to Know - MingYen Hsieh
原來是 EDR 的部分啊
MITRE 是美國贊助組織
CVE 為其子計畫
## phyramid of pain
Hash 最不痛不癢
IP 普通 nslook 或是 nmap domain 就可以 
Domain 有點麻煩 需要重新OSINT
Tool 需要改寫Tool 換CVE 改PoC 等等Exploit database
TTS 痛點 此為攻擊流程 能抓到對攻擊者影響最大 需要變更習慣改變流程

### TID
TID 可以統一對行為的描述語言，讓資訊安全的專有名詞更加一致，提升溝通聯防能力
TID 越接近 T1000 代表越明顯是惡意的行為 數字越大越接近單存描述 不參雜評斷的行為

### UI更近MITRE ATT&CK:
* JOE Sandbox Cloud
* Palo alto Playbook

### Internal Red Team vs Blue Team Drill
可使用TID來列表描述攻擊並由防守方確認防禦結果

### Red Team Tools
* MITRE - Caldaera
* Red Canary - Atomic Red Team
* Endgame - Red Team Automation(RTA)
* Uber - Metta

### Summerizing/Planing Tool
GitHub : nshalabi ATTACK Tools
Commercial : Tableau page

### Use MITRE Att&CK Evaluate Product
Round 1: 
* Red team vs Blue team
* White team judge
Round 2:
* None 沒有
* general 可疑
* technic 具體描述可疑與可能與原因(TID)
* MSSP 需要手動處理
* Correlate 連結整個過程的
* Delay 沒辦法連接出整個過程
* Host Intergration 抓不到 有存log 只能事後整理歸納

Evalutions: there is no score
但是 Forrester 提供算分數的工具與給分標準

## The Distance Betweeen Us and Industrial Control System Security - Mars Cheng

### ICS Function
控制 畫面 監視

### purdue Enterprise Reference Architecture
#### IT:
* Layer 5 Network
* Layer 4 server DMZ
#### OT:
* Layer 3 manufacturing operation control HMI
* Layer 2 router switch
* Layer 1 plc

### SCADA vs DCS
SCADA 跨區域 跨廠區 地理區域範圍較大
DCS 分散式控制系統 通常視同個廠區 但是分散控制

### PLC
邏輯時間計算演算
內部結構圖

#### PLC 架構
CPU
 <->程式記憶體
 <->系統記憶體
 <->元件記憶體
 <->資料記憶體  (最常被攻擊的位置)

2010 Stuxnet伊朗
2014 德國煉鋼 日本文殊
2015 烏克蘭核電廠
2018 臺機電

### ICD-CERT
會公告漏洞廠牌弱點
MOXA 台灣之光

DHS申請就可以取得所有攻擊報告

### CyberX Report
57% AV 無法更新病毒碼
53% 還使用 WinXP

## Attack Flow 
Internet->Intranet->Firewall->OT

### RF Attack Vector
GhostTunnel for WIFI

### ICS Protocols
至少上百種
可查到的公開資料算少
各家不公開自製土炮protocols
Fieldbus wireless 有線無線 RS232傳輸等等

### Modbus TCP
Modbus 大部分結構都如 TCP 所示
主要重點操作上是 Function code
而 Function code
Coils 其實就是 Bool true/false

### Attack Target
PLC 或是 HMI 都可以 端看哪個防護比較好
HMI 可以 fake PLC 狀態 讓操作人員自己下錯誤指令
PLC 如果可以直接收 fake packet 的 function code 就可以 success

### Ettetcap
執行 Arp Spoofing
使用 Ettetcap Filter 進行 command injection

### Schneider
FC-90 本意是在 PLC 失效時可以關掉 PLC，卻變成可以在 PLC 正常時強制關閉它
Unity Loader 12.0