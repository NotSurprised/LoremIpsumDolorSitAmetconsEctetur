# **Pictorial mess**

First, we got 7 pics' compress file, extract them.

![](https://i.imgur.com/4BXRj8y.png)

I use Stegsolver to extract special layer, then I get following pics.

![](https://i.imgur.com/CPPejyM.png)

However, it's still not the flag.

With png image, we are able to resize image size by directly editing the binary file. This kind of resize will just affect the image size and not the data contained by the image.

If some data are out of the scale, we can make it show by resize the pics.

Interesting that all pics look like in square but actually in rectangle. It's 400*380.

In the png chunk structure you can see that PNG header determind the size at fifth & sixth 8 bytes block.

| Name                        | Size     |
| --------                    | -------- |
| Specific IHDR chunk size    | 8 bytes  |
| Specific IHDR chunk start   | 8 bytes  |
| Width                       | 8 bytes  |
| Height                      | 8 bytes  |
| Bit depth                   | 1 bytes  |
| Color type                  | 1 byte   |
| Compression method          | 1 byte   |
| Filter method               | 1 byte   |
| Interlace method            | 1 byte   |

![](https://i.imgur.com/YgzjCsu.png)

![](https://i.imgur.com/7dDbn6A.png)

Change `01 7C` (380) to `01 90` (400).

I use tool to resize them, It will be more easier without convert decimal to hex. 

![](https://i.imgur.com/9YuvBbJ.png)

Here's some data below the pics.

![](https://i.imgur.com/x9j7rpG.png)

![](https://i.imgur.com/AFqyGMv.png)

We can see 7 lines with white and black square. I converted it to 0 and 1:

Image 0: 11111101111110101111
Image 1: 11111011111111111111
Image 2: 10101011000101110011
Image 3: 00001001110010000101
Image 4: 00110000111100001011
Image 5: 01011110110001101000
Image 6: 01001011100001111001

We know that we were looking for a flag starting with pctf:

p: 01110000
c: 01100011
t: 01110100
f: 01111011

It means we need to add `0` to every column to convert them into ASCII.

```
#!/usr/bin/env python
imgx = "00000000000000000000"
img0 = "11111101111110101111"
img1 = "11111011111111111111"
img2 = "10101011000101110011"
img3 = "00001001110010000101"
img4 = "00110000111100001011"
img5 = "01011110110001101000"
img6 = "01001011100001111001"

flag = ""

for i in range(len(imgx)):
    char = imgx[i]+img0[i]+img1[i]+img2[i]+img3[i]+img4[i]+img5[i]+img6[i]
    flag += chr(int(char,2))

print(flag)
```

Flag is `pctf{B3yondth3s1ght}`