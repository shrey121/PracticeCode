echo PRIME NUMBERS from 1-1000 are:

rng=1000 

echo 2 "\c" 

j=3
 

while test $j -le $rng
 
do
 
	i=2
 
	x=`expr $j - 1`
 

   	while test $i -le $x
 
   	do
 
      		if [ `expr $j % $i` -ne 0 ]
 
      		then
 
         		i=`expr $i + 1`
 
		else 

			break
 
		fi
 
	done
 

	if [ $i -eq $j ]
 
	then
 
		echo $j "\c"
  
	fi
 
	
	j=`expr $j + 1`
 
done


echo \n
