# **Install Nmap in Ubuntu 17.04**
###### tags: `else` `todo`

```
sudo add-apt-repository ppa:pi-rho/security

sudo apt-get update

sudo apt-get install nmap
```

```
ubuntu@ubuntu-virtual-machine:~$ nmap -v itri.org.tw

Starting Nmap 7.60 ( https://nmap.org ) at 2018-03-12 18:49 CST
Initiating Ping Scan at 18:49
Scanning itri.org.tw (61.61.247.113) [2 ports]
Completed Ping Scan at 18:49, 0.01s elapsed (1 total hosts)
Initiating Parallel DNS resolution of 1 host. at 18:49
Completed Parallel DNS resolution of 1 host. at 18:49, 0.01s elapsed
Initiating Connect Scan at 18:49
Scanning itri.org.tw (61.61.247.113) [1000 ports]
Discovered open port 443/tcp on 61.61.247.113
Discovered open port 80/tcp on 61.61.247.113
Increasing send delay for 61.61.247.113 from 0 to 5 due to 11 out of 16 dropped probes since last increase.
Completed Connect Scan at 18:50, 28.57s elapsed (1000 total ports)
Nmap scan report for itri.org.tw (61.61.247.113)
Host is up (0.011s latency).
Other addresses for itri.org.tw (not scanned): 61.61.247.13
rDNS record for 61.61.247.113: 240.113.seed.itri.org.tw
Not shown: 996 filtered ports
PORT    STATE  SERVICE
80/tcp  open   http
139/tcp closed netbios-ssn
443/tcp open   https
445/tcp closed microsoft-ds

Read data files from: /usr/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 28.68 seconds

```
![](https://i.imgur.com/sKO30aX.png)
![](https://i.imgur.com/TvWV9YC.png)
Conclusion: Nmap can replace the websitepulse's reverse DNS.

Now, the question is how to check all domain in one IP.

```
62.149.142.25
=============

23 site(s) hosted on ip 62.149.142.25   
Location: ![](http://www.sameip.org/images/flag/it.gif)  Italy

---

1.  omertools.com
2.  ladonatella.eu
3.  cupcakecouturemilano.com
4.  wallanddeco.it
5.  brusalino.it
6.  mamen.net
7.  rugbylyons.it
8.  azionecattolicacomo.it
9.  garlattimoto.com
10.  associazioneconse.com
11.  siegoi.it
12.  abiticerimoniadonna.it
13.  ailbrescia.it
14.  paroquiacarreco.org
15.  hamlet1.com
16.  ilmessaggerosardo2.com
17.  lux-metal.com
18.  royalfrigo.com
19.  termotecgm.net
20.  circuitosanmartinodellago.com
21.  ferienhof-oberhofer.com
22.  sexandrome.it
23.  studiocasimiro.it

```

```
I use Sublist3r & AQUATONE to solve subdomain problem, unfortinately, webservices are always needed in both tool.
```



Seems AQUATONE is more useful than Sublist3r.


```
import urllib.parse
import http.client
import socket

def checkDomainExistOrNot(fileName):
    file = open(fileName)
    outputFile = open("checkDomainExistOrNot.csv","w")
    counter = 0 
    dataRow = []
    Headers = {'User-Agent':'Mozilla/5.0 (Windows; U; Windows NT 6.1; en-US; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6'} #pretend as web browser to avoid denied connect by server.

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
        else:
            outputFile.write(str(domainName)+","+"Failed"+","+error+"\n")
            
    outputFile.close()
if __name__ == '__main__':
    checkDomainExistOrNot("AQUATONE (2).txt")

```

AQUATONE 22 OK > Sublist3r 8 OK 
Sublist3r 16 failed > AQUATONE 198 failed
