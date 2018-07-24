# WinDBG debug Crash Memory

Go to Control Panel > System and Security > System > Advanced system settings. Under Performance, click Settings. On the Advanced tab, under Virtual memory, click Change.

![](https://i.imgur.com/mIeHnOv.png)

You can find the `.dmp` file after you mechine got BSOD under `C:\Windows\` folder.

Then copy `myDriver.dbp` from your compiling output into `c:\MyRegularSymbols`. Just name `MyRegularSymbols` what you like.

Open Windbg, click `Symbol File Path` in `File` tab.

![](https://i.imgur.com/7GLtiPo.png)

Type `srv*c:\MyServerSymbols*https://msdl.microsoft.com/download/symbols` in GUI windows.

![](https://i.imgur.com/KVlcqub.png)

Then `Open Crash Dump`.

![](https://i.imgur.com/YkTLsVh.png)

You can also type `.sympath c:\MyRegularSymbols;srv*c:\MyServerSymbols*https://msdl.microsoft.com/download/symbols` command in windbg commandline.

![](https://i.imgur.com/1pCjd0L.png)

After you confirm Symbols import correctly, type `!analyze -v` to analyze the crash reason.