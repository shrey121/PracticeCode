l=0

w=0

c=0

echo Enter the Text. TO SToP TYPE end
 
k=1

ch=1


while [ $ch -gt 0 ]

do

	read data

	if [ "$data" = "end" ]

	then

		break

	fi


	if [ $k -eq 1 ]

        then

                echo $data>file2

                k=`expr $k + 1`

        else

                echo $data>>file2

        fi


	l=`expr $l + 1`

        for a in $data

        do

                if [ "$a" != "end" ]

                then

                        w=`expr $w + 1`

                else

                        echo yes

                        ch=0

                        break

                fi

        done


done


c=`ls -l file2|cut -f 5 -d ' '`

c=`expr $c - $l`


if [ $ch -eq 0 ]

then

	c=`expr $c - 3`

fi

 
for b in $@ 

do

	case $b in

	-l)
	echo number of lines is $l

		;;

	-w)
	echo number of words is $w

		;;

	-c)
	echo number of characters is $c

		;;

	*)
	echo WRONG CHOICE..!!

	
	;;
	esac


done
 
