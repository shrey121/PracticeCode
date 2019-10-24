sum=0

total=0


if [ $# -eq 0 ]

then

        echo "Comman value not passed"

else

	cd $1

	ls >fil.txt

	t=`cat fil.txt`

	for a in $t

	do

		if [ -d $a ]

		then

			total=`ls -l $a | wc -l`

			total=`expr $total - 1`

			sum=`expr $sum + $total`

			echo Entries in Sub-dir $a are $total

		fi

	done
	echo Total entires present in this directory $sum

fi
