<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>

<meta http-equiv="content-type" content="text/html; charset=utf-8" />

<meta name="description" content="" />

<meta name="keywords" content="" />

<meta name="author" content="" />

<link rel="stylesheet" type="text/css" href="style.css" media="screen" />

<title>JMI</title>
</head>

	<body>

		<div id="wrapper">
<h3>Student Login</h3>
<?php include('includes/header.php'); ?>

<div id="content">
<form name="loginform" action="login_exec.php" method="post">
<table width="309" border="0" align="center" cellpadding="2" cellspacing="5">
<tr><td colspan="2"><?php echo isset($_GET["msg"])?$_GET["msg"]:"";?>
  </td></tr>
  </tr>
  <tr>
    <td width="116"><div align="right">Username</div></td>
    <td width="117"><input name="username" type="text" /></td>
  </tr>
  <tr>
    <td><div align="right">Password</div></td>
    <td><input name="password" type="password" /></td>
  </tr>
  <tr>
    <td><div align="right"></div></td>
    <td><input name="" type="submit" value="Login" /></td>
  </tr>
</table>
</form>
</div> <!-- end #content -->

<?php include('includes/footer.php'); ?>

		</div> <!-- End #wrapper -->

	</body>

</html>