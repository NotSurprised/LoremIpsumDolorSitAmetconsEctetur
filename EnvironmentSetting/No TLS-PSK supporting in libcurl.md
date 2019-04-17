# No TLS-PSK supporting in libcurl

I search a lot to try to use libcurl to fulfill the requirement of OMA DM in communication security with TLS-PSK & X.509

But unfortunately, it can't. Fortunately, OMA DM requirement for TLS-PSK and X.509 is at least one.

Seems from 2015-2018, there still no solution in open source community for it.

<a href="https://stackoverflow.com/questions/50740130/tls-psk-support-in-curl">https://stackoverflow.com/questions/50740130/tls-psk-support-in-curl

</a><a href="https://curl.haxx.se/mail/lib-2015-11/0021.html">https://curl.haxx.se/mail/lib-2015-11/0021.html</a>  

For those of you not watching the repo Isaac Boukris has a pull request 
to add support for TLS-PSK in libcurl for the OpenSSL backend [1]. It 
has been open for two months but hasn't received much feedback. If you 
are familiar with TLS-PSK or that is a feature you want in libcurl 
please give feedback in the pull request or this thread. 

I don't use TLS-PSK but I've taken a look at the commit and given my 
feedback. I'm hesitant to +1 due to a lack of experience with the PSK 
protocols and I don't know how PSK is actually being used in practice. 
Specifically I have two reservations: 

- What type of keys we'll allow: Currently the key is strlen'd. Are the 
keys in practice similar to data that's somewhat restricted in its range 
like a random password that someone may type in or copy or more like 
random binary data? My read of the RFC [2] is we must support both. I've 
suggested we use this format: 

identity:ascii:.JVLF@!):1g=:v]yN=?q}OV|JDs.P+B9JQ|XY&d:jIlew:#\>HhyCN4ADa^v14.\ 
identity:hex:2E4A564C464021293A31673D3A765D794E3D3F717D4F567C4A44732E502B42394A517C585926643A6A496C65773A235C3E486879434E344144615E7631342E5C 
identity:file:path 

like this: 
curl_easy_setopt(curl, CURLOPT_SSL_PSK, "identity:hex:b33f"); 

Isaac has countered with splitting the id from the key into 
CURLOPT_SSL_PSK_ID and CURLOPT_SSL_PSK_{ASCII,FILE,HEX}_KEY like this: 
curl_easy_setopt(curl, CURLOPT_SSL_PSK_ID, "identity"); 
curl_easy_setopt(curl, CURLOPT_SSL_PSK_HEX_KEY, "b33f"); 

I don't like that though because it adds too many curl options. We could 
do CURLPSKOPT_ defines but I still don't like it because the RFC allows 
for the server to prefer an identity and we may want to support that one 
day, which would require on our end support for setting multiple 
identity/key pairs in libcurl, so that's something else to consider. 

- Disabling certificate and hostname verification and specify cipher: In 
order to use some forms of PSK currently the ssl verify options must be 
disabled, which currently looks like this: 

curl_easy_setopt(hnd, CURLOPT_SSL_PSK, "client_id:jqwertyuiopasdfihjlz"); 
curl_easy_setopt(hnd, CURLOPT_SSL_CIPHER_LIST, "PSK-AES256-CBC-SHA"); 
curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYPEER, 0L); 
curl_easy_setopt(hnd, CURLOPT_SSL_VERIFYHOST, 0L); 

And for the tool I assume would be curl -k --tls-psk 
client_id:jqwertyuiopasdfihjlz --ciphers PSK-AES256-CBC-SHA 

I think it would be good if we could make it so just the psk line is 
needed but apparently we need some way to signal whether certificate and 
hostname verification is required, or in other words whether or not it's 
RSA PSK. I'm concerned that since there isn't a propensity to check the 
result of curl_easy_setopt someone may set PSK when PSK is not available 
and end up with all verification disabled, and if it's a different SSL 
library then the cipher may not be set either. I don't know how likely 
that will be. We could update the doc and example to say must check the 
return of CURLOPT_SSL_PSK. 

I wonder if there's some better solution, like check which cipher the 
server returned and if it's a PSK cipher that doesn't use cert/host 
verification then we skip that part. Isaac did suggest that early on, 
but it may be complicated to do. 

 

[1]: <a href="https://github.com/bagder/curl/pull/394">https://github.com/bagder/curl/pull/394</a> 
[2]: <a href="https://tools.ietf.org/html/rfc4279">https://tools.ietf.org/html/rfc4279</a> 