# **ASIS Quals 2018 Plastic**

```shell=
~$ chmod 777 plastic_b3a67f6e7ad52d6ca559d1aafa79c6fd6a80c73360664e7330dd6303d60b789b 
~$ tar -xf plastic_b3a67f6e7ad52d6ca559d1aafa79c6fd6a80c73360664e7330dd6303d60b789b 
```

![](https://i.imgur.com/OjkV8Fh.png)

For picture in MISC, find metadata.

```shell=
~$ sudo apt install libimage-exiftool-perl
~$ exiftool plastic
ExifTool Version Number         : 10.60
File Name                       : plastic
Directory                       : .
File Size                       : 18 kB
File Modification Date/Time     : 2018:04:28 21:59:50+08:00
File Access Date/Time           : 2018:05:06 19:53:57+08:00
File Inode Change Date/Time     : 2018:05:06 19:52:05+08:00
File Permissions                : rw-r--r--
File Type                       : PNG
File Type Extension             : png
MIME Type                       : image/png
Image Width                     : 1612
Image Height                    : 74
Bit Depth                       : 8
Color Type                      : RGB with Alpha
Compression                     : Deflate/Inflate
Filter                          : Adaptive
Interlace                       : Noninterlaced
SRGB Rendering                  : Perceptual
White Point X                   : 0.3127
White Point Y                   : 0.329
Red X                           : 0.64
Red Y                           : 0.33
Green X                         : 0.3
Green Y                         : 0.6
Blue X                          : 0.15
Blue Y                          : 0.06
Pixels Per Unit X               : 5669
Pixels Per Unit Y               : 5669
Pixel Units                     : meters
XMP Toolkit                     : XMP Core 5.4.0
User Comment                    : AAAFWHjabVRfbBRFGJ/ZOeifa+m2hVJaoNf2iohQtndX9ipS29IeVuwVe/1zbfc4.5/bm7pbu7V5255DjaDISozExaggxSIxC+2KRqBhjCPFBQwgmPggtSnySFx98IP57.ML4590dEw2w2+33fzHzz+37fbyeW0TWbStIdKCDHuvUvngi7jxPL1kwj7DZjx4hK.7Vk3ttSUxsOTbmpmGgB85cLHYntFZXtHp7trx2M7H9/1RI+/78DgoWeC4zNhJarG.U7pp0ym3kdX1tapqZ02TayYY6l4gOXuOf8t5p92qjm17pXZDnVjf0LhxExMYYg62.jq1nFaySVbHqlc3NW1pat27b3sacrIZtYHWsnrWwVraNbWeucAzbRNcMMqWaumlN.ps04maIa1Uk4YxGcjukkksZJQ0toKqa8pMk4piQq1sWwupC0zKwRP1jYOGebWUsl.k+QE7QTlsbZ7j7N7rzQVDE0cGlKCoeLCUAarZFzcJXX3+fd5fL19/j6/S+qWJLnH.I/XxIXsLrkf2eX0Sj/YCEbLaVY/X1ztXKtbAaRIumcSeKadd2if/Y4aDofEiO6Jj.1fnk/qdmOV02tTQjycQjPFH/0xx+MDSWpZhXFyrOLPcPyHxfyVkbch4cHgk88Dn0.QcqtWJYSmzWwLawxKq4qcVPNpolBi0jme6QMjeSxRTVVJ4vVStYmvNIFnCTz3Cxg.tiP5IseLri4eibsSpsVfg7qK0Yd35HHatnPpGF+ZxjRl/3+uEHzU3HyWJvyRvGZk.OFJDLR2UyOouarpoLkNccc3ivOg5bmDV0jhWl5rCFlYp12t1QWajh8cuPss2XnyO.bWLN08FQgAO8c+T5CWdocmqa+yHtJOHEJAI6TtrcD/LCOgd2lhouiqyJbZ4eMw2s.mpzp2blyhqV5uWzxaOQoJ3RYUwtqwlZuKSLz4As4KjY8xHO8RP1STH5kvHNgqHTk.KnEmkoUfg2ocyOCXfrLwp/oT28pTasf4mcNcrUsLctkqKDK9Vwr0uPgDWG2h05mR.AGsr9fRAXoklXIOh0dCiku+V0l4l6stkbCWa7R1RomNeGXPx+5RofNyQlehonyFN.ECVKU96x9nZlkR+ZPR4VGx9I698al7MRuSi6wyRH4oPlq+B27uSkZZqUQVAJ6kEL.6AR7gAfIYB5gkAIZkAenwevgDfAWOAPOgrfBOXAevAveAx+AS+Ay+Ah8Aj4Fn4HP.wVVwDXwBboBvwC3wPfgR3Ae/Qwesg82wDXZBD4xCDFWYgjY8BV+Gr8I34Tl4Hr4P.V+CH8DK8Aq/Dm/AWvAvvwfvwF/gb/EP4WvhWuC2sCd8Jd4UfhHvCz8Kvwl8IoCrk.RLWoDjWhVtSButBu1IP60SAKoHl0FNnoFHoJvYbOoLPoHXQBLaNL6Aq6iq6hr9B1.dAPddFQ4ahwdjh0Ov2O/Y6DUQQGWr4s8+M9wDP0NfUGwlA==.
Orientation                     : Horizontal (normal)
Image Size                      : 1612x74
Megapixels                      : 0.119
```
In `User Comment : `, we get `AAAFWHjabVRfbBRF......`.
Decode it.

```python 2.7=
import base64
flagString = 'AAAFWHjabV......'
file=open("b64d","w")
file.write(base64.b64decode(flagString))
file.close()
```

After decompress, let's check the file type by `file` or `binwalk`:

```shell=
~$ sudo apt install binwalk
~$ binwalk b64d 

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
4             0x4             Zlib compressed data, best compression

```

Decompress the zlib compression:

```python 2.7=
import zlib
f = open('b64d', 'r')
o = open('decompressed_data','w')
o.write(zlib.decompress(f.read()))
o.close()
f.close()
```

Let's see the output `decompressed_data`:

```shell=
~$ strings decompressed_data 
bplist00
wxX$versionX$objectsY$archiverT$top
!"#$%&'()*+189=AGHNOWX\_cdhlostU$null
 WNS.keysZNS.objectsV$class
 XbaselineUcolorTmodeUtitleXpreamble]magnificationTdate_
backgroundColorZsourceText#
./0UNSRGB\NSColorSpaceO
*0.9862459898 0.007120999973 0.02743400075
2345Z$classnameX$classesWNSColor
67WNSColorXNSObject
:;<YNS.string
23>?_
NSMutableString
>@7XNSString
CDEFXNSString\NSAttributes
\documentclass[10pt]{article}
\usepackage[usenames]{color} %used for font color
\usepackage{amssymb} %maths
\usepackage{amsmath} %maths
\usepackage[utf8]{inputenc} %useful to type directly diacritic characters
VNSFont
STUVVNSSizeXNSfFlagsVNSName#@(
VMonaco
23YZVNSFont
[7VNSFont
23]^\NSDictionary
23`a_
NSAttributedString
NSAttributedString#@B
fgWNS.time#A
23ijVNSDate
k7VNSDate
m/0F1 1 1
CpEF
={\bf ASIS}\{50m3\_4pps\_u5E\_M37adat4\_dOn7\_I9n0Re\_th3M!!\}
23uv_
NSMutableDictionary
u]7_
NSKeyedArchiver
yzTroot
```

The answer is:
```
ASIS{50m3_4pps_u5E_M37adat4_dOn7_I9n0Re_th3M!!}
```