echo "Enter the term"
read n
S=0.000
for (( i = 1 ; $i <= $n ; i = $i + 1))
	do
	l=`echo "scale=3;l($i)/l(10)" | bc -l`
	S=`echo "scale=3;$S + $l" | bc -l`
done
echo "Result="$S
