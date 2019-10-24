<?php

  $sid=isset($_POST["sid"])?$_POST["sid"]:"";


  if(!empty($sid)){

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

if($count==0){

header("location:del_stu.php?msg=No Student account exist");

}

else

{

$qry="delete from user where username='$sid'";

mysql_query($qry);

$qry="delete from  student where sid='$sid'";

mysql_query($qry);


header("location:del_stu.php?msg=Student account Deleted");

}

mysql_close($link);


}

  else

  {

  header("location:del_stu.php?msg=No field should be blank");

  }