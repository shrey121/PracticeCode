count=0

for i in $*

do

if [ -f $i ]

then

	echo "File $i is already exist."

else
		
	if [ -d mydir -a $count -lt 1 ]

        then

        	count=0

			
	else

        	if [ $count -eq 0 ]

		then

			mkdir mydir

			count=1

			echo DIRECTORY "mydir" has been made

		fi
 
                cd mydir

	> $i

		echo file $i made

		cd ..

        fi

fi


done


if [ $count -eq 0 ]

then


	cd mydir

	for j in `ls`

	do

        	if [ -f $j ]

        	then

        		count=`expr $count + 1`

        	fi

	done

	echo "Mydir already exist...contains $count files"

fi


