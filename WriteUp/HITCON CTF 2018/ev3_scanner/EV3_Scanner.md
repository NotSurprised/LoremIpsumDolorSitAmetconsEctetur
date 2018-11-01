# EV3_Scanner
![](https://i.imgur.com/CiDLqEY.png)
![](https://i.imgur.com/XDIisXn.png)

In this challenge, given tar files contains an image and a pklg file that can be opened with Wireshark.
In PIC., there's a LegoEV3 using a color sensor to scan the Flag banner.

![](https://i.imgur.com/uKYYRu9.png)

In `.pklg` file, we found the data package from LegoEV3.

![](https://i.imgur.com/jmx5Hyw.png)

```
bluetooth.src == 00:16:53:61:30:c1
```
The `RFCOMM` protocol provides emulation of serial ports over the `L2CAP` protocol.
So, let's find data stored in `btrfcomm`.

![](https://i.imgur.com/bnsllhJ.png)

Cuz to most package of `btrfcomm` get `lenth == 9` 
```
bluetooth.src == 00:16:53:61:30:c1 && btrfcomm && btrfcomm.len == 9
```
If you press `↓` botton to scroll down, you will find out they most get different in 7、8 byte, one is `c0 40`, another is `80 3f`.

![](https://i.imgur.com/TpMYxXZ.png)

`c0 40` Suppose to be white.

![](https://i.imgur.com/iz6Yz7y.png)

`80 3f` Suppose to be black.

There's special situation if 8 byte is `45`, then 6、7 byte will change, first interval, 6、7 byte will increase, second will decrease:
```
00 c0 40 / 00 80 3f
++ ++ 45
00 c0 40 / 00 80 3f
-- -- 45
00 c0 40 / 00 80 3f
......
-- -- 45
00 c0 40 / 00 80 3f
```
Let just assum that LegoEV3 get U turn, following the path like this:
```
1---------->
<----------2
3---------->
......
11---------> 
```

![](https://i.imgur.com/mDEskRo.png)

Extract those packet and just save into text only with packet bytes.

Then we use Python script to make flag out:
```python
flag = []

printNum = 0
dirNum = 0
row = 0

f = open('btrfcomm9.txt', 'r')
for line in f:        
        if '0010  ' in line:
                #print('==============================')
                #print('printNum='+str(printNum))
                #print('dirNum='+str(dirNum))
                #print('row='+str(row))
                if line.split(' ')[6] == '45' and dirNum == 0 and printNum == 1:
                        printNum = 0
                        dirNum = 1
                        row+=1
                        print(''.join(flag))
                        flag[:] = []
                elif line.split(' ')[6] == '45' and dirNum == 1 and printNum == 1:
                        printNum = 0
                        dirNum = 0
                        row+=1
                        print(''.join(flag))
                        flag[:] = []
                elif dirNum == 0 and line.split(' ')[6] != '45':
                        printNum = 1
                        #print('six='+line.split(' ')[6])
                        if line.split(' ')[5] == 'c0' and line.split(' ')[6] == '40':
                                flag.append(' ')
                        if line.split(' ')[5] == '80' and line.split(' ')[6] == '3f':
                                flag.append('#')
                elif dirNum == 1 and line.split(' ')[6] != '45':
                        printNum = 1
                        #print('six='+line.split(' ')[6])
                        if line.split(' ')[5] == 'c0' and line.split(' ')[6] == '40':
                                flag.insert(0,' ')
                        if line.split(' ')[5] == '80' and line.split(' ')[6] == '3f':
                                flag.insert(0,'#')
        

```

```
  #                                              ###   ######   #        #  ######  #######   #     #  ######   #######  ######   #     #   ######   #    #   ######  ####          
  #        #     #                              #     ##        #       #        #   #         #   #      #   #    #  #       #     #   #       #  #   #           #        
  #             #####                             #     ##        ##      #        #  #         #  #    #    ##   #     #  #        #     #   #        ###     #           #        
  #            ##     ####   ###### #####   ##     ######     #     #    ######   #  ##     ##     #######   #    #  ######   #    #   ##       ###      ######     ###      
   ###  #                                              ####   #######  #       #   ######  #######   #    #  ######  #######  ######   #     #   ######   #   #  ######  #####       
 #        ##    ##                              ##     #        ##      #        #  #         #   #   #    #  #     #  #        #    #  #       #  ##   #          ##      
  #            #####                             #     #         #     ##         #   #           # #    #      #    #  #        #    #   #       ##      #           #        
 #######   #    #       ####   ###### ###  ###     ######     #    #    #######  #  ###     #    ######   #      ######   #    #   #       ###      ######      ###     
   #   ##   #     #       #      #   # #  #    #     #          #   #          #  #     #     #     #  #     #     #       #  #    #   #        # #         #      ##       
 ##   #   #    #       #     #    ##  ##    #      #            # #           #  #    #      #     #   #   #     #       #   #     #   #        #   ##        #      ##      
 #   #   ##    ###     ####  ###### ##  #    ###    ######      ##       ######  ######          #    #  ########  ######  ########  ######  #    #  ######  #####  
```
Seems suck, repair it.
```
 #                                              ###   ######  #      #   ######  #######   #     #  ######   #######  ######   #     #   ######   #    #   ######  ####          
 #        #     #                              #     ##       #     #         #  #         #   #   #   #    #     #  #     #  #     #   #        #  ##   #           #
 #           ####                             #     ##        #    #         #  #          #  #   #    ##  #     #  #        #     #   #        ###     #           #    
#######   #    #       ####   ###### ###  ###     ######      #   #   #######  #  ###      ##    ######   #     #  ######   #     #   #        ###      ######      ###     
 #   ##   #    #       #      #   # #  #    #     #           #  #         #  #     #     #     #  #     #     #       #   #     #   #        # #           #    ##       
 ##   #   #    #       #     #    # #  ##    #    #           # #         #  #    #      #     #   #    #     #       #   #     #   #        #   ##        #   ##      
 #   #   ##    ###     ####  ###### ##  #    ###  #######     ##    ######  ######      #    #     ##  #######  #######  #######   #######  #     ## ###### ##  
```

Flag: `hitcon{EV3GYROSUCKS}`