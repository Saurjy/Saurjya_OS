echo "Enter 3 Integers"
read a
read b
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
result=$a
elif [ $b -gt $c ]
then
result=$b
else
result=$c
fi
echo "Largest Number = " $result 
