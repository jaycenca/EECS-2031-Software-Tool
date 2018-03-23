#!/bin/bash

#storing the error message in a variable
message="Usage-./calculator.sh value1 operator value2\nwhere\nvalue1:numeric value\nvalue2:numeric value\noperator:one of +,-,/,x"

#Therer are 3 GENERAL scenario cases to consider:
#       1) the number of arguments entered must be 3:  two operands and one operator
#       2) division by zero 
#       3) operations if none of the cases occur
if [ $# -ne 3  ]; then
	echo -e $message
elif [ $3 -eq 0 -a $2 = "/" ]; then
	echo "Division-by-zero Error!"
else
	calculation="$1 $2 $3"
	#compare it with the 2nd argment 
	if [ $2 = "+" ]; then
		result=`expr $calculation`
	elif [ $2 = "-" ]; then
		result=`expr $calculation`
	elif [ $2 = "/" ]; then
		result=`expr $calculation`
	elif [ $2 = "x" ]; then
		result=`expr $1 \* $3`
	else 
		result=$message
	fi

	echo -e $result
fi



