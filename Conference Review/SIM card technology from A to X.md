# SIM card technology from A to X
## Relevant specification bodies/sources
* ISO (Integrated Circuit[s] Card)
* ITU (Telecom Charge Cards)
* ETSI (where GSM was originally specified)
* 3GPP (where 3G to 5G was specified)
* GlobalPlatform Card Specification
* Sun/Oracle JavaCard API, Runtime, VM
* GSMA 

## The SIM: Subscriber Identity Module
* probably anyone in the audience has at least one, likely more
* ubiquitous; every device withe cellular connectivity has at least one
* not many people outside the telecom industry ever look at them in much detail
* SIM card hacking (in the security sense) has a tradition at CCC since at least 1998
    * Vodafone Germany SIM card cloning:
    * https://ftp.ccc.de/software/gsm/gsm hack.tar.gz
    * SIM card simulator in Turbo C (1998): https://ftp.ccc.de/software/gsm/SIM sim.zip
* meanwhile: SIM technology stack is getting more complex and deep
* let’s recap what SIM cards actually are, and what they do

## Card Filesystem
* most smart cards contain file system abstraction
* cannot be mounted (not exposed like a block device / USB drive!)
* access based on file-level commands (analogy: more like MTP/PTP)
* some similarities to general-purpose (computer) OS file systems:
    * MF: Master File (root directory)
    * DF: Dedicated File (subdirectory)
    * EF: Elementary File (data file)
* However, much more comprehensive than computer OS file systems, e.g.
    * transparent EF: opaque stream of data, like PC
    * linear fixed EF: fixed-size records, seekable
    * cyclic fixed EF: ring buffer of records, seekable
    * incrementable: for monotonically incrementing counters
* Each file has Access Control Conditions (ACC)
    * read/write/update only after PIN1/PIN2/ADM-PIN

## Key SIM Card Commands
* SELECT (file)
* READ RECORD / UPDATE RECORD
    * for record-oriented EF
* READ BINARY / UPDATE BINARY
    * for transparent EF
* CHANGE CHV / DISABLE CHV / ENABLE CHV
    * CHV: Card Holder Verification (PIN)
* RUN GSM ALGORITHM
    * ask SIM to execute authentication algorithm in card

## 3G: ETSI UICC and the 3GPP USIM
* The GSM SIM was fully specified by ETSI in TS 11.11
* As GSM specs moved from ETSI to 3GPP, card specs were split:
    * ETSI UICC (Universal Integrated Circuit Card)
        * like a base class abstracting out those parts that are not cellular related, or at very least not 3GPP network related
    * 3GPP USIM Application on top of UICC
        * specifies those parts specifically relevant to 3GPP networks
        * implemented in ADF USIM (Application Dedicated File)
        * ADF can be entered via SELECT, similar to classic DF

## 4G: The ISIM
* 3G/LTE reuses the existing 3G Authentication (UMTS AKA)
* 4G/LTE simply reuses existing USIM
* some new optional files were introduced in ADF USIM
* IMS (IP Multimedia System used for not only VoLTE) specifies ISIM application
    * stores additional IMS related parameters like SIP server / user identity
    * presence of ISIM not required for IMS to work
    * if present, ISIM application present next to USIM (and possibly SIM)

## SIM cards in 5G
* 5G reuses existing 3G/4G USIM
* some new optional files were introduced in ADF USIM
* SUCI (Subscriber Concealed Identifier) can optionally be computed by SIM
    * this is the only feature requiring different card / apps on card

## Java Cards
* independent of SIM cards, Java Smart Cards have been developed
* based on Java Card Platform specifications by Sun (now Oracle)
* first cards in 1996 by Schlumberger (now Gemalto)
* independent of SIM cards, Java Smart Cards have been developed in 1996 by Schlumberger
* most cards implement GlobalPlatform specifications for vendor-independent management
    * super constrained, weird subset of Java
    * special on-card VM (not normal JVM)
    * special CAP format (not normal JAR)
    * Idea: Portability of Cardlets (card applications)

## Java SIM Cards
* There is no functional requirement for a SIM/USIM/ISIM to be a java card
* In reality, most SIM cards probably are Java Cards these days
* Portability is the main driver here
* Operators want to share same applications over multiple vendors/generations of cards
* 3GPP and ETSI specify Java APIs / packages available specifically on Java SIM cards