#!/bin/bash

#read the args

#printing out the Number of args
#echo "There are $# args"

#initialize yourlogin variable
yourlogin=$( whoami )

#echo $yourlogin
    
#creating a new directory to be used as the recycle bin 
#and store it in a variable
recyclebin="/tmp/$yourlogin/eecs2031m/a1/recycle-bin"
mkdir -p $recyclebin

if [ $# -eq 0 ]; then
	echo -e "Error:no target specified\nUsage:./myrm <files>"
else
	for arg in "$@"
	do 
		echo "deleting $arg"
		mv $arg $recyclebin/.
	done
	
fi





