#-*-coding:utf-8-*-
import math

processLen = 250
pathLen = 300
Extentions = [".EXE",".DOC",".XLS",".ZIP",".RAR",".PDF",".PPT",".MDB",".MP3",".MPG",".PNG",".GIF",".BMP",".JPG",".JPEG",".TXT" ]
extentions = [".exe",".doc",".xls",".zip",".rar",".pdf",".ppt",".mdb",".mp3",".mpg",".png",".gif",".bmp",".jpg",".jpeg",".txt" ]
dataRow = []    
processName = [[""]*1 for i in range(processLen)]
fileType = [[0]*16 for i in range(processLen)]
path = [[None]*pathLen for i in range(processLen)]
#read/write/delete/queryInfo/rename/Offset+Length/EndOfFile
pathIRP = [[[0]*7]*pathLen for i in range(processLen)]
#0 pId, 1 pathcount, 2 Read, 3 Write, 4 SetDispositionInformationFile(Delete),
#5 QueryStandardInformationFile(4name), 6 SetRenameInformationFile,
#7 FileType, 8 startTime, 9 finTime, 10 QueryDirectory
ProcessInfo = [[0]*11 for i in range(processLen)]
#0 pId, 1 FileTypeInList, 2 QueryInfoYet, 3 ReadYet, 4 WriteYet,
#5 Delete/not, 6 Rename/not, 7 FileTypeCount, 8 MappingPathRate,
#9 InfoFileRate, 10 ReadFileRate, 11 WriteFileRate,
#12 Offset+Length>=EndOfFile, 13 QueryDirectory, 14 duringTime, 15 Benign/Malicious
Log4writeBack = [[0]*16 for i in range(processLen)]

