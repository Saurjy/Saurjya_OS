echo "Enter 3 Integers"
read a
read b
read c
result=`echo " $a + $b + $c " | bc`
echo "sum = " $result 
