<?php 
echo "< ?php<br>
    if(\$_GET['name'])<br>
    {<br>
    &nbsp \$get=\$_GET['name'];<br>
    &nbsp \$file = fopen('flag.txt', 'r') or die('Unable to open flag!'');<br>
    &nbsp \$flag = fread(\$file,filesize('flag.txt'));<br>
    &nbsp if(strcmp(\$get, \$flag)==0)<br>
    &nbsp {<br>
    &nbsp&nbsp&nbsp&nbsp    echo \$flag;<br>
    &nbsp }<br>
    &nbsp else<br>
    &nbsp {<br>
    &nbsp&nbsp&nbsp&nbsp    header('Location: you_should_not_pass.php');<br>
    &nbsp }<br>
    &nbsp fclose(\$file);<br>
    }<br>
    ? ><br>";


    if(@$_GET['name'])
    {
        @$get=$_GET['name'];
        $file = fopen("flag.txt", "r") or die("Unable to open flag!");
        $flag = fread($file,filesize("flag.txt"));
        if(@strcmp($get, $flag)==0)
        {
            echo $flag;
        }
        else
        {
            header('Location: you_should_not_pass.php');
        }
        fclose($file);
    }
?>