# Driver Test Signing

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/signing-drivers-for-public-release--windows-vista-and-later-

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/cross-certificates-for-kernel-mode-code-signing

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/digital-certificates

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/introduction-to-test-signing

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/test-signing-driver-packages

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/kernel-mode-code-signing-policy--windows-vista-and-later-

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/catalog-files

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/signing-drivers-for-public-release--windows-vista-and-later-

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/software-publisher-certificate

First, install Visual Studio & WDK for Kernel Driver Developer Enivroment.

Then open VS developer command-line tool.

![](https://i.imgur.com/f8l0BxI.png)

I assume you build your own dirver already, if you try to use sign function within VS project, that's another issue. 

You should already have `.cat`, `.sys` & `.inf`. (with sign function in VS, you will get your own usable `.cer` if you set it right.)

## Make Certificate

First make CertStore in TestSignerComputer, also the certification.

But `CertStore` doesn't link to certificate, you can install certificate where you want, just make sure you can find it.

If you create a wrong CertStore you don't want, [delete it](http://www.digitallycreated.net/Blog/58/removing-a-windows-system-certificate-store).

```shell
MakeCert -r -pe -ss ITRItest -n "CN=ITRI.org(Test)" ITRItest.cer
```
[Make Sample](https://docs.microsoft.com/zh-tw/windows-hardware/drivers/devtest/makecert): `MakeCert -r -pe -ss TestCertStoreName -n "CN=CertName" CertFileName.cer` 
Here CertName should be `TestCertName`.

After all, double click `.cer` to install it.

![](https://i.imgur.com/PfaZdKz.png)

Then use `C:\WINDOWS\system32\cmd.exe certmgr` to check if the certificate correct installed?

![](https://i.imgur.com/hbSxgY3.png)

## Installing a Test Certificate on a Test Computer

Need Administator Privilege with VS 2017 developer shell.
```shell
CertMgr /add icrlmonitor.cer /s /r localMachine root 
CertMgr /add icrlmonitor.cer /s /r localMachine trustedpublisher
```

## Sign Certificate

```shell
SignTool sign /v /s ITRItest /n ITRI.org(Test) /t http://timestamp.verisign.com/scripts/timstamp.dll icrlmonitor.cat
SignTool sign /v /s ITRItest /n ITRI.org(Test) /t http://timestamp.verisign.com/scripts/timstamp.dll icrlmonitor.sys
```
[Sign Smaple](https://docs.microsoft.com/zh-tw/windows-hardware/drivers/devtest/signtool): `SignTool sign /v /s TestCertStoreName /n TestCertName /t http://timestamp.verisign.com/scripts/timstamp.dll DriverFileName.sys`

If there's multi certificates in same name, it will fail:

```
The following certificates have been found to be suitable for signing:
    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: B0EF6D47FA887170947B95DABE79E442987C2ED2

    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: 2C704EE62A45138D41663C92CC1B5FC5904D246B

SignTool Error: Multiple certificates were found that meet all the given
        criteria. Use the /a option to allow SignTool to choose the best
        certificate automatically or use the /sha1 option with the hash of the
        desired certificate.
The following certificates meet all given criteria:
    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: B0EF6D47FA887170947B95DABE79E442987C2ED2

    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: 2C704EE62A45138D41663C92CC1B5FC5904D246B

The following certificate was selected:
    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: 2C704EE62A45138D41663C92CC1B5FC5904D246B

Done Adding Additional Store
Successfully signed: IcrlMonitor.sys

Number of files successfully Signed: 1
Number of warnings: 0
Number of errors: 0
```

## Verify Signing

```shell
SignTool verify /v /pa icrlmonitor.cat
SignTool verify /v /pa icrlmonitor.sys
```

[Verify Sample](https://docs.microsoft.com/en-us/windows-hardware/drivers/install/verifying-the-signature-of-a-test-signed-driver-file): `SignTool verify /v /pa DriverFileName.sys`

```
Verifying: icrlmonitor.cat
Signature Index: 0 (Primary Signature)
Hash of file (sha1): 70DF2F92934371197DA21AF3E713D705D3F7A92B

Signing Certificate Chain:
    Issued to: ITRI.org(Test)
    Issued by: ITRI.org(Test)
    Expires:   Sun Jan 01 07:59:59 2040
    SHA1 hash: 2C704EE62A45138D41663C92CC1B5FC5904D246B

The signature is timestamped: Tue Jul 17 14:23:51 2018
Timestamp Verified by:
    Issued to: Thawte Timestamping CA
    Issued by: Thawte Timestamping CA
    Expires:   Fri Jan 01 07:59:59 2021
    SHA1 hash: BE36A4562FB2EE05DBB3D32323ADF445084ED656

        Issued to: Symantec Time Stamping Services CA - G2
        Issued by: Thawte Timestamping CA
        Expires:   Thu Dec 31 07:59:59 2020
        SHA1 hash: 6C07453FFDDA08B83707C09B82FB3D15F35336B1

            Issued to: Symantec Time Stamping Services Signer - G4
            Issued by: Symantec Time Stamping Services CA - G2
            Expires:   Wed Dec 30 07:59:59 2020
            SHA1 hash: 65439929B67973EB192D6FF243E6767ADF0834E4

SignTool Error: A certificate chain processed, but terminated in a root
        certificate which is not trusted by the trust provider.

Number of files successfully Verified: 0
Number of warnings: 0
Number of errors: 1
```

Be aware that the SignTool verify command does not explicitly specify the test certificate that was used to sign the driver file. For the verify operation to succeed, you must first install the test certificate in the **Trusted Root Certification Authorities certificate store** of the local computer that you use to verify the signature.

# Sign Release Certificate

Use `Software Publisher Certificate (SPC)` to sign the **catalog file** ( .cat ) of kernel-mode driver packages.

If the driver is a **boot-start driver** for 64-bit systems, you must also embed an SPC signature in the **driver file** ( .sys ).

## Cross-Certificates
The cross certificate is used to verify that the CA that issued an SPC is a trusted root authority.

https://docs.microsoft.com/en-us/windows-hardware/drivers/install/cross-certificates-for-kernel-mode-code-signing

CA Vendor:
https://docs.microsoft.com/en-us/windows-hardware/drivers/dashboard/get-a-code-signing-certificate
https://social.technet.microsoft.com/wiki/contents/articles/51151.microsoft-trusted-root-certificate-program-participants-as-of-january-30-2018.aspx

## Software Publisher Certificate

certificate information must first be contained in a Personal Information Exchange (.pfx) file. Use it to install certificate into CertStore.

However, CA vendor may provide following pairs of files:
* A `.pvk` file that contains the private key information. 
* An `.spc` or `.cer` file that contains the public key information.

To combine Them into one `.pfx` file, use [Pvk2Pfx](https://docs.microsoft.com/zh-tw/windows-hardware/drivers/devtest/pvk2pfx).
**.spc** :
`Pvk2Pfx -pvk mypvkfile.pvk -pi mypvkpassword -spc myspcfile.spc -pfx mypfxfile.pfx -po pfxpassword -f`
**.cer** :
`Pvk2Pfx -pvk mypvkfile.pvk -pi mypvkpassword -spc mycerfile.cer -pfx mypfxfile.pfx -po pfxpassword -f`

## Minifilter Altitude Request
https://docs.microsoft.com/en-us/windows-hardware/drivers/ifs/minifilter-altitude-request

## Driver Signing changes in Windows 10
https://blogs.msdn.microsoft.com/windows_hardware_certification/2015/04/01/driver-signing-changes-in-windows-10/