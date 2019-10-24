CheckNo=`expr $# % 2`

if [ $CheckNo -ne 0 ]

then

	echo "ERROR: Even Number Of Arguments required.!!"

else

	cnt=1

        while [ $cnt -lt $# ]

        do

        	cp $1 $2

                shift

                shift

                cnt=`expr $cnt + 2`

         done

fi
