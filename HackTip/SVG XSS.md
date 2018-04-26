# **SVG XSS**

* Success:
```shell=
<svg><script>alert&#40;1)</script>
```
* Failed:
```shell=
<script>alert&#40;1)</script>
```

## Foreign Elements:
Elements from the MathML namespace and the SVG namespace.

![](https://i.imgur.com/jolDaxQ.png)

**Scalable Vector Graphics (SVG)** is an **XML**-based vector image format for two-dimensional graphics with support for interactivity and animation.

In XML:
```shell=
<xml>
    <name>aaa</name>
    <value>aaaaaaa&#40;</value>
</xml>
```

Equal to:
```shell=
<xml>
    <name>aaa</name>
    <value>aaaaaaa&#40;</value>
</xml>
```

## <script> Tag in SVG

We can see more detail in [here](https://www.w3.org/TR/SVG/script.html#ScriptElement):

A ‘script’ element is **equivalent to the ‘script’ element in HTML** and thus is the place for scripts.