def featureSeleciton(fileName):
    file = open(fileName) ;

    outputFile = open("featureSelect2017-04-10-BatRead.csv","w")
    outputFile.write("name, pId, FileTypeInList, QueryInfo, Read, Write, Delete/not, Rename/not, FileTypeCount, MappingPathRate, InfoFileRate, ReadFileRate, WriteFileRate, Offset+Length>=EndOfFile, QueryDirectory, duringTime,Benign/Malicious\n")

    counter = 0 
    
    for line in file :
        line = line.replace("\n","")
        line = line.replace('"',"")
        counter = counter + 1
        #print(counter)
        dataRow.append(line.split(',',6))
    
    print(len(dataRow))
    
    count = 0
    for log in range(len(dataRow)):
        if (log):
            pId = 0
            pIdset = 0
            duringTime = 0
            for i in range(len(ProcessInfo)):
                pId = i
                if (pIdset == 0 and ProcessInfo[i][0] == dataRow[log][2]):#ProcessInRecording
                    ProcessInfo[i][9] = dataRow[log][0]#FinTime
                    duringTime = time(i)
                    FileTypeCount = 0
                    TargetFileType = 0
                    pathset = 0
                    for k in range(len(extentions)):
                        if (extentions[k] in dataRow[log][4]):#FileTypeInList
                            Log4writeBack[i][1]+=1
                            fileType[i][k] = 1
                            TargetFileType = 1
                            break
                        elif (Extentions[k] in dataRow[log][4]):
                            Log4writeBack[i][1]+=1
                            fileType[i][k] = 1
                            TargetFileType = 1
                            break
                    for l in range(len(extentions)):#FileTypeCount
                        if (fileType[i][l] == 1):
                            FileTypeCount=FileTypeCount+1
                            Log4writeBack[i][7]=FileTypeCount
                            ProcessInfo[i][7]=FileTypeCount
                    if (dataRow[log][3]=="QueryDirectory"):
                            ProcessInfo[i][10] = ProcessInfo[i][10] + 1
                    for j in range(pathLen):
                        if (path[i][j] == None and pathset == 0 and TargetFileType==1):#FileIsNotInRecording
                            path[i][j] = dataRow[log][4]
                            ProcessInfo[i][1] = ProcessInfo[i][1]+1
                            if (dataRow[log][3]=="ReadFile"):#read
                                ProcessInfo[i][2] = ProcessInfo[i][2] + 1
                                Log4writeBack[i][3] += 1
                                pathIRP[i][j][0] = 1
                            elif (dataRow[log][3]=="WriteFile"):#write
                                ProcessInfo[i][3] = ProcessInfo[i][3] + 1
                                Log4writeBack[i][4] += 1
                                if(dataRow[log][6]):
                                    detail = str(dataRow[log][6])
                                    lhs, rhs = detail.split("Offset: ", 1)
                                    Offset, Length = rhs.split(", Length: ", 1)
                                    Offset = Offset.replace(",", "")
                                    Length = Length.replace(",", "")
                                    pathIRP[i][j][6] = int(Offset)+int(Length)
                                    if(pathIRP[i][j][6]>=pathIRP[i][j][7]):
                                        Log4writeBack[i][12] += 1
                                pathIRP[i][j][1] = 1
                            elif (dataRow[log][3]=="SetDispositionInformationFile"):#delete
                                ProcessInfo[i][4] = ProcessInfo[i][4] + 1
                                Log4writeBack[i][5] += 1
                                pathIRP[i][j][2] = 1
                            elif (dataRow[log][3]=="QueryStandardInformationFile"):#queryInfo
                                ProcessInfo[i][5] = ProcessInfo[i][5] + 1
                                Log4writeBack[i][2] += 1
                                pathIRP[i][j][3] = 1
                                if(dataRow[log][6]):
                                    detail = str(dataRow[log][6])
                                    lhs, rhs = detail.split("EndOfFile: ", 1)
                                    EndOfFile, rhs1 = rhs.split(", ", 1)
                                    EndOfFile = EndOfFile.replace(",", "")
                                    pathIRP[i][j][6] = int(EndOfFile)
                            elif (dataRow[log][3]=="SetRenameInformationFile"):#rename
                                ProcessInfo[i][6] = ProcessInfo[i][6] + 1
                                Log4writeBack[i][6] += 1
                                pathIRP[i][j][4] = 1
                            pathset = 1
                            break
                        elif (path[i][j] == dataRow[log][4] and pathset == 0):#FileInRecording
                            if (pathIRP[i][j][3] == 1):
                                Log4writeBack[i][2] += 1
                            if (pathIRP[i][j][0] == 1):
                                Log4writeBack[i][3] += 1
                            if (pathIRP[i][j][1] == 1):
                                Log4writeBack[i][4] += 1
                            if (pathIRP[i][j][2] == 1):
                                Log4writeBack[i][5] += 1
                            if (pathIRP[i][j][4] == 1):
                                Log4writeBack[i][6] += 1
                            if (dataRow[log][3]=="ReadFile"):
                                ProcessInfo[i][2] = ProcessInfo[i][2] + 1
                                Log4writeBack[i][3] += 1
                                pathIRP[i][j][0] = 1
                            elif (dataRow[log][3]=="WriteFile"):
                                ProcessInfo[i][3] = ProcessInfo[i][3] + 1
                                Log4writeBack[i][4] += 1
                                if(dataRow[log][6]):
                                    detail = str(dataRow[log][6])
                                    lhs, rhs = detail.split("Offset: ", 1)
                                    Offset, Length = rhs.split(", Length: ", 1)
                                    if(", " in Length):
                                        Length, Priority = Length.split(", ", 1)
                                    if("," in Offset):
                                        Offset = Offset.replace(",", "")
                                    if("," in Length):
                                        Length = Length.replace(",", "")
                                    pathIRP[i][j][5] = int(Offset)+int(Length)
                                    if(pathIRP[i][j][5]>=pathIRP[i][j][6]):
                                        Log4writeBack[i][12] += 1
                                pathIRP[i][j][1] = 1
                            elif (dataRow[log][3]=="SetDispositionInformationFile"):
                                ProcessInfo[i][4] = ProcessInfo[i][4] + 1
                                Log4writeBack[i][5] += 1
                                pathIRP[i][j][2] = 1
                            elif (dataRow[log][3]=="QueryStandardInformationFile"):
                                ProcessInfo[i][5] = ProcessInfo[i][5] + 1
                                Log4writeBack[i][2] += 1
                                pathIRP[i][j][3] = 1
                                if(dataRow[log][6]):
                                    detail = str(dataRow[log][6])
                                    lhs, rhs = detail.split("EndOfFile: ", 1)
                                    EndOfFile, rhs1 = rhs.split(", ", 1)
                                    if("," in EndOfFile):
                                        EndOfFile = EndOfFile.replace(",", "")
                                    pathIRP[i][j][6] = int(EndOfFile)
                            elif (dataRow[log][3]=="SetRenameInformationFile"):
                                ProcessInfo[i][6] = ProcessInfo[i][6] + 1
                                Log4writeBack[i][6] += 1
                                pathIRP[i][j][4] = 1
                            pathset = 1
                            break
                        if(pathset == 1):
                            break
                    pIdset = 1
                    break
                elif (pIdset == 0 and ProcessInfo[i][0] == 0):#ProcessIsNotInRecording
                    ProcessInfo[i][0] = dataRow[log][2]
                    Log4writeBack[i][0] = dataRow[log][2]
                    ProcessInfo[i][1] = ProcessInfo[i][1]+1
                    ProcessInfo[i][8] = dataRow[log][0]
                    ProcessInfo[i][9] = dataRow[log][0]
                    duringTime = time(i)
                    processName[i] = dataRow[log][1]
                    FileTypeCount = 0
                    TargetFileType = 0
                    for k in range(len(extentions)):
                        if (extentions[k] in dataRow[log][4]):#FileTypeInList
                            Log4writeBack[i][1]+=1
                            fileType[i][k] = 1
                            TargetFileType = 1
                            break
                        elif (Extentions[k] in dataRow[log][4]):
                            Log4writeBack[i][1]+=1
                            fileType[i][k] = 1
                            TargetFileType = 1
                            break
                    for l in range(len(extentions)):#FileTypeCount
                        if (fileType[i][l] == 1):
                            FileTypeCount=FileTypeCount+1
                            Log4writeBack[i][7]=FileTypeCount
                            ProcessInfo[i][7]=FileTypeCount
                    path[i][0] = dataRow[log][4]
                    if (dataRow[log][3]=="QueryDirectory"):
                        ProcessInfo[i][10] = ProcessInfo[i][10] + 1
                    if (TargetFileType==1):
                        if (dataRow[log][3]=="ReadFile"):
                            ProcessInfo[i][2] = ProcessInfo[i][2] + 1
                            Log4writeBack[i][3] = 1
                            pathIRP[i][0][0] = 1
                        elif (dataRow[log][3]=="WriteFile"):
                            ProcessInfo[i][3] = ProcessInfo[i][3] + 1
                            Log4writeBack[i][4] = 1
                            if(dataRow[log][6]):
                                detail = ''.join(dataRow[log][6])
                                lhs, rhs = detail.split("Offset: ", 1)
                                Offset, Length = rhs.split(", Length: ", 1)
                                if(", " in Length):
                                    Length, Priority = Length.split(", ", 1)
                                if("," in Offset):
                                    Offset = Offset.replace(",", "")
                                if("," in Length):
                                    Length = Length.replace(",", "")
                                pathIRP[i][0][5] = int(Offset)+int(Length)
                                if(pathIRP[i][0][5]>=pathIRP[i][0][6]):
                                    Log4writeBack[i][12] = 1
                            pathIRP[i][0][1] = 1
                        elif (dataRow[log][3]=="SetDispositionInformationFile"):
                            ProcessInfo[i][4] = ProcessInfo[i][4] + 1
                            Log4writeBack[i][5] = 1
                            pathIRP[i][j][2] = 1
                        elif (dataRow[log][3]=="QueryStandardInformationFile"):
                            ProcessInfo[i][5] = ProcessInfo[i][5] + 1
                            Log4writeBack[i][2] = 1
                            pathIRP[i][0][3] = 1
                            if(dataRow[log][6]):
                                detail = ''.join(dataRow[log][6])
                                lhs, rhs = detail.split("EndOfFile: ", 1)
                                EndOfFile, rhs1 = rhs.split(", ", 1)
                                if("," in EndOfFile):
                                    EndOfFile = EndOfFile.replace(",", "")
                                pathIRP[i][0][6] = int(EndOfFile)
                        elif (dataRow[log][3]=="SetRenameInformationFile"):
                            ProcessInfo[i][6] = ProcessInfo[i][6] + 1
                            Log4writeBack[i][6] = 1
                            pathIRP[i][0][4] = 1
                    pIdset = 1
                    break
            if (duringTime!=0):
                Log4writeBack[pId][8] = float(ProcessInfo[pId][10])/duringTime#MappingPathRate
                Log4writeBack[pId][9] = float(ProcessInfo[pId][5])/duringTime#InfoFileRate
                Log4writeBack[pId][10] = float(ProcessInfo[pId][2])/duringTime#ReadFileRate
                Log4writeBack[pId][11] = float(ProcessInfo[pId][3])/duringTime#WriteFileRate
                Log4writeBack[pId][13] = ProcessInfo[pId][10]
                Log4writeBack[pId][14] = duringTime
                
    for i in range(processLen):
        if (Log4writeBack[i][7]>=7 and Log4writeBack[i][12]>=20 and Log4writeBack[i][13]>=20):
            Log4writeBack[i][15] = 1
        if (int(Log4writeBack[i][0])>0):
            if (Log4writeBack[i][15] == 1):
                outputFile.write(str(processName[i])+","+str(Log4writeBack[i][0])+","+str(Log4writeBack[i][1])+","+str(Log4writeBack[i][2])+","+str(Log4writeBack[i][3])+","+str(Log4writeBack[i][4])+","+str(Log4writeBack[i][5])+","+str(Log4writeBack[i][6])+","+str(Log4writeBack[i][7])+","+str(Log4writeBack[i][8])+","+str(Log4writeBack[i][9])+","+str(Log4writeBack[i][10])+","+str(Log4writeBack[i][11])+","+str(Log4writeBack[i][12])+","+str(Log4writeBack[i][13])+","+str(Log4writeBack[i][14])+","+"T"+"\n")
            if (Log4writeBack[i][15] != 1):
                outputFile.write(str(processName[i])+","+str(Log4writeBack[i][0])+","+str(Log4writeBack[i][1])+","+str(Log4writeBack[i][2])+","+str(Log4writeBack[i][3])+","+str(Log4writeBack[i][4])+","+str(Log4writeBack[i][5])+","+str(Log4writeBack[i][6])+","+str(Log4writeBack[i][7])+","+str(Log4writeBack[i][8])+","+str(Log4writeBack[i][9])+","+str(Log4writeBack[i][10])+","+str(Log4writeBack[i][11])+","+str(Log4writeBack[i][12])+","+str(Log4writeBack[i][13])+","+str(Log4writeBack[i][14])+","+"F"+"\n")
    #print(ProcessInfo)
    print(Log4writeBack)
    #print(path)
    #print(fileType)
    print("done")
    outputFile.close()
    
