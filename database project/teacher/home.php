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
		<h3>Teacher</h3><h4><a href="index.php">Logout</a> <a href="changepass.php">Change Password</a></h4>

<?php include('includes/header.php'); ?>

<?php include('includes/nav.php'); ?>

<div id="content">
<style>
table, td, th
{
border:1px black;
}
th
{
background-color:gray;
color:white;
}
</style>

<table>
</tr>
	<tr><td colspan="2"><?php echo isset($_GET["msg"])?$_GET["msg"]:"";?>
  </td></tr>

<tr>
<th>Firstname</th>
<th>Lastname</th>
<th>Savings</th>
</tr>
<tr>
<td>Peter</td>
<td>Griffin</td>
<td>$100</td>
</tr>
<tr>
<td>Lois</td>
<td>Griffin</td>
<td>$150</td>
</tr>
<tr>
<td>Joe</td>
<td>Swanson</td>
<td>$300</td>
</tr>
<tr>
<td>Cleveland</td>
<td>Brown</td>
<td>$250</td>
</tr>
</table>
</div> <!-- end #content -->

<?php include('includes/sidebar.php'); ?>

<?php include('includes/footer.php'); ?>

		</div> <!-- End #wrapper -->

	</body>

</html>