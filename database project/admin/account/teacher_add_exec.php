<?php

  $tid=isset($_POST["tid"])?$_POST["tid"]:"";

  $tname=isset($_POST["tname"])?$_POST["tname"]:"";

  $dname=isset($_POST["dname"])?$_POST["dname"]:"";
	
  $tphone=isset($_POST["tphone"])?$_POST["tphone"]:"";


  if(!empty($tid)&&!empty($tname)&&!empty($dname)&&!empty($tphone)){

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

if($count==1){

header("location:add_teacher.php?msg=Teacher already exists");

}

else

{

$qry="call infoteacher('$tid','$tname','$dname','$tphone',0)";

mysql_query($qry);

header("location:add_teacher.php?msg=Teacher Added");

}

mysql_close($link);


}

  else

  {

  header("location:add_teacher.php?msg=No field should be blank");

  }