Disco
===
###### tags: `PaperNote`

## Outline
1. My Review
2. Abstract
3. Introduction
4. Problem Description
5. A Return to Virtual Machine Monitor
6. Disco: A Virtual Machine Monitor
7. Related Work
8. Conclusions

## My Review
Disco 原意用作於模擬新的 Spec 環境供開發者開發相對應的新硬體架構所能運行的軟體。因此，Disco 使用軟體中介來模擬新硬體架構來開發對其相容的軟體產品。

作者之一，Rosenblum 後為 VMware 的創始人之一，足見 Disco 對 VM 發展影響之深。

這裡要提一下 para-virtualization 跟 full-virtualization 的差異。

* para-virtualization，para 意即殘缺，即無法完美兼容 GuestOS 的特權指令或是插斷處理，而需要修改變造 OS kerenel 的虛擬化系統
* full-virtualization 則相反，無須修改 Guest OS 的 kernel，其將自己作為一個大型翻譯機，對於硬體層來說唯一的 OS，所有的 GuestOS 行為皆尤其翻譯轉述。

## Abstract

此處描述了此篇論文提供了一種可以擴展 OS 功能並大量共享記憶體以及 multiprocessors 的系統，並且毋需大量人力投入並修改。

並且，該系統解決了舊型(關於模擬環境用於開發的環境)解決方案經常遇到的 overhead 問題，如: 此類系統在處理 non-uniform memory access(NUMA)硬體設計時，面對不同的 program code 跟 file system buffer caache 的 memory access overhead 問題。

## Introduction
此論文發表背景，大型運算電腦已從實驗環境邁向商用，在此情況下，無論軟硬體皆須面對商用客製化導向造成的多變問題。

而應具有較大變動彈性的 OS 的因設計不良而無法跟上大型運算電腦的硬體擴展需求並有效利用大量擴展而來的資源而導致擴展硬體的潛力被低估。

所以 Disco 做了一個中介層能有效利用擴展的資源，將對應的硬體資源分配給有需求的 OS。

此系統主要針對 Standford 的大型運算電腦--Flask做中介資源分配。Flask是一個 cache coherent NUMA (ccNUMA) 類型的 MIPS 電腦。

Disco 聲稱其基本上解決了 overhead 的問題並有效的分配資源。

## Problem Description
每當硬體擴展或是變更架構時，都會造成軟體的劇烈震盪，軟體需要大量的修改才能應對硬體的更迭。這裡舉了一些過往研究檢索，並指稱他們都需要大量的開發者人力投入才能完成 OS 對新硬體的兼容。(這裡的 Hive 跟 Apache 的 Hive 沒啥關係) 而這也造成的過於長時期的開發週期使的軟體跟不上硬體更迭的速度，使的硬體性能始終無法有效發揮。
另外 ccNUMA 有其加快核心運算的好處，無須從頭檢索(多設計為就近檢索)，但當遇到例外時的處理速度仍舊是個問題。當預算更加龐大複雜的大型運算需求時， ccNUMA 的問題到設計不良的軟體層時越發明顯，這造就硬體的革新的效果並不顯著。
一個有效發揮新硬體架構的軟體層，才能讓新的硬體架構在大型運算市場上體現價值。


## A Return to Virtual Machine Monitor
首先闡述關此方法提供的能使多虛擬機器同時存在於同個 multiprocessor 上，並同時攻克關於須達到此目標時必然面對的 NUMA 問題。

NUMA 即為因應 Multiprocessor 而提出的分散式記憶體存取架構，有許多種不同的設計，總歸是藉由分散存取來達到消除集中分配時帶來的瓶頸。此方法供單一處理器可以就近取得快取記憶體的資料，但是在存取較遠的記憶體時會顯著較慢。

此論文提出之方法雖然近似於 Cluster ，但其實仍由 VMM 來進行資源分配。在實作此種集中分配處理單元不可避免的會遇上需要處理單一 VM 的需求超出當時配與的資源之問題 ── 當一 VM 內之程序所需資源超過其當初設置之極限值，在面對此種問題下有兩種解決方式:
* 建立跨 VM 共用記憶體的機制，將其他 VM 未用到之記憶體提供與有需求之 VM
* 使用可自行針對內部運行之程序調整配置之高度可客製化 OS

另外，這邊提出關於 Disco 設計上對於同時處理多種不同OS在同一機器上時，可只需提供 VMM 以及分散式系統的溝通協定所需之資源使用量設置，在此間互隔離並易於設置的架構下處理硬體的 faults 時也藉由將其設計成 cellular 架構分割單元後由各 VM 自行處理，以避免 faults 傳播至整個系統。

針對 NUMA 的部分，藉由 VMM (Virtual Machine Monitor) 改變 VM 所見之 memory page ，使其近似於 UMA。(所以此處並無法確認實際上是否有完成對 NUMA 獲取較遠記憶體資料的優化，只是提供 UMA 形式來兼容 non-NUMA aware 的 OS，具體細節後述)

### Challenge Facing Virtual Machine

詳細描述關於 VM 所需面對的問題:
* overhead
* resource management
* communication

#### overhead
1. additional exception
2. instruction exception
3. memory needed

#### resource management
因為每個 VM 內部資源使用量其實並不透明， VMM 僅能估出大概，如此的資訊缺乏以及不同步造就 VMM 的資源分配策略無法取得最優解。此將導致真正重要的運算無法取的運算資源，因為資源正被分配給不重要的運算。

#### communication
將所有 VM 完全區分獨立將導致溝通以及共享的實現困難。例如共享資料夾中一檔案正被存取，其他 VM 將無法使用該檔案。

但即使有上述的問題， Disco 仍可使用當時 OS 的優點並利用在 VMM 中，這有效降低了上述的 VM 問題。





