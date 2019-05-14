# OMA DM 開發手札

## 通訊協定不同
從SML -> HTTP

## SQLite v.s. XML
我想 XML 的 parser 可能比用 SQLite 去 gen query 好用
XML 與 SQLite 都會以 MO 為單元建置一個表
但是存取文件上 DB 較無法直觀以文字處理的方式解決 需要 sql query

## DMtree 十分重要
在處理 ClientURI 上，OMA DM 以 DM 樹為單位，所以 query 的目標節點或是數值與條件數值所在可能為不同分支。
在關鍵分岔節點上被未知標記，在 DM tree 簡單時問題

## SQLite 使用重點
### sqlite_master
https://www.sqlite.org/faq.html#q7
https://stackoverflow.com/questions/6460671/sqlite-schema-information-metadata
mysql:information_schema

## Curl 使用重點
DOC:https://curl.haxx.se/libcurl/c/http-post.html
### init & clean

### Header List
```c
struct curl_slist *plist = NULL;

plist = curl_slist_append(plist, "Content-Type:application/vnd.oma.dm.initiation+json;");
// Set the content format become JSON
plist = curl_slist_append(plist, "Accept:application/vnd.oma.dm.request+json;");
plist = curl_slist_append(plist, "OMADM-DevID: IMEI:493005100592800;");
plist = curl_slist_append(plist, "Host: www.devicemgmt.org");

// Set Autherization into header
plist = curl_slist_append(plist, "Autherization: AB123CES121XX90TPOWQESEFSE33");

curl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, plist);
```

### multi thread
https://www.cnblogs.com/bigben0123/p/3154406.html
https://izualzhy.cn/use-curl-with-high-performance

## JSON-C 使用範例
DOC:https://json-c.github.io/json-c/json-c-0.10/doc/html/json__object_8h.html
### 範例
```JSON
{
  "name": "Brian",
  "sex": 0,
  "data": {
    "education": "master",
    "profession": "engineer"
  }
}
```

#### 組成 JSON object，並輸出成 string
```c
struct json_object *root, *data;
 
root = json_object_new_object();
json_object_object_add(root, "name", json_object_new_string("Brian"));
json_object_object_add(root, "sex", json_object_new_int(0));
 
data = json_object_new_object();
json_object_object_add(data, "education", json_object_new_string("master"));
json_object_object_add(data, "profession", json_object_new_string("engineer"));
json_object_object_add(root, "data", data);
 
// Output to string
printf("%s", json_object_to_json_string(root));
 
// Decrease counter and free object
json_object_put(data);
json_object_put(root);
```

#### 解開 JSON object
```c
struct json_object *root, *name, *sex, *data, *edu, *prof;
 
root = json_tokener_parse(json_string);
// Use is_error() to check the result, don't use "j_root == NULL".
if (is_error(j_root)) {
  printf("parse failed.");
  exit(-1);
}
 
name = json_object_object_get(root, "name");
sex = json_object_object_get(root, "sex");
data = json_object_object_get(root, "data");
// If parse fail, object is NULL
if (data != NULL) {
  edu = json_object_object_get(data, "education");
  prof= json_object_object_get(data, "profession");
}
 
if (!name || !sex|| !edu || !prof) {
  printf("parse failed.");
  json_object_put(root);
  exit(-1);
}
 
// Fetch value
printf("name=%s", json_object_get_string(name));
printf("sex=%d", json_object_get_int(sex));
printf("education=%s", json_object_get_string(edu));
printf("profession=%s", json_object_get_string(prof));
 
// Free
json_object_put(root);
```
## Gitlab-CI 遇到 docker image 無法正確 install link
### linux 缺少動態連接庫.so--cannot open shared object file: No such file or directory

error while loading shared libraries的解決方法
 
 執行行程式時，如此遇到像下列這種錯誤： 

./tests: error while loading shared libraries: xxx.so.0:cannot open shared object file: No such file or directory 


那就表示系統不知道xxx.so放在哪個目錄下。

這個時候就要在/etc/ld.so.conf中加入xxx.so所在的目錄。

 一般而言，有很多so檔會在/usr/local/lib這個目錄下，所以在/etc/ld.so.conf中加入/usr/local/lib這一行，可以解決此問題。

 或者加入一行xx.so所在的絕對路徑，如/usr/local/log4cxx/lib/也行。

將/etc/ld.so.conf存檔後，還要執行「/sbin/ldconfig –v」來更新一下才會生效。

 

如果共享庫文件安裝到了其它"非/lib或/usr/lib" 目錄下, 但是又不想在/etc/ld.so.conf中加路徑(或者是沒有權限加路徑). 那可以export一個全局變量LD_LIBRARY_PATH, 然後運行程序的時候就會去這個目錄中找共享庫.

     LD_LIBRARY_PATH的意思是告訴loader在哪些目錄中可以找到共享庫. 可以設置多個搜索目錄, 這些目錄之間用冒號分隔開. 比如安裝了一個mysql到/usr/local/mysql目錄下, 其中有一大堆庫文件在/usr/local/mysql/lib下面, 則可以在.bashrc或.bash_profile或shell裡加入以下語句即可:

export LD_LIBRARY_PATH=/usr/local/ mysql/lib:$LD_LIBRARY_PATH

一般來講這只是一種臨時的解決方案, 在沒有權限或臨時需要的時候使用.

總結：

總結下來主要有3種方法：
1.用ln將需要的so文件鏈接到/usr/lib或者/lib這兩個默認的目錄下邊
```
ln -s /where/you/install/lib/*.so /usr/lib
sudo ldconfig
```

2.修改LD_LIBRARY_PATH
```
export LD_LIBRARY_PATH=/where/you/install/lib:$LD_LIBRARY_PATH
sudo ldconfig
```

3.修改/etc/ld.so.conf，然後刷新

 

```
vim /etc/ld.so.conf
add /where/you/install/lib

sudo ldconfig
```