def time(i):
    startTime = ProcessInfo[i][8]
    finTime = ProcessInfo[i][9]
    startTime = startTime[3:]
    finTime = finTime[3:]
    time = []
    time1 = []
    time.append(startTime.split(':'))
    time1.append(finTime.split(':'))
    hour = int(time[0][0])
    hour1 = int(time1[0][0])
    min = int(time[0][1])
    min1 = int(time1[0][1])
    sec = float(time[0][2])
    sec1 = float(time1[0][2])
    sec2 = 0
    if(min1>=min):
        DuringHour = hour1-hour
        if(sec1>=sec):
            DuringMin = min1-min
            DuringSec = round(sec1-sec, 5)
            sec2=DuringHour*60*60+DuringMin*60+DuringSec
        else:
            DuringMin = min1-min-1
            DuringSec = round(60+sec1-sec, 5)
            sec2=DuringHour*60*60+DuringMin*60+DuringSec
    else:
        DuringHour = hour1-hour-1
        if(sec1>=sec):
            DuringMin = 60+min1-min
            DuringSec = round(sec1-sec, 5)
            sec2=DuringHour*60*60+DuringMin*60+DuringSec
        else:
            DuringMin = 60+min1-min-1
            DuringSec = round(60+sec1-sec, 5)
            sec2=DuringHour*60*60+DuringMin*60+DuringSec
    return sec2
       
if __name__ == '__main__':
    featureSeleciton("2017-04-10-BatRead.csv")
