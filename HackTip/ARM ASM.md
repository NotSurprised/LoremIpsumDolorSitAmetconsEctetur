# **ARM ASM**
###### tags: `else` `todo`
">payload
Html validator
mmap ART JIT interpreter

◆ r13 - 指向當前棧頂,相當於x86的esp,這個東西在彙編指令中要用sp 表示
◆ r14 - 稱作鏈接寄存器,指向函數的返回地址。用lr表示,這和x86將返回地址保存在棧中是不同的
◆ r15 - 類似於x86的eip,其值等於當前正在執行的指令的地址+8(因為在取址和執行之間多了一個譯碼的階段),這個用pc表示

{S} [Rd], [Rn], [Rm]
其中：

{S} —— 加上這個後綴的指令會更新cpsr 寄存器
[Rd] —— 目的寄存器
[Rn]/[Rm] —— 源寄存器
add r0, r1, #1
就會把r1+1的結果存放到r0中。