echo Enter one/two/three

read word



if [ $word = one ]

then

	tput bold

	echo one

	tput init

el
if [ $word = two ]

then
	tput rev

	echo two

	tput init

el
if [ $word = three ]

then

	count=0

	while [ $count -le 10 ]

	do
		
		clear

		sleep 0.2

		echo two

		sleep 0.5

		count=`expr $count + 1
`
	done

fi
