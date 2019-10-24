echo "All combinations of 1 2 & 3 are:"

for i in 1 2 3

do


	for j in 1 2 3

 	do


		for k in 1 2 3

   		do


    			if test $i -ne $j -a $i -ne $k -a $j -ne $k

    			then


				echo $i$j$k


    			fi


   		done


 	done


done

