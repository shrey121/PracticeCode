<?php

  $username=isset($_POST["username"])?$_POST["username"]:"";

  $password=isset($_POST["password"])?$_POST["password"]:"";


  if(!empty($username)&&!empty($password)){


$host="localhost";

$user="root";

$pass="1234";

///open connection

$link=mysql_connect($host,$user,$pass) or die(mysql_error());

mysql_select_db("dbms",$link);

$query="SELECT * FROM user WHERE username='$username' and password='$password'";

$result=mysql_query($query);

//count no of rows

$count=mysql_num_rows($result);

if($count==0){

header("location:index.php?msg=Wrong Username or Password");

}

else

{


header("location:home.php");

}

mysql_close($link);


}

  else

  {

  header("location:index.php?msg=Username or password cannot be blank.");

  }