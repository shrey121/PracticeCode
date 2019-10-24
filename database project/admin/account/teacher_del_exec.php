<?php

  $tid=isset($_POST["tid"])?$_POST["tid"]:"";


  if(!empty($tid)){

$host="localhost";

$user="root";

$pass="1234";

///open connection

$link=mysql_connect($host,$user,$pass) or die(mysql_error());

mysql_select_db("dbms",$link);

$query="SELECT * FROM user WHERE username='".mysql_real_escape_string($tid)."'";

$result=mysql_query($query);

//count no of rows

$count=mysql_num_rows($result);

if($count==0){

header("location:del_teacher.php?msg=No Teacher account exist");

}

else

{

$qry="delete from user where username='$tid'";

mysql_query($qry);

$qry="delete from  teacher where sid='$tid'";

mysql_query($qry);


header("location:del_teacher.php?msg=Teacher account Deleted");

}

mysql_close($link);


}

  else

  {

  header("location:del_teacher.php?msg=No field should be blank");

  }