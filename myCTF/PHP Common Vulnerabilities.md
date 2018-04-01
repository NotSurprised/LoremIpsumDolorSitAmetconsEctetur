# **PHP Common Vulnerabilities**

**Problem of `@`**
`@` will make php ignore any error messages.

``` shell=
<?php
    $A;
    echo @$A;
    if(@$A)
    {
        echo "should be write";
    }
    else
    {
        echo @$A;
    }
?>

>>> [nothing error messages]
```

**Problem of auto type transfer & urldecode**

If you `$_GET` or `$_POST` a variable as `[]=a`, then php will receive `$_GET['name']` as `[a]` (in array type), then it will call `urldecode`.

```shell=
http://PHPvulnerabilities/login.php?name[]=admin

$_GET['name'] = ['admin']
```

**Problem of strcmp**

`strcmp(str1, str2)` : 
if `str1` smaller than `str2` return < 0
if str1 bigger than str2 return > 0
if equal, return 0

-   PHP 5.2 will format two attributes into STRING
-   After PHP 5.3.3, if compare array with string will return 0
-   PHP 5.5 will return NULL if any attribute isn't STRING


```shell=
<?php
    $get=$_GET['name'];
    echo $get;
    $file = fopen("flag.txt", "r") or die("Unable to open flag!");
    $flag = fread($file,filesize("flag.txt"));
    if(strcmp($get, $flag)==0)
    {
        echo $flag;
    }
    else
    {
        echo "YouShouldNotPass!!!!!!!";
    }
    fclose($file);
?>
```
Using `http://PHPvulnerabilities/login.php?name[]=admin` can pass it.

**Problem of sha1() & md5()**

These two function cannot deal with array, but they won't break with error message and return `FALSE`.

```shell=
<?php
        $array=[1,2];
        if(sha1($array))
        {
            echo "TRUE";
        }
        else
        {
            echo "FALSE";
        }
        if(md5($array))
        {
            echo "TRUE";
        }
        else
        {
            echo "FALSE";
        }
?>
```

```shell=
<br />
<b>Warning</b>:  sha1() expects parameter 1 to be string, array given in <b>[...][...]</b> on line <b>3</b><br />
FALSE<br />
<b>Warning</b>:  md5() expects parameter 1 to be string, array given in <b>[...][...]</b> on line <b>11</b><br />
FALSE
```

