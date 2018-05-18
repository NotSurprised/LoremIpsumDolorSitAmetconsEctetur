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
