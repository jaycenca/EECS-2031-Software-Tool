#!/bin/bash

#store a variable to keep track of the loop invariant
exitD=6

#stores the messages in a variable
topMessage="----------------------------\n  M A I N - M E N U \n----------------------------"
contentMessage="1.Ongoing Processor Activity\n2.Users currently logged in\n3.Number of users currently logged in\n4.Users with bash shell\n5.Exit'"
bottomMessage="----------------------------\nPlease enter option[1 - 5]:"
finalMessage="Press [enter] key to continue . . ."

#iteration of the display of the menu 
while [ $exitD -eq 6 ]; do
	clear

        #displaying the menu message
	echo -e $topMessage
	echo -e $contentMessage
	echo -e $bottomMessage

        #reading the line of input from the keyboard
	read input
        
        #check the user answer and
        #and dispatch the appropriate output for each case
        case $input in    
           1)top;;
           2)ps aux | grep -v grep | cut -d " " -f 1 | sort | uniq;;
	   3)ps aux | grep -v grep | cut -d " " -f 1 | sort | uniq | wc -l;;
	   4)ps aux | grep /bash | grep -v grep | cut -d " " -f 1 | sort | uniq;;         
           5)exit;;
           *)echo -e "Please select the option between 1 and 5!!! Thank You\n"
	esac


        #displaying the message hinting the user
        #to go back to the menu
	echo -e $finalMessage

	read -s -n 1 key
done
	
