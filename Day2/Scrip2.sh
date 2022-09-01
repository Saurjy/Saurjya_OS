echo "Enter 1 for Addition 2 for Subtraction 3 for Multiplication 4 for Divition 5 to Quit"
read a
case "$a" in
   "1") echo "Enter the Addends." 
   	read b
   	read c
   	echo "The Result = "`echo " $b + $c " | bc`
   ;;
   "2") echo "Enter the Subtrahends."
   	read b
   	read c
   	echo "The Result = "`echo " $b - $c " | bc`
   ;;
   "3") echo "Enter the Multiplicands." 
   	read b
   	read c
   	echo "The Result = "`echo " $b * $c " | bc`
   ;;
   "4") echo "Enter the Divisors." 
   	read b
   	read c
   	echo "The Result = "`echo " $b / $c " | bc`
   ;;
   "*") echo "Quit." 
   	 exit 0
   ;;
esac
