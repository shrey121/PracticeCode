<?php

  $aid=isset($_POST["aid"])?$_POST["aid"]:"";

  $aname=isset($_POST["aname"])?$_POST["aname"]:"";

  $aphone=isset($_POST["aphone"])?$_POST["aphone"]:"";


  if(!empty($aid)&&!empty($aname)&&!empty($aphone)){

$host="localhost";

$user="root";

$pass="1234";

///open connection

$link=mysql_connect($host,$user,$pass) or die(mysql_error());

mysql_select_db("dbms",$link);

$query="SELECT * FROM user WHERE username='".mysql_real_escape_string($aid)."'";

$result=mysql_query($query);

//count no of rows

$count=mysql_num_rows($result);

if($count==1){

header("location:add_admin.php?msg=Admin already exists");

}

else

{

$qry="call infostudent('$aid','$aname','$aphone')";

mysql_query($qry);

header("location:add_admin.php?msg=Admin Added");

}

mysql_close($link);


}

  else

  {

  header("location:add_admin.php?msg=No field should be blank");

  }