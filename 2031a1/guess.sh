#!/bin/bash

#Obtaining the random number such that
#it ONLY produces in the range of 1 to 64(inclusive)
random=$RANDOM
range=`expr 1 + $random % 64`

#Initalize a variable to count the nunber of attempt
attempt=1

#Displaying a welcome message
echo "Welcome to the number game."
echo "Guess a number between 1 and 64(inclusive)"
read number

while [ $attempt -lt 7 ]; do

	#use control statements
	#to check the $number in range
	if [ $number -gt $range ]; then 
		echo "Too big"
	elif [ $number -lt $range ]; then
		echo "Too small"
	else 
		echo "You won!"
		let attempt=7
	        exit
	fi

        #update the value of attempt 
        #to keep track of the number of attempts
	let attempt=attempt+1


	if [ $attempt -gt 6 ]; then
		echo "You Lost!"
	       	exit
	fi
        
	#display message to allow another input
	echo "Try again"

	#read from the input again
	read number

done
echo $range







