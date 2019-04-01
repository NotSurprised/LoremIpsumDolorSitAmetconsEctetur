# CTF Tool
CVE-exploit
* SharpShooter
* dirtycow
* WinPwnage
* eternalblue

Web
* Burp Suite
* Wireshark
* SQLmap
* XSStrike
* Nmap
* Sublist3r
* Metasploit
* W3af
* OpenVAS
* Legion
    ```shell
    git clone https://github.com/GoVanguard/legion.git
    cd legion
    sudo chmod 777 startLegion.sh
    sudo ./startLegion.sh
    ```
* IoT-Implant-Toolkit
    ```shell
    sudo apt install sox ffmpeg
    git clone https://github.com/arthastang/IoT-Implant-Toolkit.git
    cd IoT-Implant-Toolkit/
    sudo python3 setup.py install
    ```
* tshark 
    ```
    tshark -r Not\ Only\ Wireshark.pcap -Y http -T fields -e http.request.uri
    ```
    ![](https://i.imgur.com/Xp9Is9a.png)
* Sublert
    ```
    git clone https://github.com/yassineaboukir/sublert.git 
    cd sublert
    sudo pip install -r requirements.txt
    sudo pip3 install -r requirements.txt
    python sublert.py -u paypal.com
    python sublert.py -d yahoo.com
    python sublert.py -a
    python sublert.py -m
    ```
    it will only monitors subdomains for which SSL/TLS certificate is issued, however subdomains running on HTTP/80 will not be identified unfortunately. You can nevertheless use other open source tools (Massdns, Aquatone, Sublist3r, etc.).
* CyberLens & Integrity
    https://dragos.com/community-tools/

Wireless
* aircrack-ng
* RFIDIOt

Forensic
* mimikatz
* hashcat
* CaptfEncoder
* stegsolve
* sonic-visualizer
* pkcrack
* binwalk
* EyeWitness
* fuzzbunch
* John the Ripper
* Deep-Explorer​
* imaginaryC2

Reverse
* gdb-peda
* pwntools
* ROPgadget
* checksec
* apktool
* angr
* klee
