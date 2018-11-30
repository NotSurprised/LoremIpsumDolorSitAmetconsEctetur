# Hitcon 2018 Web - Oh My Raddit
Task tell us flag format in first : `Flag is hitcon{ENCRYPTION_KEY}`
And there's hint from author :　`assert ENCRYPTION_KEY.islower()`

We can have a conclusion that we need to find out the encrypt algorithm then extract out the encrypt key.

Then we check the web source, and we find out that it's url not just requests server with plaintext but url in chipertext.

```html
<a href="?s=8c762b8f22036dbbdda56facf732ffa71c3a372e4530241246449a55e25888cf98164f49a25f54a84ea0640e3adaf107cc67c8f2e688e8adf18895d89bfae58e33ae2e67609b509afb0e52f2f8b2145e">50 million Facebook accounts owned</a>
```

When we require ` http://13.115.255.46/?s=8c762b8f22036dbbdda56facf732ffa71c3a372e4530241246449a55e25888cf98164f49a25f54a84ea0640e3adaf107cc67c8f2e688e8adf18895d89bfae58e33ae2e67609b509afb0e52f2f8b2145e` 
Then we were redirected to `https://newsroom.fb.com/news/2018/09/security-update/`

If we use BurpSuite to intercept the package, we'll found that it response `303 see other`

```
HTTP/1.1 303 See Other
Date: Mon, 22 Oct 2018 07:24:06 GMT
Server: localhost
Content-Type: text/html
Location: https://newsroom.fb.com/news/2018/09/security-update/
Connection: close
Content-Length: 0
```

Then we found whatever we modify url hex after no.48 , it all redirect to same destinition.

```
Date →Mon, 22 Oct 2018 07:33:53 GMT
Server →localhost
Content-Type →text/html
Location →https://medium.com/@Wflki/sql-injection-oracle-and-full-width-characters-13bb86fc034a
Keep-Alive →timeout=5, max=100
Connection →Keep-Alive
Transfer-Encoding →chunked
```

So we assume that hex after no.48 is encrypt from url title.

We get conclude that this is encrypt in block and there's no relationship between block and block. (ECB mode)

Popular block cipher we get DES & AES, however minus len AES will be AES-128, which just bigger than our chipher text a lot, this challenge might be DES-ECB.

Cause to last bit of every letter in key all use to check, so 64 bits only get 56 bits engage in encrypting.

```
In [1]: bin(ord('b'))
Out[1]: '0b1100010'
 
In [2]: bin(ord('c'))
Out[2]: '0b1100011'
```

According to hint by author, there's only lowercase in key, `b` is same to `c`, we only need to choose 8 letters from `abdfhjlnprtvxz`, 
the complexity is `14^8`. 

Then we found that same sub plaintext string has same sub chiphertext string.

After we separate request url 8 bytes by 8 bytes, we found that lot of url request with `3ca92540eb2d0a42` in the end.

This might be chipher of DES padding `\x08` * 8.

Then we get plaintext-chiphertext pair: `3ca92540eb2d0a42:0808080808080808`, hashcat it.

`hashcat -m 14000 3ca92540eb2d0a42:0808080808080808 -a 3 -1 acegikmoqsuwy ?1?1?1?1?1?1?1?1 --force`

The key is `ldgonaro`.

As I siad, `b` and `c` is the same as key. You can Brutalforce the flag submit input box, or follow the hint given by author: `P.S. If you fail in submitting the flag and want to argue with author, read the source first!`.

Here's suspicious url: `<a href="?s=2e7e305f2da018a2cf8208fa1fefc238522c932a276554e5f8085ba33f9600b301c3c95652a912b0342653ddcdc4703e5975bd2ff6cc8a133ca92540eb2d0a42">down</a>`

Plaintext of this url is: `m=d&f=uploads%2F70c97cc1-079f-4d01-8798-f36925ec1fd7.pdf`.

If we encrypt `m=d&f=app.py` we might download the source code right?

Then we send `http://13.115.255.46/?s=e2272b36277c708bc21066647bc214b8` as request, we get the source code like following:

```python=
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

Well, the important part should be `ENCRPYTION_KEY = 'megnnaro'` in line 9.

Flag is: `hitcon{megnnaro}`