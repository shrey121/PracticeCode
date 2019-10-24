<?php

  $sid=isset($_POST["sid"])?$_POST["sid"]:"";

  $sname=isset($_POST["sname"])?$_POST["sname"]:"";

  $dname=isset($_POST["dname"])?$_POST["dname"]:"";
	
  $syear=isset($_POST["syear"])?$_POST["syear"]:"";

  $saddress=isset($_POST["saddress"])?$_POST["saddress"]:"";

  $sphone=isset($_POST["sphone"])?$_POST["sphone"]:"";


  if(!empty($sid)&&!empty($sname)&&!empty($dname)&&!empty($syear)&&!empty($saddress)&&!empty($sphone)){

$host="localhost";

$user="root";

$pass="1234";

///open connection

$link=mysql_connect($host,$user,$pass) or die(mysql_error());

mysql_select_db("dbms",$link);

$query="SELECT * FROM user WHERE username='".mysql_real_escape_string($sid)."'";

$result=mysql_query($query);

//count no of rows

$count=mysql_num_rows($result);

if($count==1){

header("location:add_stu.php?msg=Student already exists");

}

else

{

$qry="call infostudent('$sid','$sname','$dname','$syear','$saddress','$sphone',0,0)";

mysql_query($qry);

header("location:add_stu.php?msg=Student Added");

}

mysql_close($link);


}

  else

  {

  header("location:add_stu.php?msg=No field should be blank");

  }