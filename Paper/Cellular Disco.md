Cellular Disco
===
###### tags: `PaperNote`

## Outline

1. My Review
2. Abstract
3. Introduction
4. The Cellular Disco architecture
5. The Cellular Disco Prototype
6. Memory management
7. Hardware fault recovery
8. Comparison to other approaches
9. Related Work
10. Conclusions

## My Review
比起先前的 Disco 著重於模擬出可供硬體環境項未開發完成下模擬環境用於軟體開發，Cellular Disco 更著重於有效分配大型共享記憶體的 multiprocessor 機器資源，將其塑形成 Cluster 並以此為目標支援容錯與異質，且優化 Disco 版本的擴展瓶頸。
Cellular Disco 的 cellular 最小單位為 VM，並以此形成 cluster。
此篇當中所述的 fault containment，分為來自 hardware 沒有嚴重傷害的關於錯失或是叉斷的 fault，另外是因運行 
Guest 而影響到 VMM 的嚴重且因 VMM 隔離不當可能導致所有 VM 當機停止運作的 fault，最後是來自 hardware 本身問題導致硬體不可使用的 hardware 嚴重致命 fault。處理這種 fault 問題建立於所有資源是透過 VMM 分配的，如 VMM 無法區分發生 fault 的資源並轉傳給其他 VM 使用將導致連鎖崩潰。
此篇許多部份比起前座更加詳細地闡述其在節點與邊界區隔的機制，用於應付上述如無隔離設計會導致所有 VM 死機的 fault，而在此隔離政策下，資源的分配運用將是其極大的課題，如何跨過隔離邊界共享資源並偵測收容 fault 以保證其上流通的資源都是良性安全可運行的。

## Abstract
概論闡述了與 Disco 近乎一致的問題，即關於現行商用系統仍無法有效處理關於"大型"、"記憶體共享"、"multiprocessor"機器的效能最佳化利用之問題。主要導致此問題的主要原因為根據需求改造 operating system 過於複雜且消耗大量成本。而此論文前作 Disco 雖解決此一問題，可有效降低作業系統的適應開發成本，但仍有期待優化之問題。
Cellular Disco 在消耗極低的開發成本下重構作業系統並使"大型共享記憶體多處理器機器"變為一虛擬 cluster 並支援 Disco 並無完整規劃支援的 fault containment 以及 heterogeneity 且避免後續擴展之瓶頸。
此處， Cellular Disco 稱在此優化下，其仍可有效提供資源並讓使用者在宣告資源使用量時超支資源 (此處因實驗性質的超支，所以通篇以可達 100% 的資源使用量，但實務上應不可超過常態使用資源的 50%、並另有足夠之備用資源以確保系統穩定運作)。
此篇論文著重闡述如何在有限資訊下進行有效的資源分配並同時提供全域優良效能與容錯。
另注意，此論文系統架設於 32-processor 的 SGI Origin 2000 System，當時的 OS 接只能達到 10% 的資源使用率。

## Introduction
指出當時之商用作業系統皆無法有效利用多處理器，最多達十幾個處理器的使用量已是頂尖了。此外，當時的記憶體分配演算法也無法有效考慮並處理 NUMA 架構的遠距離記憶題存取 latencies。其中最大原因在於當時資源分配 policy 在大量資源的情況下會有低效的使用分配。最後施 能影響了整個系統並使其上所有運行程式崩毀需要整台機器重啟。當時的解決方辦有用實體硬體隔離或是重新設計作業系統。其中，硬體隔離限制了該系統利用分配資源的彈性，而重新設計作業系統又需要大量成本消耗。所以當時最好的解決方案即為本論文前作 Disco(其實近乎重新設計一種作業系統，一種只做資源分配mapping的作業系統，可以將此作業系統看做 Disco 將其他作業系統模組移由 UserMode 的程式──即GuestOS來完成)，但是 Disco 有其問題，例如不支援 fault containment(hardware) 以及資源分配的機制規劃，使其無法與通時期的其他硬體分割或是客製化設計的方法做比較。而 Cellular Disco 即是 Disco 的加強版本，主要支持前述缺失的 hardware fault containment 與 resource management 在可擴展式硬體機制下。

### Fault containment
Disco 的 VMM 本身是支援 software 的 fault containment，但是關於 hardware 的 fault containment 並沒有處理，而在"大型共享記憶體多處理器機器"上，這卻比起 software fault containment 更需要妥善的解決方案。所以 Cellular Disco 選擇將自身構築為多個獨立單位並同時用為 fault containment 的隔離單位。這將使 hardware failures 影響侷限在單一隔離單位內。(所以很像 cluster 的概念)
>此處它比較此方法較 Hive 消耗成本為少，而此結果成立於 Cellular Disco 的 Code 是正確無誤的。而此論文並不想完整的偵錯，他假設 5W 行的 C 跟組語在成功運行的狀況下應該算很好的偵錯了(啥?)

