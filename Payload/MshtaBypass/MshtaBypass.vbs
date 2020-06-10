Dim objShell
Dim strPath

'CreateObject("WScript.Shell").Run("""MshtaVbs.ps1""")
Set objFS = CreateObject("Scripting.FileSystemObject")
Set objShell = Wscript.CreateObject("Wscript.Shell")
strPath = objShell.SpecialFolders("Desktop")
strFile = strPath & "\WLtester.txt"
strLine = "MshtaVbsBypass."
'WScript.Echo strFile
If Not objFS.FileExists( strFile ) Then
	'WScript.Echo "Hello World"
	Set objFile = objFS.CreateTextFile(strFile,True)
	objFile.WriteLine(strLine)
	objFile.Close
Else
	'WScript.Echo "GG"
	Const ForAppending = 8, TristateTrue = -1
	Set objFile = objFS.OpenTextFile(strFile, ForAppending, TristateTrue)
	objFile.WriteLine("")
	objFile.WriteLine(strLine)
	objFile.Close
End If