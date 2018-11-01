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
        
