#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//defining the number for lower and upper case of the characters

#define UPPER 65
#define LOWER 97

char encryptedMessage(char *str, int shift);
void HandlingError();



int main(int argc, char *argv[])
{
	char *shift;
	shift = argv[2];

	//------------------------------------------------------------------
	//testing
	//------------------------------------------------------------------
	
	//printf("The Shift is %d\n",*(shift+ (1-count)) - '0');

	//printf("The number of arguments is %d\n", argc);

        if(argc < 3) 
	{
		HandlingError();
		return -1;
	}
	
	
	//convert the list of char into integer
	int shiftValue = 0;
	int count = 0;

	//count the number of digits
	while(*shift != '\0')
	{
		//check validation of each character
		if(*shift <48 || *shift > 57) 
                {
                        HandlingError();
			return -1;
                }
		count = count + 1;
		shift++;
	}

	shift--;
	
	//calculate the number 
	int i;
	for(i = 0; i < count; i++)
	{	
		shiftValue += (i > 0) ? (((*shift-'0') * 10) * i) : *(shift) - '0';

		/**
		printf("the count is %d and i is %d\n", count, i);
		if(i > 0)
			shiftValue += (*(shift) - '0') * 10 * i;
		else 
			shiftValue += (*shift) - '0';
		printf("The number is %d\n", (*(shift)));
		printf("The shift is %d\n", (*(shift) - '0') );
		printf("The value is %d\n", shiftValue);*/
		shift--;
	}
 
	//printf("The shift Value is %d\n", shiftValue);
   
	if(shiftValue > 26 || shiftValue < 1) 
	{
		HandlingError();
		return -1;
	}

	//declaring two files: input file and output file
	FILE *fin;
	FILE *fout;

	//declare and initialize a pointer that points to the corresponding command argument,
	//In this case: pointing to the second argument, which contains the filename 
        char *filename = *&argv[1];

	//printf("%s\n", filename);
	//printf("The size of %s is %d\n", filename, size);
	
	fin = fopen(filename, "r");
	//char *enc = filename;
	//printf("%s", enc);

	strcat(filename, ".enc");
	//printf("The enc is %s\n", enc);
	//printf("The filename is %s\n", filename);
	fout = fopen(filename, "w+");

	
	char ch;
	while(fscanf(fin, "%c", &ch) != EOF)
	{
		printf("%c, ..... ",ch);
		ch = encryptedMessage(&ch, shiftValue);
		fprintf(fout,"%c", ch);
		printf("%c\n", ch);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

void HandlingError()
{
	printf("Argument Entered is Invalid\n\n");
	printf("./encrypt filename shift\n");
	printf("where filename is a valid file\n");
	printf("and shift is a number in the range from 1 to 26\n");
}
char encryptedMessage(char *ch, int shift)
{
        /*loop through all the characters in the array 
	 * and check 4 requirements: 
	 * 1) character is a letter ---> left unchanged
	 * 2) character is a space  ---> left unchanged
	 * 3) character is a lower case ---> left unchanged
	 * 4) character is a upper case ---> arithmetic operation to change 
	 */
	
	char *current = ch;
	bool condition1 = *current >= LOWER && *current < 'z'; 
	bool condition2 = *current >= UPPER && *current < 'Z';
	
	if( condition1 )
	{
		*current = LOWER +( (*current + shift) % LOWER ) % 26 ;
	}
	else if( condition2 )
	{
		*current = UPPER + ( (*current + shift) % UPPER ) % 26;
	}   
	return *current;
}


