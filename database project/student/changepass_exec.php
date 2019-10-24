<?php

  $username=isset($_POST["username"])?$_POST["username"]:"";

  $old_pass=isset($_POST["old_pass"])?$_POST["old_pass"]:"";

  $new_pass=isset($_POST["new_pass"])?$_POST["new_pass"]:"";
	
  $confirm=isset($_POST["confirm"])?$_POST["confirm"]:"";


  if(!empty($username)&&!empty($old_pass)&&!empty($new_pass)&&!empty($confirm)){
if($new_pass!=$confirm)

header("location:changepass.php?msg=Password does not be match.");


$host="localhost";

$user="root";

$pass="1234";

///open connection

$link=mysql_connect($host,$user,$pass) or die(mysql_error());

mysql_select_db("dbms",$link);

$query="SELECT * FROM user WHERE username='$username' and password='$old_pass'";

$result=mysql_query($query);

//count no of rows

$count=mysql_num_rows($result);

if($count==0){

header("location:changepass.php?msg=Wrong Username or Password");

}

else

{

$qry="update user set Password='$confirm' where username='$username' and password='$old_pass'";

mysql_query($qry);

header("location:home.php?msg=Password");

}

mysql_close($link);


}

  else

  {

  header("location:changepass.php?msg=No field should be blank");

  }