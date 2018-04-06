<?php
	error_reporting(0);
	include "flag.php";
	// Strong IP firewall, no-one can pass this except the admin in localhost
	if ($_SERVER['REMOTE_ADDR'] !== '127.0.0.1')
	{
		header("Location: you_should_not_pass");
	}
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset = "UTF-8">
	<title>admin Panel</title>
</head>
<body>
	Admin's secret is: <?php echo $flag; ?>
</body>
</html>

