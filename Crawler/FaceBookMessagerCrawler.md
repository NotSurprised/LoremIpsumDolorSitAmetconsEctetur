# FaceBookMessagerCrawler

First, go to mobile version's Messager:
https://m.facebook.com/messages/

Then open debug tool (F12) and type following script in console to start crawling:
```javascript
var id = setInterval(function () { 
		if (document.getElementById('messageGroup').getElementsByClassName('actions mfss fcg')[0].getElementsByTagName('abbr')[0].getAttribute("data-store").split(",")[0].split(":")[1]>1349020800){
			document.getElementById('see_older').getElementsByClassName('content')[0].click();
		} 
	}, 100);
```

`1349020800` in `if` condition is timestamp which can be customize.

Stop be following script:
```javascript
clearInterval(id)
```
