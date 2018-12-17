# HITCON Defense 2018

1. 確認**網路拓撲**
    ```shell
    nmap -sP 10.0.1.0/255
    nmap -sS 10.0.1.0/255
    sudo nmap -Pn 10.0.1.31 -sV -sC -O -oX 10.0.1.31.txt -vv
    ```
1. 畫出**架構圖**
    ![](https://i.imgur.com/ZxvFOWZ.png)

1. 確認每台機器的功能、型號、**版本**。
    ![](https://i.imgur.com/bZKE180.png)

3. 確認交接文件內帳密正確性，**誤植、同型字體、誤觸冗字** 等等。
4. 如有機器無遠端登入之帳號密碼，亦不具備影像輸出或USB連接，尋找 **Serial Port**
    例如: 現場有一台 DMZ 裡的 IPS 沒有帳密可登入，要走 RS232 的 RJ45 接口，上網查找機器文件有無提供頻率用以對接下指令。
1. 在做任何登入以外的操作前先重製**備份**機器檔案或映像檔。
    ERP Server 裡有一個 binary 叫 bof，運作後因為被攻擊開了許多服務在 8787 port，根據 history 可見使用 scp 下載binary 後用 root 執行。相當有惡意的味道，在沒進行確認 ERP 服務對應 Binary 下停止執行並刪除會導致沒有 ERP 原檔可供重啟服務。
3. 如無法再製虛擬機則**快照**。
    下午比賽時發生 Web Nginx設置有問題而成為幣像後門，被入侵下one line death導致映像檔崩潰無法重啟，需備份網頁程式碼或是快照 VM 才能進行補救。
5. 上各服務版本**更新**。
    phpmyadmin 有 default 的 root 登入帳號密碼，需更新或更換密碼。
7. 尋找服務登入權限**帳密風險**
    例如: 弱密碼。
3. 尋找機器內**異常服務**，
    例如: 具 DGAs 連線行為之服務。
5. 檢查**私有雲登入提取 PaaS** 之帳號有無未刪除之離職人員。
    比賽有現任人員跟**離職人員**表單(離職人員不保證完整)，需比對權限控管具訪問權限之名單。
7. 檢查私有雲提供之機器**有無後門**。
    或是檢查工作排程管理員，開機自啟動的服務 等等。
    在比賽下午，當DDoS攻擊一波接一波時，每隊所有共十台 Windows 7 VM 同時啟動 Windows Update。
    Windows 機器看是否建立 Win server 管理更新的 Policy 或是啟用 APPlock ，以避免全體更新造成私有雲當機，或是後門擴散殭屍。
9. 確認無線網路 AP 機器型號與**管理面板位置**，可登入與否？
    本次比賽的 Guest Wifi 似乎不算分，在主辦提供的登入帳密無法登入，且 Guest Wifi 接於外網(介於賽場內網的每隊內網中間)，用於從隊伍所在內網外查驗各服務運作情況。
11. 檢查無線網路黑白名單與連線是否**需額外登入介面**，介面有無爆破漏洞。
12. 對接 APS、DMZ、IPS 確認**各防禦模組啟用之模板細節**。
    Arbor APS、Imperva WAF、Cisco Firepower、Cisco Switch、Dell Server、VMware vSphere、PulseSecure SSLVPN、AWS nonVPN service / VPN token service。
    ![](https://i.imgur.com/H1MJSVf.jpg)
    ![](https://i.imgur.com/9ksLk1l.jpg)
    ![](https://i.imgur.com/Oyw4RZN.jpg)

13. 對應攻擊記錄封包並搭配後端內部**分析確認攻擊種類**。
    擬定對策，使用服務更新修補漏洞或使用防禦系統啟用攻擊類型防禦並設定判斷閥值。
    例如運用類似 HTTP Syc Flood 的攻擊，在交握成功後始終不切斷連線持續占用，並不斷另外建立新的連線，須設定等待的 Threshold 或可由 Arbor APS 防禦系統設定閥值。
15. 應可建立服務子機並使用轉送機制**分流**使用者流量。
    三年前我剛學資安，聽說1TB的DDoS很可怕，是世界奇觀。現場流量到底怎麼弄到 800MB DDoS 的，太浮誇了吧?
16. 所有現場實體機器上防毒，裝 USB 檢測驅動，可以的話，**不用的電腦拔網路**線，反正服務down也不計分。
    現場太多參觀者跟工作人員還有廠商，甚至中途因為可以連外網還有人推銷裝 Agent 扣 500 分的防護產品服務。
    結果大會趁亂派人插 BadUSB。
    ![](https://i.imgur.com/qzooKVW.jpg)

19. 太緊湊沒**好好分工**，導致 PulseSecure SSLVPN、Imperva WAF 跟 Cisco Firepower 都沒玩到，有點可惜。