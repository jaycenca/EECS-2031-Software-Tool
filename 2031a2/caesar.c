#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//storing a macro for the length of possible characters in a string
#define N 1000

//defining the number for lower and upper case of the characters
#define UPPER 97
#define LOWER 65

void encryptedMessage();
int shiftErrorHandling();

int main(void)
{
	encryptedMessage();
	//int d;
	//scanf("%d",&d);
	//printf("%d",d);
	return 0;
}


int shiftErrorHandling()
{
	int shift;

	printf("Enter shift amount (1 - 25): ");
	scanf("%d", &shift);
	//printf("%d\n", shift);

	//Error Handling
	if ( shift > 25 || shift < 1 )
	{
		printf("Please Enter a number range between 1 and 25!!!\nPlease re-run the program!!!");
		return -1;
	}

	return shift; 
	
}

void encryptedMessage()
{
	//count the number of chars
	int count = 0;

	//store the char
	char ch;

	//store the list of char as a str
	char str[N];

        /*loop through all the characters in the array 
	 * and check 4 requirements: 
	 * 1) character is a letter ---> left unchanged
	 * 2) character is a space  ---> left unchanged
	 * 3) character is a lower case ---> left unchanged
	 * 4) character is a upper case ---> arithmetic operation to change 
	 */

	printf("Enter message to be encrypted: ");

	while ( (ch=getchar()) != '\n')
	{
		str[count] = ch;
		count++;
	}

	if(count < 81)
	{
		int shift = shiftErrorHandling();
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

	//error handling
	else
	{
		printf("Please Entered a message that is less than 80 characters!\nPlease Re-run the program!!!");
	}

	printf("\n");
}


