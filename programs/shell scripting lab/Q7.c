echo Enter user name

read name


num=5

who >temp_file

res=`grep -c $name <temp_file`


while test $num -gt 0

do


	if [ $res -ne 0 ]

	then

		echo User is logged in

		echo Write your message:

		read msg

		echo Msg sent..!!

		echo Yout msg is:"\n"$msg

		num=0

 
	else


		echo User is not logged in

		sleep 5

		who >temp_file

		res=`grep -c $name <temp_file`

		num=`expr $num - 1`


	fi


done
