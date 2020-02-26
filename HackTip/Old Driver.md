# Old Driver
###### tags: `Research`
Microsoft Console Debugger (CDB) and Microsoft NT Symbolic Debugger (NTSD)
Kernel Debugger(kd), Local Kernel Debugger(lkd)

fltMgr.sys
ntfs.sys

https://docs.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/
https://technet.microsoft.com/zh-tw/ff567122(v=vs.71)
https://zh.wikipedia.org/wiki/Windows_Driver_Model
http://jumpdollar.blogspot.com/2014/09/windbg-object-command-its-usage.html

![](https://i.imgur.com/3J5fcwV.png)
![](https://i.imgur.com/Gg4J7Pj.png)
![](https://i.imgur.com/Ws3mPvs.png)
![](https://i.imgur.com/IP95GNU.png)
![](https://i.imgur.com/1OVgQ3d.png)
![](https://i.imgur.com/fBCalnn.png)

![](https://i.imgur.com/V6Jxd4r.png)
![](https://i.imgur.com/wG4XqTP.png)

https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/
https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-

Add to symbolpath
`.sympath srv*c:\Symbols*http://msdl.microsoft.com/download/symbols;`

**lm**
> show all listed loaded modules

**!object \Device**
> get all device attached to system

**!devobj {DeviceObject}**
> get device path and object list address

**!object \Driver**
> get all driver loaded in system (some driver use notification to runtime load, they may not show but in unloaded list)

**!drvobj {DriverObject}**
> get driver path and object list address

**!drvobj {DriverObjectListSignature}**
> get device which driver attached

**!drvobj {DriverObjectPath} 7**
> get the DriverEntry

![](https://i.imgur.com/0WAU6CJ.png)
![](https://i.imgur.com/qxy6cb9.png)
![](https://i.imgur.com/S3tiH7l.png)

**!process 0 0**
> show current running process

**!process {ProcessSignature}**
> show thread and IRP list(not done yet)

![](https://i.imgur.com/BanPMPD.png)
![](https://i.imgur.com/aYBTMYE.png)

**!irpfind**
> show undone irp

**!irp {IrpSignature}**
> show irp info (major function, minor function)

**!thread**
> show owner image and callstack

![](https://i.imgur.com/0GmoqIg.png)
![](https://i.imgur.com/RgffTqi.png)
![](https://i.imgur.com/uScjeOB.png)

**!process 0 7 notmyfault64.exe**
> show thread and IRP list to find myfault

**!irp {IrpSignature}**
> show irp and driver which handle it

![](https://i.imgur.com/Ql5WBGG.png)
![](https://i.imgur.com/MojBz4N.png)

Sometime !fltkd will be broken, reload `fltmgr.sys`
**!sym noisy**
**.reload fltmgr.sys**
**!fltkd.filters**
> show all filters
https://docs.microsoft.com/en-us/windows-hardware/drivers/ifs/development-and-testing-tools
http://fsfilters.blogspot.com/2011/12/debugging-minifilters-using-fltkdfilter.html

![](https://i.imgur.com/FWq5SwJ.png)

**!fltkd.filter {DriverSignature}**
> show filter detail
![](https://i.imgur.com/5Czcreb.png)


https://ss64.com/nt/fltmc.html

http://blogs.360.cn/post/dump-analyze-1-debug-flag-abuse-of-wdf01000-sys-bsod.html

**!object \Filesystem**
**!object {FiltersSignature}**
**dt _DRIVER_OBJECT {DriverSignature}**
**dqs {DriverSignature}+0x070**


