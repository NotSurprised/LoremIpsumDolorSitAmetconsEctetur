# **Windows Subsystem for Linux (WSL) 原理介紹**

https://hackmd.io/u7Js6ZwzQjy9aJiK8GZVIw?both

## 0. 目錄
第一篇：本篇
第二篇：[WSL 環境設定](https://hackmd.io/s/BJByCIUHf)
第三篇：[WSL 補充內容](https://hackmd.io/s/SyL3pzzQm)
第四篇：

## 1. 背景
Windows10 在 2017 秋季創作者 (1709 版) 更新後，將 WSL 正式脫離 Beta 而納入系統中，最初是由微軟與 Canonical 公司合作開發，目標是使純正的  Ubuntu 16.04 "Xenial Xerus" 能下載和解壓到用戶的本地電腦。
WSL 提供了一個微軟開發的 Linux 相容內核介面 (不包含 Linux code)，讓使用者在 Windows 的環境下原生運行 Linux 的 user mode binaries (ELF 格式)。

## 2. 原理
下面為整理了 [Windows Subsystem for Linux Overview](https://blogs.msdn.microsoft.com/wsl/2016/04/22/windows-subsystem-for-linux-overview/) 以及相關文件而成的說明。

### 2.1. Windows NT Subsystem
首先要先介紹一下 Windows NT 的設計，採取 user mode 和 kernel mode 模組化分層，以及 preemtion 和 reentrant 設計，將 Win32、POSIX 和 OS/2 等環境子系統放在 user mode 以簡化 kernel 的實作，如下圖所示。
在早期程式的執行，loader 會先連結對應的子系統，透過子系統 API 和 NTDLL (Windows原生API) 來呼叫 NT syscalls。
之後的版本修改了 POSIX 層以提供 Subsystem for Unix-based Applications (SUA)，透過將其 API 以 NT 架構處理，以減少轉換的部分，同時實現以下功能：
1. Process and signal management
2. Terminal management
3. System service requests and inter process communication

不過這些模組仍依賴程式的 recompiled，需要持續性的功能移植，在維護上是個負擔。
現今雖然這些子系統已經退役了，但基於 NT 架構是允許子系統的存在，WSL 即是將其擴展並改良。
<img src="https://i.imgur.com/XuoDoTo.png" width=70%>

### 2.2. Windows Subsystem for Linux
WSL 是許多模組的組合，允許原生的 Linux ELF64 binaries 執行在 Windows 上，主要由以下組成：
1. User mode session manager service that handles the Linux instance life cycle
2. Pico provider drivers (lxss.sys, lxcore.sys) that emulate a Linux kernel by translating Linux syscalls
3. Pico processes that host the unmodified user mode Linux (e.g. /bin/bash)

先將 user mode 分成 Win32 process (橘色) 以及 pico process (藍色) 兩部分，使用者透過 bash 管理，pico process 實作 Linux 指令，以 pico driver 來做溝通，以下有更詳細的說明。 

<img src="https://i.imgur.com/L5gCHBC.png" width=100%>

### 2.3. LXSS Manager Service
如上圖所示，使用者透過 Windows 的 bash 去實作 Linux 指令，而底下的 manager 會透過 LXCore/Lxss 去建立一個 Linux instance，所以可以同時有多個 bash 去做操作，每個 instance 如同沙盒，是無法干預外部的 NT process。
這些 instances 是特殊的資料結構會記錄所有 LX processes、threads 和 runtime state，當 NT 用戶端關閉後，便會中止其 Linux instance，包含在裡面的所有 processes 也包含 daemons (系統服務)。

### 2.4. Pico Process
Pico process 是基於 Minmal process 的原理，但是對應專屬的 kernel driver，不受限於原本的 NT process 一樣要許多必要資訊，能有效利用剩餘的 user mode address space。
如下圖所示，pico process 裡一開始不會含有任何必要資訊，所以不會由 NT kernel 處理，而是交由其 extension 的 driver 來處理，所以這個 driver 做了許多的安全防護以確保有安全的 pico process。
Pico process 之間的溝通除了透過 file，signal 部分是透過修改 Asynchronous Procedure Call (APC) 來模擬 Linux，當發生 exception 則會先由 NT kernel 攔截再轉交給 driver。
執行時 driver 會分配給 process 一個 Virtual Dynamic Shared Object (VDSO) 以及些許的必要資訊來初始化，VDSO 如同 NTDLL，讓 process 知道如何連結至 kernel，其他資訊像是記憶體分配等都是在 user mode 完成，Linux 的 ELF 即是 load 到 pico process，由 driver 負責處理其產生的 syscalls。

<img src="https://i.imgur.com/zPjbT20.png" width=100%>

參考資料：[Pico Process Overview](https://blogs.msdn.microsoft.com/wsl/2016/05/23/pico-process-overview/)

### 2.5. System Calls
一般 syscall 會根據 OS 和處理器的架構有所區別，但 user mode 和 kernel mode 主要透過 Application Binary Interface (ABI) 來溝通，一個 syscall 會經過以下步驟：
1. Marshall parameters – user mode puts the syscall parameters and number at locations defined by the ABI.
2. Special instruction – user mode uses a special processor instruction to transition to kernel mode for the syscall.
3. Handle the return – after the syscall is serviced, the kernel uses a special processor instruction to return to user mode and user mode checks the return value.

雖然 Linux 和 Windows 都是遵守上述的步驟，但彼此的 ABI 差異導致不相容，主要問題在於並非所有的 syscalls 都是可以直接對應的。像是 Linux 包含 fork、open 和 kill，而 Windows 則有 NtCreateProcess、NtOpenFile 和 NtTerminateProcess。
以檢視資料夾為例，Linux (ls) 和 Window (DIR) 可以在 C 簡化成以下指令：

<img src="https://i.imgur.com/oFZUMNg.png" width=90%>

#### Linux： Result = syscall(__NR_getdents64, Fd, Buffer, sizeof(Buffer));
* 1~4: Marshall parameters：
C 透過 rax 知道 syscall 的 number，再分別把 parameters 放入對應的 registers (rdi, rsi, rdx)。
* 5: Special instruction：
syscall 這個 instruction 讓 CPU ring transition 進入 kernel，並執行 kernel 的 syscall dispatcher 以及建構對應的環境，同時將 user registers 紀錄在 ABI 裡，讓 user 和 kernel 切換時能維持原本的狀態。
* 6: Handle the return：
回復 user registers，將回傳值放入 rax，同時用 special instruction (通常是 sysret 或 iretq) 通知 CPU ring transition 回到 user mode。

#### Windows： Status = NtQueryDirectoryFile(Foo, Bar, Baz);
1~4: ABI 的差異導致不同的 registers (rcx, rdx, r8)。
5: kernel 在此並不會紀錄 volatile registers，在 syscall 之前 compiler 會先把需要的 registers 紀錄下來，省略額外的 instructions。
6: 回傳會以 NTSTATUS 形式，失敗為負，有別於 Linux 會落在特定範圍。

WSL 透過 pico process 和 driver 來處理 Linux syscall，driver 實際上不包含任何 Linux 的 code，而是作為一個 Linux 相容的介面。
如圖所示，當 NT kernel 偵測到來自 pico process 的請求，由於資料結構的不同，會先紀錄 register 並將請求導向至 pico driver，若有相等的 NT API 便會直接使用，以減輕負擔。
至於有些 syscall 像是 fork() 無法直接對應，就會先做一些事前處理，再去呼叫 NT API。
<img src="https://i.imgur.com/ve7WQIB.png" width=70%>
參考資料：[WSL System Calls](https://blogs.msdn.microsoft.com/wsl/2016/06/08/wsl-system-calls/)

### 2.6. File system
Linux 使用 Virtual File System (VFS) 這個虛擬介面，提供各式的檔案系統 (ext4、rfs、FAT 等) 掛載。
VFS 不直接處理檔案格式，而是規定這些處理請求的介面及操作語意，然後交由真實的檔案系統處理，為了管理這些檔案系統，VFS 使用特殊的資料結構 (inode、directory entriy 和 file 等物件) 來記錄。
<img src="https://i.imgur.com/PhCECA8.jpg" width=90%>

在 WSL 中新增了 VFS 組件來模擬 Linux 的檔案系統，程式產生的 syscall 會先進到 syscall layer，但一般碰到檔案處理相關的 syscall 會直接交由 VFS 處理。VFS 先從 directory entry cache 檢查，若不在就由底下的 file sysyem plugins 來新建 inode，VFS 透過 inode 來建立 file 物件並回傳 file descriptor。
<img src="https://i.imgur.com/9wWvguJ.png" width=100%>
如上圖所示，WSL 的 VFS 提供了不少 file system plugins，VolFs 和 DrvFs 用來表示 disk file，而 TmpFs 用來表示 in-memory file，剩下的則是表示 pseudo file。
WSL 主要用 VolFs 和 DrvFs 分別實現以下需求：
1. Provide an environment that supports the full fidelity of Linux file systems
2. Allow interoperability with drives and files in Windows

需要注意的是這些 plugins 仍是基於 NTFS 去實作的。

#### VolFs：
/root 和 /home 分別掛載在 %LocalAppData%\lxss 下，所以當移除 WSL時，root 和 home 的資料不會馬上被移除，以便重新安裝。
這些 mount points 是在 user 的資料夾下，所以不同的 user 的 WSL 環境以及 Linux root 權限與檔案都是 local 的。
Case sensitivity 在 NTFS 已經支援，所以單純透過 Object Manager，Linux 支援的檔名像 ":" 等則用跳脫字元處理。
Linux 在 unlinking 和 renaming 採取不一樣的機制，Windows 不允許刪除在處理中的檔案，所以 WSL 會在檔案刪除前，先將 unlinked file 重新命名成隱藏的暫存資料夾。
由於 Windows 沒有 inode 的機制，所以這些額外資訊會存在 NTFS Extended Attributes：
* Mode: this includes the file type (regular, symlink, FIFO, etc.) and the permission bits for the file.
* Owner: the user ID and group ID of the Linux user and group that own the file.
* Device ID: for device files, the device major and minor number of the device. Note that WSL currently does not allow users to create device files on VolFs.
* File times: the file accessed, modified and changed times on Linux use a different format and granularity than on Windows, so these are also stored in the EAs.

其他資訊 (像 inode number 或 file size 等)，可以直接從 NTFS 獲取。
如果由 Windows 環境來修改這些檔案，因為會缺少必要的 EA，之後是無法被 VolFs 處理的。

#### DrvFs：
為了支援與原 Windows 的檔案互動，WSL 會自動掛載所有支援的檔案系統至 /mnt 下 (像 /mnt/c 等)，但目前只支援 NTFS 和 ReFS (Resilient File System)。
由於 Windows 使用較複雜的 Access Control Lists (ACLs) 來處理檔案使用權限，在 DrvFs 存取檔案是根據一開始使用者開啟 bash 時的權限決定，檢查該檔案是否可以被此 Windows 用戶使用，所以在此不支援 chmod 或 chown 等 Linux 檔案權限更動指令。
雖然 NTFS 支援 symbolic links ，但基於 NT 是透過系統管理員的權限建立，以及 WSL 可能會指向 /proc 等位置，所以不能像 VolFs 透過 EA，而是使用新的格式去 reparse point，且只能被 WSL 使用。
不同於 VolFs，DrvFs 不會儲存任何額外的檔案資訊，所有都是從 NTFS 取得，所以取消了 directory entry caching，以確保檔案的資訊更動都是同步的。
刪除檔案也遵循 Windows 機制，處理中的檔案是無法被 DrvFs 刪除。

#### 小結：
VolFs 提供了 Linux 的檔案環境，而 DrvFs 提供了便捷的管道存取 Windows 的檔案，只需注意兩個檔案系統的權限並非通用，實際上 Windows 這部分的權限影響比較大。同時由於檔案儲存的方式不同，在 Windows 修改 WSL 裡的 VolFs 檔案是無意義的。

參考資料：[WSL File System](https://blogs.msdn.microsoft.com/wsl/2016/06/15/wsl-file-system-support/)
