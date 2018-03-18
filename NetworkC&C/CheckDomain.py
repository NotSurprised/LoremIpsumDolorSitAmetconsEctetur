import urllib.parse
import http.client
import socket

def checkDomainExistOrNot(fileName):
    file = open(fileName)
    outputFile = open("checkDomainExistOrNot.csv","w")
    counter = 0 
    dataRow = []
    Headers = {'User-Agent':'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'}#pretend as web browser to avoid denied by target server

    for line in file :
        line = line.replace("\n","")

        domainName=str(line)

        print(domainName)

        print ("http")
        HTTP=http.client.HTTPConnection(domainName, timeout=3)
        
        error = ""
        r1 = None
        print ("GET")
        try:
            HTTP.request("GET","","",Headers)
            r1 = HTTP.getresponse()
        except socket.gaierror:
            error = "socket.gaierror"
            print (error)
        except socket.timeout:
            error = "socket.timeout"
            print (error)
        except ConnectionRefusedError:
            error = "ConnectionRefusedError"
            print (error)
        if(r1 is not None):
            
            print ("getresponse")
            #if (b"Hello admin" in HTTP.getresponse().read()):
            IP = socket.gethostbyname(domainName)
            
            print(domainName,IP, r1.status, r1.reason)
        
            outputFile.write(str(domainName)+","+str(IP)+","+str(r1.status)+","+str(r1.reason)+"\n")
        #else:
            #outputFile.write(str(domainName)+","+"Failed"+","+error+"\n")
            
    outputFile.close()
if __name__ == '__main__':
    checkDomainExistOrNot("DomainList.txt")
    
