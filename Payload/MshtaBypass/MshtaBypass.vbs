CreateObject("WScript.Shell").Run("""MshtaVbs.ps1""")
Set objFS = CreateObject("Scripting.FileSystemObject")
strFile = "WLtester.txt"
strLine = "MshtaVbsBypass."
If Not fso.FileExists( inputFileName ) Then
	Set objFile = objFS.CreateTextFile(strFile,True)
	objFile.Write(strLine)
	objFile.Close
Else
	Set objFile = objFS.OpenTextFile(strFile, ForAppending, True )
	objFile.Write(strLine)
	objFile.Close
End If