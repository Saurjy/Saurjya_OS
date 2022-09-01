echo "enter starting the range"
read s
echo "enter ending the range"
read e
echo "the prime nos are:" 
for (( i = $s+1 ; $i <= $e ; i = $i + 1))
	do
	c=0
	for (( j = 1 ; $j <= $i ; j = $j + 1))
		do
		if [ `expr $i % $j` -eq 0 ]
		then
			c=$((c+1))
		fi
		done
	if [ $c -eq 2 ]
	then
		echo $i
	else
		continue
	fi
	done