### Resource management
為了更有效的運用大量的資源，Cellular Disco 允許 VMs 宣告超出資源總量的資源，在此狀況下需要優良的資源調度避免過載，所以此論文假設用量尖峰不會超出資源總量(啥?)

上述兩個主要機制在 Resource Management 與 Fsult Containment 上是有衝突需要取捨的，因為針對硬體的 Fault Containment 需要追邱盡量將一個 VM 所處的隔離單位硬體資源降至最小，而可擴展式的 Resource Management 追求硬體資源充足下盡量擴展 VM 的可獲取資源量來最大化硬體資源利用。

此外，在此結構下 Cellular Disco 也支持大型應用程式利用記憶體共享的方式進行跨 VM 的運算(可視為分散式運算的雛形)。

## The Cellular Disco architecture
Cellular Disco 相較於此前的類似系統有以下創新:
1. 支持 Hardware 的 Fault Containment
2. 可擴展式的 Resource Management 
3. 為應對 Fault Containment 而設計的策略與機制
4. 支持大型著重記憶體使用的應用程式運算

### Overview of hardware virtualization
為了完全模擬讓運行 Cellular Disco 上的 OS 無法察覺 Cellular Disco 的存在，Celluar Disco 需要虛擬出各種運行硬體要件，包括 CPU。所以在 Virtual CPU (VCPU)方面，因為虛擬的原因 Cellular Disco 就需要擷取特權指令交由真正的 CPU 來幫助處理本該由 VCPU 處理的特權指令，例如 I/O 請求。但如何分辨 VM 是否執行特權指令是 Cellular Disco 無法做到的，這依賴於 CPU 架構本身的支援，比起 x86 的完美虛擬兼容支援， MIPS 提供三種分層 user mode、supervisor mode、kernel mode。特權指令屬於 kernel mode 會由 MIPS CPU 退回 Cellular Disco 尤其檢查權限，然後才將請邱發送給對應的硬體執行。
為了虛擬記憶體頁面給運行在 Cellular Disco 上的 VM， Cellular Disco 使用 pmap 來建立一個對應原本 Host 記憶體頁面的 mapping page。但是在切換 CPU 運算 VM 需求時，重新載入這個對應 VM 的 pmap 到 MIPS TLB 快取上十分耗時，CPU 會查找 TLB，VMM 會直接轉送查找給 VM，而 VM TLB 所記錄的卻是所存的虛擬記憶體位址，為了取得實際記憶體位置，VM需要拿虛擬位址給 VMM 查找已返回實際位址。為了降低這個問題耗時，Cellular Disco 為每個對應 VM 運行的 VCPU 都建立另一個 1024 接口的 TLB (L2TLB)，而這 L2TLB 所紀錄位址則無需查找 mapping 表，直接對應實際記憶體位置，這樣 VCPU 切到實際對應的 CPU 時，只要將 MIPS TLB 導向 L2TLB 即可。

### Support for hardware fault containment
當系統越大越複雜時，可靠度將是極大的考量標的。當系統越大時，完全崩壞到復原有極大的成本消耗。所以此處為了避免完全系統崩壞，有效的去收容導致崩壞的錯誤將是必須的。
在 software fault containment 上(即 VM 內之 OS 運行產生的 fault)，Cellular Disco 本身直覺將其交付予 VM，這會由OS本身設計的機制收容處理，即使屬於其無法處理的 fault，受到影響並崩潰的也只是其所屬的 VM。
而在 hardware fault containment 中，Cellular Disco 設計建立一個分隔機制，如果有此類 fault 產生也只會影響到該隔離區內的 VM，其他隔離區內的機器將不受影響地繼續運行。
針對可靠度有個要點即是越簡約越輕量的邏輯系統，則可靠度越高。所以此處 Cellular Disco 在在強調其本身 VMM 的精簡，基於這個前提可以想對於類似 Hive 系統溝通所使用的 protocol 使用更加精簡的 protocol 來相互溝通並更新資料結構。在使用此種較精簡的協定溝通後，需要另外考量的優化點即為當一 VM 影響多個 cell(隔離單位)，例如某個需要時常更新 VMM 記憶體對應的 address table。即使 Cellular Disco 可以使用共享記憶體，他們也無法直接接觸隔離圈外的記憶體單元。因此 Cellular Disco 另外設計了兩種溝通機制分別為 Fast inter-processor RPC(Remote Procedure Call)與 message， RPC無須詳述，主要利用其作用於多processor下的運用，而 Message 則是借用 CPU 上之 registry 在替換 VCPU 使用時不做清空，讓下個使用的 VCPU 接收，從而達到傳遞訊息的效果。此方法因為 VCPU 轉換交替由 VMM 控制而可行。


## The Cellular Disco Prototype

## Memory management

## Hardware fault recovery

## Comparison to other approaches

## Related work

## conlcusions

## Murmur

>**Better read by yourself**, not for fair, don't cheat, you will really hurting yourself and stuck youself in a area you don't like it. 
[name=Brian Harvey]