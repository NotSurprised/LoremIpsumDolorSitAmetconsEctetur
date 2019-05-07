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
* full-virtualization 則相反，無須修改 Guest OS 的 kernel，期將自己作為一個大型翻譯機，對於硬體層來說唯一的 OS，所有的 GuestOS 行為皆尤其翻譯轉述。

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

## Disco: A Virtual Machine Monitor

## Related Work

## Conclusions

## Reminder

>**Better read by yourself**, not for fair, don't cheat, you will really hurting yourself and stuck youself in a area you don't like it. 
[name=Brian Harvey]



