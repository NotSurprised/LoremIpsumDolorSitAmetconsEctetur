# Shannon Entropy of a file 
# = minimum average number of bits per character 
# required for encoding (compressing) the file 
# 
# So the theoretical limit (in bytes) for data compression: 
# Shannon Entropy of the file * file size (in bytes) / 8 
# (Assuming the file is a string of byte-size (UTF-8?) characters 
# because if not then the Shannon Entropy value would be different.) 
import sys
import math 
import time
#if len(sys.argv) != 2: 
    #print "Usage: file_entropy.py [path]filename" 
    #sys.exit()
 
# read the whole file into a byte array
#f = open(sys.argv[1], "rb")
file_list = open('dir_original.txt')
f1 = file_list.readlines()

fileCount=0
outputFile = open("FileEntropy.csv","w")
outputFile.write("File"+","+"size in bytes"+","+"Entropy"+"\n")
for i in f1:
    fileCount=fileCount+1
    i = i.replace("\n","")
    print("============================================")
    print("File"+str(fileCount)+":"+i)
    f = open(i, "rb")

    byteArr = list(f.read())
    f.close() 
    fileSize = len(byteArr) 
    #print ('File size in bytes:') 
    #print (fileSize) 
     
    # calculate the frequency of each byte value in the file 
    freqList = [] 
    for b in range(256): 
        ctr = 0 
        for byte in byteArr: 
            if byte == b: 
                ctr += 1 
        freqList.append(float(ctr) / fileSize) 
    # print 'Frequencies of each byte-character:' 
    # print freqList 
    # print 
     
    # Shannon entropy 
    ent = 0.0 
    for freq in freqList: 
        if freq > 0: 
            ent = ent + freq * math.log(freq, 2) 
    ent = -ent 
    print('Shannon entropy (min bits per byte-character):' )
    print(ent)
    outputFile.write(i+","+str(fileSize)+","+str(ent)+"\n")
    #print('Min possible file size assuming max theoretical compression efficiency:' )
    #print((ent * fileSize), 'in bits' )
    #print((ent * fileSize) / 8, 'in bytes')

file_list.close()
print("done")