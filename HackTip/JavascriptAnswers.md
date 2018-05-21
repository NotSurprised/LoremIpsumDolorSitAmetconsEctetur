Basics

1. <a href="%6a%61%76%61%73%63%72%69%70%74:%61%6c%65%72%74%28%31%29"></a>
URL encoded "javascript:alert(1)"

Answer: The javascript will NOT execute.


2. <a
href="&#x6a;&#x61;&#x76;&#x61;&#x73;&#x63;&#x72;&#x69;&#x70;&#x74;:%61
%6c%65%72%74%28%32%29">
Character entity encoded "javascript" and URL encoded "alert(2)"

Answer: The javascript will execute.


3. <a href="javascript%3aalert(3)"></a>
URL encoded ":"

Answer: The javascript will NOT execute.


4. <div>&#60;img src=x onerror=alert(4)&#62;</div>
Character entity encoded < and >

Answer: The javascript will NOT execute.


5. <textarea>&#60;script&#62;alert(5)&#60;/script&#62;</textarea>
Character entity encoded < and >

Answer: The javascript will NOT execute AND the character entities will NOT
be decoded either


6. <textarea><script>alert(6)</script></textarea>

Answer: The javascript will NOT execute.


Advanced
7. <button onclick="confirm('7&#39;);">Button</button>
Character entity encoded '

Answer: The javascript will execute.


8. <button onclick="confirm('8\u0027);">Button</button>
Unicode escape sequence encoded '

Answer: The javascript will NOT execute.


9. <script>&#97;&#108;&#101;&#114;&#116&#40;&#57;&#41;&#59</script>
Character entity encoded alert(9);

Answer: The javascript will NOT execute.


10. <script>\u0061\u006c\u0065\u0072\u0074(10);</script>
Unicode Escape sequence encoded alert

Answer: The javascript will execute.


11. <script>\u0061\u006c\u0065\u0072\u0074\u0028\u0031\u0031\u0029</script>
Unicode Escape sequence encoded alert(11)

Answer: The javascript will NOT execute.


12. <script>\u0061\u006c\u0065\u0072\u0074(\u0031\u0032)</script>
Unicode Escape sequence encoded alert and 12 

Answer: The javascript will NOT execute.


13. <script>alert('13\u0027)</script>
Unicode escape sequence encoded '

Answer: The javascript will NOT execute.


14. <script>alert('14\u000a')</script>
Unicode escape sequence encoded line feed.

Answer: The javascript will execute.


Bonus
16. <a
	  href="&#x6a;&#x61;&#x76;&#x61;&#x73;&#x63;&#x72;&#x69;&#x70;&#x74;&#x3a;&#x25;&#x35;&#x63;&#x25;&#x37;&#x35;&#x25;&#x33;&#x30;&#x25;&#x33;&#x30;&#x25;&#x33;&#x36;&#x25;&#x33;&#x31;&#x25;&#x35;&#x63;&#x25;&#x37;&#x35;&#x25;&#x33;&#x30;&#x25;&#x33;&#x30;&#x25;&#x33;&#x36;&#x25;&#x36;&#x33;&#x25;&#x35;&#x63;&#x25;&#x37;&#x35;&#x25;&#x33;&#x30;&#x25;&#x33;&#x30;&#x25;&#x33;&#x36;&#x25;&#x33;&#x35;&#x25;&#x35;&#x63;&#x25;&#x37;&#x35;&#x25;&#x33;&#x30;&#x25;&#x33;&#x30;&#x25;&#x33;&#x37;&#x25;&#x33;&#x32;&#x25;&#x35;&#x63;&#x25;&#x37;&#x35;&#x25;&#x33;&#x30;&#x25;&#x33;&#x30;&#x25;&#x33;&#x37;&#x25;&#x33;&#x34;&#x28;&#x31;&#x35;&#x29;"></a>

Answer: The javascript will execute.
