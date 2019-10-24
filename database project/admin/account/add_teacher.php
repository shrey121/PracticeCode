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
<h3>Admin</h3><h4><a href="../admin.php">Logout</a> <a href="../changepass.php">Change Password</a></h4>
<?php include('../includes/header.php'); ?>
<?php include('includes/nav.php'); ?>

<div id="content">
<h4>*required field</h4>
<form name="loginform" action="teacher_add_exec.php" method="post">
<table width="309" border="0" align="center" cellpadding="2" cellspacing="5">
  <tr>
    <td colspan="2">
	</td>
  </tr>
	<tr><td colspan="2"><?php echo isset($_GET["msg"])?$_GET["msg"]:"";?>
  </td></tr>
  <tr>
    <td width="116"><div align="right">Teacher ID*</div></td>
    <td width="117"><input name="tid" type="text" /></td>
  </tr>
  <tr>
    <td><div align="right">Name*</div></td>
    <td><input name="tname" type="text" /></td>
  </tr>
  <tr>
    <td><div align="right">Department*</div></td>
    <td><input name="dname" type="text" /></td>
  </tr>
  <tr>
    <td><div align="right">Phone*</div></td>
    <td><input name="tphone" type="text" /></td>
  </tr>
  <tr>
    <td><div align="right"></div></td>
    <td><input name="" type="submit" value="Add" /></td>
  </tr>
</table>
</form>
</div> 

<?php include('../includes/footer.php');?>

		</div>

	</body>

</html>