echo Enter year:

read year


if [ -z $year ]

then

	year=`date | cut -f 6 -d " "`

fi


num=`echo $year % 4 | bc`


if [ $num -eq 0 ]

then

	echo $year is leap year.

else
	
	echo $year is not a leap year.
fi

