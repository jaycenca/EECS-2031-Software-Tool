#include <stdio.h>
#include <stdbool.h>

#define N 100000

bool isAnagram(char str1[N], char str2[N]);             /* function declaraction */
int conversion(char ch);                                /* function declaraction */

int main(void){
	
	//declare any necessary variables
	char str1[N];
	char c1, c2;
	char str2[N];


	//prompt
	printf("Enter first word: ");

	int i = 0;
	while ( (c1=getchar()) != '\n')
	{
		str1[i] = c1;
		i++;
	}	 

	//prompt
	printf("Enter second word: ");
	scanf("%[^\n]", &str2);


	//check 
	if(isAnagram(str1, str2))
		printf("The words are anagrams.\n");	
	else
		printf("The words are not anagrams.\n");
	return 0;
}

/**
 * Conversion function 
 *
 * -- perform appropriate arithmetic operations on the char if it's in range
 * -- return -1 otherwise
 */
int conversion(char ch)
{
	if ( ch > 64 && ch < 91 ) 
		return ch%'A';
	else if ( ch > 96 && ch < 123 )
		return ch%'a';
	return -1;
}

bool isAnagram(char str1[N], char str2[N])
{
	/**
	 *Let us assume the two strings are not Anagram,
	 *Once we see one comparison is not equal
	 *We can conclude that the two strings are not Anagram
	 **/

	int alpha = 26;
	bool result = false;

	//initialize the two arrays
	int c1[26] = {0};
	int c2[26] = {0};

	//reading the characters from the input and storing the characters accordingly for str1
	int i = 0;
	while ( str1 != NULL && str1[i] != '\0')
	{
		int coverted = conversion(str1[i]);
		if( coverted != -1 )
			c1[coverted]++;
		i++;
	}

	//reading the characters from the input and storing the characters accordingly for str2
	i = 0;
	while ( str2 != NULL && str2[i] != '\0')
	{
		int coverted = conversion(str2[i]);
		if( coverted != -1 )
			c2[coverted]++;
		i++;
	}

	int count = 0;

	//comparing two arrays
	for( i = 0; i < 26; i++)
	{
		if( c1[i] != c2[i])
			result = false;
		else
			count++;
	}

	if( count == 26 )
		result = true;
	return result;

}
