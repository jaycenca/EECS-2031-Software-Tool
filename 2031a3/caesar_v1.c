#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//defining the number for lower and upper case of the characters
#define UPPER 97
#define LOWER 65

void encryptedMessage(char *str, int shift);
void shiftHandlingError(int shift);



int main(int argc, char *argv[])
{
	char str[10000];
	int shift;
	
	//encryptedMessage(*str, shift);
	
	//------------------------------------------------------------------
	//testing
	//------------------------------------------------------------------
	FILE *fin;
	FILE *fout;

        char *filename = *&argv[1];
	char *filenameC = filename;
	//printf("%s\n", filename);
	int size = strlen(filename);
	printf("The size of %s is %d\n", filename, size);
	
	fin = fopen(filename, "r");
	char *enc = filename;
	//printf("%s", enc);

	strcat(enc, ".enc");
	//printf("The enc is %s\n", enc);
	//printf("The filename is %s\n", filename);
	fout = fopen(enc, "w+");

	
	char ch;
	while(fscanf(fin, "%c", &ch) != EOF)
	{
		printf("%c", ch);
		fprintf(fout,"%c", ch);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

void shiftHandlingError(int shift)
{
	if(shift > 26) 
	{
		printf("Argument Entered is Invalid\n");
		printf("./encrypt filename shift\n");
		printf("where filename is a valid file\n");\
		printf("and shift is a number in the range from 1 to 25");
	}
}
void encryptedMessage(char *str, int shift)
{

	//store the char
	char ch;


        /*loop through all the characters in the array 
	 * and check 4 requirements: 
	 * 1) character is a letter ---> left unchanged
	 * 2) character is a space  ---> left unchanged
	 * 3) character is a lower case ---> left unchanged
	 * 4) character is a upper case ---> arithmetic operation to change 
	 */

	while ( (ch=getchar()) != '\n')
	{
		
	}


	{
		int i = 0;
		while ( shift != -1 && str != NULL && str[i] != '\0')
		{
			char current = str[i];
			bool condition1 = current >= LOWER && current < 91; 
			bool condition2 = current >= UPPER && current < 123;
	
			if( condition1 )
			{
				str[i] = LOWER +( (current + shift) % LOWER ) % 26 ;
			}
			else if( condition2 )
			{
				str[i] = UPPER + ( (current + shift) % UPPER ) % 26;
			}
			i++;
                }
		
		if( shift != -1)
			printf("%s", str);
	}

	printf("\n");
}


